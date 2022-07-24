#include "linked_lists.h"

void* initialize()
{
	List* list = malloc(sizeof(*list));
	Node* node = malloc(sizeof(*node));

	if (list == NULL || node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	node->id = 0;
	strcpy(node->title, "EMPTY");
	strcpy(node->author, "EMPTY");
	node->release = 0;
	node->pages = 0;
	node->next = NULL;
	list->head = node;

	return list;
}

void insert_node(List* list, int newID,char newTitle[], char newAuthor[], int newRelease, int newPages)
{
	Node* newNode = malloc(sizeof(*newNode));
	if (list == NULL || newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}

	newNode->id = newID;
	strcpy(newNode->title, newTitle);
	strcpy(newNode->author, newAuthor);
	newNode->release = newRelease;
	newNode->pages = newPages;
	newNode->next = list->head;
	list->head = newNode;
}

void update_node(List* list,int IDChoice, char updatedTitle[], char updatedAuthor[], int updatedRelease, int updatedPages)
{
	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Node* current = list->head;
	while (current->id != IDChoice)
	{
		current = current->next;
	}

	strcpy(current->title, updatedTitle);
	strcpy(current->author, updatedAuthor);
	current->release = updatedRelease;
	current->pages = updatedPages;
}

void delete_node(List* list, int IDChoice)
{
	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (list->head != NULL)
	{
		Node* toBeDelete = list->head;
		while (toBeDelete->id != IDChoice)
		{
			 toBeDelete = toBeDelete->next;
		}
		list->head = list->head->next;
		free(toBeDelete);
	}
}


void display_list(List* list)
{
	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Node* current = list->head;
	while (current != NULL)
	{
		printf("\nID : %d\n", current->id);
		printf("Title : %s\n", current->title);
		printf("Author : %s\n", current->author);
		printf("Release : %d\n", current->release);
		printf("Pages : %d\n\n", current->pages);
		current = current->next;
	}
}