#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <array>
#include "airport.hpp"
#include "csv_parser.hpp"

int main(){


  std::ifstream infile;
  std::string filename="airport-codes.csv";
  
  infile.open(filename);


  if(infile.fail()) {
        std::cerr << "Unable to open input file " << filename << '\n';
      std::exit(1);  
      
    }
  csv_parser* parser = new csv_parser(); 
  while(!infile.eof()){
    //    std::cout << "toto"<<'\n';
    std::string data;
    std::getline(infile,data);
    //infile >> data;
    if(data=="") break;
    airport* a = new airport();

    parser->analyze(*a, data);

                    std::cout <<*a <<'\n';

}


  //        std::cout << "Name : "<< a->getName() << '\n';
  //      std::cout << "Iso : "<< a->getIso() << '\n';
}
