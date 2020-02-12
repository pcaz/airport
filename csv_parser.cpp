#include <iostream>
#include <string>
#include "csv_parser.hpp"
#include "airport.hpp"



void csv_parser::analyze(airport& a, const std::string& data){
  char cstr[255];
  strcpy(cstr, data.c_str());
  current_pos_ = 0;
  state_=csv_parser_state::initial;
  while(state_ != csv_parser_state::new_line) {
    consume(a,cstr[current_pos_]);
    ++current_pos_;		
			
  }
}

void csv_parser::consume(airport& a, char c) {
  
  switch(c) {
  case '"':
    if(state_ == csv_parser_state::initial){
      state_ = csv_parser_state::airport;
      last_value_ = "";
      break;
    }
    else if( state_ == csv_parser_state::airport){
      std::string str(last_value_.begin(), last_value_.end());
      a.SetName(str);
      last_value_ = "";
      state_ = csv_parser_state::iso;
      break;
    }
  case('\r'):
    if (state_ == csv_parser_state::iso){
      std::string str(last_value_.begin(), last_value_.end());      
      a.SetIso(str);
      last_value_ = "";
      state_= csv_parser_state::new_line;
    }
      break;
    
    
  case('\n'):
      state_= csv_parser_state::initial;
      std::cout << a << '\n';
      break;
  case(','):
    if(state_==csv_parser_state::iso)
      break;
    
  default:
    last_value_.push_back(c);
  }

    }
