#include <iostream>
#include <vector>
using namespace std;


void escriu_perm(const vector<int>& V) {	
	cout << '(';
	for (int i = 0; i < V.size()-1; ++i) cout << V[i] << ',';
	//Per la precondició V.size()-1 no pot ser 0
	cout << V[V.size()-1] << ')' << endl;
}	

void permutations(vector<int>& V, int i, int n, vector<bool>& used) {
	if (i == V.size()) escriu_perm(V);
	else {
		for (int j = 1; j <= n; ++j) {
			if (not used[j-1]) {
				V[i] = j;
				used[j-1] = true;
				permutations(V, i+1, n, used);
				used[j-1] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> V(n);
	vector<bool> used(n, false);
	permutations(V, 0, n, used);
}
