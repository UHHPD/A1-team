#include <iostream>
#include <fstream>
#include <cmath>

int main() {

  std::ifstream fin("datensumme.txt");
  //std::ofstream fout("")

  int i = 0;
  while(!fin.eof()) {
    if(i > 300)
      break;

    int a;
    fin >> a;
    
    std::cout << i << ": " << a << std::endl;
    i++;
  }

