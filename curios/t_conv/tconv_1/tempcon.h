////////////////////////////////////////////////////////////////////////////////
// Comments

// Header file for temperature conversion program t_conv.

////////////////////////////////////////////////////////////////////////////////
// Symbolic constants

#define CELS 'C'      
#define FAHR 'F'   

////////////////////////////////////////////////////////////////////////////////
// Function prototypes

int t_extract( char * in, float * temp );
/* Checks for correct form, and extracts the number & scale type of temperature input string.

   `in` = The pointer to the input string. This will be checked for correct form. The temperature value & scale type is extracted from this.
   `temp` = The pointer to the output temperature. This pointer will be assigned the extracted temperature value.
    
   Returns the type of temperature scale (Celsius or Fahrenheit). */
    
float t_conv( float * temp, int * temp_type );
/* Checks the temperature scale (i.e. Celsius or Fahrenheit), and converts the input temperature to the other temperature scale (e.g. if Celsius, it converts the temp to Fahrenheit).

   `temp` = The input temperature. 
   `temp_type` = The scale type of input temperature.
   
   Returns the value of the converted temperature. */
