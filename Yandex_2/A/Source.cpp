#include <iostream>
using namespace std;

bool checkHappy(int n) 
{
    int n1 = 0;
    int n2 = 0;

    n1 += n % 10;
    n /= 10;
    n1 += n % 10;
    n /= 10;
    n1 += n % 10;
    n /= 10;

    n2 += n % 10;
    n /= 10;
    n2 += n % 10;
    n /= 10;
    n2 += n % 10;

    return n1 == n2;
}

int main() {
    
    int number;
    std::cin >> number;

    for (size_t i = number + 1; i < 1000000; i++)
    {
        if (checkHappy(i))
        {
            cout << i;
            break;
        }
    }


    return 0;
}