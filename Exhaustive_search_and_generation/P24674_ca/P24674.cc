#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void escriu_perm(const vector<string>& V) {	
	cout << '(';
	for (int i = 0; i < V.size()-1; ++i) cout << V[i] << ',';
	//Per la precondició V.size()-1 no pot ser 0
	cout << V[V.size()-1] << ')' << endl;
}	

void permutacions(vector<string>& V, int i, int n, unordered_map<string, bool>& used, vector<string>& sol) {
	if (i == n) escriu_perm(sol);
	else {
		for (int j = 0; j < n; ++j) {
			if (not used.find(V[j])->second) {
				sol[i] = V[j];
				used.find(V[j])-> second = true;
				permutacions(V, i+1, n, used, sol);
				used.find(V[j])->second = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<string> V(n);
	unordered_map<string, bool> used;
	for (int i = 0; i < n; ++i) {
		cin >> V[i];
		used.insert(make_pair(V[i], false));
	}
	vector<string> sol(n);
	permutacions(V, 0, n, used, sol);
}
