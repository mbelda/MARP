#include <iostream>
#include "GrafoDirigido.h"
using namespace std;

bool isCiclico(int v, GrafoDirigido g, vector<bool> marked) {
	if (!marked[v]){
		// Mark the current node as visited and part of recursion stack
		marked[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
				return true;
			else if (recStack[*i])
				return true;
		}

	}
	recStack[v] = false;  // remove the vertex from recursion stack
	return false;
}


bool resuelve() {
	int nVertices, nAristas;
	cin >> nVertices >> nAristas;
	if (!cin) return false;
	GrafoDirigido g = GrafoDirigido(nVertices);
	int a, b;
	for (int i = 0; i < nAristas; i++) {
		cin >> a >> b;
		g.ponArista(a, b);
	}
	bool hayCiclos = false;
	vector<bool> marked = vector<bool>(100, false);

	for (int i = 0; i < nVertices && !hayCiclos; i++) {
		if (isCiclico(i, g, marked)) hayCiclos = true;
	}




	bool arborescencia = false;
	int raiz;
	for (int i = 0; i < nVertices && !arborescencia; i++) {
		DepthFirstDirectedPaths dfs = DepthFirstDirectedPaths(g, i);
		bool puedeSer = true;
		for (int j = 0; j < nVertices && puedeSer; j++) {
			if (!dfs.hasPathTo(j)) { puedeSer = false; }
		}
		if (puedeSer) {
			arborescencia = true;
			raiz = i;
		}
	}

	if (arborescencia && !hayCiclos) cout << "SI " << raiz << endl;
	else cout << "NO" << endl;

	return true;
}

int main() {
	while (resuelve()) {}
	return 0;
}