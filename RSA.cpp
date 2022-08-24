#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
ll extended_euclid(ll n,ll m)
{
    if(m==0)
    {
        x=1;
        y=0;
    }
    else{
        extended_euclid(m,n%m);
        //cout<<x<<" "<<y<<endl;
        ll t=x;
        x=y;
        y=t-(n/m)*y;
    }
    return x;
}
ll modular_exp(ll a, ll b, ll m){
    ll ans=1;
    while(b){
        if(b%2){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b/=2;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    ll p=17, q=11;
    ll phi=(p-1)*(q-1),n=p*q, e=7;
    ll d=extended_euclid(e,phi);
    ll num, cipher;
    cin>>num;
    cipher= modular_exp(num,e,n);
    cout<<"Cipher is: "<<cipher<<endl;
    cout<<"Decrypt is: "<<modular_exp(cipher,d,n)<<endl;

    return 0;
}