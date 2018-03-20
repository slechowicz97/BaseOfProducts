#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>

using namespace std;

int ID, newID;
int deleteID, editID, Menu, searchID, searchingPrize;
string searchingName;
bool st = true;
fstream file;

struct Product
{
	int id;
	string name;
	float price;
};

list <Product> BaseOfProducts;

void AddProduct()
{
	Product new_product;
	new_product.id = ID;
	cin >> new_product.name;
	cin >> new_product.price;
	BaseOfProducts.push_back(new_product);
	ID++;
	cout << endl;
}

void DeleteProduct(int ID)
{
	for (list<Product>::iterator iterator_begin = BaseOfProducts.begin();
		iterator_begin != BaseOfProducts.end();
		iterator_begin++)
	{
		if ((iterator_begin->id) == ID)
		{
			BaseOfProducts.erase(iterator_begin);
			return;
		}
	}
	cout << "Product not find!" << endl;
}

void EditProduct(int ID)
{
	int feature = 0;
	for (list<Product>::iterator iterator_begin = BaseOfProducts.begin();
		iterator_begin != BaseOfProducts.end();
		iterator_begin++)
	{
		if ((iterator_begin->id) == ID)
		{
			cout << "What to edit? "
				<< "1. Name "
				<< "2. Price "
				<< "3. Name and price" << endl;
			cin >> feature;
			switch (feature)
			{
			case 1:
			{ cout << "Enter a new name: " << endl;
			cin >> (iterator_begin)->name; return;}
			case 2:
			{ cout << "Enter a new price: " << endl;
			cin >> (iterator_begin)->price; return;}
			case 3:
			{ cout << "Enter a new name: " << endl;
			cin >> (iterator_begin)->name;
			cout << "Enter a new price: " << endl;
			cin >> (iterator_begin)->price; return;}
			}
		}
	}
	cout << "Product not find!" << endl;
	return;
}

void DisplayTheDatabase()
{
	if (BaseOfProducts.empty()) { cout << "Base is empty! " << endl; return; }

	for (list<Product> ::iterator iterator_to_base = BaseOfProducts.begin(); iterator_to_base != BaseOfProducts.end();
		iterator_to_base++)
	{
		cout << "Product's ID: " << (iterator_to_base)->id << endl;
		cout << "Product's name: " << (iterator_to_base)->name << endl;
		cout << "Product's price: " << (iterator_to_base)->price << endl;
		cout << endl;
	}
}


void SearchingProduct()
{
	int SearchBy;
	cout << "Search by: " << endl
		<< "1. ID " << endl
		<< "2. Name " << endl
		<< "3. Price " << endl;
	cin >> SearchBy;

	switch (SearchBy)
	{
	case 1: {cout << "Enter the searching ID: " << endl;
		cin >> searchID;
		for (list<Product>::iterator iterator_search = BaseOfProducts.begin();
			iterator_search != BaseOfProducts.end();
			iterator_search++)
		{
			if ((iterator_search->id) == searchID)
			{
				cout << "Product's ID: " << (iterator_search)->id << endl;
				cout << "Product's name: " << (iterator_search)->name << endl;
				cout << "Product's price: " << (iterator_search)->price << endl;
				cout << endl;
				return;
			}
		}
		cout << "ID not find! " << endl; return; }

	case 2: {	cout << "Enter the searching name: " << endl;
		cin >> searchingName;
		for (list<Product>::iterator iterator_search = BaseOfProducts.begin();
			iterator_search != BaseOfProducts.end();
			iterator_search++)
		{
			if ((iterator_search->name) == searchingName)
			{
				cout << "Product's ID: " << (iterator_search)->id << endl;
				cout << "Product's name: " << (iterator_search)->name << endl;
				cout << "Product's price: " << (iterator_search)->price << endl;
				cout << endl;
			}
		}  return; }

	case 3: {	cout << "Enter the searching name: " << endl;
		cin >> searchingName;
		for (list<Product>::iterator iterator_search = BaseOfProducts.begin();
			iterator_search != BaseOfProducts.end();
			iterator_search++)
		{
			if ((iterator_search->price) == searchingPrize)
			{
				cout << "Product's ID: " << (iterator_search)->id << endl;
				cout << "Product's name: " << (iterator_search)->name << endl;
				cout << "Product's price: " << (iterator_search)->price << endl;
				cout << endl;
			}
		}  return; }
	}
	cout << "Product doesn't exist!" << endl;
}

void FileCleaning()
{
	file.open("Base.txt", ios::out | ios::trunc);
	file.clear();
	file.close();
}

void SaveTheBase()
{
	FileCleaning();

	file.open("Base.txt", ios::out | ios::app);
	if (file.good() == true)
	{

		for (list<Product> ::iterator iterator_to_base = BaseOfProducts.begin(); iterator_to_base != BaseOfProducts.end();
			iterator_to_base++)
		{
			file << (iterator_to_base)->id << endl;
			file << (iterator_to_base)->name << endl;
			file << (iterator_to_base)->price << endl;
			file << endl;
		}
		file.close();
	}
}


void LoadBase()
{
	file.open("Base.txt", ios::in);
	if (file.good() == true)
	{
		string line;
		int number_of_line = 1;

		Product new1;

		while (getline(file, line))
		{
			if (number_of_line % 4 == 1)
			{
				new1.id = atoi(line.c_str());
				ID = atoi(line.c_str()) + 1;
				number_of_line++;

			}
			else if (number_of_line % 4 == 2)
			{
				new1.name = line;
				number_of_line++;
			}
			else if (number_of_line % 4 == 3)
			{
				new1.price = stof(line.c_str());
				number_of_line++;
				BaseOfProducts.push_back(new1);
			}
			else
			{
				number_of_line++;
			}
		}

		file.close();
	}
	else
	{
		cout << "File doesn't exist!" << endl;
	}
}

int main()
{
	while (st)
	{
		cout << "What do you want? " << endl
			<< "1. Display the base " << endl
			<< "2. Add product " << endl
			<< "3. Delete product " << endl
			<< "4. Edit product " << endl
			<< "5. Search product " << endl
			<< "6. Save the base " << endl
			<< "7. Load the base " << endl
			<< "8. Exit " << endl;

		cin >> Menu;

		switch (Menu)
		{
		case 1: {DisplayTheDatabase(); break; }
		case 2: {
			cout << "Enter the name and price of product: " << endl;
			AddProduct(); break;}
		case 3: {
			cout << "Which product (ID) you want to delete: " << endl;
			cin >> deleteID;
			DeleteProduct(deleteID); break;}
		case 4: {
			cout << "Which product (ID) you want to edit?: " << endl;
			cin >> editID;
			EditProduct(editID); break;}
		case 5: {SearchingProduct(); break; }
		case 6: {SaveTheBase(); break; }
		case 7: {LoadBase(); break; }
		case 8: {st = false; return 0; }
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
