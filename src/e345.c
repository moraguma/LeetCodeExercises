#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct LinkedList {
    int val;
    struct LinkedList* next;
    struct LinkedList* last;
} LinkedList;


LinkedList* createLinkedList(int val) {
    LinkedList* l = malloc(sizeof(LinkedList));
    l->val = val;
    l->next = NULL;
    l->last = NULL;
    return l;
}


LinkedList* insertLinkedList(LinkedList* l, int val) {
    LinkedList* nl = malloc(sizeof(LinkedList));
    nl->val = val;

    l->next = nl;
    nl->last = l;
    nl->next = NULL;

    return nl;
}


void freeLinkedList(LinkedList* l) {
    LinkedList* aux;
    while (l != NULL) {
        aux = l;
        l = l->next;
        free(aux);
    }
}


char* reverseVowels(char* s) {
    LinkedList* l = NULL;
    LinkedList* start = NULL;

    int pos = 0;
    while (s[pos] != '\0') {
        if (s[pos] == 'a' || s[pos] == 'e' || s[pos] == 'i' || s[pos] == 'o' || s[pos] == 'u') {
            if (l == NULL) {
                l = createLinkedList(pos);
                start = l;
            } else { 
                l = insertLinkedList(l, pos);
            }
        }
        pos++;
    }

    char aux;
    char* ns = malloc(sizeof(char) * 300001);
    strcpy(s, ns);
    LinkedList* toFree = start;
    while (start != NULL) {
        aux = s[l->val];
        ns[l->val] = s[start->val];
        ns[start->val] = aux;

        start = start->next;
        l = l->last;
    }
    freeLinkedList(toFree);
    return ns;
}


int main(int argc, char *argv[]) {
    char* result = reverseVowels("hello");
    printf("%s\n", result);
    free(result);
}