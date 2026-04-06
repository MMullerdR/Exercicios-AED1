#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    
    int opcaoMenu = 0;
    int tamanho = 0, tam_del = 0;
    char letra;
    
    char *string = malloc((tamanho + 1) * sizeof(*string));
    char *str_del = malloc((tam_del + 1) * sizeof(*str_del));  
    string[0] = '\0';
    str_del[0] = '\0';

    while ( opcaoMenu != 4 ) {
        printf("MENU - Digite opcao:\n");
        printf("1. Adicionar nome\n");
        printf("2. Remover nome\n");
        printf("3. Listar\n");
        printf("4. Sair\n\n");
        scanf("%d", &opcaoMenu);
        getchar();
       
        
        switch(opcaoMenu){
            case 1:
                printf("Digite nome: \n");
                while((letra = getchar()) != '\n'){
                    
                    string = realloc(string, (tamanho + 2) * sizeof(*string));
                    string[tamanho] = letra;
                    tamanho++;
                    
                }
                string[tamanho] = '\0';
                tamanho++; 
                
                printf("Nome adicionado!");
                break;

            case 2: //remover nome
                // //===========lê string de tamanho indeterminado para ler palavra para deletar===========
                // printf("Digite nome para deletar: \n");
                // while((letra = getchar()) != '\n'){
                    
                //     str_del = realloc(str_del, (tam_del + 2) * sizeof(*str_del));
                //     str_del[tam_del] = letra;
                //     tam_del++;
                    
                // }
                // str_del[tam_del] = '\0';
                // tam_del++; 
                // //======================================================================================
                // int tam_palavra = 0;
                // while(){
                    
                //     while(string[tam_palavra] != '\0'){
                //         tam_palavra++;
                //     }
                //     char palavra1[tam_palavra];
                //     //morri aqui
                // }
                // strcmp(palavra1, palavra2)

                // break;
        
            case 3: //listar

                for(int i = 0; i < tamanho; i++){
                    if(string[i] == '\0'){
                        printf("\n");
                    }
                    else{
                        printf("%c", string[i]);
                    }
                }
                break;
        }
    }
    printf("Programa encerrado!");
    free(string);
    return 0;
}



/*



while ( opcaoMenu != 4 ) {
    printf("MENU - Digite opcao:\n");
    printf("1. Digite nome:\n");
    printf("2. Remover nome\n");
    printf("3. Listar\n");
    printf("4. Sair\n\n");
    scanf("%d", opcaoMenu);




switch ( opcaoMenu ) {
            case 1:

 break;
            
            

*/