#include <iostream>

using namespace std;

class cashRegister 
{

private:
	int cashOnHand;

public:
	int getCurrentBalance() const;
	void acceptAmount(int amountIn);
	cashRegister(); //default constructor 
	cashRegister(int cashIn);
};

int cashRegister::getCurrentBalance() const
{
	return cashOnHand;
}

void cashRegister::acceptAmount(int amountIn)
{
	cashOnHand += amountIn;
}

cashRegister::cashRegister()
{
	cashOnHand = 500;
}

cashRegister::cashRegister(int cashIn)
{
	if(cashIn >= 0)
	{
		cashOnHand = cashIn;
	} 
	else
	{
		cashOnHand = 500;
	}
}

class dispenserType
{
public:
	int getNoOfItems() const;
	int getCost() const;
	void makeSale();
	dispenserType();
	dispenserType(int setNoOfItems, int setCost);

private:
	int numberOfItems;
	int cost;
};

int dispenserType:: getNoOfItems() const
{
	return numberOfItems;
}

int dispenserType::getCost() const
{
	return cost;
}

void dispenserType:: makeSale()
{
	numberOfItems--;
}
dispenserType:: dispenserType()
{
	numberOfItems = 50;
	cost = 50;
}

dispenserType::dispenserType(int setNoOfItems, int setCost)
{
	if(setNoOfItems >=0)
	{
		numberOfItems = setNoOfItems;
	}
	else
	{
		numberOfItems = 50;
	}

	if (setCost >= 0)
	{
		cost = setCost;
	}
	else
	{
		cost = 50;
	}
}

void showSelection();


int main()
{
	showSelection();


	system("pause");
	return 0;
}

void showSelection() 
{
	cout << "*** Welcome to Q's Fruit Juice Shop ***" << endl;
	cout <<"To select an item, enter " << endl;
	cout << "1 for apple juice" << endl;
	cout << "2 for orange juice" << endl;
	cout << "3 for mango lassi" << endl;
	cout << "4 for fruit punch" << endl;
	cout << "9 to exit" << endl;
}