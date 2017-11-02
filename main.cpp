#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <stdbool.h>
#include <string.h>//necessário para manipular Strings
#include <conio.h>


/*          
        Se você resolver algum problema, escreve aqui. 
        E atualiza com os problemas que você encontrou beleza?
        Problemas:
        -Só esta salvando um usuario de cada vez
        -Precisa acrescentar a parte de visualizar os clientes ja cadastrados
*/
void cadastroCliente(char cmhRaiz[]);
void cadastroCarro(char cmhRaiz[]);

int main(){
    int opc,rodando=1;
    /*as variaveis a segui foram criados para montar "mais ou menos de banco de dados", onde cada registro tera seu 
    txt separados em pastas de acordo com o seu setor: cliente,carro,aluguel = "sera a pasta com o txt guardando os
    das do cliente que realiza o aluguel e os dados do carro alugado com a hora e quantidades de dias mais dados adicionais
    qua foram necessarios", a variavel "cmhRaiz" indica o caminho raiz que sera adaptado de acordo com o local onde esta salvo o
    programa. Eu estou mais ou menos criando uma estrutuara igual a usado na prefeitura onde vc trabalha belli*/
    char cmhCliente[12]="\\clientes\\";
    char cmhAluguel[11]="\\aluguel\\";
    char cmhCarro[10]="\\carros\\";
    char cmhRaiz[53]="c:\\Users\\Estevão\\Documents\\legalRentAACar\\bancoDados";
    char raizAux[53];

  do{
      printf("\t|----- Legal Rent a Car -----|\n\n");
      printf("Menu Principal:\n Escolha uma opcao:\n\n1- Cadastro de usuario\n2- cadastrar Carro\n4- Clientes cadastrados\n3- Sair\n");
      scanf("%d",&opc);
  
      switch(opc){
         case 1:
              system("CLS");
              strcpy(raizAux,cmhRaiz);
              strcat(cmhRaiz,cmhCliente);        
              cadastroCliente(cmhRaiz);
              strcpy(cmhRaiz,raizAux);
              printf("%s\n",cmhRaiz);
              break;
         case 2:
              system("CLS");
              strcpy(raizAux,cmhRaiz);
              strcat(cmhRaiz,cmhCarro);
              cadastroCarro(cmhRaiz);
              strcpy(cmhRaiz,raizAux);
              printf("%s\n",cmhRaiz);
              break;
         case 3:
             rodando==0;
             system("PAUSE");
             return 0;
         }
         
     }while(rodando==1);
}
//funcoes -------------------------------------------------------------------------
void cadastroCliente(char cmhRaiz[]){
     FILE *arq;
     char nome[35],cpf[11],idade[3],data[9],hora[9],resposta[5];
     int opc2,parceiro,tamanho;
     char salvarNome[35]=("nome: "),salvarCPF[11]=("cpf: "),salvarIdade[10]=("idade: "),salvarDATA[20]=("data: "),salvarHORA[20]=("hora: ");
    
     printf("\n%s\n",cmhRaiz);
     printf("\n\t|----- Cadastro de usuario -----|\n\n");
     printf("Nome completo: ");
     scanf("%s",&nome);//%[^\n]s Faz com que o scanf só pare de ler ao teclarem ENTER
     printf("Cpf: ");
     scanf("%s",&cpf);
     tamanho = strlen(cpf);//Validação de tamanho
     while(tamanho != 11){//Verifica se o tamanho inserido é valido
         printf("\nValor invalido, digite novamente: ");
         scanf("%s",&cpf);
         tamanho = strlen(cpf);
     }
     printf("Idade: ");
     scanf("%s",&idade);
     tamanho = strlen(idade);
     while(tamanho > 3){
         printf("\nValor invalido, digite novamente: ");
         scanf("%s",&idade);
         tamanho = strlen(idade);
     }
     printf("Parceiro da ONG: \n1 - Sim\n2 - Nao\n");
     scanf("%d",&parceiro);
  
     _strdate( data );
     _strtime( hora );
     printf("Data :%s Hora:%s",data,hora);
  
     printf("\n\nOs dados entao corretos?\n");
     if(parceiro==1){
                     strcpy(resposta,"sim");
     }else{
           strcpy(resposta,"nao");
     }
     printf("Nome: %s  |  CPF: %s  |  Idade: %s  |  Parceiro: %s\n\n",nome,cpf,idade,resposta);
     printf("1 - Sim\n2 - Nao\n");
     scanf("%d",&opc2);
     
     if(opc2 ==1){
         strcat(cmhRaiz,cpf);
         arq = fopen(cmhRaiz,"a");//arquivo para o gradastro atual, o arquivo tera como nome o cpf do cliente
         if(arq == NULL){
             printf("Ocorreu um erro: %s",arq);
             printf("\n%s\n",cmhRaiz);
             system("PAUSE");
             system("CLS");
         }else{
             strcat(salvarNome,strcat(nome,"\n")); // Concatena a string de formatação para salvar no arquivo e o nome da pessoa
             fprintf(arq,salvarNome); // Salvar o dado do usuario no arquivo
             strcat(salvarCPF,strcat(cpf,"\n"));
             fprintf(arq,salvarCPF);
             strcat(salvarIdade,strcat(idade,"\n"));
             fprintf(arq,salvarIdade);
             strcat(salvarDATA,strcat(data,"\n"));
             fprintf(arq,salvarDATA);
             strcat(salvarHORA,strcat(hora,"\n"));
             fprintf(arq,salvarHORA);
             
             fclose(arq);
             //char salvarNome[35]=("nome: "),salvarCPF[11]=("cpf: "),salvarIdade[10]=("idade: "),salvarDATA[20]=("data: "),salvarHORA[20]=("hora: ");
             printf("\n\tCLIENTE SALVO COM SUCESSO\n\n");
             system("PAUSE");
             system("CLS");
         }
     }      
}
void cadastroCarro(char cmhRaiz[]){
     FILE *arq;
     char marca[50],modelo[100],strMarca[]="marca:",strModelo[]="modelo:",strValorDia[]="diaria:",valorDia[10];
     int opc;
     
     do{
       printf("\n%s\n",cmhRaiz);
       printf("\t\t\t|--- Cadastro do Carro ---|\n\n");
       printf("Digite a Marca do carro:");
       scanf("%s",&marca);
       printf("Digite o modelo do carro:");
       scanf("%s",&modelo);
       printf("Digite o valor da diaria do Carro:");
       scanf("%s",&valorDia);
       
       printf("Os dados estao corretos?\nMarca:%s\t| Modelo:%s\t| valor da diario:R$%s",marca,modelo,valorDia);
       printf("\n1-sim\n2-nao\n");
       scanf("%d",&opc);
     }while(opc!=1);
     strcat(cmhRaiz,modelo);
     arq = fopen(cmhRaiz,"a");
     if(arq==NULL){
                   printf("OCORREU UM ERRO:%s",arq);
                   system("PAUSE");
                   system("CLS");
     }else{
           printf("\n%s\n",cmhRaiz);
           strcat(strMarca,strcat(marca,"\n"));
           fprintf(arq,strMarca);//salva a marca do carro
           strcat(strModelo,strcat(modelo,"\n"));
           fprintf(arq,strModelo);//salva o modelo do carro
           strcat(strValorDia,strcat(valorDia,"\n"));
           fprintf(arq,strValorDia);
           
           fclose(arq);
           printf("\n\tCARRO SALVO COM SUCESSO\n\n");
           system("PAUSE");
           system("CLS");
     }  
}
