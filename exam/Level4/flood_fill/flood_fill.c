#include "flood_fill.h"
void flood_fill(char **tab, t_point size, t_point begin)
{
   if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
        return;
    char target = tab[begin.y][begin.x];
    if (target == 'F')          // already filled
        return;
    t_point queue[1000000];
    int front = 0;
    int rear = 0;
    queue[rear++] = begin;
    while (front < rear)
    {
        t_point curr = queue[front++];

        if (curr.y < 0 || curr.y >= size.y ||
            curr.x < 0 || curr.x >= size.x || 
            tab[curr.y][curr.x] != target)
            continue;

        tab[curr.y][curr.x] = 'F';

        // Enqueue neighbors (up, right, down, left — order doesn't matter much)
        queue[rear++] = (t_point){curr.x,     curr.y - 1};
        queue[rear++] = (t_point){curr.x + 1, curr.y};
        queue[rear++] = (t_point){curr.x,     curr.y + 1};
        queue[rear++] = (t_point){curr.x - 1, curr.y};
    }
}