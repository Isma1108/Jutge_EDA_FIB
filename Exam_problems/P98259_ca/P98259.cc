#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC; typedef vector<VC> VVC;
typedef vector<int> VI; typedef vector<VI> VVI;
typedef pair<int,int> Pos;

const int DI[4] = {-1, 0, 0, 1};
const int DJ[4] = {0, -1, 1, 0};
int n, m;

bool pos_ok(const VVC& mapa, int i, int j) {
	return i >= 0 and i < n and j >= 0 and j < m
		and mapa[i][j] != '#';
}

int busca_telecos(const VVC& mapa, int& p) {
	VVI dist(n, VI(m, -1));
	VVI pers(n, VI(m, 0));
	queue<Pos> q;
	dist[0][0] = 0;
	pers[0][0] = (mapa[0][0] == 'P');
	q.push({0,0});
	
	while (not q.empty()) {
		Pos pos = q.front();
		int i = pos.first, j = pos.second;
		q.pop();
		if (mapa[i][j] == 'T') {p = pers[i][j]; return dist[i][j];} 
		for (int k = 0; k < 4; ++k) {
			int ii = i + DI[k];
			int jj = j + DJ[k];
			if (pos_ok(mapa, ii, jj)) {
				int np = pers[i][j];
				if (mapa[ii][jj] == 'P') ++np;
				if (dist[ii][jj] == -1) {
					dist[ii][jj] = dist[i][j] + 1;
					pers[ii][jj] = np;
					q.push({ii, jj});
				}
				else if (dist[ii][jj] == dist[i][j] + 1 and pers[ii][jj] < np)
					pers[ii][jj] = np;
			}
		}
	}
	return -1;
}

int main() {
	while (cin >> n >> m) {
		VVC mapa(n, VC(m));
		bool hi_es = false;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> mapa[i][j];
				if (mapa[i][j] == 'T') hi_es = true;
			}
		}
		if (not hi_es) cout << "El telecos ha fugit." << endl;
		else {
			int p = 0;
			int min_passos = busca_telecos(mapa, p);
			if (min_passos == -1) cout << "El telecos esta amagat." << endl;
			else cout << min_passos << ' ' << p << endl;
		}
	}
}
