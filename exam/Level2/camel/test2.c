#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char    *str;
    char    *result;
    int     i;
    int     j;
    int     len;
    int     extra;

    if (argc != 2 || !argv[1])
    {
        write(1, "\n", 1);
        return (0);
    }

    str = argv[1];
    len = 0;
    extra = 0;
    while (str[len])
    {
        if (str[len] >= 'A' && str[len] <= 'Z')
            extra++;
        len++;
    }

    result = malloc(sizeof(char) * (len + extra + 1));
    if (!result)
        return (1);

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            /* Only add '_' if we have already written at least one character */
            if (j > 0)
                result[j++] = '_';
            result[j++] = str[i] + 32;  /* to lowercase */
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            result[j++] = str[i];
        }
        /* Non-letter characters (spaces, etc.) are simply skipped */
        i++;
    }
    result[j] = '\0';

    /* Output the result */
    j = 0;
    while (result[j])
        write(1, &result[j++], 1);
    write(1, "\n", 1);

    free(result);
    return (0);
}
