#include <iostream>
using namespace std;

void mult_mat(int& m11, int& m12, int& m21, int& m22, int n, int m) {
	if (n > 1) {
		int  a11 = m11, a12 = m12, a21 = m21, a22 = m22;
		mult_mat(m11, m12, m21, m22, n/2, m);
		int n11 = (m11*m11 + m12*m21) % m;
		int n12 = (m11*m12 + m12*m22) % m;
		int n21 = (m21*m11 + m22*m21) % m;
		int n22 = (m21*m12 + m22*m22) % m;
		if (n%2 == 0) {m11 = n11; m12 = n12; m21 = n21; m22 = n22;}
		else {
			m11 = (n11*a11 + n12*a21) % m;
			m12 = (n11*a12 + n12*a22) % m;
			m21 = (n21*a11 + n22*a21) % m;
			m22 = (n21*a12 + n22*a22) % m;
		}
	}
	if (n == 0) {
		m11 = m22 = 1;
		m12 = m21 = 0;
	}
	if (n == 1) {
		m11 = m11%m;
		m12 = m12%m;
		m21 = m21%m;
		m22 = m22%m;
	}
}

int main() {
	int m11, m12, m21, m22;
	while (cin >> m11 >> m12 >> m21 >> m22) {
		int n, m;
		cin >> n >> m;
		mult_mat(m11, m12, m21, m22, n, m);
		cout << m11 << ' ' << m12 << endl << m21 << ' ' << m22 << endl;
		cout << "----------" << endl;
	}
}
