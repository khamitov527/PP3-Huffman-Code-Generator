#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanBase.hpp"
#include "HeapQueue.hpp"
#include <map>
#include <vector>


class HuffmanTree : public HuffmanTreeBase {
  HuffmanTree();
  ~ HuffmanTree();
  public:
  std::string compress(const std::string inputStr);
  std::string serializeTree();
  std::string decompress(const std::string inputCode, const std::string serializedTree);
  void preorder(HuffmanNode *root, std::string s);

  private:
  std::map<char, std::string> prefixList;
  HeapQueue<HuffmanNode*, HuffmanNode::Compare> hq;
  std::string str;
};

#endif /* HUFFMANBASE_H */