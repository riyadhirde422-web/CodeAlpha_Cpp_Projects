#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, i;
    float grade, credit;
    float totalCredits = 0;
    float totalPoints = 0;
    float cgpa;

    cout << "================================\n";
    cout << "       CGPA CALCULATOR\n";

    cout << "       CodeAlpha Internship\n";
    cout << "================================\n";

    cout << "Enter number of subjects: ";
    cin >> n;

    if (n <= 0 || n > 50)
    {
        cout << "Invalid number of subjects!";
        return 0;
    }

    for (i = 1; i <= n; i++)
    {
        cout << "\nSubject " << i << endl;

        cout << "Enter grade points: ";
        cin >> grade;

        cout << "Enter credit hours: ";
        cin >> credit;

        if (grade < 0 || credit <= 0)
        {
            cout << "Invalid input!";
            return 0;
        }

        totalPoints = totalPoints + (grade * credit);
        totalCredits = totalCredits + credit;
    }

    cgpa = totalPoints / totalCredits;

    cout << "\n================================\n";
    cout << "          RESULT\n";
    cout << "================================\n";

    cout << fixed << setprecision(2);
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalPoints << endl;
    cout << "Your CGPA is: " << cgpa << endl;

    cout << "================================\n";
    cout << "Thank you for using the calculator!\n";

    return 0;
}