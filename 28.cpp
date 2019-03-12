//Cazatesoros

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tCofre {
	int profundidad;
	int oro;
};



bool resuelve() {
	int T, N;
	cin >> T >> N;
	if (!cin) return false;
	tCofre c;
	vector<tCofre> cofres = vector<tCofre>();
	for (int i = 0; i < N; i++) {
		cin >> c.profundidad >> c.oro;
		cofres.push_back(c);
	}

	vector<vector<int>> mOro(N, vector<int>(T + 1, 0));

	//En la primera fila, si T es mayor que lo que nos
	//cuesta llegar al cofre, recogemos su oro
	for (int j = cofres[0].profundidad*3; j <= T; j++) {
		mOro[0][j] = cofres[0].oro;
	}

	//Llenado de matriz
	for (int i = 1; i < N; i++) {
		for (int j = T; j >= 0; j--) {
			if (j >= cofres[i].profundidad*3) { //Podemos coger el cofre
				mOro[i][j] = max(mOro[i-1][j], mOro[i-1][j - cofres[i].profundidad*3] + cofres[i].oro);
			}
			else mOro[i][j] = mOro[i - 1][j];
		}
	}

	vector<tCofre> cofresCogidos = vector<tCofre>();
	
	int i = N - 1, j = T;
	while (i >= 0) {
		if ((i > 0 && mOro[i][j] == mOro[i - 1][j])
			|| (i==0 && j < cofres[0].profundidad*3)) {
			//No cogemos el cofre i
			i--;
		}
		else {
			//Cogemos el cofre i
			cofresCogidos.push_back(cofres[i]);
			j -= cofres[i].profundidad * 3;
			i--;
			
		}
	}



	cout << mOro[N-1][T] << endl;
	cout << cofresCogidos.size() << endl;
	for (int i = cofresCogidos.size() - 1; i >= 0; i--) {
		cout << cofresCogidos[i].profundidad << " " << cofresCogidos[i].oro << endl;
	}
	cout << "----" << endl;

	return true;
}


int main() {
	while (resuelve()) {}
	return 0;
}