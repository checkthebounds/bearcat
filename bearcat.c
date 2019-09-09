#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BEARCAT "\
 ....................../´¯/) 					\n\
....................,/¯../ 						\n\
.................../..../ 						\n\
............./´¯/'...'/´¯¯`·¸ 					\n\
........../'/.../..../......./¨¯\\ 				\n\
........('(...´...´.... ¯~/'...') 				\n\
.........\\.................'...../ 			\n\
..........''...\\.......... _.·´ 				\n\
............\\..............( 					\n\
..............\\.............\\...				\n\
"

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("usage: ./bearcat files\n");
		exit(1);
	}
	char d;
	int fd;
	int i = 0;
	int nread = 0;
	int fread = 1;
	if((fd = open(argv[fread++], O_RDONLY)) == -1) {
		printf("Could not open file\n");
		exit(1);
	}
	while(BEARCAT[i] != 0) {
		char c = BEARCAT[i++];
		if(c == '8') {
			while((nread = read(fd, &d, 1)) > 0) {
				if(!(d == ' ' || d == '\t' || d == '\r' ||
				d == '\n' || d == '\x0b')) {
					printf("%c", d);
					break;
				}
			}
			if(nread == 0) {
				if(fread == argc) {
					printf("8");
				}
				else {
					close(fd);
					if((fd = open(argv[fread++], O_RDONLY)) == -1) {
						printf("\nCould not open file\n");
						exit(1);
					}
					i--;
				}
			}
		}
		else {
			printf("%c", c);
		}
		if(BEARCAT[i] == 0 && nread > 0) {
			i = 0;
		}
	}
	close(fd);
	exit(0);
}
