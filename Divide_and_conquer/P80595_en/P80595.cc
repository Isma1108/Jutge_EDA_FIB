#include <iostream>
#include <vector>
using namespace std;


int num_inversions(vector<int>& v, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		int num = num_inversions(v, l, m);
		num += num_inversions(v, m + 1, r);
		int i = l, j = m+1, k = 0;
		vector<int> aux(r - l + 1);
		while(i <= m and j <= r) {
			if(v[i] <= v[j]) aux[k++] = v[i++];
			else {
				aux[k++] = v[j++];
				num += m + 1 - i;
			}
		}
		while (i <= m) aux[k++] = v[i++];
		while (j <= r) aux[k++] = v[j++];
		for (k = 0; k <= r - l; ++k) v[l + k] = aux[k];
		return num;
	}
	return 0;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		cout << num_inversions(v, 0, n-1) << endl;
	}
}
