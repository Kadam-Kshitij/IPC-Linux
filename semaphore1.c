#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

sem_t* s1;

void foo()
{
	sem_wait( s1 );
	for( int i = 0; i < 20; ++i )
	{
			std::cout << "s2 " << i << std::endl;
			sleep( 1 );
	}	
	sem_post( s1 );
}

int main()
{
	s1 = sem_open( "/mysemaphore", O_CREAT, S_IRUSR | S_IWUSR, 1);

	std::cout << "S2 - " << std::endl;
	foo();

	sem_close( s1 );
}