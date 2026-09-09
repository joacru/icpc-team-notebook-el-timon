/**
 * Author: 
 * Description: 
 */
struct Pt {  // for 3D add z coordinate
	double x,y;
	Pt(double x, double y):x(x),y(y){}
	Pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(Pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	Pt operator+(Pt p){return Pt(x+p.x,y+p.y);}
	Pt operator-(Pt p){return Pt(x-p.x,y-p.y);}
	Pt operator*(double t){return Pt(x*t,y*t);}
	Pt operator/(double t){return Pt(x/t,y/t);}
	double operator*(Pt p){return x*p.x+y*p.y;}
//	Pt operator^(Pt p){ // only for 3D
//		return Pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(Pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	Pt unit(){return *this/norm();}
	double operator%(Pt p){return x*p.y-y*p.x;}
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
