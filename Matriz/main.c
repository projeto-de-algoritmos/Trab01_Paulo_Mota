//Alunos: Joao Pedro Mota Jardim        - 16/0031982
//        Paulo Victor de Menezes Lopes - 16/0016428

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct Pessoa{
    int valido;
    char nome[50];
}PESSOA;

void mostraPessoas(PESSOA *pessoas){
    for(int i = 0;i < 100; i++){
        if(pessoas[i].valido != 0){
            printf("%d - %s\n",i+1,pessoas[i].nome);
        }
    }
}

void adicionaPessoa(int *qtdPessoas,PESSOA *pessoas){
    char nome[50];

    int i = 0;
    if(*qtdPessoas < 100){
        while(pessoas[i].valido != 0){
            i++;
        }
        printf("Informe o nome da pessoa que deseja cadastrar:\n");
        scanf("%[^\n]",&nome);
        scanf("%*c");
        strcpy(pessoas[i].nome, nome);
        pessoas[i].valido = 1;
        *qtdPessoas = *qtdPessoas + 1;

    }
    else{
        printf("Numero maximo de pessoas cadastradas.\n");
    }
}

void removePessoa(int *qtdPessoas,PESSOA *pessoas,int amizades[100][100]){
    int pessoa;

    mostraPessoas(pessoas);
    printf("Informe o numero da pessoa que deseja remover:\n");
    scanf("%d",&pessoa);
    if(pessoas[pessoa-1].valido = 1){
      pessoas[pessoa-1].valido = 0;
      for(int i = 0;i < 100;i++){
        amizades[pessoa-1][i] = 0;
        amizades[i][pessoa-1] = 0;
      }
      *qtdPessoas = *qtdPessoas - 1;
    }
    else{
        printf("Numero informado nao corresponde ao de uma pessoa cadastrada.\n");
    }
}

void mostraMenu(int qtdPessoas){
  //system("clear");
  printf("\n");
  printf(" ===================================================\n");
  printf("|   Simulacao de Convites para festa de aniversario  |\n");
  printf("|         >>>>>>>>> Menu <<<<<<<<<                   |\n");
  printf("| 1 - Gerar lista de convidados para uma pessoa      |\n");
  printf("| 2 - Mostrar todas os pessoas                       |\n");
  printf("| 3 - Adicionar mais alguma pessoa(%d restantes)     |\n",100 - qtdPessoas);
  printf("| 4 - Remover alguma pessoa(%d cadastradas)          |\n", qtdPessoas);
  printf("| 5 - Adicionar  amizade                             |\n");
  printf("| 6 - Remover    amizade                             |\n");
  printf("| 7 - Visualizar todas as amizades                   |\n");
  printf("| 0 - Sair                                           |\n");
  printf(" ====================================================\n");
  printf("Sua opcao: ");
}

void adicionaAmizade(PESSOA *pessoas,int amizades[100][100]){
    int pessoa1,pessoa2;
    mostraPessoas(pessoas);
    printf("Digite o numero das pessoas que se tornaram amigas:");
    scanf("%d",&pessoa1);
    scanf("%d",&pessoa2);
    if(pessoas[pessoa1-1].valido == 1 && pessoas[pessoa2-1].valido == 1){
      if(amizades[pessoa1-1][pessoa2-1] == 0){
         amizades[pessoa1-1][pessoa2-1] = 1;
         amizades[pessoa2-1][pessoa1-1] = 1;
      }
      else{
          printf("Essas pessoas ja sao amigas, aperte enter para voltar ao menu.");
          getc(stdin);
      }
    }
    else{
      printf("Algum dos numeros informados nao corresponde a nenhuma pessoa cadastrada, aperte enter para voltar ao menu.");
      getc(stdin);
    }
}

void removeAmizade(PESSOA *pessoas,int amizades[100][100]){
    int pessoa1,pessoa2;
    mostraPessoas(pessoas);
    printf("Digite o numero das pessoas que deixaram de ser amigas:");
    scanf("%d",&pessoa1);
    scanf("%d",&pessoa2);
    if(pessoas[pessoa1-1].valido == 1 && pessoas[pessoa2-1].valido == 1){
      if(amizades[pessoa1][pessoa2] == 1){
         amizades[pessoa1][pessoa2] = 0;
         amizades[pessoa2][pessoa1] = 0;
      }
      else{
          printf("Essas pessoas ja nao sao amigas, aperte enter para voltar ao menu.");
          getc(stdin);
      }
    }
    else{
      printf("Algum dos numeros informados nao corresponde a nenhuma pessoa cadastrada, aperte enter para voltar ao menu.");
      getc(stdin);
    }
}

void mostraAmigos(int pessoa,PESSOA *pessoas,int amizades[100][100]){
    for(int i = 0;i < 100; i++){
        if(amizades[pessoa-1][i] != 0){
            printf("%d - %s\n",i+1,pessoas[i].nome);
        }
    }
}
void formaListaAniversario(PESSOA *pessoas,int amizades[100][100]){
    int aniversariante;
    int amigo;
    int qtdConvidados = 0;
    int convidados[100] = {0};
    printf("Quem sera o aniversariante:\n");
    mostraPessoas(pessoas);
    printf("Informe o numero do aniversariante: ");
    scanf("%d",&aniversariante);
    do{
       system("clear");
       printf("Possiveis convidados: \n");
       for(int i = 0;i < 100; i++){
        if(amizades[aniversariante-1][i] != 0 && convidados[i] != 1){
            printf("%d - %s\n",i+1,pessoas[i].nome);
            printf("Ciclo de amigos:\n");
            mostraAmigos(i+1,pessoas,amizades);
            printf("-----------\n\n ");
        }
    }
       printf("Selecione um amigo e seu respectivo ciclo de amizades para convidar(aperte 0 para finalizar):");
       scanf("%d",&amigo);
       if(amigo != 0 && amizades[aniversariante-1][amigo-1]){
          convidados[amigo-1] = 1;
          for(int i = 0;i < 100; i++){
             if(amizades[amigo-1][i] != 0){
                convidados[i] = 1;
             }
          }
       }
    }while(amigo!= 0);
    system("clear");
    printf("------------------------\n");
    printf("Lista de aniversario:\n");
    for(int i = 0;i < 100; i++){
          if(convidados[i] != 0 && i != aniversariante-1){
             printf("%d - %s\n",i+1,pessoas[i].nome);
             qtdConvidados++;
          }
    }
    printf("------------------------\n");
    printf("Ha %d convidados para a festa.\n\n",qtdConvidados);
    getc(stdin);
}
int main(int argc, char **argv) {
  PESSOA pessoas[100];
  int amizades[100][100] = {0};
  int qtdPessoas = 0;
  int opcao = 0;


  for(int i = 0;i < 100; i++)
    pessoas[i].valido = 0;

  strcpy(pessoas[0].nome, "Jorge");
  pessoas[0].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[1].nome, "Neymar");
  pessoas[1].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[2].nome, "Ricardo");
  pessoas[2].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[3].nome, "Juninho");
  pessoas[3].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[4].nome, "Pedro");
  pessoas[4].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[5].nome, "Jonas");
  pessoas[5].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[6].nome, "Amanda");
  pessoas[6].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[7].nome, "Julia");
  pessoas[7].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[8].nome, "Maria");
  pessoas[8].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[9].nome, "Cleyton");
  pessoas[9].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[10].nome, "Tulio");
  pessoas[10].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[11].nome, "Emanuel");
  pessoas[11].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[12].nome, "Jessica");
  pessoas[12].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[13].nome, "Luisa");
  pessoas[13].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[14].nome, "Ana");
  pessoas[14].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[15].nome, "Jose");
  pessoas[15].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[16].nome, "Kauan");
  pessoas[16].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[17].nome, "Peter");
  pessoas[17].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[18].nome, "Maikon");
  pessoas[18].valido = 1;
  qtdPessoas++;
  strcpy(pessoas[19].nome, "Victor");
  pessoas[19].valido = 1;
  qtdPessoas++;

  amizades[0][1] = 1;
  amizades[1][0] = 1;
  amizades[1][2] = 1;
  amizades[2][1] = 1;
  amizades[3][2] = 1;
  amizades[2][3] = 1;
  amizades[19][2] = 1;
  amizades[2][19] = 1;
  amizades[19][3] = 1;
  amizades[3][19] = 1;
  amizades[14][3] = 1;
  amizades[3][14] = 1;
  amizades[14][19] = 1;
  amizades[19][14] = 1;
  amizades[1][17] = 1;
  amizades[17][1] = 1;
  amizades[17][13] = 1;
  amizades[13][17] = 1;
  amizades[4][7] = 1;
  amizades[7][4] = 1;
  amizades[18][4] = 1;
  amizades[4][18] = 1;
  amizades[4][15] = 1;
  amizades[15][4] = 1;
  amizades[15][16] = 1;
  amizades[16][15] = 1;
  amizades[10][16] = 1;
  amizades[16][10] = 1;
  amizades[0][18] = 1;
  amizades[18][0] = 1;
  amizades[1][3] = 1;
  amizades[3][1] = 1;
  amizades[1][4] = 1;
  amizades[4][1] = 1;
  amizades[1][5] = 1;
  amizades[5][1] = 1;
  amizades[6][8] = 1;
  amizades[8][6] = 1;
  amizades[9][11] = 1;
  amizades[11][9] = 1;
  amizades[12][6] = 1;
  amizades[6][12] = 1;
  amizades[8][1] = 1;
  amizades[8][1] = 1;


  do{
        system("clear");
        mostraMenu(qtdPessoas);
        scanf("%d",&opcao);
        __fpurge(stdin);
        system("clear");
        switch(opcao){
        case 1:
            formaListaAniversario(pessoas,amizades);
            printf("Aperte enter para voltar ao menu.");
            getc(stdin);
            break;
        case 2:
            printf("Lista de pessoas cadastradas:\n");
            mostraPessoas(pessoas);
            printf("Aperte enter para voltar ao menu.");
            getc(stdin);
            break;
        case 3:
            adicionaPessoa(&qtdPessoas,pessoas);
            //qtdPessoas++;
            break;
        case 4:
            removePessoa(&qtdPessoas,pessoas,amizades);
            //qtdPessoas--;
            break;
        case 5:
            adicionaAmizade(pessoas,amizades);
            break;
        case 6:
            break;
            removeAmizade(pessoas,amizades);
        case 7:
            for(int i = 0;i < 100; i++){
               if(pessoas[i].valido != 0){
                  printf("Amigos de %s:\n",pessoas[i].nome);
                  mostraAmigos(i+1,pessoas,amizades);
                  printf("\n");
               }
            }
            printf("Aperte enter para voltar ao menu.");
            getc(stdin);
        }

  }while(opcao != 0);

  return 0;
}
