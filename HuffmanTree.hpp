#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanBase.hpp"
#include "HeapQueue.hpp"
#include <map>
#include <vector>


class HuffmanTree : public HuffmanTreeBase {
  public:
  std::string compress(const std::string inputStr);
  std::string serializeTree();
  std::string decompress(const std::string inputCode, const std::string serializedTree);
};

#endif /* HUFFMANBASE_H */