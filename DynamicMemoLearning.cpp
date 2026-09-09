#include "splashkit.h"

struct dynamic_array
{
    int *data;
    int size;
    int capacity;

    dynamic_array(int start_capacity)
    {
        if (start_capacity < 1)
        {
            start_capacity = 1;
        }

        capacity = start_capacity;
        size = 0;
        data = new int[capacity];
    }

    void add(int value)
    {
        if (size == capacity)
        {
            int new_capacity = capacity * 2;
            int *new_data = new int[new_capacity];

            for (int i = 0; i < size; i++)
            {
                new_data[i] = data[i];
            }

            delete[] data;

            data = new_data;
            capacity = new_capacity;
        }

        data[size] = value;
        size++;
    }

    int &operator[](int index)
    {
        return data[index];
    }

    ~dynamic_array()
    {
        delete[] data;
    }
};
int main()
{
    dynamic_array numbers(3);

    write_line("Adding 10, 20 and 30...");
    numbers.add(10);
    numbers.add(20);
    numbers.add(30);

    write_line("Current values:");
    for (int i = 0; i < numbers.size; i++)
    {
        write_line(to_string(numbers[i]));
    }

    write_line("");
    write_line("Size: " + to_string(numbers.size));
    write_line("Capacity: " + to_string(numbers.capacity));

    write_line("");
    write_line("Adding 40 to resize the array...");
    numbers.add(40);

    write_line("Current values:");
    for (int i = 0; i < numbers.size; i++)
    {
        write_line(to_string(numbers[i]));
    }

    write_line("");
    write_line("Size: " + to_string(numbers.size));
    write_line("Capacity: " + to_string(numbers.capacity));

    write_line("");
    write_line("Changing numbers[0] to 100...");
    numbers[0] = 100;

    write_line("numbers[0] = " + to_string(numbers[0]));

    return 0;
}