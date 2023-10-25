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

vector<vector<bool>> vis(1000, vector<bool>(1000, false));
deque<int>path;
vector<map<int, int>> dp;
vector<map<int, deque<int>>> dp2;
vector<int>currentPath, cyclePath;
vector<pair<ll, ll>> monsters;
vector<string> grid;
pair<ll, ll> A;
vector<pair<ll, ll>>output;



int manh(pair<ll, ll>a, pair<ll, ll> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

struct AStarNode {
    pair<ll,ll> node;
    long long cost;
    AStarNode* parent;
    char dir;

    AStarNode(pair<ll, ll> n, long long c, AStarNode* p) : node(n), cost(c), parent(p) {}
};

struct Compare
{
    bool operator()(const pair<ll, pair<ll, ll>>& a, const pair<ll, pair<ll, ll>>& b)
    {
        return a.first > b.first;
    }
};

string findMinPath(pair<ll,ll> start, pair<ll,ll>end, int n, int m) {

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, Compare> pq;
    vector<vector<AStarNode>> nodes(n, vector<AStarNode>(m, AStarNode({ -1,-1 }, 2000000000, nullptr)));
    pair<ll, pair<ll,ll>> p;

    nodes[start.second][start.first] = AStarNode(start, 0, nullptr);
    nodes[start.second][start.first].dir = 'A';

    pq.push({ 0, {start} });

    //aff"astar start" endf

    while (!pq.empty()) {

        p = pq.top();
        pq.pop();


        int costcurrent = p.first;
        pair<ll,ll> current = p.second;

        //aff current.first espaff current.second endf

        if (!vis[current.second][current.first]) {

            vis[current.second][current.first] = true;


            if (current == end) {
                string path;
                AStarNode* currentNode = &nodes[end.second][end.first];
                while (currentNode != nullptr && currentNode->dir != 'A') {
                    path.push_back(currentNode->dir);
                    //aff "path " espaff currentNode->dir endf
                    currentNode = currentNode->parent;
                }
                reverse(path.begin(), path.end());
                return path;
            }

            if (costcurrent > nodes[current.second][current.first].cost) {
                continue;
            }

            vector<vector<int>>dir = { {-1,0}, {1,0}, {0,-1}, {0,1} };
            vector<char> dirc = { 'U', 'D', 'L', 'R' };
            rep(i, 4) {

                int x = current.first + dir[i][1];
                int y = current.second + dir[i][0];
                //aff x espaff y  endf
                if (x < 0 || x >= m || y<0 || y >= n)continue;
                //aff grid[y][x] endf
                if ( grid[y][x] == '.') {
                    int newcost = costcurrent + manh(current, { x , y });
                    //aff "cost " espaff newcost endf
                    if (newcost < nodes[y][x].cost) {
                        nodes[y][x] = AStarNode({x, y}, newcost,  &nodes[current.second][current.first]);
                        nodes[y][x].dir = dirc[i];
                        pq.push({ newcost, {x, y } });

                    }
                }
            }

        }


    }

    return {};

}

void solve() {
    
    int n, m;
    input n >> m ;

    grid.resize(n);

    rep(i, n) {
        string l;
        input grid[i];

        repj(j, m) {
            if (grid[i][j] == 'A') {
                A = { j, i };
            }
            if (grid[i][j] == 'M') {
                monsters.push_back({ j, i });
            }

        }

    }
  
    rep(i, m) {
        if (grid[0][i] == '.') {
            output.push_back({ i, 0 });
        }
    }
    rep(i, m) {
        if (grid[n-1][i] == '.') {
            output.push_back({ i, n-1 });
        }
    }
    rep(i, n) {
        if (grid[i][0] == '.') {
            output.push_back({ 0, i });
        }
    }
    rep(i, n) {
        if (grid[i][m-1] == '.') {
            output.push_back({ m - 1, i });
        }
    }

    vector<pair<int, ll>> outd;
    rep(i, output.size()) {
        outd.push_back({ manh(output[i], A), i });
    }

    srt(outd);

    //aff "start" espaff output.size() endf;
    string path;
    rep(i, outd.size()) {
        path = findMinPath(A, output[outd[i].second], n, m);
        if (!path.empty()) {
            break;
        }
    }

    if (path.length() > 0) {
        aff "YES" endf
        aff path.length() endf
        aff path endf
    }
    else
        aff "NO" endf
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
