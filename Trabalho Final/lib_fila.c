// lib_fila.c 

//marcar inicio da fila
//       e final dela tbm

// tamanho da fila -> qtos elementos ESTAO na fila

// comprimento fila -> no caso será passado pelo usuário

//inserir na fila
    // cria novo elemento

    // verifica se tem espaço
        // tam < comp
        // overflow:
            // se tam = comprimento
                // não adiciona novo elemento na fila

    //insere na fila
        // enqueue (fila f, elemento x)

    // atualiza o fim da fila

// remover da fila
    // obtem o primero pedido

    // atualiza o inicio 
        // apontando para o próximo

    // libera a memória (do elemento removido)
        // dequeue (fila f)
        // underflow:
            // se inicio = final 
                // fila está vazia





/* ---------------------------------------------------------- */
// ADICIONAR NO MAKEFILE:

        //lib_fila.o: lib_fila.c lib_fila.h
	        //gcc $(CFLAGS) -c lib_fila.c -lncurses -ltinfo