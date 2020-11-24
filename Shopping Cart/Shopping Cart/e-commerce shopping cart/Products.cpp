#include "Products.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream> //Lee datos de un .txt
using namespace std;

Products::Products(string filename) {
	aux = 0;
	index_name = 0;
	index_price = 0;
	file.open(filename.c_str());
	while (file >> oneWord && aux < array_size*2) { //Permito que solo haga reccoridos hasta 20 productos, no más
		//oneWord almacena palabra por palabra del filename que recibe el constructor
		if (aux % 2 == 0) { //En cada iteración si mi aux es par, guarda entonces la primer palabra de cada linea
			name[index_name] = oneWord;
			index_name++;
		}
		else if(aux % 2 == 1){ //Si aux es impar esta agarrando solamente los precios
			price[index_price] = oneWord;
			index_price++;
		}
		aux++;
	}

	for (int i = 0; i <index_name; i++) {//Creo una instancia de Product con los nombres y precios obtenidos a partir del filename
		Product* product = new Product(name[i], stof(price[i])); 
		products[i] = product; //guardo las instancias de product en el arreglo products
	}
}

int Products::products_size() {
	//devuelve la cantidad de Product que hay en el arreglo
	return aux / 2;
}

Product& Products::operator[](int index)
{
	if (index > products_size() || index <0) { //No permite acceder a índices no permitidos del arreglo
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	return *products[index];
}
Products::~Products() {

}

