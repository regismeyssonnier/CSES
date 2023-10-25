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

struct AStarNode {
    pair<ll, ll> node;
    ll cost;
    AStarNode* parent;
    char dir;
    ll maxi;
    ll maxparcours;

    AStarNode(pair<ll, ll> n, long long c, AStarNode* p) : node(n), cost(c), parent(p) {}
};


const ll mod = 1e9+7;
const ll maxb = 1e18;

vector<vector<pair<ll,ll>>> g(100005);
vector<vector<pair<ll, ll>>> g2(100005);
vector<vector<bool>> vis(1000, vector<bool>(1000,false));
//vector<bool> vissh(100005, false);
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
//vector<AStarNode> nodessh(100005, AStarNode({ -1,-1 }, numeric_limits<ll>::max()/2, nullptr));

const int MAXG = 505;
vector<vector<int>> adj(MAXG, vector<int>(MAXG, 2000000000));
ll distances[MAXG][MAXG];

vector<tuple<int, int, int>> edges;


struct Compare
{
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b)
    {
        return a.first > b.first;
    }
};



ll FindShPath(int start, int n, vector<AStarNode> &nodessh, vector<vector<pair<ll, ll>>> &g) {
    vector<bool> vissh(100005, false);
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

                ll newcost = g[current.second][i].first;
                ll city = current.second;
                
                if (current.first + newcost < nodessh[g[city][i].second].cost) {
                    q.push({ (current.first + newcost), g[city][i].second });
                    nodessh[g[city][i].second] = AStarNode(g[city][i], current.first + newcost, &nodessh[current.second]);

                }
               
            }

        }

    }

   

    return nodessh[n].cost;

}

void FloydWarshall(int n) {


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) distances[i][j] = 0;
            else if (adj[i][j] != 2000000000) distances[i][j] = adj[i][j];
            else distances[i][j] = numeric_limits<ll>::max()/2;
        }
    }

    /*rep(i, n) {
        repj(j, n) {
            aff distances[i][j] espaffe;
        }aff endlf;
    }aff endlf;*/

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);

            }
        }
    }

    /*rep(i, n) {
        repj(j, n) {
            aff distances[i][j] espaffe;
        }aff endlf;
    }aff endlf;*/

}

deque<int> BellmanFord(int s, int n) {

    vector<int> d(n);
    vector<int> p(n, -1);
    int x=-1;
    for (int i = 0; i < n; ++i) {
       
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            if (d[a] + w < d[b]) {
                d[b] = d[a] + w;
                p[b] = a;
                x = b;
            }
        }
    }

    if (x == -1) {
        return {};
    }
    else {
        for (int i = 0; i < n; ++i) {
            x = p[x];
            if (x == -1) {
                return{};
            }
        }
        deque<int> cycle;
        for (int v = x;; v = p[v]) {
            
            cycle.push_back(v+1);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        return cycle;
       
    }

    
    

}

/*
map<pair<ll, ll>, int>medges;
ll maximum = numeric_limits<ll>::max();
void dfs(ll ind, ll maxi, int n, ll maxparcours) {
    
    if (ind == n) {
        aff "-- "<<maxparcours espaff maxi espaff(ll)floor(maxparcours / 2) endf
        maximum = min(maximum, maxi-maxparcours+(ll)floor(maxparcours/2));
        return;
    }

    vissh[ind] = true;

    nodessh[ind].maxi = maxi;
    nodessh[ind].maxparcours = maxparcours;

    
    rep(i, g[ind].size()) {

        int mxp = max(maxparcours, g[ind][i].first);
        int cost =  maxi + g[ind][i].first - mxp + (ll)floor(mxp / 2);
        int cost2 = nodessh[ind].maxi - nodessh[ind].maxparcours + (ll)floor(nodessh[ind].maxparcours / 2);
        aff ind espaff g[ind][i].second espaff cost endf
        if (cost < cost2 || nodessh[g[ind][i].second].cost != 1) {
            nodessh[g[ind][i].second].cost = 1;
            dfs(g[ind][i].second, maxi + g[ind][i].first, n, max(maxparcours, g[ind][i].first));
            
        }

    }

}*/

map<pair<ll, ll>, ll> med;

void solve() {
    
    int n, m;
    input n >> m ;

    

    int point = 0;
    rep(i, m) {
        ll a, b, c;

        input a >> b >> c;
        //aff c endf
        //g[a].push_back({ c, b });
        //g2[b].push_back({ c, a });
        edges.push_back({ a-1, b-1, c });
            /*if (med.count({a, b}) > 0)
                med[{a, b}] = max(med[{a, b}], c);
            else
                med[{a, b}] = c;*/
    }

    if (n == 1) {
        int a, b, w;
        tie(a, b, w) = edges[0];
        if (w < 0) {
            aff "YES" endf
            aff a + 1 espaff b + 1 endf
            return;
        }
    }
 
    
    deque<int>ans = BellmanFord(0, n);

    if(ans.size() == 0)aff "NO" endf
    else {
        aff "YES" endf;
        for (int i = 0; i < ans.size(); ++i)aff ans[i] espaffe;
        aff endlf

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
