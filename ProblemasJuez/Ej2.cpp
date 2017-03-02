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

template <class T>
bool ordenado(Arbin<T> const & a, int const & raiz) {
	bool dr = true, iz = true;
	if (!a.hijoDr().esVacio()) {
		if (a.hijoDr().raiz() <= raiz) return false;
		dr = ordenado(a.hijoDr(), a.hijoDr().raiz());
	}
	if (!a.hijoIz().esVacio()) {
		if (a.hijoIz().raiz() >= raiz) return false;
		iz = ordenado(a.hijoIz(), a.hijoIz().raiz());
	}
	return dr && iz;
}

template <class T>
bool AVL(Arbin<T> const & a) {
	if (a.esVacio()) return true;
	

}

int main() {
	int ncasos;
	cin >> ncasos;
	Arbin<int> a;

	for (int i = 0; i < ncasos; i++) {
		a = leerArbol(-1);
		try {
			if (AVL(a)) cout << "SI";
			else cout << "NO";
		}
		catch (domain_error e) {}
		cout << endl;
	}
	return 0;
}