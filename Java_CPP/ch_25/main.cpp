#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>

template <typename T>
struct TreeNode {
    T element;
    std::shared_ptr<TreeNode<T>> left;
    std::shared_ptr<TreeNode<T>> right;

    TreeNode(const T& e) : element(e), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    std::shared_ptr<TreeNode<T>> root;
    size_t treeSize;

    int height(const std::shared_ptr<TreeNode<T>>& node) const {
        if (!node) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return std::max(leftHeight, rightHeight) + 1;
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

    void preorder(const std::shared_ptr<TreeNode<T>>& node) const {
        if (!node) return;
        std::cout << node->element << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(const std::shared_ptr<TreeNode<T>>& node) const {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->element << " ";
    }

public:
    BST() : root(nullptr), treeSize(0) {}

    bool search(const T& e) const {
        auto current = root;
        while (current) {
            if (e < current->element) {
                current = current->left;
            }
            else if (e > current->element) {
                current = current->right;
            }
            else {
                return true;
            }
        }
        return false;
    }

    bool insert(const T& e) {
        if (!root) {
            root = std::make_shared<TreeNode<T>>(e);
        }
        else {
            std::shared_ptr<TreeNode<T>> parent = nullptr;
            auto current = root;
            while (current) {
                if (e < current->element) {
                    parent = current;
                    current = current->left;
                }
                else if (e > current->element) {
                    parent = current;
                    current = current->right;
                }
                else {
                    return false;
                }
            }
            if (e < parent->element) {
                parent->left = std::make_shared<TreeNode<T>>(e);
            }
            else {
                parent->right = std::make_shared<TreeNode<T>>(e);
            }
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
            }
            else if (e > current->element) {
                parent = current;
                current = current->right;
            }
            else {
                break;
            }
        }

        if (!current) return false;

        if (!current->left) {
            if (!parent) {
                root = current->right;
            }
            else {
                if (e < parent->element) {
                    parent->left = current->right;
                }
                else {
                    parent->right = current->right;
                }
            }
        }
        else {
            auto parentOfRightMost = current;
            auto rightMost = current->left;

            while (rightMost->right) {
                parentOfRightMost = rightMost;
                rightMost = rightMost->right;
            }

            current->element = rightMost->element;

            if (parentOfRightMost->right == rightMost) {
                parentOfRightMost->right = rightMost->left;
            }
            else {
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

    void inorderNonRecursive() const {
        std::stack<std::shared_ptr<TreeNode<T>>> st;
        auto current = root;

        while (current || !st.empty()) {
            while (current) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            std::cout << current->element << " ";
            current = current->right;
        }
        std::cout << '\n';
    }

    void preorder() const {
        preorder(root);
        std::cout << '\n';
    }

    void postorder() const {
        postorder(root);
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

    int height() const {
        return height(root);
    }

    bool isFullBST() const {
        return isFullBST(root);
    }

    size_t getSize() const {
        return treeSize;
    }

    bool isEmpty() const {
        return treeSize == 0;
    }

    void clear() {
        root = nullptr;
        treeSize = 0;
    }

    std::vector<T> path(const T& e) const {
        std::vector<T> list;
        auto current = root;
        while (current) {
            list.push_back(current->element);
            if (e < current->element) {
                current = current->left;
            }
            else if (e > current->element) {
                current = current->right;
            }
            else {
                break;
            }
        }
        return list;
    }
};

void displayMenu() {
    std::cout << "\n===============================\n"
        << "       BINARY SEARCH TREE      \n"
        << "===============================\n"
        << "1. Insert Element\n"
        << "2. Delete Element\n"
        << "3. Search Element\n"
        << "4. Inorder Traversal (Recursive)\n"
        << "5. Inorder Traversal (Iterative)\n"
        << "6. Preorder Traversal\n"
        << "7. Postorder Traversal\n"
        << "8. Breadth-First Traversal\n"
        << "9. Get Tree Height\n"
        << "10. Check if Tree is Full\n"
        << "11. Get Tree Size\n"
        << "12. Display Path to Element\n"
        << "13. Clear Tree\n"
        << "0. Exit\n"
        << "===============================\n"
        << "Enter choice: ";
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    BST<int> tree;
    int choice;

    do {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            int val;
            std::cout << "Enter integer to insert: ";
            if (std::cin >> val) {
                if (tree.insert(val)) {
                    std::cout << "Inserted " << val << " successfully.\n";
                }
                else {
                    std::cout << "Element " << val << " already exists.\n";
                }
            }
            break;
        }
        case 2: {
            int val;
            std::cout << "Enter integer to delete: ";
            if (std::cin >> val) {
                if (tree.remove(val)) {
                    std::cout << "Deleted " << val << " successfully.\n";
                }
                else {
                    std::cout << "Element " << val << " not found.\n";
                }
            }
            break;
        }
        case 3: {
            int val;
            std::cout << "Enter integer to search: ";
            if (std::cin >> val) {
                if (tree.search(val)) {
                    std::cout << "Element " << val << " is in the tree.\n";
                }
                else {
                    std::cout << "Element " << val << " is not in the tree.\n";
                }
            }
            break;
        }
        case 4:
            std::cout << "Inorder Traversal: ";
            tree.inorder();
            break;
        case 5:
            std::cout << "Inorder Traversal (Iterative): ";
            tree.inorderNonRecursive();
            break;
        case 6:
            std::cout << "Preorder Traversal: ";
            tree.preorder();
            break;
        case 7:
            std::cout << "Postorder Traversal: ";
            tree.postorder();
            break;
        case 8:
            std::cout << "Breadth-First Traversal: ";
            tree.breadthFirstTraversal();
            break;
        case 9:
            std::cout << "Tree Height: " << tree.height() << '\n';
            break;
        case 10:
            std::cout << "Is Full BST: " << (tree.isFullBST() ? "Yes" : "No") << '\n';
            break;
        case 11:
            std::cout << "Tree Size: " << tree.getSize() << '\n';
            break;
        case 12: {
            int val;
            std::cout << "Enter integer to get path: ";
            if (std::cin >> val) {
                auto path = tree.path(val);
                std::cout << "Path: ";
                for (size_t i = 0; i < path.size(); ++i) {
                    std::cout << path[i] << (i + 1 < path.size() ? " -> " : "");
                }
                std::cout << '\n';
            }
            break;
        }
        case 13:
            tree.clear();
            std::cout << "Tree cleared.\n";
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}