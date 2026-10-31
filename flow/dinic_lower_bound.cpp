struct Edge{
	int u, v, l, c;
};
const int S = N, T=N+1, SS=N+2, TT=N+3;
vector<Edge> es;
for(const auto &e: es){
    sum += e.l;
    G.add_edge(e.u,e.v,e.c-e.l);
    G.add_edge(SS,e.v,e.l);
    G.add_edge(e.u,TT,e.l);
}
G.add_edge(T,S,INF);
ll flow = G.max_flow(SS,TT); // for lower bound
assert(flow==sum); // check
flow = G.max_flow(S,T); // for max flow
