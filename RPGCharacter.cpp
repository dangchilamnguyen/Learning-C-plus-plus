#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
// Player struct
struct Player
{
    std::string Name;
    int MaxHealth;
    int CurrentHealth;
    int Damage;
    int HealAmount;
};

// Enemy struct
struct Enemy
{
    std::string Name;
    int MaxHealth;
    int CurrentHealth;
    int Damage;
    int CriticalChance;
};

// Menu enum
enum MenuOption
{
    PRINT_PLAYER = 1,
    PRINT_ENEMY,
    BATTLE_ENEMY,
    QUIT
};

// Function call
void printPlayer(const Player &PlayerData);
void printEnemy(const Enemy &EnemyData);
void playerAttack(const Player &PlayerData, Enemy &EnemyData);
void playerHeal(Player &PlayerData);
void enemyAttack(const Enemy &EnemyData, Player &PlayerData);
void battle(Player &PlayerData, Enemy &EnemyData);

// Main
int main()
{
    srand(time(0));

    Player PlayerData = {"Aaron", 100, 100, 30, 30};
    Enemy EnemyData = {"Troll", 100, 100, 30, 25};

    int Choice = 0;

    std::cout << "======= RPG CHARACTER =======\n";

    do
    {
        std::cout << "\n1. Print player details\n";
        std::cout << "2. Print enemy details\n";
        std::cout << "3. Battle enemy\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";

        std::cin >> Choice;
        // Fix infinite loop if user enters letter
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (Choice)
        {
        case PRINT_PLAYER:
            printPlayer(PlayerData);
            break;

        case PRINT_ENEMY:
            printEnemy(EnemyData);
            break;

        case BATTLE_ENEMY:
            battle(PlayerData, EnemyData);
            break;

        case QUIT:
            std::cout << "Goodbye!\n";
            break;

        default:
            std::cout << "Invalid choice! Please enter again.\n";
            break;
        }

    } while (Choice != QUIT &&
             PlayerData.CurrentHealth > 0 &&
             EnemyData.CurrentHealth > 0);

    if (PlayerData.CurrentHealth <= 0)
    {
        std::cout << "Hero " << PlayerData.Name << " has been defeated. Game over!\n";
    }
    else if (EnemyData.CurrentHealth <= 0)
    {
        std::cout << "Enemy " << EnemyData.Name << " faints. Victory!\n";
    }

    return 0;
}

// Player details function
void printPlayer(const Player &PlayerData)
{
    std::cout << "\nPlayer: " << PlayerData.Name << '\n';
    std::cout << "HP: " << PlayerData.CurrentHealth
              << "/" << PlayerData.MaxHealth << '\n';
    std::cout << "Damage per attack: " << PlayerData.Damage << '\n';
    std::cout << "Heal ability: " << PlayerData.HealAmount << '\n';
}

// Enemy details function
void printEnemy(const Enemy &EnemyData)
{
    std::cout << "\nEnemy: " << EnemyData.Name << '\n';
    std::cout << "HP: " << EnemyData.CurrentHealth
              << "/" << EnemyData.MaxHealth << '\n';
    std::cout << "Damage per attack: " << EnemyData.Damage << '\n';
    std::cout << "Critical hit chance: "
              << EnemyData.CriticalChance << "%\n";
}

// Player attack function
void playerAttack(const Player &PlayerData, Enemy &EnemyData)
{
    EnemyData.CurrentHealth -= PlayerData.Damage;

    if (EnemyData.CurrentHealth < 0)
    {
        EnemyData.CurrentHealth = 0;
    }

    std::cout << "You hit "
              << EnemyData.Name
              << " for "
              << PlayerData.Damage
              << " damage!\n";
}

// Player heal function
void playerHeal(Player &PlayerData)
{
    if (PlayerData.CurrentHealth == PlayerData.MaxHealth)
    {
        std::cout << "Your health is already full.\n";
        return;
    }

    PlayerData.CurrentHealth += PlayerData.HealAmount;

    if (PlayerData.CurrentHealth > PlayerData.MaxHealth)
    {
        PlayerData.CurrentHealth = PlayerData.MaxHealth;
    }

    std::cout << "You heal for "
              << PlayerData.HealAmount
              << " HP!\n";
}

// Enemy attack function
void enemyAttack(const Enemy &EnemyData, Player &PlayerData)
{
    int AttackDamage = EnemyData.Damage;
    int RandomNumber = rand() % 100;

    if (RandomNumber < EnemyData.CriticalChance)
    {
        AttackDamage = AttackDamage * 2;
        std::cout << "Critical hit! ";
    }

    PlayerData.CurrentHealth -= AttackDamage;

    if (PlayerData.CurrentHealth < 0)
    {
        PlayerData.CurrentHealth = 0;
    }

    std::cout << EnemyData.Name
              << " hits you for "
              << AttackDamage
              << " damage!\n";
}

// Option while battling
void battle(Player &PlayerData, Enemy &EnemyData)
{
    char Action;

    while (PlayerData.CurrentHealth > 0 &&
           EnemyData.CurrentHealth > 0)
    {
        std::cout << "\n----------------------------------------\n";

        std::cout << "Player has "
                  << PlayerData.CurrentHealth
                  << "/"
                  << PlayerData.MaxHealth
                  << " HP.\n";

        std::cout << "Enemy "
                  << EnemyData.Name
                  << " has "
                  << EnemyData.CurrentHealth
                  << "/"
                  << EnemyData.MaxHealth
                  << " HP.\n";

        std::cout << "What is your next move? (a = attack, h = heal): ";
        std::cin >> Action;

        if (Action == 'a' || Action == 'A')
        {
            playerAttack(PlayerData, EnemyData);
        }
        else if (Action == 'h' || Action == 'H')
        {
            playerHeal(PlayerData);
        }
        else
        {
            std::cout << "Invalid choice! Please enter again.\n";
            continue;
        }

        if (EnemyData.CurrentHealth <= 0)
        {
            return;
        }

        enemyAttack(EnemyData, PlayerData);

        if (PlayerData.CurrentHealth <= 0)
        {
            return;
        }
    }
}
