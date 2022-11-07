#include <iostream>
#include <vector>
using namespace std;

void prod(vector<int>& p1, const vector<int>& p2) {
	vector<int> aux(p1.size());
	for (int i = 0; i < p1.size(); ++i) aux[i] = p1[p2[i]];
	p1 = aux;
}

vector<int> perm_exp(const vector<int>& v, int k) {
	vector<int> perm_final(v.size());
	if (k == 0) {
		for (int i = 0; i < v.size(); ++i) perm_final[i] = i;
		return perm_final;
	}
	perm_final = perm_exp(v, k/2);
	if (k % 2 == 0) {
		prod(perm_final, perm_final);
		return perm_final;
	}
	prod(perm_final, perm_final);
	prod(perm_final, v);
	return perm_final;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		int k;
		cin >> k;
		vector<int> perm_final = perm_exp(v, k);
		cout << perm_final[0];
		for (int i = 1; i < n; ++i) cout << ' ' << perm_final[i];
		cout << endl;
	}
}
