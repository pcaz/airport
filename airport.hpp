#ifndef AIRPORT
#define AIRPORT

#include <array>
#include <ostream>

// airport
class airport {
public:
  airport()=default;
  airport(std::array<char,26> &n, std::array<char,4> &i);
  const std::array<char,4>GetIso();
  const std::array<char,26>GetName();
  void SetIso(std::array<char,4>);
  void SetName(std::array<char,26>);
  
 friend std::ostream& operator<< (std::ostream& out, const airport& air); 
private:
  std::array<char, 4> iso;
  std::array<char,26> name;    
};

#endif
