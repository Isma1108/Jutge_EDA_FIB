#include <vector>
using namespace std;

int binary_sarch(double x, const vector<double>& v, int l, int r) {
	if (l == r) return l;
	int m = (l+r)/2;
	if (x < v[m]) return binary_sarch(x, v, l, m);
	return binary_sarch(x, v, m+1, r);
}

int mes_a_la_dreta(double x, const vector<double>& v) {
	return binary_sarch(x,v, 0, v.size());
}
