#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#define SIZE 1001

struct Conection {
    int index1;
    int index2;

    bool operator == (const Conection & rhs) const
    {
        return index1 == rhs.index1 and index2 == rhs.index2;
    }
};

std::vector<Conection> conections;
bool func(short k, short target)
{
    if (k == target)
        return true;
    for (size_t i = 0; i < conections.size(); i++)
    {
        if (conections[i].index1 == k)
        {               
            if (func(conections[i].index2, target))
                return true;
        }
    }

    return false;
}

int main() {
    short** arr = new short* [SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = new short[SIZE];
        for (size_t j = 0; j < SIZE; j++)
        {
            arr[i][j] = false;
        }
    }

    int n;
    std::cin >> n;



    for (size_t k = 1; k <= n; k++)
    {
        int x;
        int y;
        int r;

        std::cin >> x;
        std::cin >> y;
        std::cin >> r;

        for (size_t i = x - r; i <= x + r; i++)
        {
            for (size_t j = y - r; j <= y + r; j++)
            {
                if (j >= 0 and j < SIZE and i >= 0 and i < SIZE)
                {
                    if (arr[i][j] != 0) 
                    {
                        Conection c;
                        if (arr[i][j] > k)
                        {

                            c.index2 = arr[i][j];
                            c.index1 = k;
                        }
                        else
                        {
                            c.index1 = arr[i][j];
                            c.index2 = k;
                        }
                        if (std::find(conections.begin(), conections.end(), c) == conections.end()) {
                            conections.push_back(c);
                        }
                    }
                    arr[i][j] = k;

                    if (i > 0 and arr[i - 1][j] != 0 and arr[i - 1][j] != k)
                    {
                        Conection c;
                        if (arr[i - 1][j] > k)
                        {

                            c.index2 = arr[i - 1][j];
                            c.index1 = k;
                        }
                        else
                        {                        
                            c.index1 = arr[i - 1][j];
                            c.index2 = k; 
                        }
                        if (std::find(conections.begin(), conections.end(), c) == conections.end()) {
                            conections.push_back(c);
                        }

                    }
                    if (i < SIZE-1 and arr[i + 1][j] != 0 and arr[i + 1][j] != k)
                    {
                        Conection c;
                        if (arr[i + 1][j] > k)
                        {

                            c.index2 = arr[i + 1][j];
                            c.index1 = k;
                        }
                        else
                        {
                            c.index1 = arr[i + 1][j];
                            c.index2 = k;
                        };
                        if (std::find(conections.begin(), conections.end(), c) != conections.end()) {
                            /* v contains x */
                        }
                        else {
                            conections.push_back(c);
                        }

                    }
                    if (j > 0 and arr[i][j-1] != 0 and arr[i][j-1] != k)
                    {
                        Conection c;
                        if (arr[i][j - 1] > k)
                        {

                            c.index2 = arr[i][j - 1];
                            c.index1 = k;
                        }
                        else
                        {
                            c.index1 = arr[i][j - 1];
                            c.index2 = k;
                        }
                        if (std::find(conections.begin(), conections.end(), c) != conections.end()) {
                            /* v contains x */
                        }
                        else {
                            conections.push_back(c);
                        }

                    }
                    if (j < SIZE-1 and arr[i][j+1] != 0 and arr[i][j+1] != k)
                    {
                        Conection c; 
                        if (arr[i][j + 1] > k)
                        {

                            c.index2 = arr[i][j + 1];
                            c.index1 = k;
                        }
                        else
                        {
                            c.index1 = arr[i][j + 1];
                            c.index2 = k;
                        }
                        if (std::find(conections.begin(), conections.end(), c) != conections.end()) {
                            /* v contains x */
                        }
                        else {
                            conections.push_back(c);
                        }

                    }
                }
                
            }
        }
    }
    
    int startX, endX, startY, endY;

    std::cin >> startX >> startY;
    std::cin >> endX >> endY;

    if (arr[startX][startY]>0 and arr[endX][endY]>0)
    {
        if (func(arr[startX][startY], arr[endX][endY]))
        {
            std::cout << 1;
        }
        else
        {
            std::cout << 0;
        }
    }
    else 
    {
        std::cout << 0;
    }

    for (int i = 0; i < SIZE; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}