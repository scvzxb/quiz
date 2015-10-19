#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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


int main()
{
	double timespent;
	clock_t start, end;
	int numLetter = 0;
	char cmpInput;
	printf("how many alphabet?\n");
	scanf(" %d", &numLetter);
	char *ch = (char*)malloc(numLetter);
	for (int i = 0; i < numLetter; i++ ) {
		scanf(" %c", &ch[i]);
	}
	scanf(" %c", &cmpInput);
	start = clock();
	cmpInput = recursive(cmpInput, ch, numLetter);
	end = clock();
	timespent = ((double) (end - start)) / CLOCKS_PER_SEC;	
	printf("ANS : %c\ntime spend : %lf\n", cmpInput,timespent);
	free(ch);

	return 0;
}
