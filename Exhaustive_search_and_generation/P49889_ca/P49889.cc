#include <iostream>
#include <vector>
using namespace std;

int n;
vector<char> cn, vn;

void escriu_solucio(const vector<char>& sol) {
	for (int i = 0; i < 2*n; ++i) cout << sol[i];
	cout << endl;
}

void escriu_paraules(vector<char>& sol, vector<bool>& usat_c, vector<bool> usat_v, int idx) {
	if (idx == 2*n) escriu_solucio(sol);
	else {
		if (idx%2 == 0) {
			for (int i = 0; i < n; ++i) {
				if (not usat_c[i]) {
					sol[idx] = cn[i];
					usat_c[i] = true;
					escriu_paraules(sol, usat_c, usat_v, idx+1);
					usat_c[i] = false;
				}
			}
		}
		else {
			for (int i = 0; i < n; ++i) {
				if (not usat_v[i]) {
					sol[idx] = vn[i];
					usat_v[i] = true;
					escriu_paraules(sol, usat_c, usat_v, idx+1);
					usat_v[i] = false;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	cn = vn = vector<char>(n);
	for (int i = 0; i < n; ++i) cin >> cn[i];
	for (int i = 0; i < n; ++i) cin >> vn[i];
	vector<bool> usat_c(n, false);
	vector<bool> usat_v(n, false);
	vector<char> sol(2*n);
	escriu_paraules(sol, usat_c, usat_v, 0);
}
