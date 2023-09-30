#include <iostream>

int main()
{
    long int curr = 1;
    long int next = 1;
    long int res = 1;
    long int n = 0;
    long int i = 0;
    std::cin >> n;
    while(i < n - 2)
    {
        res = curr + next;
        curr = next;
        next = res;
        i++;
    }
    std::cout << res << std::endl;
    return EXIT_SUCCESS;
}