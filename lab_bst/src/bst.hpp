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


        if (first != nullptr) {
            std::cout << "first: " << first->key << std::endl;
            if (first->left != nullptr) { 
                std::cout << "first->left: " << first->left->key << std::endl;
            } else {
                std::cout << "first->left: nullptr" << std::endl;
            }
            if (first->right != nullptr) {
                std::cout << "first->right: " << first->right->key << std::endl;
            } else {
                std::cout << "first->right: nullptr" << std::endl;
            }
        } else {
            std::cout << "first: nullptr" << std::endl;
        }
        if (second != nullptr) {
            std::cout << "second: " << second->key << std::endl;
            if (second->left != nullptr) { 
                std::cout << "second->left: " << second->left->key << std::endl;
            } else {
                std::cout << "second->left: nullptr" << std::endl;
            }
            if (second->right != nullptr) {
                std::cout << "second->right: " << second->right->key << std::endl;
            } else {
                std::cout << "seocnd->right: nullptr" << std::endl;
            }
        } else {
            std::cout << "second: nullptr" << std::endl;
        }

        first = second_temp;
        second = first_temp;
    
        if (first != nullptr) {
            first->left = first_left_temp;
            first->right = first_right_temp;
        }
        if (second != nullptr) {
            second->left = second_left_temp;
            second->right = second_right_temp;
        }

       if (first != nullptr) {
            std::cout << "first: " << first->key << std::endl;
            if (first->left != nullptr) { 
                std::cout << "first->left: " << first->left->key << std::endl;
            } else {
                std::cout << "first->left: nullptr" << std::endl;
            }
            if (first->right != nullptr) {
                std::cout << "first->right: " << first->right->key << std::endl;
            } else {
                std::cout << "first->right: nullptr" << std::endl;
            }
        } else {
            std::cout << "first: nullptr" << std::endl;
        }
        if (second != nullptr) {
            std::cout << "second: " << second->key << std::endl;
            if (second->left != nullptr) { 
                std::cout << "second->left: " << second->left->key << std::endl;
            } else {
                std::cout << "second->left: nullptr" << std::endl;
            }
            if (second->right != nullptr) {
                std::cout << "second->right: " << second->right->key << std::endl;
            } else {
                std::cout << "seocnd->right: nullptr" << std::endl;
            }
        } else {
            std::cout << "second: nullptr" << std::endl;
        }

    }
    // print();
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
    //left is not nullptr
    if (subtree != nullptr && subtree->left != nullptr && subtree->right == nullptr) {
        BST<K, V>::Node* temp2 = subtree->left;
        delete subtree;
        subtree = nullptr;
        subtree = temp2;
        return;
    }
    //right is not nullptr
    if (subtree != nullptr && subtree->left == nullptr && subtree->right != nullptr) {
        BST<K, V>::Node* temp2 = subtree->right;
        delete subtree;
        subtree = nullptr;
        subtree = temp2;
        return;
    }

    //2child
    if (subtree != nullptr && subtree->left != nullptr && subtree->right != nullptr) {
        
        //go smaller
        Node*& temp2 = subtree;
        temp2 = temp2->left;
        //get as close as you can to get bigger
        while (temp2 != nullptr && temp2->right != nullptr) { //&& temp2->right != nullptr
            temp2 = temp2->right; //to get to the insertion spot that we need
        }
        if (temp != nullptr) {
            std::cout << "temp: " << temp->key << std::endl;
        } else {
            std::cout << "temp: nullptr" << std::endl;
        }
        if (temp2 != nullptr) {
            std::cout << "temp2: " << temp2->key << std::endl;
        } else {
            std::cout << "temp2: nullptr" << std::endl;
        }

        // Node*& temp3 = find(temp2->key);


        swap(temp->left, temp2); //something is wrong here

        // while (temp2 != nullptr && temp2->right != nullptr) {
        //     temp2 = temp2->right;
        // }

        // std::cout << "temp: " << temp->key << std::endl;
        // std::cout << "temp2: " << temp2->key << std::endl;

        // delete temp2;
        // temp2 = nullptr;

        // delete temp2;
        // temp2 = nullptr;

        if (temp2 != nullptr) {
            
        }

        print();












        // //go smaller
        // Node* temp2 = subtree;
        // std::cout << "temp: " << temp->key << std::endl;
        // std::cout << "temp2: " << temp2->key << std::endl;
        // temp2 = temp2->left;
        // //get as close as you can to get bigger
        // while (temp != nullptr && temp->right != nullptr) {
        //     temp = temp->right;
        // }
        // std::cout << "temp: " << temp->key << std::endl;
        // std::cout << "temp2: " << temp2->key << std::endl;
        // swap(temp, temp2); //something is wrong here
        // std::cout << "temp: " << temp->key << std::endl;
        // std::cout << "temp2: " << temp2->key << std::endl;
        // delete temp2;
        // temp2 = nullptr;
        // std::cout << "temp: " << temp->key << std::endl;
        // std::cout << "temp2: " << temp2 << std::endl;
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

    // size_t n_factorial = 1;
     
    // for (size_t i = 1; i <= inList.size(); i++) {
    //     n_factorial *= i;
    // }
    
    std::vector<int> output;
    if (inList.size() <= 0) {
        return output;
    }
    std::sort(inList.begin(), inList.end());

    do {
        // std::cout << "output size: " << output.size() << std::endl;
        BST<K, V> bst = listBuild(inList);
        size_t height = bst.height();
        // std::cout << "height " << height << std::endl;
        while (height >= output.size()) {
            output.push_back(0);
        }
        output.at(height) += 2;
        std::next_permutation(inList.begin(), inList.end());
    } while (std::next_permutation(inList.begin(), inList.end()));

    // for (size_t i = 0; i < output.size(); i++) {
    //     output.at(i) *= 2;
    // }

    return output;
}