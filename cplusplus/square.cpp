#include <iostream>
using namespace std; //It's like an alias

double square(int x){
	return x*x;
}

void print_square(int x){
	cout << "The square of " << x << " is : " << square(x) << " \n";
}

int main(){
	print_square(42);
	return 0;
}