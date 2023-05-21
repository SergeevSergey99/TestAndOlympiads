#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct ROW;
struct Passenger {
	int a;
	int Row;
	int Seat;
	ROW* currentRow = nullptr;
	bool SETTET = false;
};
struct ROW {
	int number;
	int leftT = -1;
	int rightT = -1;
	Passenger* A = nullptr;
	Passenger* B = nullptr;
	Passenger* C = nullptr;
	Passenger* WAY = nullptr;
	Passenger* D = nullptr;
	Passenger* E = nullptr;
	Passenger* F = nullptr;

	void SetPassenger(Passenger* p, int seat) {
		if (p->currentRow != nullptr) 
			p->currentRow->WAY = nullptr;
		switch (seat) {
		case 0:
			A = p;
			leftT = -1;
			p->SETTET = true;
			break;
		case 1:
			B = p;
			leftT = -1;
			p->SETTET = true;
			break;
		case 2:
			C = p;
			leftT = -1;
			p->SETTET = true;
			break;
		case 3:
			D = p;
			rightT = -1;
			p->SETTET = true;
			break;
		case 4:
			E = p;
			rightT = -1;
			p->SETTET = true;
			break;
		case 5:
			F = p;
			rightT = -1;
			p->SETTET = true;
			break;
		default:
			WAY = p;
			break;
		}
		p->currentRow = this;
	}
	void TryMoveToLeft(Passenger* p, int seat) {
		if (leftT > 0)
			leftT--;
		else if (leftT == 0) {
			SetPassenger(p, seat);
		}
		else if (leftT < 0) 
		{
			if (seat == 0)
			{
				if (B != nullptr and C != nullptr)
					leftT = 14;
				else if (B != nullptr or C!= nullptr)
					leftT = 4;
				else
					SetPassenger(p, seat);
			}
			else if (seat == 1)
			{
				if (C != nullptr)
					leftT = 4;
				else
					SetPassenger(p, seat);
			}
			else
				SetPassenger(p, seat);
		}
	}
	void TryMoveToRight(Passenger* p, int seat) {
		if (rightT > 0)
			rightT--;
		else if (rightT == 0) {
			SetPassenger(p, seat);
		}
		else if (rightT < 0)
		{
			if (seat == 5)
			{
				if (D != nullptr and E != nullptr)
					rightT = 14;
				else if (D != nullptr or E!= nullptr)
					rightT = 4;
				else
					SetPassenger(p, seat);
			}
			else if (seat == 4)
			{
				if (D != nullptr)
					rightT = 4;
				else
					SetPassenger(p, seat);
			}
			else
				SetPassenger(p, seat);
		}
	}
	void TryMoveToSeat(Passenger* p, int seat) {
		if (p->SETTET) return;
		if (seat < 3)
			TryMoveToLeft(p, seat);
		else
			TryMoveToRight(p, seat); 
	}
	
};

bool Checl(vector<ROW>& vec, int count) {
	if (count > 0) return false;
	
	bool check = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i].WAY != nullptr) {
			check = false;
			break;
		}

	}

	return check;
}

int main() {
	int n;
	cin >> n;

	vector<Passenger> passengers(n);
	for (int i = 0; i < n; i++) {

		string RowSeat;
		cin >> passengers[i].a >> RowSeat;
		passengers[i].Seat = RowSeat[RowSeat.size() - 1] - 'A';
		passengers[i].Row = stoi(RowSeat.substr(0, RowSeat.size() - 1));
	}
	
	int t = 0;
	vector<ROW> rows(30);

	for (int i = 0; i < rows.size(); i++)
	{
		rows[i].number = i+1;
	}

	int countInPlane = 0;
	while (!Checl(rows, passengers.size() - countInPlane))
	{
		t++;
		for (int i = 0; i < passengers.size(); i++)
		{
			//if (passengers[i].currentRow != nullptr) cout << passengers[i].currentRow->number << " ";
			if (passengers[i].currentRow == nullptr)
			{
				if (rows[0].WAY == nullptr)
				{
					rows[0].SetPassenger(&passengers[i], -1);
					countInPlane++;
				}
				break;
			}
			else if (passengers[i].Row > passengers[i].currentRow->number 
				and rows[passengers[i].currentRow->number].WAY == nullptr)
			{
				rows[passengers[i].currentRow->number].SetPassenger(&passengers[i], -1);
			}
			else if (passengers[i].Row == passengers[i].currentRow->number) 
			{
				if (passengers[i].a > 0) 
				{
					passengers[i].a--;
				}
				else
				{
					rows[passengers[i].currentRow->number-1].TryMoveToSeat(&passengers[i], passengers[i].Seat);	
				}
			}
			
		}
		cout << endl;
	}
	
	cout << t-1;
}