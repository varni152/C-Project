#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    switch(operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error! Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation! Please choose from +, -, *, /" << endl;
    }

    return 0;
}
