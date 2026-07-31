#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <string>
#include <stdexcept>
#include <functional>


// UTILITY FUNCTIONS & EXCEPTION SAFEGUARDS


void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void runSafely(const std::string& appName, const std::function<void()>& appFunc) {
    std::cout << "\n=============================================\n";
    std::cout << " Running: " << appName << "\n";
    std::cout << "=============================================\n";
    try {
        appFunc();
    } catch (const std::invalid_argument& e) {
        std::cerr << "[Argument Error]: " << e.what() << '\n';
    } catch (const std::out_of_range& e) {
        std::cerr << "[Bounds Error]: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "[Standard Exception Caught]: " << e.what() << '\n';
    } catch (...) {
        std::cerr << "[Unknown Non-Standard Exception Occurred]\n";
    }
}


// DATA STRUCTURE: BINARY SEARCH TREE (RAII / SMART POINTERS)


template <typename T>
struct TreeNode {
    T element;
    std::shared_ptr<TreeNode<T>> left;
    std::shared_ptr<TreeNode<T>> right;

    explicit TreeNode(const T& e) : element(e), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    std::shared_ptr<TreeNode<T>> root;
    size_t treeSize;

    int height(const std::shared_ptr<TreeNode<T>>& node) const {
        if (!node) return 0;
        return std::max(height(node->left), height(node->right)) + 1;
    }

    bool isFullBST(const std::shared_ptr<TreeNode<T>>& node) const {
        if (!node) return true;
        if (!node->left && !node->right) return true;
        if (node->left && node->right) {
            return isFullBST(node->left) && isFullBST(node->right);
        }
        return false;
    }

    void inorder(const std::shared_ptr<TreeNode<T>>& node) const {
        if (!node) return;
        inorder(node->left);
        std::cout << node->element << " ";
        inorder(node->right);
    }

public:
    BST() : root(nullptr), treeSize(0) {}

    bool insert(const T& e) {
        if (!root) {
            root = std::make_shared<TreeNode<T>>(e);
        } else {
            std::shared_ptr<TreeNode<T>> parent = nullptr;
            auto current = root;
            while (current) {
                if (e < current->element) {
                    parent = current;
                    current = current->left;
                } else if (e > current->element) {
                    parent = current;
                    current = current->right;
                } else {
                    return false; // Duplicate node
                }
            }
            if (e < parent->element) parent->left = std::make_shared<TreeNode<T>>(e);
            else parent->right = std::make_shared<TreeNode<T>>(e);
        }
        treeSize++;
        return true;
    }

    bool remove(const T& e) {
        std::shared_ptr<TreeNode<T>> parent = nullptr;
        auto current = root;

        while (current) {
            if (e < current->element) {
                parent = current;
                current = current->left;
            } else if (e > current->element) {
                parent = current;
                current = current->right;
            } else {
                break;
            }
        }

        if (!current) return false;

        if (!current->left) {
            if (!parent) {
                root = current->right;
            } else {
                if (e < parent->element) parent->left = current->right;
                else parent->right = current->right;
            }
        } else {
            auto parentOfRightMost = current;
            auto rightMost = current->left;

            while (rightMost->right) {
                parentOfRightMost = rightMost;
                rightMost = rightMost->right;
            }

            current->element = rightMost->element;

            if (parentOfRightMost->right == rightMost) {
                parentOfRightMost->right = rightMost->left;
            } else {
                parentOfRightMost->left = rightMost->left;
            }
        }
        treeSize--;
        return true;
    }

    void inorder() const {
        inorder(root);
        std::cout << '\n';
    }

    void breadthFirstTraversal() const {
        if (!root) return;
        std::queue<std::shared_ptr<TreeNode<T>>> q;
        q.push(root);

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            std::cout << current->element << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        std::cout << '\n';
    }

    int height() const { return height(root); }
    bool isFullBST() const { return isFullBST(root); }
    size_t getSize() const { return treeSize; }
    void clear() { root = nullptr; treeSize = 0; }
};


// APPLICATION 1: CYLINDER CALCULATOR (EXERCISE 2.2)


void runCylinderCalculator() {
    std::cout << "Enter the radius and length of a cylinder: ";

    double radius = 0.0;
    double length = 0.0;

    if (!(std::cin >> radius >> length)) {
        clearInputStream();
        throw std::invalid_argument("Invalid numeric input provided.");
    }

    if (radius < 0.0 || length < 0.0) {
        throw std::out_of_range("Radius and length must be non-negative numbers.");
    }

    constexpr double pi = 3.14159265358979323846;
    const double area = radius * radius * pi;
    const double volume = area * length;

    std::cout << "The area is " << area << '\n';
    std::cout << "The volume is " << volume << '\n';
}


// APPLICATION 2: MYLIST & VECTOR SET OPERATIONS (EXERCISE 24.01)


template <typename T>
class MyList {
private:
    std::vector<T> data;

public:
    MyList() = default;
    MyList(std::initializer_list<T> list) : data(list) {}

    void add(const T& e) { data.push_back(e); }

    bool contains(const T& e) const {
        return std::find(data.begin(), data.end(), e) != data.end();
    }

    bool remove(const T& e) {
        auto it = std::find(data.begin(), data.end(), e);
        if (it != data.end()) {
            data.erase(it);
            return true;
        }
        return false;
    }

    bool addAll(const MyList<T>& other) {
        bool changed = false;
        for (const auto& item : other.data) {
            if (!contains(item)) {
                add(item);
                changed = true;
            }
        }
        return changed;
    }

    bool removeAll(const MyList<T>& other) {
        bool changed = false;
        for (const auto& item : other.data) {
            if (remove(item)) {
                changed = true;
            }
        }
        return changed;
    }

    bool retainAll(const MyList<T>& other) {
        bool changed = false;
        for (auto it = data.begin(); it != data.end();) {
            if (!other.contains(*it)) {
                it = data.erase(it);
                changed = true;
            } else {
                ++it;
            }
        }
        return changed;
    }

    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << data[i] << (i + 1 < data.size() ? ", " : "");
        }
        std::cout << "]\n";
    }
};

void runListSetOperations() {
    MyList<std::string> list1 = {"Tom", "George", "Peter", "Jean", "Jane"};
    MyList<std::string> list2 = {"Tom", "George", "Michael", "Michelle", "Daniel"};

    std::cout << "Initial lists:\nlist1: ";
    list1.print();
    std::cout << "list2: ";
    list2.print();

    std::cout << "\nExecuting list1.addAll(list2)...\n";
    list1.addAll(list2);
    std::cout << "list1: ";
    list1.print();

    list1 = {"Tom", "George", "Peter", "Jean", "Jane"};
    std::cout << "\nExecuting list1.removeAll(list2)...\n";
    list1.removeAll(list2);
    std::cout << "list1: ";
    list1.print();

    list1 = {"Tom", "George", "Peter", "Jean", "Jane"};
    std::cout << "\nExecuting list1.retainAll(list2)...\n";
    list1.retainAll(list2);
    std::cout << "list1: ";
    list1.print();
}


// APPLICATION 3: BINARY SEARCH TREE DEMO


void runBstDemo() {
    BST<int> tree;
    std::vector<int> values = {60, 55, 100, 45, 57, 67, 107, 59};

    std::cout << "Inserting elements into BST: ";
    for (int v : values) {
        std::cout << v << " ";
        tree.insert(v);
    }
    std::cout << "\n\nInorder Traversal: ";
    tree.inorder();

    std::cout << "Breadth-First Traversal: ";
    tree.breadthFirstTraversal();

    std::cout << "Tree Height: " << tree.height() << '\n';
    std::cout << "Is Full BST: " << (tree.isFullBST() ? "Yes" : "No") << '\n';

    std::cout << "\nDeleting node 55...\n";
    tree.remove(55);
    std::cout << "Inorder Traversal after deletion: ";
    tree.inorder();
}


// MAIN DRIVER MENU


void displayMenu() {
    std::cout << "\n=============================================\n"
              << "       UNIFIED CROSS-PLATFORM C++ RUNNER     \n"
              << "=============================================\n"
              << "1. Run Cylinder Calculator (Exercise 2.2)\n"
              << "2. Run List Set Operations (Exercise 24.01)\n"
              << "3. Run Binary Search Tree Demo\n"
              << "4. Run ALL Applications Sequentially\n"
              << "0. Exit\n"
              << "=============================================\n"
              << "Enter choice: ";
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    int choice = -1;

    do {
        displayMenu();
        if (!(std::cin >> choice)) {
            clearInputStream();
            std::cout << "Invalid entry. Please enter a valid menu number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                runSafely("Exercise 2.2 - Cylinder Calculator", runCylinderCalculator);
                break;
            case 2:
                runSafely("Exercise 24.01 - List Set Operations", runListSetOperations);
                break;
            case 3:
                runSafely("Binary Search Tree Demo", runBstDemo);
                break;
            case 4:
                runSafely("Exercise 2.2 - Cylinder Calculator", runCylinderCalculator);
                runSafely("Exercise 24.01 - List Set Operations", runListSetOperations);
                runSafely("Binary Search Tree Demo", runBstDemo);
                break;
            case 0:
                std::cout << "Exiting program runner. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please select an option from the menu.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}