#include <iostream>

int main()
{
    int sysanswer = 0;
    int answer = 0;
    std::cin >> sysanswer;
    std::cin >> answer;

    if ((sysanswer == 1) && (answer == 1))
    {
        std::cout << "YES";
    }
    else if ((sysanswer != 1) && (answer != 1))
    {
        std::cout << "YES";
    }
    else 
    {
        std::cout << "NO";
    }
    return EXIT_SUCCESS;
}   