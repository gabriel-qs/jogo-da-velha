#include <stdio.h>
#include <stdlib.h>

//funcao que exibe o tabuleiro
void exibindoTabuleiro(char tab[3][3]){
    printf("%c | %c | %c\n", tab[0][0], tab[0][1], tab[0][2]);
    printf("--------------\n");
    printf("%c | %c | %c\n", tab[1][0], tab[1][1], tab[1][2]);
    printf("--------------\n");
    printf("%c | %c | %c\n", tab[2][0], tab[2][1], tab[2][2]);
}


/*Funcao para determinar se o numero digitado é valido.*/
/*É acessado a matriz correspondente ao numero digitado e verificado se tem o caractere 'x' ou '0'*/
/*
 0 - invalido
 1 - valido
 */
int validando(int num, char tab[3][3]){
    switch(num){
        case 1:
            if(tab[0][0] == 'x' || tab[0][0] == 'o'){
                printf("Você digitou uma posição ja preenchida anteriomente.\n");
                printf("Digite novamente!\n");
                return (0);
            }
            else{
                return(1);
            }
        break;
        case 2:
            if(tab[0][1] == 'x' || tab[0][1] == 'o'){
                printf("Você digitou uma posição ja preenchida anteriomente.\n");
                printf("Digite novamente!\n");
                return (0);
            }
            else{
                return(1);
            }
        break;
        case 3:
            if(tab[0][2] == 'x' || tab[0][2] == 'o'){
                printf("Você digitou uma posição ja preenchida anteriomente.\n");
                printf("Digite novamente!\n");
                return (0);
            }
            else{
                return(1);
            }
        break;
        case 4:
            if(tab[1][0] == 'x' || tab[1][0] == 'o'){
                printf("Você digitou uma posição ja preenchida anteriomente.\n");
                printf("Digite novamente!\n");
                return (0);
            }
            else{
                return(1);
            }
        break;
        case 5:
            if(tab[1][1] == 'x' || tab[1][1] == 'o'){
                printf("Você digitou uma posição ja preenchida anteriomente.\n");
                printf("Digite novamente!\n");
                return (0);
            }
            else{
                return(1);
            }
        break;
        case 6:
            if(tab[1][2] == 'x' || tab[1][2] == 'o'){
                printf("Você digitou uma posição ja preenchida anteriomente.\n");
                printf("Digite novamente!\n");
                return (0);
            }
            else{
                return(1);
            }
        break;
        case 7:
            if(tab[2][0] == 'x' || tab[2][0] == 'o'){
                printf("Você digitou uma posição ja preenchida anteriomente.\n");
                printf("Digite novamente!\n");
                return (0);
            }
            else{
                return(1);
            }
        break;
        case 8:
            if(tab[2][1] == 'x' || tab[2][1] == 'o'){
                printf("Você digitou uma posição ja preenchida anteriomente.\n");
                printf("Digite novamente!\n");
                return (0);
            }
            else{
                return(1);
            }
        break;
        case 9:
            if(tab[2][2] == 'x' || tab[2][2] == 'o'){
                printf("Você digitou uma posição ja preenchida anteriomente.\n");
                printf("Digite novamente!\n");
                return (0);
            }
            else{
                return(1);
            }
        break;
        default:
            printf("Foi digitado um valor invalido. Tente novamente.\n");
            return(0);
        break;
       
    }
}


//Funcao para inserir caracteres 'x' ou 'o' no tabuleiro
void inserindoCaratere(int num, char tab[3][3], int v, int *r){
   /*
    num - numero escolhido pelo usuario.
    tab - tabuleiro.
    v - qual o jogador que digitou nesta rodada.
    r - ponteiro que aponta para a variável 'rodada'.
*/
   int cont = 0;
   const int X = 22;
   const int O = 33;

   for(int i = 0; i < 3; i++){
       for(int j = 0; j < 3; j++){
           cont++;
           //quando o contador for igual a num, é armazenado 'x'.
           if(cont == num && v == X){
               tab[i][j] = 'x';
               *r = *r + 1;
               break;
           }
           //quando o contador for igual a num, é armazenado 'o'.
           if(cont == num && v == O){
               tab[i][j] = 'o';
               *r = *r + 1;
               break;
           }
       }
   }
}


//funcao que verifica se o jogador x venceu
//retorna 1 se sim
//retorna 0 se nao
int VerificandoJogadorX(char tab[3][3]){
    //linha
    for(int i = 0; i < 3; i++){
        if((tab[0][i] == 'x') && (tab[1][i] == 'x') && (tab[2][i] == 'x')){
            return(1);
        }
    }
    //coluna
    for(int i = 0; i < 3; i++){
        if((tab[i][0] == 'x') && (tab[i][1] == 'x') && (tab[i][2] == 'x')){
            return(1);
        }
    }
    //diagonal principal
    if((tab[0][0] == 'x') && (tab[1][1] == 'x') && (tab[2][2] == 'x')){
        return(1);
    }
    //diagonal
    if((tab[0][2] == 'x') && (tab[1][1] == 'x') && (tab[2][0] == 'x')){
        return(1);
    }
    return(0);
}


//funcao que verifica se o jogador 'o' venceu
//retorna 2 se sim
//retorna 0 se nao
int VerificandojogadorO(char tab[3][3]){   
    //linha
    for(int i = 0; i < 3; i++){
        if((tab[0][i] == 'o') && (tab[1][i] == 'o') && (tab[2][i] == 'o')){
            return(2);
        }
    }
    //coluna
    for(int i = 0; i < 3; i++){
        if((tab[i][0] == 'o') && (tab[i][1] == 'o') && (tab[i][2] == 'o')){
            return(2);
        }
    }
    //diagonal
    if((tab[0][0] == 'o') && (tab[1][1] == 'o') && (tab[2][2] == 'o')){
        return(2);
    }
    if((tab[0][2] == 'o') && (tab[1][1] == 'o') && (tab[2][0] == 'o')){
        return(2);
    }
    return(0);
}


void verificandoVelha(int *resul, int r){
   if((r == 9) && (*resul == 0))
        *resul = 3;
}


void exibindoResultado(int resul){
    printf("Resultado: ");
    if(resul == 1){
        printf("Jogador X ganhou!\n");
    }
    else if(resul == 2) {
        printf("Jogador O ganhou!\n");
    }
    else{
        printf("Deu velha!\n");
    }
}

int main(){

    int NumEscolhido;
    char tabuleiro[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6',},
        {'7', '8', '9'}
    };
    int vez; //Define a vez de cada jogador
    int resposta = 0; //define se o looping continua ou para
    int rodada = 0; //calcula em que rodada o programa esta
    int resultado = 0; //define o resultado da partida

    const int X = 22; //numero que identifica a vez do jogador 'x'.
    const int O = 33; //numero que identifica a vez do jogador 'o'.
    vez == X;


    printf("-->JOGO DA VELHA<--\n\n");
    do{
        if(vez == X){
            printf("Vez do jogador 'x'\n");
        }
        else{
            printf("Vez do jogador 'o'\n");
        }
        exibindoTabuleiro(tabuleiro); 

        printf("Digite um número: ");
        do{
            scanf("%d", &NumEscolhido);
            resposta = validando(NumEscolhido, tabuleiro);       
        }while(resposta != 1);

        inserindoCaratere(NumEscolhido, tabuleiro, vez, &rodada); //insere o caractere no tabuleiro
       
        //estrutura que verifica as posssibilidades de 'x' e 'o'
        if(vez == X){
            resultado = VerificandoJogadorX(tabuleiro);
            vez = O; //muda a vez para o jogador 'o'
        }
        else{
            resultado = VerificandojogadorO(tabuleiro);
            vez = X; //muda a vez para o jogador 'x'.
        }
        verificandoVelha(&resultado, rodada); //verifica se deu velha
        system("cls"); //limpa a tela - versão windows
    }while(resultado != 1 && resultado != 2 && resultado != 3);
    

    exibindoResultado(resultado); //exibe o vencedor
    exibindoTabuleiro(tabuleiro); //mostra o tabuleiro

    printf("Fim de jogo!\n");

    return 0;
}

