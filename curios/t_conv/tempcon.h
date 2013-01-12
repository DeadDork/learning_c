////////////////////////////////////////////////////////////////////////////////
// Comments

// Header file for temperature conversion program t_conv.

////////////////////////////////////////////////////////////////////////////////
// Symbolic constants

#define CELS 'C'      
#define FAHR 'F'   

////////////////////////////////////////////////////////////////////////////////
// Function prototypes

int t_extract( char *in, float *temp );
/* Checks for correctness and extracts the number & scale type of temperature input string.

   *in* = the pointer to the input string. This will be checked for correct form, and will be from which the temperature value & scale type is extracted.
   *temp* = the pointer to the output temperature. This pointer will be assigned the extracted temperature value.
    
   Returns the value of the type of temperature scale. */
    
float t_conv( float *temp, int *temp_type );
/* Checks the temperature scale (i.e. Celsius or Fahrenheit), and converts the input temperature to the other temperature scale.

   *temp* = the temperature variable. 
   *temp_type* = the type of temperature scale. */
