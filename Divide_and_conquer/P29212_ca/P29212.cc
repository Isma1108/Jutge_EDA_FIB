#include <iostream>
using namespace std;

int mod_power(int n, int k, int m) {
	if (k == 0) return 1;
	int p = mod_power(n, k/2, m);
	if (k%2 == 0) return (p*p) % m;
	return (((p*p) % m) * n) % m;
}

int main() {
	int n, k, m;
	while (cin >> n >> k >> m) cout << mod_power(n, k, m) << endl;
}
