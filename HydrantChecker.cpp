#include "splashkit.h"
#include <iostream>
#include <string>

// Max 100 hydrants
const int MAX_HYDRANTS = 100;

// Hydrant struct
struct hydrant
{
    int id;
    std::string location;

    int install_day, install_month, install_year;
    int next_day, next_month, next_year;

    bool has_inspection;
    int last_day, last_month, last_year;

    std::string defect;
    double water_pressure;
    bool major_issue;
};

// Function declaration
void add_hydrant(hydrant hydrants[], int &hydrant_count, int current_day, int current_month, int current_year);
void view_hydrants(hydrant hydrants[], int hydrant_count);
void inspect_hydrant(hydrant hydrants[], int hydrant_count, int current_day, int current_month, int current_year);
void view_due_hydrants(hydrant hydrants[], int hydrant_count, int current_day, int current_month, int current_year);

int find_hydrant(hydrant hydrants[], int hydrant_count, int id);
int days_in_month(int month, int year);

bool valid_date(int day, int month, int year);
bool date_on_or_before(int day1, int month1, int year1, int day2, int month2, int year2);

void add_six_months(int &day, int &month, int &year);
void report_to_cfa(hydrant &hydrant_data);

// Main
int main()
{
    hydrant hydrants[MAX_HYDRANTS];

    int hydrant_count = 0;
    int choice;

    int current_day;
    int current_month;
    int current_year;

    while (true)
    {
        write("Enter current day: ");
        std::cin >> current_day;

        write("Enter current month: ");
        std::cin >> current_month;

        write("Enter current year: ");
        std::cin >> current_year;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            write_line("Error: Please enter numbers.");
            continue;
        }

        if (valid_date(current_day, current_month, current_year))
        {
            break;
        }
        else
        {
            write_line("Error: Invalid date.");
        }
    }

    while (true)
    {
        write_line("");
        write_line("========== HYDRANT SYSTEM ==========");
        write_line("1. Add Hydrant");
        write_line("2. View Hydrants");
        write_line("3. Perform Inspection");
        write_line("4. View Due Inspections");
        write_line("5. Exit");

        write("Enter choice: ");
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            write_line("Error: Please enter a number.");
            continue;
        }

        switch (choice)
        {
        case 1:
            add_hydrant(hydrants, hydrant_count, current_day, current_month, current_year);
            break;

        case 2:
            view_hydrants(hydrants, hydrant_count);
            break;

        case 3:
            inspect_hydrant(hydrants, hydrant_count, current_day, current_month, current_year);
            break;

        case 4:
            view_due_hydrants(hydrants, hydrant_count, current_day, current_month, current_year);
            break;

        case 5:
            write_line("Goodbye");
            return 0;

        default:
            write_line("Invalid choice.");
        }
    }
}

// Function to find hydrant with its ID
int find_hydrant(hydrant hydrants[], int hydrant_count, int id)
{
    for (int i = 0; i < hydrant_count; i++)
    {
        if (hydrants[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

// Function to add hydrant
void add_hydrant(hydrant hydrants[], int &hydrant_count, int current_day, int current_month, int current_year)
{
    if (hydrant_count >= MAX_HYDRANTS)
    {
        write_line("Maximum number of hydrants reached.");
        return;
    }

    hydrant new_hydrant;

    write("Enter Hydrant ID: ");
    std::cin >> new_hydrant.id;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        write_line("Error: ID must be a number.");
        return;
    }

    if (find_hydrant(hydrants, hydrant_count, new_hydrant.id) != -1)
    {
        write_line("Error: ID already exists.");
        return;
    }

    std::cin.ignore(10000, '\n');

    write("Enter location: ");
    std::getline(std::cin, new_hydrant.location);

    if (new_hydrant.location == "")
    {
        write_line("Error: Location cannot be empty.");
        return;
    }

    write("Enter installation day: ");
    std::cin >> new_hydrant.install_day;

    write("Enter installation month: ");
    std::cin >> new_hydrant.install_month;

    write("Enter installation year: ");
    std::cin >> new_hydrant.install_year;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        write_line("Error: Invalid date input.");
        return;
    }

    if (valid_date(new_hydrant.install_day, new_hydrant.install_month, new_hydrant.install_year) == false)
    {
        write_line("Error: Invalid installation date.");
        return;
    }

    if (date_on_or_before(new_hydrant.install_day, new_hydrant.install_month, new_hydrant.install_year,
                          current_day, current_month, current_year) == false)
    {
        write_line("Error: Installation date cannot be in the future.");
        return;
    }

    new_hydrant.next_day = new_hydrant.install_day;
    new_hydrant.next_month = new_hydrant.install_month;
    new_hydrant.next_year = new_hydrant.install_year;

    add_six_months(new_hydrant.next_day, new_hydrant.next_month, new_hydrant.next_year);

    new_hydrant.has_inspection = false;
    new_hydrant.last_day = 0;
    new_hydrant.last_month = 0;
    new_hydrant.last_year = 0;
    new_hydrant.defect = "Not checked";
    new_hydrant.water_pressure = 0;
    new_hydrant.major_issue = false;

    hydrants[hydrant_count] = new_hydrant;
    hydrant_count++;

    write_line("Hydrant added successfully.");

    write("First inspection due: ");
    write(new_hydrant.next_day);
    write("/");
    write(new_hydrant.next_month);
    write("/");
    write_line(new_hydrant.next_year);
}

// Function to view hydrant details
void view_hydrants(hydrant hydrants[], int hydrant_count)
{
    if (hydrant_count == 0)
    {
        write_line("No hydrants have been added.");
        return;
    }

    for (int i = 0; i < hydrant_count; i++)
    {
        write_line("");
        write("Hydrant ID: ");
        write_line(hydrants[i].id);

        write("Location: ");
        write_line(hydrants[i].location);

        write("Next inspection: ");
        write(hydrants[i].next_day);
        write("/");
        write(hydrants[i].next_month);
        write("/");
        write_line(hydrants[i].next_year);

        if (hydrants[i].has_inspection)
        {
            write("Last inspection: ");
            write(hydrants[i].last_day);
            write("/");
            write(hydrants[i].last_month);
            write("/");
            write_line(hydrants[i].last_year);

            write("Defect: ");
            write_line(hydrants[i].defect);

            write("Water pressure: ");
            write_line(hydrants[i].water_pressure);

            if (hydrants[i].major_issue)
            {
                write_line("Major issue: Yes");
            }
            else
            {
                write_line("Major issue: No");
            }
        }
        else
        {
            write_line("Never inspected");
        }
    }
}

// Function to add inspection details
void inspect_hydrant(hydrant hydrants[], int hydrant_count, int current_day, int current_month, int current_year)
{
    if (hydrant_count == 0)
    {
        write_line("No hydrants available. Add a hydrant first.");
        return;
    }

    int id;
    write("Enter Hydrant ID: ");
    std::cin >> id;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        write_line("Error: ID must be a number.");
        return;
    }

    int index = find_hydrant(hydrants, hydrant_count, id);

    if (index == -1)
    {
        write_line("Hydrant not found.");
        return;
    }

    std::string new_defect;
    double new_water_pressure;
    bool new_major_issue;
    char major;

    std::cin.ignore(10000, '\n');

    write("Enter defect (None if no defect): ");
    std::getline(std::cin, new_defect);

    if (new_defect == "")
    {
        write_line("Error: Defect cannot be empty.");
        return;
    }

    write("Enter water pressure: ");
    std::cin >> new_water_pressure; // Store in temporary variable to prevent false new inspection details

    if (std::cin.fail() || new_water_pressure < 0)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        write_line("Error: Invalid water pressure.");
        return;
    }

    write("Major issue? (Y/N): ");
    std::cin >> major;
    std::cin.ignore(10000, '\n');

    if (major == 'Y' || major == 'y')
    {
        new_major_issue = true;
    }
    else if (major == 'N' || major == 'n')
    {
        new_major_issue = false;
    }
    else
    {
        write_line("Error: Please enter Y or N.");
        return;
    }

    hydrants[index].defect = new_defect;
    hydrants[index].water_pressure = new_water_pressure;
    hydrants[index].major_issue = new_major_issue;

    hydrants[index].has_inspection = true;
    hydrants[index].last_day = current_day;
    hydrants[index].last_month = current_month;
    hydrants[index].last_year = current_year;

    while (date_on_or_before(hydrants[index].next_day, hydrants[index].next_month, hydrants[index].next_year,
                             current_day, current_month, current_year))
    {
        add_six_months(hydrants[index].next_day, hydrants[index].next_month, hydrants[index].next_year);
    }

    write_line("Inspection recorded successfully.");

    if (hydrants[index].major_issue)
    {
        report_to_cfa(hydrants[index]);
    }
}

// Function to report to CFA
void report_to_cfa(hydrant &hydrant_data)
{
    write_line("");
    write_line("===== URGENT CFA REPORT =====");

    write("Hydrant ID: ");
    write_line(hydrant_data.id);

    write("Location: ");
    write_line(hydrant_data.location);

    write("Inspection date: ");
    write(hydrant_data.last_day);
    write("/");
    write(hydrant_data.last_month);
    write("/");
    write_line(hydrant_data.last_year);

    write("Defect: ");
    write_line(hydrant_data.defect);

    write("Water pressure: ");
    write_line(hydrant_data.water_pressure);

    write_line("Major issue reported to CFA.");
}

// View next inspection date
void view_due_hydrants(hydrant hydrants[], int hydrant_count, int current_day, int current_month, int current_year)
{
    if (hydrant_count == 0)
    {
        write_line("No hydrants available. Add a hydrant first.");
        return;
    }

    bool found = false;

    for (int i = 0; i < hydrant_count; i++)
    {
        if (date_on_or_before(hydrants[i].next_day, hydrants[i].next_month, hydrants[i].next_year,
                              current_day, current_month, current_year))
        {
            found = true;

            write("Hydrant ");
            write(hydrants[i].id);
            write(" at ");
            write(hydrants[i].location);
            write(" is due on ");

            write(hydrants[i].next_day);
            write("/");
            write(hydrants[i].next_month);
            write("/");
            write_line(hydrants[i].next_year);
        }
    }

    if (found == false)
    {
        write_line("No inspections are currently due.");
    }
}

// Function to check date eligibility ( leap year and day in month)
int days_in_month(int month, int year)
{
    if (month == 2)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            return 29;
        }

        return 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }

    return 31;
}

// Function to check date eligibility (check for unrealistic date)
bool valid_date(int day, int month, int year)
{
    if (year <= 0 || month < 1 || month > 12)
    {
        return false;
    }

    if (day < 1 || day > days_in_month(month, year))
    {
        return false;
    }

    return true;
}

// Function to calculate next inspection date
void add_six_months(int &day, int &month, int &year)
{
    month = month + 6;

    if (month > 12)
    {
        month = month - 12;
        year++;
    }

    if (day > days_in_month(month, year))
    {
        day = days_in_month(month, year);
    }
}

// Function to prevent inaccurate hydrant installation date
bool date_on_or_before(int day1, int month1, int year1, int day2, int month2, int year2)
{
    if (year1 < year2)
    {
        return true;
    }
    else if (year1 > year2)
    {
        return false;
    }

    if (month1 < month2)
    {
        return true;
    }
    else if (month1 > month2)
    {
        return false;
    }

    return day1 <= day2;
}