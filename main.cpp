
#include <iostream>

using namespace std;

int convert(char *ptrMsgOriginal, char substituido, char substituto, char *ptrMsgNova){
    int qtdSubstituido = 0;
    
    if(*ptrMsgOriginal == '\0'){
        *ptrMsgNova = '\0';
        return 0;
    }else{
        if(*ptrMsgOriginal == substituido){
            *ptrMsgNova = substituto;
            qtdSubstituido++;
        }else{
            *ptrMsgNova = *ptrMsgOriginal;
        }
        ptrMsgOriginal++;
        ptrMsgNova++;
        qtdSubstituido+=convert(ptrMsgOriginal, substituido, substituto, ptrMsgNova);
        
    }
    return qtdSubstituido;
}

int main()
{
    char mensagemOriginal [200];
    char mensagemNova [200];
    char substituido;
    char substituto;
    
    cout << "Digite uma mensagem de até 200 caracteres: " << endl;
    cin.getline (mensagemOriginal, 200);
    cout << "Digite o caractere a ser substituido: " << endl;
    cin >> substituido;
    cout << "Digite o caractere substituto: " << endl;
    cin >> substituto;
    
    int qtdSubstituido = convert(mensagemOriginal, substituido, substituto, mensagemNova);
    cout << mensagemNova << endl;
    cout << mensagemOriginal << endl;
    cout << qtdSubstituido << endl;
    
}
