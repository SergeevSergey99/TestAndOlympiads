#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_map<int, vector<int>> categoryes;

	for (int i = 0; i < n; i++)
	{
		int p, c;
		cin >> p >> c;
		categoryes[c].insert(categoryes[c].begin(), p);
	}
	bool isWork = true;

	vector<pair<int, vector<int>>> v;

	for (auto c : categoryes)
	{
		v.push_back({ c.first, c.second });
	}
	sort(v.begin(), v.end(), [](pair<int, vector<int>> a, pair<int, vector<int>> b) {
		return a.first < b.first;
		});

	while (isWork)
	{
		isWork = false;
		for (auto c : v)
		{
			if (categoryes[c.first].size() == 0) continue;
			
			cout << categoryes[c.first].back() << " ";

			categoryes[c.first].pop_back();
			if (categoryes[c.first].size() > 0)
				isWork = true;
		}

	}
}