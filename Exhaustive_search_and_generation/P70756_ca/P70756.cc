#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<VB> VVB;
int n, p;

void print_sol(const VS& paraules, const VVB& used) {
	for (int i = 0; i < p; ++i) {
		cout << "subconjunt " << i+1 << ": {";
		int k = 0;
		while (k < n and not used[i][k]) ++k;
		if (k < n) cout << paraules[k]; ++k;
		for (k; k < n; ++k) {
			if (used[i][k]) cout << ',' << paraules[k];
		}
		cout << '}' << endl;
	}
	cout << endl;
}

void particions(const VS& paraules, int idx, VVB& used) {
	if (idx == n) print_sol(paraules, used);
	else {
		for (int i = 0; i < p; ++i) {
			if (not used[i][idx]) {
				used[i][idx] = true;
				particions(paraules, idx+1, used);
				used[i][idx] = false;
			}
		}
	}
}

int main() {
	cin >> n;
	VS paraules(n);
	for (int i = 0; i < n; ++i)	cin >> paraules[i];
	
	cin >> p;
	//Pel marcatge:
	VVB used(p, VB(n, false));
	particions(paraules, 0, used);
}
