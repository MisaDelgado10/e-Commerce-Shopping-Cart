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
	
	Products* products;

public:
	static string const& BUYS;
	static string const& RETURNS;
	static string const& SHOWCART;
	static string const& CHECKOUT;
	class Node {
		friend class Store;
		ShoppingCart  shoppingCart;
		Node* _next;
		Node(ShoppingCart const& o, Node const* const& n = 0) : shoppingCart(o), _next(const_cast<Node* const>(n)) {
		}
	} *_head;

	
	
	Store(string name) {
		//Creo mi objecto de Products y con el name que recibo del constructor, obtengo los productos que voy a usar
		products = new Products(name);
		_head = NULL;	// Inicializamos la lista vacía
	}

	~Store() {}

	bool is_open() {
		//Devuelve un true, si hay productos suficientes en la tienda, es decir, que haya 
		//más de un producto dentro del arreglo 
		if (products->products_size() == 0)
			return false;
		return true;
	}

	void processshoppingCart(string const& customer_name, string const& command) {
		if (command == SHOWCART) { //Imprime en pantalla el carrito de compra del usuario (costumer_name) con sus respectivas ordenes
			Node* aux = _head;
			while (aux != NULL && aux->shoppingCart.name != customer_name)
				aux = aux->_next;

			if (aux != NULL)
				cout << aux->shoppingCart;
			else
				cout << "El usuario " << customer_name << " no tiene ninguna orden en su carro\n";
		}
		else if (command == CHECKOUT) { //Muestra las ordenes del usuario (costumer_name) y elimina su carrito de la tienda
			Node* aux, * antes;
			aux = _head;
			antes = aux;
			while (aux != NULL && aux->shoppingCart.name != customer_name) {
				antes = aux;
				aux = aux->_next;
			}

			if (aux != NULL) {
				cout << aux->shoppingCart;
				cout << "Gracias por su compra " << aux->shoppingCart.name << endl;
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
				cout << "El usuario " << customer_name << " no tiene ninguna orden en su carro\n";
		}
		else
			cerr << "ilegal command\n";
	}

	void processshoppingCart(string const& customer_name, string const& command, int const& quantity, string const& product_name) {
		if (command == BUYS) {
			Node* aux;
			Products& catalogo = *products;
			aux = _head;
			while (aux != NULL && aux->shoppingCart.name != customer_name)
				aux = aux->_next;

			// Si no existe el carrito con el nombre de usuario creamos uno
			if (aux == NULL) {
				ShoppingCart nCart(customer_name);
				int total = products->products_size();
				int i = 0;

				while (i < total && product_name != catalogo[i].name) {
					i++;
				}

				if (i >= total)
					cout << "Orden no encontrada\n";
				else {
					if (quantity > 0) {
						order tempOrder(catalogo[i], quantity);
						if (nCart.add_to_cart(tempOrder)) {
							cout <<nCart.getName()<< ", has agregado " << quantity << " elementos de " << product_name << " exitosamente.\n";
							Node* nuevo = new Node(nCart, _head);
							_head = nuevo;

						}
						else
							cout << "La transacción no puede realizarse.\n";
					}
					else
						cout << "Debes ingresar cantidades mayor a 0\n";
				}
			}
			else {
				// Si el carro existe...
				int total = products->products_size();
				int i = 0;
				while (i < total && product_name != catalogo[i].name) {
					i++;
				}

				if (i >= total)
					cout << "Orden no encontrada\n";
				else {
					if (quantity > 0) {
						order tempOrder(catalogo[i], quantity);
						if (aux->shoppingCart.add_to_cart(tempOrder))
							cout << aux->shoppingCart.getName()<< ", has agregado " << quantity << " elementos de " << product_name << " exitosamente.\n";
						else
							cout << "La transacción no puede realizarse.\n";
					}
					else
						cout << "Debes ingresar cantidades mayor a 0\n";
				}
			}
		}
		else if (command == RETURNS) {
			Node* aux;
			Products& catalogo = *products;
			aux = _head;
			while (aux != NULL && aux->shoppingCart.name != customer_name)
				aux = aux->_next;

			if (aux == NULL) {
				ShoppingCart nCart(customer_name);
				int total = products->products_size();
				int i = 0;

				while (i < total && product_name != catalogo[i].name) {
					i++;
				}

				if (i >= total)
					cout << "Orden no encontrada\n";
				else {
					if (quantity > 0) {
						order tempOrder(catalogo[i], -quantity);
						if (nCart.add_to_cart(tempOrder))
							cout <<nCart.getName()<< ", has devuelto " << quantity << " elementos de " << product_name << " exitosamente.\n";
						else
							cout << "La transacción no puede realizarse.\n";
					}
					else
						cout << "Debes ingresar cantidades mayor a 0\n";
				}
			}
			else {
				// Si el carro existe...
				int total = products->products_size();
				int i = 0;
				while (i < total && product_name != catalogo[i].name) {
					i++;
				}

				if (i >= total)
					cout << "Orden no encontrada\n";
				else {
					if (quantity > 0) {
						order tempOrder(catalogo[i], -quantity);
						if (aux->shoppingCart.add_to_cart(tempOrder))
							cout << aux->shoppingCart.getName() << ", has devuelto " << quantity << " elementos de " << product_name << " exitosamente.\n";
						else
							cout << "La transacción no puede realizarse.\n";
					}
					else
						cout << "Debes ingresar cantidades mayor a 0\n";
				}
			}
		}
		else
			cout << "ilegal command\n";
	}

	void close(ostream& out) {
		cout << "La tienda esta cerrando...Estos son los carros pendientes:\n";
		while (_head != NULL)
			processshoppingCart(_head->shoppingCart.name, "checkout");

		out << "\n\n¡Gracias por su compra!\n";
	}

};
//Constantes que ayudarán al proceso de transacciones
string const& Store::BUYS = "buys";
string const& Store::RETURNS = "returns";
string const& Store::SHOWCART = "showcart"; 
string const& Store::CHECKOUT = "checkout";