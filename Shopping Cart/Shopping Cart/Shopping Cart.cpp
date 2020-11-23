// Shopping Cart.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "product.h"
#include "Products.h"
#include "order.h"
#include "ShoppingCart.h"

int main()
{
	//Product product1("Muffin",100);
	Products products("products.dat");
	//cout << product1.name << endl;
	//cout << product1.price << endl;

	//Product product2("Chocolate", -1); //Si asigno un num negativo a precio le pongo 0 y lanzo msj en pantalla
	//cout << product2.name << endl;
	//cout << product2.price << endl;

	/*
	//Operador ==
	if (product1 != "Muffin")
		cout << "Sí son diferentes\n";
	else
		cout << "Son iguales\n";
	//Operador !=
	if (product1 != "Muffin")
		cout << "Sí son diferentes\n";
	else
		cout << "Son iguales\n";

	cout << "Los datos del producto1 son: " << product1<<endl;
	*/
	
	//products.printProducts();
	//cout << "El primer producto es: " << products[0] << endl;
	//cout << "El tamaño del arreglo es: " << products.products_size()<<endl;

	//Pruebo que funcione la clase Order, la cual recibe por parámetro un producto y una cantidad
	Product product2("Pastel", 100.50);
	Product product3("Muffins", 70.50);

	order order1(products[0], 10);
	order order2(products[1], 10);
	order2 += 10;
	cout <<"Orden 1"<< order1 << endl;
	cout << "Orden 2" << order2 << endl;

	/*Uso operador == para ver si las ordenes son iguales porque tienen los mismos productos
	if (order1 == order2)
		cout << "Sí son iguales";
	else
		cout << "Son diferentes";
	//Uso operador != para ver si las ordenes son iguales porque tienen los mismos productos
	if (order1 != order2)
		cout << "Sí son diferentes";
		*/

	//Uso el método de cost()
	cout << "El costo de la orden 1 es: " << order1.cost()<<endl;


	ShoppingCart shoppingList("Misa");
	shoppingList.add_to_cart(order1);
	shoppingList.add_to_cart(order2);
	cout << shoppingList << endl;
}
