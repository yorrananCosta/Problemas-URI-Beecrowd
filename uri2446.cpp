#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool calculo(int moedas[100000], int pos, int desconto) 
{
    if(((desconto - moedas[pos]) > 0) && pos >= 1)
    {
        calculo(moedas, pos-1, desconto-moedas[pos]);
    }
    else if (((desconto - moedas[pos]) < 0) && pos >= 1) 
    {
        calculo(moedas, pos-1,desconto);
    }
    else if ((desconto - moedas[pos]) == 0) 
    {
        return true;
    }
    return false;
}

int main() {
    int i = 0, V = 0, M = 0;
    cin >> V >> M;
    int moedas[100000];
    for (i = 0; i < M; i++) {
        cin >> moedas[i];
        if (moedas[i] > V) {
            i--;
            M--;
        }
    }
    if(i == 0) {
            cout << "N" << endl;
            return 0;
    }
    if(calculo(moedas, M-1, V) == true)
    {
        cout << "S" << endl;
    }
    else {
        cout << "N" << endl;
    }

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