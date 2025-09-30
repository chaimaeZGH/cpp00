
#include <iostream>

int main(int ac, char **av)
{
    int i = 1;
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (i < ac )
        {
            int j = 0;
            while (av[i][j] != '\0')
            {
                std::cout << (char)toupper(av[i][j]);
                j++;
            }
            i++;
        }
    }
    std::cout << '\n';
    return 0;
}