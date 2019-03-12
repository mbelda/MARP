//Dardos

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool resuelve() {
	int suma, N;
	cin >> suma >> N;
	if (!cin) return false;

	vector<int> sectores = vector<int>();
	int s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		sectores.push_back(s);
	}

	vector<int> sol = vector<int>(suma + 1);
	for (int i = 1; i <= suma; i++) { 
		sol[i] = -1;
	}
	sol[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = sectores[i]; j <= suma; j++) {
			if (sol[j - sectores[i]] != -1) {
				if (sol[j] != -1) sol[j] = min(sol[j], sol[j - sectores[i]] + 1);
				else sol[j] = sol[j - sectores[i]] + 1;
			}
		}
	}

	if (sol[suma] == -1) { cout << "Imposible" << endl; }
	else {
		int s = suma;
		vector<int> sec = vector<int>();
		int i = N-1;
		while (s != 0) {
			if (s - sectores[i] >= 0 && sol[s] == sol[s - sectores[i]] + 1) {
				//Cogemos el sector
				sec.push_back(sectores[i]);
				s -= sectores[i];
			}
			else {
				i--;
			}
		}

		cout << sec.size() << ": ";
		for (int i = 0; i < sec.size() -1 ; i++) {
			cout << sec[i] << " ";
		}
		cout << sec[sec.size() - 1] << endl;

	}
	
	return true;
}


int main() {
	while (resuelve()) {}
	return 0;
}