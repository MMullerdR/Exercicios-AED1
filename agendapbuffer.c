#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamRascunho 50 // quantidade de caracteres maximo que pode ser lido
#define quantInts 7 // numero de variaveis int necessarias

int main ( void ) {

    // ----------------------------- buffer único -----------------------------
    void *pbuffer = malloc ( sizeof ( int ) * quantInts + tamRascunho );

    if ( pbuffer == NULL ) {
        printf ( "Erro de memoria\n" );
        return 1;
    }

    // ----------------------------- controle interno dentro do buffer -----------------------------
    int *opcao = ( int * ) pbuffer;
    int *peopleAdded = opcao + 1;
    int *count = opcao + 2;
    int *bufferEnd = opcao + 3;
    int *startOfAgenda = opcao + 4;
    int *temp = opcao + 5;

    char *rascunho = ( char * ) ( opcao + quantInts );

    // inicialização
    *opcao = 0;
    *peopleAdded = 0;
    *count = 0;
    *temp = 0;

    *startOfAgenda = sizeof ( int ) * quantInts + tamRascunho;
    *bufferEnd = *startOfAgenda;

	printf( "--------------- Agenda Buffer ---------------" );

    // ----------------------------- loop principal -----------------------------
    while ( *opcao != 5 ) {

		printf( "\nDigite opcao:\n" );
        printf ( "\n1- Adicionar\n2- Remover\n3- Buscar\n4- Listar\n5- Sair\n" );
        scanf ( "%d", opcao );
        getchar ();

        switch ( *opcao ) {

        // ============================================================
        case 1: {

            // ----------------------------- NOME -----------------------------
            printf ( "Nome:\n" );
            scanf ( "%49[^\n]", rascunho ); // armazena no rascunho
            getchar ();

            *temp = strlen ( rascunho ) + 1;

            pbuffer = realloc ( pbuffer, *bufferEnd + *temp );
            if ( pbuffer == NULL ) {
                return 1;
            }

            // atualiza os ponteiros apos realloc
            opcao = ( int * ) pbuffer;
            peopleAdded = opcao + 1;
            count = opcao + 2;
            bufferEnd = opcao + 3;
            startOfAgenda = opcao + 4;
            temp = opcao + 5;
            rascunho = ( char * ) ( opcao + quantInts );

            char *agenda = ( char * ) pbuffer + *bufferEnd;

            strcpy ( agenda, rascunho );
            agenda += *temp;
            *bufferEnd += *temp;

            // ----------------------------- IDADE -----------------------------
            pbuffer = realloc ( pbuffer, *bufferEnd + sizeof ( int ) );
            if ( pbuffer == NULL ) {
                return 1;
            }

            // atualiza os ponteiros apos realloc
            opcao = ( int * ) pbuffer;
            peopleAdded = opcao + 1;
            count = opcao + 2;
            bufferEnd = opcao + 3;
            startOfAgenda = opcao + 4;
            temp = opcao + 5;
            rascunho = ( char * ) ( opcao + quantInts );

            agenda = ( char * ) pbuffer + *bufferEnd;

            printf ( "Idade:\n" );
            scanf ( "%d", ( int * ) agenda ); // armazena no rascunho
            getchar ();

            agenda += sizeof ( int );
            *bufferEnd += sizeof ( int );

            // ----------------------------- EMAIL -----------------------------
            printf ( "Email:\n" );
            scanf ( "%49[^\n]", rascunho ); // armazena no rascunho
            getchar ();

            *temp = strlen ( rascunho ) + 1;

            pbuffer = realloc ( pbuffer, *bufferEnd + *temp );
            if ( pbuffer == NULL ) {
                return 1;
            }

            // atualiza os ponteiros apos realloc
            opcao = ( int * ) pbuffer;
            peopleAdded = opcao + 1;
            count = opcao + 2;
            bufferEnd = opcao + 3;
            startOfAgenda = opcao + 4;
            temp = opcao + 5;
            rascunho = ( char * ) ( opcao + quantInts );

            agenda = ( char * ) pbuffer + *bufferEnd;

            strcpy ( agenda, rascunho );
            *bufferEnd += *temp;

            ( *peopleAdded )++;

            break;
        }

        // ============================================================
        case 2: {

            printf ( "Nome da pessoa que deseja remover:\n" );
            scanf ( "%49[^\n]", rascunho ); // armazena no rascunho
            getchar ();

            char *p = ( char * ) pbuffer + *startOfAgenda;
            *count = 0;

            while ( *count < *peopleAdded ) {

                char *nome = p;
                char *idade = nome + strlen ( nome ) + 1;
                char *email = idade + sizeof ( int );

                if ( strcmp ( rascunho, nome ) == 0 ) {

					printf ( "Informacoes da pessoa a ser removida:\n" );
					printf ( "Nome: %s\n", nome );
                    printf ( "Idade: %d\n", *( int * ) idade );
                    printf ( "Email: %s\n", email );

                    *temp = strlen ( nome ) + 1 + sizeof ( int ) + strlen ( email ) + 1;
                    // numero de bytes de nome + idade + email da pessoa a ser apagada

                    memmove ( p, p + *temp, // posicao destino, primeira posicao apos os dados da pessoa encontrada
                        *bufferEnd - ( ( p - ( char * ) pbuffer ) + *temp ) ); // numero de bytes que precisarão ser deslocados

                    *bufferEnd -= *temp;
                    ( *peopleAdded )--;

                    pbuffer = realloc ( pbuffer, *bufferEnd );
                    if ( pbuffer == NULL && *bufferEnd > 0 ) {
                        return 1;
                    }

                    // atualiza os ponteiros apos realloc
                    opcao = ( int * ) pbuffer;
                    peopleAdded = opcao + 1;
                    count = opcao + 2;
                    bufferEnd = opcao + 3;
                    startOfAgenda = opcao + 4;
                    temp = opcao + 5;
                    rascunho = ( char * ) ( opcao + quantInts );

					printf ( "Pessoa removida com sucesso!\n" );

                    break;
                }

                p = email + strlen ( email ) + 1;
                ( *count )++;
            }

            *count = 0;
            break;
        }

        // ============================================================
        case 3: {

            printf ( "Buscar nome:\n" );
            scanf ( "%49[^\n]", rascunho ); // armazena no rascunho
            getchar ();

            char *p = ( char * ) pbuffer + *startOfAgenda;
            *count = 0;

            while ( *count < *peopleAdded ) {

                char *nome = p;
                char *idade = nome + strlen ( nome ) + 1;
                char *email = idade + sizeof ( int );

                if ( strcmp ( rascunho, nome ) == 0 ) {

                    printf ( "Nome: %s\n", nome );
                    printf ( "Idade: %d\n", *( int * ) idade );
                    printf ( "Email: %s\n", email );
                    break;
                }

                p = email + strlen ( email ) + 1;
                ( *count )++;
            }

            *count = 0;
            break;
        }

        // ============================================================
        case 4: {

            char *p = ( char * ) pbuffer + *startOfAgenda;
            *count = 0;

			if ( *peopleAdded == 0 ) {
				printf ( "Nenhuma pessoa adicionada.\n" );
			}
			
            while ( *count < *peopleAdded ) {

                char *nome = p;
                char *idade = nome + strlen ( nome ) + 1;
                char *email = idade + sizeof ( int );

                printf ( "Nome: %s\n", nome );
                printf ( "Idade: %d\n", *( int * ) idade );
                printf ( "Email: %s\n", email );

                p = email + strlen ( email ) + 1;
                ( *count )++;
            }

            *count = 0;
            break;
        }
        }
    }

    free ( pbuffer );
    return 0;
}