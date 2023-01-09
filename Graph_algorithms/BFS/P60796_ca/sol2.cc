#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;

struct Pos {
	int i, j;
	int dist;
	Pos(int i, int j, int d) {
		this->i = i;
		this->j = j;
		this->dist = d;
	}
};

bool BFS_dmin(VVC& mapa, int& d_min, int i, int j) {
	queue<Pos> Q;
	d_min = 0;
	if (mapa[i][j] != 'X') Q.push(Pos(i,j,0));
	while (not Q.empty()) {
		Pos aux = Q.front();
		Q.pop();
		i = aux.i; j = aux.j; d_min = aux.dist;
		
		if (mapa[i][j] == 't') return true;
		mapa[i][j] = 'X';

		if (mapa[i][j-1] != 'X') Q.push(Pos(i, j-1,d_min+1));
		if (mapa[i-1][j] != 'X') Q.push(Pos(i-1, j,d_min+1));
		if (mapa[i][j+1] != 'X') Q.push(Pos(i, j+1,d_min+1));
		if (mapa[i+1][j] != 'X') Q.push(Pos(i+1, j,d_min+1));
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	VVC mapa(n+2, VC(m+2, 'X'));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cin >> mapa[i][j];
	}
	int d_min, i, j;
	cin >> i >> j;
	if (BFS_dmin(mapa, d_min, i, j)) cout << "distancia minima: " << d_min << endl;
	else cout << "no es pot arribar a cap tresor" << endl;
}
