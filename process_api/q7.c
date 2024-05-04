
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
	int rc = fork();
	if (rc < 0){
		fprintf(stderr, "fork failed");
		exit(1);
	}
	else if (rc == 0) {
		close(STDOUT_FILENO);
		printf("WOW!");
	}
	else {
		int rc_wait = wait(NULL);
	}
	return 0;
	
}	
