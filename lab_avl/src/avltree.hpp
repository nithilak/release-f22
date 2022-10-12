/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
int AVLTree<K, V>::height() const {
    return height(root);
}

template <class K, class V>
int AVLTree<K, V>::height(const Node* node) const {
    if (node == nullptr) {
        return -1;
    } 
    return 1 + std::max(height(node->left), height(node->right));
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    if (t == nullptr || (t->right == nullptr)) {
        return;
    }
    Node* tempa = t;
    Node* tempb = tempa->right;
    Node* tempc = tempb->left;

    Node*& a = t;
    Node*& b = a->right;
    Node*& c = b->left;

    //switching happens

    c = tempa;
    a = tempb;
    b = tempc;

    /*
    //ok so
    //just a rotation, no need for the why here

    //             root
    //                 \
    //                  55
    //                  / \
    //                34   64
    //                     / \      
    //                   56   70
    
    //             root
    //                 \
    //                  55
    //                  / \
    //                34   64
    //                      \      
    //                   56   70

    //             root
    //                 \
    //                  
    //                    \
    //                     64
    //                    /  \      
    //                   55   70
    //                  /  \
    //                34    56

    //               root
    //                   \
    //                    \
    //                     64
    //                    /  \      
    //                   55   70
    //                  /  \
    //                34    56

    //             root
    //                 \
    //                  64
    //                 /  \      
    //               55    70
    //              /  \      
    //            34    56


    //                 root
    //                    \ 
    //                   
    //              55      \
    //             /         64
    //         /  34          \      
    //        56               70

    //                 root
    //                    \ 
    //                    
    //                      \
    //                       64
    //         /            /  \      
    //        56          55    70
    //                    /        
    //                  34
    */
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    //copied from rotateLeft
    if (t == nullptr || (t->left == nullptr)) {
        return;
    }

    Node*& a = t;
    Node*& b = a->left;
    Node*& c = b->right;

    Node* tempa = a;
    Node* tempb = b;
    Node* tempc = c;

    c = tempa;
    a = tempb;
    b = tempc;

}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    //copied from rotateLeftRight, then right ->left, and also left ->right
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    // std::cout << "rebalance" << std::endl;
    int leftheight = heightOrNeg1(subtree->left);
    int rightheight = heightOrNeg1(subtree->right);
    if (leftheight < rightheight) {
        rotateLeft(subtree);
    } else if (leftheight > rightheight) {
        rotateRight(subtree);
    }
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (subtree == nullptr) {
        subtree = new Node(key, value);
        return;
    } else if (subtree != nullptr && subtree->key != key) {
        if (subtree->key > key) {
           insert(subtree->left, key, value);
        } else {
            insert(subtree->right, key, value);
        }
        //both left and right are set now
        // std::cout << "subtree: " << subtree << " " << subtree->key << " " << subtree->value << std::endl;
        // std::cout << "left: " << height(subtree->left) << std::endl;
        // std::cout << "right: " << height(subtree->right) << std::endl;
        int num = height(subtree->right) - height(subtree->left);
        // std::cout << "num: " << num << std::endl;
        // if (num < -1 || num > 1) {
            rebalance(subtree);
        // }
    }
    // if (root->value == 4) {
    //     rotateLeft(root);
    // }
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = nullptr;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* temp = subtree;
            Node*& place = subtree;
            place = place->left;
            while (place != nullptr && place->right != nullptr) {
                place = place->right;
            }
            subtree = place;
            place = temp;
            delete temp;
            temp = nullptr;
        } else {
            /* one-child remove */
            // your code here
            Node* temp = subtree;
            if (subtree->right != nullptr) {
                subtree = subtree->right;
            } else {
                subtree = subtree->left;
            }
            delete temp;
            temp = nullptr;
        }
        // your code here
        rebalance(subtree);
    }
}
