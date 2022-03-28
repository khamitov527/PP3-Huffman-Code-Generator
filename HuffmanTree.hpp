#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanBase.hpp"
#include "HeapQueue.hpp"
#include <map>
#include <vector>
#include <stack>


class HuffmanTree : public HuffmanTreeBase {
  public:
  HuffmanTree();
  ~HuffmanTree();
  std::string compress(const std::string inputStr);
  std::string serializeTree() const;
  std::string decompress(const std::string inputCode, const std::string serializedTree);
  void preorder(HuffmanNode *node, std::map<char, std::string> *map, std::string s);
  void serialize(HuffmanNode *node, std::string &s) const;

  private:
  HeapQueue<HuffmanNode*, HuffmanNode::Compare> hq;
  HuffmanNode *root;
};

#endif /* HUFFMANBASE_H */
