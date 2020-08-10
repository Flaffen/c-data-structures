#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "llist.h"

#define MAXLINE 2048

void remove_evens(struct node **llist)
{
	struct node *current = *llist;
	struct node *prev = NULL;

	if (current == NULL)
		return;

	while (current != NULL) {
		if (current->data % 2 == 0) {
			if (prev == NULL) {
				struct node *tmp = current->next;
				*llist = current->next;
				free(current);
				current = tmp;
			} else {
				prev->next = current->next;
				struct node *tmp = current->next;
				free(current);
				current = tmp;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
}

int main(int argc, char *argv[])
{
	struct node *llist = NULL;

	int n;
	char line[MAXLINE];
	FILE *f;

	if (argc > 1) {
		f = fopen(argv[1], "r");

		while (fgets(line, MAXLINE, f))
			llist_append(&llist, llist_create_node(atoi(line)));

		fclose(f);
	} else {
		fgets(line, MAXLINE, stdin);
		n = atoi(line);

		for (int i = 0; i < n; i++) {
			fgets(line, MAXLINE, stdin);
			llist_append(&llist, llist_create_node(atoi(line)));
		}
	}

	llist_print(llist);
	printf("\n");

	remove_evens(&llist);

	llist_print(llist);

	llist_free(&llist);

	return 0;
}
