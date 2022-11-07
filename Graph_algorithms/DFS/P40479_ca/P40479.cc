#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> fila;
typedef vector<fila> mapa;
typedef vector<pair<int,int>> pos;

void DFS_paint(mapa& M, int i, int j, char c, bool first) {
	if (M[i][j] == '.' or first) {
		M[i][j] = c;
		DFS_paint(M, i+1, j, c, false);
		DFS_paint(M, i-1, j, c, false);
		DFS_paint(M, i, j+1, c, false);
		DFS_paint(M, i, j-1, c, false);
	}
}

void paint(mapa& M, const pos& V) {
	for (auto v : V) {
		DFS_paint(M, v.first, v.second, M[v.first][v.second], true);
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		pos where_to_start(0);	
		mapa M(n, fila(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> M[i][j];
				if (M[i][j] != '#' and M[i][j] != '.')
					where_to_start.push_back(make_pair(i,j));
			}
		}
		paint(M, where_to_start);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cout << M[i][j];
			cout << endl;
		}
		cout << endl;
	}
}
