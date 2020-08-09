#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "llist.h"

#define ENTRIES 5

int main(int argc, char *argv[])
{
	struct node *llist = NULL;

	llist_insert_first(&llist, llist_create_node(888));

	for (int i = 1; i <= ENTRIES; i++) {
		llist_append(&llist, llist_create_node(i * 10));
	}

	llist_insert_first(&llist, llist_create_node(999));

	llist_delete_first(&llist);
	llist_delete_first(&llist);

	llist_delete_last(&llist);
	llist_delete_last(&llist);

	llist_insert_before(llist, 30, llist_create_node(567));

	llist_print(llist);

	llist_free(&llist);

	return 0;
}
