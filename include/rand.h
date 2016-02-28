#ifndef _RAND_H_
#define _RAND_H_

#include "singleTon.h"

class Rand {

MAKE_SINGLE_TON(Rand)

public:
	int get(unsigned char buf[]) const;
private:
	int _fd;
	int check_fd() const;
};

#endif
