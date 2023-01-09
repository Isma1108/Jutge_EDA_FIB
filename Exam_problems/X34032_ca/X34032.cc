#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC; typedef vector<VC> VVC; 
typedef vector<int> VI; typedef vector<VI> VVI;
typedef pair<int,int> Pos;

const int KI[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
const int KJ[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int f, c;

bool pos_ok(const VVC& tauler, int i, int j) {
	return i >= 0 and i < f and j >= 0 and j < c and tauler[i][j] != 'X';
}

int min_dist_bfs(const VVC& tauler, int i, int j) {
	queue<Pos> q;
	VVI dist(f, VI(c, -1));
	if (tauler[i][j] != 'X') q.push({i,j});
	dist[i][j] = 0;

	while (not q.empty()) {
		Pos p = q.front();
		i = p.first; j = p.second;
		q.pop();
		if (tauler[i][j] == 'p') return dist[i][j];

		for (int k = 0; k < 8; ++k) {
			int ki = i + KI[k];
			int kj = j + KJ[k];
			if (pos_ok(tauler, ki, kj) and dist[ki][kj] == -1) {
				q.push({ki, kj});
				dist[ki][kj] = dist[i][j] + 1;
			}
		}
	}
	return -1;
}

int main() {
	while (cin >> f >> c) {
		VVC tauler(f, VC(c)); 	
		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) cin >> tauler[i][j];
		}
		int fc, cc;
		cin >> fc >> cc;
		int min_passos = min_dist_bfs(tauler, fc-1, cc-1);
		if (min_passos == -1) cout << "no" << endl;
		else cout << min_passos << endl;
	}
}
