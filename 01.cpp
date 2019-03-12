/*
Métodos algorítmicos en resolución de problemas
Problema 01
Maria José Belda Beneyto
Doble Grado en Ingeniería Infórmatica y Matemáticas
*/

#include <iostream>
#include "Arbin.h"
using namespace std;

template <class T>
Arbin<T> leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}

template <class T>
bool equilibrado(Arbin<T> const & a) {
	if (a.esVacio()) return true;

	int dr = a.hijoDr().altura();
	int iz = a.hijoIz().altura();

	if (abs(dr - iz) > 1) return false;
	
	return equilibrado(a.hijoDr()) && equilibrado(a.hijoIz());
}


int main() {
	int ncasos;
	cin >> ncasos;
	Arbin<char> a;

	for (int i = 0; i < ncasos; i++) {
		a = leerArbol('.');
		try {
			if(equilibrado(a)) cout << "SI";
			else cout << "NO";
		}
		catch (domain_error e) {}
		cout << endl;
	}
	return 0;
}