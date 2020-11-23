#pragma once
#include <string>
#include <iostream>
#include "order.h"
class ShoppingCart {
public:
	string name;
private:
	class Node {
		friend class ShoppingCart;
		order _order;
		Node* _next;
		Node(order const& o, Node const* const& n = 0) :
			_order(o), _next(const_cast<Node* const>(n)) {}
	} *_head;
public:
	ShoppingCart(string name) {
		_head = NULL;
		this->name = name;
	}
	~ShoppingCart() {

	}

	bool add_to_cart(order const& o) {
		Node* nuevo = new Node(o, NULL);
		if (_head == NULL) {
			// Si la lista esta vacia, añadimos el nuevo pedido
			if (nuevo->_order.quantity > 0) {
				// Verificamos que sea un pedido mayor a cero.
				_head = nuevo;
				return true;
			}
			else return false;
		}
		else {
			Node* aux, * antes;
			aux = _head;
			antes = aux;
			while (aux != NULL && o.product != aux->_order.product) {
				// Recorremos la lista en busqueda de un pedido similar
				antes = aux;
				aux = aux->_next;
			}

			if (aux == NULL) {
				// Si el producto no se encuentra en la lista...
				if (nuevo->_order.quantity > 0) {
					// Verificamos que sea un pedido mayor a cero.
					antes->_next = nuevo;
					return true;
				}
				else return false;
			}
			else if (o.product == aux->_order.product) {
				// Si el producto se encuentra en la lista...
				int total = 0;
				total = o.quantity + aux->_order.quantity;		// Obtenemos la "actualizacion" del total del pedido
				if (total > 0) {
					// Si aun restan elementos del pedido lo actualizamos
					aux->_order.quantity = total;
					return true;
				}
				else if (total == 0) {
					// Si se eliminan todos los elementos del pedido, se elimina de la lista
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
					/*
						else if (aux->_next == NULL) {
						// Si el elemento esta al final de la lista
						antes->_next = NULL;
						delete aux;
					*/
					return true;
				}
				else if (total < 0) {
					// Si es menor a la cantidad actual en la lista, se regresa un falso y no se actualiza.
					return false;
				}
			}
		}
		return false;
	}
	//ostream& operator<< (ostream& salida, ShoppingCart const& p);

	string getName() {
		return name;
	}
	price_t cost() {
		price_t total = 0;
		Node* aux;
		aux = _head;
		while (aux != NULL) {
			total += aux->_order.cost();
			aux = aux->_next;
		}
		return total;
	}
	order getOrder(Node* node) {
		return node->_order;
	}
	Node* getNext(Node* node) {
		return node->_next;
	}
	Node* getHead() {
		return _head;
	}
	void despNodes(Node* n) {
		if (n != NULL) {
			cout << n->_order;
			n = n->_next;
			despNodes(n);
		}
	}
};
ostream& operator<< (ostream& salida, ShoppingCart const& p) {
	salida << "==================================================\n";
	salida << "\t\tCar: " << p.name << endl;
	ShoppingCart temp = p;
	temp.despNodes(temp.getHead());
	salida << endl;
	return salida;
}