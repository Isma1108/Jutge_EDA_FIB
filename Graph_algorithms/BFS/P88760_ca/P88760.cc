#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct roca {
	double x, y, rd;
};

bool son_adjacents(const roca& r1, const roca& r2, double d) {
	double dist = sqrt(pow(r1.x-r2.x, 2) + pow(r1.y - r2.y,2));
	dist = dist - r1.rd - r2.rd;
	return (dist <= d ? true : false);
}

int BFS_roques(const vector<roca>& V, double d) {
	queue<int> Q;
	vector<int> dist(V.size(), -1); //vector de salts minims per arribar-hi

	dist[0] = 0;
	Q.push(0);
	while (not Q.empty()) {
		int pos = Q.front();
		Q.pop();
		if (pos == dist.size()-1) return dist[pos];
		for (int j = 0; j < V.size(); ++j) {
			if (j != pos and dist[j] == -1 and son_adjacents(V[pos], V[j], d)) {
				dist[j] = dist[pos] + 1;
				Q.push(j);
			}
		}
	}
	return -1;
}

int main() {
	int n;
	while (cin >> n) {
		vector<roca> V(n);
		double d; cin >> d;
		for (int i = 0; i < n; ++i) {
			cin >> V[i].x >> V[i].y >> V[i].rd;
		}
		int min_salts = BFS_roques(V, d);
		if (min_salts != -1) cout << min_salts << endl;
		else cout << "Xof!" << endl;
	}
}
