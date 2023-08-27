#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
  void *data;
  Node *next;
  Node *prev;
};

struct List {
  Node *head;
  Node *tail;
  Node *current;
};

typedef List List;

Node *createNode(void *data) {
  Node *new = (Node *)malloc(sizeof(Node));
  assert(new != NULL);
  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

List *createList() {
  List *list = (List *)malloc(sizeof(List));
  list->head = NULL;
  list->tail = 0;
  list->current = NULL;
  return list;
}

void *firstList(List *list) {
  if (!list->head) {
    return NULL;
  }

  list->current = list->head;

  return list->head->data;
}

void *nextList(List *list) {
  if (!list->current) {
    return NULL;
  }

  list->current = list->current->next;

  if (!list->current) {
    return NULL;
  }

  return list->current->data;
}

void *lastList(List *list) {
  if (list->head == NULL) {
    return NULL;
  }

  Node *tempo = list->head;

  while (tempo->next != NULL) {
    tempo = tempo->next;
  }

  list->current = tempo;

  return (list->current->data);
}

void *prevList(List *list) {
  if (list->head == NULL || list->current == NULL ||
      list->current == list->head) {
    return NULL;
  }

  Node *tempo = list->head;

  while (tempo->next != list->current) {
    tempo = tempo->next;
  }
  list->current = tempo;

  return (tempo->data);
}

void pushFront(List *list, void *data) {
  Node *n = createNode(data);
  n->next = list->head;

  if (list->head) {
    list->head->prev = n;
  }
  list->head = n;
  n->prev = NULL;
  list->tail = n;
}

void pushBack(List *list, void *data) {
  list->current = list->tail;
  pushCurrent(list, data);
}

void pushCurrent(List *list, void *data) {
  if (list->current == NULL) {
    return;
  }

  Node *nNode = createNode(data);
  nNode->next = list->current->next;
  list->current->next = nNode;
}

void *popFront(List *list) {
  list->current = list->head;
  return popCurrent(list);
}

void *popBack(List *list) {
  list->current = list->tail;
  return popCurrent(list);
}

void *popCurrent(List *list) { return NULL; }

void cleanList(List *list) {
  while (list->head != NULL) {
    popFront(list);
  }
}