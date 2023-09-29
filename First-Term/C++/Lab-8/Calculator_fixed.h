#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H


#include <algorithm>
#include <cassert>
#include <string>
#include "Stack.h"
#include <map>
#include <vector>

bool IsDigit(char c);

class Calculator {
public:
    Calculator();

    static double Calculate(const std::string& expression);

private:
    struct Token {
        enum class Type {
            kConstant,
            kPlus,
            kMinus,
            kUnaryMinus,
            kMultiply,
            kDivide,
            kLeftBrace,
            kRightBrace,
            kUnknown,
            kPower
        };

        Token();

        Token(const std::string& s);

        Token(Type type);

        Token(double constant_value);

        static Type GetTokenType(const std::string& s);

        static const std::map<Type, int> operation_priorities;

        static const std::map<Type, int> is_operation;

        Type type = Type::kUnknown;
        double constant_value;
        int operation_priority;
    };

    static std::vector<Token> Tokenize(std::string s);

    static Stack<Token> GetPolishNotation(const std::vector<Token>& tokens);

    static std::pair<Token, Token> PopTwoTokens(Stack<Token>& expression);

    static Token PopOneToken(Stack<Token>& expression);

    static std::pair<double, double> PopTwoOperands(Stack<Token>& expression);

    static double PopOneOperand(Stack<Token>& expression);

    static void PerformOperation(
            Stack<Token>& operands,
            const Token& operation_token);

    void Process(Token token);

    Stack<Token> operands_;
};
#endif //CALCULATOR_CALCULATOR_H
