#include <stdio.h>
#include <stdlib.h>
/* singly linked list: insert, reverse, print */
struct node { int value; struct node *next; };
struct node *push(struct node *head, int value) { struct node *item = malloc(sizeof *item); item->value = value; item->next = head; return item; }
struct node *reverse(struct node *head) {
  struct node *previous = NULL;
  while (head) { struct node *next = head->next; head->next = previous; previous = head; head = next; }
  return previous;
}
int main(void) {
  struct node *head = NULL;
  for (int value = 1; value <= 5; value++) head = push(head, value);
  head = reverse(head);
  for (struct node *item = head; item; item = item->next) printf("%d ", item->value);
  printf("\n");
  while (head) { struct node *next = head->next; free(head); head = next; }
  return 0;
}
