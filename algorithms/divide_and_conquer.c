#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void merge_runs(const int *src, int *dst, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (src[i] <= src[j]) dst[k++] = src[i++];
        else                   dst[k++] = src[j++];
    }
    while (i <= mid)  dst[k++] = src[i++];
    while (j <= right) dst[k++] = src[j++];
}

void merge_sort_bottom_up(int *arr, int n) {
    if (n <= 1) return;

    int *buf = (int*)malloc(n * sizeof(int));
    if (!buf) { perror("malloc"); exit(1); }

    int *src = arr;
    int *dst = buf;

    for (int width = 1; width < n; width <<= 1) {
        for (int left = 0; left < n; left += 2*width) {
            int mid   = left + width - 1;
            int right = left + 2*width - 1;

            if (mid >= n) { 
                for (int t = left; t < n; ++t) dst[t] = src[t];
                break;
            }
            if (right >= n) right = n - 1;

    
            if (src[mid] <= src[mid + 1]) {
                for (int t = left; t <= right; ++t) dst[t] = src[t];
            } else {
                merge_runs(src, dst, left, mid, right);
            }
        }
        int *tmp = src; src = dst; dst = tmp;
    }


    if (src != arr) memcpy(arr, src, n * sizeof(int));

    free(buf);
}

int main(void){
    int array[6] = {4,9,7,2,1,8};
    merge_sort_bottom_up(array, 6);

    for (int i = 0; i < 6; i++) printf("%d ", array[i]);
    printf("\n");
    return 0;
}
