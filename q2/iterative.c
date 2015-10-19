/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char smallest_character(char cmpInput, char *ch)
{
	int len;
	len = strlen(ch);
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		if (cmpInput < ch[i])return ch[i];
	}
	return ch[0];
}


int main()
{
	int numLetter = 0;
	char rtnCh;
	char cmpInput;
	time_t start, end;
	double timespend;


	printf("how many alphabet?\n");
	scanf("%d", &numLetter);
	getchar();
	char ch[20] = {0};
	for (int i = 0; i < numLetter; i++ ) {
		scanf("%c", &ch[i]);
		getchar();
	}
	printf("enter a character\n");
	scanf("%c", &cmpInput);
	getchar();

	start = clock();
	rtnCh = smallest_character(cmpInput, ch);
	end = clock();
	timespend = (double) (end - start) / CLOCKS_PER_SEC;
	printf("ANS : %c\ntime spend : %lf\n", cmpInput, timespend);
	printf("the smallest characteris %c\n", rtnCh);

	return 0;
}
