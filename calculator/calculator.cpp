#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

using Number = double;

bool ReadNumber(Number& result) {
    std::cin >> result;
    if (std::cin.fail()) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    } 
    return true;
}

bool RunCalculatorCycle() {
    Number operand = 0.0;
    Number memory_cell = 0.0;
    ReadNumber(operand);

    std::string action_temp;
    bool is_memory = false;
        
        while (!std::cin.fail()) {
            std::cin >> action_temp;
            char action = action_temp[0];
            Number next_operand = 0.0;
            Number next_enter = 0.0;
     
            if ((action_temp[0] =='*') && (action_temp[1] =='*')) {
                action = '^';
            }
            
            switch (action)
            {
                case '+':
                    ReadNumber(next_enter);
                    next_operand = next_enter;
                    operand += next_operand;
                    break;
                case '-':
                    ReadNumber(next_enter);
                    next_operand = next_enter;
                    operand -= next_operand;
                    break;
                case '*':
                    ReadNumber(next_enter);
                    next_operand = next_enter;
                    operand *= next_operand;
                    break;
                case '/':
                    ReadNumber(next_enter);
                    next_operand = next_enter;
                    operand /= next_operand;
                    break;
                case '^':
                    ReadNumber(next_enter);
                    next_operand = next_enter;
                    operand = pow(operand, next_operand);
                    break;
                case ':':
                    ReadNumber(next_enter);
                    next_operand = next_enter;
                    operand = next_operand;
                    break;
                case '=':
                    std::cout << operand << std::endl;
                    break;
                case 'c':
                    operand = 0;
                    break;
                case 'q':
                    return 0;
                case 's':
                    memory_cell = operand;
                    is_memory = true;
                    break;
                case 'l':
                    if (is_memory) {
                        operand = memory_cell;
                        break;
                    } else {
                        std::cerr << "Error: Memory is empty" << std::endl;
                        return 0;
                        break;
                    } 
                
                default:
                    std::cerr << "Error: Unknown token " << action_temp << std::endl;
                    return false;
            } 
      } 
    return true;
}







