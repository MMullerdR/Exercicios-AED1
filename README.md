# Arquitetura e Organização de Computadores - Trabalho agenda com Buffer
# Miguel Muller da Rosa
# Matrícula: 25100780
# Turma m1
---

Agenda
Faça uma agenda com o seguinte menu:
1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
 
O desafio é não poder criar variáveis e sim um buffer de memória (void *pBuffer). Nisso vocês terão que fazer o trabalho que o Sistema Operacional faz para vocês ao organizar a memória.
 
Regras:
Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
Exemplo: int *ptr = (int *)pBuffer
Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
Todas as strings que ficarem dentro do pBuffer deve ter somente o tamanho necessário, somente um buffer para receber o que o usuário digita no scanf pode ter um tamanho fixo.
Não pode usar struct em todo o programa.
Entregar link de um vídeo explicando o código e mostrando alguns testes e ao final o resultado do DrMemory ou Valgrind.
Vou perguntar no 1:1 sobre a sua implementação. Posso pedir para fazer alguma modificação no código na nossa conversa. O objetivo é saber se entenderam o que fizeram.
Veja nos vídeos feitos pelos monitores dicas para esse trabalho (o vídeo do monitor sobre o pBuffer não segue todas às regras, quando ele fez o vídeo eram regras diferentes). 
Motivação para fazer o trabalho: Desempenho e entender o hardware onde programamos.