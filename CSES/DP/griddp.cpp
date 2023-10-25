// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;

    cin >> n ;
       
    vector<vector<ll>> dp(n+5, vector<ll>(n+5, 0));
    vector<string> grid(n);

    for (int i = 0; i < n; ++i)cin >> grid[i];

    if(grid[0][0] != '*')
        dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j-1 >=0 && i-1>= 0&&grid[i][j] != '*'&& grid[i][j-1] != '*'&& grid[i-1][j] != '*') {
                dp[i][j] = (dp[i][j - 1] + dp[i-1][j])%1000000007;
            }
            else if (j - 1 >= 0 && grid[i][j] != '*' && grid[i][j - 1] != '*') {
                dp[i][j] = dp[i][j - 1];
            }
            else if  (i - 1 >= 0 && grid[i][j] != '*' && grid[i-1][j] != '*') {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dp[i][j];
        }cout << endl;
    }cout << endl;*/

    cout << dp[n-1][n-1] << endl;
    
    
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
