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

	llist_print(llist);

	llist_free(&llist);

	return 0;
}
