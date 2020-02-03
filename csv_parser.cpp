#include <iostream>
#include <string>
#include "csv_parser.hpp"
#include "airport.hpp"

void csv_parser::analyze(airport& a, char& data){
  //    std::array<char, 4 > Iso = {"AAA"};
  //   std::array<char,26 > Name = {"Sample Airport"};
  //  a.SetIso(Iso);
  //  a.SetName(Name);
  //  std::cout << data<<'\n';
  switch(data) {
  case '"':
    if(state_ == csv_parser_state::initial){
      state_ = csv_parser_state::airport;
      break;
    }
    else if( state_ == csv_parser_state::airport){
      std::string str(buffer.begin(), buffer.end());
      a.SetName(str);
      state_ = csv_parser_state::iso;
      break;
    }
    else if (state_ == csv_parser::iso){
      std::string str(buffer.begin(), buffer.end());      
      a.SetIso(str);
      state_= csv_parser_state::new_line;
      break;
    }
    
  case('\n'):
      state_= csv_parser_state::initial;
      break;
    
  default:
    buffer.push_back(data);
  }

    }
