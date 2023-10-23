#include <stdint.h>
#include <stdio.h>

uint8_t Sizeofstring(char string[]){
    
    uint8_t size = 1;

    while (*string != '\0')
    {
        if(*string == ' ') size++;
        string++;
    }
    return size;
}
void daotu(char string[]){

  uint8_t size = Sizeofstring(string);
  uint8_t index = 0;
  char *arr[size];

  arr[index] = string;

  while (*string != '\0')
  {
    if (*string == ' ')
    {
        string++;
        index++;
        arr[index] = string;        
    }
    else string++;
  }
  

  for(int8_t i = index; i >= 0; i--){
    while (*arr[i] != '\0' && *arr[i] != ' ')
    {
        printf("%c", *arr[i]);
        arr[i]++;
    }
    printf(" ");
  }
}

int main(int argc, char const *argv[])
{

    // thay đổi vị trí tên trong chuỗi.
    char string[] = "nhat hoang tuan nam nhat hoang nhat nam bao quoc nam";
     

   daotu(string);
  
   
    return 0;
}
