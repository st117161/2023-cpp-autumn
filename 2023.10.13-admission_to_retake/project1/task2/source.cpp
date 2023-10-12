#include <iostream>

typedef unsigned int uint;

int main(int argc, char *argv[])
{
    const int BITS = sizeof(uint) * 8;

    uint n = 0;
    // 898989898989 - интересное число на ввод
    std::cin >> n;

    {
        std::cout << "0b ";
        for (int i = BITS - 1; i >= 0; --i)
        {
            std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
        }
        std::cout << std::endl;
    }

    {
        if (n == 0)
        {
            n = ~n;
        }
        else
        {
            int start = BITS - 1;
            int end = 0;
            while ((n >> start & 1) == 0)
            {
                start--;
            }
            while ((n >> end & 1) == 0)
            {
                end++;
            }

            start--;
            end++;
            uint mask = 0;
            mask = ~mask;
            mask = (mask >> (start - end + 1));
            mask = ~mask;
            mask = (mask >> (BITS - start - 1));
            n = n ^ mask;

            mask = 0;
            for (int i = end; i <= start; ++i)
            {
                mask = mask | (1 << i);
            }

            {
                std::cout << "0b ";
                for (int i = BITS - 1; i >= 0; --i)
                {
                    std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
                }
                std::cout << std::endl;
            }
        }
    }
    return EXIT_SUCCESS;
}