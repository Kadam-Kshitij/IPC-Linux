#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

size_t length = 255;
const char* pidfile = "/tmp/pid.txt";

int main()
{
	int fd = open( pidfile, O_RDONLY );
	
	char buff[length];
	read( fd, buff, length );

	int pid = atoi( buff );

	kill( pid, SIGINT );
}