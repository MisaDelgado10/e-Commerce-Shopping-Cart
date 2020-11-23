#pragma once
#include "product.h"

struct Order
{
	Product* product;
	int quantity;

	Order(Product& product, int quantity);
	float cost();

	void operator += (int const& amt); //sobrecarga operador +=, manipula la cantidad de la orden
	friend bool operator== (const Order& order1, const Order& order2);//Product vs Product
	friend bool operator!= (const Order& order1, const Order& order2);//Product vs Product
	friend ostream& operator<< (ostream& output, Order& order);
};

