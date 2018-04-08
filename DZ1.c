#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

static int charlen(const char*);

int main (int argc, char* argv[]) {

	if (argc!=2) {
		printf("Wrong program call\n");
		return EXIT_FAILURE;
	}

	if (strlen(argv[1])>PATH_MAX) {
		printf("Wrong path\n");
		return EXIT_FAILURE;
	}

	int pcap=sizeof(int);
	int ncap = sizeof(int); 
	int pcounter=0;
	int ncounter=0;
	int *positive=(int*)malloc(pcap);
	int *negative=(int*)malloc(ncap);
	int zeros=0;

	FILE *r=fopen (argv[1],"r");
	if (!r) {
		printf("File open failure\n");
		return EXIT_FAILURE;
	}

	int temp=0;

	while ((fscanf(r,"%d",&temp)) != EOF) {

		if (temp>0) { 
			if (pcounter*sizeof(int)==pcap) {
				pcap*=2;
				positive=(int*)realloc(positive,pcap);
			}
			positive[pcounter]=temp;
			++pcounter;
		}

		if (temp<0) { 
			if (ncounter*sizeof(int)==ncap) {
				ncap*=2;
				negative=(int*)realloc(negative,ncap);
			}
			negative[ncounter]=temp;
			++ncounter;
		}

		if (temp==0) zeros++;
	}

	fclose(r);
	FILE *w=fopen (argv[1],"w");

	for	(int i=0; i < zeros; i++) {
		fprintf(w,"%d ", 0);
	}

	for	(int i=0; i<ncounter ; i++) {
		fprintf(w,"%d ",negative[i]);
	}

	for	(int i=0; i<pcounter ; i++) {
		fprintf(w,"%d ",positive[i]);
	}

	fclose(w);

	free(positive);
	free(negative);

	return EXIT_SUCCESS;
}

static int charlen(const char * str) {
	int i;
	for (i=0; str[i] != '\0'; ++i) {};
	return i;
}

//valgrind --tool=memcheck --leak-check=full ./a.out arg1 arg2 ...
