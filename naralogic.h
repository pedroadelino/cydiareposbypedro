#include <string.h>

int colorprint(char *message, char *color){
   if (strcmp(color, "red") == 0)
   {
      printf("\033[1;31m"); // Red color
   } else
   if (strcmp(color, "yellow") == 0)
   {
      printf("\033[1;33m"); // Yellow color
   } else
   if (strcmp(color, "green") == 0)
   {
      printf("\033[1;32m"); // Green color
   } else
   if (strcmp(color, "blue") == 0)
   {
      printf("\033[1;34m"); // Blue color
   }   
   printf("%s", message);
   printf("\033[0m"); // Reset color
   return 0;
}

int colorprinti(int message, char *color){
   if (strcmp(color, "red") == 0)
   {
      printf("\033[1;31m"); // Red color
   } else
   if (strcmp(color, "yellow") == 0)
   {
      printf("\033[1;33m"); // Yellow color
   } else
   if (strcmp(color, "green") == 0)
   {
      printf("\033[1;32m"); // Green color
   } else
   if (strcmp(color, "blue") == 0)
   {
      printf("\033[1;34m"); // Blue color
   }   
   printf("%d", message);
   printf("\033[0m"); // Reset color
   return 0;
}