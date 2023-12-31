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
    ll count = 0;
    ll mini = 0;
    ll maxi = 0;

    AStarNode(pair<ll, ll> n, long long c, AStarNode* p) : node(n), cost(c), parent(p) { }
};


const ll mod = 1e9 + 7;
const ll maxb = 1e18;

//vector<vector<pair<ll,ll>>> g(100005);
vector<vector<ll>> g(200005), g2(200005);
//vector<vector<pair<ll, ll>>> g2(100005);
//vector<vector<bool>> vis(1000, vector<bool>(1000,false));
vector<int> vis(200005, false), vistn(100005, false);
//vector<map<int, int>> dp;
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
vector<AStarNode> nodessh(100005, AStarNode({ -1,-1 }, numeric_limits<ll>::max() / 2, nullptr));
vector<int>parent(100005, -1);
stack<int> topnode;
vector<int> dp(100005, 0);
vector<int>toporder;
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

vector<ll> FindMxPath(int start, int n, vector<AStarNode>& nodessh, vector<vector<pair<ll, ll>>>& g) {
    vector<bool> vissh(100005, false);
    //queue<pair<ll, ll>> q;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> q;

    nodessh[start] = AStarNode({ start, start }, 0, nullptr);
    nodessh[start].dir = 'A';
    nodessh[start].count = 1;

    q.push({ 0, start });


    while (!q.empty()) {

        pair<ll, ll> current = q.top();

        q.pop();

        if (nodessh[current.second].cost < current.first)continue;

        if (!vissh[current.second] || current.second == n) {

            vissh[current.second] = true;

            rep(i, g[current.second].size()) {

                ll newcost = g[current.second][i].first;
                ll city = current.second;



                if (current.first + newcost == nodessh[g[city][i].second].cost) {

                    nodessh[g[city][i].second].count += nodessh[city].count;
                    nodessh[g[city][i].second].count %= mod;
                    nodessh[g[city][i].second].maxi = max(nodessh[g[city][i].second].maxi, nodessh[city].maxi + 1);
                    nodessh[g[city][i].second].mini = min(nodessh[g[city][i].second].mini, nodessh[city].mini + 1);



                }

                if (current.first + newcost < nodessh[g[city][i].second].cost) {
                    q.push({ (current.first + newcost), g[city][i].second });
                    nodessh[g[city][i].second].node = g[city][i];
                    nodessh[g[city][i].second].cost = current.first + newcost;
                    nodessh[g[city][i].second].parent = &nodessh[current.second];


                    nodessh[g[city][i].second].count = nodessh[city].count;
                    nodessh[g[city][i].second].mini = nodessh[city].mini + 1;
                    nodessh[g[city][i].second].maxi = nodessh[city].maxi + 1;

                }




            }

        }

    }

    /*if (nodessh[n].cost != numeric_limits<ll>::max() / 2) {
        AStarNode* currentNode = &nodessh[n];
        int count = 0;
        while (currentNode != nullptr && currentNode->dir != 'A') {
            ++count;
            currentNode = currentNode->parent;
        }


    }*/

    return { nodessh[n].cost, nodessh[n].count, nodessh[n].mini, nodessh[n].maxi };


}


string FindShPath(int start, int n, vector<AStarNode>& nodessh, vector<vector<pair<ll, ll>>>& g, int k) {
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


            if (cost + newcost < nodessh[g[city][i].second].dist[k - 1]) {
                nodessh[g[city][i].second].dist[k - 1] = cost + newcost;
                q.push({ nodessh[g[city][i].second].dist[k - 1], g[city][i].second });
                srt(nodessh[g[city][i].second].dist);

            }




        }



    }


    string ans;
    for (int i = 0; i < nodessh[n].dist.size() && i < k; ++i) {
        ans += to_string(nodessh[n].dist[i]) + " ";
    }

    return ans;
}

void FloydWarshall(int n) {


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) distances[i][j] = 0;
            else if (adj[i][j] != 2000000000) distances[i][j] = adj[i][j];
            else distances[i][j] = numeric_limits<ll>::max() / 2;
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
    int x = -1;
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

            cycle.push_back(v + 1);
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

int P[200005][30];
//int vis[200005];
int len[200005];


void dfs(int s) {
    if (vis[s]) return;
    vis[s] = 1;
    dfs(P[s][0]);
    len[s] = len[P[s][0]] + 1;
}

int kth_ancestor(int v, int k) {
    if (k <= 0)return v;
    for (int i = 29; i >= 0; --i) {
        if (k >> i & 1) {
            v = P[v][i];
        }
    }

    return v;



}

bool findRoute(int node, int dest) {

    queue<int>q;

    q.push(node);
    bool stop = false;
    while (!q.empty() && !stop) {

        int p = q.front();
        q.pop();

        rep(i, g[p].size()) {
            if (g[p][i] == dest) {
                stop = true;
                break;
            }

            if (!vis[g[p][i]]) {
                vis[g[p][i]] = true;
                q.push(g[p][i]);
            }
        }


    }

    return stop;

}

vector<ll> p;
vector<ll> r;
vector<ll> mi;
vector<ll> ma;
vector<ll> sz;

ll nbcomp = 0;
ll maxi = -1;

ll get(ll a) {
    return p[a] = (p[a] == a ? a : get(p[a]));
}

map<pair<int, int>, int> medges;
void _union(ll a, ll b) {


    a = get(a);
    b = get(b);

    if (a == b)return;

    if (r[a] == r[b])
        r[a]++;
    if (r[a] > r[b]) {

        sz[a] += sz[b];
        maxi = max(maxi, sz[a]);

        nbcomp--;
        p[b] = a;
        mi[a] = min(mi[a], mi[b]);
        ma[a] = max(ma[a], ma[b]);
    }
    else {

        sz[b] += sz[a];
        maxi = max(maxi, sz[b]);

        nbcomp--;
        p[a] = b;

        mi[b] = min(mi[a], mi[b]);
        ma[b] = max(ma[a], ma[b]);

    }
}

int visited;

void findOrder(int node) {

    vis[node] = true;


    rep(i, g[node].size()) {
        if (!vis[g[node][i]]) {
            findOrder(g[node][i]);
        }
    }

    toporder.push_back(node);


}



int comp[200005];
int K = 0;
void findStronglyCompConn(int node) {

    vis[node] = true;
    comp[node] = K;
    rep(i, g2[node].size()) {
        if (!vis[g2[node][i]]) {
            findStronglyCompConn(g2[node][i]);
        }
    }

}

void checkAllRoutes(int node) {

    vis[node] = true;

    visited++;

    rep(i, g[node].size()) {
        if (!vis[g[node][i]])
            checkAllRoutes(g[node][i]);
    }


}

void maxPath(int node) {

}

vector<int>vindex;
vector<int>vlowlink;
vector<bool>vonstack;
//vector<pair<int, int>>edges;
vector<vector<int>>scc;
int index_comp = 0;
void strongconnect(int v, int &index, stack<int> &s){

    vindex[v] = index;
    vlowlink[v] = index;
    index++;
    s.push(v);
    vonstack[v] = true;

    rep(i, g[v].size()) {
        if (vindex[g[v][i]] == -1) {
            strongconnect(g[v][i], index, s);
            vlowlink[v] = min(vlowlink[v], vlowlink[g[v][i]]);
        }
        else if (vonstack[g[v][i]]) {
            vlowlink[v] = min(vlowlink[v], vindex[g[v][i]]);
        }
    }

    if (vlowlink[v] == vindex[v]) {
        vector<int> cc;
        index_comp++;
        int w = v+1;
        while (!s.empty() && v != w) {
            w = s.top();
            comp[w] = index_comp;
            vonstack[w] = false;
            s.pop();
            cc.push_back(w);
        }
        scc.push_back(cc);
    }

}

void tarjan(int m) {

    vindex.resize(m + 1, -1);
    vlowlink.resize(m + 1, -1);
    vonstack.resize(m + 1, false);
    stack<int> s;
    int index = 0;
    repae(i, 1, m) {
        if (vindex[i] == -1) {
            strongconnect(i, index, s);
        }
    }


}

void findOrderC(int cc, vector<vector<int>> &fuck) {

    vis[cc] = true;


    rep(i, fuck[cc].size()) {
        if (!vis[fuck[cc][i]]) {
            findOrderC(fuck[cc][i], fuck);
        }
    }

    topnode.push(cc);


}

struct Edge {
    int ng;
    list<Edge>::iterator it;
    Edge(int _adj) : ng(_adj) {}
};

list<int> path;
vector<list<Edge>> lg;
void Hierholzer(int v) {
    while (lg[v].size() > 0) {
        int adj = lg[v].front().ng;
        lg[adj].erase(lg[v].front().it);
        lg[v].pop_front();
        Hierholzer(adj);
    }
    path.emplace_back(v);
}


void solve() {

    int n, m;
    input n >> m;

    lg.resize(200005);
    
    bool ans = false;

    rep(i, m) {
        int a, b;
        input a >> b;
        if (a == 1 || b == 1)ans = true;

        lg[a].emplace_front(b);
        lg[b].emplace_front(a);
        lg[a].begin()->it = lg[b].begin();
        lg[b].begin()->it = lg[a].begin();
              
    }

    
    if (ans) {
        int count = 0;
        for (int i = 0; i < lg.size(); ++i) {
            if (lg[i].size() % 2 == 1) {
                ++count;
                break;
            }
        }
        if (count == 0 ||count == 2) {
            Hierholzer(1);
        }
        else {
            ans = false;
        }
    }

  

    if (!ans ||path.size() != m+1) {
        aff "IMPOSSIBLE" endf
    }
    else {
        for (list<int>::iterator it = path.begin(); it != path.end(); ++it) {
            aff *it espaffe
        }aff endlf
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

    ll t = 1;

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
