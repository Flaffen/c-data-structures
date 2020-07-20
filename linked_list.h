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

/*
 * Linked list containing head node pointer. Clunky, don't know if it's the right way to initialize a linked list.
 */
struct list {
	struct node *head;
};

void print_data(struct list *linked_list);

void add_node(struct list *list, struct node *node);

struct node *create_node(int data);

struct list *create_list(struct node *head);

void print_node_data(struct node *node);

int delete(struct list *list, int data);
