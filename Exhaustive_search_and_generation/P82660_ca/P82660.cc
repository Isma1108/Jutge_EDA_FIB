#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s, n;
bool sol_found = false;

bool cmp(int a, int b) {return a > b;}

void print_sol(const vector<int>& sol) {
	bool first = true;
	cout << '{';
	for (int i : sol) {
		if (first) first = false;
		else cout << ',';
		cout << i;
	}
	cout << '}' << endl;
}

void sumes_iguals(const vector<int>& nums, int idx, int sum, vector<int>& sol) {
	if (not sol_found and idx == n and sum == s) {print_sol(sol); sol_found = true;}
	if (not sol_found and idx < n) {
		sol.push_back(nums[idx]);
		sumes_iguals(nums, idx+1, sum + nums[idx], sol);
		sol.pop_back();
		sumes_iguals(nums, idx+1, sum, sol);
	}
}


int main() {
	cin >> s >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) cin >> nums[i];
	sort(nums.begin(), nums.end(), cmp);
	
	vector<int> sol(0);
	sumes_iguals(nums, 0, 0, sol);
	if (not sol_found) cout << "no solution" << endl;
}



