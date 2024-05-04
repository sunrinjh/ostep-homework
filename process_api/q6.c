
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
	int rc1 = fork();
	int rc2 = fork();
	if (rc1 < 0 || rc2 < 0){
		fprintf(stderr, "fork failed");
		exit(1);
	}
	else if (rc1 == 0 || rc2 == 0) {
		printf("I am %d!\n", (int) getpid());
	}
	else {
		int rc_wait = waitpid(rc2);
		printf("Parent process done!\n");
	}
	return 0;
	
}	
