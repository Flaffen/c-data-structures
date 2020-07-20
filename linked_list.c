#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

struct list {
	struct node *head;
};

void print_data(struct list *l)
{
	struct node *current = l->head;

	do {
		printf("current->data is %d\n", current->data);
		current = current->next;
	} while (current != NULL);
}

void add_node(struct list *l, struct node *n)
{
	if (l->head == NULL) {
		l->head = n;
	} else {
		struct node *current = l->head;

		while (current->next != NULL) current = current->next;

		current->next = n;
	}
}

struct node create_node(int data) {
	struct node new_node = { data, NULL };

	return new_node;
}

struct list create_list(struct node *head)
{
	struct list new_list = { head };

	return new_list;
}

int insert_after(struct list *l, int d, struct node *n)
{
	struct node *current = l->head;
	
	while (current->data != d && current->next != NULL) {
		current = current->next;
	}

	if (current->data != d) {
		return 1;
	} else {
		struct node *prev = current->next;
		n->next = prev;
		current->next = n;
		return 0;
	}
}

int delete(struct list *l, int d)
{
	struct node *current = l->head;
	struct node *prev = NULL;

	while (current->data != d && current->next != NULL) {
		prev = current;
		current = current->next;
	}

	if (current->data != d) {
		return 1;
	} else {
		if (prev == NULL) {
			l->head = current->next;
		} else {
			prev->next = current->next;
		}
		return 0;
	}
}

int main(void)
{
	struct node n0 = create_node(0);

	struct list linked_list = create_list(&n0); 

	struct node n1 = create_node(10);
	struct node n2 = create_node(20);

	add_node(&linked_list, &n1);
	add_node(&linked_list, &n2);

	struct list *pll = &linked_list;

	struct node n3 = create_node(100);
	if (insert_after(pll, 20, &n3)) {
		printf("did not find\n");
	}

	struct node n4 = create_node(9000);
	insert_after(pll, 20, &n4);

	delete(pll, 20);

	print_data(pll);

	return 0;
}
