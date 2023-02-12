#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;

int main() {
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> c(n);
	for (size_t i = 0; i < n; i++)	cin >> c[i];
	
	unordered_map<int, int> m;
	int tmp;
	for (size_t i = 0; i < n; i++) 
	{
		cin >> tmp;
		m.insert({ c[i], tmp });
	}	
		
	int k;
	cin >> k;
	vector<int> s(k);
	for (size_t i = 0; i < k; i++)	cin >> s[i];
	
	int sum = 0;
	for (size_t i = 1; i < k; i++)
	{
		if (m[s[i]] != m[s[i - 1]]) sum += 1;
	}
	cout << sum;
}