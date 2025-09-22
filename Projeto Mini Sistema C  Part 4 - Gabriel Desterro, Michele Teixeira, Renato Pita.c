#include<stdio.h>
#include<locale.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

	/* Mini Sistema de cadastro. Alunos: Gabriel Desterro, Michele Teixeira, Renato Pita*/

	struct CadastroEscolar //Declaração de um struct com os dados para cadastro escolar;
	{
		//Nome do curso;
		char curso[50]; 
		//Unidades curriculares;
		char materia[50];
		//Nome do aluno;
		char nome[50]; 
		//Endereço do aluno;
		char endereco[50]; 
		//Telefone do aluno;
		char telefone[50];
		//Número da turma;
		char turma[50]; 
		//Número da matrícula;
		char ra[50];
		//Data de nascimento;
		int dia;
		int mes;
		int ano; 
		//Notas;
		float nota1; 
		float nota2;
		float nota3;
		//Média;
		float media;
	};
	
	void cadastro(struct CadastroEscolar *A) //Sequência de entradas e saídas para cadastrar informações dos alunos;
	{
		printf("\nDigite o nome do aluno: ");
		fgets(A->nome, sizeof(A->nome), stdin);
		A->nome[strcspn(A->nome, "\n")] = 0;
		A->nome[0] = toupper(A->nome[0]);
		
		printf("Digite o RA do aluno: ");
		fgets(A->ra, sizeof(A->ra), stdin);
		A->ra[strcspn(A->ra, "\n")] = 0;
		
		printf("Digite a data de nascimento do aluno (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &A->dia, &A->mes, &A->ano);
		getchar();
		
		printf("Digite o endereço do aluno: ");
		fgets(A->endereco, sizeof(A->endereco), stdin);
		A->endereco[strcspn(A->endereco, "\n")] = 0;
		
		printf("Digite o telefone do aluno: ");
		fgets(A->telefone, sizeof(A->telefone), stdin);
		A->telefone[strcspn(A->telefone, "\n")] = 0;
		
		printf("Digite o curso do aluno: ");
		fgets(A->curso, sizeof(A->curso), stdin);
		A->curso[strcspn(A->curso, "\n")] = 0;
						
		printf("Digite o nome da unidade curricular (matéria): ");
		fgets(A->materia, sizeof(A->materia), stdin);
		A->materia[strcspn(A->materia, "\n")] = 0;
						
		printf("Digite o número da turma do aluno: ");
		fgets(A->turma, sizeof(A->turma), stdin);
		A->turma[strcspn(A->turma, "\n")] = 0;
		
		printf("Digite o 1° nota do aluno: ");
		scanf("%f", &A->nota1);
		getchar();
		
		printf("Digite o 2° nota do aluno: ");
		scanf("%f", &A->nota2);
		getchar();	
		
		printf("Digite o 3° nota do aluno: ");
		scanf("%f", &A->nota3);
		getchar();
		
		A->media = (A->nota1+A->nota2+A->nota3) / 3;
	}

    void trocarCadastro(struct CadastroEscolar *a, struct CadastroEscolar *b) {
        struct CadastroEscolar temp = *a;
        *a = *b;
        *b = temp;
    }

    void bubbleSort(struct CadastroEscolar *A, int n) {
        int i, j;
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (strcmp(A[j].nome, A[j+1].nome) > 0) {
                    trocarCadastro(&A[j], &A[j+1]);
                }
            }
        }
    }
    
    int imprimirSalvarCadastro (struct CadastroEscolar *A, int size) {
        int cont;
        for (cont = 0; cont <= size; cont++)
						{
							const char *endereco_do_arquivo = "D:\\Cadastro_Alunos_Senai.txt";
							FILE *arquivo_cadastro;
							arquivo_cadastro = fopen(endereco_do_arquivo, "w");
							
							if (arquivo_cadastro == NULL)
							{
								printf("Erro ao abrir o arquivo\n");
								return 1;
							} else {
								printf("Arquivo salvo com sucesso!\n");
							}
							
							fprintf(arquivo_cadastro, "Cadastro de alunos - Senai\n");
							
							printf("\nNome do %d° aluno: %s", cont+1, A[cont].nome);
							fprintf(arquivo_cadastro, "\nNome do %d° aluno: %s", cont+1, A[cont].nome);
							
							printf("\nRA do %d° aluno: %s", cont+1, A[cont].ra);
							fprintf(arquivo_cadastro, "\nRA do %d° aluno: %s", cont+1, A[cont].ra);
														
							printf("\nData de nascimento do %d° aluno: %02d/%02d/%04d", cont+1, A[cont].dia, A[cont].mes, A[cont].ano);
							fprintf(arquivo_cadastro, "\nData de nascimento do %d° aluno: %02d/%02d/%04d", cont+1, A[cont].dia, A[cont].mes, A[cont].ano);
													
							printf("\nEndereço do %d° aluno: %s", cont+1, A[cont].endereco);
							fprintf(arquivo_cadastro, "\nEndereço do %d° aluno: %s", cont+1, A[cont].endereco);
														
							printf("\nTelefone do %d° aluno: %s", cont+1, A[cont].telefone);
							fprintf(arquivo_cadastro, "\nTelefone do %d° aluno: %s", cont+1, A[cont].telefone);
														
							printf("\nCurso do %d° aluno: %s", cont+1, A[cont].curso);
							fprintf(arquivo_cadastro, "\nCurso do %d° aluno: %s", cont+1, A[cont].curso);
																		
							printf("\nUnidade curricular do %d° aluno: %s", cont+1, A[cont].materia);
							fprintf(arquivo_cadastro, "\nUnidade curricular do %d° aluno: %s", cont+1, A[cont].materia);
																		
							printf("\nNúmero da turma do %d° aluno: %s", cont+1, A[cont].turma);
							fprintf(arquivo_cadastro, "\nNúmero da turma do %d° aluno: %s", cont+1, A[cont].turma);
							
							printf("\n1° nota do %d° aluno: %.2f", cont+1, A[cont].nota1);
							fprintf(arquivo_cadastro, "\n1° nota do %d° aluno: %.2f", cont+1, A[cont].nota1);
														
							printf("\n2° nota do %d° aluno: %.2f", cont+1, A[cont].nota2);
							fprintf(arquivo_cadastro, "\n2° nota do %d° aluno: %.2f", cont+1, A[cont].nota2);
														
							printf("\n3° nota do %d° aluno: %.2f", cont+1, A[cont].nota3);
							fprintf(arquivo_cadastro, "\n3° nota do %d° aluno: %.2f", cont+1, A[cont].nota3);

							printf("\nMédia do %d° aluno: %.2f\n", cont+1, A[cont].media);
							fprintf(arquivo_cadastro, "\nMédia do %d° aluno: %.2f\n", cont+1, A[cont].media);
							
							fclose(arquivo_cadastro);
						}
    }

	int main()
	{
		setlocale(LC_ALL, "Portuguese"); //torna possível a impressão de caracteres especiais no console;
		
		int i, n = 0, condicao = 1, opcao = 0, alteracao, exclusao, numAluno, confirmacaoAluno, escolhaAlteracao; //Declaração de variáveis;
		struct CadastroEscolar A[100]; //Declaração do struct como um vetor;
		
		printf("\nBem vindo ao sistema de cadastro de informações dos alunos do SENAI.\n");
		
		while (opcao != 5) //Loop onde rodará o sistema de cadastro;
		{		
		
			//Impressão do menu e leitura da entrada para as opções;
			printf("\n	Escolha uma opção: \n\n	1 - Cadastrar dados de um aluno. \n	2 - Alterar dados. \n	3 - Excluir dados. \n	4 - Salvar e Exibir dados. \n	5 - Sair.\n");
			printf("\nOpção: ");
			scanf("%d", &opcao);
			getchar();
			
			//divisão das opções escolhidas no menu	
			switch (opcao) 
			{
				case 1: //Opção que inicia o loop de cadastro de dados;
					{
						condicao = 1;
						while (condicao == 1)
						{
							cadastro(&A[n]);
							
							/*Faz o filtro do resultado do aluno com base na sua média e exibe na tela o status*/
							if (A[n].media >= 7)
							{
								printf("\nO aluno %s está aprovado com média %.2f\n", A[n].nome, A[n].media);
							} else if (A[n].media < 7 && A[n].media >= 4){
								printf("\nO aluno %s está em recuperação com média %.2f\n", A[n].nome, A[n].media);
							} else if (A[n].media < 4){
								printf("\nO aluno %s está reprovado com média %.2f\n", A[n].nome, A[n].media);
							}
							
							/*Pergunta ao usuário se deseja adicionar mais um aluno (iniciar o loop novamente)*/
							printf("\n\nDeseja adicionar mais um aluno (1 para SIM / 0 para NÃO)? \n");
							printf("\nOpção: ");
							scanf("%d", &condicao);
							getchar();
							
							n++;
							system("cls");
							
							//Filtro de escolha da condição;
							if (condicao == 0)
							{
								break;
							} else if (condicao != 1 && condicao != 0){
								printf("\nComando inválido, retornando ao menu...\n");
								break;
							}
						}
						break;
					}
				case 2: //Opção que inicia alteração de dados;
					{
						if (n == 0)
						{
							printf("\nÉ necessário cadastrar algum aluno antes de alterar.\n");
							break;
						} else {
							printf("\n	Escolha o aluno que deseja alterar: \n\n");
							for (numAluno = 0; numAluno <= n-1; numAluno++)
							{
								printf("	%d - Alterar dados de %s.\n", numAluno+1, A[numAluno].nome);
							}
								printf("\nOpção: ");
								scanf("%d", &alteracao);
								getchar();
								alteracao--;
								
								for (confirmacaoAluno = 0; confirmacaoAluno <= numAluno; confirmacaoAluno++)
								{
									if (confirmacaoAluno == alteracao)
									{
    									printf("\n	Escolha o que deseja alterar: \n\n	1 - Nome. \n	2 - RA. \n	3 - Data de nascimento. \n	4 - Endereço. \n	5 - Telefone.\n	6 - Curso.\n	7 - Matéria.\n	8 - Número da matrícula.\n	9 - 1° nota.\n	10 - 2° nota.\n	11 - 3° nota.\n");
    									printf("\nOpção: ");
    									scanf("%d", &escolhaAlteracao);
    									getchar();
										
										switch (escolhaAlteracao)
										{
											case 1:
												{
													printf("\nDigite o nome do aluno: ");
													fgets(A[alteracao].nome, sizeof(A[alteracao].nome), stdin);
													A[alteracao].nome[strcspn(A[alteracao].nome, "\n")] = 0;
													A[alteracao].nome[0] = toupper(A[alteracao].nome[0]);
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
												
											case 2:
												{
													printf("\nDigite o RA do aluno: ");
													scanf("%d", &A[alteracao].ra);
													getchar();
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
											
											case 3:
												{
													printf("\nDigite a data de nascimento do aluno (dd/mm/aaaa): ");
													scanf("%d/%d/%d", &A[alteracao].dia, &A[alteracao].mes, &A[alteracao].ano);
													getchar();
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
												
											case 4:
												{
													printf("\nDigite o endereço do aluno: ");
													fgets(A[alteracao].endereco, sizeof(A[alteracao].endereco), stdin);
													A[alteracao].endereco[strcspn(A[alteracao].endereco, "\n")] = 0;
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
											
											case 5:
												{
													printf("\nDigite o telefone do aluno: ");
													fgets(A[alteracao].telefone, sizeof(A[alteracao].telefone), stdin);
													A[alteracao].telefone[strcspn(A[alteracao].telefone, "\n")] = 0;
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
											
											case 6:
												{
													printf("\nDigite o curso do aluno: ");
													fgets(A[alteracao].curso, sizeof(A[alteracao].curso), stdin);
													A[alteracao].curso[strcspn(A[alteracao].curso, "\n")] = 0;
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
											
											case 7:
												{
													printf("\nDigite o nome da unidade curricular (matéria): ");
													fgets(A[alteracao].materia, sizeof(A[alteracao].materia), stdin);
													A[alteracao].materia[strcspn(A[alteracao].materia, "\n")] = 0;
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
											
											case 8:
												{
													printf("\nDigite o número da turma do aluno: ");
													scanf("%d", &A[alteracao].turma);
													getchar();
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
											
											case 9:
												{
													printf("\nDigite o 1° nota do aluno: ");
													scanf("%f", &A[alteracao].nota1);
													getchar();
													A[alteracao].media = (A[alteracao].nota1+A[alteracao].nota2+A[alteracao].nota3) / 3;
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
											
											case 10:
												{
													printf("\nDigite o 2° nota do aluno: ");
													scanf("%f", &A[alteracao].nota2);
													getchar();
													A[alteracao].media = (A[alteracao].nota1+A[alteracao].nota2+A[alteracao].nota3) / 3;
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
											
											case 11:
												{
													printf("\nDigite o 3° nota do aluno: ");
													scanf("%f", &A[alteracao].nota3);
													getchar();
													A[alteracao].media = (A[alteracao].nota1+A[alteracao].nota2+A[alteracao].nota3) / 3;
													system("cls");
													printf("\nDados de %s foram alterados com sucesso.\n", A[alteracao].nome);
													break;
												}
											
											default:
												{
													printf("\nOpção inválida.\n");
													break;
												}
										}
										break;
									}
								}
						}
            			break;
            		}
                case 3: //Opção que inicia  deleção de dados;
					{
						if (n == 0)
						{
							printf("\nÉ necessário cadastrar algum aluno antes de deletar.\n");
							break;
						} else {
							printf("\n	Escolha o aluno que deseja deletar: \n\n");
							for (numAluno = 0; numAluno <= n-1; numAluno++)
							{
								printf("	%d - Deletar dados de %s.\n", numAluno+1, A[numAluno].nome);
							}
							printf("\nOpção: ");
							scanf("%d", &exclusao);
							getchar();
							exclusao--;
								
							if (exclusao >= 0 && exclusao <= n)
							{
								for (i = exclusao; i<= n-1; i++)
								{
									A[i] = A[i + 1];
								}
								n--;
								system("cls");
								printf("\nDados do %d° aluno foram removidos com sucesso.\n", exclusao);	
							}
						}
						break;
					}
                case 4: //Opção que inicia o loop de impressão dos dados cadastrados;
					{
						system("cls");
					    bubbleSort(A, n);
						imprimirSalvarCadastro(A, n-1);
						break;
					}
				case 5: //Opção que finaliza o programa
					{
						printf("\nEncerrando programa...");
						break;
					}
				default: //Opção para casos de erro de digitação
					{
						printf("\nOpção inválida, tente novamente.\n");
						break;					
					}
			}
		}
		return 0;			
	}
	
