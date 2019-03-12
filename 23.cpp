//Los Broncos de Boston

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelve() {
	int nCasos;
	cin >> nCasos;
	if (!cin) return false;

	vector<int> enemigo = vector<int>();
	int a;
	for (int i = 0; i < nCasos; i++) {
		cin >> a;
		enemigo.push_back(a);
	}

	vector<int> nosotros = vector<int>();
	for (int i = 0; i < nCasos; i++) {
		cin >> a;
		nosotros.push_back(a);
	}

	sort(enemigo.begin(), enemigo.end()); //De menor a mayor
	sort(nosotros.begin(), nosotros.end());
	int victorias = 0;
	int j = nCasos - 1;
	int i = nCasos - 1;
	while (i >= 0 && j >= 0) {
		if (enemigo[j] > nosotros[i]) {
			j--;
		}
		else {
			victorias++;
			j--; i--;
		}
	}

	cout << victorias << endl;
	return true;
}


int main() {
	while (resuelve()) {}

	return 0;
}
