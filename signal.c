#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>	

size_t length  = 255;	
const char* file = "/tmp/pid.txt";

char* itoa( int val, int base 	)
{	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}

void foo()
{
	printf( "FOO" );
	exit( EXIT_FAILURE );
}

int main()
{
	int fd = open( file, O_WRONLY );
	
	pid_t pid = getpid();

	char* buff;	
	buff = itoa( pid, 10 );
	
	printf( "%s\n", buff );
	write( fd, buff, length );

	close( fd );

	signal( SIGINT, foo ); // SIG_ING, SIG_DFL

	while( 1 )
	{
		printf( "Still alive\n" );
		sleep(1);		
	}
}