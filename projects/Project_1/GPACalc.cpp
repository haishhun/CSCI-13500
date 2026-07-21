#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    // Declare variables to store the user's grade input and separate it into credits and letter grade.
    std::string input_grade = "";
    int input_credits = 0;
    std::string input_letter_grade = "";

    // Declare variables used to calculate the GPA.
    int total_classes = 0;
    double total_credits = 0.0;
    double total_credit_points = 0.0;
    double grade_points = 0.0;
    double gpa = 0.0;

    // Declare variable to store the user's choice to continue entering grades.
    char continue_option = ' ';

    // Provide user the instructions on how to use the program.
    std::cout
        << "Welcome to the GPA Calculator!\n"
        << "Enter each course in the format <credits><letter grade>.\n"
        << "After each entry, press Y to enter another grade.\n"
        << "Press any other key to calculate your GPA and exit the program.\n\n";

    // Continuously ask for grades until the user chooses to stop.
    while (true)
    {
        std::cout << "Please enter your grade: ";
        std::cin >> input_grade;
        std::cin.ignore(10000, '\n'); // Handling inputs like "3 A B 3A+" etc.

        // Filter out inputs that are too short or too long like "1", "1000A+" etc.
        if (input_grade.size() < 2 || input_grade.size() > 4)
        {
            std::cout << "Error: Invalid grade input. Please enter again.\n";
            continue;
        }

        // Validate that the number of credits is between 1 and 9.
        if (input_grade[0] < '1' || input_grade[0] > '9')
        {
            std::cout << "Error: Invalid grade input. Please enter again.\n";
            continue;
        }

        // Convert the credit value from a character to an integer.
        input_credits = input_grade[0] - '0';

        // Separate the credits from the letter grade.
        input_letter_grade = input_grade.substr(1);

        // Convert the letter grade to uppercase.
        for (int i = 0; i < input_letter_grade.size(); i++)
        {
            if (input_letter_grade[i] >= 'a' && input_letter_grade[i] <= 'z')
                input_letter_grade[i] = input_letter_grade[i] - 'a' + 'A';
        }

        // Convert the letter grade into a point value.
        if (input_letter_grade == "A+" || input_letter_grade == "A")
        {
            grade_points = 4.0;
        }
        else if (input_letter_grade == "A-")
        {
            grade_points = 3.7;
        }
        else if (input_letter_grade == "B+")
        {
            grade_points = 3.3;
        }
        else if (input_letter_grade == "B")
        {
            grade_points = 3.0;
        }
        else if (input_letter_grade == "B-")
        {
            grade_points = 2.7;
        }
        else if (input_letter_grade == "C+")
        {
            grade_points = 2.3;
        }
        else if (input_letter_grade == "C")
        {
            grade_points = 2.0;
        }
        else if (input_letter_grade == "D")
        {
            grade_points = 1.0;
        }
        else if (input_letter_grade == "F" || input_letter_grade == "WU" || input_letter_grade == "FIN" || input_letter_grade == "FAB")
        {
            grade_points = 0.0;
        }
        else
        {
            std::cout << "Error: Invalid grade input. Please enter again.\n";
            continue;
        }

        // Update totals after each grade input.
        total_credit_points += input_credits * grade_points;
        total_credits += input_credits;
        total_classes++;

        // Ask the user if he wants to enter another grade.
        std::cout << "Enter Y to add another grade. Any other key to exit.\n";
        std::cin >> continue_option;
        std::cin.ignore(10000, '\n'); // Handling inputs like "y3A+" etc.

        if (continue_option != 'y' && continue_option != 'Y')
        {
            break;
        }
    }

    // Ensure that at least one valid grade was entered.
    if (total_credits == 0)
    {
        std::cout << "Error: No valid grades entered.\n";
        return 0;
    }

    // Calculate and display the final GPA.
    gpa = total_credit_points / total_credits;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Classes taken: " << total_classes << ", Semester GPA: " << gpa << std::endl;
}
