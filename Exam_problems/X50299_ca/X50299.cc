#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> P;
typedef vector<P> VP;
typedef vector<VP> VVP;
const int INF = INT_MAX;
 
int mod_dijkstra(const VVP& G) {
	vector<bool> finished(G.size(), false);
	vector<int> dist(G.size(), INF);
	priority_queue<P, vector<P>, greater<P>> pq;
	dist[0] = 0;
	pq.push({0,0});
	while (not pq.empty()) {
		int v = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (v == 1) return dist[1];
		if (not finished[v]) {
			finished[v] = true;
			for (auto w : G[v]) {
				int cost2 = max(cost, w.second);
				if (cost2 < dist[w.first]) {
					dist[w.first] = cost2;
					pq.push({cost2, w.first});
				}
			}
		}
	}
	return INF;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		VVP G(n, VP(0));
		for (int i = 0; i < m; ++i) {
			int x, y, w;
			cin >> x >> y >> w;
			G[x].push_back({y,w});
		}
		cout << mod_dijkstra(G) << endl;
	}
}
