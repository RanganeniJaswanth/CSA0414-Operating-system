#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

bool is_page_in_frame(int page, int frames[], int n_frames) 
{
    for (int i = 0; i < n_frames; i++) 
	{
        if (frames[i] == page) 
		{
            return true;
        }
    }
    return false;
}

int fifo(int pages[], int n_pages, int n_frames) 
{
    int frames[MAX_FRAMES];
    int next_frame_index = 0;
    int page_faults = 0;

    for (int i = 0; i < n_pages; i++) 
	{
        int page = pages[i];
        if (!is_page_in_frame(page, frames, n_frames)) 
		{

            frames[next_frame_index] = page;
            next_frame_index = (next_frame_index + 1) % n_frames;
            page_faults++;
        }
    }

    return page_faults;
}

int main() 
{
    int pages[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int n_pages = 8;
    int n_frames = 3;

    printf("Page reference sequence: ");
    for (int i = 0; i < n_pages; i++) 
	{
        printf("%d ", pages[i]);
    }
    printf("\n");
    printf("No of page frames: %d\n", n_frames);

    int page_faults = fifo(pages, n_pages, n_frames);

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}