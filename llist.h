/*
 * A NOTE ON STRUCTS:
 * A more convenient albeit controversial way to declare a structure is
 * 	typedef struct Node {
 * 		int data;
 * 		struct Node *next;
 * 	} Node;
 * That way when you can write
 * 	Node *n1;
 * instead of
 * 	struct node *n1;
 * and generally write less code. However, that style is not encouraged by everyone.
 * One of such people is Linus Torvalds, which has a kernel style guide that goes
 * into it further: https://www.kernel.org/doc/html/v4.10/process/coding-style.html
 * Personally I think the typedef variant is fine as long as the project is small.
 */

/*
 * A node of a linked list containing an integer as data and a pointer to the next node.
 * Would be nice to store data of arbitrary type as data.
 */
struct node {
	int data;
	struct node *next;
};

void llist_print(struct node *head);

struct node *llist_create_node(int data);

struct node *llist_get_node(struct node *llist, int data);

void llist_print_node_data(struct node *node);

int llist_delete(struct node **list, int data);

int llist_free(struct node **list);

int llist_insert_after(struct node *list, int data, struct node *node);

int llist_append(struct node **list, struct node *n);
