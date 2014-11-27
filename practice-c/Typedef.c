#include <stdio.h>

/*
Typedef gives a new name for a given datatype

Ex:

typedef unsigned char FOO;

now I can create a variable called:

FOO foo1;

That will be an unsigned char, called though this ~typedef alias~
*/

typedef struct Point{
	int x;
	int y;
} CartesianPoint;

//In example above I declared struct Point as a new datatype and I gave a new "label" for it as Cartesian Point

int main (){
	CartesianPoint point1;

	point1.x = 1;
	point1.y = 2;

	printf("(X,Y) :: (%d,%d)\n", point1.x, point1.y);

	return 0;
}