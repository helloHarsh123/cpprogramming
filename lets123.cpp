#include<bits/stdc++.h>
 
#define lli long long int
#define M 1000000007
#define M1 1000000003
#define vi vector<int>
#define vlli vector<lli>
#define plli pair< lli , lli >
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i : c)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define f(a,b,c) for(int a=b;a<c;a++)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


/*
vector<int> v = {2,4,2,5,1};
vector<int> v(10);
vector<int> v(10, 5);
multiset<int> s;
map<string,int> m;
priority_queue<int> q;
priority_queue<int,vector<int>,greater<int>> q;
bitset<10> s;
bitset<10> s(string("0010011010"));
*/



/*
    modular arithmetic tip
    (a/(b*c*d))modm = (amodm*invb*invc*invd)modm
    (a-b)modm = ((a-b)modm+m)modm
*/


/*declarations*/
long long int modfact(long long int n, long long int p);
long long int modpow(long long int a, long long int b, long long int m);
long long int gcdex(long long int a, long long int b,long long int *x,long long int *y); 
long long int modinv(long long int b,long long int m);
long long int moddiv(long long int a, long long int b, long long int m);
long long int modmulbig(long long int a, long long int b, long long int mod); 
long long int modinvshort(lli b,lli m);



int main()
{
    fastio;

}



/*modular arithmetic functions*/
long long int modfact(long long int n, long long int p) {
    long long int res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (int i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
long long int modpow(long long int a, long long int b, long long int m) {
    a %= m;
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
} 
long long int modinv(long long int b,long long int m) 
{ 
    long long int x, y;
    long long int g = gcdex(b, m, &x, &y);  
    if (g != 1) 
        return -1; 
    return (x%m + m) % m; 
} 
long long int moddiv(long long int a, long long int b, long long int m) 
{ 
    a = a % m; 
    long long int inv = modinv(b, m); 
    if (inv == -1) 
       return 0;
    return (inv * a) % m; 
} 
long long int gcdex(long long int a, long long int b, long long int *x, long long int *y) 
{ 
    if (a == 0) 
    { *x = 0, *y = 1;  return b; } 
    long long int x1, y1; 
    long long int gcd = gcdex(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 
long long int modmulbig(long long int a, long long int b, long long int mod) 
{ 
    long long int res = 0;  
    a %= mod; 
    while (b) 
    { 
        if (b & 1) 
            res = (res + a) % mod; 
        a = (2 * a) % mod; 
        b >>= 1;
    } 
    return res; 
} 

lli modinvshort(lli a,lli m)
{
    return pow(b,m-2)%m;
}