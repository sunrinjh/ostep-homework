
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
	int pipefd[2];
	if(pipe(pipefd) == -1){
		fprintf(stderr, "pipe creation failed");
		exit(1);
	}

	int child1pid = fork(); //Write
	if (child1pid < 0 ){
		fprintf(stderr, "fork failed");
		exit(1);
	}
	else if (child1pid == 0) {
		close(pipefd[0]);
		char inputline[99];
		scanf("%[^\n]s", &inputline);
		write(pipefd[1], inputline, strlen(inputline));
		close(pipefd[1]);
		
	}
	else {
		int child2pid = fork();
		if (child2pid < 0){
			fprintf(stderr, "fork failed");
			exit(1);
		}
		else if (child2pid ==0) {
			close(pipefd[1]);
			char buf;
			while(read(pipefd[0], &buf, 1 > 0)){
				write(STDOUT_FILENO,&buf,1);
			}
			write(STDOUT_FILENO, "\n", 1);
			close(pipefd[0]);
		}
		else {
			int rc_wait = wait(NULL);
		}
		
	}
	return 0;
	
}	
