#include <stdlib.h>
#include <stdio.h>
#include "list.h"


struct list_node* create_node(int num)
{
    struct list_node *node = malloc(sizeof(struct list_node));

    if (node)
    {
        node->num  = num;
        node->next = NULL;
    }

    return node;
}


struct list_node* add_front(struct list_node *head, struct list_node *node)
{
    node->next = head;

    return node;
}

void print(struct list_node *head)
{
    printf("List:\n");
    for ( ; head; head = head->next)
        printf("%d ", head->num);

    printf("\n");
}


void free_all(struct list_node *head)
{
    struct list_node *next;

    for ( ; head; head = next)
    {
        next = head->next;
        free(head);
    }
}
