#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <regex>

using namespace std;


int main() {
    wstring students_1;
    wstring students_2;
    getline(wcin, students_1);
    getline(wcin, students_2);

    wstring students1 = students_1.substr(0, students_1.length() - 1);
    students1 = regex_replace(students1, wregex(L",( )*"), L",");
    wstring students2 = students_2.substr(0, students_2.length() - 1);
    students2 = regex_replace(students2, wregex(L",( )*"), L",");

    wstringstream ss1(students1);

    multimap<wstring, wstring> studensMap;

    wstring student;
    int cnt = 0;
    while (getline(ss1, student, L','))
    {
        cnt++;
        student = regex_replace(student, wregex(L"( ){2,}"), L" ");

        int i = student.find(L" ");
        wstring name = student.substr(0, i);
        wstring lastName = student.substr(i + 1);
        studensMap.insert(make_pair(name, lastName));
    }

    wstringstream ss2(students2);
    while (getline(ss2, student, L',')) {
        cnt--;
        student = regex_replace(student, wregex(L"( ){2,}"), L" ");


        int i = student.find(L" ");
        wstring name = student.substr(0, i);
        wstring lastName = student.substr(i + 1);
        auto index = studensMap.equal_range(name);
        auto index2 = studensMap.equal_range(lastName);

        bool first = false;
        bool second = false;
        for (auto it = index.first; it != index.second; it++)
        {
            if (!it->second.compare(lastName))
            {
                first = true;
                break;
            }
        }
        for (auto it = index2.first; it != index2.second; it++)
        {
            if (!it->second.compare(name))
            {
                second = true;
                break;
            }
        }
        if (!(first || second))
        {
            wcout << "NO";
            return 0;
        }
    }

    if (cnt == 0) {
        wcout << "YES";
    }
    else {
        wcout << "NO";
    }

    return 0;
}
