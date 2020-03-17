#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "airport.hpp"
#include "csv_parser.hpp"
#include "tree.hpp"

int main(){

  int line__;
  int loop;
  std::clock_t time;
  std::clock_t sum = 0;
  
  std::ifstream infile;
  std::string filename="airport-codes.csv";
  std::cout <<"Number of loops ?: "<<'\n';
  std::cin >> loop; 
 for(int i=0; i<loop; i++) { 
  infile.open(filename);


  if(infile.fail()) {
        std::cerr << "Unable to open input file " << filename << '\n';
      std::exit(1);  
      
    }

  csv_parser* parser = new csv_parser();

  tree* tree_ = new tree();


  //  std::map<std::string,std::string> airports;
  std::clock_t    start;
  std::clock_t    stop;

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

     stop = std::clock();
    
     //    tree_->list();
     time= (stop - start);
     sum+= time;
     //   std::cout << (stop - start) / (double)(CLOCKS_PER_SEC / 1000)<< " milliseconds"<< '\n';
    line__ = nline_;
    //    std::cout << "Time : " << times[i] << '\n';
    infile.close();
 }
 // tree_->list();
 std::time_t val=sum/loop; 

 std::cout << val/(double)(CLOCKS_PER_SEC / 1000)<< " milliseconds medium time"<< '\n';
 std::cout << "number of lines: " << line__<< '\n';
  std::cout << "number of loops: " << loop << '\n';

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
