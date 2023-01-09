#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef pair<int,int> Pos;

const int MI[4] = {-1, 0, 0, 1};
const int MJ[4] = {0, 1, -1, 0};

bool puc_arribar(VVC& mapa, int i, int j, int n, int m) {
	if (mapa[i][j] == 'X') return false;
	if (mapa[i][j] == 'F') return true;
	mapa[i][j] = 'X';
	return puc_arribar(mapa, i-1, j, n, m) or puc_arribar(mapa, i+1, j, m, m)
		or puc_arribar(mapa, i, j-1, n, m) or puc_arribar(mapa, i, j+1, n, m);
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		VVC mapa(n+2, VC(m+2, 'X'));
		int pi, pj;
		vector<Pos> monstres(0);
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> mapa[i][j];
				if (mapa[i][j] ==  'I') {pi = i; pj = j;}
				else if (mapa[i][j] == 'M') monstres.push_back({i,j});
			}
		}

		for (int i = 0; i < monstres.size(); ++i) {
			for (int k = 0; k < 4; ++k) {
				int mi = monstres[i].first + MI[k];
				int mj = monstres[i].second + MJ[k];
				mapa[mi][mj] = 'X';
			}
		}
		if (puc_arribar(mapa, pi, pj, n, m)) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}
