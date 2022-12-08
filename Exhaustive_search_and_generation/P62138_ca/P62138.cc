#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef set<int>::iterator set_it;

int n, m;

void print_sol(const VI& sol) {
	cout << sol[0];
	for (int i = 1; i < sol.size(); ++i) cout << ' ' << sol[i];
	cout << endl;
}

void topological_orders(const VVI& graf, VI& preds, VI& sol, set<int>& without_preds) {
	if (sol.size() == n) print_sol(sol); 
	else {
		for (set_it it = without_preds.begin(); it != without_preds.end(); ++it)	{
			int v = *it;
			sol.push_back(v);
			without_preds.erase(it);
			for (int j = 0; j < graf[v].size(); ++j) {
				--preds[graf[v][j]];
				if (preds[graf[v][j]] == 0) without_preds.insert(graf[v][j]);
			}
			topological_orders(graf, preds, sol, without_preds);
			sol.pop_back();
			//it no apunta a nada en este punto, necesitamos volver al inicio!!
			it = without_preds.insert(v).first; //insert devuelve un pair donde el primer elem. es el iterador!!
			for (int j = 0; j < graf[v].size(); ++j) {
				if (preds[graf[v][j]] == 0) without_preds.erase(graf[v][j]);
				++preds[graf[v][j]];
			}
		}
	}
}


int main() {
	cin >> n >> m;
	VVI graf(n, VI(0));
	VI preds(n, 0);
	
	int x, y;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		++preds[y];
		graf[x].push_back(y);
	}
	VI sol(0);
	VB used(n, false);
	set<int> without_preds;
	for (int i = 0; i < n; ++i) {
		if (preds[i] == 0) without_preds.insert(i);
	}
	topological_orders(graf, preds, sol, without_preds);
}
