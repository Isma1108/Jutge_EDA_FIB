#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef vector<char> VC;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef unordered_map<char,int> CI;

int n;
CI char2int;	

void print_sol(const VC& sol) {
	for (int i = 0; i < sol.size(); ++i) cout << sol[i];
	cout << endl;
}

void combinacions_ind(const VC& ind, VB& colocats, const VVB& incmp, VC& sol, int idx, int ant) {
	if (idx == n) print_sol(sol);
	else {
		for (int i = 0; i < ind.size(); ++i) {
			if (not colocats[i]) {
				if (idx == 0 or incmp[ant][i]) {
					colocats[i] = true;
					sol[idx] = ind[i];
					combinacions_ind(ind, colocats, incmp, sol, idx + 1, i);
					colocats[i] = false;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	VC ind(n);
	for (int i = 0; i < n; ++i) {cin >> ind[i]; char2int[ind[i]] = i;}
	
	int m;
	cin >> m;
	VVB incmp(n, VB(n, true));
	for (int i = 0; i < m; ++i) {
		string p; cin >> p;	
		incmp[char2int[p[0]]][char2int[p[1]]] = false; 
		incmp[char2int[p[1]]][char2int[p[0]]] = false; 
	}
	VB colocats(n, false);
	VC sol(n);
	combinacions_ind(ind, colocats, incmp, sol, 0, 0);
}
