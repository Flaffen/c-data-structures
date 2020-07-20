#include <stdio.h>
#include <stdlib.h>

/*
 * A node of a linked list containing an integer as data and a pointer to the next node.
 * Would be nice to store data of arbitrary type as data.
 *
 */
struct node {
	int data;
	struct node *next;
};

/*
 * Linked list containing head node pointer. Clunky, don't know if it's the right way to initialize a linked list.
 *
 */
struct list {
	struct node *head;
};

/*
 * Print the 'data' field of every node of a linked list.
 *
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
 *
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
 * Create a new linked list node and return it as value. Need to find out how to use malloc() and the whole memory management stuff to return a pointer.
 *
 */
struct node create_node(int data) {
	struct node new_node = { data, NULL };

	return new_node;
}

/*
 * Create a linked list with 'head' as head pointer.
 *
 */
struct list create_list(struct node *head)
{
	struct list new_list = { head };

	return new_list;
}

/*
 * Insert a node after a node containing 'd' in its 'data' field.
 *
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

struct node *create_node_malloc(int d)
{
	struct node *p;
	p = malloc(sizeof *p);
	p->data = d;

	return p;
}

struct list *create_list_malloc(struct node *head)
{
	struct list *l;
	l = malloc(sizeof *l);

	l->head = head;

	return l;
}

void print_node_data(struct node *node)
{
	printf("%d\n", (*(node)).data);
}

int main(void)
{
	struct list *llist = create_list_malloc(NULL);

	// Allocate memory for 10 node structs and fill out the linked list with them.
	for (int i = 0; i < 10; i++) {
		add_node(llist, create_node_malloc(i + 1));
	}

	// Do things with the linked list.
	print_data(llist);

	// Deallocate memory for the linked list.
	struct node *current = llist->head;

	while (current != NULL) {
		delete(llist, current->data);
		current = current->next;
	}
	free(llist);

	return 0;
}
