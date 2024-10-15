#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int BemVindo (){
    char play[5];
    printf("Seja bem-vindo ao jogo HangMan\n");
    printf("Digite 'enter' para começar o jogo ou 'quit' para sair do jogo\n");
    scanf("%s", play);
    if(strcmp(play, "quit") == 0)
            return 1;
        else
            return 0;
}

void WinOrLose (int letras, int qtd_letras, int tentativas, char palavra[]){
    
    if(letras == qtd_letras){
            printf("You Win!\n");
            exit(0);
        } else if (tentativas == 7){
            printf("You Lose!\n");
            printf("A palavra era ");
            for (int i=0; i<qtd_letras; i++)
                printf("%c", palavra[i]);
            printf("\n");
            exit(0);
        }
}

int Tentativas(char letras[], int Numero_Tents, int Verificacao, int Quantidade_Letras, char palavra[]){
    printf("Digite a letra: ");
    scanf(" %c", &letras[Numero_Tents]);
    Numero_Tents++;
    printf("---------------------------------------\n");
    printf("Tentativa %d/6:", Numero_Tents);
    Verificacao = 0;
    for(int i=0; i<Quantidade_Letras; i++){
        if(strchr(letras, palavra[i])!=NULL){
            printf("%c", palavra[i]);
            Verificacao++;
        }
        else
            printf("_");
    }
    printf("\n");
    WinOrLose(Verificacao,Quantidade_Letras,Numero_Tents,palavra);
    return Numero_Tents;
}

void PrimeiraTentativa (int Quantidade_Letras) {
    printf("Tentativa 0/6:");
    for(int i=0; i<Quantidade_Letras; i++)
        printf("_");
    printf("\n");
}

int main () {
    char words[10][10] = {
        "gato",
        "pato",
        "flor",
        "agua",
        "mato",
        "amor",
        "rosa",
        "bola",
        "vida",
        "lobo",
    };
    int play2, qtd, random;

    srand(time(NULL));
    random = rand() % 11;
    qtd = strlen(words[random]);
    char word[qtd];

    for(int i=0; i<qtd; i++)
        word[i] = words[random][i];

    play2 = BemVindo();
    if(play2 == 1)
        exit(0);
    
    PrimeiraTentativa(qtd);
    
    char tent[6];
    int tents = 0, ver;

    while(1){
        tents = Tentativas(tent,tents,ver,qtd,word);
    }
}
