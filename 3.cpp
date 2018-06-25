#include <iostream>
#include <math.h>
using namespace std;

double pp(double a ,double b,double c,double x,double y)
{

	double m = sqrt(a*a+b*b);
	
	double ans = a*x+b*y+c/m;
	if(ans<0)
	ans = -1*ans;

	return(ans);
}	

int main()
{
	double x1,x2,x3,x4;
	double y1,y2,y3,y4;

	int xx1,xx2,xx3,xx4;
	int yy1,yy2,yy3,yy4;

	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

	cin>>xx1>>yy1>>xx2>>yy2>>xx3>>yy3>>xx4>>yy4;


	// L1
	double a1=1,b1,c1;

	b1 = (double) (y2-y1)*(-1)/(double) (x2-x1);

	c1 = (double) -y1 - b1*x1 ;

	// L2
	double a2=1,b2,c2;

	b2 = (double) (y3-y2)*(-1)/(double) (x3-x2);

	c2 = (double) -y2 - b2*x2 ;

	// L3
	double a3=1,b3,c3;

	b3 = (double) (y4-y3)*(-1)/(double) (x4-x3);

	c3 = (double) -y3 - b3*x3 ;


// L4
	double a4=1,b4,c4;

	b4 = (double) (y4-y1)*(-1)/(double) (x4-x1);

	c4 = (double) -y4 - b4*x4 ;

	// LL1
	double aa1=1,bb1,cc1;

	bb1 = (double) (yy2-yy1)*(-1)/(double) (xx2-xx1);

	cc1 = (double) -yy1 - bb1*xx1 ;

	// L2
	double aa2=1,bb2,cc2;

	bb2 = (double) (yy3-yy2)*(-1)/(double) (xx3-xx2);

	cc2 = (double) -yy2 - bb2*xx2 ;

	// L3
	double aa3=1,bb3,cc3;

	bb3 = (double) (yy4-yy3)*(-1)/(double)(xx4-xx3);

	cc3 = (double) -yy3 - bb3*xx3 ;


// L4
	double aa4=1,bb4,cc4;

	bb4 = (double) (yy4-yy1)*(-1)/(double) (xx4-xx1);

	cc4 = (double) -yy4 - bb4*xx4 ;


	double l2 = (c1-c3)/(double) sqrt(1+(b1*b1)) ;
	if(l2<0)
	l2 = -1*l2;
		
	double l1 =(double)(cc1-cc3)/ (double) sqrt(1+(bb1*bb1));


	if(l1 <0)
	l1 = -1*l1;
	
	// cout << b1 << " " << bb1;	
		cout<< l1 <<" " << l2<<endl;
	if( false && (pp(a1,b1,c1,xx1,yy1)+pp(a3,b3,c3,xx1,yy1) <= l2  && pp(a2,b2,c2,xx1,yy1)+pp(a4,b4,c4,xx1,yy1) <= l2 ) || (  pp(a1,b1,c1,xx2,yy2)+pp(a3,b3,c3,xx2,yy2) <= l2  && pp(a2,b2,c2,xx2,yy2)+pp(a4,b4,c4,xx2,yy2) <= l2) || (pp(a1,b1,c1,xx3,yy3)+pp(a3,b3,c3,xx3,yy3) <= l2  && pp(a2,b2,c2,xx3,yy3)+pp(a4,b4,c4,xx3,yy3) <= l2) || (pp(a1,b1,c1,xx4,yy4)+pp(a3,b3,c3,xx4,yy4) <= l2  && pp(a2,b2,c2,xx4,yy4)+pp(a4,b4,c4,xx4,yy4)) <= l2)
	cout <<"YES";	
	else if((pp(aa1,bb1,cc1,x1,y1)+pp(aa3,bb3,cc3,x1,y1) <= l1  && pp(aa2,bb2,cc2,x1,y1)+pp(aa4,bb4,cc4,x1,y1) <= l1 ) ||  ( pp(aa1,bb1,cc1,x2,y2)+pp(aa3,bb3,cc3,x2,y2) <= l1  && pp(aa2,bb2,cc2,x2,y2)+pp(aa4,bb4,cc4,x2,y2) <= l1) || ( ( pp(aa1,bb1,cc1,x3,y3)+pp(aa3,bb3,cc3,x3,y3) <= l1 ) && (pp(aa2,bb2,cc2,x3,y3)+pp(aa4,bb4,cc4,x3,y3)) <= l1 )||( (pp(aa1,bb1,cc1,x4,y4)+pp(aa3,bb3,cc3,x4,y4) <= l1  && pp(aa2,bb2,cc2,x4,y4)+pp(aa4,bb4,cc4,x4,y4) <= l1)) )
	cout <<"YES";
	else
	cout << "NO";	
	
	return 0;
}