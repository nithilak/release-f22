/**
 * @file bst.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V BST<K, V>::find(const K& key)
{
    // your code here
    
   struct BST<K, V>::Node*& node = find(root, key);
    if (node == nullptr) {
        return V();
    } else {
        return node->value;
    }

}

template <class K, class V>
struct BST<K, V>::Node* & BST<K, V>::find(Node* & subtree, const K& key)
{
    // Your code here
    if (subtree == nullptr || subtree->key == key) {
        return subtree;
    } 
    // BST<K, V>::Node* & subtree_left = subtree->left;
    // BST<K, V>::Node* & subtree_right = subtree->right;
    if (subtree->key < key) {
        return find(subtree->right, key);
    } 
    return find(subtree->left, key);
}

template <class K, class V>
void BST<K, V>::insert(const K & key, const V & value)
{
    // your code here
    struct BST<K, V>::Node*& node = find(root, key);
    // std::cout << node << std::endl;
    if (node == nullptr) {
        node = new Node(key, value);
    }
}

template <class K, class V>
void BST<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    struct BST<K, V>::Node*& node = find(root, key);
    // std::cout << node << std::endl;
    if (node == nullptr) {
        node = subtree;
    }
    //     } else { //do not modify the original tree
    //         node->value = value;
    //     }    
}

template <class K, class V>
void BST<K, V>::swap(Node*& first, Node*& second)
{
    // your code here
    if (first == nullptr && second == nullptr) {
        return;
    } else {
        Node* first_temp = first;
        Node* first_left_temp = nullptr;
        Node* first_right_temp = nullptr;
        if (first != nullptr) {
           first_left_temp = first->left;
           first_right_temp = first->right;
        }

        Node* second_temp = second;
        Node* second_left_temp = nullptr;
        Node* second_right_temp = nullptr;
        if (second != nullptr) {
            second_left_temp = second->left;
            second_right_temp = second->right;
        }

        // if (first != nullptr) {
        //     first->left = second_left_temp;
        //     first->right = second_right_temp;
        // }
        first = second_temp;

        // if (second != nullptr) {
        //     second->left = first_left_temp;
        //     second->right = first_right_temp;
        // }
        second = first_temp;


    }
}

template <class K, class V>
void BST<K, V>::remove(const K& key)
{
    // your code here
    struct BST<K, V>::Node*& node = find(root, key);
    if (node != nullptr) {
        remove(node, key);
    }

}

template <class K, class V>
void BST<K, V>::remove(Node*& subtree, const K& key)
{
    // your code here

    if (subtree == nullptr) {
        return;
    }
    
    BST<K, V>::Node* temp = subtree;

    //0 child
    if (subtree != nullptr && subtree->left == nullptr && subtree->right == nullptr) {
        delete temp;
        subtree = nullptr;
        return;
    }

    //1child
    if (subtree != nullptr && subtree->left == nullptr) {
        BST<K, V>::Node* temp2 = subtree->left;
        delete subtree;
        subtree = nullptr;
        subtree = temp2;
        return;
    }
    if (subtree != nullptr && subtree->right == nullptr) {
        BST<K, V>::Node* temp2 = subtree->right;
        delete subtree;
        subtree = nullptr;
        subtree = temp2;
        return;
    }

    //2child
    if (subtree != nullptr) {
        subtree = subtree->left;
        while (subtree != nullptr && subtree->right != nullptr) {
            subtree = subtree->right;
        }
        swap(temp, subtree);
        delete subtree;
        subtree = nullptr;
    }
}

template <class K, class V>
BST<K, V> listBuild(std::vector<std::pair<K, V>> inList){
    // your code here
    BST<K, V> bst;
    for (std::pair<K, V> elem : inList) {
        bst.insert(elem.first, elem.second);
    }
    return bst;
}

template <class K, class V>
std::vector<int> allBuild(std::vector<std::pair<K, V>> inList){
    // your code here
    std::vector<int> output;
    if (inList.size() <= 0) {
        return output;
    }
    std::stable_sort(inList.begin(), inList.end());

    size_t n_factorial = 1;

    for (size_t i = 1; i <= inList.size(); i++) {
        n_factorial *= i;
    }

    for (size_t i = 0; i < n_factorial; i++) {
        BST<K, V> bst = listBuild(inList);
        output.push_back(bst.height());
        std::next_permutation(inList.begin(), inList.end());
    }

    return output;
}