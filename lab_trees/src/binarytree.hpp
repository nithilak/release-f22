/**
 * @file binarytree.hpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirror(root);
}

//helpers
    template <typename T>
void BinaryTree<T>::mirror(Node* node) {
    // std::cout << "mirror" << std::endl;
    if (node == nullptr) {
        return;
    }
    // std::cout << "mirror left" << std::endl;
    if (node->left != nullptr) {
        mirror(node->left);
    }
    // // std::cout << "mirror right" << std::endl;
    if (node->right != nullptr) {
        mirror(node->right);
    }

    // std::cout << node->elem << std::endl;
    Node* temp = node->right;
    node->right = node->left;
    node->left = temp;

}

/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive(Node* node, int max) const
{
    // your code here
    if (node == nullptr) {
        return true;
    }
    std::cout << "node: " << node->elem << std::endl;
    if (node->left == nullptr && node->right == nullptr) {
        return true;
    }
    if (node->left != nullptr && (node->left->elem >= max || node->left->elem >= node->elem)) {
        return false;
    }
    if (node->right != nullptr && (node->right->elem < max || node->right->elem < node->elem)) {
        return false;
    }

    return isOrderedRecursive(node->left, max) && isOrderedRecursive(node->right, max);
    
}

template <typename T>
bool BinaryTree<T>::isOrderedIterative() const {
    if (root == nullptr) {
        return true;
    }
    std::vector<int> nums;
    int max = root->elem;
    std::stack<Node*> stack;
    Node* current = root;
    while (current != NULL) {
        stack.push(current);
        current = current->left;
    }
    while (!stack.empty()) {
        // std::cout << stack.top()->elem << std::endl;
        nums.push_back(stack.top()->elem);
        current = stack.top()->right;
        stack.pop();
        while (current != NULL) {
            stack.push(current);
            current = current->left;
        }
    }


    // while (!nums.empty()) {
    //     int top = nums.top();
    //     nums.pop();
    //     std::cout << top << std::endl;
    //     if (nums.empty()) {
    //         break;
    //     }
    //     int top_next = nums.top();
    //     // nums.pop();
    //     if (top > top_next) {
    //         return false;
    //     }

    // }

    for (size_t i = 0; i + 1 < nums.size(); i++) {
        std::cout << i << " ";
        if (nums.at(i) > nums.at(i + 1)) {
            return false;
        }
    }
    std::cout << std::endl;

    return true;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    if (root == nullptr) {
        return true;
    }
    std::cout << "max: " << root->elem << std::endl;
    return isOrderedRecursive(root, root->elem);
}

