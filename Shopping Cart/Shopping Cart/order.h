#pragma once
#include "product.h"

struct order
{
	Product* product;
	int quantity;

	order(Product& product, int quantity);
	price_t cost();

	void operator += (int const& amt); //sobrecarga operador +=, manipula la cantidad de la orden
	friend bool operator== (const order& order1, const order& order2);//Product vs Product
	friend bool operator!= (const order& order1, const order& order2);//Product vs Product
	friend ostream& operator<< (ostream& output, order& order);
};

