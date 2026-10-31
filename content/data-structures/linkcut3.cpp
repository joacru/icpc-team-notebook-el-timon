const T NDEL=0, NVAL=0; // no lazy, null
inline T mOp(T x, T y){return max(x,y);}
inline T qOp(T lv, T rv){return max(lv,rv);}
inline T dOnSeg(T d, int len){return NDEL;}
inline T joinD(T d1, T d2){
    if(d1==NDEL) return d2;
    if(d2==NDEL) return d1;
    return mOp(d1,d2);
}
inline T joinVD(T v, T d){return d==NDEL?v:mOp(v,d);}
typedef struct Node *node;
struct Node{
    int sz=1;bool rev=0;
    T nVal, tVal, d=NDEL;
    node c[2],p=0;
    Node(T v): nVal(v),tVal(v){c[0]=c[1]=0;}
    bool isRoot(){return !p||(p->c[0]!=this&&p->c[1]!=this);}
    void push(){
        if(rev){
            rev=0;swap(c[0],c[1]);
            forn(x,0,2)if(c[x])c[x]->rev^=1;
        }
        nVal=joinVD(nVal,d);tVal=joinVD(tVal,dOnSeg(d,sz));
        forn(x,0,2)if(c[x])c[x]->d=joinD(c[x]->d,d);
        d=NDEL;
    }
    void upd();
};
int getSize(node r){return r?r->sz:0;}
T getPV(node r){if(!r)return NVAL;r->push();return r->tVal;}
void Node::upd(){
    tVal=qOp(qOp(getPV(c[0]),nVal),getPV(c[1]));
    tVal=qOp(qOp(getPV(c[0]),joinVD(nVal,d)),getPV(c[1]));
    sz=1+getSize(c[0])+getSize(c[1]);
}
void conn(node c, node p, int il){
    if(c)c->p=p;
    if(il>=0)p->c[!il]=c; }
void rotate(node x){
    node p=x->p,g=p->p;
    bool gCh=p->isRoot(),isl=x==p->c[0];
    conn(x->c[isl],p,isl); conn(p,x,!isl);
    conn(x,g,gCh?-1:(p==g->c[0])); p->upd();
}
void spa(node x){
    while(!x->isRoot()){
        node p=x->p,g=p->p;
        if(!p->isRoot())g->push();
        p->push();x->push();
        if(!p->isRoot())rotate((x==p->c[0])==(p==g->c[0])?p:x);
        rotate(x);
    }
    x->push();x->upd();
}
node exv(node x){
    node last=0;
    for(node y=x;y;y=y->p)spa(y),y->c[0]=last,y->upd(),last=y;
    spa(x);
    return last;
}
void mkR(node x){exv(x);x->rev^=1;}
node getR(node x){
    exv(x);
    while(x->c[1])x=x->c[1];
    spa(x);return x;
}
node lca(node x, node y){exv(x);return exv(y);}
bool path(node x, node y){exv(x);exv(y);return x==y?1:x->p!=0;}
void link(node x, node y){mkR(x);x->p=y;}
void cut(node x, node y){mkR(x);exv(y);y->c[1]->p=0;y->c[1]=0;}
node father(node x){
    exv(x);node r=x->c[1];
    if(!r) return 0;
    r->push();
    while(r->c[0]) r=r->c[0],r->push();
    return r; }
void cut(node x){ exv(father(x));x->p=0; }
T query(node x, node y){mkR(x);exv(y);return getPV(y);}
void modify(Node x, Node y, int d){mkR(x);exv(y);y->d=joinD(y->d,d);}
Node lift_rec(Node x, int t){
	if(!x)return 0;
	if(t==getSize(x->c[0])){spa(x);return x;}
	if(t<getSize(x->c[0]))return lift_rec(x->c[0],t);
	return lift_rec(x->c[1],t-getSize(x->c[0])-1);
}
Node lift(Node x, int t){ // t-th ancestor of x (lift(x,1) is x's father)
	exv(x);return lift_rec(x,t);}
int depth(Node x){ // distance from x to its tree root
	exv(x);return getSize(x)-1;}
