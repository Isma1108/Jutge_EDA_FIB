#include <iostream>
#include <vector>
using namespace std;

bool binary_resistant(double x, const vector<double>& v, int e, int d) {
    if (e > d) return false;
    int m = (e+d)/2;
    if (v[m] == x) return true;
    if ((m > 0 and v[m-1] == x) or (m < v.size()-1 and v[m+1] == x)) return true;
    if (v[m] < x) return binary_resistant(x, v, m+1, d);
    return binary_resistant(x, v, e, m-1);
}

bool resistant_search(double x, const vector<double>& v) {  
    return binary_resistant(x, v, 0, v.size()-1);
}
