#include <stdlib.h>
#include <stdbool.h>
#include "so_long.h"  // таны төслийн header (t_game, t_map, тодорхойлолтууд гэх мэт)

// -----------------------------------------------------------------
// Point struct (x, y координат)
// -----------------------------------------------------------------
typedef struct s_point
{
    int x;
    int y;
}   t_point;

// -----------------------------------------------------------------
// Энгийн Circular Queue (хамгийн аюулгүй, хурдан сонголт)
// -----------------------------------------------------------------
#define QUEUE_MAX 16384   // 128x128 газрын зураг хүртэл хангалттай

typedef struct s_queue
{
    t_point items[QUEUE_MAX];
    int     front;
    int     rear;
    int     size;
}   t_queue;

static t_queue  *queue_new(void)
{
    t_queue *q = malloc(sizeof(t_queue));
    if (!q)
        return (NULL);
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return (q);
}

static bool queue_is_empty(t_queue *q)
{
    return (q->size == 0);
}

static void queue_push(t_queue *q, t_point p)
{
    if (q->size >= QUEUE_MAX)
        return;
    q->rear = (q->rear + 1) % QUEUE_MAX;
    q->items[q->rear] = p;
    q->size++;
}

static t_point queue_pop(t_queue *q)
{
    t_point p = q->items[q->front];
    q->front = (q->front + 1) % QUEUE_MAX;
    q->size--;
    return (p);
}

static void queue_destroy(t_queue *q)
{
    free(q);
}

// -----------------------------------------------------------------
// Газрын зургийн гүн хуулбар (visited-д ашиглана)
// -----------------------------------------------------------------
static char **map_copy(char **original, int height)
{
    char    **copy;
    int     i;

    copy = malloc(sizeof(char *) * (height + 1));
    if (!copy)
        return (NULL);
    
    i = 0;
    while (i < height)
    {
        copy[i] = ft_strdup(original[i]);
        if (!copy[i])
        {
            while (i-- > 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

static void free_map_copy(char **map)
{
    int i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}

// -----------------------------------------------------------------
// Хамгийн чухал функц: Бүх C болон E хүрэх боломжтой эсэхийг шалгана
// -----------------------------------------------------------------
bool    has_valid_path(t_game *game)
{
    char        **visited;
    t_queue     *q;
    t_point     start;
    int         found_c;
    bool        found_e;
    int         height, width;
    int         i;

    height = game->map.height;
    width  = game->map.width;

    if (game->map.collectible_count == 0 || !game->map.exit_exists)
        return (false);

    start = game->player.pos;

    // Газрын зургийн хуулбар үүсгэх
    visited = map_copy(game->map.grid, height);
    if (!visited)
        return (false);

    q = queue_new();
    if (!q)
    {
        free_map_copy(visited);
        return (false);
    }

    // Эхлэлийн цэгийг queue-д хийж, visited гэж тэмдэглэнэ
    queue_push(q, start);
    visited[start.y][start.x] = 'V';

    found_c = 0;
    found_e = false;

    // 4 чиглэл: баруун, зүүн, доод, дээд
    t_point directions[4] = {
        {1, 0},   // right
        {-1, 0},  // left
        {0, 1},   // down
        {0, -1}   // up
    };

    while (!queue_is_empty(q))
    {
        t_point current = queue_pop(q);

        // Оригинал газрын зургаас юу байна вэ гэдгийг харна
        char tile = game->map.grid[current.y][current.x];

        if (tile == 'C')
            found_c++;
        if (tile == 'E')
            found_e = true;

        // 4 чиглэлээр шалгах
        for (i = 0; i < 4; i++)
        {
            int new_x = current.x + directions[i].x;
            int new_y = current.y + directions[i].y;

            // Хилээс хальсан эсэх
            if (new_x < 0 || new_x >= width || new_y < 0 || new_y >= height)
                continue;

            // Хана эсвэл аль хэдийн очсон газар
            if (game->map.grid[new_y][new_x] == '1' || visited[new_y][new_x] == 'V')
                continue;

            // Явах боломжтой (0, C, E)
            visited[new_y][new_x] = 'V';
            queue_push(q, (t_point){new_x, new_y});
        }
    }

    // Цэвэрлэгээ
    queue_destroy(q);
    free_map_copy(visited);

    // Шалгалт: БҮХ collectible болон exit хүрсэн эсэх
    return (found_c == game->map.collectible_count && found_e);
}
