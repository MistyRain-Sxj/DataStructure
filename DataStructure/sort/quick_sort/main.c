#include <stdio.h>

int quickSort(int* nums, int low, int height){
    int point = nums[low];
    while(low < height){
        while(low < height && nums[height] >= point){
            height--;
        }
        nums[low] = nums[height];

        while(low < height && nums[low] <= point){
            low++;
        }
        nums[height] = nums[low];
    }
    nums[low] = point;
    return low;
}

void sortMain(int* nums, int low, int height){
    if(low < height){
        int midPos = quickSort(nums, low, height);
        sortMain(nums, low, midPos-1);
        sortMain(nums, midPos+1, height);
    }
}

int main() {
    int a[] = {24, 1, 4, 23 , 2, 24, 11, 15, 33};
    sortMain(a, 0, ((sizeof(a)/sizeof(int))-1));
    for(int i = 0; i <= 8; i++){
        printf("%d,",a[i]);
    }
    return 0;
}
