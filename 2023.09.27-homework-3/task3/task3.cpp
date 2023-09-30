#include <iostream>

int main()
{
    long int x = 0;
    long int res = 0;
    long int opposite = 0;
    std::cin >> x;

    for (long int i = 1; i <= x/2 + 1; i++)
    {   
        //прервыание цикла, если из x не извлекается квадрат
        if (opposite == i) break;
        if (x % i == 0)
        {
            opposite = x / i;
            res ++;
            //std::cout << i << " " << opposite << std::endl; 
        }
        //прерывание цикла, когда из x извлекается квадрат
        if (opposite == i) break;
    }

    if (x == 1)
    {
        std::cout << 1;
    }
     //умножение результата на 2 и вычитание повторяющегося делителя
    else if (opposite * opposite == x)
    {
        std::cout << res * 2 - 1;
    }
    //результат если повторяющихся делителей нет (при неизвлечимом корне из x)
    else
    {
        std::cout << res * 2;
    }
    return EXIT_SUCCESS;
}