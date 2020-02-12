#ifndef CSV_PARSER
#define CSV_PARSER

#include <string>
#include <cstring>
#include "airport.hpp"


enum class csv_parser_state {
	initial,
	airport,
	iso,
	new_line,
};


class csv_parser {
public:
  csv_parser()=default;
  void analyze(airport& a, const std::string& data);
private:
  void consume(airport& a,char c);
  csv_parser_state state_ = csv_parser_state::initial;
  int current_pos_  = 0;
  std::string last_value_;
};

#endif
