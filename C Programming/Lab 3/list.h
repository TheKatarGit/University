#ifndef _LIST_H_

#define _LIST_H_


struct list_node
{
    int num;

    struct list_node *next;
};


struct list_node* create_node(int num);

struct list_node* add_front(struct list_node *head, struct list_node *node);

void print(struct list_node *head);

void free_all(struct list_node *head);

#endif  // #ifndef _LIST_H_
