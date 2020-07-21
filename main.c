#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{
	struct list *llist = create_list(NULL);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		struct node *n = create_node(x);
		add_node(llist, n);
	}

	print_data(llist);
	int findx;
	scanf("%d", &findx);
	struct node *found = get_node(llist, findx);
	printf("%s\n", found ? "found" : "not found");

	// Deallocate memory for the linked list.
	free_linked_list(llist);

	return 0;
}
