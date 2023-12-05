//Isoamento social parcial
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

int chance(int n){
    int propabilidade = rand()%n;
    return propabilidade;
}

int main(int argc, char const *argv[]) {

    int matriz[106][106];
    srand(time(NULL));

    for (int i = 0 ; i < 106; i++) {
        for (int j = 0; j < 106; j++) {
            if (i>= 3 && i<103 && j>=3 && j<103) {
                matriz[i][j] = 0;
            }else{
                matriz[i][j] = -1;
            }
        }
    }

    int individuos = 0;
    while (individuos < 5000) {
        int i = 3+(chance(100));
        int j = 3+(chance(100));
        if (matriz[i][j] == 0) {
            matriz[i][j] = 1;
            individuos++;
        }
    }

    int infectados_totais = 0;
    int mortos = 0;
    int segundos = 0;
    while (segundos <= 100)
    {
        int infectados_novos = 0;
        if (segundos == 0) {
            int infectados = 0;
            while (infectados < 5) {
                int i = 3+(chance(100));
                int j = 3+(chance(100));
                if (matriz[i][j] == 0) {
                    matriz[i][j] = 3;
                    infectados++;
                    infectados_totais++;
                    infectados_novos++;
                }
            }
        }
        for (int i = 3; i < 103; i++) {
            for (int j = 3; j < 103; j++) {
                if (matriz[i][j] == 63) {
                    matriz[i][j] = 4;
                }else if (matriz[i][j] == 40) {
                    int sobrevivencia = chance(10);
                    if (sobrevivencia > 0) {
                        matriz[i][j] = 1;
                    }else{
                        matriz[i][j] = 0;
                        mortos++;
                    }
                }
            }
        }
        int individuos_que_andam = 0;
        for (int i = 3; i < 103; i++) {
            for (int j = 3; j < 103; j++) {
                if (matriz[i][j] > 0 && matriz[i][j]%2 == 1) {
                    individuos_que_andam++;
                }
            }
        }
        int andou = 0;
        while (andou < individuos_que_andam) {
            int i = 3+(chance(100));
            int j = 3+(chance(100));
            if (matriz[i][j] > 0 && matriz[i][j]%2==1) {
                int direcao = chance(4);
                if (direcao==0) {
                    if (matriz[i][j+1] == 0) {
                        matriz[i][j+1] = matriz[i][j];
                        matriz[i][j] = 0;
                        andou++;
                    }
                }else if (direcao==1) {
                    if (matriz[i][j-1] == 0) {
                        matriz[i][j-1] = matriz[i][j];
                        matriz[i][j] = 0;
                        andou++;
                    }
                }else if (direcao==2) {
                    if (matriz[i+1][j] == 0) {
                        matriz[i+1][j] = matriz[i][j];
                        matriz[i][j] = 0;
                        andou++;
                    }   
                }else if (direcao==3) {
                    if (matriz[i-1][j] == 0) {
                        matriz[i-1][j] = matriz[i][j];
                        matriz[i][j] = 0;
                        andou++;
                    }   
                }
            }
        }
        for (int i = 3; i < 103; i++) {
            for (int j = 3; j < 103; j++) {
                if (matriz[i][j] > 3) {
                    for (int linha = (i-3); linha <= (i+3); linha++) {
                        for (int coluna = (j-3); coluna <= (j+3); coluna++)
                        {
                            if (linha == (i-3) || linha == (i+3)) {
                                if (coluna == j) {
                                    if (matriz[linha][coluna] == 1) {
                                        int contagio = chance(4);
                                        if (contagio > 0) {
                                            matriz[linha][coluna] = 3;
                                            infectados_novos++;
                                        }
                                    }
                                }
                            }else if (linha == (i-2) || linha == (i+2) || linha == (i-1) || linha == (i+1)) {
                                if (coluna != (j-3) && coluna != (j+3)) {
                                    if (matriz[linha][coluna] == 1) {
                                        int contagio = chance(4);
                                        if (contagio > 0) {
                                            matriz[linha][coluna] = 3;
                                            infectados_novos++;
                                        }
                                    }
                                }
                            }else if (linha == i) {
                                if (matriz[linha][coluna] == 1) {
                                    int contagio = chance(4);
                                    if (contagio > 0) {
                                        matriz[linha][coluna] = 3;
                                        infectados_novos++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 3; i < 103; i++) {
            for (int j = 3; j < 103; j++) {
                if (matriz[i][j] > 1) {
                    matriz[i][j] += 2;
                }
            }
        }

        for (int i = 2; i < 104; i++) {
            for (int j = 3; j < 103; j++) {
                if (matriz[i][j] == 0) {
                    printf(" ");
                }else if (matriz[i][j] == 1) {
                    printf(".");
                }else if(matriz[i][j] > 1 && matriz[i][j] % 2 == 1) {
                    printf("I");
                }else if(matriz[i][j] > 1 && matriz[i][j] % 2 == 0) {
                    printf("D");
                }else if (matriz[i][j] < 0) {
                    printf("X");
                }
            }
            printf("\n");
        }

        printf("segundos: %d\n", segundos);
        printf("+%d infectados\n", infectados_novos);
        segundos += 2;
        sleep(2);
    }

    printf("Infeccoes totais: %d\n", infectados_totais);
    printf("Mortos: %d\n", mortos);

    return 0;
}
