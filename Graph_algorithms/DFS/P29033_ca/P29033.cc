#include <iostream>
#include <vector>
using namespace std;

typedef int vertex;
typedef vector<vertex> llista_adjacencia;
typedef vector<llista_adjacencia> graf;


bool dos_colorejable_dfs(graf& G, vector<vertex>& vec, vertex v, int color) {
	if (vec[v] == -1) {
		vec[v] = color;
		for (auto w : G[v]) {
			if (not dos_colorejable_dfs(G, vec, w, 1-color)) return false;
		}
		return true;
	}
	else return vec[v] == color;
}

bool dos_colorejable(graf& G) {
	vector<vertex> vec_colors(G.size(), -1);
	for (vertex v = 0; v < G.size(); ++v) {
		if (vec_colors[v] == -1) {
			if (not dos_colorejable_dfs(G, vec_colors, v, 0)) return false;
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
		if (dos_colorejable(G)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
