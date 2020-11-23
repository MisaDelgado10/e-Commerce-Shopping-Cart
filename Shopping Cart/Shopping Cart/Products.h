#pragma once
#include "product.h"
#include <fstream> //Lee datos de un .txt


class Products
{
private:
	static const int array_size = 20;
	string filename;
	Product *products[array_size];
	fstream file;
	string oneWord;
	string name[array_size];
	string price[array_size];
	int aux;
	int index_name;
	int index_price;

public:
	Products(string filename);
	void printProducts();
	static int products_size();

	Product& operator[](int);

};

