#ifndef AIRPORT
#define AIRPORT

#include <string>
#include <ostream>

// airport
class airport {
public:
  airport()=default;
  airport(std::string &n, std::string &i);
  const std::string GetIso();
  const std::string GetName();
  void SetIso(std::string&);
  void SetName(std::string&);
  
 friend std::ostream& operator<< (std::ostream& out, const airport& air); 
private:
  std::string name;
  std::string iso;
};

#endif
