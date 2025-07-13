#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    double result;

    cout << "🧮 Simple Calculator in C++" << endl;

    // Input numbers
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Choose operation
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform calculation
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "❌ Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "❌ Invalid operation selected." << endl;
    }

    return 0;
}
