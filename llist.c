#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/*
 * Print the 'data' field of every node of a linked list.
 */
void print_data(struct node *head)
{
	struct node *current = head;

	if (current == NULL) return;

	do {
		printf("current->data is %d\n", current->data);
		current = current->next;
	} while (current != NULL);
}

/*
 * Insert a node after a node containing 'd' in its 'data' field.
 */
int insert_after(struct node *l, int d, struct node *n)
{
	struct node *current = l;

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

int delete(struct node *l, int d)
{
	struct node *current = l;
	struct node *prev = NULL;

	while (current->data != d && current->next != NULL) {
		prev = current;
		current = current->next;
	}

	if (current->data != d) {
		return 1;
	} else {
		if (prev == NULL) {
			l = current->next;
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

struct node *get_node(struct node *llist, int data)
{
	struct node *current = llist;

	while (current->data != data && current->next != NULL) {
		current = current->next;
	}

	return current->data == data ? current : NULL;
}

int append(struct node **head, struct node *n)
{
	if (*head == NULL) {
		*head = n;
	} else {
		struct node *val = *head;

		while (val != NULL)
			val = val->next;
		val->next = n;
	}

	return 0;
}

void print_node_data(struct node *node)
{
	printf("%d\n", node->data);
}

int free_linked_list(struct node **llist)
{
	if (*llist == NULL) {
		free(llist);
	} else {
		struct node *n;

		do {
			n = *llist;
			struct node *next = n->next;

			free(n);
			n = next;
		} while (n->next != NULL);
	}

	return 1;
}
