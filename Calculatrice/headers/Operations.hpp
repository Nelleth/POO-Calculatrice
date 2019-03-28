#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <iostream>

using namespace std;

const string PI("3.14159265");

// Rajout de la stack pour la fonction calcul
bool isOperator(string buffer);
bool hasNoOperator(string buffer);
bool hasNoOpeUnlessMinus(string buffer);
bool isError(string buffer);
bool isValidNumber(string str);


#endif
