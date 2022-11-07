#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string,int> casino;
	map<string,int>::iterator map_it;
	string name, op;
	while (cin >> name >> op) {
		map_it = casino.find(name);
		if (op == "enters") {
			if (map_it == casino.end()) casino.insert(make_pair(name, 0));
			else cout << name << " is already in the casino" << endl;
		}
		else if (op == "wins") {
			int num; cin >> num;
			if (map_it == casino.end()) cout << name << " is not in the casino" << endl;
			else casino[name] += num;
		}
		else {
			if (map_it == casino.end()) cout << name << " is not in the casino" << endl;
			else {
				cout << name << " has won " << map_it->second << endl;
				casino.erase(map_it);
			}
		}
	}
	cout << "----------" << endl;
	map_it = casino.begin();
	while (map_it != casino.end()) {
		cout << map_it->first << " is winning " << map_it->second << endl;
		++map_it;
	}
}
