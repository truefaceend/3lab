#include <iostream>
#include "PostfixExpression.h"

int main() {
	std::string ex = "sqrt(((sqrt(16)+5)*2)^2)/2";
	Table<std::string, size_t> priorT(7);
	priorT.Apennd("+", 1);
	priorT.Apennd("-", 1);
	priorT.Apennd("*", 2);
	priorT.Apennd("/", 2);
	priorT.Apennd("^", 3);
	priorT.Apennd("sqrt", 4);
	priorT.Apennd("(", 0);
	Table<std::string, double> valT(2);
	valT.Apennd("a", 5);
	valT.Apennd("aa", 16);
	PostfixExpression exp(priorT);
	std::cout << exp.solveExp("sqrt(0)");
	return 0;
}