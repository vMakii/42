#include "cub3D.h"

static void add_gb_to_back(t_garbage **garbage_list, t_garbage *new_gb)
{
    t_garbage *current;

    if (!garbage_list || !new_gb)
        return;
    if (!*garbage_list)
    {
        *garbage_list = new_gb;
        return;
    }
    current = *garbage_list;
    while (current->next)
        current = current->next;
    current->next = new_gb;
}

void    *gc_malloc(size_t size, t_garbage **garbage_list)
{
    t_garbage    *new_gb;
    void        *alloc;

    new_gb = ft_calloc(1, sizeof(t_garbage));
    alloc = malloc(size);
    if (!alloc || !new_gb)
    {
        free(alloc);
        free(new_gb);
        perror("gc_malloc");
        return (NULL);
    }
    ft_bzero(new_gb, sizeof(t_garbage));
    ft_bzero(alloc, size);
    new_gb->alloc = alloc;
    add_gb_to_back(garbage_list, new_gb);
    return (alloc);
}