// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>
using namespace std;
typedef long long int ll;

vector<ll>dp(1000000+5, 0);
//vector<vector<ll>>dp(100000 + 5, vector<ll>(100+5, 0));

void solve() {

    ll n;

    cin >> n;

    dp[1] = 2;
    ll h, f;
    h = f = 1;

    for (int i = 2; i <= n; ++i) {
        

        ll nf = (2 * f + h) % 1000000007;
        ll nh = (f + 4 * h) % 1000000007;
        //cout << nf << " " << nh << endl;
        dp[i] = (nf + nh) % 1000000007;

        h = nh;
        f = nf;
    }

   
    cout << dp[n] << endl;

}

int main()
{
    ll t;

    cin >> t;
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
