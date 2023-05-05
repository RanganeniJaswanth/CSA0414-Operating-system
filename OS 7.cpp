#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3

int main() {
    int page_frames[MAX_FRAMES] = {0};
    int page_faults = 0;
    int num_pages = 0;
    int page_reference_sequence[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int i, j, k;

    for (i = 0; i < sizeof(page_reference_sequence)/sizeof(int); i++) {
        int page = page_reference_sequence[i];
        bool found = false;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (page_frames[j] == page) {
                found = true;
                break;
            }
        }
        if (!found) {
            page_faults++;
            int lru_frame = 0;
            int lru_count = 0;
            for (j = 0; j < MAX_FRAMES; j++) {
                int count = 0;
                for (k = i - 1; k >= 0; k--) {
                    if (page_reference_sequence[k] == page_frames[j]) {
                        break;
                    }
                    count++;
                }
                if (count > lru_count) {
                    lru_count = count;
                    lru_frame = j;
                }
            }
            page_frames[lru_frame] = page;
        }
        printf("Page reference %d: ", page);
        for (j = 0; j < MAX_FRAMES; j++) {
            if (page_frames[j] == 0) {
                printf("- ");
            } else {
                printf("%d ", page_frames[j]);
            }
        }
        printf("\n");
    }
    printf("Number of page faults: %d\n", page_faults);
    return 0;
}