#include<fstream>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

ifstream fin("datensumme.txt");
ofstream likeli("Lennart/likelihood_L.txt");
ofstream nll("Lennart/nll_L.txt");
ofstream deltanll("Lennart/deltanll.txt");

double factorial(int i) {
  if (i <= 1)
    return 1;
  else
    return i*factorial(i-1);
}

double poisson(double mu, int k) {
  double d = pow(mu, k);
  d *= exp(-mu);
  //d /= tgamma(k); die Gamma funktion gibt bei k=0, inf aus. Deshalb muss ich eine factorial(k) verwenden... :/
  d /= factorial(k);
  //cout << k << " -> " << d << endl;
  return d;
}

double prob(vector<int> daten, double mu) {
  double p = 1.0;

  for (int d : daten) {
    double poi = poisson(mu, d);
    p *= poi;
    //cout << p << "\t" << poi << endl;
  }
}

int main() {
  // filling the vector
  vector<int> daten;
  int end = 234;
  for (int i = 0; i < end; i++){
    int temp;
    fin >> temp;
    daten.push_back(temp);
  }

  // Aufgabe 2a) berechnen
  double mu = 3.11538;
  double probability = prob(daten, mu);
  //cout << "probability:\t" << probability << endl;

  // Aufgabe 2b), 2c) gesamt Wahrscheinlichkeit für verschiedene μ 
  likeli << "μ\tL(μ)" << endl;
  vector<double> vec;
  double prob_nll = -2 * log(probability);
  for (mu = 0; mu <= 6; mu += .1) {
    double p = prob(daten, mu);

    // 2a)
    likeli << mu << "\t" << p << endl;
    //cout << mu << "\t" << p << endl;

    // 2b)
    p = -2 * log(p);
    vec.push_back(p);
    nll << mu << "\t" << p << endl;
    //cout << mu << "\t" << p << endl;
    deltanll <<  mu << "\t" << p - prob_nll << endl;
  
  }

  // 2d)
  // minimum finden
  double currentmin = 1e100 // besser wäre inf, jedoch weiß ich nicht, wie ich daran komme...
  double minMu = currentmin;
}