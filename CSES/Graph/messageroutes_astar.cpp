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
#define disptablnsp(v) rep(i,v.size()){ aff v[i] ;}aff endlf
#define srt(v) sort(v.begin(), v.end())
#define srtd(v) sort(v.rbegin(), v.rend())

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


const ll mod = 1e9+7;
const ll maxb = 1e18;

vector<vector<ll>> g(100005);

vector<bool> vis(100005, false);

struct AStarNode {
    int node;
    long long cost;
    AStarNode* parent;

    AStarNode(int n, long long c, AStarNode* p) : node(n), cost(c), parent(p) {}
};

void dfs(int p, int& numson, int& indson) {

    vis[p] = true;

    if (g[p].size() < numson) {
        numson = p;
        indson = p;
    }

    rep(i, g[p].size()) {
        if (!vis[g[p][i]]) {
            dfs(g[p][i], numson, indson);
        }
    }

}


struct Compare
{
    bool operator()(const pair<ll, int>& a, const pair<ll, int>& b)
    {
        return a.first > b.first;
    }
};

vector<int> findMinPath(int n) {

    priority_queue<pair<ll,int>, vector<pair<ll, int>>, Compare> pq;
    vector<AStarNode> nodes(n + 1, AStarNode(-1, 2000000000, nullptr));
    pair<ll, int> p;

    nodes[1] = AStarNode(1, 0, nullptr);

    vector<int> startv;
    pq.push({ 0, 1 });
        

    while (!pq.empty()) {

        p = pq.top();
        pq.pop();
                

        int costcurrent = p.first;
        int current = p.second;
        

        if (!vis[current]) {

            vis[current] = true;
         

            if (current == n) {
                vector<int> path;
                AStarNode* currentNode = &nodes[n];
                while (currentNode != nullptr) {
                    path.push_back(currentNode->node);
                    currentNode = currentNode->parent;
                }
                reverse(path.begin(), path.end());
                return path;
            }

            if (costcurrent > nodes[current].cost) {
                continue;
            }


            rep(i, g[current].size()) {
                if (costcurrent + 1 < nodes[g[current][i]].cost) {
                    nodes[g[current][i]] = AStarNode(g[current][i], costcurrent+1, &nodes[current]);
                    pq.push({ costcurrent + 1, g[current][i] });

                }
            }

        }


    }

    return {};

}

void solve() {
    
    int n, m;
    input n >> m ;

    rep(i, m) {
        int a, b;
        input a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    
    vector<int> path = findMinPath(n);

    if (path.size() > 0) {
        aff path.size() endf;
       
        rep(i, path.size()) {
            aff path[i] espaffe;
        }
    }
    else {
        aff "IMPOSSIBLE" endf
    }

   
        
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
