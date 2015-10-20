/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char smallest_character(char cmpInput, char *str)
{
	int len;
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (cmpInput < str[i])return str[i];
	}
	return str[0];
}

double timeCal(clock_t start, clock_t end)
{
	double time;
	time = (double) (end - start) / CLOCKS_PER_SEC;
	return time;
}


int main(int argc, char *argv[])
{
	char str[9];
	char rtnCh;
	char cmpInput;
	clock_t start, end;
	double timespend;

	strcpy(str, argv[1]);
	cmpInput = *argv[2];
	start = clock();
	rtnCh = smallest_character(cmpInput, str);
	end = clock();
	timespend = timeCal(start, end);
	printf("ANS : %c\ntime spend : %lf\n", cmpInput, timespend);
	printf("the smallest characteris %c\n", rtnCh);

	return 0;
}
