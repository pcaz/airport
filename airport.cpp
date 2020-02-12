#include <cstring>
#include "airport.hpp"


airport::airport(std::string &n, std::string &i): name(n), iso(i) {};

const std::string airport::GetIso(){
  return iso;
}

const std::string airport::GetName(){
  return name;
}

void airport::SetIso (std::string& a) {
  this->iso=a;
  }

void airport::SetName(std::string& a) {
  size_t p = a.find_last_not_of(" ");
  if (std::string::npos != p)
    a.erase(p+1);
  this->name=a;
  }

std::ostream& operator<< (std::ostream& out, const airport& air)
{
    out << air.name << ":"<< air.iso;
    return out;
}
