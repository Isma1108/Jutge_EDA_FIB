#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB; 

struct Pos {
	int i, j;
	Pos(int i2, int j2) : i(i2), j(j2) {}
};

int n, m;

const int N_DIRS = 4;
const int DR[N_DIRS] = {0, -1, 0, 1};
const int DC[N_DIRS] = {1, 0, -1, 0};

bool pos_ok(const Pos& p) {
	return p.i >= 0 and p.i < n and p.j >= 0 and p.j < m;
}

void print_sol(const VC& sol) {
	for (int i = 0; i < sol.size(); ++i) cout << sol[i];
	cout << endl;
}

void viatge_tortuga(const VVC& mapa, Pos p_actual, Pos p_final, VC& sol, VVB& vist) {
	int i = p_actual.i, j = p_actual.j;
	if (i == p_final.i and j == p_final.j) {
		print_sol(sol);
	}
	else {
		for (int k = 0; k < N_DIRS; ++k) {
			int r = i + DR[k];
			int c = j + DC[k];
			if (pos_ok(Pos(r, c)) and not vist[r][c]) {
				vist[r][c] = true;
				sol.push_back(mapa[r][c]);
				viatge_tortuga(mapa, Pos(r,c), p_final, sol, vist);
				sol.pop_back();
				vist[r][c] = false;
			}
		}
	}	
}

int main() {
	cin >> n >> m;
	VVC mapa(n, VC(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> mapa[i][j];
	}
	int i1, j1, i2, j2; 
	cin >> i1 >> j1 >> i2 >> j2;
	Pos p_inicial = Pos(i1, j1);
	Pos p_final = Pos(i2, j2);
	VC sol(1, mapa[i1][j1]);
	VVB vist(n, VB(m, false)); 
	vist[i1][j1] = true;
	viatge_tortuga(mapa, p_inicial, p_final, sol, vist);
}
