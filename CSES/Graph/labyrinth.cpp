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

map<pair<ll,ll>, vector<pair<ll,ll>>> g;
vector<vector<ll>> vis;
vector<string>vr;

/*
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
*/

int manh(pair<ll, ll>a, pair<ll, ll>b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

struct Point {
    ll x;
    ll y;
    //string path;
};

struct Compare
{
    bool operator()(const pair<ll, Point>& a, const pair<ll, Point>& b)
    {
        return a.first > b.first;
    }
};



string find_pathAB(pair<ll,ll>A, pair<ll,ll>B, int n, int m) {

    //priority_queue<pair<ll, Point>, vector<pair<ll, Point>>, Compare> minq, pqbis;
    deque<  Point> minq;
    Point p, pbis;
    vector<vector<char>> previous(n, vector<char>(m, -1));
    //int maxdist = (double)manh(A, B)*2.0;
    minq.push_back({A.first, A.second});

    while (!minq.empty()) {

        p = minq.front();
        minq.pop_front();

        //int costcurrent = p.first;
        pair<ll, ll> current = { p.x, p.y };
        //string pathcurrent_f = p.path;
        //aff current.first espaff current.second endf

        //if (costcurrent > maxdist && n*m>=500*500)continue;

        /*if (minq.size() > 4000) {
            int x = 0;
            pbis = {};
            pqbis = {};
            while (!minq.empty() && x < 2000) {
                pbis = minq.top();
                minq.pop();
                pqbis.push(pbis);
                x++;
            }
            while (!minq.empty()) {
                pbis = minq.top();
                minq.pop();
                vis[{ pbis.second.x, pbis.second.y }] = 1;
            }
            minq.swap(pqbis);
        }*/

        if (!vis[current.second][current.first]) {

            vis[current.second][current.first] = 1;
            //pathcurrent_f.push_back(current);

            if (current == B) {
                string ans;
                int x = B.first, y = B.second;
                /*rep(i, n) {
                    rep(j, m) {
                        aff previous[i][j];
                    }aff endlf;
                }*/
                while (previous[y][x] != -1) {
                    ///aff previous[y][x] endf
                    ans += previous[y][x];
                    if (previous[y][x] == 'U') {
                        ++y;
                    }
                    else if (previous[y][x] == 'D') {
                        --y;
                    }

                    else if (previous[y][x] == 'L') {
                        ++x;
                    }

                    else if (previous[y][x] == 'R') {
                        --x;
                    }

                }
                reverse(ans.begin(), ans.end());
                return ans;
            }

            if (current.second - 1 >= 0 && (vr[current.second - 1][current.first] == 'B' ||vr[current.second - 1][current.first] == '.')) {
                if (vis[current.second - 1][current.first] == 0) {
                    //aff 'U' endf
                    int cost = 0;// manh(current, { current.first, current.second - 1 });
                    //cost += (double)cost * (double)cost / (double)maxdist;
                    previous[current.second - 1][current.first] = 'U';
                    minq.push_back({current.first,current.second - 1});

                }
            }

            if (current.second + 1 < n && (vr[current.second + 1][current.first] == 'B' || vr[current.second + 1][current.first] == '.')) {
                if (vis[current.second + 1][current.first] == 0) {
                    //aff 'D' endf
                    int cost = 0;//manh(current, { current.first, current.second + 1 });
                    //cost += (double)cost * (double)cost / (double)maxdist;
                    previous[current.second + 1][current.first] = 'D';
                    minq.push_back({current.first,current.second + 1});

                }
            }
            
            if (current.first - 1 >= 0 && (vr[current.second ][current.first- 1] == 'B' || vr[current.second][current.first - 1] == '.')) {
                if (vis[current.second][current.first - 1] == 0) {
                    //aff 'L' endf
                    int cost = 0;// manh(current, { current.first - 1, current.second });
                    //cost += (double)cost * (double)cost / (double)maxdist;
                    previous[current.second ][current.first-1] = 'L';
                    minq.push_back({current.first- 1,current.second});

                }
            }
            
            if (current.first + 1 < m && (vr[current.second ][current.first+ 1] == 'B' || vr[current.second][current.first + 1] == '.')) {
                if (vis[ current.second ][ current.first + 1] == 0) {
                    //aff 'R' endf
                    int cost = 0;// manh(current, { current.first + 1, current.second });
                    //cost += (double)cost * (double)cost / (double)maxdist;
                    previous[current.second ][current.first+1] = 'R';
                    minq.push_back( {current.first+1,current.second});

                }

            }
            

        }


    }


    return {};

}


void solve() {
    
    int n, m;
    input n >> m ;

    vis.clear();
    vis.resize(n);
    rep(i, n) {
        vis[i].resize(m, 0);
    }

    vr.clear();
    vr.resize(n);
    vector<pair<ll, ll>> floor;
    pair<ll, ll>A, B;

    int t = 0;
    rep(i, n) {
        input vr[i];
        
        if (t < 2) {

            rep(j, vr[i].length()) {

                if (vr[i][j] == 'A') {
                    A = { j,i };
                    ++t;
                }
                if (vr[i][j] == 'B') {
                    B = { j,i };
                    ++t;
                }
            }
        }
               
    }
    

    string path = find_pathAB(A, B, n, m);
    if (path.size() > 0) {
        aff "YES" endf;
        aff path.size() endf;
       
        string ans;
        /*repa(i, 1, path.size()) {
          

            if (path[i-1].first < path[i].first) {
                ans+= 'R';
            }
            else if (path[i - 1].first > path[i].first) {
                ans += 'L';
            }
            else if (path[i - 1].second < path[i].second) {
                ans += 'D';
            }
            else if (path[i - 1].second > path[i].second) {
                ans += 'U';
            }

            
          
        }*/
        /*rep(i, path.size()) {
            ans += path[i];
        }*/
        aff path endf
    }
    else {
        aff "NO" endf
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
