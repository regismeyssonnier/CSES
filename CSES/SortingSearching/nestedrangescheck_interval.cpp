// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;

#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <list>

typedef unsigned long long int ll;


#define rep(i,n) for(int i = 0;i < n;++i)
#define repe(i,n) for(int i = 0;i <= n;++i)
#define repa(i,a,n) for(int i = a;i < n;++i)
#define repae(i,a,n) for(int i = a;i <= n;++i)
#define repj(j,n) for(int j = 0;j < n;++j)
#define repej(j,n) for(int j = 0;j <= n;++j)
#define repaj(j,a,n) for(int j = a;j < n;++j)
#define repaej(j,a,n) for(int j = a;j <= n;++j)
#define vll vector<ll>
#define itvll vector<ll>::iterator
#define vi vector<int>
#define pb push_back
#define pqll priority_queue<ll>
#define mpll map<ll, ll>
#define mmpll multimap<ll, ll>
#define sll set<ll>
#define msll multiset<ll>
#define aff cout <<
#define daff cerr <<
#define endf << '\n';
#define endlf '\n';
#define espaff << " " <<
#define espaffe << " " ;
#define input cin >>
#define disptabl(v) rep(i,v.size()){ aff v[i] espaffe}aff endlf
#define srt(v) sort(v.begin(), v.end())
#define srtd(v) sort(v.rbegin(), v.rend())

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

///vector<ll> dp(500 + 5, 0);
vector<vector<ll>>dp(18 + 5, vector<ll>(18+5, 0));
const ll mod = 1e9+7;
const ll maxb = 1e18;

struct Coord{
    int a;
    int b;
    int i;
};

void solve() {
    
    int n, x;
    input n ;

    vector<Coord> vp;
    vector<bool> contain(n);
    vector<bool> contained(n);
   
    rep(i, n) {
        int a, b;
        input a >> b;
      
        vp.push_back({ a, b, i });
          
    }

    sort(vp.begin(), vp.end(), [](Coord a, Coord b)-> bool {
        if (a.a == b.a)
            return a.b > b.b;
        else
            return a.a < b.a;

        });
        

    int maxi = 0;
    rep(i, n) {
        if (vp[i].b <= maxi) {
            contained[vp[i].i] = true;
        }
        maxi = max(maxi, vp[i].b);
    }
        
    int mini = 2e9;
    for(int i = n-1;i>=0;--i) {
        if (vp[i].b >= mini) {
            contain[vp[i].i] = true;
        }
        mini = min(mini, vp[i].b);

    }

    rep(i, n) {
        aff contain[i] espaffe;
    }
    aff endlf
    rep(i, n) {
        aff contained[i] espaffe;
    }
    aff endlf
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
