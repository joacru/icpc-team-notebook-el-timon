/**
 * Author: -
 * Description: -
 */
int gauss(vector<vector<ll>> a, vector<ll> &ans){
	int n=SZ(a), m=SZ(a[0])-1;
	vector<int> where(m,-1);
	for(int col=0,row=0;col<m&&row<n;++col){
		int sel=row;
		forn(i,row,n) if(a[i][col]) sel=i;
		if(!a[sel][col]) continue;
		swap(a[sel],a[row]);
		where[col]=row;
		ll x=inv(a[row][col]);
		forn(i,0,n){
			if(i!=row){
				ll c=mod(a[i][col]*x);
				for(int j=col;j<=m;++j)
					a[i][j] = mod(a[i][j]-mod(a[row][j]*c));
			}
		}
		++row;
	}
	ans.assign(m,0);
	forn(i,0,m)
		if(where[i]!=-1)
			ans[i]=mod(a[where[i]][m]*inv(a[where[i]][i]));
	forn(i,0,n){
		ll sum = 0;
		for(int j=0;j<m;++j)
			sum = mod(sum+mod(ans[j]*a[i][j]));
		if(sum != a[i][m]) return -1;
	}
	int ret = 0;
	forn(i,0,m) ret+=where[i]==-1;
	return ret; // variables libres
}