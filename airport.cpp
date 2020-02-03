#include <cstring>
#include "airport.hpp"


airport::airport(std::array<char, 26> &n, std::array<char,4> &i) {
   std::copy (std::begin(n), std::end(n), name.begin());
   std::copy (std::begin(i), std::end(i), iso.begin());
};

const std::array<char,4> airport::GetIso(){
  return iso;
}

const std::array<char,26> airport::GetName(){
  return name;
}

void airport::SetIso (std::array<char,4> a) {
    std::copy(std::begin(a), std::end(a), std::begin(this->iso));
  }

void airport::SetName(std::array<char,26> a) {
    std::copy(std::begin(a), std::end(a), std::begin(this->name));
  }

std::ostream& operator << (std::ostream& out, const airport& air)
{
  std::string str1(air.name.data());
  std::string str2(air.iso.data());
  out << str1 << " "<< str2;
    return out;
}
