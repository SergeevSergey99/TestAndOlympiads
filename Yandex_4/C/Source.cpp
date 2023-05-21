#include<iostream>
#include<vector>
#include<string>
#include <bitset>
#include <algorithm>
using namespace std;
struct ITEM {
	double cost;
	vector<int> cupons;
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<ITEM> items(n);
	for (int i = 0; i < items.size(); i++)
	{
		cin >> items[i].cost;
	}
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		for (int j = 0; j < c; j++)
		{
			int cupon; 
			cin >> cupon;
			items[i].cupons.push_back(cupon);
		}
	}
	
	vector<int> discounts(m);
	for (int i = 0; i < discounts.size(); i++)
	{
		cin >> discounts[i];
	}


    double max_discount = 0;
    int mask = 0;

    for (int i = 1; i < (1 << m); i++) {
        double curr_discount = 0;
        int curr_mask = i;

        if (bitset<20>(curr_mask).count() > k) 
            continue;
        for (int j = 0; j < n; j++) 
        {
            vector<int> applicable;
            double cost = items[j].cost;
            for (int coupon : items[j].cupons) 
            {
                if (curr_mask & (1 << (coupon - 1))) 
                {
                    applicable.push_back(coupon);
                }
            }
            for (int coupon : applicable)
            {
                double discount = discounts[coupon - 1] / 100.0 * cost;
                curr_discount += discount;
				cost -= discount;
            }
        }

        if (curr_discount > max_discount) 
        {
            max_discount = curr_discount;
            mask = curr_mask;
        }
    }

    cout << bitset<20>(mask).count() << endl;
    for (int i = 1; i <= m; i++) 
    {
        if (mask & (1 << (i - 1))) 
        {
            cout << i << " ";
        }
    }

    return 0;
	
}