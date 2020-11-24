#include "product.h"
#include <iostream>

using namespace std;

Product::Product(string name, price_t price) {
	if (price > 0) { //para almacenar un producto correcto debe tener un precio mayor a 0
		this->name = name;
		this->price = price;
	}
	else {
		this->name = name;
		this->price = 0;
		cout << "Ingresa un monto correcto a price\n";
	}
}
bool operator== (const Product& product1, const Product& product2) { 
	//Compara si dos productos son iguales en nombre y precio
	//Entrada: 2 instancias de Product
	//salida: True -> si son iguales, False -> son diferentes
	if (product1.name == product2.name && product1.price == product2.price) {
		return true;
	}
	else {
		return false;

	}
}
bool operator== (const Product& product1, const string& product_name) { //Muestra el inicio y el final
	//Compara el nombre de un Producto contra un string
	//Entrada: product1 -> Objeto Producto, product_name -> nombre tipo string a comparar
	//salida: True -> si son  el nombre del producto es el mismo que el string product_name, False -> son diferentes
	if (product1.name == product_name) {
		return true;
	}
	else {
		return false;

	}
}
bool operator!= (const Product& product1, const Product& product2){ //Muestra el inicio y el final
	//Compara si dos productos son iguales en nombre y precio
	//Entrada: 2 instancias de Product
	//salida: True -> si son diferentes, False -> son iguales
	if (product1.name != product2.name) {
		return true;//Diferentes
	}
	else if(product1.name == product2.name && product1.price == product2.price){
		return false; //Son iguales

	}
}
bool operator!= (const Product& product1, const string& product_name) { //Muestra el inicio y el final
	//Compara el nombre de un Producto contra un string
	//Entrada: product1 -> Objeto Producto, product_name -> nombre tipo string a comparar
	//salida: True -> si son  el nombre del producto es diferente que el string product_name, False -> son iguales
	if (product1.name != product_name) 
		return true;//Diferentes
	else
		return false;
}
std::ostream& operator<< (std::ostream& output, Product& product) { //Muestra nombre y precio del producto
	//Muestra en pantalla los datos del producto nombre y precio
	output << "\nName: " << product.name << endl;
	output << "Price: " << product.price << endl;
	return output;
}
Product::~Product() {

}