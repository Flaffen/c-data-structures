#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "llist.h"

#define ENTRIES 5

int main(int argc, char *argv[])
{
	struct node *llist = NULL;

	for (int i = 1; i <= ENTRIES; i++) {
		llist_append(&llist, llist_create_node(i * 10));
	}

	llist_delete(&llist, 30);
	llist_insert_after(llist, 10, llist_create_node(1));

	llist_print_node_data(llist_get_node(llist, 40));

	llist_print(llist);

	return 0;
}
