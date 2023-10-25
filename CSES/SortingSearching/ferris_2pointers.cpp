// CSES.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>
#include <set>
#include <map>
#include <string>
using namespace std;
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
#define aff cout <<
#define daff cerr <<
#define endf << '\n';
#define endlf '\n';
#define espaff << " " <<
#define espaffe << " " ;
#define input cin >>
#define disptabl(v) rep(i,v.size()){ aff v[i] espaffe}aff endlf
#define sort(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.rbegin(), v.rend())

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

///vector<ll> dp(500 + 5, 0);
vector<vector<ll>>dp(18 + 5, vector<ll>(18+5, 0));
const ll mod = 1e9+7;
const ll maxb = 1e18;


void solve() {
    
    int n, x;
    input n >>x;

    map<ll, ll>fr;
    vll a(n);
    rep(i, n) {
        input a[i];
       
    }
  

    sort(a);

    //disptabl(a);


    itvll it, it2;
    ll count = 0;

    it = a.begin();
    it2 = a.end() - 1;

    ll accum = 0;
    while (it <= it2) {

        //aff* it espaff* it2 endf;

        if (*it + *it2 <= x) {
            ++it;
            --it2;
        }
        else {

            if (*it > x)
                ++it;
            else
                --it2;

            

        }
        count++;
        

             
            /*
        bool sup = false;
        if (accum + *it < x) {
            accum += *it;
            
            ++it;
        }
        else if (accum + *it == x) {
            accum =0;
            ++it;
            count++;
        }
        else if (accum + *it > x) {
            accum = *it;
            count++;
            sup = true;
        }

        if (accum + *it2 < x) {
            accum += *it2;
            --it2;
        }
        else if (accum + *it2 == x) {
            accum = 0;
            --it2;
            count++;
        }
        else if (accum + *it2 > x) {
            if(!sup)
                --it;
            --it2;
            count++;
            accum = *it;

        }
        */
          

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
