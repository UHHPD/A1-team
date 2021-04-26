#include <fstream>
#include <iostream>

int main() {

	std::ifstream fin("daten.txt");
	std::ofstream fout("datensumme.txt");

	while (!fin.eof()) {
		int a, b;
		fin >> a >> b;

		std::cout << "a + b = " << a+b << std::endl;
		fout << a << " + " << b << " = " << a+b << std::endl;
	}
}