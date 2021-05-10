#include <iostream>
#include <fstream>
#include <cmath>

int main() {

  std::ifstream fin("datensumme.txt");
  std::ofstream varianzOut("varianzen_L.txt");
  std::ofstream mittelOut("mittelwerte_L.txt");

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

    for (int j = 0; j < 9; j++) {
      // Varianz & Standardabweichung
      double varianz = mittelwert - neueDaten[j]; // berechnen der Varianz
      varianz *= varianz; // quadrieren
      varianzOut << varianz << std::endl;

      double stdAbw = std::sqrt(varianz); // berechnen der Standardabweichung
    }
  }

  varianzOut.close();
  mittelOut.close();
}