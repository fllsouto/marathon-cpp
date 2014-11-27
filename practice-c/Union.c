#include <stdio.h>
#include <string.h>


/*
Union it's a special datatype that's capable to store diferents data type in the same memory segment.
You can define a Union with many member, but only one member can contain a value at any given time.

Ex:
	data.integer = 10;
	data.floating = 3.14;
	strcpy(data.text, "waka");
	
	You will get waka when you print the string but incorrect values when you put integer or float
*/
union Data{
	int integer;
	float floating;
	char text[20];
};

int main (){
	union Data data;

	printf("Uso incorreto da Union : \n");
	data.integer = 10;
	data.floating = 3.14;
	strcpy(data.text, "waka");

	printf("Data '10' != %d\n", data.integer);
	printf("Data '3.14' != %f\n", data.floating);
	printf("Data 'waka' == %s\n", data.text);	

	/**************************************************/

	printf("\nUso correto da Union : \n");
	
	data.integer = 10;
	printf("Data '10' == %d\n", data.integer);
	
	data.floating = 3.14;
	printf("Data '3.14' == %f\n", data.floating);
	
	strcpy(data.text, "waka");
	printf("Data 'waka' == %s\n", data.text);
	return 0;
}