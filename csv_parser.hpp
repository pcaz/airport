#ifndef CSV_PARSER
#define CSV_PARSER

#include <functional>
#include <string>
#include <vector>
#include "airport.hpp"


bool is_separator(char c);
bool is_new_line(char c);
bool is_double_quote(char c);
bool is_start_comment(char c);


enum class csv_parser_state {
	initial,
	airport,
	iso,
	new_line,
};

enum class csv_error {
        no_error=0,
	error_other,
	error_user_aborted,
	error_malformed_quoted_string,
	error_unterminated_quoted_string,
	error_empty_file
};


typedef std::string string_type; // Pour pouvoir le changer plus facilement

//std::function<bool(string_type const &)> comment_handler;
//std::function<bool(string_type const &)> field_handler;
//std::function<bool()> end_line_handler;
//std::function<bool()> end_file_handler;
//std::function<void(csv_error,int,int)> error_handler;


void call_field_handler();
void call_end_line_handler();
void call_comment_handler();
void call_error_handler(csv_error err);
void update_line_counter();


//void truncate(string_type & s) { s.clear(); }
//void append(string_type& s, char c) { s.push_back(c); }
				


class csv_parser {
public:
  csv_parser()=default;
  //  void consume(char c);
  //void end_of_data();
  void analyze(airport& a, char& data);
private:
  csv_parser_state state_ = csv_parser_state::initial;
  int current_pos_  = 0;
  std::string last_value_;
  std::vector<char> buffer;
};

#endif
