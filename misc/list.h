#include <stdbool.h>
#include <stddef.h>

struct node {
    struct node* next;
}

#define for_each_node(head, elem) \
    for (struct node* cur = head; cur; cur = cur->next)

#define container_of(node, member, type) \
    ((type*)((char*)node - offsetof(type, member)))

static inline bool list_empty(struct node* head)
{
    return head->next;
}

void list_push_front(struct node* head, struct node* elem);
struct node* list_pop_front(struct node* head);
void list_reverse(struct node* head);
