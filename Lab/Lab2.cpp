#include "Lab2.h"

#include <sstream>
#include <stack>

std::string infixToRpn(const std::string& infix)
{
    std::istringstream in(infix);
    std::ostringstream out;

    std::stack<char> operStack;

    while (in >> std::ws && !in.eof()) {
        if (std::isdigit(in.peek())) {
            float operand;
            in >> operand;
            out << operand << ' ';
        } else {
            char ch;
            in >> ch;

            switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
                operStack.push(ch);
                break;
            case ')':
                while (operStack.top() != '(') {
                    out << operStack.top() << ' ';
                    operStack.pop();
                }
                operStack.pop();
                break;
            default:
                throw std::invalid_argument(std::string("Unexpected operation: ") + ch);
            }
        }
    }

    while (!operStack.empty()) {
        out << operStack.top() << ' ';
        operStack.pop();
    }

    return out.str();
}