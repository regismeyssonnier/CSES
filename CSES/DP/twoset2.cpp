// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>
#include <set>
#include <map>
using namespace std;
typedef long long int ll;

//vector<ll>dp(150000+5, 0);
vector<vector<ll>>dp(500 + 1, vector<ll>(62625 +1, 0));
const ll mod = 1e9+7;
void solve() {

    ll n;

    cin >> n;

    ll sum = n * (n + 1) / 2;

    if (sum % 2 != 0) {
        cout << 0 << '\n';
        return;
    }


    dp[0][0] = 1;

    sum /= 2;

    for (ll i = 1; i < n; ++i) {
        for (ll j = 0 ; j <=sum; ++j) {
        
            dp[i][j] = dp[i - 1][j];

            if (j - i >= 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i])%mod;
              
            }
            
            
        }
         
    }

    cout << dp[n-1][sum] << endl;

 
   
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
