struct dllist_node {
	void *data;

	struct dllist_node *prev;
	struct dllist_node *next;
};

struct dllist {
	int cur_size;
	int max_size;

	struct dllist_node *head;
	struct dllist_node *tail;
};

struct dllist_node *allocate_node(void *data);
void insert_head(struct dllist *list, struct dllist_node *node);
struct dllist *create_dllist(int size);
void destroy_dllist(struct dllist *list);
