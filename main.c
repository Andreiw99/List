#include <stdio.h>
#include <stdlib.h>
#include "functiListe.h"
#include <time.h>
int main()
{
    FILE *file = fopen ("file.txt", "w");   // Se creeaza si se deschide fisierul "file.txt"
    struct g_node *head= malloc (sizeof(struct g_node));    // Se creeaza nodul head
    struct g_node *iterator=head;
    struct g_node *last_element;
    clock_t start,finish;
    double duration;
    start=clock();
    head->next = NULL;
    int i,n,k;
    n = generate_numbers ();  // Se genereaza n copii
    printf("Numarul de copii este: %d\n",n);
    printf("Introduceti numarul k: ");
    scanf("%d", &k);
    for(i=1;i<=n;i++)
        push_element_end(head,i); // Se creeaza o lista simplu inlantuita
    while(iterator->next != NULL) // Se parcurge lista pana la ultimul nod
        iterator = iterator->next;
    last_element = iterator;
    last_element->next = head->next; // Ultimul nod se leaga la primul, lista devenind circulara
    iterator = head;
    if(k==1)    // Pentru k=1, vor iesi pe rand fiecare copil, unul dupa altul
    {
        for(i=1;i<=n;i++)
        {
            fprintf(file,"%d ", iterator->next->info);
            iterator=iterator->next;
        }
    }
    else
    {
        while (1)
        {
            if(one_element(iterator) == 1)  // Daca mai este doar un singur copil se iese din bucla
                break;
            for(i=1;i<k;i++) // Se parcurge lista pana la copilul de pe pozitia k-1
                iterator=iterator->next;
            fprintf(file,"%d ", iterator->next->info); // Se afiseaza nodul de pe pozitia k
            iterator->next = iterator->next->next;  // Nodul de pe pozitia k-1, se va lega cu nodul de pe poztia k+1, astfel se va sterge nodul de pe pozitia k
        }
    }
    finish=clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    fprintf(file, "\nduration: %.3fs ", duration);
    fclose(file);   // Se inchide fisierul
    return 0;
}
