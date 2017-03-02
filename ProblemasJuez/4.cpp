//Capitulos repetidos
#include <iostream>
using namespace std;

bool repetidos(int cap[100000], int ini, int fin) {
	for (int i = ini; i < fin; i++) {
		for (int j = i + 1; j <= fin; j++) {
			if (cap[i] == cap[j]) return true;
		}
	}
	return false;
}


int main() {
	int nseries;
	cin >> nseries;
	int ncap, cap[100000];
	for (int i = 0; i < nseries; i++) {
		cin >> ncap;
		for (int j = 0; j < ncap; j++) {
			cin >> cap[j];
		}
		//Ya lo tengo leido, calculamos max dias sin repetir

		int maxLong = 1, nowLong = 1;
		int ini = 0, fin = 1;
		while (fin < ncap) {
			if (!repetidos(cap, ini, fin)) {
				fin++;
			}
			else {
				if (maxLong < fin - ini) { maxLong = fin - ini; }
				ini++;
				fin = ini + maxLong;
			}
		}
		cout << maxLong << endl;
	}
	return 0;
}