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

vector<bool> vis(100005, 0);
deque<int>path;
vector<map<int, int>> dp;
vector<map<int, deque<int>>> dp2;
vector<int>currentPath, cyclePath;

bool dfs(int p, int s) {

    //aff p espaff col endf
    vis[p] = true;

    path.push_back(p);
    //disptabl(path);

    if (dp[p].count(s) > 0) {
        path = dp2[p][s];
        return dp[p][s];
    }



    if (path.size() >= 3 && path.back() == path[0]) {
        dp[p][s] = 1;
        dp2[p][s] = path;
       return true;
    }

    rep(i, g[p].size()) {
        
        if (vis[g[p][i]] == 0 || (g[p][i] == s && path.size()>=3)) {
           if(dfs(g[p][i],s)) {
               dp2[p][s] = path;
               dp[p][s] = 1;
               return true;
           }
        }
        
    }

    if(path.size() > 0)
        path.pop_back();
    vis[p] = false;
    dp[p][s] = 0;

    return false;


}

bool hasCycle(int node, int parent) {

    vis[node] = 1;
    currentPath.push_back(node);

    for (int neighbor : g[node]) {

        if (vis[neighbor] == 0) {

            if (hasCycle(neighbor, node)) {
                return true;
            }
        }
        else if (neighbor != parent) {
            // Un cycle a été trouvé, sauvegarder le chemin du cycle
            int start = 0;
            while (currentPath[start] != neighbor) {
                start++;
            }

            for (int i = start; i < currentPath.size(); i++) {
                cyclePath.push_back(currentPath[i]);
            }
                       

            return true;
        }
    }

    currentPath.pop_back();
    return false;


}

bool test(int p, int col) {
        
    //aff p espaff col endf
    
    rep(i, g[p].size()) {
        if (vis[g[p][i]] == 0) {
            int colf = 0;
            if (col == 1)colf = 2;
            else if (col == 2)colf = 1;

            vis[g[p][i]] = colf;

        }
        else {
            if (col == vis[g[p][i]])return false;
        }
    }

    return true;

}

struct AStarNode {
    int node;
    long long cost;
    AStarNode* parent;

    AStarNode(int n, long long c, AStarNode* p) : node(n), cost(c), parent(p) {}
};

struct Compare
{
    bool operator()(const pair<ll, int>& a, const pair<ll, int>& b)
    {
        return a.first > b.first;
    }
};

vector<int> findMinPath(int start, int end, int n) {

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, Compare> pq;
    vector<AStarNode> nodes(n + 1, AStarNode(-1, 2000000000, nullptr));
    pair<ll, int> p;

    nodes[start] = AStarNode(start, 0, nullptr);

    pq.push({ 0, start });


    while (!pq.empty()) {

        p = pq.top();
        pq.pop();


        int costcurrent = p.first;
        int current = p.second;

        //aff current endf

        if (!vis[current]) {

            vis[current] = true;


            if (current == end) {
                vector<int> path;
                AStarNode* currentNode = &nodes[end];
                while (currentNode != nullptr) {
                    path.push_back(currentNode->node);
                    //aff "path " espaff currentNode->node endf
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
                    nodes[g[current][i]] = AStarNode(g[current][i], costcurrent + 1, &nodes[current]);
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
  
    int  ans = 0;
        

    //dp.clear();
    //dp.resize(n + 1);
    //d//p2 = {};
    //dp2.resize(n + 1);
    //for (int k = 0; k < n; ++k)dp[k][i] = -1;
    
    repae(i, 1, n) {
        //if (g[i].size() < 2)continue;
        //dp.clear();
        //dp.resize(n + 1);
        if (!vis[i]) {

            /*path = {};
            bool res = dfs(i, i);
            if (res) {
                break;
            }*/

            cyclePath = {};
            bool res = hasCycle(i, -1);
            if (res) {
                break;
            }
        }

        /*repj(j, g[i].size()) {

            for (int k = j + 1; k < g[i].size(); ++k) {
                if (g[i][j] != g[i][k] && g[g[i][j]].size() >= 2 && g[g[i][k]].size() >= 2) {
                    //aff g[i][j] espaff g[i][k] endf;
                    for (int c=1; c <= n; ++c)vis[c] = 0;
                    vis[i] = true;

                    path = findMinPath(g[i][j], g[i][k], n);
                    if (path.size() > 0) {
                        ans = i;
                        break;
                    }
                }
            }
        }*/

    }

    if (cyclePath.size() > 0) {
        aff cyclePath.size()+1 endf;
             
        rep(i, cyclePath.size()) {
            aff cyclePath[i] espaffe;
            
        }
        aff cyclePath[0] endf
     
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
