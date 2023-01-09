#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;
	string accio;
	int valor;
	priority_queue<int> pq;
	unordered_map<int,bool> m;

	while (cin >> accio >> valor) {
		if (accio == deixar) {
			auto it = m.find(valor);
			pq.push(valor);
			m.insert({valor, true});
		}
		else m[valor] = false;
		int i = 0, total = 0;
		while (not pq.empty()) {
			auto it = m.find(pq.top());
			if (it != m.end() and it->second and i < n) {total += pq.top(); ++i;}
			pq.pop();
		}
	}
}
