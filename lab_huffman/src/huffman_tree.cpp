/**
 * @file huffman_tree.cpp
 * Implementation of a Huffman Tree class.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#include "huffman_tree.h"
#define CS225_SOLUTION
using namespace std;

HuffmanTree::HuffmanTree(vector<Frequency> frequencies)
{
    std::stable_sort(frequencies.begin(), frequencies.end());
    buildTree(frequencies);
    vector<bool> path;
    buildMap(root_, path);
}

HuffmanTree::HuffmanTree(const HuffmanTree& other)
{
    copy(other);
}

HuffmanTree::HuffmanTree(BinaryFileReader& bfile)
{
    root_ = readTree(bfile);
    vector<bool> path;
    buildMap(root_, path);
}

HuffmanTree::~HuffmanTree()
{
    clear(root_);
}

const HuffmanTree& HuffmanTree::operator=(const HuffmanTree& rhs)
{
    if (this != &rhs) {
        clear(root_);
        copy(rhs);
    }
    return *this;
}

void HuffmanTree::clear(TreeNode* current)
{
    if (current == NULL)
        return;
    clear(current->left);
    clear(current->right);
    delete current;
}

void HuffmanTree::copy(const HuffmanTree& rhs)
{
    root_ = copy(rhs.root_);
}

HuffmanTree::TreeNode* HuffmanTree::copy(const TreeNode* current)
{
    if (current == NULL)
        return NULL;
    TreeNode* node = new TreeNode(current->freq);
    node->left = copy(current->left);
    node->right = copy(current->right);
    return node;
}

HuffmanTree::TreeNode*
HuffmanTree::removeSmallest(queue<TreeNode*>& singleQueue,
                            queue<TreeNode*>& mergeQueue)
{

    /**
     * @todo Your code here!
     *
     * Remove the smallest TreeNode * from the two queues given as
     * parameters. The entries on the queues are in sorted order, so the
     * smaller of the two queues heads is the smallest item in either of
     * the queues. Return this item after removing it from its queue.
     */

    std::cout << "remove smallest" << std::endl;
    // // print both queues to std::cout
    // std::cout << "print both queues to std::cout" <<std::endl;
    // auto copySingle = singleQueue;
    // auto copyMerge = mergeQueue;

    //  std::cout << "single: " << std::endl;
    //  while (!copySingle.empty()) {
    //     TreeNode* current = copySingle.front();
    //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
    //     copySingle.pop();
    //  }
    //  std::cout << "merge: " << std::endl;
    //  while (!copyMerge.empty()) {
    //     TreeNode* current = copyMerge.front();
    //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
    //     copyMerge.pop();
    //  }

    // std::cout << "test1" << std::endl;

    // TreeNode* single = singleQueue.front();
    // TreeNode* merge = mergeQueue.front();

    if (singleQueue.empty() && mergeQueue.empty()) {
        // std::cout << "test3" << std::endl;
        TreeNode* temp = nullptr;
        return temp;
    } else if (singleQueue.empty()) { //could move this outside of this function but keeping this here for code versatility, and for future plans
        // std::cout << "test4" << std::endl;
        TreeNode* merge = mergeQueue.front();
        mergeQueue.pop();
        return merge;
    } else if (mergeQueue.empty()) {
        // std::cout << "test5" << std::endl;
        TreeNode* single = singleQueue.front();
        singleQueue.pop();
        return single;
    }

    // std::cout << "test2" << std::endl;

    TreeNode* single = singleQueue.front();
    TreeNode* merge = mergeQueue.front();

    // std::cout << "test6" << std::endl;

    int singleFreq = single->freq.getFrequency();
    // std::cout << "test7" << std::endl;
    int mergeFreq = merge->freq.getFrequency();
    // std::cout << "test8" << std::endl;

    if (singleFreq > mergeFreq) {
        // std::cout << "test9" << std::endl;
        mergeQueue.pop();
        // std::cout << "test10" << std::endl;
        return merge;
    }
    // std::cout << "test11" << std::endl;
    singleQueue.pop();
    // std::cout << "test12" << std::endl;
    // std::cout << single->freq.getCharacter() << " " << single->freq.getFrequency() << std::endl;
    // std::cout << merge->freq.getCharacter() << " " << merge->freq.getFrequency() << std::endl;
    return single;
}

void HuffmanTree::buildTree(const vector<Frequency>& frequencies)
{
    queue<TreeNode*> singleQueue; // Queue containing the leaf nodes
    queue<TreeNode*> mergeQueue;  // Queue containing the inner nodes

    /**
     * @todo Your code here!
     *
     * First, place all of the leaf nodes into the singleQueue in
     * increasing order of frequency. Note: frequencies is already sorted
     * for you.
     *
     * Next, until there is only one node on the two queues (that is, one
     * of the queues is empty and one has a single node), remove the two
     * smallest entries from the two queues. Then, create a new internal
     * node with these nodes as children, whose frequency is the sum of
     * these two children's frequencies. Place the new internal node onto
     * the back of the mergeQueue.
     *
     * Finally, when there is a single node left, it is the root. Assign it
     * to the root and you're done!
     */

    //build tree
    std::cout << "build tree" << std::endl;

    //  std::cout << "tree: " << std::endl;
    //  this->printInOrder();

    // //  print both queues to std::cout
    //  std::cout << "print both queues to std::cout" << std::endl;
    //  auto copySingle = singleQueue;
    //  auto copyMerge = mergeQueue;

    //  std::cout << "single: " << std::endl;
    //  while (!copySingle.empty()) {
    //     TreeNode* current = copySingle.front();
    //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
    //     copySingle.pop();
    //  }
    //  std::cout << "merge: " << std::endl;
    //  while (!copyMerge.empty()) {
    //     TreeNode* current = copyMerge.front();
    //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
    //     copyMerge.pop();
    //  }


    // std::cout << "add all nodes in frequency to singleQueue" << std::endl;
    //add all nodes in frequency to singleQueue
    for (Frequency freq : frequencies) { //already sorted
        // std::cout << "add frequency: " << freq.getCharacter() << " " << freq.getFrequency() << std::endl;
        TreeNode* temp = new TreeNode(freq);
        singleQueue.push(temp);
    }

    // // print both queues to std::cout
    //  std::cout << "print both queues to std::cout" << std::endl;
    //  copySingle = singleQueue;
    //  copyMerge = mergeQueue;

    //  std::cout << "single: " << std::endl;
    //  while (!copySingle.empty()) {
    //     TreeNode* current = copySingle.front();
    //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
    //     copySingle.pop();
    //  }
    //  std::cout << "merge: " << std::endl;
    //  while (!copyMerge.empty()) {
    //     TreeNode* current = copyMerge.front();
    //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
    //     copyMerge.pop();
    //  }
    //  std::cout << "end" << std::endl;

     int count = 0;

    while (singleQueue.size() + mergeQueue.size() > 1) {  // && count < 100
        // std::cout << "remove small1" << std::endl;
        TreeNode* small1 = removeSmallest(singleQueue, mergeQueue);
        int small1Freq = small1->freq.getFrequency();
        char small1Char = small1->freq.getCharacter();
        // std::cout << "small1: " << small1Char << " " << small1Freq << std::endl;
        count++;
        // if (small1 == nullptr) {
        //     std::cout << "small1 == nullptr" << endl;
        //    return;
        // }
        
        // std::cout << "remove small2" << std::endl;
        TreeNode* small2 = removeSmallest(singleQueue, mergeQueue);
        // if (small2 == nullptr) {
        //     std::cout << "small2 == nullptr" << endl;
        //    return;
        // }
        int small2Freq = small2->freq.getFrequency();
        char small2Char = small2->freq.getCharacter();
        // std::cout << "small2: " << small2Char << " " << small2Freq << std::endl;

        // std::cout << "make new" << std::endl;
        TreeNode* newNode = new TreeNode(Frequency(small1Freq + small2Freq));
        newNode->left = small1;
        newNode->right = small2;
        // std::cout << "node: " << newNode->freq.getCharacter() << " " << newNode->freq.getFrequency() << std::endl;

        mergeQueue.push(newNode);

        // // print both queues to std::cout
        // std::cout << "print both queues to std::cout" << std::endl;
        // copySingle = singleQueue;
        // copyMerge = mergeQueue;

        // std::cout << "single: " << std::endl;
        // while (!copySingle.empty()) {
        //     TreeNode* current = copySingle.front();
        //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
        //     copySingle.pop();
        // }
        // std::cout << "merge: " << std::endl;
        // while (!copyMerge.empty()) {
        //     TreeNode* current = copyMerge.front();
        //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
        //     copyMerge.pop();
        // }
        // std::cout << "end" << std::endl;

        if (singleQueue.empty() && (mergeQueue.size() == 1)) {
            break;
        }
        if (mergeQueue.empty() && (singleQueue.size() == 1)) { //this should never happen
            std::cout << "warning: unintended behaviour" << std::endl;
            break;
        }
    }

    // // print both queues to std::cout
    //  std::cout << "print both queues to std::cout" << std::endl;
    //  copySingle = singleQueue;
    //  copyMerge = mergeQueue;

    //  std::cout << "single: " << std::endl;
    //  while (!copySingle.empty()) {
    //     TreeNode* current = copySingle.front();
    //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
    //     copySingle.pop();
    //  }
    //  std::cout << "merge: " << std::endl;
    //  while (!copyMerge.empty()) {
    //     TreeNode* current = copyMerge.front();
    //     std::cout << current->freq.getCharacter() << " " << current->freq.getFrequency() << std::endl;
    //     copyMerge.pop();
    //  }

    if (!mergeQueue.empty()) {
        root_ = mergeQueue.front();
        mergeQueue.pop();
    } else if (!singleQueue.empty()) {
        std::cout << "warning: unintended behaviour" << std::endl; //actually, this could happen if there was only one node
        root_ = singleQueue.front(); //just in case, for some reason this were to happen,
        singleQueue.pop();
    } else {
        root_ = NULL;
    }

    // std::cout << "tree: " << std::endl;
    // this->printInOrder();

}

string HuffmanTree::decodeFile(BinaryFileReader& bfile)
{
    stringstream ss;
    decode(ss, bfile);
    return ss.str();
}

void HuffmanTree::decode(stringstream& ss, BinaryFileReader& bfile)
{
    TreeNode* current = root_;
    while (bfile.hasBits()) {
        /**
         * @todo Your code here!
         *
         * This code is reading in all of the bits in the binary file
         * given. After reading a bit, we go left if the bit was a 0 (or
         * false), and we go right if the bit was a 1 (or true).
         *
         * Special case: if we are at a leaf node, we should "print" its
         * character to the stringstream (with operator<<, just like cout)
         * and start traversing from the root node again.
         */
         char c = bfile.getNextBit();

         if (c == 0 && current != nullptr) {
            // std::cout << "left: " << c << std::endl;
            current = current->left;
         } else if (c == 1 && current != nullptr) {
            // std::cout << "right: " << c << std::endl;
            current = current->right;
         }
         if (current != nullptr && current->left == nullptr && current->right == nullptr) {
                ss << current->freq.getCharacter();
                // std::cout << current->freq.getCharacter() << std::endl;
            current = root_;
         }
         if (current == nullptr) {
            current = root_;
         }
    }
}

void HuffmanTree::writeTree(BinaryFileWriter& bfile)
{
    writeTree(root_, bfile);
}

void HuffmanTree::writeTree(TreeNode* current, BinaryFileWriter& bfile)
{
    /**
     * @todo Your code here!
     *
     * This code is writing the current HuffmanTree in a compressed format
     * to the given BinaryFileWriter. The strategy for doing so is as
     * follows:
     *      1. If we are a leaf node, write the bit "1" followed by the
     *         byte that is the character of this node.
     *      2. If we are an internal node, writ the bit "0", and then
     *         encode the left and right subtree, recursively.
     *
     * Note that we don't encode the frequencies in this compressed
     * version: this is fine, as the structure of the tree still reflects
     * what the relative frequencies were.
     */

        this->print(std::cout);
     if (current == nullptr) {
        return;
     } if (current->left == nullptr && current->right == nullptr) {
        std::cout << "1" << std::endl;
        bfile.writeBit(1);
        std::cout << current->freq.getCharacter() << std::endl;
        bfile.writeBit(current->freq.getCharacter());
     } else {
        bfile.writeBit(0);
        std::cout << "0" << std::endl;
        writeTree(current->left, bfile);
        writeTree(current->right, bfile);
     }
}

HuffmanTree::TreeNode* HuffmanTree::readTree(BinaryFileReader& bfile)
{
    /**
     * @todo Your code here!
     *
     * This code is reading a HuffanTree in from a file in the format that
     * we wrote it above. The strategy, then, is as follows:
     *      1. If the file has no more bits, we're done.
     *      2. If we read a 1 bit, we are a leaf node: create a new
     *         TreeNode with the character that is the next byte in the
     *         file (its frequency should be 0, since we are ignoring
     *         frequency data now).
     *      3. If we read a 0 bit, create a new internal node (with
     *         frequency 0, since we are ignoring them now, and set its left
     *         child and right children to be the subtrees built recursively.
     *      4. Your function should return the TreeNode it creates, or NULL
     *         if it did not create one.
     */

     if (!bfile.hasBits()) {
        return NULL;
     }

     TreeNode* newNode = nullptr;

        char c = bfile.getNextBit();
        std::cout << c << std::endl;
        if (c == 1) {
            newNode = new TreeNode(Frequency(bfile.getNextByte(), 0));
            std::cout << newNode->freq.getCharacter() << std::endl;
        } else if (c == 0) {
           newNode = new TreeNode(0);
           newNode->left = readTree(bfile);
           newNode->right = readTree(bfile);
        }

    return newNode;
}

void HuffmanTree::buildMap(TreeNode* current, vector<bool>& path)
{
    // Base case: leaf node.
    if (current->left == NULL && current->right == NULL) {
        bitsMap_[current->freq.getCharacter()] = path;
        return;
    }

    // Move left
    path.push_back(false);
    buildMap(current->left, path);
    path.pop_back();

    // Move right
    path.push_back(true);
    buildMap(current->right, path);
    path.pop_back();
}

void HuffmanTree::printInOrder() const
{
    printInOrder(root_);
    cout << endl;
}

void HuffmanTree::printInOrder(const TreeNode* current) const
{
    if (current == NULL)
        return;
    printInOrder(current->left);
    cout << current->freq.getCharacter() << ":" << current->freq.getFrequency()
         << " ";
    printInOrder(current->right);
}

void HuffmanTree::writeToFile(const string& data, BinaryFileWriter& bfile)
{
    for (auto it = data.begin(); it != data.end(); ++it)
        writeToFile(*it, bfile);
}

void HuffmanTree::writeToFile(char c, BinaryFileWriter& bfile)
{
    vector<bool> bits = getBitsForChar(c);
    for (auto it = bits.begin(); it != bits.end(); ++it)
        bfile.writeBit(*it);
}

vector<bool> HuffmanTree::getBitsForChar(char c)
{
    return bitsMap_[c];
}

// class for generic printing

template <typename TreeNode>
class HuffmanTreeNodeDescriptor
    : public GenericNodeDescriptor<HuffmanTreeNodeDescriptor<TreeNode>>
{
  public:
    HuffmanTreeNodeDescriptor(const TreeNode* root) : subRoot_(root)
    { /* nothing */
    }

    string key() const
    {
        std::stringstream ss;
        char ch = subRoot_->freq.getCharacter();
        int freq = subRoot_->freq.getFrequency();

        // print the sum of the two child frequencies
        if (ch == '\0')
            ss << freq;
        // print the leaf containing a character and its count
        else {
            if (ch == '\n')
                ss << "\\n";
            else
                ss << ch;
            ss << ":" << freq;
        }
        return ss.str();
    }

    bool isNull() const
    {
        return subRoot_ == NULL;
    }
    HuffmanTreeNodeDescriptor left() const
    {
        return HuffmanTreeNodeDescriptor(subRoot_->left);
    }
    HuffmanTreeNodeDescriptor right() const
    {
        return HuffmanTreeNodeDescriptor(subRoot_->right);
    }

  private:
    const TreeNode* subRoot_;
};

int HuffmanTree::height(const TreeNode* subRoot) const
{
    if (subRoot == NULL)
        return -1;
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

void HuffmanTree::print(std::ostream& out) const
{
    int h = height(root_);
    if (h > _max_print_height) {
        out << "Tree is too big to print. Try with a small file (e.g. "
               "data/small.txt)"
            << endl;
        return;
    }

    printTree(HuffmanTreeNodeDescriptor<TreeNode>(root_), out);
}

Frequency
HuffmanTree::testRemoveSmallest(vector<Frequency> single,
                                vector<Frequency> merge)
{
    queue<TreeNode*> singleQueue;
    queue<TreeNode*> mergeQueue;
    for (auto it = single.begin(); it != single.end(); ++it) {
         singleQueue.push(new TreeNode(*it));
    }
    for (auto it = merge.begin(); it != merge.end(); ++it) {
         mergeQueue.push(new TreeNode(*it));
    }

    TreeNode* testNode = removeSmallest(singleQueue, mergeQueue);
    Frequency testFreq = testNode->freq;

    delete testNode;
    while (!singleQueue.empty()) {
        delete singleQueue.front();
        singleQueue.pop();
    }
    while (!mergeQueue.empty()) {
        delete mergeQueue.front();
        mergeQueue.pop();
    }

    return testFreq;
}
