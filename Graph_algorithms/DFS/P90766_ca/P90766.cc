#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> fila;
typedef vector<fila> mapa;

int DFS_num_tresors(mapa& M, int n, int m) {
	if (M[n][m] == 'X') return 0;
	if (M[n][m] == 't') {
		M[n][m] = 'X';
		return 1 + DFS_num_tresors(M, n+1, m) + DFS_num_tresors(M, n, m+1) +
			DFS_num_tresors(M, n-1, m) + DFS_num_tresors(M, n, m-1);
	}
	M[n][m] = 'X';
	return DFS_num_tresors(M, n+1, m) + DFS_num_tresors(M, n, m+1) + 
		DFS_num_tresors(M, n-1, m) + DFS_num_tresors(M, n, m-1);
}

int main() {
	int n, m;
	cin >> n >> m;
	mapa M(n+2, fila(m+2, 'X'));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cin >> M[i][j];
	}
	
	int n_aux, m_aux;
	cin >> n_aux >> m_aux;
	cout << DFS_num_tresors(M, n_aux, m_aux) << endl;
}
