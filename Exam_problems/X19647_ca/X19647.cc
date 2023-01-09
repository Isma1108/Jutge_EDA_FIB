#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> vertex;
typedef vector<int> VI;
typedef vector<vertex> VX;
typedef vector<VX> VVX;
const int INF = 1e9;

int dijkstra(const VVX& graf, const VI& nit, int s, int d) {
	VI dist(graf.size(), INF);	
	vector<bool> finished(graf.size(), false);
	priority_queue<vertex, vector<vertex>, greater<vertex>> pq;
	dist[s] = 0;
	pq.push({0, s});

	while (not pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		if (not finished[v]) {
			finished[v] = true;
			if (v == d) return dist[v];
			for (auto w : graf[v]) {
				int dx = dist[v] + w.second;
				if (w.first != d) dx += nit[w.first];  
				if (dx < dist[w.first]) {
					dist[w.first] = dx;
					pq.push({dx, w.first});
				}
			}
		}
	}
	return INF;
}

int main() {
	int n, m;
	cin >> n >> m;
	VVX graf(n, VX(0));
	VI nit(n);
	for (int i = 0; i < n; ++i) cin >> nit[i];
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		graf[u].push_back({v, c});
		graf[v].push_back({u, c});
	}
	int s, d;
	while (cin >> s >> d) {
		int min_cost = dijkstra(graf, nit, s, d);	
		cout << "c(" << s << ',' << d << ") = "; 
		if (min_cost == INF) cout << "+oo" << endl;
		else cout << min_cost << endl;
	}
}
