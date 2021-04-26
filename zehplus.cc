#include<iostream>
#include<fstream>

std::ifstream fin("daten.txt");
std::ofstream fout("zehplusplus_plus.txt");

int main()
{
  int end = 234;
  for(int n = 0; n < end; n = n + 1)
  {
    int b, c;
    fin >> b >> c;
    int a = b + c;
    //std::cout<< a << std::endl;
    fout << a << std::endl;
  }
}