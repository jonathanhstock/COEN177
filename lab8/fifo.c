// Jonathan Stock
// fifo page replacement algorithm

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct
{ // to
    int pageno;
} ref_page;

int main(int argc, char *argv[])
{
    int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE];     // Cache that stores pages
    char pageCache[100];            // Cache that holds the input from test file

    int placeInArray = 0;
    int totalRequests = 0;
    int i;
    int totalFaults = 0; // keeps track of the total page faults

    for (i = 0; i < CACHE_SIZE; i++)
    { // initialize cache array
        cache[i].pageno = -1;
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
                break; // break out loop because found page_num in cache
            }
        }
        if (foundInCache == false)
        {
            // You may print the page that caused the page fault
            cache[placeInArray].pageno = page_num;
            totalFaults++;
            placeInArray = (placeInArray + 1) % CACHE_SIZE; // Need to keep the value within the cacheSize
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