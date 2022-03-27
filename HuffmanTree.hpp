#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanBase.cpp"
#include "HeapQueue.hpp"
#include <map>
#include <vector>


class HuffmanTree : public HuffmanTreeBase {
  public:
  HuffmanTree();
  ~HuffmanTree();
  std::string compress(const std::string inputStr);
  std::string serializeTree() const;
  std::string decompress(const std::string inputCode, const std::string serializedTree);
  void preorder(HuffmanNode *node, std::map<char, std::string> *map, std::string s);

  private:
  HeapQueue<HuffmanNode*, HuffmanNode::Compare> hq;
};

#endif /* HUFFMANBASE_H */
