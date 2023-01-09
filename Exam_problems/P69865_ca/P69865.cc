#include <iostream>
#include <vector>
using namespace std;

struct Coord {
	int i, j;
	Coord(int f, int c) {i = f; j = c;} 
};

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<Coord> VP;
typedef vector<bool> VB;
typedef vector<vector<bool>> VVB;

const int Dir_fila_K[8] = {-2,-2,-1,-1,1,1,2,2};
const int Dir_col_K[8] = {-1,1,-2,2,-2,2,-1,1};

const int Dir_fila_B[4] = {-1,-1,1,1};
const int Dir_col_B[4] = {-1,1,-1,1};

int n, m;

bool is_num(const char& c) {return c >= '0' and c <= '9';}

bool pos_ok(const Coord& c) {return c.i >= 0 and c.i < n and c.j >= 0 and c.j < m;}

int dfs(VVC& mapa, VVB& mark, Coord c, char tipus) {
	int total = 0;
	mark[c.i][c.j] = true;
	if (tipus == 'K') {
		for (int i = 0; i < 8; ++i) {
			Coord aux = Coord(c.i + Dir_fila_K[i], c.j + Dir_col_K[i]);
			if (pos_ok(aux) and mapa[aux.i][aux.j] != 'T' and not mark[aux.i][aux.j]) {
				total += dfs(mapa, mark, aux, 'K');
			}
		}
	}
	else {
		for (int i = 0; i < 4; ++i) {
			Coord aux = Coord(c.i + Dir_fila_B[i], c.j + Dir_col_B[i]);
			if (pos_ok(aux) and mapa[aux.i][aux.j] != 'T' and not mark[aux.i][aux.j]) {
				total += dfs(mapa, mark, aux, 'B');
			}
		}
	}
	if (is_num(mapa[c.i][c.j])) {
		total += mapa[c.i][c.j] - '0';
		mapa[c.i][c.j] = '.';
	}
	return total;
}

int main() {
	while (cin >> n >> m) {
		VVC mapa(n, VC(m, 'T'));
		VP alfils, cavalls;
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> mapa[i][j];
				if (mapa[i][j] == 'B') alfils.push_back(Coord(i,j));
				else if (mapa[i][j] == 'K') cavalls.push_back(Coord(i,j));
			}
		}
		int monedes = 0;
		VVB marcatge_alfils(n, VB(m, false));
		for (int i = 0; i < alfils.size(); ++i) {
			Coord c = alfils[i];
			if (not marcatge_alfils[c.i][c.j]) monedes += dfs(mapa, marcatge_alfils, c, 'B');
		}

		VVB marcatge_cavalls(n, VB(m, false));
		for (int i = 0; i < cavalls.size(); ++i) {
			Coord c = cavalls[i];
			if (not marcatge_cavalls[c.i][c.j]) monedes += dfs(mapa, marcatge_cavalls, c, 'K');
		}
		cout << monedes << endl;
	}
}
