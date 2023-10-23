#include <stdio.h>
#include <stdlib.h>
/*
Hệ thống đặt phòng khách sạn:
* Tạo một struct để lưu trữ thông tin về phòng: Số phòng, Loại phòng (đơn, đôi), 
* và Trạng Thái(đã đặt, trống)
* Sử dụng union để lưu trữ giá phòng dưới dạng tiền tệ cụ thể (USD, EUR, VND) hoặc tỷ giá.
* Sử dụng con trỏ hàm để tính tổng tiền dựa trên loại tiền tệ đã chọn.
*/


#define USD 1
#define EUR 2
#define VND 3

// định nghĩa union cho Giá phòng
typedef union 
{
    double usd;
    double eur;
    double vnd;
} RoomPrice;

// định nghĩa loại phòng
typedef enum{
    SINGLED,
    DOUBLE
} RoomType;

// trạng thái của phòng
typedef enum{
    BOOKED,
    EMPTY
}RoomStatus;

// định nghĩa struct cho phòng
typedef struct{

    int RoomNumber;
    RoomType type;
    RoomStatus status;
    RoomPrice price;
    int CurrencyType;
}Room;

double getPriceInUSD(Room room){

    switch (room.CurrencyType)
    {
    case USD:
        return room.price.usd;
    case EUR:
        return room.price.eur;
    case VND:
        return room.price.vnd;
    default:
        return 0.0;
    }
}




int main(int argc, char const *argv[])
{
    Room room1 = {.RoomNumber = 1,
                  .type = SINGLED,
                  .status = BOOKED,
                  .price = 100.00,
                  .CurrencyType = VND};

    // Tính giá phòng
    double TotalVND = getPriceInUSD(room1);

    //printf("%f\n", TotalVND);        

    int RoomNumber;

    room1.RoomNumber= (int*)malloc(RoomNumber*sizeof(int));

    printf("Nhap vao so phong: ");
    scanf("%d", &RoomNumber);

    printf("\n-----------------------\n");
    return 0;
}
