#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exec.h"
#include "decodArgs.h"
#include "decodc.h"

void interface();

int main(int argc, char *argv[]){
  if(argc < 3){
      printf("\nError: Falta de parametros, exemplo\n\n\t%s <Opçõees> <Fonte(Programa)>\n\n",argv[0]);
      printf("Opções: < -r > Modo execucao silenciosa\n\t");
      printf("< -v > Modo debug, passo a passo\n\t");
      printf("< -s n > n computações com parada para uma nova entrada de modo\n\n");
      printf("Fonte(Progama): Entrada com arquivo.MT com codigo de execução\n\n");
      exit(1);
  }
  FILE *file;
  if(!(file=fopen(argv[argc-1],"r"))){
      fprintf(stderr, "\nERRO: ao abrir arquivo\n\n", argv[argc-1]);
      exit(1);
  }
  cabecote = 0;
  decodArgs(argc, argv);
  interface();
  getBlocos(file);
  for(int i=strlen(fita);i<tam_fita;i++){
      fita[i]='_';
  }
  exec(file);

  return 0;
}

void interface(){
  system("clear");
  printf("Simulador de Maquína de Turing ver. 1.0\nDesenvolvido como trabalho pratíco para ");
  printf("a disciplina de Teoria da Computação\n" );
  printf("Autores: Julio Cesar M.C. e Renato Borges B.\tIFMG 2018.\n\nForneça a palavra inicial: ");
  scanf("%s", fita);
  printf("\n");
}
