#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamRascunho 49 //quantidade de caracteres maximo que pode ser lido
#define quantInts 6 // numero de variaveis int necessarias 

int main (void) {

// ----------------------------- declaração do buffer -----------------------------
    void *pbuffer = malloc(sizeof(int) * quantInts + sizeof(char) * tamRascunho);

// ----------------------------- declaração das variaveis necessárias -----------------------------
    *(int*)pbuffer = 0; 

    int *peopleAdded = (int*)pbuffer + 1;  
    *peopleAdded = 0;

    int *count = peopleAdded + 1; 
    *count = 0;

    int *bufferEnd = count  + 1;
    *bufferEnd = (sizeof(int) * quantInts + sizeof(char) * tamRascunho);

    int *startOfAgenda = bufferEnd + 1;
    *startOfAgenda = (sizeof(int) * quantInts + sizeof(char) * tamRascunho);

    int *tamPalavra = startOfAgenda + 1;
    *tamPalavra = 0;    

    while(*(int*)pbuffer != 5){
        printf("Digite opcao:\n");
        printf("1- Adicionar Pessoa (Nome, Idade, email)\n2- Remover Pessoa\n3- Buscar Pessoa\n4- Listar todos\n5- Sair:\n");
        scanf("%d", &(*(int*)pbuffer));
        getchar();

        switch(*(int*)pbuffer){
            case 1: // -----------------------------------------------------------------------------------------------------------------------------------------------------------
                // ----------------------------- add name -----------------------------
                printf("Digite nome (maximo de %d caracteres):\n", tamRascunho);
                scanf("%[^\n]", (char*)pbuffer + sizeof(int) * quantInts ); // armazena no rascunho
                getchar();

                *tamPalavra = strlen((char*)pbuffer + sizeof(int) * quantInts);
                pbuffer = realloc(pbuffer, *bufferEnd + (*tamPalavra + 1) );

                peopleAdded = (int*)pbuffer + 1;  
                count = peopleAdded + 1; 
                bufferEnd = count  + 1;
                startOfAgenda = bufferEnd + 1;
                tamPalavra = startOfAgenda + 1;
                

                strcpy((char*)pbuffer + *bufferEnd, (char*)pbuffer + sizeof(int) * quantInts);
                *bufferEnd = *bufferEnd + (*tamPalavra + 1);

                // ----------------------------- add age -----------------------------

                pbuffer = realloc(pbuffer, *bufferEnd + sizeof(int));
                
                peopleAdded = (int*)pbuffer + 1;  
                count = peopleAdded + 1; 
                bufferEnd = count  + 1;
                startOfAgenda = bufferEnd + 1;
                tamPalavra = startOfAgenda + 1;

                printf("Digite idade:\n");
                scanf("%d", (int*)((char*)pbuffer + *bufferEnd)); // armazena no rascunho
                getchar();
                *bufferEnd = *bufferEnd + sizeof(int);

                // ----------------------------- add email -----------------------------
                printf("Digite email (maximo de %d caracteres):\n", tamRascunho);
                scanf("%[^\n]", (char*)pbuffer + sizeof(int) * quantInts ); // armazena no rascunho
                getchar();

                *tamPalavra = strlen( ((char*)pbuffer + sizeof(int) * quantInts) ); 
                pbuffer = realloc(pbuffer, *bufferEnd + (*tamPalavra + 1) );

                peopleAdded = (int*)pbuffer + 1;  
                count = peopleAdded + 1; 
                bufferEnd = count  + 1;
                startOfAgenda = bufferEnd + 1;
                tamPalavra = startOfAgenda + 1;
                
                strcpy((char*)pbuffer + *bufferEnd, (char*)pbuffer + sizeof(int) * quantInts);
                *bufferEnd = *bufferEnd + (*tamPalavra + 1);

                (*peopleAdded)++;
                
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
                printf("Digite nome para procurar:\n");
                scanf("%[^\n]", (char*)pbuffer + sizeof(int) * quantInts ); // armazena no rascunho
                getchar();
                *tamPalavra = strlen( ((char*)pbuffer + sizeof(int) * quantInts) );

                char *find = (char*)pbuffer + *startOfAgenda;
                
                while (*count < *peopleAdded){
                    if(strncmp((char*)pbuffer + sizeof(int) * quantInts, find, *tamPalavra) == 0){

                        printf("Pessoa encontrada:\n");
                        printf("Nome: %s\n", find);
                        find = find + strlen(find) + 1;
                        
                        printf("Idade: %d\n", *((int*)find));
                        find = find + sizeof(int);
                        
                        printf("Email: %s\n", find);
                        find = find + strlen(find) + 1;
                    }
                    else {
                        find = find + strlen(find) + 1 + sizeof(int);
                        find = find + + strlen(find) + 1;
                        (*count)++;
                    }
                }
                (*count) = 0;
            break;

            case 4: // -----------------------------------------------------------------------------------------------------------------------------------------------------------
                char *aux = (char*)pbuffer + *startOfAgenda;
                
                printf("Agenda:\n");
                if(*peopleAdded == 0) 
                    printf("Nenhuma pessoa adicionada!\n");

                while(*count < *peopleAdded){
                    printf("Nome: %s\n", aux);
                    aux = aux + strlen(aux) + 1;
                    
                    printf("Idade: %d\n", *((int*)aux));
                    aux = aux + sizeof(int);
                    
                    printf("Email: %s\n", aux);
                    aux = aux + strlen(aux) + 1;

                    (*count)++;
                }
                *count = 0;
                break;
            
        }

    }
    free(pbuffer);
}