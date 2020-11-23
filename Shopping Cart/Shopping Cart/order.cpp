#include "Order.h"

Order::Order(Product& product, int quantity) {
	this->product = &product;
	this->quantity = quantity;
	if (quantity == 0)
		this->quantity = 1;
}
void Order::operator +=(int const& amt) {
	this->quantity += amt;
}
float Order::cost() {
	return quantity * product->price;
}
bool operator== (const Order& order1, const Order& order2) { //Muestra el inicio y el final
	if (order1.product == order2.product)
		return true;
	else
		return false;
}
bool operator!= (const Order& order1, const Order& order2) { //Muestra el inicio y el final
	if (order1.product != order2.product)
		return true;
	else
		return false;
}
std::ostream& operator<< (std::ostream& output, Order& order) { //Muestra nombre y precio del producto
	
	cout << "Esta orden contiene:\n";
	output << *order.product;
	output << "Con un costo total de : " << order.cost()<< endl;
	return output;
}

