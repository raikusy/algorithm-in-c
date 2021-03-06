// Linked list implementation by Fayza Tasnim (193 019 042)
#include <stdio.h>
#include <stdlib.h>

// Create a node for linked list
struct Node
{
  int item;
  struct Node *next;
};

struct UniqueNode
{
  int item;
  struct UniqueNode *next;
};

// Print the linked list
void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf(" %d ", node->item);
    node = node->next;
  }
}

// Print the unique linked list
void printUniqueList(struct UniqueNode *node)
{
  while (node != NULL)
  {
    printf(" %d ", node->item);
    node = node->next;
  }
}

void insertAtBeginning(struct Node **ref, int data)
{
  // Allocate memory to a node
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  // insert the item
  new_node->item = data;
  new_node->next = (*ref);

  // Move head to new node
  (*ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node *node, int data)
{
  if (node == NULL)
  {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->item = data;
  new_node->next = node->next;
  node->next = new_node;
}

void insertAtEnd(struct Node **ref, int data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  struct Node *last = *ref;

  new_node->item = data;
  new_node->next = NULL;

  if (*ref == NULL)
  {
    *ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

// Find the unique items in list
void findUnique(struct Node *head, struct UniqueNode **result)
{
  struct Node *p;
  struct UniqueNode *temp, *prev;

  p = head;
  while (p != NULL)
  {
    temp = *result;
    while (temp != NULL && temp->item != p->item)
    {
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL)
    {
      temp = (struct UniqueNode *)malloc(sizeof(struct UniqueNode));
      temp->item = p->item;
      temp->next = NULL;
      if (*result != NULL)
      {
        prev->next = temp;
      }
      else
      {
        *result = temp;
      }
    }
    p = p->next;
  }
}

// Insert a node after a node
void insertAtGivenPosition(struct Node *node, int data)
{
  if (node == NULL)
  {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->item = data;
  new_node->next = node->next;
  node->next = new_node;
}

void deleteNode(struct Node **ref, int key)
{
  struct Node *temp = *ref, *prev;

  if (temp != NULL && temp->item == key)
  {
    *ref = temp->next;
    free(temp);
    return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->item != key)
  {
    prev = temp;
    temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL)
    return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

int main()
{
  struct Node *head = NULL;
  struct UniqueNode *unique = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);
  insertAfter(head->next, 5);

  findUnique(head, &unique);

  printf("Linked list: ");
  printList(head);

  printf("Unique Linked list: ");
  printUniqueList(unique);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 3);
  printList(head);
}