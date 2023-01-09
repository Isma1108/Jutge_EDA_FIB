#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e8;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> graf;

int dijkstra(const graf& G, int s, int d) {
	vector<int> D(G.size(), INF);
	vector<bool> finished(G.size(), false);
	priority_queue<PI, vector<PI>, greater<PI>> Q;
	D[s] = 0;
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
					Q.push(make_pair(dist, w.first));
				}
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
		int x, y; cin >> x >> y;
		int min_cost = dijkstra(G, x, y);
		if (min_cost != INF) cout << min_cost << endl;
		else cout << "no path from " << x << " to " << y << endl;
	}
}
