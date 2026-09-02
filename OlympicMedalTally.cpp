#include "splashkit.h"

string input_country_name(string country_number);
int input_medal(string medal);

int total_medals(int gold, int silver, int bronze);

void print_scoreboard(
    string country1,
    int gold1,
    int silver1,
    int bronze1,
    string country2,
    int gold2,
    int silver2,
    int bronze2
);

void show_menu(string country1, string country2);

int update_medal(string country, string medal);


int main()
{
    string country1;
    string country2;

    int gold1;
    int silver1;
    int bronze1;

    int gold2;
    int silver2;
    int bronze2;

    int option = 0;

    write_line("Welcome to the Olympic Medal Tally!");
    write_line("");

    // Input country 1
    write_line("Enter country one details:");

    country1 = input_country_name("one");

    gold1 = input_medal("Gold");
    silver1 = input_medal("Silver");
    bronze1 = input_medal("Bronze");

    write_line("");

    // Input country 2
    write_line("Enter country two details:");

    country2 = input_country_name("two");

    gold2 = input_medal("Gold");
    silver2 = input_medal("Silver");
    bronze2 = input_medal("Bronze");

    write_line("");

    // Print first scoreboard
    print_scoreboard(
        country1,
        gold1,
        silver1,
        bronze1,
        country2,
        gold2,
        silver2,
        bronze2
    );

    // Main menu
    while (option != 8)
    {
        show_menu(country1, country2);

        write("Option: ");
        option = convert_to_integer(read_line());

        switch (option)
        {
        case 1:
            gold1 = update_medal(country1, "gold");

            print_scoreboard(
                country1,
                gold1,
                silver1,
                bronze1,
                country2,
                gold2,
                silver2,
                bronze2
            );
            break;

        case 2:
            silver1 = update_medal(country1, "silver");

            print_scoreboard(
                country1,
                gold1,
                silver1,
                bronze1,
                country2,
                gold2,
                silver2,
                bronze2
            );
            break;

        case 3:
            bronze1 = update_medal(country1, "bronze");

            print_scoreboard(
                country1,
                gold1,
                silver1,
                bronze1,
                country2,
                gold2,
                silver2,
                bronze2
            );
            break;

        case 4:
            gold2 = update_medal(country2, "gold");

            print_scoreboard(
                country1,
                gold1,
                silver1,
                bronze1,
                country2,
                gold2,
                silver2,
                bronze2
            );
            break;

        case 5:
            silver2 = update_medal(country2, "silver");

            print_scoreboard(
                country1,
                gold1,
                silver1,
                bronze1,
                country2,
                gold2,
                silver2,
                bronze2
            );
            break;

        case 6:
            bronze2 = update_medal(country2, "bronze");

            print_scoreboard(
                country1,
                gold1,
                silver1,
                bronze1,
                country2,
                gold2,
                silver2,
                bronze2
            );
            break;

        case 7:
            print_scoreboard(
                country1,
                gold1,
                silver1,
                bronze1,
                country2,
                gold2,
                silver2,
                bronze2
            );
            break;

        case 8:
            write_line("Goodbye!");
            break;

        default:
            write_line("Invalid option.");
            write_line("");
            break;
        }
    }

    return 0;
}


string input_country_name(string country_number)
{
    string name;

    write("Name: ");
    name = read_line();

    return name;
}


int input_medal(string medal)
{
    int amount;

    write(medal + ": ");
    amount = convert_to_integer(read_line());

    return amount;
}


int total_medals(int gold, int silver, int bronze)
{
    return gold + silver + bronze;
}


void print_scoreboard(
    string country1,
    int gold1,
    int silver1,
    int bronze1,
    string country2,
    int gold2,
    int silver2,
    int bronze2
)
{
    int total1;
    int total2;

    total1 = total_medals(gold1, silver1, bronze1);
    total2 = total_medals(gold2, silver2, bronze2);

    write_line("");
    write_line("Calculating scoreboard...");
    write_line("");

    if (total1 > total2)
    {
        write_line(country1 + " is in the lead.");
        write_line(
            country1 + ": " +
            to_string(total1) +
            " medals total."
        );

        write_line(
            country2 + ": " +
            to_string(total2) +
            " medals total."
        );
    }
    else if (total2 > total1)
    {
        write_line(country2 + " is in the lead.");
        write_line(
            country2 + ": " +
            to_string(total2) +
            " medals total."
        );

        write_line(
            country1 + ": " +
            to_string(total1) +
            " medals total."
        );
    }
    else
    {
        if (gold1 > gold2)
        {
            write_line(
                country1 +
                " is in the lead (more gold medals)."
            );

            write_line(
                country1 + ": " +
                to_string(total1) +
                " medals total."
            );

            write_line(
                country2 + ": " +
                to_string(total2) +
                " medals total."
            );
        }
        else if (gold2 > gold1)
        {
            write_line(
                country2 +
                " is in the lead (more gold medals)."
            );

            write_line(
                country2 + ": " +
                to_string(total2) +
                " medals total."
            );

            write_line(
                country1 + ": " +
                to_string(total1) +
                " medals total."
            );
        }
        else
        {
            write_line("The countries are tied.");

            write_line(
                country1 + ": " +
                to_string(total1) +
                " medals total."
            );

            write_line(
                country2 + ": " +
                to_string(total2) +
                " medals total."
            );
        }
    }

    write_line("");
}


void show_menu(string country1, string country2)
{
    write_line("Select from the following menu options:");

    write_line(
        "1. Update " +
        country1 +
        " gold"
    );

    write_line(
        "2. Update " +
        country1 +
        " silver"
    );

    write_line(
        "3. Update " +
        country1 +
        " bronze"
    );

    write_line(
        "4. Update " +
        country2 +
        " gold"
    );

    write_line(
        "5. Update " +
        country2 +
        " silver"
    );

    write_line(
        "6. Update " +
        country2 +
        " bronze"
    );

    write_line("7. Print scoreboard");
    write_line("8. Quit");
    write_line("");
}


int update_medal(string country, string medal)
{
    int amount;

    write(
        "Enter how many " +
        medal +
        " medals " +
        country +
        " has: "
    );

    amount = convert_to_integer(read_line());

    return amount;
}