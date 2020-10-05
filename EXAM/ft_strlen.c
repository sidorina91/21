#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return(i);
}

// int main ()
// {
//     char s[] = "pony";
//     printf("%d", ft_strlen(s));
//     return (0);
// }