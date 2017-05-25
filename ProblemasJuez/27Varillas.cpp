#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

void resuelve(int const & N, int const & coche, int val[1000], int cant[1000]){
	int monedas[10000];
	monedas[0] = 0;	
	for (int i = 1; i < coche; i++) monedas[i] = numeric_limits<int>::max();

	for (int i = 1; i < N; i++){
		for (int j = val[i]; j < coche; j++){
			monedas[j] = min(monedas[j], monedas[j-val[i]] +1);
		}
	}
	cout << monedas[coche-1];
}

void pagar(){

}



int main(){
	int N, coche;
	int val[1000], cant[1000];
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> val[i] >> cant[i];
	}
	cin >> coche;
	resuelve(N, coche, val, cant);
	return 0;
}