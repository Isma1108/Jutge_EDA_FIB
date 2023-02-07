#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> c, d1, d2;

int diag1(int i, int j) {return i + j;}
int diag2(int i, int j) {return i - j + n - 1;}

int reines(int i) {
	if (n == i) return 1;
	int res = 0;
	for (int j = 0; j < n; ++j) {
		if (not c[j] and not d1[diag1(i,j)] and not d2[diag2(i,j)]) {
			c[j] = d1[diag1(i,j)] = d2[diag2(i,j)] = true;
			res += reines(i+1);
			c[j] = d1[diag1(i,j)] = d2[diag2(i,j)] = false;	
		}
	}
	return res;
}


int main() {
	cin >> n;
	c = vector<bool>(n, false);
	d1 = d2 = vector<bool>(2*n - 1, false); //Hi ha 2*n - 1 diagonals (pel marcatge)
	cout << reines(0) << endl;
}
