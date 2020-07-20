#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{
	struct list *llist = create_list(NULL);

	// Allocate memory for 10 node structs and fill out the linked list with them.
	for (int i = 0; i < 10; i++) {
		add_node(llist, create_node(i + 1));
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
