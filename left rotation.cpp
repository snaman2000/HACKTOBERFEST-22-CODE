#include<iostream>
#include<vector>
using namespace std ;
int gcd(int x,int y)
{
    if(y==0)
        return x ;
    else return gcd(y,x%y) ;     
}
int main()
{
int n , d ;
cin>>n>>d ;

d=d%n ;
vector<int> v(n) ;
for(int i=0 ;i<n ;i++)
    cin>>v[i] ;

for(int i=0 ; i<gcd(n,d) ; i++)
{
    int temp=v[i] ;
    int j= i ;

    while(1)
    {
        int k=j+d ;
        if(k>=n)
            k=k-n ;
        if(k==i) ;
            break ;    
        v[j] = v[k] ;
        j=k ;
    }
    v[j] = temp ;
}

for(auto x:v)
    cout<<x<<' ';
}