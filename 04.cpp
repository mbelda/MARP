/*
Métodos algorítmicos en resolución de problemas
Problema 04
Maria José Belda Beneyto
Doble Grado en Ingeniería Infórmatica y Matemáticas
*/
#include <iostream>
#include "TreeMap_AVL.h"
using namespace std;

void resuelve(map<int, bool>::TreeNode *raiz, int preg, int & aux) {
	if (raiz == nullptr) cout << "??" << endl;
	//tam_i quiere decir que eres el tam_i mas pequeño si estas en el hijo izq
	// si estas en el derecho eres el tam_i + los otros mas peques del hijo izq
	else if (aux + raiz->tam_i == preg) cout << raiz->cv.clave << endl;
	else if (aux + raiz->tam_i < preg) {
		//Esta en el hijo derecho
		aux += raiz->tam_i;
		resuelve(raiz->dr, preg, aux);
	}
	else resuelve(raiz->iz, preg, aux);
}

int main() { //Tiene que ser O(logn) es decir la altura del arbol
	int nclaves, clave, npreg, preg;
	cin >> nclaves;
	while (nclaves != 0) {
		map<int, bool> tree; //Importante dentro del bucle, sino no se borra el arbol de un caso a otro
		for (int i = 0; i < nclaves; i++) {
			cin >> clave;
			map<int, bool>::clave_valor cv = map<int, bool>::clave_valor(clave);
			tree.insert(cv);
		}
		cin >> npreg;
		for (int i = 0; i < npreg; i++) {
			cin >> preg;
			int auxMasPeq = 0;
			resuelve(tree.raiz, preg, auxMasPeq);
		}
		cout << "----" << endl;
		cin >> nclaves;
	}
	return 0;
}