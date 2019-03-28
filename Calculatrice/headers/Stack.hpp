#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <cmath>
#include <map>

using namespace std;

class Stack
{
	public:
		/*constructeurs*/
		Stack();
		Stack(stack <float> argt);

		stack <float> argument;
		string Operation(string);
		stack <float> getArgument();
};

#endif
