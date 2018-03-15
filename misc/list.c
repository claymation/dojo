#include "list.h"

void list_push_front(struct node* head, struct node* elem)
{
    elem->next = head->next;
    head->next = elem;
}

struct node* list_pop_front(struct node* head)
{
    struct node* ret = head->next;
    head->next = ret->next;
    return ret;
}

void list_reverse(struct node* head)
{
    struct node *prev = NULL
    struct node* next = head->next->next;

    if (!next) return;

    while (next) {
        head->next->next = prev;
        prev = head->next;
        head->next = next;
        next = next->next;
    }
    head->next = prev;
}
