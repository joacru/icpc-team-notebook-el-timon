/**
 * Author: 
 * Description: 
 */
const ld EPS = 1e-9;
bool ge (ld a, ld b){ return a >  b + EPS; }
bool geq(ld a, ld b){ return a >= b - EPS; }
bool leq(ld a, ld b){ return a <= b + EPS; }
struct Pt {
	double x, y;
	Pt(double x, double y):x(x),y(y){}
	Pt(){}
	double norm2() const {return *this**this;}
	double norm() const {return sqrt(norm2());}
	bool operator==(const Pt& p) const {return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	Pt operator+(const Pt& p) const {return Pt(x+p.x,y+p.y);}
	Pt operator-(const Pt& p) const {return Pt(x-p.x,y-p.y);}
	Pt operator*(double t) const {return Pt(x*t,y*t);}
	Pt operator/(double t) const {return Pt(x/t,y/t);}
	double operator*(const Pt& p) const {return x*p.x+y*p.y;}
	double operator%(const Pt& p) const {return x*p.y-y*p.x;}
//	Pt operator^(Pt p){ // only for 3D
//		return Pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(Pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	Pt unit(){return *this/norm();}
	// 2D from now on
	bool operator<(Pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(Pt p, Pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	Pt rot(Pt r){return Pt(*this%r,*this*r);}
	Pt rot(double a){return rot(Pt(sin(a),cos(a)));}
};
Pt ccw90(1,0);
Pt cw90(-1,0);
