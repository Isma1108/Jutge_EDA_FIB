#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

//Fa falta aquest booleà, ja que si arribo a la solució (que és única)
//no em serveix de res fer més crides recursives, cal sortir com abans millor!!
bool solucionat = false;

int quin_subq(int i, int j) {return (i/3)*3 + j/3;}

void print_solution(const VVI& sol) {
	cout << endl;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (j == 0) cout << sol[i][j];
			else cout << ' ' << sol[i][j];
		}
		cout << endl;
	}
}

bool tot_correcte(int i, int j, int k, const VVB& files, const VVB& cols, const VVB& subq) {
	return not solucionat and not files[i][k-1] and not cols[j][k-1] and not subq[quin_subq(i,j)][k-1];
}

void resol_sudoku(VVI& sol, VVB& files, VVB& cols, VVB& subq, int i, int j) {
	if (i == 8 and j == 9) {print_solution(sol); solucionat = true; return;}	
	else if (j == 9) resol_sudoku(sol, files, cols, subq, i+1, 0);
	else {
		if (sol[i][j] == -1) {
			for (int k = 1; k <= 9; ++k) {
					if (tot_correcte(i,j,k, files, cols, subq)) {
						files[i][k-1] = cols[j][k-1] = subq[quin_subq(i,j)][k-1] = true;
						sol[i][j] = k;
						resol_sudoku(sol, files, cols, subq, i, j+1);
						files[i][k-1] = cols[j][k-1] = subq[quin_subq(i,j)][k-1] = false;
						sol[i][j] = -1;
				}
			}
		}
		else resol_sudoku(sol, files, cols, subq, i, j+1);
	}
}

int main() {
	int n;
	cin >> n;
	cout << n << endl;
	//n sudokus 9x9 ...
	for (int i = 0; i < n; ++i) {
		solucionat = false;
		VVI sol(9, VI(9, -1));
		VVB files(9, VB(9, false));	
		VVB cols(9, VB(9, false));	
		VVB subq(9, VB(9, false));	
		
		for (int j = 0; j < 9; ++j) {
			for (int k = 0; k < 9; ++k) {
				char c; cin >> c;
				if (c != '.') {
					int num = c - '0';
					sol[j][k] = num;
					files[j][num-1] = true;
					cols[k][num-1] = true;
					subq[quin_subq(j,k)][num-1] = true;
				}
			}
		}
		resol_sudoku(sol, files, cols, subq, 0, 0);
	}
}
