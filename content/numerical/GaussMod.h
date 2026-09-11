/**
 * Author: -
 * Description: -
 */
int gauss(vector<vector<ll>> a, vector<ll> &ans){
	int n = (int) a.size();
	int m = int(a[0].size()-1);
	vector<int> where(m,-1);
	for(int col=0,row=0;col<m&&row<n;++col){
		int sel = row;
		for(int i=row;i<n;++i){
			if(a[i][col]) sel=i;
		}
		if(!a[sel][col]) continue;
		//~ for(int i=col;i<=m;++i) swap(a[sel][i],a[row][i]);
		swap(a[sel],a[row]);
		where[col]=row;
		for(int i=0;i<n;++i){
			if(i!=row){
				ll c=a[i][col]*inv(a[row][col])%MOD;
				for(int j=col;j<=m;++j){
					a[i][j] -= a[row][j]*c%MOD;
					a[i][j] = mod(a[i][j]);
				}
			}
		}
		++row;
	}
	ans.assign(m,0);
	for(int i=0;i<m;++i){
		if(where[i] != -1) ans[i]=a[where[i]][m]*inv(a[where[i]][i])%MOD;
	}
	for(int i=0;i<n;++i){
		ll sum=0;
		for(int j=0;j<m;++j){
			sum += ans[j]*a[i][j]%MOD;
			sum %= MOD;
		}
		if(sum != a[i][m]) return 0;
	}
	return 1;
}