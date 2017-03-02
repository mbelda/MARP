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

bool equilibrado(Arbin<int> const & a) {
	if (a.esVacio()) return true;

	int dr = a.hijoDr().altura();
	int iz = a.hijoIz().altura();

	if (abs(dr - iz) > 1) return false;

	return equilibrado(a.hijoDr()) && equilibrado(a.hijoIz());
}

int maximo(int const& minDr, int const& minIz, int const& raiz) {
	if (minDr == -1 && minIz == -1) {
		return raiz;
	}
	if (minIz == -1 && minDr != -1) {
		if (minDr > raiz) return minDr;
		return raiz;
	}
	if (minDr == -1 && minIz != -1) {
		if (minIz > raiz) return minIz;
		return raiz;
	}
	if (minDr > minIz && minDr > raiz) return minDr;
	if (minIz > minDr && minIz > raiz) return minIz;
	return raiz;
}

int max(Arbin<int> const & a) {
	if (a.esVacio()) return -1;
	int minDr = max(a.hijoDr());
	int minIz = max(a.hijoIz());
	return maximo(minDr, minIz, a.raiz());
}

int minimo(int const& minDr, int const& minIz, int const& raiz) {
	if (minDr == -1 && minIz == -1) {
		return raiz;
	}
	if (minIz == -1 && minDr != -1) {
		if (minDr < raiz) return minDr;
		return raiz;
	}
	if (minDr == -1 && minIz != -1) {
		if (minIz < raiz) return minIz;
		return raiz;
	}
	if (minDr < minIz && minDr < raiz) return minDr;
	if (minIz < minDr && minIz < raiz) return minIz;
	return raiz;
}

int min(Arbin<int> const & a) {
	if (a.esVacio()) return -1;
	int minDr = min(a.hijoDr());
	int minIz = min(a.hijoIz());
	return minimo(minDr, minIz, a.raiz());
}

bool ordenado(Arbin<int> const & a) {
	
	if (a.esVacio()) return true;

	if (!a.hijoDr().esVacio()) {
		int minDr = min(a.hijoDr());
		if (minDr != -1 && minDr < a.raiz()) return false;
	}

	if (!a.hijoIz().esVacio()) {
		int maxIz = max(a.hijoIz());
		if (maxIz > a.raiz()) return false;
	}

	return ordenado(a.hijoDr()) && ordenado(a.hijoIz());
}

bool AVL(Arbin<int> const & a) {
	if (a.esVacio()) return true;
	if (ordenado(a) && equilibrado(a)) return true;
	return false;
}

int main() {
	int ncasos;
	cin >> ncasos;
	Arbin<int> a;

	for (int i = 0; i < ncasos; i++) {
		a = leerArbol(-1);
		if (AVL(a)) cout << "SI";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}