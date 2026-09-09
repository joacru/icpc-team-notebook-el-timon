#include <bits/stdc++.h>
#define forn(i,a,n) for(int i=int(a);i<int(n);++i)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset(a,v,sizeof(a))
#define ALL(v) v.begin(),v.end()
#define SZ(v) (int)v.size()
#define LINE cerr<<"=========="<<endl
using namespace std;
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
	os<<"["; for(T x: v) os<<x<<", "; os<<"]";
	return os; }
template<typename... T>
void _d(T... x){((cerr<<x<<", "),...);cerr<<"\n";}
#define DBG(...) (cerr<<"["<<#__VA_ARGS__<<"] = ",_d(__VA_ARGS__))
typedef long long ll;
typedef long double ld;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	
}