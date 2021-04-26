#include <iostream>
#include <fstream>
#include <cmath>

int main() {

  std::ifstream fin("datensumme_Lennart.txt");
  std::ofstream varianzOut("varianzen_Lennart.txt");
  std::ofstream mitelOut("mittelwerte_Lennart.txt");

  int num = 234;
  int daten[num];

  // füllen von daten[]
  for (int i = 0; i < num; i++)
    fin >> daten[i];
  fin.close();


  for (static int i = 0; i < num; i += 9)
    static int neueDaten[9];
    int summe = 0;
    for (int j = 0; j < 9; j++) {
      neueDaten[j] = daten[i+j];
      summe += neueDaten[j];
    }
    
    //mittelwert
    double mittelwert = summe / 9;
    std::cout << "Mittelwert:\t" << mittelwert << std::endl;
    mittelOut << mittelwert << std::endl;

    for (int j = 0; j < 9; j++) {
      // Varianz & Standardabweichung
      double varianz = mittelwert - neuedaten[j]; // berechnen der Varianz
      varianz *= varianz; // quadrieren
      std::cout << "\tVarianz:\t" << varianz << std::endl;
      varianzOut << varianz << std::endl;

      double stdAbw = std::sqrt(varianz); // berechnen der Standardabweichung
      std::cout << "\tStandardabweichung: \t" << stdAbw << std::endl;
    }
  }


}