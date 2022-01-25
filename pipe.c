#include <stdio.h>
#include <unistd.h>

size_t length = 255;
const char* message = "This is a message";

int main()
{
	int pipefd[2];

	pipe( pipefd );

	write( pipefd[1], message, length );

	char buff[length];
	read( pipefd[0], buff, length );
	printf( "%s\n", buff );
}
