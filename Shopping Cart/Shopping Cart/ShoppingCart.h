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
	bool add_to_cart(order const& o) {
		Node* new_node = new Node(o);
		new_node->_next = _head;
		_head = new_node;
		return true;

	}
	friend ostream& operator<< (ostream& salida, ShoppingCart p);

	string getName() {
		return name;
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
		int i = 1;
		cout << "La lista de " << name<<endl;
		while (n!= NULL) {
			cout << "Orden " << i++ << " " << endl;
			cout << n->_order;
			n = n->_next;
		}
	}
};
/*ostream& operator<< (ostream& salida, ShoppingCart p) {
	if (p.getHead() != NULL) {
		p.despNodes(p.getHead());
		salida << "\n";
	}
	else
	{
		salida << "Lista vacía\n";
	}
	return salida;
}*/