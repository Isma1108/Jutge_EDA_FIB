#include <iostream>
#include <vector>
using namespace std;

typedef pair<string,bool> str;

void escriu_perm(const vector<string>& V) {	
	cout << '(';
	for (int i = 0; i < V.size()-1; ++i) cout << V[i] << ',';
	cout << V[V.size()-1] << ')' << endl;
}	

void permutacions(vector<str>& V, int i, int n, vector<string>& sol) {
	if (i == n) escriu_perm(sol);
	else {
		for (int j = 0; j < n; ++j) {
			if (not V[j].second) {
				sol[i] = V[j].first;
				V[j].second = true;
				permutacions(V, i+1, n, sol);
				V[j].second = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<str> V(n);
	vector<string> sol(n);
	string s;
	for (int i = 0; i < n; ++i) {cin >> s; V[i] = make_pair(s, false);}
	permutacions(V, 0, n, sol);
}
