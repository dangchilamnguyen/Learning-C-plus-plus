#include "splashkit.h"

// Create a group of choices for the menu
enum menu_option
{
    BUILD_PIZZA = 1,
    PRINT_RECEIPT = 2,
    QUIT = 3
};

// Pizza structure
struct pizza
{
    string customer_name;
    string size;

    bool cheese;
    bool mushrooms;
    bool onion;
    bool chicken;

    bool delivery;
    bool order;
};

// Function declarations
string input_name();
string input_size();
bool input_topping(string topping);
bool input_delivery();

pizza build_pizza();

double calculate_cost(pizza pizza);

void print_receipt(pizza pizza);
void show_menu();

int main()
{
    pizza pizza;

    int option = 0;

    // No pizza has been ordered yet
    pizza.order = false;

    write_line("Welcome to the Pizzeria!");
    write_line("");

    while (option != QUIT)
    {
        show_menu();

        write("Option: ");
        option = convert_to_integer(read_line());

        switch (option)
        {
        case BUILD_PIZZA:
            pizza = build_pizza();
            break;

        case PRINT_RECEIPT:
            print_receipt(pizza);
            break;

        case QUIT:
            write_line("Goodbye!");
            break;

        default:
            write_line("Invalid option. Please try again.");
            write_line("");
            break;
        }
    }

    return 0;
}

// Function to get customer name
string input_name()
{
    string name;

    write("Enter customer name: ");
    name = read_line();

    return name;
}

// Function to choose pizza size
string input_size()
{
    string size;

    write("Choose pizza size (s = small, m = medium, l = large): ");
    size = read_line();

    while (
        size != "s" &&
        size != "S" &&
        size != "m" &&
        size != "M" &&
        size != "l" &&
        size != "L")
    {
        write_line("Invalid size. Please try again.");

        write("Choose pizza size (s = small, m = medium, l = large): ");
        size = read_line();
    }

    return size;
}

// Function to choose a topping
bool input_topping(string topping)
{
    string answer;

    write(
        "Do you want to add " +
        topping +
        " [y/n]? ");

    answer = read_line();

    while (
        answer != "y" &&
        answer != "Y" &&
        answer != "n" &&
        answer != "N")
    {
        write_line("Please enter y or n.");

        write(
            "Do you want to add " +
            topping +
            " [y/n]? ");

        answer = read_line();
    }

    if (answer == "y" || answer == "Y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to choose delivery
bool input_delivery()
{
    string answer;

    write("Do you need delivery [y/n]? ");
    answer = read_line();

    while (
        answer != "y" &&
        answer != "Y" &&
        answer != "n" &&
        answer != "N")
    {
        write_line("Please enter y or n.");

        write("Do you need delivery [y/n]? ");
        answer = read_line();
    }

    if (answer == "y" || answer == "Y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to build a pizza
pizza build_pizza()
{
    pizza pizza;

    pizza.customer_name = input_name();
    pizza.size = input_size();

    write_line(
        "You can choose the following ingredients to add: "
        "cheese, mushrooms, onion, chicken");

    pizza.cheese = input_topping("cheese");
    pizza.mushrooms = input_topping("mushrooms");
    pizza.onion = input_topping("onion");
    pizza.chicken = input_topping("chicken");

    pizza.delivery = input_delivery();

    pizza.order = true;

    write_line("");
    write_line("Your order has been received!");
    write_line("");

    return pizza;
}

// Function to calculate pizza cost
double calculate_cost(pizza pizza)
{
    double cost;
    double topping_cost;

    if (pizza.size == "s" || pizza.size == "S")
    {
        cost = 8.0;
        topping_cost = 1.0;
    }
    else if (pizza.size == "m" || pizza.size == "M")
    {
        cost = 11.0;
        topping_cost = 1.5;
    }
    else
    {
        cost = 14.0;
        topping_cost = 2.0;
    }

    if (pizza.cheese)
    {
        cost = cost + topping_cost;
    }

    if (pizza.mushrooms)
    {
        cost = cost + topping_cost;
    }

    if (pizza.onion)
    {
        cost = cost + topping_cost;
    }

    if (pizza.chicken)
    {
        cost = cost + topping_cost;
    }

    if (pizza.delivery)
    {
        cost = cost + 15.0;
    }

    return cost;
}

// Function to print the receipt
void print_receipt(pizza pizza)
{
    double cost;

    if (pizza.order == false)
    {
        write_line("No pizzas have been built yet.");
        write_line("");

        return;
    }

    cost = calculate_cost(pizza);

    write_line("");
    write_line("Receipt");
    write_line("Customer: " + pizza.customer_name);

    if (pizza.size == "s" || pizza.size == "S")
    {
        write_line("Pizza size: Small");
    }
    else if (pizza.size == "m" || pizza.size == "M")
    {
        write_line("Pizza size: Medium");
    }
    else
    {
        write_line("Pizza size: Large");
    }

    write("Toppings: ");

    if (pizza.cheese)
    {
        write("cheese ");
    }

    if (pizza.mushrooms)
    {
        write("mushrooms ");
    }

    if (pizza.onion)
    {
        write("onion ");
    }

    if (pizza.chicken)
    {
        write("chicken ");
    }

    write_line("");

    if (pizza.delivery)
    {
        write_line("Delivery: Yes");
    }
    else
    {
        write_line("Delivery: No");
    }

    write_line(
        "Order cost is: $" +
        to_string(cost));

    write_line("");
}

// Function to show the main menu
void show_menu()
{
    write_line("Pizza order menu:");
    write_line("1. Build new pizza");
    write_line("2. Print receipt");
    write_line("3. Quit");
    write_line("");
}