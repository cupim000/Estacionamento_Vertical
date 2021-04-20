#include <iostream>
#include <cmath>
#include <clocale>
#include <cstring>
#include <cstdio>
#include <ctime>
#include "ctype.h"
#include "EVert.h"
using namespace std;

void No::setCarro(Carro x) // atribui um carro ao nó
{
    car=x;
}

Carro No::getCarro() //retorna o carro atribuido
{
    return car;
}

void No::setLig(No* N) // lig aponta para outro nó
{
    lig=N;
}

No* No::getLig() // retorna o nó que está senda apontado por lig
{
    return lig;
}

bool Lista::listavazia() // retorna true se a lista estiver vazia
{
    if(first==NULL)
    {
        return true;
    }
    return false;
}

void Lista::insere(Carro x)// insere um nó com carro como parâmetro
{
    if(listavazia())
    {
        first= new No;
        first->setCarro(x);
        first->setLig(NULL);
    }
    else
    {
        No* aux=first;
        No* ant=NULL;
        while((aux!=NULL)&&(strcmp(aux->getCarro().placa,x.placa)<0))
        {
            ant=aux;
            aux=aux->getLig();
        }
        aux= new No;
        aux->setCarro(x);
        if(ant==NULL)
        {
            aux->setLig(first);
            first=aux;
        }
        else
        {
            aux->setLig(ant->getLig());
            ant->setLig(aux);
        }
    }
}

bool Lista::retira(char x[20],time_t &te) // retira um nó a partir da placa do carro atribuído a ele
{
    char ex[20];
    for(int i=0; i<strlen(x); i++)
    {
        ex[i]=(char)toupper(x[i]);
    }
    ex[strlen(x)]='\0';
    No* ant = NULL;
    No* aux = first;
    while((aux!=NULL) && (strcmp(aux->getCarro().placa,ex)!=0))
    {
        ant = aux;
        aux = aux->getLig();
    }
    if(aux==NULL)
    {
        return false;
    }
    if(aux==first)
    {
        te=aux->getCarro().hora;
        first = first->getLig();
    }
    else
    {
        te=aux->getCarro().hora;
        ant->setLig(aux->getLig());
    }
    delete aux;
    return true;
}

void Lista::imprime() // imprime as placas dos carros na lista ordenada
{
    if(listavazia())
    {
        cout <<" Andar vazio..." <<endl <<endl;
    }
    else
    {
        No *aux=first;
        do
        {
            cout <<aux->getCarro().placa <<" | ";
            aux=aux->getLig();
        }
        while(aux!=NULL);
        cout <<endl;
    }
}

bool Lista::listacheia()// retorna true se a lista estiver cheia (5 Nós)
{
    int i=0;
    No* aux=first;
    while(aux!=NULL)
    {
        i++;
        aux=aux->getLig();
    }
    if(i==5)
    {
        return true;
    }else
    {
        return false;
    }
}

No* Lista::getFirst()// retorna o primeiro nó da lista
{
    return first;
}

Carro::Carro()// construtor default com as insformações não especificadas
{
    char m[17]="Não Específicada";
    char c[17]="Não Específicada";
    char p[17]="Não Específicada";
    strcpy(marca,m);
    strcpy(cor,c);
    strcpy(placa,p);
    hora=time(NULL);
}

void Carro::setCarInfo(char m[20],char c[20],char p[20],time_t t)// atribui as informações a um carro
{
    hora=t;
    char aux[20];
    strcpy(marca,m);
    strcpy(cor,c);
    for(int i=0; i<strlen(p); i++)
    {
        aux[i]=(char)toupper(p[i]);
    }
    aux[strlen(p)]='\0';
    strcpy(placa,aux);
}

void Carro::imprimeCarInfo()// imprime os atributos de um carro
{
    struct tm HE=*localtime(&hora);
    cout <<" Marca: " <<marca <<endl;
    cout <<" Cor: " <<cor <<endl;
    cout <<" Placa: " <<placa <<endl;
    cout <<" Horario de entrada: " <<HE.tm_hour <<":" <<HE.tm_min <<endl;
}

char Estacionamento::menu()// imprime o menu e retorna a opção escolhida pelo usuário
{
    char op;
    time_t t=time(NULL);
    struct tm localtm;
    localtm=*localtime(&t);

    cout << " Quantidade atual de carros: " << quant  <<"/15" << endl;
    cout <<" Data: " <<localtm.tm_mday <<"/" <<localtm.tm_mon+1 <<"/" <<localtm.tm_year+1900 <<endl;
    cout <<" Horario atual: " <<localtm.tm_hour <<":" <<localtm.tm_min <<endl;
    cout <<" Taxa: R$2,00 + R$0,05/Min" <<endl <<endl;

    cout << " Opções: " << endl;
    cout << " (1) - Entrar com um carro." << endl;
    cout << " (2) - Retirar um carro." << endl;
    cout << " (3) - Imprimir esquema do estacionamento." << endl;
    cout << " (4) - Imprimir informações dos carros de um andar." << endl;
    cout << " (5) - Fechar o programa." <<endl;

    cin >> op;
    cout <<endl;

    return op;
}

Carro Estacionamento::recebeCarro() // recebe as informações de um carro a ser inserido
{
    Carro x;
    time_t t=time(NULL);
    char m[20],c[20],p[20];
    cout <<" Entre com as informações do carro..." <<endl;
    cout <<" Marca: "; gets(m);
    cout <<" Cor: "; gets(c);
    cout <<" Placa: "; gets(p);
    cout <<endl;
    x.setCarInfo(m,c,p,t);
    upQuant();
    return x;
}

void Estacionamento::upQuant() // aumenta a quantidade de carros
{
    quant++;
}

void Estacionamento::downQuant()// diminui a quantidade de carros
{
    quant--;
}
