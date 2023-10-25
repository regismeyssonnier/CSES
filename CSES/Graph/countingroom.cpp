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

typedef long long int ll;


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

map<pair<ll,ll>, vector<pair<ll,ll>>> g;
map<pair<ll, ll>, int> vis;
vector<string>vr;

void dfs(pair<ll,ll> p) {

    vis[p] = 1;

    for (auto const& f : g[p]) {
        if (!vis[f]) {
            dfs(f);
        }
    }

}

void dfs2(pair<ll, ll> p, int n, int m) {

    vis[p] = 1;
    //aff p.first espaff p.second endf
    
    if (vis[{p.first,  p.second - 1 }] == 0) {
        
        if (p.second - 1 >= 0 && vr[p.second - 1][p.first] == '.') {
            dfs2({ p.first,  p.second - 1 }, n,m);

        }
    }
   
    if (vis[{ p.first, p.second + 1  }] == 0) {
        if (p.second + 1 < n && vr[p.second + 1][p.first] == '.') {
            dfs2({ p.first, p.second + 1 }, n, m);

        }
    }
    if (vis[{p.first - 1 ,p.second }] == 0) {
        if (p.first - 1 >= 0 && vr[p.second][p.first - 1] == '.') {
            dfs2({ p.first - 1 ,p.second }, n, m);

        }
    }
    if (vis[{ p.first + 1, p.second }] == 0) {
        if (p.first + 1 < m && vr[p.second ][p.first+1] == '.') {
            dfs2({ p.first + 1, p.second }, n, m);

        }
            
    }
    

}


void solve() {
    
    int n, m;
    input n >> m ;

    vr.clear();
    vr.resize(n);
    vector<pair<ll, ll>> floor;



    rep(i, n) {
        input vr[i];
        rep(j, vr[i].length()) {
            if (vr[i][j] == '.') {

                floor.push_back({ j, i });
            }
        }
               
    }
    /*
    rep(i, n) {
        rep(j, vr[i].length()) {
            if (vr[i][j] == '.') {
                
                floor.push_back({ j, i });
                if (i - 1 >= 0 && vr[i - 1][j] == '.') {
                    g[{j, i}].push_back({ j,i - 1 });

                }
                if (i + 1 < n && vr[i + 1][j] == '.') {
                    g[{j, i}].push_back({ j,i + 1 });

                }
                if (j - 1 >= 0 && vr[i][j - 1] == '.') {
                    g[{j, i}].push_back({ j - 1,i  });

                }
                if (j + 1 < m && vr[i][j+1] == '.') {
                    g[{j, i}].push_back({ j+1,i  });

                }

            }
        }

    }
    */

    int count = 0;
    for (auto& f : floor) {
        if (vis[f] == 0) {
            dfs2(f, n, m);
            //rep(i, n) { rep(j, m) { aff vis[{j, i}]; }aff endlf }
            //aff endlf;
            count++;
        }
    }

    aff count endf


        
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