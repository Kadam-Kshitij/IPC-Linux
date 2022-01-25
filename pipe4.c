#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>	

size_t length = 255;
const char* fifofile = "/tmp/fifo.txt";

int main()
{
	int fd = open( fifofile, O_RDONLY );

	char* buff = new char[ length ];
	for ( int i = 0; i < 5; ++i )
	{
		read( fd, buff, length );
		printf( "%s", buff );
	}

	remove( fifofile );
}