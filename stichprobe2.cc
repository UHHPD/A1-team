#include <iostream>
#include <fstream>
#include <cmath>

int main() {

  std::ifstream fin("datensumme.txt");
  std::ofstream varianzOut("varianzen.txt");
  std::ofstream mittelOut("mittelwerte.txt");

  int num = 234;
  int daten[num];

  // füllen von daten[]
  for (int i = 0; i < num; i++)
    fin >> daten[i];
  fin.close();


  for (static int i = 0; i < num; i += 9) {
    int neueDaten[9];
    int summe = 0;
    for (int j = 0; j < 9; j++) {
      neueDaten[j] = daten[i+j];
      summe += neueDaten[j];
    }

    //mittelwert
    double mittelwert = summe / 9.0;
    mittelOut << mittelwert << std::endl;

    // Varianz
    double varianz = 0;
    for (int j = 0; j < 9; j++) {
      double temp = neueDaten[j] - mittelwert; //differenz
      temp *= temp; //quadrieren
      varianz += temp;//  summieren
    }
    varianz /= 9.0;
    varianzOut << varianz << std::endl;
  }

  varianzOut.close();
  mittelOut.close();


  std::ifstream mittelIn("mittelwerte.txt");
  std::ifstream varianzIn("varianzen.txt");

  int mittelSumme = 0;
  int varianzSumme = 0;
  num = 26;
  for (int i = 0; i < num; i++ ) {
    double temp = 0;
    mittelIn >> temp;
    mittelSumme += temp;
   
    temp = 0;
    varianzIn >> temp;
    varianzSumme += temp;
  }
  mittelSumme /= num;
  varianzSumme /= num;
  std::cout /*<< "Der Mittelwert der Mittelwerte ist:\t"*/ << mittelSumme << std::endl;
  std::cout /*<< "Der Mittelwert der Varianzen ist:\t"*/ << varianzSumme << std::endl;

  //std::cout << 2.4359 << std::endl;

}