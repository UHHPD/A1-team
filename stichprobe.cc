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

  // Varianz & Standardabweichung
  double varianz = 0;
  for (int i = 0; i < num; i++) {
    double temp = mittelwert - daten[i]; // berechnen der Varianz
    temp *= temp;
    varianz += temp;
  }
  varianz /= num;

  double stdAbw = std::sqrt(varianz); // berechnen der Standardabweichung

  std::cout << stdAbw << std::endl;
}