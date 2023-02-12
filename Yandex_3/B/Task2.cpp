#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

long long x;

struct Item {
	long long Weight;
	long long index;
};

bool operator < (const Item& a, const Item& b) {
	return abs(a.Weight - x) < abs(b.Weight - x);
}

int main() {
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	long long n, t;
	cin >> n >> x >> t;
	
	vector<Item> items(n);
	for (long long i = 0; i < n; i++) {
		cin >> items[i].Weight;
		items[i].index = i + 1;
	}

	sort(items.begin(), items.end());
	long long i = 0;
	while (t >= abs(x - items[i].Weight) && i < n) {
		t -= abs(x - items[i].Weight);
		i++;
	}
	
	cout << i << "\n";
	for (long long j = 0; j < i; j++) {
		cout << items[j].index << " ";
	}
}