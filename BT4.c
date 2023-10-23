#include <stdio.h>
#include <stdint.h>


uint8_t SizeText(char text[]){
    
    uint8_t count = 0;

    while (*text != '\0')
    {
        count++;
        text++;
    }
    return count;
}
void capital_letters(char string[]){

  while (*string != '\0')
  {
    if(*string == '.')
    {
      string++;
      while (*string != '\0')
      {
        if(*string == ' ') string++;
        *string = *string - 32;
        string++;
      }
      return;
    }
    string++;
  }
} 
void find_Text(char string[], char text[]){
  uint8_t i = 0;
  uint8_t j = 0;
  uint8_t k = 0;

  while (string[i] != '\0')
  {
    k = i;
    while (string[k] == text[j])
    {
      k++;
      j++;
      if(text[j] == '\0'){
        printf("Co\nVi tri: %d\n", i);
        return;
      }
    }
    j = 0;
    i++;
  }
  printf("Khong co");
}

void find_replace(char string[], char text1[], char text2[]){
 
 uint8_t i = 0;
 uint8_t j = 0;

 while (string[j] != '\0')
 {
  if(string[j] == text1[i]){
    i++;
    if(text1[i] == '\0') {
      break;
    }
    }else if(i > 0){
      i = 0;
      j--;
    }
    j++;
 }
 if(text1[i] != '\0')
 {
  printf("khong co");
  return;
 }

 uint8_t location_First = j - i + 1;
 uint8_t location_Final = j;
 uint8_t length_String = SizeText(string);
 uint8_t length_update = SizeText(string) - SizeText(text1) + SizeText(text2);
 

 if(length_update > length_String){

  string[length_update] = '\0';
  length_update--;
  length_String--;
  while(length_update > location_First + SizeText(text2) - 1){
    string[length_update] = string[length_String];
    length_String--;
    length_update--;
  }

  while (*text2 != '\0')
  {
    string[location_First] = *text2;
    location_First++;
    text2++; 
  }
  
 }else {
 
        while (*text2 != '\0')
        {
          string[location_First] = *text2;
          location_First++;
          text2++;
        }
        location_Final++;

        while (location_First < length_update)
        {
          string[location_First] = string[location_Final];
          location_First++;
          location_Final++;
        }
        string[length_update] = '\0';
       }
}



int main(int argc, char const *argv[]){

    char string[] = "to learn around the world learn how to do anything. today we learn about that!";
    //yêu cầu 1: to learn around the world learn how to do anything. TODAY WE LEARN ABOUT THAT!
    //yêu cầu 2: Text: anything               | Text: abc
    //           Kết quả: Co                  | Kết quả: Không có
    //           vị tri: 42                   |
    //yêu cầu 3: "ab that" -> "about that" (tìm "ab that" nếu có thì thay thế thành "about that")
    //            to learn about the world learn how to do anything. today we learn about that              
     
    // capital_letters(string);
    //find_Text(string, "around");
    find_replace(string, "anything", "the world learn");
    
    printf("\n%s\n\n", string);
    return 0;
}
