#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamRascunho 50 // quantidade de caracteres maximo que pode ser lido
#define quantInts 6 // numero de variaveis int necessarias

int main( void ) {

	// ----------------------------- declaração do buffer -----------------------------
	void *pbuffer = malloc( sizeof( int ) * quantInts + sizeof( char ) * tamRascunho );

	if ( pbuffer == NULL ) {
		printf( "Erro de memoria\n" );
		free( pbuffer );
		return 1;
	}

	// ----------------------------- declaração das variaveis necessárias -----------------------------
	*( int * )pbuffer = 0;

	int *peopleAdded = ( int * )pbuffer + 1;
	*peopleAdded = 0;

	int *count = peopleAdded + 1;
	*count = 0;

	int *bufferEnd = count + 1;
	*bufferEnd = ( sizeof( int ) * quantInts + sizeof( char ) * tamRascunho );

	int *startOfAgenda = bufferEnd + 1;
	*startOfAgenda = ( sizeof( int ) * quantInts + sizeof( char ) * tamRascunho );

	int *tamPalavra = startOfAgenda + 1;
	*tamPalavra = 0;

	// ----------------------------- repeticao do menu -----------------------------
	while ( *( int * )pbuffer != 5 ) {

		printf( "\nDigite opcao:\n" );
		printf( "1- Adicionar Pessoa (Nome, Idade, email)\n2- Remover Pessoa\n3- Buscar Pessoa\n4- Listar todos\n5- Sair:\n" );

		scanf( "%d", &( *( int * )pbuffer ) );
		getchar();

		switch ( *( int * )pbuffer ) {

			case 1: // -----------------------------------------------------------------------------------------

				// ----------------------------- add name -----------------------------
				printf( "Digite nome (maximo de %d caracteres):\n", tamRascunho );
				scanf( "%49[^\n]", ( char * )pbuffer + sizeof( int ) * quantInts ); // armazena no rascunho
				getchar();

				*tamPalavra = strlen( ( char * )pbuffer + sizeof( int ) * quantInts );
				pbuffer = realloc( pbuffer, *bufferEnd + ( *tamPalavra + 1 ) );

				if ( pbuffer == NULL ) {
					printf( "Erro de memoria\n" );
					free( pbuffer );
					return 1;
				}

				// atualiza os ponteiros apos realloc
				peopleAdded = ( int * )pbuffer + 1;
				count = peopleAdded + 1;
				bufferEnd = count + 1;
				startOfAgenda = bufferEnd + 1;
				tamPalavra = startOfAgenda + 1;

				strcpy( ( char * )pbuffer + *bufferEnd, ( char * )pbuffer + sizeof( int ) * quantInts );
				*bufferEnd = *bufferEnd + ( *tamPalavra + 1 );

				// ----------------------------- add age -----------------------------
				pbuffer = realloc( pbuffer, *bufferEnd + sizeof( int ) );

				if ( pbuffer == NULL ) {
					printf( "Erro de memoria\n" );
					free( pbuffer );
					return 1;
				}

				// atualiza os ponteiros apos realloc
				peopleAdded = ( int * )pbuffer + 1;
				count = peopleAdded + 1;
				bufferEnd = count + 1;
				startOfAgenda = bufferEnd + 1;
				tamPalavra = startOfAgenda + 1;

				printf( "Digite idade:\n" );
				scanf( "%d", ( int * )( ( char * )pbuffer + *bufferEnd ) ); // armazena no rascunho
				getchar();

				*bufferEnd = *bufferEnd + sizeof( int );

				// ----------------------------- add email -----------------------------
				printf( "Digite email (maximo de %d caracteres):\n", tamRascunho );
				scanf( "%49[^\n]", ( char * )pbuffer + sizeof( int ) * quantInts ); // armazena no rascunho
				getchar();

				*tamPalavra = strlen( ( char * )pbuffer + sizeof( int ) * quantInts );
				pbuffer = realloc( pbuffer, *bufferEnd + ( *tamPalavra + 1 ) );

				if ( pbuffer == NULL ) {
					printf( "Erro de memoria\n" );
					free( pbuffer );
					return 1;
				}

				// atualiza os ponteiros apos realloc
				peopleAdded = ( int * )pbuffer + 1;
				count = peopleAdded + 1;
				bufferEnd = count + 1;
				startOfAgenda = bufferEnd + 1;
				tamPalavra = startOfAgenda + 1;

				strcpy( ( char * )pbuffer + *bufferEnd, ( char * )pbuffer + sizeof( int ) * quantInts );
				*bufferEnd = *bufferEnd + ( *tamPalavra + 1 );

				( *peopleAdded )++;

				break;

			case 2: // -----------------------------------------------------------------------------------------

				printf( "Digite nome para excluir:\n" );
				scanf( "%49[^\n]", ( char * )pbuffer + sizeof( int ) * quantInts ); // armazena no rascunho
				getchar();

				char *find = ( char * )pbuffer + *startOfAgenda;

				while ( *count < *peopleAdded ) {

					if ( strcmp( ( char * )pbuffer + sizeof( int ) * quantInts, find ) == 0 ) {

						printf( "Pessoa encontrada\n" );
						printf( "Nome: %s\n", find );

						*tamPalavra = ( ( strlen( find ) + 1 ) + sizeof( int ) + ( strlen( find + strlen( find ) + 1 + sizeof( int ) ) + 1 ) );

						// numero de bytes de nome + idade + email da pessoa a ser apagada
						memmove(
							find, // posicao destino
							find + ( strlen( find ) + 1 ) + sizeof( int ) + ( strlen( find + strlen( find ) + 1 + sizeof( int ) ) + 1 ),
							// primeira posicao apos os dados da pessoa encontrada
							*bufferEnd - ( find - ( char * )pbuffer + ( strlen( find ) + 1 ) + sizeof( int ) + ( strlen( find + strlen( find ) + 1 + sizeof( int ) ) + 1 ) )
							// numero de bytes que precisarão ser deslocados
						);

						// atualiza os ponteiros apos realloc
						pbuffer = realloc( pbuffer, *bufferEnd - *tamPalavra );

						if ( pbuffer == NULL ) {
							printf( "Erro de memoria\n" );
							free( pbuffer );
							return 1;
						}

						*bufferEnd = *bufferEnd - *tamPalavra;

						peopleAdded = ( int * )pbuffer + 1;
						count = peopleAdded + 1;
						bufferEnd = count + 1;
						startOfAgenda = bufferEnd + 1;
						tamPalavra = startOfAgenda + 1;

						( *peopleAdded )--;

						printf( "Pessoa excluida!\n" );

						break;

					} else {

						find = find + strlen( find ) + 1 + sizeof( int ); // tamanho do nome + int
						find = find + strlen( find ) + 1; // tamanho do email

						( *count )++;
					}
				}

				( *count ) = 0;

				break;

			case 3: // -----------------------------------------------------------------------------------------

				printf( "Digite nome para procurar:\n" );
				scanf( "%49[^\n]", ( char * )pbuffer + sizeof( int ) * quantInts ); // armazena no rascunho
				getchar();

				*tamPalavra = strlen( ( char * )pbuffer + sizeof( int ) * quantInts );

				find = ( char * )pbuffer + *startOfAgenda;

				while ( *count < *peopleAdded ) {

					if ( strcmp( ( char * )pbuffer + sizeof( int ) * quantInts, find ) == 0 ) {

						printf( "Pessoa encontrada:\n" );
						printf( "Nome: %s\n", find );
						find = find + strlen( find ) + 1;

						printf( "Idade: %d\n", *( ( int * )find ) );
						find = find + sizeof( int );

						printf( "Email: %s\n\n", find );
						find = find + strlen( find ) + 1;

					} else {

						find = find + strlen( find ) + 1 + sizeof( int ); // tamanho do nome + int
						find = find + strlen( find ) + 1; // tamanho do email
					}

					( *count )++;
				}

				( *count ) = 0;

				break;

			case 4: // -----------------------------------------------------------------------------------------

				char *aux = ( char * )pbuffer + *startOfAgenda;

				printf( "Agenda:\n" );

				if ( *peopleAdded == 0 ) {
					printf( "Nenhuma pessoa adicionada!\n" );
				}

				while ( *count < *peopleAdded ) {

					printf( "Nome: %s\n", aux );
					aux = aux + strlen( aux ) + 1;

					printf( "Idade: %d\n", *( ( int * )aux ) );
					aux = aux + sizeof( int );

					printf( "Email: %s\n\n", aux );
					aux = aux + strlen( aux ) + 1;

					( *count )++;
				}

				*count = 0;

				break;
		}
	}

	free( pbuffer );

	return 0;
}