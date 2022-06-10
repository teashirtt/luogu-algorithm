#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N =20010;
int  n;
ll fire_start,fire_end,fire_dis;
struct firefield
{
    ll fir;
    ll end;
}q[N];

bool cmp(firefield k1,firefield k2)
{
    return k1.fir<k2.fir;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) 
        cin>>q[i].fir>>q[i].end;
    sort(q+1,q+n+1,cmp);

    fire_start=q[1].fir;
    fire_end=q[1].end;
    fire_dis=q[1].end-q[1].fir;
    for(int i=2;i<=n;i++)
    {
        if(q[i].fir>fire_end) fire_start=q[i].fir,fire_end=q[i].end,fire_dis=fire_dis+q[i].end-q[i].fir;
        else 
        {
            if(q[i].end<fire_end) continue;
            else fire_dis=fire_dis+q[i].end-fire_end,fire_end=q[i].end;
        }
    }
    cout<<fire_dis;
    return 0;
}