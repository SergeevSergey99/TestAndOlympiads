#include<iostream>
using namespace std;

int main() {
	int days;
	string weekDayStart;

	cin >> days >> weekDayStart;

	int start = 0;
	if (weekDayStart == "Tuesday")
		start = 1;
	else if (weekDayStart == "Wednesday")
		start = 2;
	else if (weekDayStart == "Thursday")
		start = 3;
	else if (weekDayStart == "Friday")
		start = 4;
	else if (weekDayStart == "Saturday")
		start = 5;
	else if (weekDayStart == "Sunday")
		start = 6;
	
	int count = 0;
	while (count < days) {
		for (int i = 0; i < 7 and count < days; i++)
		{
			if (count == 0 and i < start)
			{
				cout << ".. ";
				continue;
			}
			if (count < 9)
				cout << ".";
			cout << count + 1 << " ";
			count++;
		}
		cout << endl;
	}
}