#include <stdio.h> 
/* 
The purpose of the program is to check if each line in 
a given file is less than or equal to 80 characters.
As is this program will count every character as a 
single character (even the tab character (\t), which 
attributes from 1-8 blank spaces). Thats why there is 
a tabexpand.c file, which has the sole purpose of 
expanding '\t' characters to the appropriate number of 
blank space they take up. 
*/ 

/*
Here are the prototypes to the two functions
that are in this program. 
*/
void reading_lines(void); 
void writing_lines(char letters[], int length); 

/*
This function takes every line that is given by the 
input stream, and counts the number of characters and 
stores them in a character array with length 999 (since 
there are only 999 characters allowed in a line maximum). 
Once a new line character is reached in the file, the array 
with the characters that were stored so far, and the count 
(which is also the length of the array) is passed as parameters
for the other function writing_lines(). The count variable is set 
to 0, and the loop continues until the end of the file is reached. 
*/
void reading_lines(void) {
  char c; 
  /*count keeps track of which character it is on in a line*/
  int count = 0; 
  char letters[999];  

  scanf("%c", &c); 
  /*
   this loop parses through each character in a file until it
   reaches the end of a file
  */
  while(!feof(stdin)) {
    count++; 
    letters[count-1] = c;
    /*
      the if statement checks if the loop has reached the end 
      of a line, and if it has it will call the writing_lines 
      function to print out that line in the format specified 
      in the documentation. And then it sets count back to 0. 
    */
    if(c == '\n'|| count >= 999) {
      writing_lines(letters, count);
      count = 0;  
    }
    scanf("%c", &c);
  }  
} 

/*
This line writes the output for this program 
in the way that was specified in the documentation. 
First a space or a 'X' is printed depending on whether 
that line exceeds 80 characters or not. Then it prints 
how many characters are in the line, and then it prints 
the line as it appeared in the file. 
*/
void writing_lines(char letters[], int length) {
  int size = 0; /*keeps track of the index of the array*/

  if(length <= 80) {
    printf("  "); 
  }
  else {
    printf("X "); 
  }
  
  printf("%3d: ", (length-1)); 

  while(size < length) {
    printf("%c", letters[size]); 
    size++; 
  } 
}
/*
The main method only calls the reading_lines 
function since writing_lines is 
essentially a helper method for the 
reading_lines function 
*/

int main(void) {
  reading_lines(); 

  return 0;
}
