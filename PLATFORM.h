#ifndef PLATFORM_H
#define PLATFORM_H
#define CPU_TYPE_8  8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
/**************************/
#define CPU_TYPE CPU_TYPE_64
/**************************/
#if (CPU_TYPE==64)
typedef unsigned char u8;
typedef unsigned char boolean;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
#elif (CPU_TYPE==32)
typedef unsigned char u8;
typedef unsigned char boolean;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;
typedef double f64;
#elif (CPU_TYPE==16)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;
typedef double f64;
#elif (CPU_TYPE==8)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;
typedef double f64;	
#endif //End Of #If
#endif //End Of File Guard