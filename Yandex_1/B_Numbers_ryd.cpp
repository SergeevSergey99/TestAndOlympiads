#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>


int main() {

    std::vector<int> values;


    std::string str;
    std::getline(std::cin, str);
    std::stringstream ss(str);

    std::string item;
    while (std::getline(ss, item, ' ')) {
        values.push_back(stoi(item));
    }

    bool value = false;
    int i = 0;
    for (; i < values.size() - 1; i++)
    {
        if (values[i] == values[i + 1] and values[i + 2] == values[i])
        {
            value = true;
            i++;
            break;
        }
    }
    int j = i;

    while (i > 0 and j < values.size()-1)
    {
        if (values[j + 1] == values[i - 1])
        {
            i--;
            j++;
        }
        else
        {
            break;
        }
        while (j < values.size() - 1 && values[j] == values[j + 1]) j++;
        while (i > 0 && values[i] == values[i - 1]) i--;
    }
    
    if(value)    std::cout << j - i + 1;
    else
    {
        std::cout << 0;
    }
    return 0;
}