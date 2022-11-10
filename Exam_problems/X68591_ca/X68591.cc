#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> graf;

int dfs(const graf& G, int v, int pare, vector<bool>& visitats) {
	visitats[v] = true;
	int mida = 1;
	for (auto w : G[v]) {
		if (not visitats[w]) mida += dfs(G, w, v, visitats);
	}
	return mida;
}

int main() {
	int n;
	while (cin >> n) {
		int m;
		cin >> m;
		graf G(n, VI(0));
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		vector<bool> visitats(G.size(), false);
		int mn = G.size() + 1, mx = 0;
		for (int v = 0; v < G.size(); ++v) {
			if (not visitats[v]) {
				int mida = dfs(G, v, v, visitats);
				mn = min(mn, mida);
				mx = max(mx, mida);
			}
		}
		cout << mn << ' ' << mx << endl;
	}
}
