#include <unistd.h>

int main()
{
    char z;
    char y;
    z = 'z';
    y = 'Y';
    while (y >= 'A')
    {
        write(1, &z, 1);
        write(1, &y, 1);
        z = z - 2;
        y = y - 2;
    }
    write(1, "\n", 1);
    return(0);
}