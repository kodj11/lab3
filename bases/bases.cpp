#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int a = 060;
	int b = 60;
	int c = 0x60;

	printf(" C style \n ");
	printf(" symbol \t octal \t decimal \t hex \n");
	printf(" %6 c \t %5 o \t %7 d \t %3 x \n" , a , a , a , a);
	printf(" %6 c \t %5 o \t %+7 d \t %3 x \n" , b , b , b , b);
	printf(" %-6 c \t %-5 o \t %-7 d \t %-3 x \n" , c , c , c , c);

	cout << " \n C ++ style " << endl;
	cout << " symbol \t octal \t decimal \t hex " << endl;
	cout.width(6); cout <<(char) a;
	cout.width(7); cout << oct << a;
	cout.width(10); cout << dec << a;
	cout.width(4); cout << hex << a << endl;

	cout << showpos;
	cout.width(6); cout <<(char) b;
	cout.width(7); cout << oct << b;
	cout.width(10); cout << dec << b;
	cout.width(4); cout << hex << b << endl;

	cout << noshowpos << left;
	cout.width(8); cout <<(char) c;
	cout.width(8); cout << oct << c;
	cout.width(8); cout << dec << c;
	cout.width(3); cout << hex << c << endl;

	return 0;
}
