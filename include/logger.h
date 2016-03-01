#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "singleTon.h"

class Logger {
MAKE_SINGLE_TON(Logger)
public:
	int writeFile(const char* ptr, int total_len) const;
private:
	int _fd;
	int check_fd() const;
};

#endif
