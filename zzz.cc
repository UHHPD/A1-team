#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("varianzen.txt");

int main() {

  
  double summe = 0; 
  double temp = 0;
  for (int i = 0; i < 26; i++) {
    fin >> temp;
    summe += temp;
  }
  summe /= 26.;

  cout << summe << endl;
}