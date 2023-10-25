// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>
#include <set>
#include <map>
using namespace std;
typedef long long int ll;


#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

///vector<ll> dp(500 + 5, 0);
vector<vector<ll>>dp(1000 + 1, vector<ll>(1<<11, -1));
const ll mod = 1e9+7;

void generate_next_mask(vector<ll> &vmask, ll mask, ll new_mask, int l, int n) {

    if (l == n + 1) {
        vmask.push_back(new_mask);
        return;
    }

    if (((1LL << l) & mask) != 0) {
        generate_next_mask(vmask, mask, new_mask, l + 1, n);
    }

    if (l != n) {
        if ((((1LL << l) & mask) == 0) && (((1LL << (l+1)) & mask) == 0)) {
            generate_next_mask(vmask, mask, new_mask, l + 2, n);
        }
    }


    if (((1LL << l) & mask) == 0) {
        generate_next_mask(vmask, mask, new_mask | (1LL << l), l + 1, n);
    }
}

int solvedp(int c, ll mask, int n, int m) {

    if (c == m + 1) {
        if (mask == 0) {
            return 1;
        }
        return 0;
    }

    if (dp[c][mask] != -1)
        return dp[c][mask];

    int ans = 0;

    vector<ll>masks;
    generate_next_mask(masks, mask, 0, 1, n);

    for (int next_mask : masks) {
        ans = (ans + solvedp(c + 1, next_mask, n, m)) % mod;
    }

    return dp[c][mask] = ans;
}


void solve() {

    ll n, m;

    cin >> n >> m;

    cout << solvedp(1, 0, n, m) << endl;

}

void init_code() {
    fast_io;
#ifndef ONLINE_JUDGE
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
#endif 
}

int main()
{
    init_code();

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
