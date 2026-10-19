#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(string username)
{
    ifstream file("users.txt");
    string savedUser, savedPassword;

    while (file >> savedUser >> savedPassword)
    {
        if (savedUser == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void registerUser()
{
    string username, password;

    cout << "\nEnter username: ";
    cin >> username;

    if (userExists(username))
    {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    if (!file)
    {
        cout << "Error saving user data!\n";
        return;
    }

    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

void loginUser()
{
    string username, password;
    string savedUser, savedPassword;
    bool found = false;

    cout << "\nEnter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> savedUser >> savedPassword)
    {
        if (savedUser == username &&
            savedPassword == password)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login successful! Welcome, " << username << "!\n";
    else
        cout << "Invalid username or password!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n============================\n";
        cout << " LOGIN AND REGISTRATION SYSTEM\n";
        cout << "============================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank you for using the system!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}