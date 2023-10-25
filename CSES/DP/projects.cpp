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

vector<ll>dp;// (2e5 + 5, 0);
//vector<vector<ll>>dp(500 + 1, vector<ll>(62625 +1, 0));
const ll mod = 1e9+7;
void solve() {

    ll n;

    cin >> n;

    vector<ll>a(n), b(n), p(n);
    map <int, int>anus;
    for (int i = 0; i < n; ++i) {
     
        cin >> a[i] >> b[i] >> p[i];
     
        b[i]++;

        anus[a[i]];
        anus[b[i]];
        
    }

    int coords=0;
    for (auto &a : anus) {
        a.second = coords;
        ++coords;
    }

    vector<vector<pair<int, int>>> projects(coords);
    for (int i = 0; i < n; ++i) {
        projects[anus[b[i]]].emplace_back( anus[a[i]], p[i] );
    }

    vector<ll> dp(coords, 0);
    for (int i = 0; i < coords; ++i) {

        if (i > 0) {
            dp[i] = dp[i - 1];
        }

        for (auto p : projects[i]) {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }

    }

    cout << dp[coords - 1] << endl;

   
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
