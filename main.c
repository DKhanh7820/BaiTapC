#include <stdio.h>
#include <stdint.h>


void arrage(int array[], uint8_t size){

    for (uint8_t i = 0; i < size - 1; i++)
    {
        int temp = i;
        for (uint8_t j = i + 1; j < size; j++)
        {
            if(array[j] < array[temp]){
                temp = j;
            }
        }
        int a = array[i];
        array[i] = array[temp];
        array[temp] = a;
    }
    
}

void print(int array[], uint8_t size){

  printf("\nValue\t:");
  for(uint8_t i = 0; i < size; i++){
    printf("  %d", array[i]);
  }

  printf("\nVi tri\t:");
  for(uint8_t i = 0; i < size; i++){
    if((array[i] / 10) != 0) printf("  %d ", i);
    else printf("  %d", i);
  }

}

int binary_Search(int arr[], int left, int right, int target){

    while (left <= right)
    {
        
        int mid = left + (right - left)/2;
        
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1; 
    }
    return -1;
    
}

int main(int argc, char const *argv[])
{
    int array[10] = {5, 8, 1, 43, 61, 24, 16, 37, 2, 80};

    uint8_t size = sizeof(array)/sizeof(array[0]);

    arrage(array, size);

    print(array, size);

    int target = 37;
    int index = binary_Search(array, 0, size - 1, target);

    if(index != -1) printf("\n%d Tai vi tri: %d", target, index);
    else printf("%d Khong ton tai", target);

    return 0;
}
