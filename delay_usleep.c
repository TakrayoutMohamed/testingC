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

/*sleep a proccess or a thread for some time in milliseconds*/
void ft_usleep(unsigned long unbr)
{
    unsigned long   time;
    unsigned long   start;

    time = unbr * 95 / 100;
    start = get_time();
    usleep(time * 1000);
    while(1)
    {
        if (get_time() - start >= unbr)
        {
            break ;
        }
        usleep(100);
    }
}

// unbr ------ 100
// x   ------- 90
int main(void)
{
    int i;
    long start_time;
		
	// Remember when we started
    i = 0;
    start_time = get_time();

    while (10)
    {
		// Print time from start, in ms
        printf("%ld\n", get_time() - start_time);

		// Sleep 200 times 1000 microseconds (1 millisecond)
        ft_usleep(200);
        i++;
    }
}