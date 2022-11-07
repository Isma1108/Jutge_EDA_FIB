#include <iostream>
#include <vector>
using namespace std;

typedef int vertex;
typedef vector<vertex> llista_adjacencia;
typedef vector<llista_adjacencia> graf;

bool es_bosc_DFS(const graf& G, vertex v, vertex pare, vector<bool>& visitat) {
	visitat[v] = true;
	for (auto w: G[v]) {
		if (visitat[w] and w != pare) return false;
		if (not visitat[w] and not es_bosc_DFS(G, w, v, visitat)) return false;
	}
	return true;
}

bool es_bosc_DFS(const graf& G, int& total) {
	vector<bool> visitat(G.size(), false);
	for (vertex v = 0; v < G.size(); ++v) {
		if (not visitat[v]) {
			if (not es_bosc_DFS(G, v, v, visitat)) return false;
			++total;
		}
	}
	return true;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		graf G(n, llista_adjacencia(0));
		for (int i = 0; i < m; ++i) {
			vertex x1, x2;
			cin >> x1 >> x2;
			G[x1].push_back(x2);
			G[x2].push_back(x1);
		}
		int total = 0;
		if (es_bosc_DFS(G, total)) cout << total << endl;
		else cout << "no" << endl;
	}
}

