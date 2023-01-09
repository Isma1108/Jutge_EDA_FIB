#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,pair<int,int>> Pos;
typedef vector<bool> VB; typedef vector<VB> VVB;
typedef vector<int> VI; typedef vector<VI> VVI;

const int INF = INT_MAX;
const pair<int,int> DIRS[4] = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
int n; 

bool border(int i, int j) {
	return i == 0 or i == n-1 or j == 0 or j == n-1;
}

int dijkstra(const VVI& tauler) {
	VVB finished(n, VB(n, false));
	VVI dist(n, VI(n, INF));
	priority_queue<Pos, vector<Pos>, greater<Pos>> pq; 

	dist[n/2][n/2] = tauler[n/2][n/2];
	pq.push({dist[n/2][n/2], {n/2, n/2}});

	while (not pq.empty()) {
		int w = pq.top().first;
		int i = pq.top().second.first;
		int j = pq.top().second.second;
		pq.pop();
		
		if (not finished[i][j]) {
			finished[i][j] = true;
			if (border(i, j)) return dist[i][j];
			for (int k = 0; k < 4; ++k) {
				int i2 = i + DIRS[k].first;
				int j2 = j + DIRS[k].second;
				
				int nd = w + tauler[i2][j2];
				if (nd < dist[i2][j2]) {
					dist[i2][j2] = nd;
					pq.push({nd, {i2, j2}});
				}
			}
		}
	}
	return INF;
}

int main() {
	while (cin >> n) {
		VVI tauler(n, VI(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> tauler[i][j];
		}
		cout << dijkstra(tauler) << endl;
	}
}
