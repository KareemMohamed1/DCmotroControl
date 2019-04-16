/*
 ============================================================================
 Name        : datatypes.h
 Author      : kareem mohamed
 Description : define the used data types  in embedded programming
 Date        : 14/4/2019
 ============================================================================
 */
#ifndef DATATYPES_H_
#define DATATYPES_H_
/*
 *  define the logical values for true , false , and logical high and low
 */
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef LOW
#define LOW 0
#endif

#ifndef HIGH
#define HIGH 1
#endif
/*
 * define standard types in C for embedded applications
 */
typedef unsigned char bool;         // it should contain logical values , true or false
typedef unsigned char uint8 ;	    // type contain values from 0 to 255
typedef signed char sint8;			// type contains value from -127 to 128
typedef unsigned short uint16;		// type contains value from 0 to 65536
typedef signed short sint16;		// type contains values from -32767 to 32768
typedef unsigned long uint32;
typedef signed long  sint32;
typedef unsigned long long uint64 ;
typedef signed long long sint64 ;
typedef float float32;
typedef double float64;

#endif /* DATATYPES_H_ */
