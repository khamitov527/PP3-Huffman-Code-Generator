#include "HuffmanTree.hpp"


std::string HuffmanTree::compress(const std::string inputStr)
{
    std::map<char, int> freqList;
    std::map<char, std::string> prefixList;
    HeapQueue<HuffmanNode*, HuffmanNode::Compare> hq;
    VectorCompleteTree<HuffmanNode*> vt;

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

        hnL->parent = hnP;
        hnR->parent = hnP;

        vt.addLast(hnL);
        vt.addLast(hnR);
    }
    vt.addLast(hq.min());
    hq.removeMin();
    
    for (auto iter = vt.root(); iter == vt.last(); ++iter){
        
    }
    


    // std::vector< std::pair<int, char> > vec;

    // HeapQueue<int, char> hq;

    // for(int i = 0; i < vec.size(); i++){
    //     hq.insert(vec[i].first);
    // }  

}

std::string HuffmanTree::serializeTree()
{
}

std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree)
{
}

// int main(){

//     std::string inputStr = "aaaaaa";

//     std::map<char, int> freqList;	

//     for(int i = 0; i < inputStr.size(); i++){
//         freqList[inputStr[i]]++;
//     }

//     HeapQueue<char, int> hq;

//     for(int i = 0; i < inputStr.size(); i++){
//         hq.insert(freqList[i]);
//     }
//     return 0;
// }