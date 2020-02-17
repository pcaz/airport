#include <iomap>
#include <string>
#include <map>

class tree {
public:
  tree(){
    data = std::vector();
    ind =  std::vector();
  }
  friend int hash(&std::string);
private:
  void add(std::string& key, std::string &value);
  
  

  
  
