#include "Calculator.h"
#include <algorithm>
#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <cmath>

bool IsDigit(char c) {
    return c >= '0' && c <= '9';
}

std::string Trim(const std::string& s) {
    int start_index = 0;
    int end_index = s.size();
    while (start_index < s.size() && s[start_index] == ' ') {
        ++start_index;
    }
    while (end_index > start_index && s[end_index - 1] == ' ') {
        --end_index;
    }
    return s.substr(start_index, end_index - start_index);
}

std::string ReplaceAll(
        std::string str,
        const std::string& from,
        const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
Calculator::Calculator() = default;

Calculator::Token::Token() = default;

Calculator::Token::Token(const std::string& s) : type(GetTokenType(s)) {
    if (type == Type::kConstant) {
        constant_value = std::stoi(s);
    }

    if (is_operation.at(type)) {
        operation_priority = operation_priorities.at(type);
    }
}

Calculator::Token::Token(const Type type) : type(type) {
    if (is_operation.at(type)) {
        operation_priority = operation_priorities.at(type);
    }
}

Calculator::Token::Token(double constant_value) : constant_value(constant_value) {}

Calculator::Token::Type Calculator::Token::GetTokenType(const std::string& s) {
    assert(!s.empty());

    if (s == "+") {
        return Type::kPlus;
    } else if (s == "-") {
        return Type::kMinus;
    } else if (s == "*") {
        return Type::kMultiply;
    } else if (s == "/") {
        return Type::kDivide;
    } else if (s == "(") {
        return Type::kLeftBrace;
    } else if (s == ")") {
        return Type::kRightBrace;
    } else if (s == "^") {
        return Type::kPower;
    }else {
        bool all_chars_are_numbers = std::all_of(s.begin(), s.end(), IsDigit);

        if (all_chars_are_numbers) {
            return Type::kConstant;
        }
    }
    return Type::kUnknown;
}

void PrepareForTokenization(std::string& s) {
    s = ReplaceAll(s, "(", " ( ");
    s = ReplaceAll(s, ")", " ) ");
    s = ReplaceAll(s, "-", " - ");
    s = ReplaceAll(s, "+", " + " );
    s = ReplaceAll(s, "/", " / " );
    s = ReplaceAll(s, "*", " * " );
    s = ReplaceAll(s, "^", " ^ " );
    s = ReplaceAll(s, "   ", " ");
    s = ReplaceAll(s, "  ", " ");
    s = Trim(s);
}

std::vector<Calculator::Token> Calculator::Tokenize(std::string s) {
    PrepareForTokenization(s);

    using Type = Token::Type;

    std::vector<Token> result;
    int token_start_index = 0;
    Type previous_token_type = Type::kUnknown;

    while (token_start_index < s.size()) {
        int token_end_index = token_start_index + 1;  // exclusive
        do {
            ++token_end_index;
        } while (token_end_index < s.size()
                 && s[token_end_index - 1] != ' ');
        if (token_end_index != s.size()) {
            --token_end_index;
        }

        Type current_token_type = Token::GetTokenType(
                s.substr(token_start_index,
                         token_end_index - token_start_index));

        if (current_token_type == Type::kUnknown) {
            assert(false);
        }

        if (
                current_token_type == Type::kMinus &&
                previous_token_type != Type::kConstant &&
                previous_token_type != Type::kRightBrace) {
            current_token_type = Type::kUnaryMinus;
        }

        Token current_token = Token(current_token_type);
        if (current_token_type == Type::kConstant) {
            current_token.constant_value = std::stoi(
                    s.substr(token_start_index,
                             token_end_index - token_start_index));
        }

        result.push_back(current_token);
        token_start_index = token_end_index + 1;
        previous_token_type = current_token_type;
    }
    return result;
}

Stack<Calculator::Token> Calculator::GetPolishNotation(
        const std::vector<Token>& tokens) {
    using Type = Token::Type;

    Stack<Token> operations;
    Stack<Token> result;
    for (Token token : tokens) {
        if (token.type == Type::kConstant) {
            result.Push(token);
        } else if (token.type == Type::kLeftBrace) {
            operations.Push(token);
        } else if (token.type == Type::kRightBrace) {
            while (operations.Top().type != Type::kLeftBrace) {
                result.Push(operations.Top());
                operations.Pop();
            }
            operations.Pop();
        } else {
            while (
                    !operations.Empty() &&
                    operations.Top().operation_priority >= token.operation_priority) {
                result.Push(operations.Top());
                operations.Pop();
            }
            operations.Push(token);
        }
    }
    while (!operations.Empty()) {
        result.Push(operations.Top());
        operations.Pop();
    }
    return result;
}

std::pair<Calculator::Token, Calculator::Token> Calculator::PopTwoTokens(
        Stack<Token>& expression) {
    Token first_operand;
    Token second_operand;
    second_operand = expression.Top();
    expression.Pop();
    first_operand = expression.Top();
    expression.Pop();
    return std::make_pair(first_operand, second_operand);
}

Calculator::Token Calculator::PopOneToken(Stack<Token>& expression) {
    Token operand = expression.Top();
    expression.Pop();
    return operand;
}

std::pair<double, double> Calculator::PopTwoOperands(Stack<Token>& expression) {
    std::pair<Token, Token> two_tokens = PopTwoTokens(expression);
    return std::make_pair(
            two_tokens.first.constant_value,
            two_tokens.second.constant_value);
}

double Calculator::PopOneOperand(Stack<Token>& expression) {
    Token token = PopOneToken(expression);
    return token.constant_value;
}

void Calculator::PerformOperation(
        Stack<Token>& operands_stack,
        const Token& operation_token) {
    const Token::Type operation = operation_token.type;
    double operation_result;
    switch (operation) {
        case Token::Type::kMinus : {
            std::pair<double, double> operands = PopTwoOperands(operands_stack);
            operation_result = operands.first - operands.second;
            break;
        }
        case Token::Type::kPlus: {
            std::pair<double, double> operands = PopTwoOperands(operands_stack);
            operation_result = operands.first + operands.second;
            break;
        }
        case Token::Type::kPower: {
            std::pair<double, double> operands = PopTwoOperands(operands_stack);
            operation_result = pow(operands.first, operands.second);
            break;
        }
        case Token::Type::kMultiply: {
            std::pair<double, double> operands = PopTwoOperands(operands_stack);
            operation_result = operands.first * operands.second;
            break;
        }
        case Token::Type::kDivide: {
            std::pair<double, double> operands = PopTwoOperands(operands_stack);
            operation_result = operands.first / operands.second;
            break;
        }
        case Token::Type::kUnaryMinus: {
            operation_result = -PopOneOperand(operands_stack);
            break;
        }
    }
    operands_stack.Push(Token(operation_result));
}

double Calculator::Calculate(const std::string& expression) {
    std::vector<Token> tokenized = Tokenize(expression);
    Stack<Token> polish_notation = GetPolishNotation(tokenized);

    if (polish_notation.Size() == 1) {
        assert(polish_notation.Top().type == Token::Type::kConstant);
        return polish_notation.Top().constant_value;
    }

    Stack<Token> reversed_expression;
    while (!polish_notation.Empty()) {
        reversed_expression.Push(polish_notation.Top());
        polish_notation.Pop();
    }

    Calculator calculator = Calculator();
    while (!reversed_expression.Empty()) {
        calculator.Process(reversed_expression.Top());
        reversed_expression.Pop();
    }

    return calculator.operands_.Top().constant_value;
}

void Calculator::Process(Token token) {
    if (token.type == Token::Type::kConstant) {
        operands_.Push(token);
        return;
    }
    PerformOperation(operands_, token);
}

const std::map<Calculator::Token::Type, int>
        Calculator::Token::operation_priorities = {
        {Token::Type::kPlus, 1},
        {Token::Type::kMinus, 1},
        {Token::Type::kUnaryMinus, 41},
        {Token::Type::kMultiply, 2},
        {Token::Type::kDivide, 2},
        {Token::Type::kLeftBrace, 0},
        {Token::Type::kRightBrace, 0},
        {Token::Type::kPower, 3},
};

const std::map<Calculator::Token::Type, int> Calculator::Token::is_operation = {
        {Type::kConstant,         false},
        {Type::kUnknown,          false},
        {Type::kLeftBrace,        true},
        {Type::kRightBrace,       true},
        {Type::kPlus,             true},
        {Type::kMinus,            true},
        {Type::kUnaryMinus,       true},
        {Type::kMultiply,         true},
        {Type::kPower,            true},
        {Type::kDivide,           true},

};