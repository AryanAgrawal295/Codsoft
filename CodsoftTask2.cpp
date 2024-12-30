#include <iostream>
using namespace std;

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed.\n";
        return 0;
    }
    return a / b;
}

int main() {
    double num1, num2, result;
    char operation;
    char choice;

    do {
        // Input two numbers
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        // Display operation choices
        cout << "Select an operation to perform (+, -, *, /): ";
        cin >> operation;

        // Perform the chosen operation
        switch (operation) {
            case '+':
                result = add(num1, num2);
                cout << "The result of addition is: " << result << "\n";
                break;
            case '-':
                result = subtract(num1, num2);
                cout << "The result of subtraction is: " << result << "\n";
                break;
            case '*':
                result = multiply(num1, num2);
                cout << "The result of multiplication is: " << result << "\n";
                break;
            case '/':
                result = divide(num1, num2);
                if (num2 != 0) {
                    cout << "The result of division is: " << result << "\n";
                }
                break;
            default:
                cout << "Error: Invalid operation selected.\n";
        }

        // Ask the user if they want to perform another calculation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator. Goodbye!\n";
    return 0;
}
