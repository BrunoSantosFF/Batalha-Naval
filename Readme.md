<h1>BATALHA NAVAL</h1>

- É um jogo criado na linguagem C 
- Representa uma batalha Naval
- Tem objetivo de destruir todos os navios do inimigo


Passo 1 :
    Dentro de uma pasta(Ex:Batalha), deverá conter o arquivo executável(BatalhaNaval.c) e uma pasta para jogadas(Ex: 01).
    Dentro da pasta 01 conterá :
    - Uma pasta chamada "saída"(vazia)
    - tabu_1.txt
    - tabu_2.txt
    - jogadas.txt
    *(esses últimos 3 está disponibilizado no final desse arquivo)

Passo 2 :
    Para compilação no terminal do linux :
    1) gcc -o prog BatalhaNaval.c -lm
        - obs: o arquivo "prog" poderá ser qualquer nome que desejar
    2) ./prog 01
        - obs : "01" por que é a pasta que contém os arquivos de comandos do jogo
    -Até esse ponto você poderá jogar o jogo manualmente.

    -JOGANDO AUTOMATICAMENTE :
    1) gcc -o prog BatalhaNaval.c -lm
        - obs: o arquivo "prog" poderá ser qualquer nome que desejar
    2)./prog 01 <01/jogadas.txt
        -através desse comando você ira direcionar o que há dentro do arquivo "jogadas.txt" para que o programa compile automaticamente

    EXTRA:
    -Caso queira ver as Estatísticas,Inicialização,Resultado,Validação do tabuleiro ,siga os passos :
    3)./prog 01 <01/jogadas.txt> saida.txt
        -Você verá os dados tudo na pasta de saída
    Estatisticas : quantidade de tiros de cada jogador certos ou errados , os navios abatidos , etc.
    Inicialização : Tabuleiro inicial de cada jogador
    Resultado : Cada tiro em cada posição e o vencedor
    Validação tabuleiro : Mostrará se está tudo ok com o tabuleiro (tamanhos dos navios não podem ultrapassar a borda,nome errados de navios, etc.) 


*Pastas :
jogadas.txt :
    Leticia
    Thiago
    b3
    a2
    b1
    a3
    b2
    a4

tabu_1.txt :
Submarine;1;1;a2

tabu_2.txt :
Submarine;1;0;g3


Informações do jogo:
Tipo Barco  - tamanho
    Carrier - 5
    Battleship - 4
    Cruiser  - 3
    Submarine - 3
    Destroyer - 2
Detalhes do tabuleiro (tabu_x.txt):

Submarine(tipo de barco);1(sentido 1-horizontal/2-vertical);0;g3(coordenada X e Y).

FIM......

