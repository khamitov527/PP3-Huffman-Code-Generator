#include "HuffmanTree.hpp"

HuffmanTree::HuffmanTree() {

};
  
HuffmanTree::~HuffmanTree() {

};


std::string HuffmanTree::compress(const std::string inputStr)
{
    std::map<char, int> freqList;
    std::map<char, std::string> *prefixList = new std::map<char, std::string>;
    std::string output;

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

    std::string str = "";
    preorder(hq.min(), prefixList, str);

    for(int i = 0; i < inputStr.size(); i++) {
        output.append((*prefixList)[inputStr[i]]);
    }
    
    return output;
}


void HuffmanTree::preorder(HuffmanNode *node, std::map<char, std::string> *map, std::string s) {   
    if(node == nullptr)
        return;

    std::cout << node->getCharacter() << ": " << node->getFrequency() << " - " << s << std::endl;

    if(node->isLeaf()){
        (*map)[node->getCharacter()] = s;
    }
    preorder(node->left, map, s.append("0"));
    s.pop_back();
    preorder(node->right, map, s.append("1"));
}


std::string HuffmanTree::serializeTree() const
{
    return " ";
}

std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree)
{
    return " ";
}
