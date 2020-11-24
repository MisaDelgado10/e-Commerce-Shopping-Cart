#include "order.h"

order::order(Product& product, int quantity) {
	this->product = &product;
	this->quantity = quantity;
	if (quantity == 0) //no puedes meter productos con cantidad 0, en ese caso lo toma como 1
		this->quantity = 1;
}
void order::operator +=(int const& amt) {
	//Aumenta o disminuye la cantidad de productos segun el signo ( + o -) de amt
	this->quantity += amt;
}
price_t order::cost() {
	//Regresa el costo total de la orden (costo del producto * cantidad del producto)
	return quantity * product->price;
}
bool operator== (const order& order1, const order& order2) {
	//compara si dos productos de una orden son iguales, esta comparacion es por referencia de instancia de Product
	//Returna true si son iguales, false si no
	if (order1.product == order2.product)
		return true;
	else
		return false;
}
bool operator!= (const order& order1, const order& order2) { //Muestra el inicio y el final
	//compara si dos productos de una orden son diferentes, esta comparacion es por referencia de instancia de Product
	//Returna true si son diferentes, false si son iguales
	if (order1.product != order2.product)
		return true;
	else
		return false;
}
std::ostream& operator<< (std::ostream& output, order& order) { //Muestra nombre y precio del producto
	//Imprime en pantalla lo que contiene la orden, osea, el producto, que a su vez este imprime su nombre y precio
	//Y además imprime el costo total de la orden (cantidad del producto * precio del producto)
	cout << "Esta orden contiene...\n";
	output << *order.product;
	output << "Con un costo total de : " << order.cost()<< endl;
	return output;
}

