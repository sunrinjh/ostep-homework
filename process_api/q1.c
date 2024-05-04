#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	int x = 100;
	printf("value of x = %d, pid:%d\n", x, getpid());
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed");
		exit(1);
	}
	else if (rc == 0){
		x--;
		printf("value of x = %d, pid:%d\n", x, getpid());
	}
	else {
		x++;
		printf("value of x = %d, pid:%d\n", x, getpid());
	}
	return 0;
}
//Result: x is not shared after changing value of x. (Fork uses copy on write.)
