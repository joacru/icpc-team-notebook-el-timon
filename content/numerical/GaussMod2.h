/**
 * Author: cp-algorithms
 * Description: mod 2 or xor. Complexity: O(n*m*min(n,m)/64)
 */

int gauss(vector<bitset<MAXN>> &a, int n, int m, bitset<MAXN> &ans){
	vector<int> where(m,-1);
	for(int col=0,row=0;col<m&&row<n;++col){
		for(int i=row;i<n;++i){
			if(a[i][col]){
				swap(a[i],a[row]);
				break;
			}
		}
		if(!a[row][col]) continue;
		where[col] = row;
		for(int i=0;i<n;++i) if(i!=row&&a[i][col]) a[i]^=a[row];
		++row;
	}
	ans.reset();
	for(int i=0;i<m;++i){
		if(where[i]!=-1){
			assert(a[where[i]][i]);
			ans[i] = a[where[i]][m];
		}
	}
	for(int i=0;i<n;++i){
		int sum = 0;
		for(int j=0;j<m;++j) sum ^= (ans[j]&a[i][j]);
		if(sum!=a[i][m]) return -1; // no hay solucion
	}
	int ret = 0;
	for(int i=0;i<m;++i) if(where[i] == -1) ret += 1;
	return ret; // variables libres
}