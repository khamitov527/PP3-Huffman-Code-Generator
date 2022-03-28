#include "HuffmanTree.hpp"

HuffmanTree::HuffmanTree() {

};
  
HuffmanTree::~HuffmanTree() {

};


std::string HuffmanTree::compress(const std::string inputStr)
{
    std::map<char, int> freqList;
    std::map<char, std::string> *prefixList = new std::map<char, std::string>;
    std::string output = "";

    for(int i = 0; i < inputStr.size(); i++){
        freqList[inputStr[i]]++;
    }

    for(int i = 0; i < inputStr.size(); i++){
        if(freqList[inputStr[i]] != 0){
            hq.insert(new HuffmanNode(inputStr[i], freqList[inputStr[i]]));
            freqList[inputStr[i]] = 0;
        }
    }

    while(hq.size() > 1){
        HuffmanNode *hnL = hq.min();
        hq.removeMin();
        HuffmanNode *hnR = hq.min();
        hq.removeMin();
        HuffmanNode *hnP = new HuffmanNode('\0', (hnL->getFrequency() + hnR->getFrequency()), nullptr, hnL, hnR);
        hnL->parent = hnP;
        hnR->parent = hnP;
        hq.insert(hnP);
    }

    root = hq.min();

    std::string str = "";
    preorder(root, prefixList, str);

    for(int i = 0; i < inputStr.size(); i++) {
        output.append((*prefixList)[inputStr[i]]);
    }
    
    return output;
}


void HuffmanTree::preorder(HuffmanNode *node, std::map<char, std::string> *map, std::string s) {   
    if(node == nullptr)
        return;

    if(node->isLeaf()){
        (*map)[node->getCharacter()] = s;
    }
    preorder(node->left, map, s.append("0"));
    s.pop_back();
    preorder(node->right, map, s.append("1"));
}

std::string HuffmanTree::serializeTree() const
{
    std::string output = "";

    if (root == nullptr) {
        return output;
    }

    serialize(root, output);
    
    return output;
}

void HuffmanTree::serialize(HuffmanNode *node, std::string &s) const {   
    if(node == nullptr)
        return;

    serialize(node->left, s);
    serialize(node->right, s);

    if (node->isBranch()) {
        s.append("B");
    } else if (node->isLeaf()) {
        std::string temp = "L";
        temp += node->getCharacter();
        s.append(temp);
    }
}

std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree)
{
    std::string output = "";
    std::stack<HuffmanNode*> deserializeTree;
    HuffmanNode *treeRoot;
    HuffmanNode *node;
    
    for (int i = 0; i < serializedTree.size(); i++) {
        if (serializedTree[i] == 'L') {
            continue;
        } else if (serializedTree[i] == 'B') {
            HuffmanNode *hnR = deserializeTree.top();
            deserializeTree.pop();
            HuffmanNode *hnL = deserializeTree.top();
            deserializeTree.pop();
            HuffmanNode *hnP = new HuffmanNode('\0', 0, nullptr, hnL, hnR);
            hnL->parent = hnP;
            hnR->parent = hnP;
            deserializeTree.push(hnP);

            if (deserializeTree.size() == 1) {
                treeRoot = hnP;
            }
        } else {
            deserializeTree.push(new HuffmanNode(serializedTree[i], 0));
        }
    }

    node = treeRoot;
    for (int i = 0; i < inputCode.size(); i++) {
        if (inputCode[i] == '0') {
            node = node->left;
        } else if (inputCode[i] == '1') {
            node = node->right;
        }

        if (node->isLeaf()) {
            output += node->getCharacter();
            node = treeRoot;
        }
    }
    
    return output;
}
