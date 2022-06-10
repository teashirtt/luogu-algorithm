#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-4  
using namespace std;
double A, B, C, D;
double Judge(double x)
{
    double ans = A * x * x * x + B * x * x + C * x + D;
    return ans;
}
int main()
{
    cin >> A >> B >> C >> D;
    for(int i = -100; i <= 100; i++)
    {
        double l = i;
        double r = i + 1;  
        if(fabs(Judge(l)) < eps)  
            printf("%.2lf ", l);
        else if(fabs(Judge(r)) < eps)  
            continue;
        else if(Judge(l) * Judge(r) < 0)  
        {
            double mid;
            while(r - l > eps)
            {
                mid = (l + r) / 2;
                if(Judge(mid) * Judge(r) > 0) r=mid;
                else  l = mid;
            }
            printf("%.2lf ", l);
        }
    }
    return 0;
}