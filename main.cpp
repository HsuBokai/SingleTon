#include <stdio.h>
#include "rand.h"

// void bar(const Rand r) // copy make compile error !!
void bar(const Rand& r){
	unsigned char c;
	r.get(&c);
	printf("in bar: %c\n", (c%26) + 'a');
	printf("%16p\n", &r);
}

void foo(){
	unsigned char c;
	Rand::instance().get(&c);
	printf("in foo: %c\n", (c%26) + 'a');
	printf("%16p\n", &Rand::instance());
}

int main(int argc , char* argv[])
{

	foo();

	unsigned char c;
	Rand::instance().get(&c);
	printf("in main: %c\n", (c%26) + 'a');
	printf("%16p\n", &Rand::instance());

	bar(Rand::instance());

	//Rand r1; // construct make compile error !!
	//Rand r2 = Rand::instance(); // copy make compile error !!

	return 0;
}

