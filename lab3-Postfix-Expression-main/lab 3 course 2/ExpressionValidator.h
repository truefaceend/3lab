#pragma once
#include <iostream>
#include <vector>
#include "Table.h"
class ExpressionValidator
{
public:
	static bool CheckExpression(const std::vector<std::string>& exp, const Table<std::string, size_t>& tableOp) {
        int bracketCount = 0;
        std::string prevElem = "";
        for (size_t i = 0; i < exp.size(); i++) {
            if (exp[i] == "(") {
                bracketCount++;
            }
            if (tableOp.keyExist(prevElem) && tableOp.keyExist(exp[i]) && tableOp[exp[i]] != tableOp.maxValue() && exp[i] != "(")
                throw i;
            if (exp[i] == ")")
                bracketCount--;
            if (bracketCount < 0)
                throw i;
            if (exp[i] != "(" && tableOp.keyExist(exp[i])) {
                if (prevElem == "")
                    if (tableOp[exp[i]] == tableOp.maxValue())
                        prevElem = exp[i];
                    else
                        throw i;
            }
            prevElem = exp[i];
        }
        if (bracketCount != 0)
            throw "Bracket error";
        return true;
	}
};

