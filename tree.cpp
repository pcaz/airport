#include "tree.hpp"


void tree::add (airport& a){
    tree_[a.GetIso()]= a.GetName();
};

void tree::list(){
  std::map<std::string, std::string>::iterator p;

  for(p=tree_.begin();p != tree_.end();p++) {
    std::cout << p->first << ":" << p->second << std::endl;
  }
}

std::string tree::search(std::string& iso) {

  std::map<std::string,std::string>::iterator it;

  
  it = tree_.find(iso);

  if (it != tree_.end())
    return it->second;
  else
    return "not found";


}

