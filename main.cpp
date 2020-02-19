#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "airport.hpp"
#include "csv_parser.hpp"
#include "tree.hpp"

int main(){


  std::ifstream infile;
  std::string filename="airport-codes.csv";
  
  infile.open(filename);


  if(infile.fail()) {
        std::cerr << "Unable to open input file " << filename << '\n';
      std::exit(1);  
      
    }
  csv_parser* parser = new csv_parser();
  tree* tree_ = new tree();

  
  //  std::map<std::string,std::string> airports;
  std::clock_t    start;

   start = std::clock();
  
  //  std::cout << tv1.tv_usec << '\n';

  int nline_=0;
  
  while(!infile.eof()){
    //    std::cout << "toto"<<'\n';
    std::string data;
    std::getline(infile,data);
    //infile >> data;
    if(data=="") break;
    airport* a = new airport();

    parser->analyze(*a, data);
    tree_->add (*a);
    ++nline_;

    
    //                    std::cout <<*a <<'\n';

}
  
    std::cout << nline_ << " lines  in "<<(std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000)<< " milliseconds"<< '\n';
  //  tree_->list();
  //        std::cout << "Name : "<< a->getName() << '\n';
  //      std::cout << "Iso : "<< a->getIso() << '\n';

    //  std::string ISO;
    //do {
    //std::cout << '\n'<<'\n';
    //std::cout <<"Input the Iso code of the airport"<< '\n'; 
    //std::cin >> ISO;
    //for (auto & c :ISO) c = toupper(c);
    //std::string airport = tree_->search(ISO);
    //std::cout << "ISO code: "<<ISO << " -> "<< "Airport: "<<airport << '\n';
    //} while (ISO != "");
}
