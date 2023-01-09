#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;
int f, c;

void print_sol(const VI& sol) {
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			if (sol[i] == j) cout << 'R';
			else cout << '.';
		}
		cout << endl;
	}
	cout << endl;
}

void bt(VB& cols, VI& sol, int idx) {
	if (idx == f) print_sol(sol);
	else {
		for (int i = 0; i < c; ++i) {
			if (not cols[i]) {
				cols[i] = true;
				sol[idx] = i;
				bt(cols, sol, idx+1);
				cols[i] = false;
			}
		}
	}
}

int main() {
	cin >> f >> c;
	VB mark_cols(c, false);
	VI solution(f);
	bt(mark_cols, solution, 0);
}
