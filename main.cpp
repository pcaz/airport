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
  while(!infile.eof()){
    //    std::cout << "toto"<<'\n';
    char data;
    //infile >> data;
    //    std::getline(infile,data);
    infile >> data;
    airport* a = new airport();
    csv_parser* parser = new csv_parser(); 
    parser->analyze(*a, data);

    //    std::cout <<*a <<'\n';

}


  //      std::cout << "Name : "<< a->getName() << '\n';
  //    std::cout << "Iso : "<< a->getIso() << '\n';
}
