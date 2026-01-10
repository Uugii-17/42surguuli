#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
    struct s_list   *next;
    int            *data;      // sometimes int data; depending on the exercise
}                   t_list;

#endif
