#include <iostream>
using namespace std;

bool hayCasos() {
	int agujeros;
	cin >> agujeros;
	if (!cin) return false;
	int longi;
	cin >> longi;

	int manguera[10000000];

	for (int i = 0; i < agujeros; i++) {
		cin >> manguera[i];
	}
	int parches = 0;
	int cubierto = 0;

	for (int i = 0; i < agujeros; i++) {
		parches++;
		cubierto = manguera[i] + longi;
		while (manguera[i] < cubierto && i < agujeros) {
			i++;
		}
	}
	cout << parches << endl;
	return true;
}



int main() {

	while (hayCasos()) {}

	return 0;
}