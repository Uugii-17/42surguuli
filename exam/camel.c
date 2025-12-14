#include <stdlib.h>

int     count_uppercase(char *str)
{
    int count = 0;
    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
            count++;
        str++;
    }
    return (count);
}

char    *camel_to_snake(char *str)
{
    int     i = 0;
    int     j = 0;
    int     upper_count;
    char    *result;

    if (!str)
        return (NULL);
    
    upper_count = count_uppercase(str);
    
    // Original length + number of '_' we will insert + 1 for '\0'
    result = malloc(sizeof(char) * (strlen(str) + upper_count + 1));
    if (!result)
        return (NULL);
    
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            // Insert '_' before uppercase letters (except if it's the first char)
            if (j > 0)  // avoids leading '_' if string starts with uppercase
                result[j++] = '_';
            result[j++] = str[i] + 32;  // convert to lowercase
        }
        else
            result[j++] = str[i];
        i++;
    }
    result[j] = '\0';
    return (result);
}

int     main(int argc, char **argv)
{
    char    *converted;

    if (argc == 2)
    {
        converted = camel_to_snake(argv[1]);
        if (converted)
        {
            int k = 0;
            while (converted[k])
                write(1, &converted[k++], 1);
            free(converted);
        }
    }
    write(1, "\n", 1);
    return (0);
}
