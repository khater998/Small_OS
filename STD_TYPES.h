/************************************************/
/* Author	: Mohamed Ibrahim  	        */
/* Date 	: 6 / 8 / 2023 		        */
/* Version 	: V01				*/
/************************************************/


#ifndef STD_TYPES_H
#define STD_TYPES_H

#define NULL 			((void *) 0)

typedef unsigned char 		u8;
typedef unsigned short		u16;
typedef unsigned long 	 	u32;
typedef unsigned long long 	u64;

typedef signed char 		s8;
typedef signed short		s16;
typedef signed long 	 	s32;
typedef signed long long 	s64;

typedef float			f32;
typedef double			f64;

typedef enum {
	FALSE,
	TRUE
}boolean;

#define FALSE 0
#define TRUE 1

#define STD_TYPES_NOK 0
#define STD_TYPES_OK 1



#endif
