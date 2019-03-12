#include <iostream>
#include "Grafo.h"
#include <algorithm>
#include <stack>
using namespace std;

bool esBipartitaLaCC(int v, vector<int> color, Grafo g) {
	queue<int> q = queue<int>();
	bool bipartito = true;
	color[v] = 0;
	q.push(v);
	while (!q.empty() && bipartito) {
		v = q.front();
		q.pop();
		for (int s : g.adj(v)) {
			//Si no esta pintado, lo pintamos y lo añadimos a la cola
			if (color[s] == -1) {
				color[s] = (color[v] + 1) % 2;
				q.push(s);
			}
			else if (color[s] == color[v]) { bipartito = false; break; }
		}
	}

	if (bipartito) return true;
	return false;
}

bool resuelve() {
	int nVertices, nAristas;
	cin >> nVertices >> nAristas;
	if (!cin) return false;
	Grafo g = Grafo(nVertices);
	int a, b;
	for (int i = 0; i < nAristas; i++) {
		cin >> a >> b;
		g.ponArista(a, b);
	}
	//Inicializamos a -1 para marcar que no esta pintado
	vector<int> color = vector<int>(100, -1);
	bool bipartito = true;
	for (int i = 0; i < nVertices && bipartito; i++) {

		if (color[i] == -1) { //Si no esta pintado es una nueva cc
			if (!esBipartitaLaCC(i, color, g)) {
				bipartito = false;
			}
		}
	}
	if (bipartito) cout << "SI" << endl;
	else cout << "NO" << endl;

	return true;
}



int main() {
	while (resuelve()) {}
	return 0;
}