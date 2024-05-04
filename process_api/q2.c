
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
	int fd = open("./q2.output",O_RDWR|O_TRUNC, S_IRWXU);
	int rc = fork();
	if (rc < 0){
		fprintf(stderr, "fork failed");
		exit(1);
	}
	else if (rc == 0) {
		write(fd, "Child!\n", sizeof("Child!\n"));
	}
	else {
		write(fd, "Parent!\n", sizeof("Parent!\n"));
	}
	return 0;
	
}	
//Writable
