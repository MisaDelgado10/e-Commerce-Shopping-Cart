#include "product.h"
#include <iostream>

using namespace std;

Product::Product(string name, price_t price) {
	if (price > 0) {
		this->name = name;
		this->price = price;
	}
	else {
		this->name = name;
		this->price = 0;
		cout << "Ingresa un monto correcto a price\n";
	}
}
bool operator== (const Product& product1, const Product& product2) { //Muestra el inicio y el final

	if (product1.name == product2.name && product1.price == product2.price) {
		return true;
	}
	else {
		return false;

	}
}
bool operator== (const Product& product1, const string& product_name) { //Muestra el inicio y el final

	if (product1.name == product_name) {
		return true;
	}
	else {
		return false;

	}
}
bool operator!= (const Product& product1, const Product& product2){ //Muestra el inicio y el final

	if (product1.name != product2.name) {
		return true;//Diferentes
	}
	else if(product1.name == product2.name && product1.price == product2.price){
		return false; //Son iguales

	}
}
bool operator!= (const Product& product1, const string& product_name) { //Muestra el inicio y el final

	if (product1.name != product_name) 
		return true;//Diferentes
	else
		return false;
}
std::ostream& operator<< (std::ostream& output, Product& product) { //Muestra nombre y precio del producto

	output << "\nName: " << product.name << endl;
	output << "Price: " << product.price << endl;
	return output;
}