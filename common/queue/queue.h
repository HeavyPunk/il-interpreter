#ifndef COMMON_QUEUE_H
#define COMMON_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct QueueNode{
    struct QueueNode* next;
    void* data;
} queue_node;

queue_node* queue_create_node(void* payload);
bool queue_push(queue_node** queue, void* payload);
void* queue_pop(queue_node** queue); 

#endif
