#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int lista_adj[100];
    int tamanho_lista;
}vertice;

int main(){

    vertice * vertices;
    int n, a, i, j;

    scanf("%d %d", &n, &a);

    vertices = malloc(sizeof(vertices)*(n+1));

    for(i = 0; i < a; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        int tamanho = vertices[x].tamanho_lista;
        vertices[x].lista_adj[ tamanho ] = y;
        vertices[x].tamanho_lista++;
    }

    for(i = 1; i <= n; i++){
        printf("\n%d -> ", i);
        for(j = 0; j < vertices[i].tamanho_lista; j++){
            printf("%d ", vertices[i].lista_adj[j]);
        }
    }

    printf("\n");
    return 0;
}
