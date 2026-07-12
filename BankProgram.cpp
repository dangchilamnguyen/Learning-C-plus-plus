#include <iostream>
#include <vector>
#include <cmath>

void balance(double balance);
void deposit(double &CurrentBalance);
void withdraw(double &CurrentBalance);
int main()
{
    int choose;
    double CurrentBalance = 5000.00;

    while (true)
    {
        std::cout << "========== BANK SYSTEM ==========\n";
        std::cout << "1.Show balance\n";
        std::cout << "2.Deposit\n";
        std::cout << "3.Withdraw\n";
        std::cout << "4.Exit\n";
        std::cout << "=================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            balance(CurrentBalance);
            break;
        case 2:
            deposit(CurrentBalance);
            break;
        case 3:
            withdraw(CurrentBalance);
            break;
        case 4:
            std::cout << "Goodbye";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again" << '\n';
            break;
        }
    }
    system("pause");
    return 0;
}
void balance(double CurrentBalance)
{
    std::cout << "Your current balance is: " << CurrentBalance << '\n';
}
void deposit(double &CurrentBalance)
{
    double AddedDeposit;
    std::cout << "Enter amount you want to deposit: ";
    std::cin >> AddedDeposit;
    if (AddedDeposit < 0)
    {
        std::cout << "Invalid" << '\n';
    }
    else
    {
        CurrentBalance += AddedDeposit;
    }
    std::cout << "Your current balance is " << CurrentBalance << '\n';
}
void withdraw(double &CurrentBalance)
{
    double WithdrawAmount;
    std::cout << "Enter amount you want to withdraw: ";
    std::cin >> WithdrawAmount;
    if (WithdrawAmount < 0 || WithdrawAmount > CurrentBalance)
    {
        std::cout << "Invaid" << '\n';
    }
    else
    {
        CurrentBalance -= WithdrawAmount;
    }
    std::cout << "Your current balance is " << CurrentBalance << '\n';
}
