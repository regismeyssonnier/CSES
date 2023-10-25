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

//vector<ll>dp(5000+5, 0), dp2(5000 + 5, 0), dp3(5000 + 5, 0);
vector<vector<ll>>dp(5000 + 5, vector<ll>(5000 +5, 0));

void solve() {

    ll n;

    cin >> n;

 
    vector<ll>a(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
       
    }
   
    for (int i = 0; i < n; ++i)dp[i][i] = a[i];

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i < n-l+1 ;++i) {
            ll j = i + l - 1;
            ll j2 = (j - 2) >= 0? dp[i][j-2] : 0;
            dp[i][j] = max(a[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                a[j] + min(dp[i + 1][j - 1], j2));

            
        }
    }

    cout << dp[0][n - 1] << endl;

    /*for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
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
