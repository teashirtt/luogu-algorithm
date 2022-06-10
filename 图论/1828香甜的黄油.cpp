#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 10010;
int n, p, c, idx, e[N], head[N], nx[N], cow[N];
bool st[N];
long long dis[N], res = 0x3f3f3f3f, v[N];
void add(int a, int b, long long w)
{
    e[idx] = b, v[idx] = w, nx[idx] = head[a], head[a] = idx++;
}
long long spfa(int h)
{
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    dis[h] = 0;
    st[h] = true;
    q.push(h);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        st[u] = false;
        for (int i = head[u]; ~i; i = nx[i])
        {
            int j = e[i];
            if (dis[j] > dis[u] + v[i])
            {
                dis[j] = dis[u] + v[i];
                if (!st[j])
                    q.push(j), st[j] = true;
            }
        }
    }
    long long val = 0;
    for (int i = 1; i <= n; i++)
        val += dis[cow[i]];
    return val;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++)
        cin >> cow[i];
    memset(head, -1, sizeof head);
    for (int i = 1; i <= c; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        add(a, b, w);
        add(b, a, w);
    }
    for (int i = 1; i <= p; i++)
        res = min(res, spfa(i));
    cout << res;
    return 0;
}