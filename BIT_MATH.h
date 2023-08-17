/************************************************/
/* Author	: Mohamed Ibrahim  	        */
/* Date 	: 6 / 8 / 2023 		        */
/* Version 	: V01				*/
/************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR, BIT)		((VAR) |= (1 << (BIT)))	
#define CLR_BIT(VAR, BIT)		((VAR) &= ~(1 << (BIT)))
#define GET_BIT(VAR, BIT)		(((VAR) >> (BIT)) & 0X1)
#define TOG_BIT(VAR, BIT)		((VAR) ^= (1 << (BIT)))

#define ROR(VAR, SHIFTS)		((VAR) >> (SHIFTS)) | ((VAR) << sizeof(VAR) - (SHIFTS))
#define ROL(VAR, SHIFTS)		((VAR) << (SHIFTS)) | ((VAR) >> sizeof(VAR) - (SHIFTS))



#define BIT_IS_SET(VAR, BIT)	((VAR) >> (BIT)) & 0x01)
#define BIT_IS_CLEAR(VAR, BIT)	(!((VAR) >> (BIT)) & 0x01)





#endif