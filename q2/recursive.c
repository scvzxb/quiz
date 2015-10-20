#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double timeCal(clock_t start, clock_t end)
{
	double time;
	time = (double) (end - start) / CLOCKS_PER_SEC;
	return time;
}



char recursive(char cmpInput, char ch[], int count)
{
	if (cmpInput < ch[count - 1]) {
		count--;
		if (count < 0) {
			return ch[0];
		}
		return recursive(cmpInput, ch, count);

	} else if (count == strlen(ch) && cmpInput >= ch[count - 1]) {
		return ch[0];
	} else  {
		return ch[count++];
	}
}


int main(int argc, char *argv[])
{
	char ch[9];
	double timespent;
	clock_t start, end;
	char cmpInput, rtnCh;
	
	strcpy(ch, argv[1]);
	cmpInput = *argv[2];
	start = clock();
	rtnCh = recursive(cmpInput, ch, 9);
	end = clock();
	timespent = timeCal(start, end);
	printf("ANS : %c\ntime spend : %lf\n", cmpInput,timespent);
	printf("the smallest characteris %c\n", rtnCh);


	return 0;
}
