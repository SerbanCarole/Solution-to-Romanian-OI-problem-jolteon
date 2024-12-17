#include <fstream>
#include <ctime>
#include <chrono>
#include <random>
#include <unordered_map>
using namespace std;
ifstream cin("jolteon.in");
ofstream cout("jolteon.out");
const int buc = 316;
const int nmax = 1e5 + 1;
const int vmax = 1e6 + 1;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
int n , last[vmax] , l[nmax];
long long v[nmax] , aux[nmax] , xh[vmax] , lz[buc+1];
bool invec[vmax];
unordered_map<long long,int>um[buc+1];
int upd(int dr , int val)
{
    int b = dr/buc;
    int cnt = 0;
    if(b == 0)
    {
        for(int i = 1 ; i <= dr ; ++i)
        {
            um[b][v[i]]--;
            if((v[i]^lz[b]) == 0) --cnt;
            if(!um[b][v[i]]) um[b].erase(v[i]);
            v[i]^=val;
            um[b][v[i]]++;
            if((v[i]^lz[b]) == 0) ++cnt;
        }
    }
    else
    {
        int cdr = b*buc;
        for(int i = dr ; i >= cdr ; --i)
        {
            um[b][v[i]]--;
            if((v[i]^lz[b]) == 0) --cnt;
            if(!um[b][v[i]]) um[b].erase(v[i]);
            v[i]^=val;
            um[b][v[i]]++;
            if((v[i]^lz[b]) == 0) ++cnt;
        }
        for(int i = 0 ; i < b ; ++i)
        {
            if(um[i].count(lz[i])) cnt -= um[i][lz[i]];
            lz[i]^=val;
            if(um[i].count(lz[i])) cnt += um[i][lz[i]];
        }
    }
    return cnt;
}
int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> v[i];
        invec[v[i]] = 1;
        aux[i] = v[i];
        l[i] = last[v[i]];
        last[v[i]] = i;
    }
    for(int i = 1 ; i < vmax ; ++i) if(invec[i]) xh[i] = mt();
    int un = 0;
    long long ans = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        un++;
        um[i/buc][0]++;
        v[i] = 0;
        if(l[i]) un += upd(l[i],xh[aux[i]]);
        ans += un;
    }
    cout << ans;
    return 0;
}
