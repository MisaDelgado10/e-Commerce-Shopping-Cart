#pragma once
#include "product.h"

struct order
{
	Product* product; 
	int quantity; //Se refiera a la cantidad de Product que querremos

	order(Product& product, int quantity); //Constructor que recibe un Product y la cantidad de ese producto
	price_t cost(); //costo total de la orden 

	void operator += (int const& amt); //sobrecarga operador +=, manipula la cantidad de la orden (incrementa o decrementa)
	friend bool operator== (const order& order1, const order& order2);//Product vs Product
	friend bool operator!= (const order& order1, const order& order2);//Product vs Product
	friend ostream& operator<< (ostream& output, order& order); //muestra en pantalla  la orden
};

