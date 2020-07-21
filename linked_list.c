#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
 * Print the 'data' field of every node of a linked list.
 */
void print_data(struct list *l)
{
	struct node *current = l->head;

	if (current == NULL) return;

	do {
		printf("current->data is %d\n", current->data);
		current = current->next;
	} while (current != NULL);
}

/*
 * Add a node at the end of a linked list.
 */
void add_node(struct list *l, struct node *n)
{
	if (l->head == NULL) {
		l->head = n;
	} else {
		struct node *current = l->head;

		while (current->next != NULL) current = current->next;

		current->next = n;
	}
}

/*
 * Insert a node after a node containing 'd' in its 'data' field.
 */
int insert_after(struct list *l, int d, struct node *n)
{
	struct node *current = l->head;
	
	while (current->data != d && current->next != NULL) {
		current = current->next;
	}

	if (current->data != d) {
		return 1;
	} else {
		struct node *prev = current->next;
		n->next = prev;
		current->next = n;
		return 0;
	}
}

int delete(struct list *l, int d)
{
	struct node *current = l->head;
	struct node *prev = NULL;

	while (current->data != d && current->next != NULL) {
		prev = current;
		current = current->next;
	}

	if (current->data != d) {
		return 1;
	} else {
		if (prev == NULL) {
			l->head = current->next;
		} else {
			prev->next = current->next;
		}
		free(current);
		return 0;
	}
}

struct node *create_node(int d)
{
	struct node *p;
	p = malloc(sizeof *p);
	p->data = d;

	return p;
}

struct node *get_node(struct list *llist, int data)
{
	struct node *current = llist->head;

	while (current->data != data && current->next != NULL) {
		current = current->next;
	}

	return current->data == data ? current : NULL;
}

struct list *create_list(struct node *head)
{
	struct list *l;
	l = malloc(sizeof *l);

	l->head = head;

	return l;
}

void print_node_data(struct node *node)
{
	printf("%d\n", node->data);
}

int free_linked_list(struct list *llist)
{
	struct node *current = llist->head;

	if (current->next == NULL) {
		free(current);
	} else {
		while (current != NULL) {
			delete(llist, current->data);
			current = current->next;
		}
	}
	free(llist);

	return 1;
}
