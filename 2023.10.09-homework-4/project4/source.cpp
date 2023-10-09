#include <iostream>
#include <cstdlib>

int main(int argc, char **)
{
    int element = 0;
    int max_element = -1000000;
    int n = 0;
    std::cin >> n;
    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> element;
        if (max_element < element)
        {
            max_element = element;
        }
        *(a + i) = element;
    }

    free(a);

    std::cout << max_element;
}
