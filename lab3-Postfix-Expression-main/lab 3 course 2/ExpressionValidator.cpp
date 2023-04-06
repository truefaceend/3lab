#include "ExpressionValidator.h"

//bool ExpressionValidator::CheckExpression(const std::vector<std::string>& exp, const Table<std::string, size_t>& table)
//{
//    int bracketCount = 0;
//    std::string prevElem = "";
//    for (size_t i = 0; i < exp.size(); i++) {
//        if (exp[i] == "(") {
//            bracketCount++;
//        }
//        if (table.keyExist(prevElem) && table.keyExist(exp[i]) && table[exp[i]] != table.maxValue() && exp[i] != "(")
//            throw i;
//        if (exp[i] == ")")
//            bracketCount--;
//        if (bracketCount < 0)
//            throw i;
//        if (exp[i] != "(" && table.keyExist(exp[i])) {
//            if (prevElem == "")
//                if (table[exp[i]] == table.maxValue())
//                    prevElem = exp[i];
//                else
//                    throw i;
//        }
//        prevElem = exp[i];
//    }
//    if (bracketCount != 0)
//        throw "Bracket error";
//    return true;
//}

