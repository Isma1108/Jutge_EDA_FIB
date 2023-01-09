#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

void BFS(const VVI& graf, VI& cami) {
	queue<int> Q;
	vector<bool> visitat(graf.size(), false);
	Q.push(0);
	visitat[0] = true;
	while (not Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (auto w : graf[v]) {
			if (not visitat[w]) {
				cami[w] = v;
				visitat[w] = true;
				if (w == graf.size()-1) return;
				else Q.push(w);
			}
		}
	}
}

void print_cami(const VI& cami, int s, int d) {
	if (s == d) cout << s;	
	else {
		print_cami(cami, s, cami[d]);
		cout << ' ' << d;
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		VVI graf(n, VI(0));
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			graf[x].push_back(y);
		}
		for (int i = 0; i < n; ++i) sort(graf[i].begin(), graf[i].end());
		VI cami(n, -1);
		BFS(graf, cami);
		print_cami(cami, 0, n-1);
		cout << endl;
	}
}
