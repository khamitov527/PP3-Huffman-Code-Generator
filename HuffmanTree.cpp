#include "HuffmanTree.hpp"


std::string HuffmanTree::compress(const std::string inputStr)
{

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
        HuffmanNode *hnP = new HuffmanNode(' ', hnL->getFrequency() + hnR->getFrequency(), nullptr, hnL, hnR);
        hq.insert(hnP);
    }

    preorder(hq.min(), str, prefixList);
    
    return str;
}


void preorder(HuffmanNode *root, std::string s, std::map<char, std::string> prefList){
    
    if(root == nullptr)
        return;

    if(root->isLeaf()){
        prefList[root->getCharacter()] = s;
    }
    preorder(root, s.append("0"), prefList);
    preorder(root, s.append("1"), prefList);
}


std::string HuffmanTree::serializeTree()
{
    return " ";
}

std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree)
{
    return " ";
}

int main(){

    HuffmanTree huf;
    std::string outputStr = huf.compress("abcd");
    
}