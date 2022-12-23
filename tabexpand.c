#include <stdio.h> 
/*
The purpose of the program is to find tab characters 
(\t), and expand them to the appropriate amount of 
spaces. Since tab can account from 1-8 spaces depending 
on how many characters preceded the tab character 
*/

/*
These are the prototypes of the two functions 
that are being used in this program 
*/
void expand(void); 
void output(char letters[], int length); 

/*
This function expand(void) tries to 
find the '\t' characters in the file and expands 
them appropriately depending on the characters that 
were before the '\t' character. 
*/
void expand(void) {
  int count = 0; /*index in an array*/ 
  char letters[999]; 
  char c;  

  scanf("%c", &c);  
  /*
   the loop goes through all the characters in
   the file 
   */
  while(!feof(stdin)) {
    /*
      this if statement checks if the character 
      that is being read is a tab character. If a
      tab character is read then it will calculate
      how many spaces the tab character represents 
     */
    if(c == '\t') {
      int spaces = 8 - (count % 8); 
      /*
       this loop adds the proper number of spaces 
       that was calculated
       */
      while(spaces > 0) {
	letters[count] = ' '; 
	count++; 
	spaces--; 
      }

    }
    /*
      if a new line character was read then the 
      output function is called, and count is
      reset back to 0. Also the same procedure 
      occurs if 999 characters or more were read. 
      Since a line can only hold 999 characters 
     */
    else if(c == '\n' || count >= 999) {
      output(letters, count); 
      count = 0; 
    }
    /*
      this is a character that is not a new line 
      or a tab is read, which in that case the 
      character 'c' will be added to the array, 
      and count will be incremented. 
     */
    else {
      letters[count] = c;
      count++; 
    } 
    
    scanf("%c", &c); 
  }
}

/*
The function output(char letters[], int length), 
is a helper method of expand(). Once a line is properly 
expanded and the method either reaches the new line character
in the line or the line reaches 999 characters, this method 
is called to print out what is in the array. 
*/
void output(char letters[], int length) {
  int size = 0; /*keeps track of the index in the array*/ 
  /*
    this loop just goes through the array and prints 
    all the characters that are in it. 
   */
  while(size < length) {
    printf("%c", letters[size]); 
    size++; 
  }
  printf("\n"); 
}

int main(void) {
  expand(); 
  return 0;
}
