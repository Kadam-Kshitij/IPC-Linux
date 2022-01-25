#include <stdio.h>
#include <unistd.h>

size_t length = 255;

int main()
{
	int pipefd[2];

	pipe( pipefd );

	pid_t pid = fork();	

	if ( 0 == pid )
	{
		// Child
		close( pipefd[0] );
		sleep(2);
		const char* msg = "Message from child";
		write( pipefd[1], msg, length );
	}
	else
	{
		// Parent
		close( pipefd[1] );
		char buff[length];
		printf( "Parent : Waiting for message\n");
		read( pipefd[0], buff, length );
		printf( "%s\n", buff );
	}
}