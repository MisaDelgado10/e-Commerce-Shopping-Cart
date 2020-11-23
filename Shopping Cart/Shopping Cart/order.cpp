#include "order.h"

order::order(Product& product, int quantity) {
	this->product = &product;
	this->quantity = quantity;
	if (quantity == 0)
		this->quantity = 1;
}
void order::operator +=(int const& amt) {
	this->quantity += amt;
}
price_t order::cost() {
	return quantity * product->price;
}
bool operator== (const order& order1, const order& order2) { //Muestra el inicio y el final
	if (order1.product == order2.product)
		return true;
	else
		return false;
}
bool operator!= (const order& order1, const order& order2) { //Muestra el inicio y el final
	if (order1.product != order2.product)
		return true;
	else
		return false;
}
std::ostream& operator<< (std::ostream& output, order& order) { //Muestra nombre y precio del producto
	
	cout << "Esta orden contiene:\n";
	output << *order.product;
	output << "Con un costo total de : " << order.cost()<< endl;
	return output;
}

