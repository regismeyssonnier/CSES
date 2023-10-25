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


//vector<vector<ll>>dp(20 + 1, vector<ll>(20 +1, 0));
const ll mod = 1e9+7;
void solve() {

    ll n, x;

    cin >> n >> x;

    vector<ll>a(n);
      
    

    for (int i = 0; i < n; ++i)cin >> a[i];
    vector<pair<ll, ll>>dp(1 << n);
        
    dp[0] = { 1,0 };

    for (ll mask = 1; mask < (1LL << n); ++mask) {
        pair<ll, ll> best = { 2000000000, 2000000000 };
        for (int i = 0; i < n; ++i) {
            if (((1LL << i) & mask) == 0)continue;
            
            auto res = dp[(1LL << i) ^ mask];
          
            if (res.second + a[i] <= x) {
                res.second += a[i];
            }
            else {
                res.first++;
                res.second = a[i];
                

            }

            best = min(best, res);

            
        }
        dp[mask] = best;
    }

    cout << dp[(1 << n) - 1].first << endl;

        
    
    
    /*for (int j = 0; j < (1 << n); ++j) {
        cout << dp[j].first << " " << dp[j].second << endl;
    }cout << endl;*/

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
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
