//Los Broncos de Boston

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void resuelve(int nPartidos) {

	vector<int> r = vector<int>();
	int a;
	for (int i = 0; i < nPartidos; i++) {
		cin >> a;
		r.push_back(a);
	}

	vector<int> b = vector<int>();
	for (int i = 0; i < nPartidos; i++) {
		cin >> a;
		b.push_back(a);
	}

	sort(r.begin(), r.end()); //De menor a mayor
	sort(b.begin(), b.end());
	int suma = 0;
	for (int i = 0, j = nPartidos - 1; i < nPartidos && j >= 0; i++, j--) {
		int puntos = b[j] - r[i];
		if (puntos > 0) suma += puntos;
	}
	cout << suma << endl;
}


int main() {
	int nPartidos; 
	cin >> nPartidos;
	while (nPartidos != 0) {
		resuelve(nPartidos);
		cin >> nPartidos;
	}
	
	return 0;
}
