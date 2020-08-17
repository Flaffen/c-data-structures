#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.c"
#include "dllist.h"

int main(int argc, char *argv[])
{
	struct file_data *fdata = get_file("llist.c");
	struct dllist *list = create_dllist(5);

	struct dllist_node *n1 = allocate_node(fdata->data);

	insert_head(list, n1);

	printf("%s", (char *) list->head->data);

	free(fdata->data);
	free(fdata);

	return 0;
}
