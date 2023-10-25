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
#include <stack>
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
    vector<ll>dist;

    AStarNode(pair<ll, ll> n, long long c, AStarNode* p) : node(n), cost(c), parent(p) { dist.resize(10, numeric_limits<ll>::max()  ); }
};


const ll mod = 1e9+7;
const ll maxb = 1e18;

//vector<vector<pair<ll,ll>>> g(100005);
vector<vector<ll>> g(100005);
//vector<vector<pair<ll, ll>>> g2(100005);
//vector<vector<bool>> vis(1000, vector<bool>(1000,false));
vector<bool> vis(100005, false);
deque<int>path;
vector<map<int, int>> dp;
vector<map<int, deque<int>>> dp2;
vector<int>cyclePath;
stack<int>currentPath;
vector<bool> rsFlag(100005, false);
vector<pair<ll, ll>> monsters;
vector<string> grid;
pair<ll, ll> A;
vector<pair<ll, ll>>output;
map<pair<ll, ll>, int> outmap;
vector<vector<AStarNode>> nodess(1000, vector<AStarNode>(1000, AStarNode({ -1,-1 }, 2000000000, nullptr)));
vector<AStarNode> nodessh(100005, AStarNode({ -1,-1 }, numeric_limits<ll>::max()/2, nullptr));

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



string FindShPath(int start, int n, vector<AStarNode> &nodessh, vector<vector<pair<ll, ll>>> &g, int k) {
    vector<bool> vissh(100005, false);
    //queue<pair<ll, ll>> q;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> q;

    nodessh[start] = AStarNode({ start, start }, 0, nullptr);
    nodessh[start].dir = 'A';
    //nodessh[start].dist.resize(3, numeric_limits<ll>::max());
    //rep(i, k)
        nodessh[start].dist[0] = 0;
    q.push({ 0, start });


    while (!q.empty()) {

        pair<ll, ll> current = q.top();

        q.pop();
        ll newcost = current.first;
        ll city = current.second;
        if (nodessh[current.second].dist[k - 1] < newcost)continue;

            rep(i, g[current.second].size()) {
               int cost = g[city][i].first;
               
                    
                    if (cost + newcost < nodessh[g[city][i].second].dist[k-1]) {
                        nodessh[g[city][i].second].dist[k - 1] = cost + newcost;
                        q.push({ nodessh[g[city][i].second].dist[k - 1], g[city][i].second });
                        srt(nodessh[g[city][i].second].dist);
                       
                    }

                    
                    
              
            }

     

    }


    string ans;
    for(int i = 0;i < nodessh[n].dist.size() && i <k;++i) {
        ans += to_string(nodessh[n].dist[i]) + " ";
    }
    
    return ans;
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

map<pair<ll, ll>, bool> medges;
bool hasCycle(int node, int parent) {

    vis[node] = 1;
    currentPath.push(node);
    rsFlag[node] = true;
    //aff "node " espaff node endf
    for (int neighbor : g[node]) {
        //aff "neighbor " espaff neighbor endf
        if (vis[neighbor] == 0) {

            if (hasCycle(neighbor, node)) {
                return true;
            }
            
        }
        else if (rsFlag[neighbor]) {
            // Un cycle a été trouvé, sauvegarder le chemin du cycle
                            
            cyclePath.clear();
            while (!currentPath.empty()) {
                cyclePath.push_back(currentPath.top());
                currentPath.pop();
                if (cyclePath.back() == neighbor) {
                    break;
                }
            }

            reverse(cyclePath.begin(), cyclePath.end());
          
                
            return true;

            
        }
       
    }

    currentPath.pop();
    rsFlag[node] = false;
    return false;


}



void solve() {

    int n, m, k;
    input n >> m;



    int point = 0;
    bool det_cycle = false;

    rep(i, m) {
        ll a, b, c;

        input a >> b;
        //aff c endf
        g[a].push_back(b);
        medges[{a, b}] = true;

        if (medges.count({ b, a }) > 0 && !det_cycle) {
            det_cycle = true;
            cyclePath.push_back(a);
            cyclePath.push_back(b);

        }

        //g2[b].push_back({ c, a });
        //edges.push_back({ a-1, b-1, c });
            /*if (med.count({a, b}) > 0)
                med[{a, b}] = max(med[{a, b}], c);
            else
                med[{a, b}] = c;*/
    }
    bool res = false;
    if (!det_cycle) {
        
        repae(i, 1, n) {

            if (!vis[i]) {
                cyclePath = {};
                res = hasCycle(i, -1);
                if (res ) {
                    
                    break;
                }
              
            }
        }
    }

    if (res  ||det_cycle) {
        aff cyclePath.size() + 1 endf;

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
