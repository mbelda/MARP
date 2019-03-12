//Palindromos

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string>
using namespace std;

bool resuelve() {
	string palabra;
	cin >> palabra;
	if (!cin) return false;
	int n = palabra.size();

	vector<vector<int>> sol(n, vector<int>(n, 0));

	for (int d = 1; d < n; d++) {
		for (int i = 0; i < n - d; i++) {
			int j = i + d;
			if (palabra.at(i) == palabra.at(j))
				sol[i][j] = sol[i+1][j-1];
			else sol[i][j] = min(sol[i][j - 1], sol[i + 1][j]) + 1;
		}
	}

	cout << sol[0][n-1] << endl;

	return true;
}


int main() {
	while (resuelve()) {}
	return 0;
}