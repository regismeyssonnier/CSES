#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n, k, a, b, pass = 0;
     cin >> n >> k;
     vector<int> numbers(n + 1);
     vector<int> location(n + 1);
     map<int, int> numpairs;
     for (int i = 1; i <= n; i++)
     {
          cin >> numbers[i];
          location[numbers[i]] = i;
     }

     for (int i = 1; i < n; i++)
          if (location[i + 1] < location[i])
               pass++;
     pass++;

     while (k--)
     {
          cin >> a >> b;

          // put the numbers but we will check for boundary cond

          if (numbers[a] - 1 >= 1)
               numpairs.insert({numbers[a] - 1, numbers[a]});
          if (numbers[a] + 1 <= n)
               numpairs.insert({numbers[a], numbers[a] + 1});
          if (numbers[b] - 1 >= 1)
               numpairs.insert({numbers[b] - 1, numbers[b]});
          if (numbers[b] + 1 <= n)
               numpairs.insert({numbers[b], numbers[b] + 1});

          for (auto it = numpairs.begin(); it != numpairs.end(); it++)
               if (location[it->first] > location[it->second])
                    pass--;

          swap(numbers[a], numbers[b]);
          location[numbers[a]] = a;
          location[numbers[b]] = b;

          for (auto it = numpairs.begin(); it != numpairs.end(); it++)
               if (location[it->first] > location[it->second])
                    pass++;

          cout << pass << "\n";
          numpairs.clear();
     }
}