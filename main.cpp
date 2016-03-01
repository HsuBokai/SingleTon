#include <stdio.h>

#include "rand.h"
#include "logger.h"

#define BUF_SIZE 64

// void bar(const Rand r) // copy make compile error !!
void bar(const Rand& r){
	unsigned char c;
	char buf[BUF_SIZE];
	int size;
	
	r.get(&c);
	size = sprintf(buf, "The address of Rand: %16p\n", &r);
	Logger::instance().writeFile(buf, size);

	size = sprintf(buf, "In foo, the random number: %d\n", c);
	Logger::instance().writeFile(buf, size);

	size = sprintf(buf, "The address of Logger: %16p\n", &Logger::instance());
	Logger::instance().writeFile(buf, size);
}

void foo(){
	unsigned char c;
	char buf[BUF_SIZE];
	int size;
	
	Rand::instance().get(&c);
	size = sprintf(buf, "The address of Rand: %16p\n", &Rand::instance());
	Logger::instance().writeFile(buf, size);

	size = sprintf(buf, "In foo, the random number: %d\n", c);
	Logger::instance().writeFile(buf, size);

	size = sprintf(buf, "The address of Logger: %16p\n", &Logger::instance());
	Logger::instance().writeFile(buf, size);
}

int main(int argc , char* argv[])
{

	foo();
	bar(Rand::instance());
	
	unsigned char c;
	char buf[BUF_SIZE];
	int size;
	
	Rand::instance().get(&c);
	size = sprintf(buf, "The address of Rand: %16p\n", &Rand::instance());
	Logger::instance().writeFile(buf, size);

	size = sprintf(buf, "In foo, the random number: %d\n", c);
	Logger::instance().writeFile(buf, size);

	size = sprintf(buf, "The address of Logger: %16p\n", &Logger::instance());
	Logger::instance().writeFile(buf, size);

	//Rand r1; // construct make compile error !!
	//Rand r2 = Rand::instance(); // copy make compile error !!

	printf("Logging to ./log\n");
	return 0;
}

