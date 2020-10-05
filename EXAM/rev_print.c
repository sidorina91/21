#include <unistd.h>

int main (int ac, char **av)
{
    int i;
    i = 0;
    int j;
    j = 0;

    if (ac == 2)
    {
        while (av[1][i] != '\0')
        {
            i++;
        }
        for (j = i - 1; j >= 0; j--)
        {
            write(1, &av[1][j], 1);
        }
        
    }
    write(1, "\n", 1);
    return (0);
}