#include <stdio.h>
#include <stdlib.h>
#include "functiListe.h"
#include <time.h>
void push_element_end(struct g_node *head ,int new_element_value)
{
    struct g_node *new_element = malloc(sizeof(struct g_node));
    struct g_node *iterator = head;
    struct g_node *last_element;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    last_element = iterator;

    last_element->next = new_element;
    new_element->info = new_element_value;
    new_element->next = NULL;
}

int one_element (struct g_node *head)
{
    struct g_node *iterator = head;
    if(iterator->next == iterator)
        return 1;
    return 0;
}

int generate_numbers ()
{
    int n;
    srand(time(NULL));
    n = rand() % 1000000;
    return n;
}
