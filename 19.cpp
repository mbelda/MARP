//Oferta 3x2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelve() {
	int nLibros;
	cin >> nLibros;
	if (!cin) return false;

	vector<int> precios = vector<int>();
	int p;
	for (int i = 0; i < nLibros; i++) {
		cin >> p;
		precios.push_back(p);
	}
	sort(precios.begin(), precios.end()); //De menor a mayor
	int suma = 0;
	for (int i = nLibros - 3; i >= 0; i -= 3) suma += precios[i];

	cout << suma << endl;
	return true;
}


int main() {
	while (resuelve()) {}
	return 0;
}