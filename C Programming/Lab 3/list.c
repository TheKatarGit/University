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


struct list_node* add_end(struct list_node *head, struct list_node *node)
{
    struct list_node *cur = head;

    if (!head)
        return node;

    for ( ; cur->next; cur = cur->next)
        ;

    cur->next = node;

    return head;
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
