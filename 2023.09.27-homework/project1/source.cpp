#include <iostream>

int main(int argc, char *argv[])
{
    long int sec = 0;
    // num - цифра которую нам нужно выводить
    long int num = 1;
    // counter - счетчик, сколько цифр равных num нам нужно вывести
    long int counter = 1;
    std::cin >> sec;
    for (long int i = 1; i <= sec; i++)
    {
        if (counter != num)
        {
            counter++;
            std::cout << num << " ";
        }
        else
        {
            std::cout << num << " ";
            counter = 1;
            num++;
        }
    }
    return EXIT_SUCCESS;
}