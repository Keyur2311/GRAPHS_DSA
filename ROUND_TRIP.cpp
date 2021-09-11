#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
vector<bool> vis(N, 0);
vector<int> par(N, -1);

void DFS(int src, int parent)
{

    vis[src] = 1;
    par[src] = parent;

    for (auto it : graph[src])
    {
        if (vis[it] == false)
            DFS(it, src);
        else if (it != parent)
        {
            vector<int> ans;
            int curr = src;
            ans.push_back(curr);

            while (par[curr] != it)
            {
                curr = par[curr];
                ans.push_back(curr);
            }
            ans.push_back(it);
            ans.push_back(src);

            cout << (int)ans.size() << endl;
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
            exit(0);
        }
    }

    return;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            DFS(i, -1);
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return;
}

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}

