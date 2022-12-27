#include "queue.h"

queue_node *queue_create_node(void *payload)
{
    queue_node* node = malloc(sizeof(queue_node));
    (*node) = (queue_node){.data = payload, .next = NULL};
    return node;
}

bool queue_push(queue_node **queue, void *payload)
{
    if (!queue || !(*queue))
        return false;
    queue_node* new = queue_create_node(payload);
    new->next = *queue;
    *queue = new;
    return true;
}

void *queue_pop(queue_node **queue)
{
    if (!queue || !(*queue))
        return NULL;
    void* data = (*queue)->data;
    queue_node* old = *queue;
    (*queue) = (*queue)->next;
    free(old);
    return data;
}
