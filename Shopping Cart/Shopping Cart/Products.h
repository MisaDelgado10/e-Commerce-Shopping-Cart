#pragma once
#include "product.h"
#include <fstream> //Lee datos de un .txt

//Esta clase almacenará referencias de instancias de productos en un arreglo de tamaño 20
class Products
{
private:
	static const int array_size = 20; //delimita un tamaño máximo del arreglo
	string filename;
	Product *products[array_size];
	fstream file;
	string oneWord;
	string name[array_size]; //almacenará sólo el nombre del producto a partir de un archivo de entrada
	string price[array_size];//almacenará sólo el precio del producto a partir de un archivo de entrada
	int aux; //Servirá para hacer recorrido general del archivo .dat que recibe el constructor
	int index_name; //servirá para recorrer el arreglo name
	int index_price;//servirá para recorrer el arreglo precio

public:
	Products(string filename); //Constructor que recibe por parámetro un archivo .dat que trae nombres y precios de los productos
	~Products(); //Destructor
	int products_size(); //Regresa el num de productos que hay en el arreglo

	Product* getProductsArray(); //me devuelve el arreglo de productos
	Product& operator[](int); //Sobrecarga el operador [] para acceder a cada producto del arreglo products

};

