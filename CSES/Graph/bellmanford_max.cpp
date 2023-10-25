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

    AStarNode(pair<ll, ll> n, long long c, AStarNode* p) : node(n), cost(c), parent(p) {}
};


const ll mod = 1e9 + 7;
const ll maxb = 1e18;

vector<vector<pair<ll, ll>>> g(100005);
vector<vector<bool>> vis(1000, vector<bool>(1000, false));
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
vector<AStarNode> nodessh(100005, AStarNode({ -1,-1 }, -5000000000000, nullptr));

const int MAXG = 505;
vector<vector<int>> adj(MAXG, vector<int>(MAXG, 2000000000));
ll distances[MAXG][MAXG];

vector<tuple<int, int, int>> edges;


struct Compare
{
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b)
    {
        return a.first < b.first;
    }
};



ll FindShPath(int start, int n) {

    //queue<pair<ll, ll>> q;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> q;

    nodessh[start] = AStarNode({ start, start }, 0, nullptr);
    nodessh[start].dir = 'A';
    q.push({ 0, start });


    while (!q.empty()) {

        pair<ll, ll> current = q.top();

        q.pop();

        if (!vissh[current.second]) {

            vissh[current.second] = true;

            rep(i, g[current.second].size()) {

                ll newcost = g[current.second][i].first;
                ll city = current.second;

                if (current.first + newcost > nodessh[g[city][i].second].cost) {
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

ll BellmanFord(int x, int n) {

    ll distance[2501];
    vector<int>par(n, -1);

    for (int i = 0; i < n; i++) distance[i] = numeric_limits<ll>::max() / 2;
    distance[x] = 0;
    for (int i = 0; i < n - 1; i++) {

        for (const auto& e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            //cout << a << " " << b << " " << w << endl<<endl;
            if (distance[a] == numeric_limits<ll>::max() / 2)continue;
            if (distance[a] + w < distance[b]) {

                distance[b] = distance[a] + w;
                distance[b] = max(distance[b], -numeric_limits<ll>::max() / 2);


            }
        }
    }

    for (int i = 0; i < n - 1; i++) {

        for (const auto& e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            //cout << a << " " << b << " " << w << endl<<endl;
            if (distance[a] == numeric_limits<ll>::max() / 2)continue;
            distance[b] = max(distance[b], -numeric_limits<ll>::max() / 2);
            if (distance[a] + w < distance[b]) {

                distance[b] = -numeric_limits<ll>::max() / 2;


            }
        }
    }



    return distance[n - 1];

}

map<pair<ll, ll>, int>medges;
ll maximum = -numeric_limits<ll>::max();
void dfs(ll ind, ll maxi, int n) {

    if (ind == n) {
        maximum = max(maximum, maxi);
        return;
    }

    rep(i, g[ind].size()) {

        //medges[{ind, g[ind][i].second}]++;
        //if (medges[{ind, g[ind][i].second}] == 1) {

        dfs(g[ind][i].second, maxi + g[ind][i].first, n);
        //}

    }

}

map<pair<ll, ll>, ll> med;

void solve() {

    int n, m;
    input n >> m;



    int point = 0;
    rep(i, m) {
        ll a, b, c;

        input a >> b >> c;
        //aff c endf
        edges.push_back({ a - 1, b - 1, c * -1 });
        //edges.push_back({ b - 1, a - 1, c });
        /*if (med.count({a, b}) > 0)
            med[{a, b}] = max(med[{a, b}], c);
        else
            med[{a, b}] = c;*/
    }

    /*for (auto& e : med) {
        //aff e.first.first espaff e.second espaff e.first.second endf
        g[e.first.first].push_back({ e.second, e.first.second });
        g[e.first.second].push_back({ e.second, e.first.first });
    }*/

    if (n == 1 && m == 1) {
        ll a, b, w;
        tie(a, b, w) = edges[0];
        if (w >= 0) {
            aff 0 endf;
        }
        else {
            aff -1 endf;
        }
        return;
    }

    ll maxi = 0;
    //dfs(1, maxi, n);
    //aff maximum endf
    ll res = BellmanFord(0, n);
    if (res == -numeric_limits<ll>::max() / 2)cout << -1 << endl;
    else aff res * -1 endf


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
