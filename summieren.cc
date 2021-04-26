#include <fstream>
#include <iostream>

int main() {

	std::ifstream fin("daten.txt");
	std::ofstream fout("datensumme.txt");
  
  int max = 234;
	for (int i = 0; i < max; i++) {
		int a, b;
		fin >> a >> b;

		std::cout << "a + b = " << a+b << std::endl;
		fout << a+b << std::endl;
	}
}