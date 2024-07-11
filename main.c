#include "include/bookList.h"

int main(){
    lista *list = create_list();
    char comand[12];

    setlocale(LC_ALL, "portuguese");

    scanf("%s", comand);

    while(strcmp(comand, "para")){
        if(!strcmp(comand, "add")){
            int id;
            char titulo[100];
            char desc[300];
            float preco;
            unsigned int pgs;

            scanf("%d %s %s %f %d", &id, titulo, desc, &preco, &pgs);
            add_book(list, id, titulo, desc, preco, pgs);
            imprime_books(list);

        }else if(!strcmp(comand, "view")){
            int id;

            scanf("%d", &id);

            node *comp = search_item(list, id);
            if(comp != NULL){
                imprime_item(comp);
            }else{
                printf("\nElemento não encontrado");
            }

        }else{
            printf("\nComando inexistente");
        }

        scanf("%s", comand);
    }

    lista_books(list);
    list_destroy(&list);

    return 0;
}