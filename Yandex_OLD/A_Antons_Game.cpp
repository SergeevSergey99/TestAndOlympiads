#include <iostream>
#include <vector>
#include <algorithm>


class Monster
{
public:
    int index;
    int level;
    bool operator < (const Monster& rhs) const { return level < rhs.level; }
};
int main() {

    int n;
    std::cin >> n;

    std::vector<Monster> monsters;

    for (int i = 1; i <= n; i++)
    {
        Monster tmp;
        int levl;
        std::cin >> levl;
        tmp.index = i;
        tmp.level = levl;
        monsters.push_back(tmp);
    }

    int lifes = 3;
    int level = 1;
    std::sort(monsters.begin(), monsters.end());

    for (size_t i = 0; i < n; i++)
    {
        

        if(level >= monsters[i].level)
        {
            if (level < monsters[i].level * 2)
            {
                lifes--;
                
            }
            level++;
            if (lifes < 1)
            {
                level--;
                lifes = 3;
            }
        }
        else
        {
            std::cout << "Impossible";
            return 0;
        }
    }

    std::cout << "Possible" << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        std::cout << monsters[i].index << " ";
    }
    return 0;
}