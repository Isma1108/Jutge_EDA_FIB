#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Només hem de minimitzar els salts, ja que els pesos són constants
//Podem usar un algorisme de cerca en amplada per assolir l'objectiu

typedef pair<int,int> Pos;
typedef vector<Pos> VP;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int KI[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int KJ[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool pos_ok(int n, int m, int i, int j) {
	return i >= 0 and i < n and j >= 0 and j < m;
}

int punts_bfs(int n, int m, Pos inici, Pos obj) {
	int oi = obj.first, oj = obj.second;
	VVI dist(n, VI(m, -1));
	queue<Pos> q;
	dist[inici.first][inici.second] = 0;
	q.push(inici);

	while (not q.empty()) {
		Pos p = q.front();
		int i = p.first, j = p.second;
		q.pop();
		if (p == obj) return dist[i][j];
		
		for (int k = 0; k < 8; ++k) {
			int ii = i + KI[k];
			int jj = j + KJ[k];
			if (pos_ok(n, m, ii, jj) and dist[ii][jj] == -1) {
				dist[ii][jj] = dist[i][j] + 1;
				q.push({ii,jj});
			}
		}
	}
	return -1;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		int w, l, k;
		cin >> w >> l >> k;
		VP pos(k); 
		for (int i = 0; i < k; ++i) {
			cin >> pos[i].first >> pos[i].second;
		}
		int i = 0;
		bool possible = true;
		int max_punts = 0;
		int punts = 0;
		Pos inici = {0,0};

		while (possible and i < k) {
			int salts = punts_bfs(n, m, inici, pos[i]);
			if (salts != -1) {
				punts += (w - salts*l);
				if (punts > max_punts) max_punts = punts;
			}
			else possible = false;
			inici = pos[i];
			++i;
		}
		cout << max_punts << endl;
	}
}


