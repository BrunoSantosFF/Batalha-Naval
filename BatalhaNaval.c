#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{

	int ID; //id do barco
	char nomeNavio[11]; //nome do navio,seria o tipo dele igual na outra struct
	int PriJogada; // primeira jogada no navio

}tNavioabatido; //struct para os navios que foram abatidos na primeira jogada de cada

typedef struct{

	int ID; //id de cada navio
	int Tiro; // pega o tiro no navio;
	char nomeNavio[11]; //nome do navio,seria o tipo dele igual na outra struct
	int coluna; // linha no jogo.
	char linha;// Coluna no jogo.
	char jogadinhas[4]; //jogadas dos jogadores

}tJogadas; //struct para as jogadas dos jogadores

typedef struct{

	int LetraNum; //cordenada Letra -> vira numero (EX: a = 0 )
	int tamanhoNavio; //tamanho do navio
	char TipoNavio[11]; // tipo do navio(nome)
	int id; // Identidade do navio
	int sentido; // Sentido do navio
	char coordLetra; // Cordenada do navio em formato de letra (Seria a linha : a,b,c,...)
	int coordNumero; //Cordenada do navio em formato de Numero (Seria a coluna : 1,2,3,...)

}tNavio; //struct para os dados do navio

typedef struct {
	//------- variaveis navios abatidos ---------//
	tNavioabatido abatido[50]; //tabuleiro com os navios abatidos
	int qtdAbatidos; // quantidade de navios abatidos
	int vetorAux[30]; //vetor auxiliar para contar os ID
	int qtdDoVetor; // quantidade de ID
	//----------tabuleiro auxiliar---------------//
	int tabuleiroAux[10][10]; //tabuleiro auxiliar(com os id dos navios)

	tJogadas jogadasJogo[100]; //jogadas dos jogadores
	int valido;//Navio Valido
  	int contNavio; //quantidade de navios
	tNavio Navios[50]; //tipo navio
	char tabuleiro[10][10]; // tabuleiros

}tTabuNavio; //struct geral do jogo

// -------- Funcao Gerais ----------- //
tTabuNavio LeNavios(FILE* tabu); //Pega as informacoes de cada navio.
tTabuNavio retornaNavios(tNavio *Navios ,int qtd); // retorna os valores(parametros)
tTabuNavio ValidaTabuleiro(tTabuNavio tabuleiros); // Valida tabuleiros
tTabuNavio TabuleiroInicial(tTabuNavio tabuleiros); //Tabuleiro Inicial (sem navio)
int LetraNumero(tNavio Navios); // troca a letra por numero , no quesito coordenada
int TamanhoDoBarco(tNavio Navios);// Retorna o tamanho do Navio
int ColocandoCoordenadaNoTabuleiro(tNavio Navios); // ajeita a coordenada numero para o tabuleiro
int UltrapassouLimites(int NavioLimite); // funcao limite do tabuleiro
int Sentido(tNavio Navios); //sentido do navio

// --------- Funcoes Tabuleiro -------//
tTabuNavio ColocandoNavios(tTabuNavio tabu); //Colocando navios no tabuleiro
void Compatibilidade(tTabuNavio tabu1,tTabuNavio tabu2,char *argv); //Salva se for compativel
int tabuleirosCompativeis(tTabuNavio tabu1,tTabuNavio tabu2); //verifica se for compativel e valido
void NomesUsuarios(tTabuNavio tabu1,tTabuNavio tabu2,char jogador1[17],char jogador2[17],char *argv); //Nome e tabuleiros salvos em arquivo

// --------- Jogo ---------------//
void Jogo(tTabuNavio tabu1,tTabuNavio tabu2,char *argv); //funcao para iniciar jogo
tTabuNavio JogadoresJogadas(int qtd,tTabuNavio tabu,char jogador[17]);// jogadas dos jogadores
int verificaLinha(tJogadas letra); // verifica se a letra da coordenada linha esta correta
int verificaRepetida(tJogadas *str,int qtd); //verifica se o comando(jogada) foi repetido
int verificaColuna(tJogadas letra); //verifica se o numero da coordenada coluna esta correta
void TabuleiroInicialImpresso(char tabuleiro[10][10]); // inicia colocando (".")
tTabuNavio ColocandoValoresNavio(tTabuNavio tabuA,tTabuNavio tabuB); //colocando os valores do tabu2 em tabu1 auxiliar
int IDdoNavio(tNavio id); // pega o id dos navios que sao unicos
void DecisaoJogador(char *nome); //devisao da jogada do jogador
tTabuNavio Jogadas(tTabuNavio tabuA,tTabuNavio tabuB,tJogadas jogada,char tabuleiro[10][10],int i); //jogadas dos jogadores
tTabuNavio JogadasCertaNavio(tTabuNavio tabuA,tTabuNavio tabuB,int ID,int i); //verifica se acertou o navio
int ColocandoCoordenadaNoTabuleiro2(int coluna); // ajeita as coordenadas coluna no tabuleiro
int LetraNumero2(char letra);// ajeita as coordenadas linha no tabuleiro
void ImprimirTabuleiraJogada(char tabuleiro[10][10]);//funcao para imprimir o tabuleiro
int Ganhador(tTabuNavio tabuA); //Imprimi o campeao

// ---------Gerar resumo de resultado ------//
tJogadas retornandoIdETiro(tJogadas jogada,int id,int Tiro);// nome dos id e tiro passando para outra struct , as struct das jogadas
tJogadas NomesDoBarcos(tJogadas nome,tNavio nome2); // nome dos barcos passando para outra struct , as struct das jogadas
int retornaTiro(tJogadas tiro); //Retorna se acertou o navio;
tTabuNavio ResultadoJogador(tTabuNavio tabuA,int qtd,char jogador[17],FILE* arquivoResul); // resultado geral das jogadas
void ResultadoDoVencedor(int Ganhador1 ,int Ganhador2,FILE* arquivoResul,char jogador1[17],char jogador2[17]);//resultado do campeao;
int ResultadoDoVencedor2(int Ganhador1 ,int Ganhador2,char jogador1[17],char jogador2[17]);//resultado do campeao 2;

// -------- Gerar arquivo de estataticas para anaise ------- //
void EstatisticasJogadores(tTabuNavio tabuA,int i,char jogador[17],FILE* arquivoEsta); // contabiliza as estatisticas do jogo
int RetornandoColuna(tJogadas JogColuna); //retorna os valores da coluna
char RetornandoLinha(tJogadas JogLinha); //retorna os valores da linha
float DesvioPadrao(tTabuNavio tabu,int i,float locMedLinha,float locMedColuna); // Desvio padrao

// --------- Ordem Alfabetica --------------------//
void NavioAbatido(tTabuNavio tabuA,FILE* arquivoEsta); // imprimi o navio abatido
tNavioabatido PassandoIDeNomeePos(int cont,tJogadas nomeid); //Passando as informacoes dos navios como id ,posicao ,nome
tTabuNavio VetorAux(tTabuNavio tabuA ); // vetor auxiliar para contar os ID
tNavioabatido BotandoEmOrdem1(tNavioabatido tabuA); // Colocando navios em ordem 1 (ordem dos id)
tTabuNavio BotandoEmOrdem2(tTabuNavio tabuA);//Colocando navios em ordem 2 (ordem alfabetica)

//------------funcoes auxiliares --------------//
int PassandoID(tNavioabatido abatido); // repassa os valores de Id dos navios
int PassandoPrimeiraTiro(tNavioabatido abatido); //repassa o primeiro tiro
void ImprimiNomeNavio(tNavioabatido abatido,FILE* arquivoEsta); //imprimindo o nome do navio
char PassandoLinha(tJogadas jogada); //passando coordenada linha
int PassandoColuna(tJogadas jogada);//passando coordenada coluna
int PassandoID2(tJogadas jogada);// repassa os valores de Id dos navios
void ImprimiNomeNavio2(tJogadas jogada,FILE* arquivoResul);  //imprimindo o nome do navio
void ImprimiNomeNavio3(tNavio navio);  //imprimindo o nome do navio
tJogadas PassandoJogadaDigitada(tJogadas jogada,char *vetor); // passando a jogada do jogador
tJogadas PassandoJogadaDigitadaComsscanf(tJogadas jogada,char linha,int coluna); // passando a jogada do jogador atraves do sscanf
int PassandoString(tNavioabatido tabuA,tNavioabatido tabuB); //passando o valor da string do nome do navio que foi comparado
int PassandoString2(tNavio tabuA ,char *string); //passando o valor da string do nome do navio que foi comparado


int main(int argc, char *argv [] ){
	FILE* arquivoT1; //arquivo do tabuleiro 1
	FILE* arquivoT2; //arquivo do tabuleiro 2
	char vetor1[1000],vetor2[1000];

	tTabuNavio tabu1; // tabuleiro 1
	tTabuNavio tabu2; // tabuleiro 2

	//verifica se arquivo existe dentro da pasta e verifica o diretorio.
	if (argc <= 1){
		printf("ERRO: O diretorio de arquivos de configuracao nao foi informado");
	  	return 1;
  	}
    sprintf(vetor1,"%s/tabu_1.txt" ,argv[1]);
    arquivoT1 = fopen(vetor1,"r");
    if (!arquivoT1){
      printf("Erro de leitura do arquivo,  %s \n",vetor1);
      return 1;
    }
    sprintf(vetor2,"%s/tabu_2.txt" ,argv[1]);
    arquivoT2 = fopen(vetor2,"r");
    if (!arquivoT2){
      printf("Erro de leitura do arquivo,  %s \n",vetor2);
      fclose(arquivoT2);
      return 1;
    }

	tabu1 = LeNavios(arquivoT1); //lendo os navios do tabuleiro 1 (1)
	tabu2 = LeNavios(arquivoT2); //lendo os navios do tabuleiro 2 (1)
	Compatibilidade( tabu1,tabu2,argv[1]); //verificando compatibilidade (2)
 	Jogo( tabu1, tabu2,argv[1]); // inicializando o jogo (3)

	return 0;
}

void Jogo(tTabuNavio tabu1,tTabuNavio tabu2,char *argv){
	char jogador1[17]; // nome do jogador 1;
	char jogador2[17]; // nome do jogador 2;
	FILE* arquivoResul;//arquvio que sera salvo na pasta resultado;
	FILE* arquivoEsta; //arquivos de estatisticas
	char tabuleiro1[10][10];//tabuleiro auxiliar 1,que servira para imprimir
	char tabuleiro2[10][10];//tabuleiro auxiliar 2,que servira para imprimir


	int i = 0,a =0,Ganhador1 =0,Ganhador2 =0;//variaveis

	NomesUsuarios(tabu1,tabu2,jogador1,jogador2,argv); // colocando nome nos usuarios (4)
	TabuleiroInicialImpresso(tabuleiro1); //tabuleiro inicia  com "." sem navio
	TabuleiroInicialImpresso(tabuleiro2);//tabuleiro inicia  com "." sem navio
	tabu1 = ColocandoValoresNavio( tabu1, tabu2); // colocando valores nos tabuleiros auxiliares
	tabu2 = ColocandoValoresNavio( tabu2, tabu1); // colocando valores nos tabuleiros auxiliares



	// --- jogo em acao --- //
	while(1){
		// --- jogador 1 ---- //
		DecisaoJogador(jogador1);
		tabu1 = JogadoresJogadas( i, tabu1, jogador1);
		tabu1 = Jogadas( tabu1, tabu2, tabu1.jogadasJogo[i],tabuleiro2,i);
		printf("\nTabuleiro atual de %s apos a jogada de %s\n",jogador2,jogador1);		
		ImprimirTabuleiraJogada(tabuleiro2);

		if (Ganhador( tabu1)){
			Ganhador1 = 1;
		}

		// --- jogador 2 ---- //
		DecisaoJogador(jogador2);
		tabu2 = JogadoresJogadas( i, tabu2, jogador2);
		tabu2 = Jogadas( tabu2, tabu1, tabu2.jogadasJogo[i],tabuleiro1,i);
		printf("\nTabuleiro atual de %s apos a jogada de %s\n",jogador1,jogador2);
		ImprimirTabuleiraJogada(tabuleiro1);

		if (Ganhador(tabu2)){
			Ganhador2 = 1;
		}

		if (ResultadoDoVencedor2(Ganhador1,Ganhador2, jogador1, jogador2)){
			break;
		}
		i++;
	}

	// ----- Resultado ---- //
	char Arq2[1000];
	sprintf(Arq2,"%s/saida/resultado.txt" ,argv);
	arquivoResul = fopen(Arq2,"w"); //abrindo arquivo do resultado
	tabu1 = ResultadoJogador(tabu1,i,jogador1,arquivoResul); // resultado do tabuleiro 1;
    fprintf(arquivoResul,"\n");
	tabu2 = ResultadoJogador(tabu2,i, jogador2,arquivoResul); // resultado do tabuleiro 2;
	ResultadoDoVencedor( Ganhador1, Ganhador2,arquivoResul,jogador1, jogador2);
	fclose(arquivoResul);

	// ----- Estatisticas ---//
	char Arq3[1000];
	sprintf(Arq3,"%s/saida/estatisticas.txt" ,argv);
	arquivoEsta = fopen(Arq3,"w"); //abrindo arquivo do estatisticas
	EstatisticasJogadores(tabu1, i, jogador1,arquivoEsta); //estatisticas do tabuleiro 1
	NavioAbatido( tabu2 ,arquivoEsta); // ordem alfabetica dos navios abatido
	fprintf(arquivoEsta,"\n\n");
	EstatisticasJogadores(tabu2, i, jogador2,arquivoEsta);//estatisticas do tabuleiro 2
	NavioAbatido( tabu1 ,arquivoEsta);// ordem alfabetica dos navios abatido
  	fprintf(arquivoEsta,"\n");
	fclose(arquivoEsta);


}
void EstatisticasJogadores(tTabuNavio tabuA,int i,char jogador[17],FILE* arquivoEsta){ //Estatisticas dos jogadores
	int a=0,linha =0,coluna =0,colunaSec =0,qtdJogadas =0,contTiro = 0,contAgua = 0;
	char linhaSec; // linha secudario para auxiliar na fun?ao
	float locMedLinha = 0.0,locMedColuna = 0.0,Desvio = 0.0;

	for (a=0;a <= i;a++){
		if (retornaTiro(tabuA.jogadasJogo[a])){
			contTiro++; // conta a quatidade de tiros nos navios acertados
		}
		else {
			contAgua++; // conta a quantidade de tiros na agua ,os tiros errados
		}
		colunaSec = RetornandoColuna(tabuA.jogadasJogo[a]); //pega os  valores da coordelada x (coluna)

		coluna += colunaSec; //soma as colunas

		linhaSec = RetornandoLinha(tabuA.jogadasJogo[a]); //pega os  valores da coordelada y (linha)

		linha += LetraNumero2(linhaSec)+1; // coloca nos valores do tabuleiro a = 1 ,b =2 ,...

	}
	qtdJogadas = i+1; //quantidade de jogadas

  	//---- centr?ide ----//
	locMedLinha = linha/(float)qtdJogadas; // media de linhas
	locMedColuna = coluna/(float)qtdJogadas;// media de colunas

	Desvio = DesvioPadrao(tabuA, qtdJogadas, locMedLinha, locMedColuna); //funcao desvio padrao

	//Printando as informacoes nos arquivos//
	fprintf(arquivoEsta,"%s\n",jogador);
	fprintf(arquivoEsta,"Tiros Errados: %d\n",contAgua);
	fprintf(arquivoEsta,"Tiros Acertados: %d\n",contTiro);
	fprintf(arquivoEsta,"Localizacao Media: (%.2f,%.2f)\n",locMedLinha,locMedColuna);
	fprintf(arquivoEsta,"Desvio Padrao da Localizacao: %.2f\n",Desvio);
	fprintf(arquivoEsta,"Navios de %s:",jogador);


}
void NavioAbatido(tTabuNavio tabuA ,FILE* arquivoEsta){ // navio abatido em ordem
	int a = 0,i = 0,cont =0;

	tabuA = VetorAux(tabuA ); //pega os ids dos navios que foram abatidos com um tiro em cada posicao

	/*Essa funcao serve para pegar os IDS unicos do navio
	e comparar com os outros atingidos e pegar somente o
	primeiro que aparece*/

	for (i =0;i < tabuA.qtdDoVetor;i++){
		for (a =0;a < tabuA.qtdAbatidos;a++){
			if (tabuA.vetorAux[i] == PassandoID(tabuA.abatido[a])){
				cont++;
				if (cont == 1){ //pega o primeiro navio que foi abatido
         			tabuA.abatido[i] = BotandoEmOrdem1(tabuA.abatido[a]);
				}
			}
		}
		cont=0;
	}

	tabuA = BotandoEmOrdem2(tabuA); //colocar em ordem alfabetica

	//---- printa os navios ----//
	for (i = 0;i < tabuA.qtdDoVetor;i++){
	    if (PassandoID(tabuA.abatido[i]) != 0){
			fprintf(arquivoEsta,"\n%02d ",PassandoPrimeiraTiro(tabuA.abatido[i]));
			ImprimiNomeNavio(tabuA.abatido[i],arquivoEsta);
			fprintf(arquivoEsta," ID %02d",PassandoID(tabuA.abatido[i]));
	    }

	}

}

int PassandoPrimeiraTiro(tNavioabatido abatido){ //passando o primeiro tiro
	return abatido.PriJogada;
}
int PassandoID(tNavioabatido abatido){//passando o ID
	return abatido.ID;
}
void ImprimiNomeNavio(tNavioabatido abatido,FILE* arquivoEsta){ //imprimindo o nome do navio
	fprintf(arquivoEsta,"- %s -",abatido.nomeNavio);
}

tNavioabatido BotandoEmOrdem1(tNavioabatido tabuA){ //funcao que serve para passar os paramentros
	tNavioabatido navio;

	navio.ID = tabuA.ID;
	navio.PriJogada = tabuA.PriJogada;
	strcpy(navio.nomeNavio, tabuA.nomeNavio); //passa valor de string para outra

	return navio;
}
tTabuNavio BotandoEmOrdem2(tTabuNavio tabuA){ //colocar em ordem alfabetica
	int i =0,a =0;
	tTabuNavio tabuAux; // tabuleiro auxiliar para trocar valores

	/*Troca os valores da struct para colocar em ordem alfabetica*/

	for (i = 0;i < tabuA.qtdDoVetor;i++ ){
		for (a = i+1;a < tabuA.qtdDoVetor;a++){
			if (PassandoString(tabuA.abatido[i],tabuA.abatido[a]) == 1){
				tabuAux.abatido[i] =  tabuA.abatido[i];
				tabuA.abatido[i] = tabuA.abatido[a];
				tabuA.abatido[a] = tabuAux.abatido[i];
			}
			if (PassandoString(tabuA.abatido[i],tabuA.abatido[a])== 0){
				if (PassandoPrimeiraTiro(tabuA.abatido[i]) > PassandoPrimeiraTiro(tabuA.abatido[a])){
					tabuAux.abatido[i] =  tabuA.abatido[i];
					tabuA.abatido[i] = tabuA.abatido[a];
					tabuA.abatido[a] = tabuAux.abatido[i];
				}
			}
		}

	}

	return tabuA;

}
int PassandoString(tNavioabatido tabuA,tNavioabatido tabuB){
	//funcao para retornar quando igual, maior ou menor um nome do navio do outro
	if (strcmp(tabuA.nomeNavio, tabuB.nomeNavio)> 0){
		return 1; // string 1 maior que a 2
	}
	else if (strcmp(tabuA.nomeNavio, tabuB.nomeNavio)==0){
		return 0;//string 1 = 2
	}
	else {
		return -1; //string 2 maior que a 1
	}
}

tTabuNavio VetorAux(tTabuNavio tabuA ){
	int i =0,a =0,cont = 0,cont2 =1;
	
	/*
	Essa funcao serve para pegar os ID dos tiros do navio , e logo depois pegar um ID
	uma unica vez ou seja se o id for repetido ele ira pegar somente um id Ex id : (8,7,9,9,6,4,8) ->R:(8,7,9,6,4)
	*/

	for (i =0;i < tabuA.qtdAbatidos;i++){
		if (i == 0){
			tabuA.vetorAux[i] = PassandoID(tabuA.abatido[i]); //primeiro sempre ira ser adicionado
		}
		else {
			for(a =0;a < i;a++){
				if (PassandoID(tabuA.abatido[a]) == PassandoID(tabuA.abatido[i])){ // se o id atual for igual aos antigos ira adicionar +1 em cont
					cont++;
				}
			}
			if (cont <= 0){ //se cont for maior q 0 será um id repetido , logo nao adicionara no  tabuA.vetorAux 
				tabuA.vetorAux[cont2] = PassandoID(tabuA.abatido[i]);
        		cont2++;
			}
		}
		cont = 0;
	}

	tabuA.qtdDoVetor = cont2; //quantidade de ids nao repetidos

	return tabuA;
}
//---------------------Desvio Padrao -----------------------//
float DesvioPadrao(tTabuNavio tabu,int i,float locMedLinha,float locMedColuna){
	int a=0,linha =0,coluna =0,qtdJogadas =0,divisao = 0;
	char linhaSec;
	float Desvio = 0.0,somatorio = 0.0,resultado = 0.0;

	for (a=0;a < i;a++){

		coluna = RetornandoColuna(tabu.jogadasJogo[a]);
		linhaSec = RetornandoLinha(tabu.jogadasJogo[a]);
		linha = LetraNumero2(linhaSec)+1; //+1 para encaixar no tabuleiro Ex:(9)=> R: 9+1: 10

		somatorio += pow((linha-locMedLinha),2) + pow((coluna-locMedColuna),2); //formula somatorio
		qtdJogadas++;

	}
 	// --- formula de desvio padrao --- //
  	resultado = somatorio/(float)qtdJogadas;
	Desvio = sqrt(resultado);

	return Desvio;
}

int RetornandoColuna(tJogadas JogColuna){
	return JogColuna.coluna;
}
char RetornandoLinha(tJogadas JogLinha){
	return JogLinha.linha;
}
// ------------------- Resultado do campeao ------------------- //
void ResultadoDoVencedor(int Ganhador1 ,int Ganhador2,FILE* arquivoResul,char jogador1[17],char jogador2[17]){
	//funcao que imprimi no arquivo quem for o campeao
	if (Ganhador1 == 1 &&  Ganhador2 == 1){
    	fprintf(arquivoResul,"\nEmpate");
	}
	else if(Ganhador1 == 1 &&  Ganhador2 == 0){
		fprintf(arquivoResul,"\nVencedor: %s",jogador1);
	}
	else if (Ganhador1 == 0 &&  Ganhador2 == 1){
		fprintf(arquivoResul,"\nVencedor: %s",jogador2);
	}

}
int ResultadoDoVencedor2(int Ganhador1 ,int Ganhador2,char jogador1[17],char jogador2[17]){
	//resultado do vencedor da funcao do jogo
	if (Ganhador1 == 1 &&  Ganhador2 == 1){
    	printf("\nEmpate\n");
		return 1;
	}
	else if(Ganhador1 == 1 &&  Ganhador2 == 0){
		printf("\nVencedor: %s\n",jogador1);
		return 1;
	}
	else if (Ganhador1 == 0 &&  Ganhador2 == 1){
		printf("\nVencedor: %s\n",jogador2);
		return 1;
	}
	else {
		return 0;
	}

}
//---------------------- Resultado do tabuleiro ---------------- //
tTabuNavio ResultadoJogador(tTabuNavio tabuA,int qtd,char jogador[17],FILE* arquivoResul){
	int i =0,cont=0,contSec =0,id=0;

	//funcao responsavel pelo arquivo resultado que ira contabilizar os tiros dos jogadores
	
	fprintf(arquivoResul,"%s\n",jogador);

	for(i =0;i <= qtd;i++){
		if (retornaTiro(tabuA.jogadasJogo[i])){
			//imprimi o navio abatido na jogada atual
			fprintf(arquivoResul,"%c%d - Tiro ",PassandoLinha(tabuA.jogadasJogo[i]),PassandoColuna(tabuA.jogadasJogo[i]));
			ImprimiNomeNavio2(tabuA.jogadasJogo[i],arquivoResul); //imprimir nome do navio abatido
			fprintf(arquivoResul," ID %02d\n",PassandoID2(tabuA.jogadasJogo[i]));

			cont++; // contador de numeros de jogadas

			tabuA.abatido[contSec] = PassandoIDeNomeePos(cont,tabuA.jogadasJogo[i]);

			contSec++; //contador para a quantidade de navios abatidos
		}
		else {
			//Se o tiro acertar a agua , ira salvar no arquivo resultado
			fprintf(arquivoResul,"%c%d - Agua\n",PassandoLinha(tabuA.jogadasJogo[i]),PassandoColuna(tabuA.jogadasJogo[i]));
			cont++;
		}

	}
	tabuA.qtdAbatidos = contSec; // quantidade de navios abatidos

	return tabuA;
}
//---------- funcoes auxiliares ------//
char PassandoLinha(tJogadas jogada){
	return jogada.linha;
}
int PassandoColuna(tJogadas jogada){
	return jogada.coluna;
}
int PassandoID2(tJogadas jogada){
	return jogada.ID;
}
void ImprimiNomeNavio2(tJogadas jogada,FILE* arquivoResul){ //imprimi no arquivo o nome do navio
	fprintf(arquivoResul,"- %s -",jogada.nomeNavio);
}


tNavioabatido PassandoIDeNomeePos(int cont,tJogadas nomeid){//passando o nome,id,posicao dos navios
	int i = 0;
	tNavioabatido navio;

	navio.PriJogada = cont;
	navio.ID = nomeid.ID;

	strcpy(navio.nomeNavio,nomeid.nomeNavio);

	return navio;

}

int retornaTiro(tJogadas tiro){ //funcao que retorna para ver se o tiro foi na agua ou no navio
	int TIRO =0;
	TIRO = tiro.Tiro;
	return TIRO;
}

int Ganhador(tTabuNavio tabuA){//descobre qual jogador ganhou a partida
	int l =0,c=0,cont =0;

	/*
	Se as casas do tabuleiro forem  diferentes de -191 , quer dizer que ainda ha navios
	entao a funcao   vai retorna 0 , mas se nao tiver navios ,ira retorna 1
	ai havera um campeao.
	*/

	for (l =0;l<10;l++){
		for (c =0;c<10;c++){
			if (tabuA.tabuleiroAux[l][c] != -191){
				cont++;
			}
		}
	}
	if (cont>0){
		return 0;
	}
	else{
		return 1;
	}

}
//----------- imprimir tabuleiro apos jogada -----------//
void ImprimirTabuleiraJogada(char tabuleiro[10][10]){
	int l = 0,c = 0;

	//funcao para imprimir o tabuleiro a cada jogada

	for (l =0;l < 10;l++){
		for(c=0;c < 10;c++){
	      if (c == 9){
	        printf("%c",tabuleiro[l][c]);
	      }
	      else {
	        printf("%c ",tabuleiro[l][c]);
	      }
		}
		printf("\n");
	}

}
//---------------------- jogadas (tiros) ------------ //
tTabuNavio Jogadas(tTabuNavio tabuA,tTabuNavio tabuB,tJogadas jogada,char tabuleiro[10][10],int i ){ //funcao para  jogada de cada jogador
	int linha =0,coluna =0,ID =0,Tiro = 0;

	linha = LetraNumero2(jogada.linha); // linha no tabuleiro
	coluna = ColocandoCoordenadaNoTabuleiro2(jogada.coluna);// coluna no tabuleiro

	/*
	Essa parte funciona :  a cada tiro certo , ele substitui o tabuleiro id pelo valor que representa agua(-191) ,
	ate deixar todas as posicoes com -191 , assim o jogador ganhara
	*/

	if (tabuB.tabuleiro[linha][coluna] == 'X'){
		Tiro = 1;

		tabuleiro[linha][coluna] = 'X'; //colocando "X" no tabuleiro que ira ser impresso
		ID = tabuA.tabuleiroAux[linha][coluna]; // pegando o ID antes de zerar o numero no tabuleiro
		tabuA.jogadasJogo[i] = retornandoIdETiro(tabuA.jogadasJogo[i] ,ID,Tiro); //pegando ID em cada posicao e os tiros
		tabuA.tabuleiroAux[linha][coluna] = -191; // coloca na posicao do tabulerio que contem os IDs 
		tabuA =  JogadasCertaNavio( tabuA, tabuB,ID,i); //funcao para ver se acertou o navio completo

	}
	else {
		Tiro = 0;
		tabuleiro[linha][coluna] = 'o'; //colocando "o" no tabuleiro que ira ser impresso
		tabuA.jogadasJogo[i] = retornandoIdETiro(tabuA.jogadasJogo[i] ,ID,Tiro);//pegando ID em cada posicao
		printf(":Agua\n");
	}

 	return tabuA;

}
tJogadas retornandoIdETiro(tJogadas jogada,int id,int Tiro){//retorna os ID e o tiro (1 : acertou navio,0: acertou Agua)
	jogada.ID = id;
	jogada.Tiro = Tiro;
	return jogada;
}
//------------- jogadas que acertaram os navios -------//
tTabuNavio JogadasCertaNavio(tTabuNavio tabuA,tTabuNavio tabuB,int ID,int i){
	int a =0,l =0,c=0,nome =0,cont=0;

	//Se o Id estiver contido no tabuleiro ele soma +1 na variavel "cont" .quer dizer que o navio ainda está no tabuleiro
	for (l=0;l <10;l++){
		for (c =0;c<10;c++){
			if (tabuA.tabuleiroAux[l][c] == ID){
				cont++;
			}
		}
	}
	//Pega o id dos navios e compara com o id desejavel e coloca na variavel "nome" a posicao que se encontra ,para saber a posicao correta dentro do vetor para saber o tipo do navio
	for(a =0;a < tabuB.contNavio;a++){
		if (IDdoNavio(tabuB.Navios[a]) == ID){
			nome = a; //posicao do navio atigindo
			break;
		}
	}
	//Se o Navio for totalmente afundado a variavel cont tem que ser 0 e imprimir "Afundou navio" ,caso ao contrario ira imprimir que o tiro deu certo
  	tabuA.jogadasJogo[i] = NomesDoBarcos(tabuA.jogadasJogo[i],tabuB.Navios[nome]); //passando os nomes dos navios para salvar em outra struct
	if (cont <= 0){
		ImprimiNomeNavio3(tabuB.Navios[nome]);

	}
	else {
		printf(":Tiro!\n");
	}

	return tabuA;
}
void ImprimiNomeNavio3(tNavio navio){ // imprimi o tipo do navio
	printf(":Afundou %s\n",navio.TipoNavio);
}

tJogadas NomesDoBarcos(tJogadas nome,tNavio nome2){

	strcpy(nome.nomeNavio,nome2.TipoNavio); // passando o nome dos navios de uma struct para outra
	return nome;
}

int ColocandoCoordenadaNoTabuleiro2(int coluna){ //passa a coluna da coordenada para a coluna do tabuleiro
	return coluna-1;
}

int LetraNumero2(char letra){ //passa a letra da coordenada para a linha do tabuleiro

	if (letra == 'a'){
		return 0;
	}
	else if (letra == 'b'){
		return 1;
	}
	else if (letra == 'c'){
		return 2;
	}
	else if (letra == 'd'){
		return 3;
	}
	else if (letra == 'e'){
		return 4;
	}
	else if (letra == 'f'){
		return 5;
	}
	else if (letra == 'g'){
		return 6;
	}
	else if (letra == 'h'){
	    return 7;
	}
	else if (letra == 'i'){
		return 8;
	}
	else if (letra == 'j'){
		return 9;
	}

}
void DecisaoJogador(char *nome){ // Imprimi a  jogada do jogador da vez

	printf("\nJogada de %s:\n",nome);
}
//----------- colocando valores de Id em cada espaco ocupado pelo navio ----------//
tTabuNavio ColocandoValoresNavio(tTabuNavio tabuA,tTabuNavio tabuB){
	int i =0 ,l =0,c =0,Lini=0,Cini=0,TamN=0,sentido=0,x =0;

	/*
	Essa funcao serve primeiro para iniciar tabuleiro auxiliar com o numero -191,que representa Agua;
	logo depois colocar os valores de id em cada coordenada do navio , ja que os ids sao unicos;
	E por ultimo passar os valores do tabuleiro para a matriz auxiliar da struct;
	*/

	int tabuAuxiliar[10][10];

	for (l =0;l< 10;l++){ // iniciando tabuleiro auxiliar com o numero -191 (numero aleatorio)
		for (c=0;c <10;c++){
			tabuAuxiliar[l][c] = -191;
		}
	}

	for (i =0;i < tabuB.contNavio;i++){

		Lini = LetraNumero(tabuB.Navios[i]); //coordenada Linha inicial
		Cini = ColocandoCoordenadaNoTabuleiro(tabuB.Navios[i]);//coordenada coluna inicial
		TamN = TamanhoDoBarco(tabuB.Navios[i]); // tamanho do navio
		sentido =  Sentido(tabuB.Navios[i]); //sentido barco

		if (sentido == 1){
			if (tabuB.tabuleiro[Lini][Cini] == 'X'){
				for (x = 0;x < TamN;x++){//tamanho que o navio ocupa no tabuleiro
					tabuAuxiliar[Lini][Cini+x] = IDdoNavio(tabuB.Navios[i]);
				}
		   }
		}
		else {
			if (sentido == 0){
				if (tabuB.tabuleiro[Lini][Cini] == 'X'){
					for (x = 0;x < TamN;x++){
						tabuAuxiliar[Lini+x][Cini] = IDdoNavio(tabuB.Navios[i]);
					}
				}
			}
		}

	}
	for (l =0;l <10;l++){
		for (c= 0;c < 10;c++){
			tabuA.tabuleiroAux[l][c] = tabuAuxiliar[l][c]; // passando os valores do tabuleiro auxiliar para  tabuleiroAux
		}
	}

	return tabuA;

}

int IDdoNavio(tNavio id){ //retorna o id dos navios
	return id.id;
}
// ---------- valores iniciais do tabuleiro --------//
void TabuleiroInicialImpresso(char tabuleiro[10][10]){ //passa o valor do tabuleiro inicial "."
	int l =0,c =0;

	for (l =0;l < 10;l++){
		for (c =0;c < 10;c++){
			tabuleiro[l][c] = '.';
		}
	}

}
//----------------  funcao para a jogada das coordenadas ----- //
tTabuNavio JogadoresJogadas(int qtd,tTabuNavio tabu,char jogador[17]){
	char vetor[10];//vetor auxiliar para digitar as jogadas
	char linha;
	int coluna;

	scanf("%s",vetor); //coordenadas da jogada do jogador
	tabu.jogadasJogo[qtd] = PassandoJogadaDigitada(tabu.jogadasJogo[qtd],vetor);//passando a jogada para struct na parte de jogadinhas para a funcao repetida (em formato de string)

	while(!verificaLinha(tabu.jogadasJogo[qtd]) || !verificaColuna(tabu.jogadasJogo[qtd]) || !verificaRepetida(tabu.jogadasJogo,qtd) ){//se for invalida ou repetida ,o jogador ira ter que jogar de novo
		printf("\n%s:Jogada invalida! Jogue novamente %s:\n",vetor,jogador);
		scanf("%s",vetor);
		tabu.jogadasJogo[qtd] = PassandoJogadaDigitada(tabu.jogadasJogo[qtd],vetor);
	}

	sscanf(vetor ,"%c%d",&linha,&coluna);
	tabu.jogadasJogo[qtd] = PassandoJogadaDigitadaComsscanf(tabu.jogadasJogo[qtd],linha,coluna);//passando a jogada para struct  para a funcao repetida (em formato de char e int)

	printf("\n%s",vetor);

	return tabu;

}
tJogadas PassandoJogadaDigitadaComsscanf(tJogadas jogada,char linha,int coluna){ //passando a jogada valida para a struct

	jogada.coluna = coluna; //atribui os valores de coluna
	jogada.linha = linha; //atribui os valores de linha

	return jogada;
}

tJogadas PassandoJogadaDigitada(tJogadas jogada,char *vetor){ //jogada digita passando para a struct em string

	strcpy(jogada.jogadinhas,vetor);
	return jogada;
}

int verificaRepetida(tJogadas *str,int qtd){ //veridica se e uma jogada repetida
	int i = 0 ,i2 =0;

	//compara os valores das jogadas para ver se foi igual a alguma anterior
	if (qtd > 0){
		for (i =0;i < qtd;i++){
			for (i2 = i+1;i2 <= qtd;i2++){
				if(strcmp(str[i].jogadinhas,str[i2].jogadinhas) ==0){
					return 0;
				}
			}
		}
		return 1;
	}
	else {
		return 1;
	}
}
int verificaColuna(tJogadas letra){// ve se o comando foi valido na coordenada linha
	//quando a coordenada da coluna for 1 , ele podera ser 1 ou 10 , entao ele ira ver cada posicao do vetor
	if(letra.jogadinhas[1] == '1'){
		if (letra.jogadinhas[2] == '0'){
			if (letra.jogadinhas[3] == '\0'){
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			if (letra.jogadinhas[2] =='\0' ){
				return 1;
			}
			else {
				return 0;
			}
		}

	}
	else if (letra.jogadinhas[1] == '2'){
		if (letra.jogadinhas[2]== '\0'){
			return 1;
		}
		else {
			return 0;
		}

	}
	else if (letra.jogadinhas[1] == '3'){
		if (letra.jogadinhas[2]== '\0'){
			return 1;
		}
		else {
			return 0;
		}

	}
	else if (letra.jogadinhas[1]== '4'){
		if (letra.jogadinhas[2] == '\0'){
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (letra.jogadinhas[1] == '5'){
		if (letra.jogadinhas[2] == '\0'){
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (letra.jogadinhas[1] == '6'){
		if (letra.jogadinhas[2] == '\0'){
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (letra.jogadinhas[1] == '7'){
		if (letra.jogadinhas[2] == '\0'){
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (letra.jogadinhas[1] == '8'){
		if (letra.jogadinhas[2] == '\0'){
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (letra.jogadinhas[1] == '9'){
		if (letra.jogadinhas[2]== '\0'){
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

}
//--------- verifica se a coordenada linha esta de acordo  com o tabuleiro -----//
int verificaLinha(tJogadas letra){ // ve se o comando foi valido na linha
	if (letra.jogadinhas[0] == 'a' || letra.jogadinhas[0] == 'b' ||
		letra.jogadinhas[0] == 'c' || letra.jogadinhas[0] == 'd' ||
		letra.jogadinhas[0] == 'e' || letra.jogadinhas[0] == 'f' ||
		letra.jogadinhas[0] == 'g' || letra.jogadinhas[0] == 'h' ||
		letra.jogadinhas[0] == 'i' || letra.jogadinhas[0] == 'j' )
	{
		return 1;
	}
	else {
		return 0;
	}

}
//----------- (4) funcao ler nome dos jogadores ------------//
void NomesUsuarios(tTabuNavio tabu1,tTabuNavio tabu2,char jogador1[17],char jogador2[17],char *argv){
    FILE* player; //arquivo para salvar na pasta inicializacao
    int l =0,c=0;

	//funcao que salva os nomes e o tabuleiro de cada jogador
	char Arq4[1000];
	sprintf(Arq4,"%s/saida/inicializacao.txt" ,argv);

    player = fopen(Arq4,"w");
    printf("Nome do Jogador 1:\n");
    scanf("%s",jogador1);
    fprintf(player,"%s",jogador1);
    fprintf(player,"\n");

	// jogador 1
    for (l =0;l < 10;l++){
      for (c=0;c< 10;c++){
        if (c == 9){
          fprintf(player,"%c",tabu1.tabuleiro[l][c]);
        }
        else {
          fprintf(player,"%c ",tabu1.tabuleiro[l][c]);
        }

      }
      fprintf(player,"\n");
    }
    fprintf(player,"\n");

    // jogador 2
    printf("Nome do Jogador 2:\n");
    scanf("%s",jogador2);
    fprintf(player,"%s",jogador2);
    fprintf(player,"\n");

    for (l =0;l < 10;l++){
      for (c=0;c< 10;c++){
        if ( c==9){
          fprintf(player,"%c",tabu2.tabuleiro[l][c]);
        }
        else {
          fprintf(player,"%c ",tabu2.tabuleiro[l][c]);
        }

      }
      if(l != 9){
        fprintf(player,"\n");
      }

    }

    fclose(player);
}
//----------------- verifica se sao validos  para inicializar o jogo -------------//
void Compatibilidade(tTabuNavio tabu1,tTabuNavio tabu2,char *argv){
	FILE* verifica; //arquivo da verificacao do tabuleiro
	char Arq5[1000];
	sprintf(Arq5,"%s/saida/validacao_tabuleiros.txt" ,argv);
	
	if (tabu1.valido == 1 && tabu2.valido == 1){ // tabuleiros validos
		if (tabuleirosCompativeis( tabu1, tabu2)){
		  verifica = fopen(Arq5,"w");
	      fprintf(verifica,"%s","tabu_1.txt;valido\ntabu_2.txt;valido\nTabuleiros compativeis entre si");
	      fclose(verifica);
		}
		else {
		  verifica = fopen(Arq5,"w");
	      fprintf(verifica,"%s","tabu_1.txt;valido\ntabu_2.txt;valido\nTabuleiros incompativeis entre si");
	      fclose(verifica);
	      
       	  exit(1);
		}
	}
	else if(tabu1.valido == 1 && tabu2.valido == 0){// tabuleiro 1 valido e 2 invalido
		  verifica = fopen(Arq5,"w");
	      fprintf(verifica,"%s","tabu_1.txt;valido\ntabu_2.txt;invalido");
	   	  fclose(verifica);

	   	 
       	  exit(1);
	}
	else if(tabu1.valido == 0 && tabu2.valido == 1){// tabuleiro 1 invalido e 2 valido
		 verifica = fopen(Arq5,"w");
	      fprintf(verifica,"%s","tabu_1.txt;invalido\ntabu_2.txt;valido");
	      fclose(verifica);

	      
          exit(1);
	}
	else if(tabu1.valido == 0 && tabu2.valido == 0){// tabuleiro 1 invalido e 2 invalido
		  verifica = fopen(Arq5,"w");
		  fprintf(verifica,"%s","tabu_1.txt;invalido\ntabu_2.txt;invalido");
		  fclose(verifica);

	      exit(1);
	}


}
// ----------------- (2) tabuleiros compativeis -------------------------//
int tabuleirosCompativeis(tTabuNavio tabu1,tTabuNavio tabu2){
	int pos =0;
	//essa funcao ira ver se a quantidade de navios sao iguais e se tem a mesma quantidade de cada navio
	if (tabu1.contNavio == tabu2.contNavio){ //quantidades de navios

		int Carrier1 = 0,Battleship1 = 0,Cruiser1 = 0,Submarine1 =0,Destroyer1 = 0;
		int Carrier2 = 0,Battleship2 = 0,Cruiser2 = 0,Submarine2 =0,Destroyer2 = 0;

		while (pos < tabu1.contNavio){
			char barco1[8] = "Carrier"; 	//5
			char barco2[11]="Battleship"; 	//4
			char barco3[8] ="Cruiser";		//3
			char barco4[10]="Submarine";	//3
			char barco5[10]= "Destroyer";	//2

			if (PassandoString2(tabu1.Navios[pos] ,barco1)== 0  ){
				Carrier1++;
			}
			else if (PassandoString2(tabu1.Navios[pos] ,barco2)==0){
				Battleship1++;
			}
			else if (PassandoString2(tabu1.Navios[pos] ,barco3)==0){
				Cruiser1++;
			}
			else if (PassandoString2(tabu1.Navios[pos] ,barco4)==0){
				Submarine1++;
			}
			else if (PassandoString2(tabu1.Navios[pos] ,barco5)==0){
				Destroyer1++;
			}
			if (PassandoString2(tabu2.Navios[pos] ,barco1)== 0){
				Carrier2++;
			}
			else if (PassandoString2(tabu2.Navios[pos] ,barco2)==0){
				Battleship2++;
			}
			else if (PassandoString2(tabu2.Navios[pos] ,barco3)==0){
				Cruiser2++;
			}
			else if (PassandoString2(tabu2.Navios[pos] ,barco4)==0){
				Submarine2++;
			}
			else if (PassandoString2(tabu2.Navios[pos] ,barco5)==0){
				Destroyer2++;
			}

			pos++;
		}
		if (Carrier1 == Carrier2 && Battleship1 == Battleship2 && Cruiser1 == Cruiser2 && Submarine1 == Submarine2 && Destroyer1 == Destroyer2 ){ //se cada quantidade de navios forem iguais ira ser compativel
			return 1; //Tabuleiros Compativeis entre si
		}
		else {
			return 0; //Tabuleiros Imcompativeis entre si
		}

	}
	else {
		return 0; //Tabuleiros Imcompativeis entre si
	}
}
int PassandoString2(tNavio tabuA ,char *string){
	if (strcmp(tabuA.TipoNavio,string)==0){
		return 0;
	}
}

// ------------- (1) lendo as informacoes dos navios ----------- //
tTabuNavio LeNavios(FILE* tabu){
	int cont=0;
	char NomesNavios[100];

	tNavio Navios[50];
	tTabuNavio navio;

	//fun?ao para ler o arquivo que contem os navios
	while (!feof(tabu)){
		fscanf (tabu,"%[^\n]\n",NomesNavios);
		sscanf(NomesNavios,"%[^;];%d;%d;%c%d",Navios[cont].TipoNavio,&Navios[cont].id, //Passando informacoes do navios
		&Navios[cont].sentido,&Navios[cont].coordLetra,&Navios[cont].coordNumero);

		cont++; //quantidade de navios
	}


	navio = retornaNavios(Navios ,cont);

	return navio;
}
tTabuNavio retornaNavios(tNavio *Navios ,int qtd){
	int a = 0;

	tTabuNavio navio;

	for (a =0;a < qtd ;a++){
		navio.Navios[a] = Navios[a]; // adiciona os parametros dos navios como tipo,coordenada,sentido,etc...
	}

  	navio.contNavio = qtd; //quantidade de navios
  	navio  =  ValidaTabuleiro(navio); //validacao do tabuleiro

	return navio;
}

tTabuNavio ValidaTabuleiro(tTabuNavio tabuleiros){

	tabuleiros = TabuleiroInicial(tabuleiros); //tabuleiro inicial : as posicoes sao todas agua ("o")

	tabuleiros = ColocandoNavios( tabuleiros); //coloca os navios dentro do tabuleiro se for possivel

	return tabuleiros;

}
// ------------------- colocando navios no tabuleiro ------------------//
tTabuNavio ColocandoNavios(tTabuNavio tabu){
	int LfinH =0 ,CfinH = 0; //Posicao final dos navios
	int a = 0,Lini =0,Cini = 0,TamN =0,sentido =0;
	int l =0,c=0,x =0,cont = 0;

	tabu.valido = 1; //navio ja comeca valido

	for (a = 0;a < tabu.contNavio;a++){ // for com cada navio no tabuleiro

		Lini = LetraNumero(tabu.Navios[a]); //coordenada Linha inicial
		Cini = ColocandoCoordenadaNoTabuleiro(tabu.Navios[a]);//coordenada coluna inicial
		TamN = TamanhoDoBarco(tabu.Navios[a]); // tamanho do navio
		sentido =  Sentido(tabu.Navios[a]); //sentido barco

		if (Lini == -1 || Cini > 9 || Cini < 0){ // se a letra ou coluna nao estiver contido  no tabuleiro ,sera invalida
			tabu.valido = 0;
		}
		//-------------- Sentido horizontal ------------//
		if (sentido == 1){
			CfinH = Cini + TamN -1; //Posicao final dos navios
			if (UltrapassouLimites(CfinH)){
				cont++;
			}

			for (x =0 ;x < TamN ;x++){ // verifica se ha algo dentro do navio
				if (tabu.tabuleiro[Lini][Cini+x] == 'X'){
					cont++;
				}
			}

			if (Lini == 0 && Cini >=0 && Cini <= 9){ // primeira linha
				if (Cini == 0){ // inicial na coluna  ZERO
					for (l = 0;l < TamN;l++){
						if (tabu.tabuleiro[Lini+1][l] == 'X'){
							cont++;
						}
					}
					if (tabu.tabuleiro[Lini][CfinH+1] == 'X' ||tabu.tabuleiro[Lini+1][CfinH+1] == 'X' || tabu.tabuleiro[Lini+1][CfinH] == 'X' ){
						cont++;
					}
				}
				else if (Cini > 0 && CfinH < 9){//no meio da primeira linha
					for (l = 0;l < TamN;l++){
						if (tabu.tabuleiro[Lini+1][Cini+l] == 'X' ){
							cont++;
						}
					}
					if (tabu.tabuleiro[Lini][Cini-1] == 'X' ||tabu.tabuleiro[Lini+1][Cini-1] == 'X' || tabu.tabuleiro[Lini+1][Cini] == 'X' ){
						cont++;
					}
					else if(tabu.tabuleiro[Lini+1][CfinH+1] == 'X' ||tabu.tabuleiro[Lini][CfinH+1] == 'X' || tabu.tabuleiro[Lini+1][CfinH] == 'X'){
						cont++;
					}
				}
				else if (CfinH == 9){//No ponto final
					for (l = 0;l < TamN;l++){
						if (tabu.tabuleiro[Lini+1][Cini+l] == 'X'){
							cont++;
						}
					}
					if (tabu.tabuleiro[Lini][Cini-1] == 'X' ||tabu.tabuleiro[Lini+1][Cini-1] == 'X' || tabu.tabuleiro[Lini+1][Cini] == 'X' ){
						cont++;
					}
				}
			}
			else if(Lini > 0 && Lini < 9 && Cini ==0 ){//Meio  lateral Esquerda
				for (l = 0;l < TamN;l++){
					if (tabu.tabuleiro[Lini+1][Cini+l] == 'X' || tabu.tabuleiro[Lini-1][Cini+l] == 'X' ){
						cont++;
					}
				}
				if (tabu.tabuleiro[Lini-1][CfinH] == 'X' || tabu.tabuleiro[Lini-1][CfinH+1] == 'X' ||
					tabu.tabuleiro[Lini][CfinH+1] == 'X' ||tabu.tabuleiro[Lini+1][CfinH+1] == 'X'  ||
					tabu.tabuleiro[Lini+1][CfinH] == 'X' ){
					cont++;
				}
			}
			else if(Lini > 0 && Lini < 9 && CfinH ==9 ){//Meio  lateral Direita
				for (l = 0;l < TamN;l++){
					if (tabu.tabuleiro[Lini+1][Cini+l] == 'X' || tabu.tabuleiro[Lini-1][Cini+l] == 'X' ){
						cont++;
					}
				}
				if (tabu.tabuleiro[Lini-1][Cini] == 'X' || tabu.tabuleiro[Lini-1][Cini-1] == 'X' ||
					tabu.tabuleiro[Lini][Cini-1] == 'X' ||tabu.tabuleiro[Lini+1][Cini-1] == 'X'  ||
					tabu.tabuleiro[Lini+1][Cini] == 'X' ){
					cont++;
				}
			}
			else if (Lini == 9 && Cini >=0 && Cini <= 9){ // ultima  linha
				if (Cini == 0){ // inicial na coluna ZERO
					for (l = 0;l < TamN;l++){
						if (tabu.tabuleiro[Lini-1][l] == 'X'){
							cont++;
						}
					}
					if (tabu.tabuleiro[Lini][CfinH+1] == 'X' ||tabu.tabuleiro[Lini-1][CfinH+1] == 'X' || tabu.tabuleiro[Lini-1][CfinH] == 'X' ){
						cont++;
					}
				}
				else if (Cini > 0 && CfinH < 9){//no meio da primeira linha
					for (l = 0;l < TamN;l++){
						if (tabu.tabuleiro[Lini-1][Cini+l] == 'X' ){
							cont++;
						}
					}
					if (tabu.tabuleiro[Lini][Cini-1] == 'X' ||tabu.tabuleiro[Lini-1][Cini-1] == 'X' || tabu.tabuleiro[Lini-1][Cini] == 'X' ){
						cont++;
					}
					else if(tabu.tabuleiro[Lini][CfinH+1] == 'X' ||tabu.tabuleiro[Lini-1][CfinH+1] == 'X' || tabu.tabuleiro[Lini-1][CfinH] == 'X'){
						cont++;
					}
				}
				else if (CfinH == 9){//No ponto final
					for (l = 0;l < TamN;l++){
						if (tabu.tabuleiro[Lini-1][Cini+l] == 'X'){
							cont++;
						}
					}
					if (tabu.tabuleiro[Lini][Cini-1] == 'X' ||tabu.tabuleiro[Lini-1][Cini-1] == 'X' || tabu.tabuleiro[Lini-1][Cini] == 'X' ){
						cont++;
					}
				}
			}
			else if (Lini>0 && Lini<9 && Cini >0 && CfinH<9){ //meio do tabuleiro
				for (l = 0;l < TamN;l++){
					if (tabu.tabuleiro[Lini+1][Cini+l] == 'X' || tabu.tabuleiro[Lini-1][Cini+l] == 'X' ){
						cont++;
					}
				}
				if (tabu.tabuleiro[Lini-1][Cini] == 'X' || tabu.tabuleiro[Lini-1][Cini-1] == 'X' ||
					tabu.tabuleiro[Lini][Cini-1] == 'X' ||tabu.tabuleiro[Lini+1][Cini-1] == 'X'  ||
					tabu.tabuleiro[Lini+1][Cini] == 'X' ){
					cont++;
				}
				if (tabu.tabuleiro[Lini-1][CfinH] == 'X' || tabu.tabuleiro[Lini-1][CfinH+1] == 'X' ||
					tabu.tabuleiro[Lini][CfinH+1] == 'X' ||tabu.tabuleiro[Lini+1][CfinH+1] == 'X'  ||
					tabu.tabuleiro[Lini+1][CfinH] == 'X' ){
					cont++;
				}
			}
			if (cont <= 0){
				for (x =0 ;x < TamN ;x++){ //adiciona o valor "X" se for tudo valido(cont for = 0) para acoplar o navio
					tabu.tabuleiro[Lini][Cini+x] = 'X';
				}
				cont = 0;
			}
			else {
				tabu.valido = 0;
				cont = 0;
			}
		}

		//--------------------- sentido Vertical ------------------------//
		if (sentido == 0){
			LfinH = Lini + TamN -1; // ponto final (linha final)

			if (UltrapassouLimites(LfinH)){ // verifica se o tamanho do navio passou do  limite do tabuleuri
				cont++;
			}

			for (x =0 ;x < TamN ;x++){ // verifica se ha algo dentro do navio
				if (tabu.tabuleiro[Lini+x][Cini] == 'X'){
					cont++;
				}
			}

			if (Lini == 0 &&  Cini>=0 && Cini<=9 ){ // encontra na linha 0 variando na coluna
				if (Cini == 0){
					for (c =0;c < TamN;c++){
						if (tabu.tabuleiro[Lini+c][Cini+1] == 'X'){
							cont++;
						}
					}
					if(tabu.tabuleiro[LfinH][Cini+1] == 'X'|| tabu.tabuleiro[LfinH+1][Cini+1] == 'X'||tabu.tabuleiro[LfinH+1][Cini] == 'X'){
						cont++;
					}
				}
				else if (Cini>0 && Cini<9){ //meio da coluna
					for (c =0;c < TamN;c++){
						if (tabu.tabuleiro[Lini+c][Cini+1] == 'X' ||tabu.tabuleiro[Lini+c][Cini-1] == 'X'  ){
							cont++;
						}
					}
					if(tabu.tabuleiro[LfinH][Cini-1] == 'X'|| tabu.tabuleiro[LfinH][Cini+1] == 'X'||
						tabu.tabuleiro[LfinH+1][Cini-1] == 'X' || tabu.tabuleiro[LfinH+1][Cini] == 'X'||
						tabu.tabuleiro[LfinH+1][Cini+1] == 'X' ){
						cont++;
					}
				}
				else if(Cini == 9){ //final da coluna
					for (c =0;c < TamN;c++){
						if (tabu.tabuleiro[Lini+c][Cini-1] == 'X'){
							cont++;
						}
					}
					if(tabu.tabuleiro[LfinH][Cini-1] == 'X'|| tabu.tabuleiro[LfinH+1][Cini-1] == 'X'||tabu.tabuleiro[LfinH+1][Cini] == 'X'){
						cont++;
					}
				}
			}
			else if (Lini> 0 && LfinH < 9 && Cini==0 ){ //verifica primeira coluna variando na linha
				for (c =0;c < TamN;c++){
					if (tabu.tabuleiro[Lini+c][Cini+1] == 'X'){
						cont++;
					}
				}
				if(tabu.tabuleiro[Lini][Cini+1] == 'X'|| tabu.tabuleiro[Lini-1][Cini+1] == 'X'||tabu.tabuleiro[Lini-1][Cini] == 'X'){
					cont++;
				}
				else if(tabu.tabuleiro[LfinH][Cini+1] == 'X'|| tabu.tabuleiro[LfinH+1][Cini+1] == 'X'||tabu.tabuleiro[LfinH+1][Cini] == 'X'){
					cont++;
				}
			}
			else if (Lini> 0 && LfinH < 9 && Cini==9 ){ //ultima coluna variando na linha
				for (c =0;c < TamN;c++){
					if (tabu.tabuleiro[Lini+c][Cini-1] == 'X'){
						cont++;
					}
				}
				if(tabu.tabuleiro[Lini][Cini-1] == 'X'|| tabu.tabuleiro[Lini-1][Cini-1] == 'X'||tabu.tabuleiro[Lini-1][Cini] == 'X'){
					cont++;
				}
				else if(tabu.tabuleiro[LfinH+1][Cini] == 'X'|| tabu.tabuleiro[LfinH+1][Cini-1] == 'X'||tabu.tabuleiro[LfinH][Cini-1] == 'X'){
					cont++;
				}
			}
			if (LfinH == 9 &&  Cini>=0 && Cini<=9 ){ // ultima linha variando na coluna
				if (Cini == 0){
					for (c =0;c < TamN;c++){
						if (tabu.tabuleiro[Lini+c][Cini+1] == 'X'){
							cont++;
						}
					}
					if(tabu.tabuleiro[Lini][Cini+1] == 'X'|| tabu.tabuleiro[Lini-1][Cini+1] == 'X'||tabu.tabuleiro[LfinH+1][Cini] == 'X'){
						cont++;
					}
				}
				else if (Cini>0 && Cini<9){
					for (c =0;c < TamN;c++){
						if (tabu.tabuleiro[Lini+c][Cini+1] == 'X' ||tabu.tabuleiro[Lini+c][Cini-1] == 'X'  ){
							cont++;
						}
					}
					if(tabu.tabuleiro[Lini][Cini+1] == 'X'|| tabu.tabuleiro[Lini-1][Cini+1] == 'X'||
						tabu.tabuleiro[Lini-1][Cini] == 'X' || tabu.tabuleiro[Lini-1][Cini-1] == 'X'||
						tabu.tabuleiro[Lini][Cini-1] == 'X' ){
						cont++;
					}
				}
				else if(Cini == 9){
					for (c =0;c < TamN;c++){
						if (tabu.tabuleiro[Lini+c][Cini-1] == 'X'){
							cont++;
						}
					}
					if(tabu.tabuleiro[Lini-1][Cini] == 'X'|| tabu.tabuleiro[Lini-1][Cini-1] == 'X'||tabu.tabuleiro[Lini][Cini-1] == 'X'){
						cont++;
					}
				}
			}
			else if (LfinH < 9 && Lini > 0 && Cini>0 && Cini<9){ // meio do tabuleiro
				for (c =0;c < TamN;c++){
					if (tabu.tabuleiro[Lini+c][Cini-1] == 'X'||tabu.tabuleiro[Lini+c][Cini+1] == 'X'){
						cont++;
					}
				}
				if(tabu.tabuleiro[Lini][Cini+1] == 'X'|| tabu.tabuleiro[Lini-1][Cini+1] == 'X'||
					tabu.tabuleiro[Lini-1][Cini] == 'X' || tabu.tabuleiro[Lini-1][Cini-1] == 'X'||
					tabu.tabuleiro[Lini][Cini-1] == 'X' ){
					cont++;
				}
				else if(tabu.tabuleiro[LfinH][Cini+1] == 'X'|| tabu.tabuleiro[LfinH+1][Cini+1] == 'X'||
					tabu.tabuleiro[LfinH+1][Cini] == 'X' || tabu.tabuleiro[LfinH+1][Cini-1] == 'X'||
					tabu.tabuleiro[LfinH][Cini-1] == 'X' ){
					cont++;
				}
			}
			if (cont <= 0){
				for (x =0 ;x < TamN ;x++){ //adiciona o valor "X" se for tudo valido para acoplar o navio
					tabu.tabuleiro[Lini+x][Cini] = 'X';
				}
				cont = 0;
			}
			else {
				tabu.valido = 0;
				cont = 0;
			}
		}
	}

	return tabu;
}
int Sentido(tNavio Navios){ //sentido dos navios

	if (Navios.sentido == 1){
		return 1; // sentido = 1 na horizontal
	}
	else if (Navios.sentido == 0){
		return 0;// sentido = 0 na vertical
	}

}

int UltrapassouLimites(int NavioLimite){ //funcao para ver se um navio ultaprassou o limite do tabuleiro

	if(NavioLimite > 9 ){
		return 1;
	}
	else {
		return 0;
	}

}

tTabuNavio TabuleiroInicial(tTabuNavio tabuleiros){ //tabuleiro comeca com "o" representando agua
	int l = 0,c =0;

	for (l =0;l < 10;l++){
		for (c =0;c < 10;c++){
			tabuleiros.tabuleiro[l][c] = 'o';
		}
	}

	return tabuleiros;
}
int ColocandoCoordenadaNoTabuleiro(tNavio Navios){//funcao para passar a coluna para as coordenadas do tabuleiro

	return Navios.coordNumero-1;
}

int LetraNumero(tNavio Navios){ //funcao para passar a letra para as coordenadas do tabuleiro
	char letra = Navios.coordLetra;

	if (letra == 'a'){
		return 0;
	}
	else if (letra == 'b'){
		return 1;
	}
	else if (letra == 'c'){
		return 2;
	}
	else if (letra == 'd'){
		return 3;
	}
	else if (letra == 'e'){
		return 4;
	}
	else if (letra == 'f'){
		return 5;
	}
	else if (letra == 'g'){
		return 6;
	}
	else if (letra == 'h'){
	    return 7;
	}
	else if (letra == 'i'){
		return 8;
	}
	else if (letra == 'j'){
		return 9;
	}
	else {
		return -1; //erro nas linhas
	}
}

int TamanhoDoBarco(tNavio Navios){ //verifica o tamanho do barco atraves do seu tipo
	char barco1[8] = "Carrier"; 	//5
	char barco2[11]="Battleship"; 	//4
	char barco3[8] ="Cruiser";		//3
	char barco4[10]="Submarine";	//3
	char barco5[10]= "Destroyer";	//2

	int resultado1 = strcmp(Navios.TipoNavio,barco1);
	int resultado2 = strcmp(Navios.TipoNavio,barco2);
	int resultado3 = strcmp(Navios.TipoNavio,barco3);
	int resultado4 = strcmp(Navios.TipoNavio,barco4);
	int resultado5 = strcmp(Navios.TipoNavio,barco5);

	if (!resultado1){
		return 5;
	}
	else if (!resultado2){
		return 4;
	}
	else if(!resultado3){
		return 3;
	}
	else if (!resultado4){
		return 3;
	}
	else if (!resultado5){
		return 2;
	}

}


