#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char *argv[])
{
	struct list *llist = create_list(create_node(9000));
	int left, right;
	char line[128];
	FILE *f1 = argc > 1 ? fopen(argv[1], "r") : stdin;
	FILE *f2 = argc > 1 ? fopen(argv[2], "r") : stdin;

	printf("Enter a range (x-y): ");
	fgets(line, 128, f1);
	sscanf(line, "%d-%d", &left, &right);
	printf("\nCreating a linked list for you...\n");

	for (int i = left; i < (right + 1); i++) {
		add_node(llist, create_node(i));
	}

	printf("Your linked list is here.\n\n");
	print_data(llist);
	printf("\n");

	while (1) {
		int x, y;
		char command[128];
		fgets(command, 128, f2);

		if (strstr(command, "insert")) {
			sscanf(command, "insert %d after %d", &x, &y);
			insert_after(llist, y, create_node(x));
		} else if (strstr(command, "delete")) {
			int del_d;

			sscanf(command, "delete %d", &del_d);
			delete(llist, del_d);
		} else if (strstr(command, "quit")) {
			break;
		}

		printf("\n");
		print_data(llist);
		printf("\n");
	}

	fclose(f1);
	fclose(f2);
	free_linked_list(llist);

	return 0;
}
