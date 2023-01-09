#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC; 
int n, m;

int num_lols(VVC& mat, int i, int j, int num) {
	if (i == n) return num;
	if (j == m) return num_lols(mat, i+1, 0, num);
	
	//Probem de posar una L
	mat[i][j] = 'L';
	//Hem completat algun LOL?
	int lols_nous = 0;
	if (j >= 2 and mat[i][j-2] == 'L' and mat[i][j-1] == 'O') ++lols_nous;
	if (i >= 2 and mat[i-2][j] == 'L' and mat[i-1][j] == 'O') ++lols_nous;
	if (i >= 2 and j >= 2 and mat[i-2][j-2] == 'L' and mat[i-1][j-1] == 'O') ++lols_nous;
	if (i >= 2 and j+2 < m and mat[i-2][j+2] == 'L' and mat[i-1][j+1] == 'O') ++lols_nous;

	int n1 = num_lols(mat, i, j+1, num + lols_nous);

	//Ara probem de posar una O
	mat[i][j] = 'O';
	int n2 = num_lols(mat, i, j+1, num);

	return max(n1, n2);
}

int main() {
	while (cin >> n >> m) {
		VVC mat(n, VC(m));
		cout << num_lols(mat, 0, 0, 0) << endl;;
	}
}
