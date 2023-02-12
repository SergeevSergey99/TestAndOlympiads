#include<iostream>
#include<vector>
using namespace std;

struct Item {
	long long Price;
	long long index;
};
struct bestPath {
	double bestWin;
	vector<int> bestDays;
};

bestPath CalcWin(vector<Item>& pp,	vector<int> Days, int start = 0, int deals = 4)
{
	if (deals == 0)
		return bestPath{ 1, Days };
	double maxWin = 1;
	vector<int> bestDays = Days;
	
	for (size_t i = start; i < pp.size(); i++)
	{

		for (size_t j = i + 1; j < pp.size(); j++)
		{

			if (pp[i].Price < pp[j].Price)
			{
				Days.push_back(pp[i].index);
				Days.push_back(pp[j].index);
				
				auto winPath = CalcWin(pp, Days, j + 1, deals - 1);
				winPath.bestWin *= pp[j].Price * 1.0f / pp[i].Price;
				
				if (winPath.bestWin > maxWin)
				{
					maxWin = winPath.bestWin;
					bestDays = winPath.bestDays;
				}
				Days.pop_back();
				Days.pop_back();
			}

		}

	}
	return { maxWin, bestDays };
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<Item> p(n);

	for (int i = 0; i < n; i++) {
		cin >> p[i].Price;
		p[i].index = i + 1;
	}

	vector<Item> pp;
	pp.push_back(p[0]);
	auto last = p[0].Price;
	for (size_t i = 1; i < n-1; i++)
	{
		if (last < p[i].Price and p[i].Price > p[i + 1].Price
			or last > p[i].Price and p[i].Price < p[i + 1].Price)
		{
			pp.push_back(p[i]);
			last = p[i].Price;
		}
	}
	pp.push_back(p[n - 1]);
	
	vector<int> bestDays;
	auto winPath = CalcWin(pp, bestDays);
	//cout << winPath.bestWin << endl;
	if (winPath.bestDays.size() > 1)
	{
		cout << winPath.bestDays.size() / 2 << endl;
		for (size_t i = 0; i < winPath.bestDays.size(); i += 2)
			cout << winPath.bestDays[i] << " " << winPath.bestDays[i + 1] << '\n';
	}
	else
		cout << "0";
	
}