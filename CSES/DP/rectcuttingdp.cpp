// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>
using namespace std;
typedef long long int ll;

vector<ll>dp(500+5, 0);
vector<vector<ll>>dp2(500 + 5, vector<ll>(500 +5, 200000));

void solve() {

    ll a, b;

    cin >> a >> b;

    if (a == b) {
        cout << 0 << endl;
        return;
    }

    /*if (b > a) {
        ll tmp = a;
        a = b;
        b = tmp;
    }*/

    //for (int i = 0; i <= a; ++i)dp2[i][0] = i;
    //for (int i = 0; i <= b; ++i)dp2[0][i] = i;

    int nb = 0;
    dp2[0][0] = 0;
    for (int i = 1; i <= 504; ++i) dp2[i][i] = 0;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {

            for (int ci = 1; ci < i; ++ci) {
                dp2[i][j] = min(dp2[i][j], dp2[i - ci][j] + dp2[ci][j] + 1);
            }
            for (int cj = 1; cj < j; ++cj) {
                dp2[i][j] = min(dp2[i][j], dp2[i ][j- cj] + dp2[i][cj] + 1);
            }
        }
    }

    cout << dp2[a][b] << endl;
    

    /*/int ii = 504;
    for (; ii >= 0; --ii) {
        if (dp[ii] != 0) {
            break;
        }
    }*/

    //cout << dp[ii] << endl;

    /*for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            cout << dp2[i][j] << " ";
        }cout << endl;
    }*/
    

}

int main()
{
    ll t=1;

    //cin >> t;
    while (t > 0) {
        solve();
        --t;
   }
    
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
