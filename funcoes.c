/* Universidade do Estado da Bahia */
/* Sistemas de Informa��o - 2017.1 */
/* Linguagens de Programa��o I */
/* Pedro Gabriel Sena Cardoso */

/* Solu��o da Lista de Exerc�cios */

#define NMAT 10 /* Dimens�o das matrizes quadradas das quest�es 13, 14 e 15 */
#include "funcoes.h" /* Arquivo com prot�tipos das fun��es */

/* Quest�o 1 */
int soma(int x,int y){
    return x+y;
}

/* Quest�o 2 */
/* Assuma que op ser entre 0 e 3 seja
    responsabilidade do main ou de outra fun��o */
/* Assuma que divis�o por zero ser� evitada pelo main */
float opera(float x,float y,int op){
    float saida;
    switch(op){
        case 0: saida=x+y;
                break;
        case 1: saida=x-y;
                break;
        case 2: saida=x*y;
                break;
        case 3: saida=x/y;
                break;
    }
    return saida;
}

/* Quest�o 3 */
/* Assuma que o vetor seja de tamanho suficiente */
int divisores(int num,int divisor[]){
    int potdiv=1,i=0;
    while(potdiv<=num){
        if(num%potdiv==0){
            divisor[i]=potdiv;
            i++;
        }
        potdiv++;
    }
    return i+1;
}

/* Quest�o 4 */
/* binario[0] � o bit mais significativo,
    ou seja, o de maior pot�ncia */
int converte(int binario[], int qtebits){
    int i, soma=0;
    for(i=0;i<qtebits;i++){
        soma=2*soma+binario[i];
    }
    return soma;
}

/* Quest�o 5 */
/* Solu��o preliminar - n�o funciona para
    parte fracion�ria com zeros � esquerda */
float compoe(int inteiro,int fracionario){
    float saida,termo;
    saida=(float)inteiro;
    termo=(float)fracionario;
    while(termo>1.0){
        termo=termo*0.1;
    }
    saida=saida+termo;
    return saida;
}

float compoe_v2(int inteiro,int fracionario,int ajuste){
    float saida,termo;
    saida=(float)inteiro;
    termo=(float)fracionario;
    while(termo>1.0){
        termo*=0.1;
    }
    while(ajuste>0){
        termo*=0.1;
        ajuste--;
    }
    saida+=termo;
    return saida;
}

/* Quest�o 6 */
int maior_de_dois(int x,int y){
    if(x>=y) return x;
    return y;
}

/* Quest�o 7 */
int menor_de_tres(int x, int y, int z){
    int saida;
    if(x<=y){
        if(x<=z) saida=x;
        else saida=z;
    }
    else{
        if(y<=z) saida=y;
        else saida=z;
    }
    return saida;
}

/* Quest�o 8 */
int maior_de_quatro(int x,int y,int z,int w){
    /* cheating */
    int numeros[3];
    int i,maior=x;
    numeros[0]=y;
    numeros[1]=z;
    numeros[2]=w;
    for(i=0;i<3;i++)
        if(numeros[i]>maior) maior=numeros[i];
    return maior;
}

/* Quest�o 9 */
int maior_de_todos(int numeros[],int tamanho){
    int i,maior,index;
    maior=numeros[0];
    index=0;
    for(i=1;i<tamanho;i++){
        if(numeros[i]>maior){
            maior=numeros[i];
            index=i;
        }
    }
    return i;
}

/* Quest�o 10 */
int existe(int numeros[],int tamanho,int valor){
    int i,contador=0;
    for(i=0;i<tamanho;i++)
        if(numeros[i]==valor) contador++;
    return contador;
}

/* Quest�o 11 */
/* Usando fun��o existe() da quest�o anterior. */
int conjuntos_iguais(int numeros1[],int numeros2[],int tamanho){
    int i,termo_busca,qte_em_1,qte_em_2;
    for(i=0;i<tamanho;i++){
        termo_busca=numeros1[i];
        qte_em_1=existe(numeros1,tamanho,termo_busca);
        qte_em_2=existe(numeros2,tamanho,termo_busca);
        if(qte_em_1!=qte_em_2) return 0;
    }
    return 1;
}

/* Quest�o 12 */
/* Refer�ncia: http://www.jogos.antigos.nom.br/jporrinha.asp */
int rodada_palitinhos(int palitos[], int palpites[], int tamanho){
    int i,saida=-1,soma_palitos=0,continua=1;
    for(i=0;i<tamanho;i++) soma_palitos+=palitos[i];
    /* Lembrando que palpites n�o se repetem */
    for(i=0;i<tamanho&&continua;i++){
        if(palpites[i]==soma_palitos){
            saida=i;
            continua=0;
        }
    }
    return saida;
}

/* Quest�o 13 */
int mais_preenchida(char matriz[][NMAT]){
    int i,j,contador,maior=-1,saida;
    for(i=0;i<NMAT;i++){
        contador=0;
        for(j=0;j<NMAT;j++) if(matriz[i][j]=='*') contador++;
        if(contador>maior){
            maior=contador;
            saida=i;
        }
    }
    return saida;
}

/* Quest�o 14 */
int mais_preenchida_2(char matriz[][NMAT]){
    int i,j,contador,maior=-1,saida;

    /* Varrendo linha a linha */
    for(i=0;i<NMAT;i++){
        contador=0;
        for(j=0;j<NMAT;j++) if(matriz[i][j]=='*') contador++;
        if(contador>maior){
            maior=contador;
            saida=i;
        }
    }

    /* Varrendo coluna a coluna */
    for(j=0;j<NMAT;j++){
        contador=0;
        for(i=0;i<NMAT;i++) if(matriz[i][j]=='*') contador++;
        if(contador>maior){
            maior=contador;
            saida=-1-j;
        }
    }

    return saida;
}

/* Quest�o 15 */
/* Assumindo que a matriz deve, ao final do procedimento, ser� a sua transposta */
/* Transposta: se M � uma matriz mxn, MT � uma matriz nxm, dita transposta de M,
    se �s linhas de MT correspondem as colunas de M, e vice-versa. */
void troca(int *px,int *py){
    int aux=*px;
    *px=*py;
    *py=aux;
    return;
}

void diagonal_invertida(int matriz[][NMAT]){
    int i,j;
    for(i=0;i<NMAT;i++){
        for(j=i+1;j<NMAT;j++){
            troca(&(matriz[i][j]),&(matriz[j][i]));
        }
    }
    return;
}

/* Quest�o 16 */
void calcula_media(int notas[][3], float media[], int qte){
    int i,j,soma;
    for(i=0;i<qte;i++){
        soma=0;
        for(j=0;j<3;j++) soma+=notas[i][j];
        media[i]=(float)soma;
        media[i]/=3;
    }
    return;
}
