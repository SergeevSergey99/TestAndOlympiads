#include <iostream>
#include <vector>

using namespace std;

struct otdel {
    unsigned long long effect = 0;
    unsigned long long  money = 0;
    vector<otdel *> podOtdels;

    void calcMoney(float m) {
        unsigned long long sumEffect = 0;
        for (unsigned long long i = 0; i < podOtdels.size(); i++)
        {
            sumEffect += podOtdels[i]->effect;
        }
        for (unsigned long long i = 0; i < podOtdels.size(); i++)
        {
            podOtdels[i]->money += podOtdels[i]->effect * 1.0 / sumEffect * m;
            podOtdels[i]->calcMoney(podOtdels[i]->money);
        }
    }
};


int main() {
    unsigned long long n, m;
    cin >> n >> m;

    vector<otdel> otdels(n);

    for (unsigned long long i = 0; i < otdels.size(); i++)
    {
        cin >> otdels[i].effect;
    }

    otdel company;

    for (unsigned long long i = 0; i < otdels.size(); i++)
    {
        unsigned long long index;
        cin >> index;
        if (index == 0) {
            company.podOtdels.push_back(&otdels[i]);
        }
        else
        {
            otdels[index - 1].podOtdels.push_back(&otdels[i]);
        }
    }

    company.calcMoney(m);


    for (unsigned long long i = 0; i < otdels.size(); i++)
    {
        cout <<  otdels[i].money;
        if (i < otdels.size() - 1)
            cout << " ";
    }
    return 0;
}
