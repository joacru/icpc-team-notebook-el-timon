int sz[MAXN];
int get_size(int u, int p){
	sz[u] = 1;
	for(int v: g[u]) if(v != p) sz[u] += get_size(v,u);
	return sz[u];
}
int get_centroid(int u, int p, int s){
	for(int v: g[u])
		if(v!=p&&2*sz[v]>s) return get_centroid(v,u,s);
	return u;
}
void build(int u){
	if(sz[u] == -1) get_size(u,u);
	int q = get_centroid(u,u,sz[u]);
	run(q,sz[u]); // Resolver el problema en O(n)
	for(int v:g[q]){
		g[v].erase(find(g[v].begin(),g[v].end(),q));
		if(sz[v] > sz[q]) sz[v] = -1;
		build(v);
    }
}
void build(){ forn(i,0,MAXN) sz[i] = -1; build(0); }