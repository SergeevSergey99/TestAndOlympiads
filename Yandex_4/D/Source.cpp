#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main() {
	int n;
	cin >> n;
	unordered_map<int, int> umap;
	
	for (int i = 0; i < n; i++)
	{
		int KEY, VALUE;
		cin >> KEY >> VALUE;

		umap[KEY] = VALUE;
	}

	vector<int> order(n);
	for (int i = 0; i < order.size(); i++)
	{
		cin >> order[i];
	}

	unordered_set<int> uniqueValues;
	int left = 0;
	int right = 0;
	int minLength = 1;

	while (right < n) 
	{
		while (uniqueValues.count(umap[order[right]]) > 0) 
		{
			uniqueValues.erase(umap[order[left]]);
			left++;
		}

		uniqueValues.insert(umap[order[right]]);

		if (right - left + 1 > minLength) 
		{
			minLength = right - left + 1;
		}

		right++;
	}

	cout << minLength;
}