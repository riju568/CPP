#include <iostream>
#include <vector>
#include <functional>
#include <limits>
#include <utility>
#include <stdexcept>
#include <string>
#include <algorithm>

// Generic Sorting Algorithms

// 1. Generic Bubble Sort
template <typename T, typename Compare = std::less<T>>
void bubble_sort(std::vector<T>& vec, Compare comp = Compare()) {
    if (vec.size() <= 1) return; // Prevent underflow on vec.size() - 1

    bool need_next_pass = true;
    for (size_t k = 0; k < vec.size() && need_next_pass; ++k) {
        need_next_pass = false;
        for (size_t i = 0; i < vec.size() - 1 - k; ++i) {
            if (comp(vec[i + 1], vec[i])) {
                std::swap(vec[i], vec[i + 1]);
                need_next_pass = true;
            }
        }
    }
}

// 2. Generic Merge Sort
template <typename T, typename Compare = std::less<T>>
void merge_sort(std::vector<T>& vec, Compare comp = Compare()) {
    if (vec.size() <= 1) return;
    const size_t mid = vec.size() / 2;
    std::vector<T> first_half(vec.begin(), vec.begin() + mid);
    std::vector<T> second_half(vec.begin() + mid, vec.end());
    merge_sort(first_half, comp);
    merge_sort(second_half, comp);
    size_t i = 0, j = 0, k = 0;
    while (i < first_half.size() && j < second_half.size()) {
        if (comp(second_half[j], first_half[i])) {
            vec[k++] = std::move(second_half[j++]);
        } else {
            vec[k++] = std::move(first_half[i++]);
        }
    }
    while (i < first_half.size()) vec[k++] = std::move(first_half[i++]);
    while (j < second_half.size()) vec[k++] = std::move(second_half[j++]);
}

// Median-of-Three Pivot Selection helper
template <typename T, typename Compare>
size_t median_of_three_index(std::vector<T>& vec, size_t low, size_t high, Compare comp) {
    size_t mid = low + (high - low) / 2;
    if (comp(vec[mid], vec[low])) std::swap(vec[low], vec[mid]);
    if (comp(vec[high], vec[low])) std::swap(vec[low], vec[high]);
    if (comp(vec[high], vec[mid])) std::swap(vec[mid], vec[high]);
    return mid;
}

// 3. Improved Generic Quick Sort
template <typename T, typename Compare>
size_t partition(std::vector<T>& vec, size_t low, size_t high, Compare comp) {
    size_t median_idx = median_of_three_index(vec, low, high, comp);
    std::swap(vec[median_idx], vec[high]);
    const T pivot = vec[high];
    size_t i = low;
    for (size_t j = low; j < high; ++j) {
        if (comp(vec[j], pivot)) {
            std::swap(vec[i], vec[j]);
            ++i;
        }
    }
    std::swap(vec[i], vec[high]);
    return i;
}

template <typename T, typename Compare>
void quick_sort_impl(std::vector<T>& vec, size_t low, size_t high, Compare comp) {
    if (low < high) {
        size_t p = partition(vec, low, high, comp);
        
        // Pure size_t indexing without underflow risk
        if (p > low) {
            quick_sort_impl(vec, low, p - 1, comp);
        }
        if (p < high) {
            quick_sort_impl(vec, p + 1, high, comp);
        }
    }
}

template <typename T, typename Compare = std::less<T>>
void quick_sort(std::vector<T>& vec, Compare comp = Compare()) {
    if (vec.size() <= 1) return;
    quick_sort_impl(vec, 0, vec.size() - 1, comp);
}

// 4. Generic Heap Sort
template <typename T, typename Compare>
void heapify(std::vector<T>& vec, size_t n, size_t i, Compare comp) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    if (left < n && comp(vec[largest], vec[left])) largest = left;
    if (right < n && comp(vec[largest], vec[right])) largest = right;
    if (largest != i) {
        std::swap(vec[i], vec[largest]);
        heapify(vec, n, largest, comp);
    }
}

template <typename T, typename Compare = std::less<T>>
void heap_sort(std::vector<T>& vec, Compare comp = Compare()) {
    if (vec.size() <= 1) return;

    // Type-safe size_t reverse loop
    for (size_t i = vec.size() / 2; i > 0; --i) {
        heapify(vec, vec.size(), i - 1, comp);
    }
    for (size_t i = vec.size() - 1; i > 0; --i) {
        std::swap(vec[0], vec[i]);
        heapify(vec, i, 0, comp);
    }
}

// 5. Check Array Order
template <typename T, typename Compare = std::less<T>>
bool is_ordered(const std::vector<T>& vec, bool ascending = true, Compare comp = Compare()) {
    if (vec.size() <= 1) return true;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (ascending) {
            if (comp(vec[i + 1], vec[i])) return false;
        } else {
            if (comp(vec[i], vec[i + 1])) return false;
        }
    }
    return true;
}


// UI & Stream Helpers


void clear_input_stream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void print_vector(const std::vector<int>& vec, const std::string& label = "Array") {
    std::cout << label << ": [ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i + 1 < vec.size() ? ", " : " ");
    }
    std::cout << "]\n";
}

std::vector<int> read_sample_array() {
    std::cout << "\nEnter array size: ";
    int size = 0;
    if (!(std::cin >> size) || size <= 0) {
        clear_input_stream();
        throw std::invalid_argument("Size must be a positive integer.");
    }

    std::vector<int> data(size);
    std::cout << "Enter " << size << " space-separated integers: ";
    for (int i = 0; i < size; ++i) {
        if (!(std::cin >> data[i])) {
            clear_input_stream();
            throw std::invalid_argument("Invalid numerical input entered.");
        }
    }
    return data;
}


// Entry Point

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        bool running = true;
        while (running) {
            std::cout << "  ~ Sorting Algorithms Suite ~             \n";
            std::cout << "1. Generic Bubble Sort\n";
            std::cout << "2. Generic Merge Sort\n";
            std::cout << "3. Improved Quick Sort (Median Pivot)\n";
            std::cout << "4. Generic Heap Sort\n";
            std::cout << "5. Check Array Order (Ascending/Descending)\n";
            std::cout << "6. Exit\n";
            std::cout << "Select an option (1-6): ";

            int choice = 0;
            if (std::cin >> choice) {
                if (choice == 6) {
                    std::cout << "Exiting program. Goodbye!\n";
                    break;
                }

                if (choice >= 1 && choice <= 5) {
                    try {
                        std::vector<int> arr = read_sample_array();
                        print_vector(arr, "Original Array");

                        switch (choice) {
                            case 1:
                                bubble_sort(arr);
                                print_vector(arr, "Bubble Sorted ");
                                break;
                            case 2:
                                merge_sort(arr);
                                print_vector(arr, "Merge Sorted  ");
                                break;
                            case 3:
                                quick_sort(arr);
                                print_vector(arr, "Quick Sorted  ");
                                break;
                            case 4:
                                heap_sort(arr);
                                print_vector(arr, "Heap Sorted   ");
                                break;
                            case 5:
                                std::cout << "Is ascending?  : " << (is_ordered(arr, true) ? "Yes" : "No") << '\n';
                                std::cout << "Is descending? : " << (is_ordered(arr, false) ? "Yes" : "No") << '\n';
                                break;
                        }
                    } catch (const std::exception& err) {
                        std::cerr << "Operation Error: " << err.what() << "\n";
                    }
                } else {
                    std::cerr << "Error: Selection out of range. Choose 1-6.\n";
                }
            } else {
                if (std::cin.eof()) break;
                std::cerr << "Error: Invalid selection. Enter an integer.\n";
                clear_input_stream();
            }
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "\nFatal Exception: " << e.what() << '\n';
        return 1;
    } 
    catch (...) {
        std::cerr << "\nFatal Error: An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}