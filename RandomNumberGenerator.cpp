#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib> // rand() srand()

int main()
{
    srand(time(NULL));
    int num = (rand() % 7) + 1; // number 6 -> 6 numbers 0->6
    // number 100 -> 100 numbers 0->9
    std::cout << num;
    return 0;
}
