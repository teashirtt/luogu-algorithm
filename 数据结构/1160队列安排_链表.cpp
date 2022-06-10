#include<iostream>
using namespace std;
const int N=100010;
int n,m,head;
struct node{
    int pre;
    int next;
}queue[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    queue[0].next = 1;
    queue[1].pre = 0;queue[1].next = -1;
    for(int i = 2;i <= n;i++)
    {
        int k,p;cin>>k>>p;
        if(p)
        {
            queue[i].pre = k;
            queue[queue[k].next].pre = i;
            queue[i].next = queue[k].next;
            queue[k].next = i;
        }else
        {
            queue[i].next = k;
            queue[queue[k].pre].next = i;
            queue[i].pre = queue[k].pre;
            queue[k].pre = i;
        }
    }
    cin>>m;
    for(int i = 1;i <= m;i++)
    {
        int temp;cin>>temp;
        if(queue[temp].next == -1 && queue[temp].pre == -1)
            continue;
        queue[queue[temp].pre].next = queue[temp].next;
        queue[queue[temp].next].pre = queue[temp].pre;
        queue[temp].next = queue[temp].pre = -1;
    }
    int k = queue[0].next;
    while(k != -1)
    {
        cout<<k<<' ';
        k = queue[k].next;
    }
    return 0;
}