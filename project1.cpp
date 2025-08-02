#include <iostream>
#include <cmath>
#include <limits> // for input validation
using namespace std;

// Function prototypes
void basicMenu();
void scientificMenu();
void clearScreen();
void pause();

void add(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);
void power(double base, double exponent);
void squareRoot(double a);
void logarithm(double a);
void sine(double angle);
void cosine(double angle);
void tangent(double angle);

int main() {
    int mainChoice;

    do {
        clearScreen();
        cout << "========== ADVANCED CALCULATOR ==========" << endl;
        cout << "1. Basic Operations" << endl;
        cout << "2. Scientific Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                basicMenu();
                break;
            case 2:
                scientificMenu();
                break;
            case 3:
                cout << "Thank you for using the calculator!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                pause();
        }
    } while (mainChoice != 3);

    return 0;
}

// Basic Operations Menu
void basicMenu() {
    int choice;
    double num1, num2;

    do {
        clearScreen();
        cout << "\n--- Basic Operations ---" << endl;
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }

        switch (choice) {
            case 1: add(num1, num2); break;
            case 2: subtract(num1, num2); break;
            case 3: multiply(num1, num2); break;
            case 4: divide(num1, num2); break;
            case 5: break;
            default: cout << "Invalid choice."; break;
        }

        pause();
    } while (choice != 5);
}

// Scientific Operations Menu
void scientificMenu() {
    int choice;
    double num;

    do {
        clearScreen();
        cout << "\n--- Scientific Operations ---" << endl;
        cout << "1. Power (x^y)\n2. Square Root\n3. Logarithm (base e)" << endl;
        cout << "4. Sine\n5. Cosine\n6. Tangent\n7. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            cout << "Enter number (angle in degrees for trig functions): ";
            cin >> num;
        }

        switch (choice) {
            case 1: {
                double exp;
                cout << "Enter exponent: ";
                cin >> exp;
                power(num, exp);
                break;
            }
            case 2: squareRoot(num); break;
            case 3: logarithm(num); break;
            case 4: sine(num); break;
            case 5: cosine(num); break;
            case 6: tangent(num); break;
            case 7: break;
            default: cout << "Invalid choice."; break;
        }

        pause();
    } while (choice != 7);
}

// Basic functions
void add(double a, double b) {
    cout << "Result: " << a + b << endl;
}
void subtract(double a, double b) {
    cout << "Result: " << a - b << endl;
}
void multiply(double a, double b) {
    cout << "Result: " << a * b << endl;
}
void divide(double a, double b) {
    if (b == 0)
        cout << "Error: Cannot divide by zero." << endl;
    else
        cout << "Result: " << a / b << endl;
}

// Scientific functions
void power(double base, double exponent) {
    cout << "Result: " << pow(base, exponent) << endl;
}
void squareRoot(double a) {
    if (a < 0)
        cout << "Error: Cannot take square root of negative number." << endl;
    else
        cout << "Result: " << sqrt(a) << endl;
}
void logarithm(double a) {
    if (a <= 0)
        cout << "Error: Logarithm undefined for zero or negative numbers." << endl;
    else
        cout << "Result: " << log(a) << endl;
}
void sine(double angle) {
    cout << "Result: " << sin(angle * M_PI / 180) << endl;
}
void cosine(double angle) {
    cout << "Result: " << cos(angle * M_PI / 180) << endl;
}
void tangent(double angle) {
    cout << "Result: " << tan(angle * M_PI / 180) << endl;
}

// Utility functions
void clearScreen() {
    // Works on most systems (or you can use system("cls") on Windows)
    cout << string(50, '\n');
}
void pause() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
