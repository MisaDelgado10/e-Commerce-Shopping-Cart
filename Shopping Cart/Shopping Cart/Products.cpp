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
	while (file >> oneWord && aux < array_size*2) {
		//cout<<"word: " << oneWord << endl;
		if (aux % 2 == 0) {
			name[index_name] = oneWord;
			index_name++;
		}
		else if(aux % 2 == 1){
			price[index_price] = oneWord;
			index_price++;
		}
		aux++;
	}

	for (int i = 0; i <index_name; i++) {
		Product* product = new Product(name[i], stof(price[i])); //Creo una instancia de Product
		products[i] = product;
		//cout << "productos del arreglo: "<<*products[i]<<endl;
	}
}
void Products::printProducts() {
	for (int i = 0; i < aux/2; i++) {
		cout << "Name: " <<name[i] << endl;
		cout << "Price: "<< price[i] << endl;
	}
}
int Products::products_size() {
	return aux / 2;
}

Product& Products::operator[](int index)
{
	if (index > products_size() || index <0) {
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	return *products[index];
}

