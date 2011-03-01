#ifndef INCLUDE_jrv_types_h__
#define INCLUDE_jrv_types_h__

/**
 * This is returned when a function executes correctly
 */
#define JRV_SUCCESS 0

/** 
 * Unspecified error for when an operation fails.
 * NOTE: This is also the base for all other error types,
 * which results that the value of all error types are less than 0.
 */
#define JRV_ERROR -1

/**
 * This is returned when the function received a parameter with the wrong type
 */
#define JRV_INVALID_TYPE (JRV_ERROR - 1)

/**
 * This is returned when a string (char *) is NULL or equals "" (empty string)
 */
#define JRV_INVALID_STRING (JRV_ERROR - 2)

/**
 * This is returned when a pointer parameter is NULL when it shouldn't be
 */
#define JRV_NULL_PTR_ERROR (JRV_ERROR - 3)

/**
 * Returns a description of the given error.
 *
 * @param error The error to get the description for
 * @return A description or "Unknown error" if no description is found
 */
char *jrv_error_description(int error);

#endif /* INCLUDE_jrv_types_h__ */
