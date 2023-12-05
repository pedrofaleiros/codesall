#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ID_COUNT = 0;

typedef struct Node
{
	int id;
	char *key;
	int value;
	struct Node *next;
	struct Node * last;
} Node;

typedef struct LinkedList
{
	int size;
	struct Node *start;
	struct Node *end;
} LinkedList;

#define SIZE 1000
typedef struct HashMap
{
	LinkedList **vet;
} HashMap;

Node *alloc_node(char *key, int value);
LinkedList *alloc_linked_list();
HashMap *alloc_hash_map();
void insert_node(LinkedList *list, char *key, int value);
void show_list(LinkedList *list);
int hashFunction(char *name);
void insert_map(HashMap *map, char *key, int value);
void find_map(HashMap *map, char *key);

int main()
{
	HashMap *map = alloc_hash_map();

	insert_map(map, "pedro", 22);
	insert_map(map, "pedro", 25);
	insert_map(map, "pedro", 23);
	insert_map(map, "pedro", 23);

	find_map(map, "pedro");

	show_list(map->vet[hashFunction("pedro")]);
	printf("\n");
	show_list(map->vet[hashFunction("dani")]);

	printf("\n");
	return 0;
}

void find_map(HashMap *map, char *key)
{
}

void insert_map(HashMap *map, char *key, int value)
{
	insert_node(map->vet[hashFunction(key)], key, value);
}

int hashFunction(char *name)
{
	int hash = 0;
	while (*name)
	{
		hash += (char)(*name);
		name++;
	}
	return hash % SIZE;
}

void show_list(LinkedList *list)
{
	Node *aux = list->start;

	while (aux != NULL)
	{
		printf("%s: %d\n",aux->key, aux->value);
		aux = aux->next;
	}
}

void insert_node(LinkedList *list, char *key, int value)
{
	Node * new = alloc_node(key, value);

	if (list->start == NULL){
		list->start = new;
		list->end = new;
	}else{
		Node *aux = list->start;

		while (aux->next != NULL && aux->value < value){
			aux = aux->next;
		}

		if(aux->value > value){
			if(aux->last){
				new->next = aux;
				new->last = aux->last;
				aux->last->next = new;
				aux->last = new;
			}else{
				list->start = new;
				new->next = aux;
				aux->last = new;
			}
		}else{
			aux->next = new;
			new->last = aux;
			list->end = new;
		}

	}
	list->size += 1;
}

HashMap *alloc_hash_map()
{
	HashMap *new = malloc(sizeof(HashMap));
	new->vet = malloc(sizeof(LinkedList*) * SIZE);
	for(int i = 0; i < SIZE; i++){
		new->vet[i] = alloc_linked_list();
	}
	return new;
}

LinkedList *alloc_linked_list()
{
	LinkedList *new = malloc(sizeof(LinkedList));
	new->size = 0;
	new->start = NULL;
	new->end = NULL;
	return new;
}

Node *alloc_node(char *key, int value)
{
	Node *new = malloc(sizeof(Node));
	new->id = ID_COUNT++;
	new->value = value;
	new->next = NULL;
	new->last = NULL;

	new->key = malloc(sizeof(char) * strlen(key));
	strcpy(new->key, key);

	return new;
}