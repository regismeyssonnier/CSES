// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long int ll;

//vector<vector<ll>>dp(1000 + 1, vector<ll>(100000 + 1, 0));
vector<ll>dp2(100000 + 1, 0);
int main()
{
    ll n, x;

    cin >> n >> x;
       
    vector<pair<ll,ll>>price(n);
    
    
    for (int i = 0; i < n; ++i)cin >> price[i].first;

    ll sumpg = 0;
    for (int i = 0; i < n; ++i) {
        cin >> price[i].second;
        sumpg += price[i].second;
    }

    //vector<ll>  dp2(sumpg+5, 0);
    
    //vector<ll> dp(sumpg + 5, 0);// , p(sumpg + 5);
    //sort(price.begin(), price.end());
    //for (int i = 1; i <= n; ++i)dp[i][0] = price[i - 1].second;

    //for (int i = 1; i <= x; ++i)dp[0][i] = i;

   /* for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= x; ++j) {
                            
            if (j - price[i-1].first >= 0 ) {
                dp[i][j] =  max(dp[i-1][j], dp[i-1][j-price[i-1].first]+ price[i - 1].second);
                
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][x] << endl;*/

    for (ll i = 1; i <= n; ++i) {
        for (ll j = x; j >= 1; --j) {
            if (j - price[i - 1].first >= 0) {
                dp2[j] = max(dp2[j], dp2[j - price[i - 1].first] + price[i - 1].second);
            }
        }
    }
    
    cout << dp2[x] << endl;

    /*for (int i = 0; i <= x; ++i) {

        cout << dp2[i] << " ";

    }cout << endl;*/

    /*dp2[0] = 0;
    for (int j = 0; j < n; ++j) {
        for (int i = 1; i <= x; ++i) {

            if (i - price[j].first >= 0) {
                dp2[i] = dp2[i - price[j].first] + price[j].first;
                
            }
        }
    }
    */
    
    /*4 10
4 8 6 3
5 12 8 1

10 10
1 2 10 6 5 1 7 4 10 4
6 3 8  1 7 3 8 6 5  6*/
    
    //cout << p[x] << endl;

    /*for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            cout << dp[i][j] << " ";
        }cout << endl;
       
    }cout << endl;*/
    /*
    for (int i = 0; i <= sumpg; ++i) {

        cout << dp2[i] << " ";

    }cout << endl;*/

    /*for (int j = 0; j < p.size(); ++j) {
        cout << p[j] << " ";
    }cout << endl;*/
    /*for (int j = 0; j < p.size(); ++j) {
        cout << p2[j] << " ";
    }cout << endl;
    
    for (int i = 0; i <= sumpg; ++i) {
        cout << i << ": ";
        for (int j = 0; j < p[i].size(); ++j) {
            cout << p[i][j] << " ";
        }cout << endl;
    }cout << endl;*/
   
    
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
