// Jonathan Stock
// lru page replacement algorithm

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

typedef struct
{ // to
    int pageno;
} ref_page;

int main(int argc, char *argv[])
{
    int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE];     // Cache that stores pages
    char pageCache[100];            // Cache that holds the input from test file
    int time_arr[CACHE_SIZE];

    // int placeInArray = 0;
    int totalRequests = 0;
    int i;
    int totalFaults = 0; // keeps track of the total page faults
    int seconds = 1;

    for (i = 0; i < CACHE_SIZE; i++)
    { // initialize cache array
        cache[i].pageno = -1;
        time_arr[i] = ++seconds;
    }

    while (fgets(pageCache, 100, stdin))
    {
        int page_num = atoi(pageCache); // Stores number read from file as an int

        bool foundInCache = false;
        totalRequests++;
        for (i = 0; i < CACHE_SIZE; i++)
        {
            if (cache[i].pageno == page_num)
            {
                foundInCache = true;
                time_arr[i] = ++seconds;
                break; // break out loop because found page_num in cache
            }
        }
        if (foundInCache == false)
        {
            // You may print the page that caused the page fault
            int temp = time_arr[0];

            int tempindex = 0;
            for (i = 1; i < CACHE_SIZE; i++)
            {
                if (time_arr[i] < temp)
                {
                    temp = time_arr[i];
                    tempindex = i;
                }
            }
            cache[tempindex].pageno = page_num;
            time_arr[tempindex] = ++seconds;
            totalFaults++;
        }
    }
    float hitrate = ((totalRequests - totalFaults) / (double)totalRequests);
    float missrate = (1 - ((totalRequests - totalFaults) / (double)totalRequests));
    printf("%d Total Page Faults\n", totalFaults);
    printf("%d Total Number of Requests\n", totalRequests);
    printf("%f Hit Rate\n", hitrate);
    printf("%f Miss Rate\n", missrate);
    return 0;
}