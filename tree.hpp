#ifndef TREE
#define TREE

#include <iostream>
#include <map>
#include <string>
#include "airport.hpp"

class tree {
public:
  void add(airport& a);
  //  remove(airport& a);
  void list();
  std::string search(std::string& iso);
  private:
    std::map<std::string, std::string> tree_;
};

#endif
