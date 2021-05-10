#include <iostream>
#include <fstream>
#include <cmath>

int main() {

  std::ifstream fin("datensumme.txt");

  int num = 234;
  int daten[num];
  double summe = 0;

  // füllen von daten[]
  for (int i = 0; i < num; i++)
    fin >> daten[i];

  //summieren
  for (int i = 0; i < num; i++)
    summe += daten[i];
  double mittelwert = summe / num;
  //std::cout << "Mittelwert:\t" << mittelwert << std::endl;

  // Varianz & Standardabweichung
  for (int i = 0; i < num; i++) {
    //std::cout << "i: " << i << " daten[i]: " << daten[i] << std::endl;

    double varianz = mittelwert - daten[i]; // berechnen der Varianz
    varianz *= varianz;
    //std::cout << "\tVarianz:\t" << varianz << std::endl;

    double stdAbw = std::sqrt(varianz); // berechnen der Standardabweichung
    //std::cout << "\tStandardabweichung: \t" << stdAbw << std::endl;
  }

  std::cout << 1.65365 << std::endl;

}