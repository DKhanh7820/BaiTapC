#include <stdio.h>
#include <stdint.h>

typedef enum{
    TRAM = 0,
    CHUC = 2,
    DONVI = 1
}unit;

typedef enum{
    KHONG = '0',
    MOT = '1',
    HAI = '2',
    BA = '3',
    BON = '4',
    NAM = '5',
    SAU = '6',
    BAY = '7',
    TAM = '8',
    CHIN = '9'
}NUM;


uint8_t size(char number[]){
    uint8_t size = 0;
    while (*number != '\0')
    {
        number++;
        size++;
    }
    return size;  
}

void prin_Number(char number[], uint8_t i, uint8_t unit){

 switch (number[i])
 {
 case KHONG:
    if(unit == TRAM) printf("Khong ");
    else if(unit == CHUC && number[i+1] != '0') printf("Le ");  
    break;
 case MOT:
    if (unit == CHUC) printf("Muoi` ");
    else if(unit == DONVI && number[i-1] != '0' && number[i-1] != '1' && i > 0) printf("Mot' "); 
    else printf("Mot ");
    break;    
 case HAI:
    printf("Hai ");
    break;
 case BA:
    printf("Ba ");
    break;
 case BON:
    if(unit == DONVI && number[i-1] != '0' && number[i-1] != '1') printf("Tu ");
    else printf("Bon ");
    break;
 case NAM:
    if(unit == DONVI && number[i-1] != '0') printf("Lam ");
    else printf("Nam ");
    break;
 case SAU:
    printf("Sau ");
    break;
 case BAY:
    printf("Bay ");
    break;
 case TAM:
    printf("Tam ");
    break;
 case CHIN:
    printf("Chin ");
    break;          

 default:
    break;
 }
}

int main(int argc, char const *argv[])
{
    char number[] = "100000000"; //100 000 111
    uint8_t length = size(number);
    uint8_t unit = 0;
    uint8_t location;
    printf("\n");
    
    for (uint8_t i = 0; i < length; i++)
    {
       unit = (length - i) % 3;
       prin_Number(number, i, unit);

       switch (unit)
       {
       case TRAM:
        printf("Tram "); 
        break;
       case CHUC:
        if(number[i] != '0' && number[i] != '1') printf("Muoi "); 
        break;
       case DONVI:
        location = length - i;
        if(location == 10) printf("Ty ");
        else if(location == 7) printf("Trieu ");
        else if(location == 4) printf("Nghin ");
        else{ 
            printf("Dong\n\n");
            return 0;
        } 

        uint8_t  check = 0;
        uint8_t j = i+1;
        while (number[j] != '\0')
       {
        if(number[j] != '0') check++;
        j++;
       }
        if(check == 0){
        printf("Dong ");
        return 0;
       }
        break;
        
        default:
        break;
       }
    }
    
    
    return 0;
}
