#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

std::string getUserchoice();
std::string getComputerChoice();
void showWinner(std::string UserChoice, std::string ComputerChoice);
void score(std::string UserChoice, std::string ComputerChoice, int &PlayerScore, int &ComputerScore);
int main()
{
    srand(time(0));
    char PlayAgain;
    int PlayerScore = 0;
    int ComputerScore = 0;
    do
    {
        std::string UserChoice;
        std::string ComputerChoice;
        std::cout << "======= ROCK PAPER SCISSORS GAME =======\n";
        UserChoice = getUserchoice();
        ComputerChoice = getComputerChoice();
        std::cout << "You chose    : " << UserChoice << "\n";
        std::cout << "Computer chose: " << ComputerChoice << "\n";
        showWinner(UserChoice, ComputerChoice);
        score(UserChoice, ComputerChoice, PlayerScore, ComputerScore);
        std::cout << "----------------------------------------\n";
        std::cout << "SCORE:  YOU : " << PlayerScore << " //  COMPUTER : " << ComputerScore << '\n';
        std::cout << "----------------------------------------\n";
        std::cout << "Do you want a rematch ? (Enter y/n)";
        std::cin >> PlayAgain;
    } while (PlayAgain == 'y');

    std::cout << "Thanks for playing!";
    return 0;
}
std::string getUserchoice()
{
    std::string UserChoice;
    do
    {
        std::cout << "Enter your choice (rock, paper, scissors) : ";
        std::cin >> UserChoice;
        if (UserChoice != "rock" && UserChoice != "paper" && UserChoice != "scissors")
        {
            std::cout << "Invalid choice! Please enter again.\n";
        }
    } while (UserChoice != "rock" && UserChoice != "paper" && UserChoice != "scissors");
    return UserChoice;
}
std::string getComputerChoice()
{
    int num = rand() % 3;
    if (num == 0)
        return "rock";
    else if (num == 1)
        return "paper";
    else
        return "scissors";
}
void showWinner(std::string UserChoice, std::string ComputerChoice)
{

    if (UserChoice == ComputerChoice)
    {
        std::cout << "IT'S A TIE!\n";
    }
    else if ((UserChoice == "rock" && ComputerChoice == "scissors") ||
             (UserChoice == "paper" && ComputerChoice == "rock") ||
             (UserChoice == "scissors" && ComputerChoice == "paper"))
    {
        std::cout << "YOU WIN! \n";
    }

    else
    {
        std::cout << "YOU LOSE!\n";
    }
}
void score(std::string UserChoice, std::string ComputerChoice, int &PlayerScore, int &ComputerScore)
{
    if (UserChoice == ComputerChoice)
    {
        return;
    }
    else if ((UserChoice == "rock" && ComputerChoice == "scissors") ||
             (UserChoice == "paper" && ComputerChoice == "rock") ||
             (UserChoice == "scissors" && ComputerChoice == "paper"))
    {
        PlayerScore += 1;
    }
    else
    {
        ComputerScore += 1;
    }
}
