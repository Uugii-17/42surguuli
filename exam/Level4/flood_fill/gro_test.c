#include <stdlib.h>  // for malloc/free
#include <stdio.h>   // for printf (testing only)

// Define t_point
typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

// The recursive fill helper
void    fill(char **tab, t_point size, t_point cur, char to_fill)
{
    // Boundary check
    if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
        return;
    
    // Not the target char or already filled
    if (tab[cur.y][cur.x] != to_fill)
        return;
    
    // Fill
    tab[cur.y][cur.x] = 'F';
    
    // Recurse in 4 directions
    fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);    // up
    fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);    // down
    fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);    // left
    fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);    // right
}

// The main flood_fill function
void    flood_fill(char **tab, t_point size, t_point begin)
{
    if (!tab || begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
        return;

    char to_fill = tab[begin.y][begin.x];
    if (to_fill == 'F' || to_fill == '\0')  // Avoid filling empty or already F
        return;

    fill(tab, size, begin, to_fill);
}

// Example main() for testing (not required for submission, but useful for local checks)
int main(void)
{
    // Example 4x4 grid
    int width = 4, height = 4;
    char **tab = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        tab[i] = malloc((width + 1) * sizeof(char));  // +1 for null terminator if needed
        // Sample grid: 1s to fill, 0s as walls
        snprintf(tab[i], width + 1, "1110");
        if (i == 1) snprintf(tab[i], width + 1, "1010");
        if (i == 2) snprintf(tab[i], width + 1, "1110");
        if (i == 3) snprintf(tab[i], width + 1, "0000");
    }

    // Print original
    printf("Original:\n");
    for (int y = 0; y < height; y++)
    {
        printf("%s\n", tab[y]);
    }

    t_point size = {width, height};
    t_point begin = {1, 1};  // Start at '1' in the middle

    flood_fill(tab, size, begin);

    // Print after fill
    printf("\nAfter flood_fill from (1,1):\n");
    for (int y = 0; y < height; y++)
    {
        printf("%s\n", tab[y]);
    }

    // Cleanup
    for (int i = 0; i < height; i++)
        free(tab[i]);
    free(tab);

    return 0;
}