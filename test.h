#ifndef _TEST_H
#define _TEST_H

#pragma GCC diagnostic ignored "-Wpedantic"

#ifndef NO_COLOR
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[36m"
#define RESET "\033[0m"
#else
#define RED 1
#define GRN 2
#define YEL 3 
#define BLU 4
#define RESET 5
#endif

#define TEST_RESULT(x) do{\
    __test_counter++;\
    __test_passed = (__pass)? __test_passed + 1 : __test_passed;\
    __pass = (x);\
    printf(YEL "%s" RESET " line "  "%d " BLU "%s" RESET ": %s\n", \
	   __FILE__, __LINE__ , __FUNCTION__, \
	   ((!__pass) ? RED "NOT PASS" RESET : GRN "PASS" RESET));	\
  } while (0)

#define PRINT_PERCENTAGE printf("Tests passed %d%%\n", ((__test_passed * 100) / __test_counter))
      
static int __test_counter = 0;
static int __test_passed  = 0;
static int __pass = 0;

#endif