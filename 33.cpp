//Carpintero

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void resuelve(int L, int N) {
	
	vector<int> cortes = vector<int>();
	cortes.push_back(0);
	int c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		cortes.push_back(c);
	}
	cortes.push_back(L);

	vector<vector<int>> mC(N+2, vector<int>(N + 2, 0));

	//Llenado de matriz por diagonales
	for (int d = 2; d < N + 2; d++) {
		for (int j = d; j < N + 2; j++) {
			int minimo = mC[j - d][j - d + 1] + mC[j - d + 1][j];
			for (int k = j - d + 2; k < j; k++) {
				minimo = min(minimo, mC[j - d][k] + mC[k][j]);
			}
			mC[j - d][j] = 2 * (cortes[j] - cortes[j - d]) + minimo;
		}
	}

	cout << mC[0][N + 1] <<endl;
}


int main() {
	int L, N;
	cin >> L >> N;
	while (L != 0 && N != 0) {
		resuelve(L, N);
		cin >> L >> N;
	}
	return 0;
}