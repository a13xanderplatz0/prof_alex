 #include <iostream>
 #include <vector>
#include <assert.h>
 using namespace std;

 class CMatrixL
 {
 public:
     CMatrixL(int _dx, int _dy);
     ~CMatrixL();
     int fi(int x, int y);
     int get(int x, int y);
     void set(int x, int y, int v);
     int& gs(int x, int y);
     int& operator()(int x, int y);
     void print();
 private:
     int* vec;
     int dy, dx;
 };

 CMatrixL::CMatrixL(int _dx, int _dy)
 {
     dy = _dy; dx = _dx;
     vec = new int [dx*dy];
 }

 CMatrixL::~CMatrixL()
 {
     delete vec;
 }

 int CMatrixL::fi(int x, int y)
{
     assert(x>=0 && x<dx && y>=0 && y<dy);
     return y*dx + x;
}

 int CMatrixL::get(int x, int y)
 {   return vec[ fi(x,y) ];  }

 void CMatrixL::set(int x, int y, int v)
 {   vec[ fi(x,y) ] = v; }

 int& CMatrixL::gs(int x, int y)
 {   return vec[ fi(x,y) ];  }

 int& CMatrixL::operator()(int x, int y)
 {   return vec[ fi(x,y) ];  }

 void CMatrixL::print()
 {
     for ( int i = 0; i < dx; ++i )
     {
         for ( int j = 0; j < dy; ++j )
             cout<<vec[ fi(i,j) ]<<" ";
         cout<<"\n";
     }
     cout<<"--------\n";
 }

 int main()
 {
     CMatrixL m(4,3);
     m.print();
     m.set(2,2, 5); m.set(1,1, 2); m.set(1,2, 7);
     m.set(2,1, m.get(2,2));
     m.print();
     m.gs(3,0) = 7;
     m.gs(3,1) = m.gs(3,0);
     m.print();
     m(0,0) = 4;
     m(5,8) = m(0,2) = m(3,1);
     m.print();
     

 }
