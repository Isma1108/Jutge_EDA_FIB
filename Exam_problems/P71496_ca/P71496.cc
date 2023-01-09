#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> edge;
typedef vector<edge> VE;
typedef vector<VE> graph;

int prim_msp(const graph& G) {
	vector<bool> visited(G.size(), false);
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	visited[0] = true;
	for (edge e : G[0]) pq.push(e);
	int num_vtx = 1, min_cost = 0;
	while (num_vtx < G.size()) {
		int cost = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (not visited[v]) {
			visited[v] = true;
			for (edge e : G[v]) pq.push(e);
			min_cost += cost;
			++num_vtx;
		}
	}
	return min_cost;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		graph G(n, VE(0));
		int cost_total = 0;
		for (int i = 0; i < m; ++i) {
			int x, y, c;
			cin >> x >> y >> c; 
			cost_total += c;
			G[x].push_back({c, y});
			G[y].push_back({c, x});
		}
		int min_cost = prim_msp(G);
		cout << cost_total - min_cost << endl;
	}
}
