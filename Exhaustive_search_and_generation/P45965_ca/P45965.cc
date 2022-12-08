#include <iostream>
#include <vector>	
using namespace std;

void escriu(const vector<int>& A) {
	cout << A[0];
	for (int i = 1; i < A.size(); ++i) cout << ' ' << A[i];
	cout << endl;
}

void cadenes(vector<int>& A, int i, int z_temp, int u_temp, int u) {
	if (i == A.size()) escriu(A);
	else {
		if (z_temp < A.size() - u) {
			A[i] = 0; 
			cadenes(A, i+1, z_temp+1, u_temp, u);
		}
		if (u_temp < u) {
			A[i] = 1; 
			cadenes(A, i+1, z_temp, u_temp+1, u);
		}
	}
}

int main() {
	int n, u;
	cin >> n >> u;
	vector<int> A(n);
	cadenes(A, 0, 0, 0, u);
}
