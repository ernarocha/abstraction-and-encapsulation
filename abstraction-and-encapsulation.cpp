#include <iostream>
#include <limits>
using namespace std;

class BankAccount
{

protected:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    virtual void withdrawAmount(double amount) = 0;
    virtual void depositAmount(double amount) = 0;
    virtual void displayMenu() = 0;

    double getAccountBalance() const {
        return balance;
    }
};

class SavingsAccount : public BankAccount
{

private:
    const double minimumBalance = 1000;

public:
    SavingsAccount(double initialBalance) : BankAccount(initialBalance) {}

    void depositAmount(double amount) override {
        bool inputValid = false;

        while (!inputValid) {
            cout << endl <<"Enter the amount to deposit: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout <<"Invalid input! Please enter a valid number." << endl;
            }
            else if (balance == 0 && amount < minimumBalance) {
                cout << "The minimum initial deposit must be at least 1000." << endl;
            }
            else if (amount > 0) {
                balance += amount;
                cout << endl << "Deposit successful! Your new balance is: " << balance << endl << endl;
                inputValid = true;
            }
            else {
                cout << "Invalid input!" << endl;
            }
        }
        cout << "Returning to the main menu..." << endl;
        system("pause");
    }

    void withdrawAmount(double amount) override
    {
        if (balance == 0)
        {
            cout << "Insufficient funds! Your current balance is 0." << endl << endl;
            system("pause");
            return;
        }

        bool inputValid = false;

        while (!inputValid)
        {
            cout << endl << "Enter the amount to withdraw: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please try again." << endl;
            }
            else if (amount > 0 && balance - amount >= minimumBalance) {
                balance -= amount;
                cout << "Withdrawal successful! Your new balance is: " << balance << endl << endl;
                inputValid = true;
            }
            else if (amount > balance) {
                cout << "Insufficient funds!" << endl << "Current Balance: " << balance << endl;
            }
            else if (balance - amount < minimumBalance) {
                cout << "Withdrawal not allowed! You must maintain a minimum balance of 1000." << endl  << "Current Balance: " << balance << endl << endl;
                break;
            }
            else {
                cout << "Invalid input!" << endl;
                break;
            }
        }
        cout << "Returning to the main menu..." << endl;
        system("pause");
    }

    void displayMenu() override
    {
        int choice = 0;
        do
        {
            system("cls");

            cout << endl << "Savings Account Menu" << endl;
            cout << "1 - Deposit" << endl;
            cout << "2 - Withdrawal" << endl;
            cout << "3 - Check Balance" << endl;
            cout << "4 - Back" << endl;

            cout << endl <<"Enter choice: ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice> 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl <<"Invalid input! Please try again." << endl;
                system("pause");
            }
            else
            {
                switch (choice) {
                case 1:
                    system("cls");
                    depositAmount(0);
                    break;
                case 2:
                    system("cls");
                    withdrawAmount(0);
                    break;
                case 3:
                    system("cls");
                    cout << "Your current balance is: " << getAccountBalance() << endl << endl;
                    system("pause");
                    break;
                case 4:
                    cout << "Returning to the main menu..." << endl;
                    break;
                }
            }
        } while (choice != 4);
    }
};

class CurrentAccount : public BankAccount
{

public:
    CurrentAccount(double initialBalance) : BankAccount(initialBalance) {}

    void depositAmount(double amount) override
    {
        bool inputValid = false;
        while (!inputValid)
        {
            cout << endl << "Enter the amount to deposit: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout <<"Invalid input! Please enter a valid number." << endl;
            }
            else if (amount > 0) {
                balance += amount;
                cout << "Deposit successful! Your new balance is: " << balance << endl << endl;
                inputValid = true;
            }
            else {
                cout << "Invalid input!" << endl;
            }
        }
        cout << "Returning to the main menu..." << endl;
        system("pause");
    }

    void withdrawAmount(double amount) override
    {
        if (balance == 0)
        {
            cout << "You have no funds to withdraw!" << endl
                 << "Your current balance is 0" << endl << endl;
            system("pause");
            return;
        }

        bool inputValid = false;
        while (!inputValid)
        {
            cout << endl << "Enter the amount to withdraw: ";
            cin >> amount;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl <<"Invalid input! Please try again." << endl;
                system("pause");
            }
            else if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrawal successful! Your new balance is: " << balance << endl << endl;
                inputValid = true;
            }
            else if (amount > balance) {
                cout << "Insufficient funds!" << endl << "Current Balance: " << balance << endl << endl;
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
        }
        cout << "Returning to the main menu..." << endl;
        system("pause");
    }

    void displayMenu() override
    {
        int choice = 0;

        do
        {
            system("cls");

            cout << endl << "Current Account Menu" << endl;
            cout << "1 - Deposit" << endl;
            cout << "2 - Withdraw" << endl;
            cout << "3 - Check Balance" << endl;
            cout << "4 - Back" << endl;

            cout << endl <<"Enter choice: ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl <<"Invalid input! Please try again." << endl;
                system("pause");
            }
            else {
                switch (choice) {
                case 1:
                    system("cls");
                    depositAmount(0);
                    break;
                case 2:
                    system("cls");
                    withdrawAmount(0);
                    break;
                case 3:
                    system("cls");
                    cout << "Your current balance is: " << getAccountBalance() << endl << endl;
                    system("pause");
                    break;
                case 4:
                    cout << "Returning to the main menu..." << endl;
                    break;
                }
            }
        } while (choice != 4);
    }
};

int main()
{

    SavingsAccount savings(0);
    CurrentAccount current(0);

    int choice = 0;

    do
    {
        system("cls");

        cout << endl  << "      Main Menu" << endl;
        cout << "1 - Savings Account" << endl;
        cout << "2 - Current Account" << endl;
        cout << "3 - Exit" << endl;

        cout << endl <<"Enter choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl <<"Invalid input! Please try again." << endl;
            system("pause");
        }
        else {
            switch (choice)
            {
            case 1:
                savings.displayMenu();
                break;
            case 2:
                current.displayMenu();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            }
        }
    } while (choice != 3);

    return 0;
}