#ifndef DEF_LINKED_LISTS
#define DEF_LINKED_LISTS
#include "library_manager.h"

typedef struct Node Node;
struct Node
{
	int id;
	char title[100];
	char author[100];
	int release;
	int pages;

	Node* next;
};

typedef struct List List;

struct List {
	Node* head;
};

void* initialize();
void insert_node(List* list,int newID, char newTitle[], char newAuthor[], int newRelease, int newPages);
void delete_node(List* list, int IDChoice);
void update_node(List* list,int IDChoice, char updatedTitle[], char updatedAuthor[], int updatedRelease, int updatedPages);
void display_list(List* list);


#endif // !DEF_LINKED_LISTS