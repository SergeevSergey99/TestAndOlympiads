#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
    
    int k;
    std::cin >> k;

    std::string str,str2 = "&";
    std::cin >> str;
    for (size_t i = 0; i < str.size(); i++)
    {
        std::string s(1, str[i]);
        str2 += s + "&";
    }

    int arr[100000] = {};

    for (int i = 0; i < str2.size(); i++)
    {
        int j = 0;
        while (i - j >= 0 and i + j < str2.size() and str2[i + j] == str2[i - j])
            j++;
        arr[i] = j;
    }

    for (size_t i = str.size() / k; i > 0; i--)
    {
        int count = 0;
        for (size_t j = 0; j < str2.size(); j++)
        {
            if (arr[j] >= i)
            {       
                count++;
                j += arr[j];
            }
            if (count == k)
            {       
                std::cout << i;
                return 0;
                
            }

        }
    }

    std::cout << 0;
    return 0;
}