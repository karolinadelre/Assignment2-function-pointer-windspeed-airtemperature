#ifndef BST_H
#define BST_H


/**
 * @brief A template class representing a Binary Search Tree (BST).
 *
 * @tparam T The type of data stored in the tree.
 */
template <class T>
class Bst {
public:
    /**
     * @brief Constructor to initialize an empty BST.
     */
    Bst();

    /**
     * @brief Copy constructor to create a copy of an existing BST.
     *
     * @param other The BST to copy from.
     */
    Bst(const Bst<T>& other);

    /**
     * @brief Assignment operator to copy an existing BST.
     *
     * @param other The BST to copy from.
     * @return A reference to the copied BST.
     */
    Bst<T>& operator=(const Bst<T>& other);

    /**
     * @brief Destructor to delete all nodes in the BST.
     */
    ~Bst();

    /**
     * @brief Inserts a new value into the binary search tree.
     *
     * @param value The value to be inserted.
     */
    void insert(T value);

    /**
     * @brief Searches for a value in the binary search tree.
     *
     * @param value The value to search for.
     * @return true if the value is found, false otherwise.
     */
    bool search(T value) const;

    /**
     * @brief Performs an in-order traversal of the binary search tree.
     *
     * @param visit Pointer to a function to call on each node's data.
     */
    void inOrderTraversal(void (*visit)(T)) const;

    /**
     * @brief Performs a pre-order traversal of the binary search tree.
     *
     * @param visit Pointer to a function to call on each node's data.
     */
    void preOrderTraversal(void (*visit)(T)) const;

    /**
     * @brief Performs a post-order traversal of the binary search tree.
     *
     * @param visit Pointer to a function to call on each node's data.
     */
    void postOrderTraversal(void (*visit)(T)) const;

    /**
     * @brief Deletes all nodes in the binary search tree.
     */
    void deleteTree();

private:
    // Node struct represents a single node in the binary search tree
    struct Node {
        T data; ///< Data stored in the node
        Node* left; ///< Pointer to the left child node
        Node* right; ///< Pointer to the right child node

        /**
         * @brief Constructor to initialize a new node with the given value.
         *
         * @param value The value to be stored in the node.
         */
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root; ///< Pointer to the root node of the binary search tree

    // Private recursive methods
    /**
     * @brief Recursive helper function to insert a value into the BST.
     *
     * @param value The value to be inserted.
     * @param node The current node being considered.
     * @return A pointer to the root node after insertion.
     */
    Node* insert(T value, Node* node);

    /**
     * @brief Recursive helper function to search for a value in the BST.
     *
     * @param value The value to search for.
     * @param node The current node being considered.
     * @return true if the value is found, false otherwise.
     */
    bool search(T value, Node* node) const;

    /**
     * @brief Recursive helper function to perform an in-order traversal of the BST.
     *
     * @param node The current node being considered.
     * @param visit Pointer to a function to call on each node's data.
     */
    void inOrderTraversal(Node* node, void (*visit)(T)) const;

    /**
     * @brief Recursive helper function to perform a pre-order traversal of the BST.
     *
     * @param node The current node being considered.
     * @param visit Pointer to a function to call on each node's data.
     */
    void preOrderTraversal(Node* node, void (*visit)(T)) const;

    /**
     * @brief Recursive helper function to perform a post-order traversal of the BST.
     *
     * @param node The current node being considered.
     * @param visit Pointer to a function to call on each node's data.
     */
    void postOrderTraversal(Node* node, void (*visit)(T)) const;

    /**
     * @brief Recursive helper function to delete all nodes in the BST.
     *
     * @param node The current node being considered.
     */
    void deleteTree(Node* node);

    /**
     * @brief Recursive helper function to copy a tree.
     *
     * @param node The current node being copied.
     * @return A pointer to the new node that is a copy of the current node.
     */
    Node* copyTree(Node* node);
};

// Implementation of methods

template <class T>
Bst<T>::Bst() : root(nullptr) {
    // Constructor: Initializes the root pointer to nullptr
}

template <class T>
Bst<T>::Bst(const Bst<T>& other) : root(nullptr) {
    // Copy constructor: Creates a copy of another Bst object
    root = copyTree(other.root);
}

template <class T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other) {
    // Assignment operator: Copies an existing Bst object
    if (this != &other) {
        deleteTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

template <class T>
Bst<T>::~Bst() {
    // Destructor: Deletes all nodes in the BST
    deleteTree(root);
}

template <class T>
void Bst<T>::insert(T value) {
    // Inserts a new value into the binary search tree
    root = insert(value, root);
}

template <class T>
bool Bst<T>::search(T value) const {
    // Searches for a value in the binary search tree
    return search(value, root);
}

template <class T>
void Bst<T>::inOrderTraversal(void (*visit)(T)) const {
    // Performs an in-order traversal of the binary search tree
    inOrderTraversal(root, visit);
}

template <class T>
void Bst<T>::preOrderTraversal(void (*visit)(T)) const {
    // Performs a pre-order traversal of the binary search tree
    preOrderTraversal(root, visit);
}

template <class T>
void Bst<T>::postOrderTraversal(void (*visit)(T)) const {
    // Performs a post-order traversal of the binary search tree
    postOrderTraversal(root, visit);
}

template <class T>
void Bst<T>::deleteTree() {
    // Deletes all nodes in the binary search tree
    deleteTree(root);
    root = nullptr;
}

template <class T>
typename Bst<T>::Node* Bst<T>::insert(T value, Node* node) {
    // Recursive helper function to insert a value into the BST
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = insert(value, node->left);
    else if (value > node->data)
        node->right = insert(value, node->right);

    return node;
}

template <class T>
bool Bst<T>::search(T value, Node* node) const {
    // Recursive helper function to search for a value in the BST
    if (node == nullptr)
        return false;
    else if (node->data == value)
        return true;
    else if (value < node->data)
        return search(value, node->left);
    else
        return search(value, node->right);
}

template <class T>
void Bst<T>::inOrderTraversal(Node* node, void (*visit)(T)) const {
    // Recursive helper function to perform an in-order traversal of the BST
    if (node != nullptr) {
        inOrderTraversal(node->left, visit);
        visit(node->data);
        inOrderTraversal(node->right, visit);
    }
}

template <class T>
void Bst<T>::preOrderTraversal(Node* node, void (*visit)(T)) const {
    // Recursive helper function to perform a pre-order traversal of the BST
    if (node != nullptr) {
        visit(node->data);
        preOrderTraversal(node->left, visit);
        preOrderTraversal(node->right, visit);
    }
}

template <class T>
void Bst<T>::postOrderTraversal(Node* node, void (*visit)(T)) const {
    // Recursive helper function to perform a post-order traversal of the BST
    if (node != nullptr) {
        postOrderTraversal(node->left, visit);
        postOrderTraversal(node->right, visit);
        visit(node->data);
    }
}

template <class T>
void Bst<T>::deleteTree(Node* node) {
    // Recursive helper function to delete all nodes in the BST
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template <class T>
typename Bst<T>::Node* Bst<T>::copyTree(Node* node) {
    // Recursive helper function to copy a tree
    if (node == nullptr) {
        return nullptr;
    }

    Node* newNode = new Node(node->data);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);

    return newNode;
}

#endif // BST_H
