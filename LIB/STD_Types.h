#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_


typedef unsigned char             u8  ;
typedef unsigned short int        u16 ;
typedef unsigned long int         u32 ;
typedef signed char               s8  ;
typedef signed short int          s16 ;
typedef signed long int           s32 ;
typedef float                     f32 ;
typedef double                    f64 ;
typedef long double               f128;
typedef unsigned long long int    u64 ;

/*user expected errors*/
typedef enum {
	FUN_OK,
	FUN_NOK,
	PARAM_OUT_OF_RANGE ,

}enuErrorStatus;

#define STD_TYPE_OK     1
#define STD_TYPE_NOK    0

#define STD_TYPE_NULL   ((void*)0)


#endif /* LIB_STD_TYPES_H_ */
