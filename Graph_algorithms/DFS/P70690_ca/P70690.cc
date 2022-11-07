#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> fila;
typedef vector<fila> mapa;

bool dfs_tresor(mapa& M, int n, int m) {	
	if (n < 0 or m < 0 or n >= M.size() or m >= M[0].size() or M[n][m] == 'X')
		return false;
	if (M[n][m] == 't') return true;
	M[n][m] = 'X';
	return dfs_tresor(M, n-1, m) or dfs_tresor(M, n, m-1) 
		or dfs_tresor(M, n+1, m) or dfs_tresor(M, n, m+1);
}

int main() {
	int n, m;
	cin >> n >> m;
	mapa M(n, fila(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> M[i][j];
	}
	int n_aux, m_aux;
	cin >> n_aux >> m_aux;
	if (dfs_tresor(M, n_aux-1, m_aux-1)) cout << "yes" << endl;
	else cout << "no" << endl;
}

