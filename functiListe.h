#ifndef CODE_LISTS_H
#define CODE_LISTS_H

struct g_node{
    int info;
    struct g_node *next;
};

void push_element_end(struct g_node *head, int new_element_value);
int one_element (struct g_node *head);
int generate_numbers();


#endif //CODE_LISTS_H
