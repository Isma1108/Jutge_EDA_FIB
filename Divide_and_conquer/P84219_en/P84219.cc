#include <iostream>
#include <vector>
using namespace std;

int binary_search(double x, const vector<double>& v, int e, int d) {
	int mid = (e + d)/2;
	if (e > d) return -1;
	if (x < v[mid]) return binary_search(x, v, e, mid - 1);
	if (x > v[mid]) return binary_search(x, v, mid + 1, d);
  if (mid == e or v[mid-1] != x) return mid;
  return binary_search(x, v, e, mid-1);
}

int first_occurrence(double x, const vector<double>& v) {
  if (v.empty() or x < v[0] or v[v.size()-1] < x) return -1;
  else return binary_search(x, v, 0, v.size() - 1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        double x;
        cin >> x;
        cout << first_occurrence(x, V) << endl;
    }
}

