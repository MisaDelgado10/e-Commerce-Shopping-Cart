#pragma once
#include <iostream>
using namespace std;
typedef float price_t;

struct Product {
    string name;
    price_t price;

    Product(string name, price_t price);
    friend bool operator== (const Product& product1, const Product& product2);//Product vs Product
    friend bool operator== (const Product& product1, const string& product_name);//Product vs Product_name
    friend bool operator!= (const Product& product1, const Product& product2);//Product vs Product
    friend bool operator!= (const Product& product1, const string& product2);//Product vs Product_name
    friend ostream& operator<< (ostream& output, Product& n);
};
