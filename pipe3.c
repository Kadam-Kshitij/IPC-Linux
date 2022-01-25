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
	if( 0 != mkfifo( fifofile, 0755 ) )
	{
		perror( "Error in creating fifo file" );
		exit( EXIT_FAILURE );
	}

	int fd = open( fifofile, O_WRONLY );

	char* buff = new char[ length ];
	for ( int i = 0; i < 5; ++i )
	{
		printf( "Enter string :\n" );
		getline( &buff, &length, stdin );
		write( fd, buff, length );
	}
}