#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char *ptr;         // lưu địa chỉ kí tự đầu tiên của tên
    uint8_t length;    // độ dài của tên
    uint8_t quantily;  // số lần xuất hiện
    bool status;       // trạng thái
}words;

uint8_t sizeStr (char string[]){
    uint8_t size = 1;
    while (*string != '\0')
    {
        if (*string == ' ') size++;
        string++;
    }
    return size;
}

words* splitString(char string[], uint8_t size, words array[]){

    uint8_t count = 0;
    uint8_t index = 0;  // vi tri dia chi 
    array[index].ptr = string;

    while (*string != '\0')
    {
        if (*string == ' ')
        {
            array[index].length = count;
            count = 0;
            string++;
            index++;
            array[index].ptr = string;
        }
        else 
        {
            string++;
            count++;
        }   
    }
    array[index].length = count;

    return array;
}


void findName(words array[], uint8_t size){

    for(uint8_t i = 0; i < size; i++){
        uint8_t count = 0;
        for(uint8_t j = 0; j <size; j++){
            uint8_t index = 0;
            while (array[i].ptr[index] == array[j].ptr[index])
            {
                index++;
                if(array[i].length == index && array[j].length == index){
                   count++;
                   if(count >= 2) array[j].status = false;
                   else array[j].status = true;
                   break;
                }
            }
            index = 0;
        }
        array[i].quantily = count;
    }
}

void print(words array[], uint8_t size){

    
    for(uint8_t i = 0; i < size; i++){
        if(array[i].status == true){
        for(uint8_t j = 0; j < array[i].length; j++){
            printf("%c", array[i].ptr[j]);
        }
    printf(":\t%d\n", array[i].quantily);
       } 
    }
}




int main(int argc, char const *argv[])
{
    char string[] = "nam bao hoang nam hoang hoang yen anh yen";
    
    uint8_t size = sizeStr(string);
    
    words array[size];

    splitString(string, size, array);

    findName(array, size);

    print(array, size);
    return 0;
}
