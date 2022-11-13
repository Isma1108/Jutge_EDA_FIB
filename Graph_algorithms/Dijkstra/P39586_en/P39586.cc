#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> graf;
typedef vector<int> VI;
typedef vector<bool> VB;

int dijkstra(const graf& G, int s, int d, vector<int>& ways)  {
	ways[s] = 1;
	VI dist(G.size(), INF);
	VB visited(G.size(), false);	
	priority_queue<PI, vector<PI>, greater<PI>> Q;
	dist[s] = 0;
	Q.push(make_pair(0,s));

	while (not Q.empty()) {
		int v = Q.top().second;
		Q.pop();
		if (not visited[v]) {
			visited[v] = true;
			for (auto w : G[v]) {
				int d = dist[v] + w.second;
				if (d < dist[w.first]) {
					dist[w.first] = d;
					ways[w.first] = ways[v];
					Q.push(make_pair(dist[w.first], w.first));
				}
				else if (d == dist[w.first]) ways[w.first] += ways[v];  
			}
		}
	}
	return dist[d];
}

int main() {
	int n;
	while (cin >> n) {
		int m; cin >> m;
		graf G(n, VPI(0));
		for (int i = 0; i < m; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			G[u].push_back(make_pair(v, c));
		}
		int x, y, min_cost; 
		cin >> x >> y;
		vector<int> ways(G.size(), 0);
		min_cost = dijkstra(G, x, y, ways);
		if (min_cost == INF) 
			cout << "no path from " << x << " to " << y << endl;
		else cout << "cost " << min_cost << ", " << ways[y] << " way(s)" << endl; 
	}
}
