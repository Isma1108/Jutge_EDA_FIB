#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef pair<bool,bool> BB;
typedef vector<BB> VBB;

int x, n;

void escriu_solucio(const VI& m, const VBB& usades) {
	cout << x << " = ";
	int suma = 0;
	for (int i = 0; i < n and suma != x; ++i) {
		if (usades[i].first) {
			cout << m[i]; suma += m[i];
			if (suma != x) cout << " + ";
		}
		if (usades[i].second) {
			cout << m[i] << 'p'; suma += m[i];
			if (suma != x) cout << " + ";
		}
	}
	cout << endl;
}

void monedes(VI& m, VBB& usades, int idx, int suma) {
	if (suma == x) escriu_solucio(m, usades);	
	else {
		if (idx < n and suma < x and m[idx] + suma <= x) {
			if (not usades[idx].first) {
				usades[idx].first = true;
				monedes(m, usades, idx, m[idx] + suma);
				usades[idx].first = false;
			}
			if (not usades[idx].second) {
				usades[idx].second = true;
				monedes(m, usades, idx + 1, m[idx] + suma);
				usades[idx].second = false;
			}
			monedes(m, usades, idx + 1, suma);
		}
	}
}

int main() {
	while (cin >> x >> n) {
		VI m(n);
		for (int i = 0; i < n; ++i) cin >> m[i];
		VBB usades(n, make_pair(false, false));
		//Per assegurar l'ordre de les solucions demanat, cal fer un sort
		sort(m.begin(), m.end());
		monedes(m, usades, 0, 0);
		cout << "----------" << endl;
	}
}
