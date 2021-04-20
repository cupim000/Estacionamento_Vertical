#ifndef EVERT_H_INCLUDED
#define EVERT_H_INCLUDED

class Carro
{
protected:
    char marca[20];
    char cor[20];
public:
    char placa[20];
    time_t hora;
    Carro(); //construtor com as informações não especificadas
    void setCarInfo(char[20],char[20],char[20],time_t); //atribui as inormações a um carro
    void imprimeCarInfo(); //imprime as informações (atributos) de um carro
};

class No
{
private:
    Carro car;
    No *lig;
public:
    No()
    {
        lig=NULL; //incia apontando para NULL
    };
    void setCarro(Carro); //atribui um carro ao No
    Carro getCarro(); //retorna o carro atribuido
    void setLig(No*); //lig aponta para um outro No
    No* getLig(); //retorna o No sendo apontado por lig
};

class Lista:public No,public Carro
{
private:
    No* first; //primeiro elemento da lista do tipo No
public:
    Lista()
    {
        first=NULL; //começa apontando para NULL;
    };
    bool retira(char[20],time_t&); //retira um No a partir da placa do carro atribuido a ele
    void imprime(); //Imprime as placas dos carros na lista ordenada
    bool listavazia(); //retorna true se a lista estiver vazia
    void insere(Carro); //insere um No com carro como parametro
    bool listacheia(); //retorna true se a lista estiver cheia (5 Nos)
    No* getFirst(); //retorna o primeiro no da lista
};

class Estacionamento:public Carro
{
private:
    int quant=0; //quantidade de carros no estacionamento
public:
    Lista andar[3]; //os andares são um vetor de Lista
    char menu(); //imprime e retorna a opção de menu a escolha do usuario
    Carro recebeCarro(); //recebe as informações de um carro a ser inserido
    void upQuant(); //aumenta a quantidade atual de carros
    void downQuant(); //reduz a quantidade atual de carros
};


#endif // EVERT_H_INCLUDED
