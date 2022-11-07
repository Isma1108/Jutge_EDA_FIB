#include <iostream>
#include <map>
using namespace std;

int main() {
	int x, y, n;
	while (cin >> x >> y >> n) {
		map<int,int> seq;
		map<int,int>::const_iterator map_it;

		int num_cicle = 0;
		bool cicle = false;
		seq.insert(make_pair(n, 0));

		while (not cicle and n <= 100000000) {
			++num_cicle;
			if (n%2 == 0) n = n/2 + x;
			else n = 3*n + y;

			map_it = seq.find(n);
			if (map_it == seq.end()) seq.insert(make_pair(n, num_cicle));
			else cicle = true;
		}
		if (cicle) cout << seq.size() - map_it->second << endl;
		else cout << n << endl;
	}
}
