#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "EVert.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Estacionamento E;
    char op;
    int a;
    do
    {
        fflush(stdin);
        op=E.menu();
        fflush(stdin);
        if (op=='1')  //Insere Carro no andar a
        {
            cout <<" Escolha o andar(0/1/2): ";
            cin >>a;
            cout <<endl;
            while(a!=0 && a!=1 && a!=2)
            {
                cout <<" Andar inexistente, entre novamente: ";
                cin >>a;
            }
            fflush(stdin);
            if(E.andar[a].listacheia())
            {
                cout <<" Não é possivel colocar um carro, andar atualmente cheio..." <<endl <<endl;
                system("pause");
                system("cls");
            }
            else
            {
                E.andar[a].insere(E.recebeCarro());
                system("cls");

            }
        }
        else if (op=='2') //Retira carro com a placa selecionada
        {
            time_t he;
            char ex[20];
            cout <<" Entre com a placa do carro a ser retirado: ";
            gets(ex);
            fflush(stdin);
            for(int i=0; i<3; i++)
            {
                if(E.andar[i].retira(ex,he))
                {
                    time_t t=time(NULL);
                    struct tm TA=*localtime(&t);
                    struct tm TD=*localtime(&he);
                    cout <<" Entrou: " <<TD.tm_hour <<":" <<TD.tm_min <<":" <<TD.tm_sec <<endl;
                    cout <<" Saiu: " <<TA.tm_hour <<":" <<TA.tm_min <<":" <<TA.tm_sec <<endl;
                    cout <<" Valor a pagar: R$" <<2.00+0.05*(difftime(t,he)/60) <<endl;
                    cout <<" Obrigado pela preferência, volte sempre :)!"<<endl;
                    E.downQuant();
                }
            }
            system("pause");
            system("cls");
            cout <<endl;
        }
        else if (op=='3') //imprime esquema do estacionamento
        {
            for(int i=2; i>=0; i--)
            {
                cout <<" Andar " <<i <<": ";
                E.andar[i].imprime();
                cout <<endl;
            }
                system("pause");
                system("cls");
        }
        else if (op=='4') //imprime informações de todos os carros de um andar a
        {
            cout <<" Escolha o andar(0/1/2): ";
            cin >>a;
            cout <<endl;
            while(a!=0 && a!=1 && a!=2)
            {
                cout <<" Andar inexistente, entre novamente: ";
                cin >>a;
            }
            fflush(stdin);
            if(E.andar[a].getFirst()==NULL)
            {
                cout <<" Andar atualmente vazio..." <<endl <<endl;
            }
            else
            {
                No* aux = E.andar[a].getFirst();
                int i=1;
                while(aux!=NULL)
                {
                    cout <<" Carro " <<i <<":" <<endl;
                    aux->getCarro().imprimeCarInfo();
                    aux=aux->getLig();
                    i++;
                    cout <<"\t";
                }
            }
                system("pause");
                system("cls");
        }
        else if (op=='5') //finaliza o programa
        {
            return 0;
        }
        else
        {
            cout <<" Opção invalida..." <<endl;
            system("pause");
            system("cls");
        }
    }
    while(1);
}
