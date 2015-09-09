#include<stdio.h>

int max(int a, int b)
{
  int m;
  if (a>b)
    {
      m = a;
    }
  else
    {
      m=b;
    }
  return m;
}

bool checkSize(int x, int y, int XL, int XU, int YL, int YU)
{
  if (((x>=XL && x<XU) && (y==YL || y==YU-1)) ||((y>=YL && y<YU) && (x==XL || x==XU-1)))                     
    {
      return 1;
    }
  else
    {
      return 0;
    }
}


void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w

  //compute the max of size1 and (y_offset + size2).  Call this h

  //count from 0 to h. Call the number you count with y

  //count from 0 to w. Call the number you count with x

  //check if  EITHER
  //    ((x is between x_offset  and x_offset +size2) AND 
  //     y is equal to either y_offset OR y_offset + size2 - 1 )
  //  OR
  //    ((y is between y_offset and y_offset + size2) AND
  //     x is equal to either x_offset OR x_offset + size2 -1)
  // if so, print a *

  //if not,
  // check if EITHER
  //    x is less than size1 AND (y is either 0 or size1-1)
  // OR
  //    y is less than size1 AND (x is either 0 or size1-1)
  //if so, print a #

  //else print a space
  //when you finish counting x from 0 to w, 
  //print a newline
  int w = max(size1,(x_offset + size2));
  int h = max(size2,(y_offset + size2));
  for (int i =0;i<h;i++)
    {
      for (int j=0;j<w;j++)
	{
	  if (checkSize(j,i,x_offset,x_offset +size2,y_offset,y_offset+size2))
	    {
	      printf("*");
	    }
	  else if (checkSize(j,i,0,size1,0,size1))
	    {
	      printf("#");
	    }
	  else
	    {
	      printf(" ");
	    }

	}
      printf("\n");
    }
}

  int main(){
    squares(4,2,1,4);
    return 0;

  }








