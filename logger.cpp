#include <stdio.h>
#include <fcntl.h> // open
#include <unistd.h> // close

#include "logger.h"

#define BUF_SIZE 256

Logger::Logger():_fd(-1) {
	char buf[BUF_SIZE];
	if(getcwd(buf, BUF_SIZE)==NULL){
		fprintf(stderr, "getcwd return NULL\n");
	}
	int len = 0;
	while(buf[len++]!='\0');
	buf[len-1] = '/';
	buf[len++] = 'l';
	buf[len++] = 'o';
	buf[len++] = 'g';
	buf[len++] = '\0';
	_fd = open(buf, O_WRONLY | O_CREAT | O_EXCL | O_FSYNC, 0644);
	if(_fd < 0) fprintf(stderr, "Logger create file fail\n");
}

Logger::~Logger(){
	if(check_fd() < 0) return ;
	_fd = close(_fd);
	if(_fd < 0) fprintf(stderr, "Logger close file fail\n");
}

int Logger::writeFile(const char* ptr, int total_len) const {
	if(check_fd() < 0) return -1;
	while(total_len > 0){
		int len = write(_fd, ptr, total_len);
		if(len<0){
			fprintf(stderr, "Logger write file descriptor %d fail\n", _fd);
			return -1;
		}
		total_len -= len;
		ptr += len;
	}
	return 0;
}

int Logger::check_fd() const {
	if(_fd < 0) {
		fprintf(stderr, "Logger file descriptor < 0\n");
		return -1;
	}
	return 0;
}


