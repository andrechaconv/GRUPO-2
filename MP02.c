#include <stdio.h>
#include <stdlib.h>

int strlength(char* s);
void inverter(char *s);
void deslocar(char *s, int n);
void trocarParesImpares(char *s);
void inverterCaixa(char *s);
void rotacionar(char *s, int n);
void trocarMetades(char *s);

int main(){
    char *frase = malloc(10001*sizeof(char));
    int operacao = -1, num;
    fgets(frase, 10001, stdin);
    while (operacao != 0){
        scanf("%d", &operacao);
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
            scanf("%d", &num);
            rotacionar(frase, num);
        }
        else if(operacao == 6){
            trocarMetades(frase);
        }
    }

    printf("%s", frase);

    free(frase);
    return 0;
}

int strlength(char* s){
    int len = 0;
    char ponteiro = s[len];
    while (ponteiro != '\0'){
        len++;
        ponteiro = s[len];
    }
    return len-1;
}

void inverter(char *s){
    int len = strlength(s), j = len-1;
    char temp;
    for (int i = 0; i < len/2; i++){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j--;
    }
}

void deslocar(char *s, int n){
    int len = strlength(s);
    for (int i = 0; i < len; i++){
        if (n > 0){
            for (int j = 0; j < n; j++){
                if (s[i] > 47 && s[i] < 58){
                    if (s[i]+ 1 >= 58){
                        s[i] = 48;
                    }
                    else s[i]++;
                }
                else if (s[i] > 96 && s[i] < 123){
                    if (s[i]+ 1 >= 123){
                        s[i] = 97;
                    }
                    else s[i]++;
                }
                else if (s[i] > 64 && s[i] < 91){
                    if (s[i]+ 1 >= 91){
                        s[i] = 65;
                    }
                    else s[i]++;
                }
            }
        }
        else if (n < 0){
            for (int j = 0; j > n; j--){
                if (s[i] > 47 && s[i] < 58){
                    if (s[i]- 1 <= 47){
                        s[i] = 57;
                    }
                    else s[i]--;
                }
                else if (s[i] > 96 && s[i] < 123){
                    if (s[i] - 1 <= 96){
                        s[i] = 122;
                    }
                    else s[i]--;
                }
                else if (s[i] > 64 && s[i] < 91){
                    if (s[i] - 1 <= 64){
                        s[i] = 90;
                    }
                    else s[i]--;
                }
            }
        }
    }
}

void trocarParesImpares(char *s){
    int len = strlength(s), temp;
    for (int i = 0; i < len; i++){
        if (s[i+1] != '\n' && i%2 == 0){
            temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
        }
    }
}

void inverterCaixa(char *s){
    int len = strlength(s), temp;
    for (int i = 0; i < len; i++){
        if (s[i] > 64 && s[i] < 91) s[i] += 32;
        else if (s[i] > 96 && s[i] < 123) s[i] -= 32;
    }
}

void rotacionar(char *s, int n){
    char frase[10001];
    int len = strlength(s), ContadorGiros;
    for (int i = 0; i < len; i++){
        frase[i] = s[i];
    }
    for (int i = 0; i < len; i++){
        ContadorGiros = i;
        for (int j = 0; j < n; j++){
            ContadorGiros++;
            if (ContadorGiros >= len) ContadorGiros = 0;
        }
        s[ContadorGiros] = frase[i];
    }
}

void trocarMetades(char *s){
    int len = strlength(s)-1, temp;
    int j = len/2+1;
    for (int i = 0; i < j-1; i++){
        if (j <= len){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            j++;
        }
    }
}
