// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long int ll;

//vector<vector<ll>>dp(1000 + 1, vector<ll>(100000 + 1, 0));
vector<vector<ll>>dp(100000 + 5, vector<ll>(100+5, 0));
int main()
{
    ll n, m;

    cin >> n >> m;
       
    vector<ll>a(n);
    for (int i = 0; i < n; ++i)cin >> a[i];

    if (a[0] == 0) {
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = 1;
        }
    }
    else {
        dp[0][a[0]] = 1;
    }
    
    for (int i = 1; i < n; ++i) {
        if (a[i] != 0) {
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1])% 1000000007;
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i]]) % 1000000007;
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1]) % 1000000007;

        }
        else {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000007;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 1000000007;
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % 1000000007;
            }
        }
    }

    int res = 0;
    for (int j = 1; j <= m; ++j) {
        res = (res + dp[n - 1][j])%1000000007;
    }
        

    cout << res << endl;
    
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
