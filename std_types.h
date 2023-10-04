#ifndef STD_TYPES_H
#define STD_TYPES_H

#define LOW 0
#define HIGH 1
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef char int8;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;
typedef unsigned long long uint64;
typedef long long int64;
typedef float float32;
typedef double float64;

#ifndef bool
#define bool int
#endif
#ifndef false
#define false 0u
#endif
#ifndef true
#define true 1u
#endif

#endif /*STD_TYPES_H*/