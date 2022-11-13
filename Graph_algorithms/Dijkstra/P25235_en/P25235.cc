#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e8;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> graf;

int dijkstra(const graf& G, int s, int d, vector<int>& passos) {
	vector<int> D(G.size(), INF);
	vector<bool> finished(G.size(), false);
	priority_queue<PI, vector<PI>, greater<PI>> Q;
	D[s] = 0;
	passos[s] = 0;
	Q.push(make_pair(0,s));
	
	while (not Q.empty()) {
		int v = Q.top().second;
		Q.pop();
		if (not finished[v]) {
			finished[v] = true;
			for (auto w : G[v]) {
				int dist = D[v] + w.second;
				if (dist < D[w.first]) {
					D[w.first] = dist;
					passos[w.first] = passos[v] + 1;
					Q.push(make_pair(D[w.first], w.first));
				}
				else if (dist == D[w.first] and passos[v] + 1 < passos[w.first]) 
					passos[w.first] = passos[v] + 1;
			}
		}
	}
	return D[d];
}

int main() {
	int n;
	while (cin >> n) {
		int m; cin >> m;
		graf G(n, VPI(0));
		for (int i = 0; i < m; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			G[u].push_back(make_pair(v,c));
		}
		int x, y, steps; cin >> x >> y;
		vector<int> passos(G.size(), INF);

		int min_cost = dijkstra(G, x, y, passos);
		if (min_cost != INF) {
			cout << "cost " << min_cost << ", " << passos[y] << " step(s)" << endl;
		}
		else cout << "no path from " << x << " to " << y << endl;
	}
}
