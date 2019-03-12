/*
Métodos algorítmicos en resolución de problemas
Problema 03
Maria José Belda Beneyto
Doble Grado en Ingeniería Infórmatica y Matemáticas
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int nclaves, k1, k2, k;
	cin >> nclaves;
	while (nclaves > 0) {
		vector<int> v, iguales;
		for (int i = 0; i < nclaves; i++) {
			cin >> k;
			v.push_back(k);
		}
		sort(v.begin(), v.end());
		cin >> k1 >> k2;
		
		for (int i = 0; i < nclaves; i++) {
			if (v[i] >= k1 && v[i] <= k2) iguales.push_back(v[i]);
		}

		if (iguales.size() > 0) {
			for (int i = 0; i < iguales.size() - 1; i++) {
				cout << iguales[i] << " ";
			}
			cout << iguales[iguales.size() -1];
		}
		cout << endl;
		
		cin >> nclaves;
	}

	return 0;
}