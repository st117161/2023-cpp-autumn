#include <iostream>
#include <cstdlib>

int main(int argc, char **)
{
    int element = 0;
    int n = 0;
    std::cin >> n;
    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> element;
        *(a + i) = element;
    }

    for (int i = 0; i < n; i += 2)
    {
        std::cout << *(a + i) << " ";
    }
    std::cout << std::endl;

    free(a);
}
