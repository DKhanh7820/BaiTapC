// nhập vào ngày mong muốn VD(28,9,2023) in ra thứ ....


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
typedef struct{
 uint8_t day;
 uint8_t month;
 uint8_t year;
}Date;

typedef enum{
    T2 = 3,
    T3 = 4,
    T4 = 5,
    T5 = 6,
    T6 = 0,
    T7 = 1, 
    CN = 2
};


const char *weekofDay[] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};


const Date date = {1, 1, 2000};
Date dateCurrent = {5, 10, 2022};


// tinh so nam nhuan
bool Leapyear(int coutyear){
    
    if(!((coutyear % 4 == 0 && coutyear % 100 == 0 && coutyear % 400 != 0) || coutyear % 4 != 0)){
        return true;
        
    } else return false;
}

// tính số ngày trong 1 năm đến 1 tháng cụ thể
int result(){

    int countDay = 0;  //tính ngày
    int countYear = date.year; 

    while (1)
    {
        if(Leapyear(countYear)) countDay++;    // nếu năm nhuận thì coutday++
        if(countYear == dateCurrent.year){

            if(Leapyear(countYear)) countDay--;
            countDay = (countYear - date.year) * 365 + countDay;
            break;
        }    
         countYear++;   
    }
   
   switch (dateCurrent.month)
   {
   case 10:
    countDay = 273 + dateCurrent.day + countDay; 
    break;
   default:
    break;
   }

   if (dateCurrent.month != 1 && dateCurrent.month != 2 && Leapyear(dateCurrent.year) == 1) countDay++;
    return countDay;

}
 

int main(int argc, char const *argv[])
{
       
    int coutDay = result();
    int dayofweek = coutDay % 7;
    
    printf("To day is ");
    switch (dayofweek)
    {
    case T2:
        printf("%s", weekofDay[T2]);
        break;
    case T3:
        printf("%s", weekofDay[T3]);
        break;  
    case T4:
        printf("%s", weekofDay[T4]);
        break;     
    case T5:
        printf("%s", weekofDay[T5]);
        break;     
    case T6:
        printf("%s", weekofDay[T6]);
        break; 
    case T7:
        printf("%s", weekofDay[T7]);
        break;
    case CN:
        printf("%s", weekofDay[CN]);
        break;               
    default:
        break;
    }
    
    return 0;
    
}
