#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void islp(int i);
void dslp(double d);

int main(void)
{
	int cycle = 1;
	while (1)
	{

		cycle ? system("figlet HELLO") : system("figlet BRO");
		dslp(0.15);

		cycle = cycle ? 0 : 1;
	}
	return 0;
}

void islp(int i)
{
	fflush(stdout);
	struct timespec ts = {i, 0};
	nanosleep(&ts, NULL);
}

void dslp(double d)
{
	fflush(stdout);
	struct timespec ts = {0, (1000000000 * d) - 1};
	nanosleep(&ts, NULL);
}
