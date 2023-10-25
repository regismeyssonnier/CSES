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
#define disptablnsp(v) rep(i,v.size()){ aff v[i] ;}aff endlf
#define srt(v) sort(v.begin(), v.end())
#define srtd(v) sort(v.rbegin(), v.rend())

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

struct AStarNode {
    pair<ll, ll> node;
    ll cost;
    AStarNode* parent;
    char dir;

    AStarNode(pair<ll, ll> n, long long c, AStarNode* p) : node(n), cost(c), parent(p) {}
};


const ll mod = 1e9+7;
const ll maxb = 1e18;

vector<vector<pair<ll,ll>>> g(100005);
vector<vector<bool>> vis(1000, vector<bool>(1000,false));
vector<bool> vissh(100005, false);
deque<int>path;
vector<map<int, int>> dp;
vector<map<int, deque<int>>> dp2;
vector<int>currentPath, cyclePath;
vector<pair<ll, ll>> monsters;
vector<string> grid;
pair<ll, ll> A;
vector<pair<ll, ll>>output;
map<pair<ll, ll>, int> outmap;
vector<vector<AStarNode>> nodess(1000, vector<AStarNode>(1000, AStarNode({ -1,-1 }, 2000000000, nullptr)));
vector<AStarNode> nodessh(100005, AStarNode({ -1,-1 }, numeric_limits<ll>::max(), nullptr));




struct Compare
{
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b)
    {
        return a.first > b.first;
    }
};



string FindShPath(int start, int n) {

    //queue<pair<ll, ll>> q;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> q;

    nodessh[start] = AStarNode({ start, start }, 0, nullptr);
    nodessh[start].dir = 'A';
    q.push({ 0, start });


    while (!q.empty()) {

        pair<ll, ll> current = q.top();

        q.pop();

        if (!vissh[current.second]) {
                       
            vissh[current.second]= true;

            rep(i, g[current.second].size()) {

                int newcost = g[current.second][i].first;
                int city = current.second;

                if (nodessh[city].cost + newcost < nodessh[g[city][i].second].cost) {
                    q.push({ (nodessh[city].cost + newcost), g[city][i].second });
                    nodessh[g[city][i].second] = AStarNode(g[city][i], nodessh[city].cost + newcost, &nodessh[current.second]);

                }
            }

        }

    }

    string ans;
    repae(i,1, n) {
        ll d= nodessh[i].cost;
           
        if (d >= numeric_limits<ll>::max()) {
            ans += "0 ";
        }
        else {
            ans += to_string(d) + " ";
        }
    }

    return ans;

}

void solve() {
    
    int n, m;
    input n >> m ;

    int point = 0;
    rep(i, m) {
        int a, b, c;

        input a >> b >> c;

        g[a].push_back({ c, b });
        //g[b].push_back({ c, a });


    }


    aff FindShPath(1, n) endf


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
