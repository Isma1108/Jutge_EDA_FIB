#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> edge;
typedef vector<edge> VE;
typedef vector<VE> graph;

int weight_MSP(const graph& G) {				
	vector<bool> visited(G.size(), false);
	visited[0] = true; 
	priority_queue<edge, vector<edge>, greater<edge>> Q;
	for (edge e : G[0]) Q.push(e);
	int num_vtx = 1, sum_cost = 0;
	while (num_vtx < G.size()) {
		int cost = Q.top().first;
		int v = Q.top().second;
		Q.pop();
		if (not visited[v]) {
			visited[v] = true;
			for (edge e : G[v]) Q.push(e);
			sum_cost += cost;
			++num_vtx;
		}
	}
	return sum_cost;
}


int main() {
	int n;
	while (cin >> n) {
		int m; cin >> m;
		graph G(n, VE(0));
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			--u; --v;
			G[u].push_back(make_pair(w,v));
			G[v].push_back(make_pair(w,u));
		}
		cout << weight_MSP(G) << endl;
	}
}
