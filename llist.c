#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/*
 * Print the 'data' field of every node of a linked list.
 */
void llist_print(struct node *head)
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
int llist_insert_after(struct node *l, int d, struct node *n)
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

int llist_insert_before(struct node *llist, int d, struct node *n)
{
	if (llist == NULL)
		return 1;
	
	struct node *current = llist;
	struct node *prev = NULL;

	while (current->data != d && current->next != NULL) {
		prev = current;
		current = current->next;
	}

	if (current->data != d) {
		return 1;
	} else {
		if (prev == NULL) {
			printf("coming soon\n");
		} else {
			n->next = current;
			prev->next = n;
		}

		return 0;
	}
}

int llist_delete(struct node **headp, int d)
{
	if (*headp == NULL) {
		printf("the first element in the linked list is null!");
		return 1;
	}

	struct node *current = *headp;
	struct node *prev = NULL;

	while (current->data != d && current->next != NULL) {
		prev = current;
		current = current->next;
	}

	if (current->data == d) {
		if (prev == NULL) {
			*headp = current->next;
			free(current);
		} else {
			prev->next = current->next;
			free(current);
		}

		return 0;
	} else {
		return 1;
	}
}

struct node *llist_create_node(int d)
{
	struct node *p;
	p = malloc(sizeof *p);
	p->data = d;

	return p;
}

struct node *llist_get_node(struct node *llist, int data)
{
	struct node *current = llist;

	while (current->data != data && current->next != NULL) {
		current = current->next;
	}

	return current->data == data ? current : NULL;
}

int llist_append(struct node **head, struct node *n)
{
	if (*head == NULL) {
		*head = n;
	} else {
		struct node *val = *head;

		while (val->next != NULL)
			val = val->next;
		val->next = n;
	}

	return 0;
}

int llist_insert_first(struct node **head, struct node *n)
{
	n->next = *head;
	*head = n;

	return 0;
}

void llist_print_node_data(struct node *node)
{
	printf("%d\n", node->data);
}

int llist_delete_first(struct node **llist)
{
	if (*llist == NULL)
		return 1;

	struct node *tmp = *llist;
	*llist = (*llist)->next;
	free(tmp);
	return 0;
}

int llist_delete_last(struct node **llist)
{
	if (*llist == NULL)
		return 1;

	struct node *current = *llist;
	struct node *prev = NULL;

	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}

	if (prev == NULL) {
		return 1;
	} else {
		prev->next = NULL;
		free(current);
	}

	return 0;
}

int llist_free(struct node **llist)
{
	if (*llist == NULL) {
		return 1;
	} else {
		struct node *current = *llist;
		struct node *tmp = NULL;

		while (current != NULL) {
			tmp = current->next;
			printf("Freeing node with d == %d\n", current->data);
			free(current);
			current = tmp;
		}

		return 0;
	}

	return 1;
}
