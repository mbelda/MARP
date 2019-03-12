//Agujeros en la manguera

#include <iostream>
#include <vector>
using namespace std;

bool resuelve() {
	int L;
	long int N;
	cin >> N >> L;
	if (!cin) return false;

	vector<int> agujeros = vector<int>();
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		agujeros.push_back(a);
	}

	int parches = 0;
	int cubierto = 0;
	int j = 0;
	if (agujeros[0] == 0) {
		parches = 1;
		cubierto = L;
		j = 1;
	}
	while (j < N) {
		if (agujeros[j] > cubierto) { //Necesitamos mas parches
			parches++;
			cubierto = agujeros[j] + L;
		}
		j++;
	}

	cout << parches << endl;
	return true;
}


int main() {
	while (resuelve()) {}
	return 0;
}