#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calculo (int moedas[100000], int pos, int desconto, int limite) 
{
    if ((desconto-moedas[pos] > 0) && pos < limite) 
    {
        cout << "d:" << desconto-moedas[pos] << endl;
        calculo(moedas, pos++, desconto-moedas[pos], limite);
    }
    else if ((desconto-moedas[pos] < 0) && pos < limite)
    {
        cout << "d n a:" << desconto << endl;
        calculo(moedas, pos++, desconto, limite);
    }
    else if ((desconto-moedas[pos] == 0))
    {
        cout << "d:" << desconto-moedas[pos] << " " << pos << endl;
        cout << "S" << endl;
    }
    else
    {
        cout << "d p:" << desconto-moedas[pos] << " " << pos << endl;
        cout << "N" << endl;
    }
}

int main() {
    int i = 0, V = 0, M = 0;
    bool situacao = false;
    cin >> V >> M;
    int moedas[100000];
    for (i = 0; i < M; i++) {
        cin >> moedas[i];
        if (moedas[i] > V) {
            i--;
            M--;
        }
        else if (moedas[i] == V) 
        {
            situacao = true;
        }
    }
    if (situacao == true) 
    {
        cout << "S" << endl;
        return 0;
    }
    if (i < 0)
    {
        cout << "N" << endl;
        return 0;
    }
    calculo(moedas, 0, V, M);

}

/*
bool soma(int sum, int pos, vector<int> moedas) {
    if (sum > 0 && pos > 0) {
        soma(sum - moedas[pos], pos-1, moedas)
    }
    else if (pos < 0) {
        
    }
    else {
        return true;
    }
}
vector<int> moedasv (moedas, moedas+M);
    sort(moedasv.begin(), moedasv.end());
    int posicao = 0;
    for (int i = 0; i < M; i++)
    {
        if (moedasv[i] <= V)
        {
            if (moedasv == V)
            {
                cout << "S" << endl;
                return 0;
            }
            else
            {
                posicao = i;
            }
            
        }
    }
    if(posicao > 0) {

    }
    */
