// Sean Bufano

#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include "Store.h"

#define USAGE  argv[0]


int main(int  argc, char* argv[]) {

	cout << "Welcome to our online store!" << endl;

	if (argc > 1) {
		cerr << USAGE << endl;
		return  EXIT_FAILURE;
	}

	string  file_name;
	cerr << "Enter products file name:  " << flush;
	cin >> file_name;

	Store  store(file_name);

	if (store.is_open()) {

		istream* in;
		cerr << "Enter transactions file name (\"-\" for standard input):  " <<
			flush;
		cin >> file_name;
		if (file_name == "-") {
			in = &cin;
		}
		else {
			if ((in = new  ifstream(file_name.c_str()))->bad()) {
				cerr << "ERROR:  Failed to open file...aborting." << endl;
				return  EXIT_FAILURE;
			}
		}

		string  customer_name;
		string  command;
		int  quantity;
		string  product_name;
		string  junk;  // to clear a junk line

		while ((*in >> customer_name >> command).good()) {

			if (command == Store::SHOWCART || command == Store::CHECKOUT) {
				store.processshoppingCart(customer_name, command);
			}
			else
				if (command == Store::BUYS || command == Store::RETURNS) {
					if ((*in >> quantity >> product_name).good()) {
						store.processshoppingCart(customer_name, command, quantity, product_name);
					}
					else {
						if (!in->bad()) {
							cerr << "Input error...skipping line" << endl;
							in->clear();
							*in >> junk;
						}
						else {
							cerr << "Input error...cannot recover...aborting." << endl;
							return  EXIT_FAILURE;
						}
					}
				}
				else {
					cerr << "Illegal command \"" << command <<
						"\"...skipping line." << endl;
					*in >> junk;
				}
		}

		if (in->eof()) {
			store.close(cout);
			return  EXIT_SUCCESS;
		}
		else {
			cerr << "Input error...cannot recover...aborting." << endl;
			return  EXIT_FAILURE;
		}
	}
	else {
		cerr << "Store remains empty...exiting." << endl;
		return  EXIT_FAILURE;
	}
}
