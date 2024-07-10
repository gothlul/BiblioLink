#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct _livro{
    int id;
    char titulo[100];
    char desc[300];
    float preco;
    unsigned int pgs;
}book;

typedef struct _snode{
    book *book;
    struct _snode *last;
    struct _snode *next;
    unsigned int acess;
}node;

typedef struct linkedlist{
    node *begin;
    node *end;
    unsigned int size;
}lista;

book *create_book(int id, char *tittle, char *desc, float preco, unsigned int pgs){
    book *t = calloc(1, sizeof(book));

    strcpy(t->titulo, tittle);
    strcpy(t->desc, desc);
    t->id = id;
    t->preco = preco;
    t->pgs = pgs;

    return t;
}

node *create_node(int id, char *tittle, char *desc, float preco, unsigned int pgs){
    node *n = calloc(1, sizeof(node));
    n->book = create_book(id, tittle, desc, preco, pgs);
    n->last = NULL;
    n->next = NULL;
    n->acess = 0;

    return n;
}

lista *create_list(){
    lista *l = calloc(1, sizeof(lista));
    l->begin = NULL;
    l->end = NULL;
    l->size = 0;

    return l;
}


void book_destroy(book **n){
    free(*n);
    *n = NULL;
}

void node_destroy(node **n){
    node *no = *n;
    book_destroy(&no->book);

    free(no);
    *n = NULL;
}

void list_destroy(lista **l_ref){
    lista *l = *l_ref;
    node *pos = l->begin;
    node *del = NULL;

    while(pos != NULL){
        del = pos;
        pos = pos->next;

        node_destroy(&del);
    }

    free(l);
    *l_ref = NULL;
}

bool lista_nula(const lista *l){
    return l->size == 0;
}

void add_book(lista *l, int id, char *tittle, char *desc, float preco, unsigned int pgs){
    node *q = create_node(id, tittle, desc, preco, pgs);
    q->last = l->end;
    
    if(lista_nula(l)){
        l->begin = q;
    }else{
        l->end->next = q;
    }

    l->end = q;
    l->size++;
}


void imprime_item(node *no){
    printf("\n-----------------------------------------");
    printf("\n| ID: %d\tTitulo:\t%s\n", no->book->id, no->book->titulo);
    printf("-----------------------------------------");
    printf("\n|\n| Descrição:\t%s\n|\n", no->book->desc);
    printf("-----------------------------------------");
    printf("\n| Preço: %.2f\tNúmero de páginas:\t%d\n", no->book->preco, no->book->pgs);
    printf("-----------------------------------------\n");
}

void lista_books(const lista *l){
    node *aux = l->begin;
    
    printf("\n-----------------------------------------");
    printf("\n|\t\tID\t\t|\t\tTitulo\t\t|\t\tPreço\t\t|\t\tAcessos\t\t|");

    while(aux != NULL){
        printf("\n-----------------------------------------");
        printf("\n|\t\t%d\t\t|\t\t%s\t\t|\t\t%.2f\t\t|\t\t%d\t\t|", aux->book->id, aux->book->titulo, aux->book->preco, aux->acess);
        aux = aux->next;
    }

    printf("\n-----------------------------------------");

    printf("\nTamanho da lista: %d\n", l->size);
}

void imprime_books(const lista *l){
    node *aux = l->begin;
    
    while(aux != NULL){
        imprime_item(aux);
        aux = aux->next;
    }

    printf("\nTamanho da lista: %d\n", l->size);
}

void remove_first_item(lista *list, book *t){
    node *leitor = list->begin;

    if(!lista_nula(list)){
        while(strcmp(leitor->book->titulo, t->titulo)){
            leitor = leitor->next;
        }

        if(leitor != NULL){
            if(list->end == leitor){
                list->end = leitor->last;
            }

            if(list->begin == leitor){
                list->begin = leitor->next;

            }else{
                leitor->next->last = leitor->last;
                leitor->last->next = leitor->next;
            }

            free(leitor);
            list->size--;
        }
    }
}

size_t count_itens(const lista *itens){
    return itens->size;
}

node *first_item(const lista *itens){
    return itens->begin;
}

node *last_item(const lista *itens){
    return itens->end;
}

node *search_item(lista *itens, int pos){
    node *leitor = itens->begin;

    if(!lista_nula(itens)){
        while(leitor != NULL && leitor->book->id != pos){
            leitor = leitor->next;
        }

        if(leitor != NULL){
            leitor->acess++;
            
            if(itens->begin != leitor){
                node *aux = leitor->last;

                while(aux != NULL && aux->acess <= leitor->acess){
                    leitor->last = aux->last;
                    aux->last = leitor;
                    aux->next = leitor->next;
                    leitor->next= aux;

                    if(leitor->last == NULL){
                        itens->begin = leitor;
                    }else{
                        leitor->last->next = leitor;
                    }

                    if(aux->next == NULL){
                        itens->end = aux;
                    }else{
                        aux->next->last = aux;
                    }

                    aux = leitor->last;
                }
            }

        }

    }

    return leitor;
}