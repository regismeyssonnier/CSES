// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>
#include <set>
using namespace std;
typedef long long int ll;

vector<bool>dp(500+5, 0);
vector<vector<ll>>dp2(500 + 5, vector<ll>(500 +5, 200000));

void solve() {

    ll n;

    cin >> n;

    ll sum = 0;
    vector<ll>a(n);
    set<ll> first;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
       
    }
    sort(a.begin(), a.end());
    dp.resize(sum + 5, false);
    vector<ll>f;
    
   

    dp[0] = 1;
    
    for (int j = 0; j < n; ++j) {
      
        for (int i = sum; i >= 0; --i) {
            
            if ( dp[i])dp[i + a[j]] = true;
                       
        }
       
    }

    for (int i = 1; i <= sum; ++i)
        if (dp[i])
            first.insert(i);

    cout << first.size() << endl;
   

    for (auto s:first) {
        cout << s << " ";
    }
    

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
