#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "llist.h"

int main(int argc, char *argv[])
{
	struct node *llist = NULL;
	struct node *n1 = create_node(10);
	struct node *n2 = create_node(20);

	append(&llist, n1);

	insert_after(llist, 10, n2);

	print_data(llist);

	free_linked_list(&llist);

	return 0;
}
