#include <iostream>
#include <vector>
#include <set>
#include <optional>
#include <string>
#include <sstream>
#include <stdexcept>
#include <functional>
#include <utility>

template <typename K, typename V>
class MyMap {
public:
    struct Entry {
        std::optional<K> key;
        std::optional<V> value;

        Entry() = default;
        Entry(K k, V v) : key(std::move(k)), value(std::move(v)) {}

        const K& getKey() const { return key.value(); }
        const V& getValue() const { return value.value(); }

        bool operator<(const Entry& other) const {
            if (key.has_value() && other.key.has_value()) {
                return key.value() < other.key.value();
            }
            return key.has_value() < other.key.has_value();
        }

        std::string toString() const {
            std::ostringstream ss;
            ss << "[";
            if (key.has_value()) ss << key.value();
            else ss << "null";
            ss << ", ";
            if (value.has_value()) ss << value.value();
            else ss << "null";
            ss << "]";
            return ss.str();
        }
    };

    virtual ~MyMap() = default;
    virtual void clear() = 0;
    virtual bool containsKey(const K& key) const = 0;
    virtual bool containsValue(const V& value) const = 0;
    virtual std::set<Entry> entrySet() const = 0;
    virtual std::optional<V> get(const K& key) const = 0;
    virtual std::set<V> getAll(const K& key) const = 0;
    virtual bool isEmpty() const = 0;
    virtual std::set<K> keySet() const = 0;
    virtual std::optional<V> put(K key, V value) = 0;
    virtual void remove(const K& key) = 0;
    virtual size_t size() const = 0;
    virtual std::set<V> values() const = 0;
};

template <typename K, typename V>
class MyHashMap : public MyMap<K, V> {
    using Entry = typename MyMap<K, V>::Entry;

private:
    static constexpr size_t DEFAULT_INITIAL_CAPACITY = 4;
    static constexpr size_t MAXIMUM_CAPACITY = 1ULL << 30;
    static constexpr float DEFAULT_MAX_LOAD_FACTOR = 0.4f;

    size_t capacity;
    float loadFactorThreshold;
    size_t sizeCount = 0;
    std::vector<std::optional<Entry>> table;

    size_t hash(size_t hashCode) const {
        return hashCode % capacity;
    }

    void removeEntries() {
        std::fill(table.begin(), table.end(), std::nullopt);
    }

    void rehash() {
        auto entries = entrySet();
        capacity <<= 1;
        table.assign(capacity, std::nullopt);
        sizeCount = 0;

        for (const auto& entry : entries) {
            put(entry.key.value(), entry.value.value());
        }
    }

public:
    MyHashMap() : MyHashMap(DEFAULT_INITIAL_CAPACITY, DEFAULT_MAX_LOAD_FACTOR) {}

    explicit MyHashMap(size_t initialCapacity) : MyHashMap(initialCapacity, DEFAULT_MAX_LOAD_FACTOR) {}

    MyHashMap(size_t initialCapacity, float loadFactorThreshold)
        : capacity(initialCapacity), loadFactorThreshold(loadFactorThreshold), table(initialCapacity, std::nullopt) {}

    void clear() override {
        sizeCount = 0;
        removeEntries();
    }

    bool containsKey(const K& key) const override {
        return get(key).has_value();
    }

    bool containsValue(const V& value) const override {
        for (const auto& bucket : table) {
            if (bucket.has_value() && bucket->value.has_value() && bucket->value.value() == value) {
                return true;
            }
        }
        return false;
    }

    std::set<Entry> entrySet() const override {
        std::set<Entry> set;
        for (const auto& bucket : table) {
            if (bucket.has_value() && bucket->key.has_value()) {
                set.insert(bucket.value());
            }
        }
        return set;
    }

    std::optional<V> get(const K& key) const override {
        size_t k = hash(std::hash<K>{}(key));
        size_t i = k;
        size_t j = 1;

        while (table[i].has_value()) {
            if (table[i]->key.has_value() && table[i]->key.value() == key) {
                return table[i]->value;
            }
            i = (k + j * j) % capacity;
            j++;
        }

        return std::nullopt;
    }

    std::set<V> getAll(const K& key) const override {
        std::set<V> set;
        for (const auto& bucket : table) {
            if (bucket.has_value() && bucket->key.has_value() && bucket->key.value() == key) {
                if (bucket->value.has_value()) {
                    set.insert(bucket->value.value());
                }
            }
        }
        return set;
    }

    bool isEmpty() const override {
        return sizeCount == 0;
    }

    std::set<K> keySet() const override {
        std::set<K> set;
        for (const auto& bucket : table) {
            if (bucket.has_value() && bucket->key.has_value()) {
                set.insert(bucket->key.value());
            }
        }
        return set;
    }

    std::optional<V> put(K key, V value) override {
        if (sizeCount >= capacity * loadFactorThreshold) {
            if (capacity >= MAXIMUM_CAPACITY) {
                throw std::runtime_error("Exceeding maximum capacity");
            }
            rehash();
        }

        size_t k = hash(std::hash<K>{}(key));
        size_t j = 1;
        size_t i = k;

        while (table[i].has_value() && table[i]->key.has_value()) {
            i = (k + j * j) % capacity;
            j++;
        }

        table[i] = Entry(key, value);
        sizeCount++;

        return value;
    }

    void remove(const K& key) override {
        size_t k = hash(std::hash<K>{}(key));
        size_t j = 1;
        size_t i = k;

        while (table[i].has_value() && (!table[i]->key.has_value() || table[i]->key.value() != key)) {
            i = (k + j * j) % capacity;
            j++;
        }

        if (table[i].has_value() && table[i]->key.has_value() && table[i]->key.value() == key) {
            table[i] = Entry();
            table[i]->key = std::nullopt;
            table[i]->value = std::nullopt;
            sizeCount--;
        }
    }

    size_t size() const override {
        return sizeCount;
    }

    std::set<V> values() const override {
        std::set<V> set;
        for (const auto& bucket : table) {
            if (bucket.has_value() && bucket->value.has_value()) {
                set.insert(bucket->value.value());
            }
        }
        return set;
    }

    std::string toString() const {
        std::ostringstream builder;
        builder << "[";
        for (size_t i = 0; i < capacity; ++i) {
            if (table[i].has_value() && table[i]->key.has_value()) {
                builder << table[i]->toString();
            }
        }
        builder << "]";
        return builder.str();
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        MyHashMap<int, int> map;
        map.put(2, 2);
        std::cout << "Is key 2 in the map? " << (map.containsKey(2) ? "true" : "false") << '\n';
        map.remove(2);
        std::cout << "Is key 2 in the map? " << (map.containsKey(2) ? "true" : "false") << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}