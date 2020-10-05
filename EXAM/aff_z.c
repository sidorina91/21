#include <unistd.h>

int main()
{
    write(1, "z\n", 1);
    return(0);
}