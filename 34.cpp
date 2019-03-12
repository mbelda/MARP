#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void resuelve(int nCubos) {
	vector<int> cubos = vector<int>();
	int c;
	for (int i = 0; i < nCubos; i++) {
		cin >> c;
		cubos.push_back(c);
	}
	vector<vector<int>> sol(nCubos, vector<int>(nCubos, 0));
	for (int i = 0; i < nCubos; i++) {
		sol[i][i] = cubos[i];
		int j = i + 1;
		if (j < nCubos) sol[i][j] = max(cubos[i], cubos[j]);
	}


	for (int d = 2; d < nCubos; d++) {
		for (int i = 0; i < nCubos - d; i++) {
			int j = i + d;
			int auxComoi, auxComoj;
			
			if (cubos[i + 1] > cubos[j]) {
				//Yo me como i, devoradora se come i+1
				auxComoi = sol[i + 2][j];
			}
			else {
				//Yo me como i, devoradora se come j
				auxComoi = sol[i + 1][j - 1];
			}

			if (cubos[i] > cubos[j-1]) {
				//Yo me como j, devoradora se come i
				auxComoj = sol[i + 1][j - 1];
			}
			else {
				//Yo me como j, devoradora se come j-1
				auxComoj = sol[i][j - 2];
			}


			sol[i][j] = max(cubos[i] + auxComoi, cubos[j] + auxComoj);
		}
	}

	cout << sol[0][nCubos - 1] <<endl;
}


int main() {
	int nCubos;
	cin >> nCubos;
	while (nCubos != 0) {
		resuelve(nCubos);
		cin >> nCubos;
	}
	return 0;
}