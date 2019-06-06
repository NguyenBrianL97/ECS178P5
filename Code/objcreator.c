//header
#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

//globals
float ctrlPts [8][2];
int count=0;
int xa=1;

float getPt( float n1 , float n2 , float perc )
{
  float diff = n2 - n1;
  return n1 + ( diff * perc );
}  

int main(int argc,char **argv) {
// DATA
  ctrlPts[0][0]=0; 
  ctrlPts[0][1]=0;
  ctrlPts[0][2]=0;
  ctrlPts[1][0]=2; 
  ctrlPts[1][1]=4;
  ctrlPts[1][2]=0;
  ctrlPts[2][0]=4; 
  ctrlPts[2][1]=0;
  ctrlPts[2][2]=0;

  ctrlPts[3][0]=0; 
  ctrlPts[3][1]=0;
  ctrlPts[3][2]=1;
  ctrlPts[4][0]=2; 
  ctrlPts[4][1]=4;
  ctrlPts[4][2]=1;
  ctrlPts[5][0]=4; 
  ctrlPts[5][1]=0;
  ctrlPts[5][2]=1;
//


  ofstream file;
  file.open ("wavefront.txt");
  ifstream fin;
  fin.open("input.txt");
  char my_character ;
  


  for (int i=0; i<=2; i++) { //front and back
      for (int j=0; j<=1; j++) {

        if (!fin.eof() ) {
        fin.get(my_character);
        
        float coor=my_character;
        coor = coor - '0';
        
        ctrlPts[i][j]=coor;
        }
        
      }
    }
  for( float i = 0 ; i <= 1.1 ; i += 0.10 ) {

    float x1,x2,x3,y1,y2,y3,xa,xb,ya,yb,x,y;

    //FEED DATA
    x1=ctrlPts[0][0];
    y1=ctrlPts[0][1];
    x2=ctrlPts[1][0];
    y2=ctrlPts[1][1];
    x3=ctrlPts[2][0];
    y3=ctrlPts[2][1];

    

    // The Green Line
    xa = getPt( x1 , x2 , i );
    ya = getPt( y1 , y2 , i );
    xb = getPt( x2 , x3 , i );
    yb = getPt( y2 , y3 , i );

    // The Black Dot
    x = getPt( xa , xb , i );
    y = getPt( ya , yb , i );

    file << "v " << x << " " << y << " 0\n";
    file << "v " << x << " " << y << " 1\n";
    count++;
  }

  for (float i=0; i<=1; i++) { //front and back
    for (float i=0; i<=count-1; i++) {
      file << "f ";
      file << xa << "// ";
      xa=xa+2;
    }
    file << "\n";
    xa=2;
  }
  
  xa=1;
  for (float i=0;i<=count-2;i++) { //edge
    file << "f ";
    file << xa << "// ";
    xa=xa+1;
    file << xa << "// ";
    xa=xa+2;
    file << xa << "// ";
    xa=xa-1;
    file << xa << "// ";
    file << "\n";
  }

  file << "f 1// 2// "; //bottom
  file << count*2 << "// " << count*2-1 <<"//";

  file.close();
  rename("wavefront.txt", "wavefront.obj");
}


