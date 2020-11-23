#pragma once
#include <string>
#include <iostream>
#include "Order.h"
class ShoppingCart {
public:
	string name;
private:
	class Node {
		friend class ShoppingCart;
		Order _order;
		Node* _next;
		Node(Order const& o, Node const* const& n = 0) :
			_order(o), _next(const_cast<Node* const>(n)) {}
	} *_head;
public:
	// add code here, begin with the constructor
};