#include <iostream>
#include <vector>
using namespace std;

bool bin_search(const vector<int>& v, int x, int e, int d, bool order) {
    if (e > d) return false;
    int mid = (e + d) / 2;
    if (x < v[mid]) {
        if (order) return bin_search(v, x, e, mid - 1, true);
        return bin_search(v, x, mid + 1, d, false); 
    }
    if (x > v[mid]) {
        if (order) return bin_search(v, x, mid + 1, d, true);
        return bin_search(v, x, e, mid - 1, false);
    }
    return true;
}

int busca_pic(const vector<int>& v, int e, int d) {
    if (e <= d - 2) {
        int mid = (e + d) / 2;
        if (v[mid - 1] < v[mid] and v[mid] < v[mid + 1]) return busca_pic(v, mid + 1, d);
        if (v[mid - 1] > v[mid] and v[mid] > v[mid + 1]) return busca_pic(v, e, mid - 1);
		    return mid;
	  }
	  if (v[d] >= v[e]) return d;
	  return e;
}

bool search(int x, const vector<int>& v) {
    int i = busca_pic(v, 0, v.size() - 1);
    return bin_search(v, x, 0, i, true) or bin_search(v, x, i, v.size() - 1, false);
}
