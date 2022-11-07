#include <iostream>
#include <cmath>
#include <cmath>
using namespace std;

int days(int min, int max, double m, double f, double r) {
	if (min <= max) {
		int mid = (min + max) / 2;
		double bank = log(r)*mid + log(m);
		double oak = log(mid*f + m);
		if (oak < bank) return days(min, mid-1, m, f, r);
		if (oak > bank) return days(mid+1, max, m, f, r);
		return mid;
	}
	return min;
}

int main() {
	double m, r, f;
	while (cin >> m >> f >> r) {
		r = r/100 +1;
		cout << days(1, 10000000, m, f, r) << endl;
	}
}
