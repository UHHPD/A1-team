#include<iostream>
#include<fstream>
#include<cmath>

std::ifstream fin("datensumme.txt");
std::ofstream Aufgabe_eins ("Aufgabe_eins_Tom");

int main()
{

double summe = 0;
double end = 234;
double mittelwert;

      //Mittelwert//
for (int i = 0; i < end; ++i){

double b;  
fin>> b;
summe = b + summe;


  }
mittelwert = summe/end;
Aufgabe_eins<< "der Mittelwert ist " << mittelwert <<std::endl;



double varianz;
double varsum = 0;
     //varianz//
for (int n = 0; n < end; ++n)
{
  
int b;
fin>> b;
varsum = (b - mittelwert) * (b - mittelwert);

}

  varianz = varsum * 1/end;

  double Standartabweichung = sqrt(varianz);
  
  Aufgabe_eins<< "Die Varianz ist:  " << varianz <<std::endl;
  Aufgabe_eins<< "Die Standartabweichung lautet:  "<<Standartabweichung;

  Aufgabe_eins.close();
}
