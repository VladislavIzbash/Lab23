#include "Lab3.h"

#include <sstream>
#include <stack>

float calculateRpn(const std::string& rpn)
{
    std::istringstream in(rpn);

    std::stack<float> operandStack;
    while (in >> std::ws && !in.eof() && std::isdigit(in.peek())) {
        float operand;
        in >> operand;
        operandStack.push(operand);
    }

    while (in >> std::ws && !in.eof()) {
        char oper;
        in >> oper;

        float result = 0;
        float b = operandStack.top();
        operandStack.pop();
        float a = operandStack.top();
        operandStack.pop();

        switch (oper) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) {
                throw std::domain_error("Zero division");
            } else {
                result = a / b;
            }

            break;
        }

        operandStack.push(result);
    }

    return operandStack.top();
}