
/**
 * @brief It defines common types
 * @file types.h
 * @author Lucia Colmenarejo, Maria Barroso
 * @version 1.0
 * @date 23/09/2016
 */

#ifndef TYPES_H
#define TYPES_H

/*** Definition of public macros ***/

/**
 * @brief Definition of macro WORD_SIZE
*/

#define WORD_SIZE 300 /*character limit for names*/

/**
 * @brief Definition of macro DESC_SIZE
*/

#define DESC_SIZE 250 /*character limit for descriptions*/

/**
 * @brief Definition of macro NO_ID
*/

#define NO_ID -1 /*Value of uninitialized identifiers*/

/**
 * @brief Definition of macro ERR
*/

#define ERR -1 /*Value for error cases in funcions whose return type is integer*/

/**
 * @brief Definition of data enumeration
*/

typedef long Id;

/**
 * @brief Definition of data enumeration
*/

typedef enum {
  FALSE, TRUE
} BOOL;

/**
 * @brief Definition of data enumeration
*/

typedef enum {
    ERROR, OK
} STATUS;

/**
 * @brief Definition of data enumeration
*/

typedef enum {
    N, S, E, W
} DIRECTION;

#endif
