#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct palabra {
	string pal;
	vector<int> linea;
} ;


void refsCruzadas(int const & N) {
	//Leer N lineas
	vector<palabra> palabras;
	string str;
	palabra p;
	cin >> str;
	//Con el for contamos la linea en la que estamos
	for (int i = 0; i < N; i++) {
		while (str != "\n") {
			if (str.length() > 2) {
				p.pal = str;
				p.linea.push_back( i + 1 );

				palabras.push_back(p);
			}
			cin >> str;
		}
	}

	sort(palabras.begin(), palabras.end());
}


int main() {
	int N;
	cin >> N;
	while (N != 0) {
		refsCruzadas(N);

		cin >> N;
	}

	return 0;
}