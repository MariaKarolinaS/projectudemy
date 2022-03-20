#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <new>
#include <string.h>
#include <time.h>

using namespace std;

void LimpaTela(){
    system("CLS");
}

string RetornaPalavraAleatoria(){
    string Palavras[5] = {"abacaxi", "manga", "morango", "uva", "jambo"};
    int IndiceAleatorio = rand() % 3;
    return Palavras[IndiceAleatorio];
} //RETORNA A PALAVRA ALEATORIA GERADA PELO RAND

string RetornaPalavraComMascara(string Palavra, int TamanhoDaPalavra){

    int cont = 0;

    string PalavraComMascara;
    while(cont < TamanhoDaPalavra){
        PalavraComMascara += "_";
        cont ++;
    }
    return PalavraComMascara;

} /// É EXIBIDO O NUMERO DE _ DE ACORDO COM AS LETRAS DA PALAVRA

void ExibeStatus(string PalavraComMascara, int TamanhoDaPalavra, int TentativasRestantes, string LetrasArriscadas, string Mensagem){

        cout << Mensagem;
        cout << "\nLetras da palavra: " << PalavraComMascara << " Tamanho: " << TamanhoDaPalavra << "\n";
        cout << "Tentativas restantes: " << TentativasRestantes;


        int cont;
        cout << "\nLetras arriscadas: ";
        for(cont = 0; cont < LetrasArriscadas.size();cont++){
            cout << LetrasArriscadas[cont] << ", ";
        }

}

int Jogar(int NumeroDeJogadores){

    ///confere o numero de jogadores

    string Palavra; ///palavra a ser advinhada

    if(NumeroDeJogadores==1){
        Palavra = RetornaPalavraAleatoria();
    }else{
        cout << "\nDigite uma palavra secreta! :)";
        cin >> Palavra;

    }



    int TamanhoDaPalavra = Palavra.size();

    string PalavraComMascara = RetornaPalavraComMascara(Palavra,TamanhoDaPalavra);

    ///VARIAVEIS GERAIS
    int Tentativas = 0;
    int MaximoDeTentativas = 10;
    int cont = 0;                              ///auxiliar para laços de repetição
    int Opcao;                                   /// Para reiniciar o jogo
    char Letra;
    string LetrasArriscadas;
    string Mensagem = "Bem vindo ao jogo! :D";
    bool JaDigitou = false;                 /// para saber se a letra ja foi digitada
    bool AcertouLetra;



    ///LAÇO DE REPETIÇÃO
    while(Palavra != PalavraComMascara && MaximoDeTentativas - Tentativas > 0){

        LimpaTela();

        ExibeStatus(PalavraComMascara,TamanhoDaPalavra,MaximoDeTentativas-Tentativas, LetrasArriscadas, Mensagem);

        cout << "\n>>Digite uma letra:\n";
        cin >> Letra;



        for(cont = 0; cont < Tentativas; cont++){ ///Percorre as letras ja arriscadas
            if(LetrasArriscadas[cont]==Letra){
                Mensagem = ">>Essa letra ja foi digitada!!! ";
                JaDigitou = true;

            }

        }
        if(!JaDigitou){ ///se for uma letra nova

            Mensagem = "Voce arriscou uma letra nova! :o";

            LetrasArriscadas += tolower(Letra);

            for(cont = 0; cont < TamanhoDaPalavra; cont++){

                if(Palavra[cont]== tolower(Letra)){ ///percorre a palavra real
                    PalavraComMascara[cont] = Palavra[cont]; ///caso acerte a letra
                    Mensagem = ">> Voce acertou uma letra!!! :D";
                    AcertouLetra = true;
                }
            }

            if(!AcertouLetra){
                Mensagem = ">>Voce errou uma letra! :/";
            }
            Tentativas++;
        }
        /// REINICIAR VARIAVEIS AUXILIARES
        JaDigitou = false;
        AcertouLetra = false;

    }

    if(Palavra == PalavraComMascara){
        cout << "\n--------------------------------------------------------------------\n";
        cout << "Parabens, voce acertou a palavra secreta! Vai encarar a proxima? ;D\n";
        cout << "\nDeseja reiniciar?";
        cout << "\n1- Sim, desejo jogar novamente!";
        cout << "\n2- Nao, vou deixar para a proxima!";
        cin >> Opcao;
        return Opcao;

    }else{
        cout << "\n--------------------------------------------------------------------\n";
       cout << "Ahh...Voce perdeu!:(, vamos tentar de novo? :)\n";
       cout << "Deseja reiniciar?";
       cout << "\n1- Sim, desejo jogar novamente!";
       cout << "\n2- Nao, vou deixar para a proxima!";
       cin >> Opcao;
       return Opcao;
    }


}

void MenuInicial(){

    int Opcao = 0;

    while(Opcao < 1 || Opcao > 3){

        LimpaTela();

        cout << "-----------------------------------------------------------";
        cout << "\n>>>>>>>>>>>>>BEM-VINDO AO JOGO DA FORCA!<<<<<<<<<<<<<<<<<<\n";
        cout << "-----------------------------------------------------------";
        cout << "\n\n1---> Jogar sozinho!";
        cout << "\n2---> Jogar em dupla!";
        cout << "\n3---> Sobre o jogo:";
        cout << "\n4---> Sair do jogo.";
        cout << "\n\nESCOLHA UMA OPCAO E CONFIRME COM ENTER:";
        cin >> Opcao;



        switch(Opcao){

            case 1:
                if(Jogar(1)==1){
                    MenuInicial();
                }

                break;

            case 2:
                if(Jogar(2)==1){
                    MenuInicial();
                }


                break;

            case 3:
                cout << "Informacoes sobre o jogo.";
                cout << "\nJogo desenvolvido em projeto da Udemy por Maria Karolina, em 2022.\nClassico jogo de palavra secretas, ou, como preferir A FORCA!!!\nPara jogar e muito facil! Vamos la? \nBasta tentar advinhar a palavra secreta, seguindo as dicas, antes que acabem as tentativas!\nVamos tentar evitar a forca agora? :D\n";
                cout << "\n1 - Voltar.";
                cout << "\n2 - Sair.";
                cin >> Opcao;
                if(Opcao==1){
                    MenuInicial();
                }

            case 4:
                cout << "\nAte mais!!!\n";

                break;





        }
    }

}

int main(){

    srand((unsigned)time(NULL));


    MenuInicial();

}

