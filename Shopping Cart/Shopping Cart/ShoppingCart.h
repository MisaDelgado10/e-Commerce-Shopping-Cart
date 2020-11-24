#pragma once
#include <string>
#include <iostream>
#include "order.h"
//Esta clase es una lista ligada donde sus nodos almacenan ordenes
//ShoppingCart simula un carrito de compra
class ShoppingCart {
public:
	string name; //Almecena el nombre del dueño del carrito
private:
	class Node { //tiene la clase Node anidada que almacenará ordenes
		friend class ShoppingCart;
		order _order;
		Node* _next;
		Node(order const& o, Node const* const& n = 0) :
			_order(o), _next(const_cast<Node* const>(n)) {}
	} *_head;
public:
	ShoppingCart(string name) {
		//Le asigno el nombre del dueño a name e inicializo la lista vacía
		_head = NULL;
		this->name = name;
	}
	~ShoppingCart() {
		//Destructor
	}

	bool add_to_cart(order const& o) {
		//Entrada: Recibe como paramentro una orden la cual se manipulará dependiendo la acción requerida
		//Salidas: Retorna true si realiza ciertas operaciones con exito-> Agrega una orden al carrito,
		//elimina una orden con 0 productos, actualiza la cantidad de productos de 2 ordenes iguales
		//Retorna false si-> hay una orden con productos negativos, o si no se realizar ninguna de las operaciones de arriba
		Node* nuevo = new Node(o, NULL);
		if (_head == NULL) {
			// Si la lista esta vacia, añadimos el nuevo pedido
			if (nuevo->_order.quantity > 0) {
				// Verificamos que sea un pedido mayor a cero.
				_head = nuevo;
				return true; //Orden agregada al carrito exitosamente
			}
			else return false;
		}
		else {
			Node* aux, * antes;
			aux = _head;
			antes = aux;
			//Recorremos la lista mientras no tengamos productos similares
			while (aux != NULL && o.product != aux->_order.product) {
				antes = aux;
				aux = aux->_next;
			}

			if (aux == NULL) {
				// Si el producto ya se encuentra en la lista debemos asegurarnos que esta dando una cantidad mayor a 0
				if (nuevo->_order.quantity > 0) {
					antes->_next = nuevo;
					return true; //Orden agregada al carrito exitosamente
				}
				else return false;
			}
			else if (o.product == aux->_order.product) {
				// Si queremos meter 2 ordenes iguales, osea, que las dos tienen el mismo producto
				//Entonces, en lugar de meter la misma orden al carrito, solo incrementamos o decrementamos su cantidad del producto
				int total = 0;
				total = o.quantity + aux->_order.quantity;
				if (total > 0) {
					// Si la cantidad resultante es mayor que 0 entonces es una orden valida
					aux->_order.quantity = total;
					return true; //Operación ejecutada con exito
				}
				else if (total == 0) {
					// Si la cantidad de productos es 0, quiere decir que ya no debe de estar la orden ahi porque no tendrá productos dentro
					if (aux == antes) {
						// Si la orden con 0 productos que buscamos esta al inico de la lista la eliminamos
						_head = aux->_next;
						delete aux;
					}
					else {
						// Si la orden con 0 productos esta en cualquier otro lugar de la lista la eliminamos
						antes->_next = aux->_next;
						delete aux;
					}
					return true; //Operacion realizada con éxito
				}
				else if (total < 0) {
					// Si la cantidad de las 2 ordenes iguales resulta un número negativo no se realiza ninguna operación
					return false;
				}
			}
		}
		return false;
	}

	string getName() {
		//Regresa el nombre del dueño del carrito
		return name;
	}
	price_t cost() {
		//Regresa el costo total de las ordenes
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
		//Accesor de orden
		return node->_order;
	}
	Node* getNext(Node* node) {
		//Accesor de apuntador next
		return node->_next;
	}
	Node* getHead() {
		//Accesor del nodo head
		return _head;
	}
	void despNodes(Node* n) {
		//Hace el recorrido del carrito a partir del nodo n que es el head e
		//Imprime en pantalla todas las ordenes del carrito y hace 
		//Entrada: Nodo head
		//Salida: Imprime las ordenes del carrito
		if (n != NULL) {
			cout << n->_order;
			n = n->_next;
			despNodes(n);
		}
	}
};
ostream& operator<< (ostream& salida, ShoppingCart const& p) {
	salida << "Carrito de : " << p.name << endl;
	ShoppingCart temp = p;

	if(temp.getHead() == NULL) //Si no hay ordenes en el carrito...
		salida<<"No hay elementos en tu carrito\n";
	else {
		temp.despNodes(temp.getHead()); //Si los hay, manda a llamar el metodo que despliega todas las ordenes del carrito
		salida << endl;
	}
	return salida;
}