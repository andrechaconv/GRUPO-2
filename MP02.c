#include <stdio.h>

void inverter(char *s);
void deslocar(char *s, int n);
void trocarParesImpares(char *s);
void inverterCaixa(char *s);
void rotacionar(char *s, int n);
void trocarMetades(char *s);


int main(){
    char *frase;
    int operacao = -1, num;
    scanf("%s", &frase);
    while (operacao != 0){
        scanf("%d", operacao);
        if (operacao == 1){
            inverter(frase);
        }
        else if (operacao == 2){
            scanf("%d", &num);
            deslocar(frase, num);
        }
        else if(operacao == 3){
            trocarParesImpares(frase);
        }
        else if(operacao == 4){
            inverterCaixa(frase);
        }
        else if(operacao == 5){
            scanf("%d", num);
            rotacionar(frase, num);
        }
        else if(operacao == 6){
            trocarMetades(frase);
        }
    }

    printf("%s\n", &frase);

    return 0;
}

void inverter(char *s){
    
}
