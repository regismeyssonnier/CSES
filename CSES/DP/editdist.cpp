// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>
using namespace std;
typedef long long int ll;

//vector<ll>dp(1000000+5, 0);
vector<vector<ll>>dp(5000 + 5, vector<ll>(5000 +5, 0));

void solve() {

    string s1, s2;

    cin >> s1 >> s2;

    for (int i = 0; i <= s1.length(); ++i)dp[i][0] = i;
    for (int i = 0; i <= s2.length(); ++i)dp[0][i] = i;

    
    for (int a = 1; a <= s1.length(); ++a) {
        for (int b = 1; b <= s2.length(); ++b) {
            dp[a][b] = min(dp[a - 1][b] + 1,
                       min(dp[a][b - 1] + 1,
                       dp[a - 1][b - 1] + ((s1[a - 1] == s2[b - 1]) ? 0 : 1)));
        }
    }

    cout << dp[(int)s1.length()][(int)s2.length()] << endl;


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
