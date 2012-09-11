#include <iostream>

using namespace std;
void sellProduct(dispenserType& product, cashRegister& pCounter);
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
	cashRegister counter;
	dispenserType appleJuice(100, 50);
	dispenserType orangeJuice(100, 65);
	dispenserType mangoLassi(75, 45);
	dispenserType fruitPunch(100, 85);

	int choice;
	showSelection();

	cin >> choice;

	while(choice !=9)
	{
		switch (choice)
		{
		case 1:
			sellProduct(appleJuice, counter);
			break;
		case 2:
			sellProduct(orangeJuice, counter);
			break;
		case 3:
			sellProduct(mangoLassi, counter);
			break;
		case 4:
			sellProduct(fruitPunch, counter);
			break;
		default:
			cout <<"Invalid selection. " << endl;
			break;
		}//end switch
		showSelection();
		cin >> choice;

	}

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
void sellProduct(dispenserType& product, cashRegister& pCounter)
{
	int amount;
	int amount2;

	if(product.getNoOfItems() > 0)
	{
		cout <<"Please deposit " << product.getCost() << "cents " << endl;
		cin >> amount;
	
	
	if(amount < product.getCost())
	{
		cout << "Please deposit another " << product.getCost() - amount << "cents" << endl;
		cin >> amount2;
	}

	if (amount = product.getCost())
	{
		pCounter.acceptAmount(amount);
		product.makeSale();
		cout << "Collect your item at the bottom and enjoy " << endl;
	} else {
		cout << "The amount is no enough. " << "collect what you deposited" << endl;
	}
	}
	else
	{
		cout << "Sorry, this item is sold out" << endl;

	}
}