#include <iostream>
#include <vector>
using namespace std;

int s, n;

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

void sumes_iguals(const vector<int>& nums, int idx, int sum, int rest, vector<int>& sol) {
	if (idx == n and sum == s) print_sol(sol);
	if (idx < n) {
		if (rest - nums[idx] + sum >= s) sumes_iguals(nums, idx+1, sum, rest - nums[idx], sol);
		if (sum + nums[idx] <= s and rest + sum >= s) {
			sol.push_back(nums[idx]);
			sumes_iguals(nums, idx+1, sum + nums[idx], rest - nums[idx], sol);
			sol.pop_back();
		}
	}
}

int main() {
	cin >> s >> n;
	int rest = 0;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {cin >> nums[i]; rest += nums[i];}
	vector<int> sol(0);
	sumes_iguals(nums, 0, 0, rest, sol);
}
