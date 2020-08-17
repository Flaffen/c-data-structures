/**
 * dllist -- double linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

struct dllist_node *allocate_node(void *data)
{
	struct dllist_node* new_node;
	new_node = malloc(sizeof(*new_node));

	new_node->data = data;

	return new_node;
}

void insert_head(struct dllist *list, struct dllist_node *node)
{
	if (list->head == NULL) {
		list->head = list->tail = node;
	} else {
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
		node->prev = NULL;
	}

	list->cur_size++;

	if (list->cur_size > list->max_size) {
		struct dllist_node *saved = list->tail;
		list->tail->prev->next = NULL;
		list->tail = saved->prev;
		free(saved);
		list->cur_size--;
	}
}

struct dllist *create_dllist(int size)
{
	struct dllist *list;
	list = malloc(sizeof(*list));
	list->cur_size = 0;
	list->max_size = size;
	list->head = list->tail = NULL;

	return list;
}

void destroy_dllist(struct dllist *list)
{
	struct dllist_node *cur = list->head;

	if (cur == NULL) {
		free(list);
	} else {
		while (cur != NULL) {
			struct dllist_node *tmp = cur->next;
			free(cur);
			cur = tmp;
		}
	}
}
