#include "splashkit.h"

// Maximum number of vehicles
const int MAX_VEHICLES = 100;

// Menu options
enum menu_option
{
    ADD_VEHICLE = 1,
    REMOVE_VEHICLE = 2,
    ADVANCE_CLOCK = 3,
    PRINT_ALL = 4,
    PRINT_SPECIFIC = 5,
    QUIT = 6
};

// Vehicle struct
struct vehicle
{
    string registration;
    string type;
    int hours;
};

// Function declarations
void show_menu(int vehicle_count);
vehicle input_vehicle();
int find_vehicle(vehicle vehicles[], int vehicle_count, string registration);
double calculate_fee(vehicle vehicle_data);
void add_vehicle(vehicle vehicles[], int &vehicle_count);
void remove_vehicle(vehicle vehicles[], int &vehicle_count);
void advance_clock(vehicle vehicles[], int vehicle_count);
void print_vehicle(vehicle vehicle_data);
void print_all_vehicles(vehicle vehicles[], int vehicle_count);
void print_specific_vehicle(vehicle vehicles[], int vehicle_count);

int main()
{
    vehicle vehicles[MAX_VEHICLES];

    int vehicle_count = 3;
    int option = 0;

    // Vehicles already parked when the program starts
    vehicles[0] = {"ABC123", "car", 3};
    vehicles[1] = {"VAN222", "van", 5};
    vehicles[2] = {"TRK999", "truck", 2};

    write_line("Welcome to the Parking Garage!");
    write_line("");

    while (option != QUIT)
    {
        show_menu(vehicle_count);

        write("Option: ");
        option = convert_to_integer(read_line());

        switch (option)
        {
        case ADD_VEHICLE:
            add_vehicle(vehicles, vehicle_count);
            break;

        case REMOVE_VEHICLE:
            remove_vehicle(vehicles, vehicle_count);
            break;

        case ADVANCE_CLOCK:
            advance_clock(vehicles, vehicle_count);
            break;

        case PRINT_ALL:
            print_all_vehicles(vehicles, vehicle_count);
            break;

        case PRINT_SPECIFIC:
            print_specific_vehicle(vehicles, vehicle_count);
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

// Function to show the menu
void show_menu(int vehicle_count)
{
    write_line("There are currently " + to_string(vehicle_count) +
               " vehicles parked, and " +
               to_string(MAX_VEHICLES - vehicle_count) +
               " free spots available.");

    write_line("1. Add vehicle");
    write_line("2. Remove vehicle");
    write_line("3. Advance the clock");
    write_line("4. Print all vehicles");
    write_line("5. Print specific vehicle");
    write_line("6. Quit");
    write_line("");
}

// Function to input a vehicle
vehicle input_vehicle()
{
    vehicle new_vehicle;

    write("Enter registration number: ");
    new_vehicle.registration = read_line();

    write("Enter vehicle type (car, van, truck): ");
    new_vehicle.type = read_line();

    while (new_vehicle.type != "car" &&
           new_vehicle.type != "van" &&
           new_vehicle.type != "truck")
    {
        write_line("Invalid vehicle type. Please try again.");

        write("Enter vehicle type (car, van, truck): ");
        new_vehicle.type = read_line();
    }

    new_vehicle.hours = 0;

    return new_vehicle;
}

// Function to find a vehicle
int find_vehicle(vehicle vehicles[], int vehicle_count, string registration)
{
    for (int i = 0; i < vehicle_count; i++)
    {
        if (vehicles[i].registration == registration)
        {
            return i;
        }
    }

    return -1;
}

// Function to calculate parking fee
double calculate_fee(vehicle vehicle_data)
{
    double rate = 0;
    double cost;

    if (vehicle_data.type == "car")
    {
        rate = 4.0;
    }
    else if (vehicle_data.type == "van")
    {
        rate = 6.0;
    }
    else
    {
        rate = 15.0;
    }

    cost = rate * vehicle_data.hours;

    if (vehicle_data.hours > 8)
    {
        cost = cost + 25.0;
    }

    return cost;
}

// Function to add a vehicle
void add_vehicle(vehicle vehicles[], int &vehicle_count)
{
    vehicle new_vehicle;

    if (vehicle_count >= MAX_VEHICLES)
    {
        write_line("The parking garage is full.");
        write_line("");
        return;
    }

    new_vehicle = input_vehicle();

    vehicles[vehicle_count] = new_vehicle;
    vehicle_count++;

    write_line("Vehicle added successfully.");
    write_line("");
}

// Function to remove a vehicle
void remove_vehicle(vehicle vehicles[], int &vehicle_count)
{
    string registration;
    int index;
    double cost;

    write("Enter registration number: ");
    registration = read_line();

    index = find_vehicle(vehicles, vehicle_count, registration);

    if (index == -1)
    {
        write_line("There is no vehicle parked with registration '" +
                   registration + "'.");

        write_line("");
        return;
    }

    cost = calculate_fee(vehicles[index]);

    write_line("Parking fee is: $" + to_string(cost));

    // Move later vehicles one position left
    for (int i = index; i < vehicle_count - 1; i++)
    {
        vehicles[i] = vehicles[i + 1];
    }

    vehicle_count--;

    write_line("Vehicle removed successfully.");
    write_line("");
}

// Function to advance the clock
void advance_clock(vehicle vehicles[], int vehicle_count)
{
    int hours;

    write("Enter number of hours to advance: ");
    hours = convert_to_integer(read_line());

    while (hours <= 0)
    {
        write_line("Please enter a number greater than 0.");

        write("Enter number of hours to advance: ");
        hours = convert_to_integer(read_line());
    }

    for (int i = 0; i < vehicle_count; i++)
    {
        vehicles[i].hours = vehicles[i].hours + hours;
    }

    write_line("The clock has been advanced by " +
               to_string(hours) + " hours.");

    write_line("");
}

// Function to print one vehicle
void print_vehicle(vehicle vehicle_data)
{
    write_line("Vehicle '" + vehicle_data.registration + "':");
    write_line("Type: " + vehicle_data.type);
    write_line("Hours parked: " + to_string(vehicle_data.hours));
    write_line("Current parking cost: $" +
               to_string(calculate_fee(vehicle_data)));

    write_line("");
}

// Function to print all vehicles
void print_all_vehicles(vehicle vehicles[], int vehicle_count)
{
    if (vehicle_count == 0)
    {
        write_line("There are no vehicles parked.");
        write_line("");
        return;
    }

    for (int i = 0; i < vehicle_count; i++)
    {
        print_vehicle(vehicles[i]);
    }
}

// Function to print a specific vehicle
void print_specific_vehicle(vehicle vehicles[], int vehicle_count)
{
    string registration;
    int index;

    write("Enter registration plate: ");
    registration = read_line();

    index = find_vehicle(vehicles, vehicle_count, registration);

    if (index == -1)
    {
        write_line("There is no vehicle parked with registration '" +
                   registration + "'.");

        write_line("");
    }
    else
    {
        print_vehicle(vehicles[index]);
    }
}