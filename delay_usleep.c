#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

/*
** Returns the timestamp in milliseconds
*/

long    get_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000;
    return (milliseconds);
}

/*
** Prints time, sleeps 200ms, repeats!
*/

int main(void)
{
    int i;
    long start_time;
		
	// Remember when we started
    i = 0;
    start_time = get_time();

    while (i < 10)
    {
		// Print time from start, in ms
        printf("%ld\n", get_time() - start_time);

		// Sleep 200 times 1000 microseconds (1 millisecond)
        usleep(200 * 1000);
        i++;
    }
}