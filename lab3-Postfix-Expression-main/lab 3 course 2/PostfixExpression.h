#pragma once
#include <string>
#include <cmath>
#include "ExpressionValidator.h"
#include "TStack.h"
class PostfixExpression
{
private:
	TStack<std::string> opStack;
	TStack<double> valStack;
	Table<std::string, size_t> priorTable;
	Table<std::string, double> varTable;
	std::vector<std::string> exp;
	std::vector<std::string> posfixExp;
	ExpressionValidator check;
public:
	PostfixExpression(const Table<std::string, size_t>& _priorTable, const Table<std::string, double>& _varTable = Table<std::string, double>(0)) {
		priorTable =_priorTable;
		varTable = _varTable;
	}
	void initVector(const std::string& str) {
		std::string buf;
		for (size_t i = 0; i < str.size(); i++) {
			std::string s;
			s.push_back(str[i]);
			if (str[i] == ' ')
				continue;
			if (str[i] == '(' || str[i] == ')' || priorTable.keyExist(s)) {
				if(buf != "")
					exp.push_back(buf);
				buf.clear();
				exp.push_back(s);
				continue;
			}
			buf.push_back(str[i]);
		}
		if (buf != "")
			exp.push_back(buf);
	}
	void toPosfix(const std::string& str) {
		initVector(str);
		if (check.CheckExpression(exp, priorTable)) {
			for (size_t i = 0; i < exp.size(); i++) {
				if (!priorTable.keyExist(exp[i])) {
					if (exp[i] != ")")
						posfixExp.push_back(exp[i]);
					else {
						while (opStack.Top() != "(") {
							posfixExp.push_back(opStack.Pop());
						}
						opStack.Pop();
					}
				}
				else {
					if (exp[i] != "(")
						while (!opStack.CheckEmpty() && priorTable[opStack.Top()] >= priorTable[exp[i]]) {
							posfixExp.push_back(opStack.Pop());
						}
					opStack.Push(exp[i]);
				}
			}
			while (!opStack.CheckEmpty())
				posfixExp.push_back(opStack.Pop());
		}
	}
	double solveExp(const std::string& str) {
		toPosfix(str);
		for (size_t i = 0; i < posfixExp.size(); i++) {
			if (!priorTable.keyExist(posfixExp[i])) {
				if (!varTable.keyExist(posfixExp[i])) {
					valStack.Push(std::stod(posfixExp[i]));
				}
				else {
					valStack.Push(varTable[posfixExp[i]]);
				}
			}
			else {
				double operand2 = valStack.Pop();
				double operand1;
				if(!valStack.CheckEmpty())
					operand1 = valStack.Pop();
				if (posfixExp[i] == "+") {
					valStack.Push(operand1 + operand2);
					continue;
				}
				if (posfixExp[i] == "-") {
					valStack.Push(operand1 - operand2);
					continue;
				}
				if (posfixExp[i] == "*") {
					valStack.Push(operand1 * operand2);
					continue;
				}
				if (posfixExp[i] == "/") {
					valStack.Push(operand1 / operand2);
					continue;
				}
				if (posfixExp[i] == "^") {
					valStack.Push(pow(operand1, operand2));
					continue;
				}
				if (posfixExp[i] == "sin") {
					valStack.Push(operand1);
					valStack.Push(sin(operand2));
					continue;
				}
				if (posfixExp[i] == "cos") {
					valStack.Push(operand1);
					valStack.Push(cos(operand2));
					continue;
				}
				if (posfixExp[i] == "sqrt") {
					valStack.Push(operand1);
					valStack.Push(sqrt(operand2));
					continue;
				}
				if (posfixExp[i] == "tan") {
					valStack.Push(operand1);
					valStack.Push(tan(operand2));
					continue;
				}
				if (posfixExp[i] == "asin") {
					valStack.Push(operand1);
					valStack.Push(asin(operand2));
					continue;
				}
				if (posfixExp[i] == "acos") {
					valStack.Push(operand1);
					valStack.Push(acos(operand2));
					continue;
				}
				if (posfixExp[i] == "atan") {
					valStack.Push(operand1);
					valStack.Push(atan(operand2));
					continue;
				}
			}
		}
		return valStack.Pop();
	}
};

