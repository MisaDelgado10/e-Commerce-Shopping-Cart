#pragma once

#include <string>
#include "ShoppingCart.h"
#include "Products.h"
#include "Product.h"
#include "order.h"
using namespace std;

class Store
{
private:
	
	Products* myProds;

public:
	static string const& BUYS;
	static string const& RETURNS;
	static string const& SHOWCART;
	static string const& CHECKOUT;
	class Node {
		friend class Store;
		ShoppingCart  _cart;
		Node* _next;
		Node(ShoppingCart const& o, Node const* const& n = 0) : _cart(o), _next(const_cast<Node* const>(n)) {
		}
	} *_head;

	
	
	Store(string name) {
		//Products prod(name);	// Inicializamos los productos que se venderan en la tienda.
		//myProds = &prod;
		myProds = new Products(name);
		_head = NULL;	// Inicializamos nuestra lista ligada (de shoppingCarts) en nulo.
	}

	~Store() {}

	bool is_open() {
		//if (_head == NULL)
			//return false;
		return true;
	}

	void process_cart(string const& customer_name, string const& command) {
		if (command == SHOWCART) {
			Node* aux = _head;
			while (aux != NULL && aux->_cart.name != customer_name)
				aux = aux->_next;

			if (aux != NULL)
				cout << aux->_cart;
			else
				cout << "Sorry, the car with the name *" << customer_name << "* was not found\n";
		}
		else if (command == CHECKOUT) {
			Node* aux, * antes;
			aux = _head;
			antes = aux;
			while (aux != NULL && aux->_cart.name != customer_name) {
				antes = aux;
				aux = aux->_next;
			}

			if (aux != NULL) {
				cout << aux->_cart;
				cout << "Thank you for your purchase " << aux->_cart.name << endl;
				if (aux == antes) {
					// Si el elemento esta al inicio de la lista
					_head = aux->_next;
					delete aux;
				}
				else {
					// Si el elemento esta en cualquier otro lugar de la lista
					antes->_next = aux->_next;
					delete aux;
				}
			}
			else
				cout << "Sorry, the car with the name *" << customer_name << "* was not found\n";
		}
		else
			cerr << "ilegal command\n";
	}

	void process_cart(string const& customer_name, string const& command, int const& quantity, string const& product_name) {
		if (command == BUYS) {
			Node* aux;
			Products& catalogo = *myProds;
			aux = _head;
			while (aux != NULL && aux->_cart.name != customer_name)
				aux = aux->_next;

			// Si no existe el carrito con el nombre de usuario creamos uno
			if (aux == NULL) {
				ShoppingCart nCart(customer_name);
				int total = myProds->products_size();
				int i = 0;

				while (i < total && product_name != catalogo[i].name) {
					i++;
				}

				if (i >= total)
					cout << "Article not found!\n";
				else {
					if (quantity > 0) {
						order tempOrder(catalogo[i], quantity);
						if (nCart.add_to_cart(tempOrder)) {
							cout << "You added " << quantity << " elements of " << product_name << " succesfully.\n";
							Node* nuevo = new Node(nCart, _head);
							_head = nuevo;

						}
						else
							cout << "The operation can not be completed.\n";
					}
					else
						cout << "Error!\nOnly positive amounts can be bought.\n";
				}
			}
			else {
				// Si el carro existe...
				int total = myProds->products_size();
				int i = 0;
				while (i < total && product_name != catalogo[i].name) {
					i++;
				}

				if (i >= total)
					cout << "Article not found!\n";
				else {
					if (quantity > 0) {
						order tempOrder(catalogo[i], quantity);
						if (aux->_cart.add_to_cart(tempOrder))
							cout << "You added " << quantity << " elements of " << product_name << " succesfully.\n";
						else
							cout << "The operation can not be completed.\n";
					}
					else
						cout << "Error!\nOnly positive amounts can be bought.\n";
				}
			}
		}
		else if (command == RETURNS) {
			Node* aux;
			Products& catalogo = *myProds;
			aux = _head;
			while (aux != NULL && aux->_cart.name != customer_name)
				aux = aux->_next;

			if (aux == NULL) {
				ShoppingCart nCart(customer_name);
				int total = myProds->products_size();
				int i = 0;

				while (i < total && product_name != catalogo[i].name) {
					i++;
				}

				if (i >= total)
					cout << "Article not found!\n";
				else {
					if (quantity > 0) {
						order tempOrder(catalogo[i], -quantity);
						if (nCart.add_to_cart(tempOrder))
							cout << "You return " << quantity << " elements of " << product_name << " succesfully.\n";
						else
							cout << "The operation can not be completed.\n";
					}
					else
						cout << "Error!\nOnly positive amounts can be bought.\n";
				}
			}
			else {
				// Si el carro existe...
				int total = myProds->products_size();
				int i = 0;
				while (i < total && product_name != catalogo[i].name) {
					i++;
				}

				if (i >= total)
					cout << "Article not found!\n";
				else {
					if (quantity > 0) {
						order tempOrder(catalogo[i], -quantity);
						if (aux->_cart.add_to_cart(tempOrder))
							cout << "You return " << quantity << " elements of " << product_name << " succesfully.\n";
						else
							cout << "The operation can not be completed.\n";
					}
					else
						cout << "Error!\nOnly positive amounts can be bought.\n";
				}
			}
		}
		else
			cerr << "ilegal command\n";
	}

	void close(ostream& out) {
		out << "==================================================\n";
		out << "\t\tPending carts\n";
		while (_head != NULL)
			process_cart(_head->_cart.name, "checkout");

		out << "\n\n==================================================\n";
		out << "\t\tThank you\n";
	}

};

string const& Store::BUYS = "buys";
string const& Store::RETURNS = "returns";
string const& Store::SHOWCART = "showcart"; 
string const& Store::CHECKOUT = "checkout";