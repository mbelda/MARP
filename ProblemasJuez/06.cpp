#include <queue>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct paciente {
	int prio;
	string nombre;
};


void resuelve(int & nEv) {
	priority_queue<int, string> q;
	char ai;
	while(nEv != 0){
		cin >> ai;
		if (ai == 'A') {
			cout << q.top() << endl;
			q.pop();
		}
		else {//ai == 'I'
			int prio;
			string nombre;
			cin >> nombre >> prio;
			q.push(prio, nombre);
		}
		nEv--;
	}
	cout << "----" << endl;
}

int main() {
	int nEv;
	cin >> nEv;
	while (nEv != 0) {
		resuelve(nEv);
		cin >> nEv;
	}
	return 0;
}
