#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void posicionaBuffer(string &buffer, string input, int &index)
{
    buffer = input.substr(index, 4);
}

// < deslocamentos<- , tamanho , prox caracter>

void ajustaTamanhoDicionarioCasoNecessario(string &dicionario)
{
    // 123456789
    if (dicionario.size() > 6)
    {
        string aux = dicionario;
        int descarte = dicionario.size() - 6;
        dicionario = dicionario.substr(descarte, 6);
    }
}
void funcao(string &buffer, string &dicionario, int &index)
{
    string auxBuffer = buffer;
    string auxDicionario = dicionario;

    int cont = 0;
    for (int i = 0; i < dicionario.size(); i++)
    {
        //verifica se buffer todo ta no dicionario
        if (auxDicionario.find(auxBuffer) != -1) //eh pq o buffer todo ta no dicionario
        {

            if(buffer.size()<4){
                //eh pq o input acabou.
                cout << "<" << (auxDicionario.size() - auxDicionario.find(auxBuffer)) << "," << auxBuffer.size() << "," <<"EOF"<< ">" << endl;
                break;
                
            }
            cout << "<" << (auxDicionario.size() - auxDicionario.find(auxBuffer)) << "," << auxBuffer.size() << "," << buffer[cont] << ">" << endl;
            dicionario = dicionario + auxBuffer + buffer[cont];
            ajustaTamanhoDicionarioCasoNecessario(dicionario);
            break; ////////// tamanhoDicionario  -   indice do dicionario onde começa a palavra
        }
        else
        {
            auxBuffer.pop_back();
            cont++;
        }
    }
    index = index + auxBuffer.size();
}

int main(int argc, char const *argv[])
{
    string path = argv[1];
    string input;
    ifstream arq;
    arq.open(path, ios::in);
    getline(arq, input);
    //input aqui ja vale bananabacana.
    string dicionario;
    string buffer;

    for (int i = 0; i < input.size(); i++)
    {
        posicionaBuffer(buffer, input, i);
        //verificar se acha o buffer[0] no dicionario , se sim chama a funcao , se nao anda com o buffer e dicionario
        if (dicionario.find(buffer[0]) != -1)
        {
            funcao(buffer, dicionario, i);
        }
        else
        {
            char aux = buffer[0];
            dicionario = dicionario + aux;
            cout << "<0,0," << aux << ">" << endl;
            ajustaTamanhoDicionarioCasoNecessario(dicionario);
        }
    }

    //arq.close();
    return 0;
}