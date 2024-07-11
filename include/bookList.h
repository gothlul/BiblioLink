#ifndef BOOKLIST_H
#define BOOKLIST_H
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct _livro book;
typedef struct _snode node;
typedef struct linkedlist lista;

book *create_book(int id, char *tittle, char *desc, float preco, unsigned int pgs);
node *create_node(int id, char *tittle, char *desc, float preco, unsigned int pgs);
lista *create_list();

void book_destroy(book **n);
void node_destroy(node **n);
void list_destroy(lista **l_ref);

bool lista_nula(const lista *l);

void add_book(lista *l, int id, char *tittle, char *desc, float preco, unsigned int pgs);

void imprime_item(node *no);
void lista_books(const lista *l);
void imprime_books(const lista *l);

void remove_first_item(lista *list, book *t);

size_t count_itens(const lista *itens);
node *first_item(const lista *itens);
node *last_item(const lista *itens);
node *search_item(lista *itens, int pos);

#endif