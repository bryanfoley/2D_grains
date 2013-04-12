/*CONSTANTS*/
#define PI 3.14159265
#define MAX_ARRAY 10000

/*MATHEMATICAL MACROS*/
#define AREA(r) (PI * (r*r))

#define RADTODEG(x) ((x) * 57.29578)

#define MIN(a,b) ((a) < (b)?(a):(b))

#define MAX(a,b) ((a) < (b)?(b):(a))

/*FILE MACROS*/
#define EXISTS(filename) (!access(filename, F_OK))

/*ARRAY MACROS*/
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof(x[0]))
