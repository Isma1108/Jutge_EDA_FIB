#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;

const int DI[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DJ[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, r;

void print_sol(const VVC& tauler) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << tauler[i][j];
		cout << endl;
	}
	cout << "----------" << endl;
}

bool puc_posar_rei(const VVC& tauler, int i, int j) {
	for (int k = 0;  k < 8; ++k) {
		int r = i + DI[k];
		int c = j + DJ[k];
		if (r >= 0 and r < n and c >= 0 and c < n and tauler[r][c] == 'K') return false;
	}
	return true;
}

void bt(int i, int j, VVC& tauler, int n_reis) {
	if (i == n) return;
	else if (n_reis == r) print_sol(tauler);	
	else if (j == n) bt(i+1, 0, tauler, n_reis);
	else {
		if (puc_posar_rei(tauler, i, j)) {
			tauler[i][j] = 'K';
			bt(i, j+1, tauler, n_reis+1);
			tauler[i][j] = '.';
		}
		bt(i, j+1, tauler, n_reis);
	}
}

int main() {
	cin >> n >> r;
	VVC tauler(n, VC(n, '.'));	
	bt(0, 0, tauler, 0);
}
