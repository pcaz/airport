//#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <ios>
#include <iomanip>




class airport {
public:
  airport(char* n, char* i){
    strcpy(name,n);
    strcpy(iso,i);
  };

  char* getIso() { return iso;};
  char* getName() { return name;};

    
};

class node {
public:
  node()=default;
private:
  airport* father=NULL;
  airport* left=NULL;
  airport* right=NULL;
};

class tree{
public:
  tree(int nb): nblevel(nb){}
private:
  int nblevel;
  airport* root=NULL;
};

  
  
