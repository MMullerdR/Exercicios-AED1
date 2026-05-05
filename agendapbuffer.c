#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamName 30
#define tamEmail 30
  
/*
char nome[30]
int idade
char email[30]
*/

int main (void) {
    void *pbuffer = malloc(sizeof(int) * 3 + sizeof(char) * tamName);

    *(int*)pbuffer = 0; // menu option (first int space of buffer)

    int *peopleAdded = (int*)pbuffer;  // number of added persons 
    peopleAdded++;
    *peopleAdded = 0;

    int *count = peopleAdded; // counter 
    count++;
    *count = 0;
    

    while(*(int*)pbuffer != 5){
        printf("Digite opcao:\n");
        printf("1- Adicionar Pessoa (Nome, Idade, email)\n2- Remover Pessoa\n3- Buscar Pessoa\n4- Listar todos\n5- Sair:\n");
        scanf("%d", &(*(int*)pbuffer));
        getchar();

        switch(*(int*)pbuffer){
            case 1: // -----------------------------------------------------------------------------------------------------------------------------------------------------------
                (*peopleAdded)++;
                pbuffer = realloc(pbuffer, (sizeof(int) * 3 + sizeof(char) * tamName) + (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * *peopleAdded); // menu, people added, count, (name, age, email)...
                printf("Digite nome (máximo 30 caracteres):\n");
                scanf("%29[^\n]", (char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) ) * (*peopleAdded - 1) );
                getchar();
                
                printf("Digite idade:\n");
                scanf("%d", (int*)((char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*peopleAdded - 1) ) + (sizeof(char) * tamName) ));
                getchar();
                
                printf("Digite email (máximo 30 caracteres):\n");
                scanf("%29[^\n]", (char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*peopleAdded - 1) ) + (sizeof(char) * tamName) + (sizeof(int)) );
                getchar();
                
                
            break;
                
            case 2: // -----------------------------------------------------------------------------------------------------------------------------------------------------------
                // char *searchName = (char*)pbuffer + (sizeof(int) * 3);
                // printf("Digite nome para deletar dados da agenda:\n");
                // scanf("%29[^\n]", (char*)pbuffer + (sizeof(int) * 3)); 
                // getchar();

                // void *andarbuffer = searchName;
                // andarbuffer = andarbuffer + 30 * sizeof(char);

                // while (*count < *peopleAdded){
                //     if(strncmp(searchName, (char*)andarbuffer + ((sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count)), 29) == 0){
                //         printf("Pessoa encontrada:\n");
                //         printf("Nome : %.29s\n", (char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count)));
                //         printf("Idade: %d\n", *((int*)((char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count) + (sizeof(char) * tamName)))));
                //         printf("Email: %.29s\n\n", (char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count) ) + (sizeof(char) * tamName) + (sizeof(int)) );
                //     }
                //     (*count)++;
                // }

                // while()




                // (*count) = 0;
            break;

            case 3: // -----------------------------------------------------------------------------------------------------------------------------------------------------------
                char *searchName = (char*)pbuffer + (sizeof(int) * 3);
                printf("Digite nome para procurar:\n");
                scanf("%29[^\n]", (char*)pbuffer + (sizeof(int) * 3)); 
                getchar();

                void *andarbuffer = searchName;
                andarbuffer = andarbuffer + 30 * sizeof(char);

                while (*count < *peopleAdded){
                    if(strncmp(searchName, (char*)andarbuffer + ((sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count)), 29) == 0){
                        printf("Pessoa encontrada:\n");
                        printf("Nome : %.29s\n", (char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count)));
                        printf("Idade: %d\n", *((int*)((char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count) + (sizeof(char) * tamName)))));
                        printf("Email: %.29s\n\n", (char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count) ) + (sizeof(char) * tamName) + (sizeof(int)) );
                    }
                    (*count)++;
                }
                (*count) = 0;
            break;

            case 4: // -----------------------------------------------------------------------------------------------------------------------------------------------------------
                printf("Agenda:\n");
                while(*count < *peopleAdded){
                    printf("Nome: %.29s\n", (char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count)));
                    printf("Idade: %d\n", *((int*)((char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count) + (sizeof(char) * tamName)))));
                    printf("Email: %.29s\n\n", (char*)pbuffer + (sizeof(int) * 3 + sizeof(char) * tamName) + ( (sizeof(char) * tamName + sizeof(int) + sizeof(char) * tamEmail) * (*count) ) + (sizeof(char) * tamName) + (sizeof(int)) );
                  
                    (*count)++;
                }
                *count = 0;
                break;
            
        }

    }
    free(pbuffer);
}