#include<iostream>
#include<vector>
#include <limits>
using namespace std;

struct Country {
	int minIncome;
	bool isVishie;
	bool isAsseptCitizen;
};
struct Student {
	int Income;
	bool isVishie;
	int AsseptCountry;
};
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<Country> countryes(n);
	int minIncome = std::numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		cin >> countryes[i].minIncome;
		if (countryes[i].minIncome < minIncome) {
			minIncome = countryes[i].minIncome;
		}
	}
	for (int i = 0; i < n; i++) 
	{
		int temp;
		cin >> temp;
		if (temp == 1) {
			countryes[i].isVishie = true;
		}
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 1) {
			countryes[i].isAsseptCitizen = true;
		}
	}
		
	int Q;
	cin >> Q;
	vector<Student> students(Q);
	
	for (int i = 0; i < Q; i++) 
	{
		cin >> students[i].Income;
	}
	for (int i = 0; i < Q; i++) 
	{
		int temp;
		cin >> temp;
		if (temp == 1) {
			students[i].isVishie = true;
		}
	}
	for (int i = 0; i < Q; i++) 
	{
		cin >> students[i].AsseptCountry;
	}

	for (size_t i = 0; i < Q; i++)
	{
		if (students[i].Income < minIncome) {
			if (students[i].AsseptCountry == 0 || !countryes[students[i].AsseptCountry - 1].isAsseptCitizen) 
				cout << 0 << " ";
			else
				cout << students[i].AsseptCountry << " ";
			continue;
		}
				
		for (size_t j = 0; j < n; j++)
		{
			if (students[i].AsseptCountry-1 == j and countryes[j].isAsseptCitizen or
				students[i].Income >= countryes[j].minIncome and
				(countryes[j].isVishie == false or students[i].isVishie == true))
			{
				cout << j + 1 << " ";
				break;
			}
			else if (j == n - 1)
			{
				cout << 0 << " ";
			}
		}
		
	}
}