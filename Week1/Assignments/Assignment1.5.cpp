#include <iostream>

int main()
{
    double first_number = 0; // Using double to have a proper result in dividing operation.
    double second_number = 0;
    char operation = ' ';
    double result = 0;
    char exit_choice = ' ';
    while (true)
    {
        // Taking user input and storing it in variables. Additionally validating each number input.
        std::cout << "Enter first number: ";
        std::cin >> first_number;
        if (std::cin.fail())
        {
            std::cout << "Error: Invalid data. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cout << "Enter second number: ";
        std::cin >> second_number;
        if (std::cin.fail())
        {
            std::cout << "Error: Invalid data. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cout << "Choose operation (+, -, *, /, %): "; // Validation is not needed because we do it later in switch-case.
        std::cin >> operation;
        std::cin.ignore(10000, '\n'); // Covering cases like '+1231231231', '%qweqwe' etc.

        // Calculating the result.
        switch (operation)
        {
        case '+':
            result = first_number + second_number;
            std::cout << "Result: " << result << '\n';
            break;

        case '-':
            result = first_number - second_number;
            std::cout << "Result: " << result << '\n';
            break;

        case '*':
        case 'x':
        case 'X':
            result = first_number * second_number;
            std::cout << "Result: " << result << '\n';
            break;

        case '/':
            if (second_number == 0)
                std::cout << "Error: Cannot divide by zero.\n";
            else
            {
                result = first_number / second_number;
                std::cout << "Result: " << result << '\n';
            }
            break;

        case '%':
            if (second_number == 0)
                std::cout << "Error: Cannot divide by zero.\n";
            else
            {
                result = first_number - (int)(first_number / second_number) * second_number; // Manually calculating, because our data types for numbers are double.
                std::cout << "Result: " << result << '\n';
            }
            break;

        default:
            std::cout << "Error: Invalid data. Please enter again\n";
            break;
        }

        // Asking if the user wants to exit.
        std::cout << "Would you like to continue? (Y/N)\n";
        std::cin >> exit_choice;
        std::cin.ignore(10000, '\n');
        if (exit_choice != 'Y' && exit_choice != 'y')
        {
            break;
        }
    }
    return 0;
}
