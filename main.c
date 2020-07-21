#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void del_all_occ(struct list *llist, int data)
{
	struct node *current;

	while (!delete(llist, data));
}

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
	int replacex;
	scanf("%d %d", &findx, &replacex);
	insert_after(llist, findx, create_node(replacex));

	print_data(llist);

	// Deallocate memory for the linked list.
	free_linked_list(llist);

	return 0;
}
