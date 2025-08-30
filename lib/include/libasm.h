#ifndef __FT_LIBASM_H__
#define __FT_LIBASM_H__
#include <sys/types.h>

/**
 * @brief Find length of 'null-terminated' string
 * 
 * @param str 'null-terminated' string
 * 
 * @return length of 'null-terminated' string
 */
extern size_t   ft_strlen(const char* str);

/**
 * @brief Copy content of s2 string to s1 string
 * 
 * @param s1 destination string
 * @param s2 source 'null-terminated' string
 * 
 * @return pointer of destination string
 */
extern char *ft_strcpy(char* s1, const char* s2);

/**
 * @brief Compare two 'null-terminated' string lexically
 * 
 * @param s1 base 'null-terminated' string
 * @param s2 'null-terminated' string that compare against base
 * 
 * @return
 * 
 * - <0: s1 less than s2 lexically
 * 
 * - 0: s1 equal s2 lexically
 * 
 * - >0: s1 more than s2 lexically
 */
extern int  ft_strcmp(const char* s1, const char* s2);

/**
 * @brief Write n bytes of buffer's content to file descriptor
 * 
 * @param fd file descriptor
 * @param buff buffer
 * @param n amount of bytes
 * 
 * @return
 * 
 * - >=0: the actual bytes that IO can write to file descriptor
 * 
 * - -1: error is occured
 */
extern ssize_t  ft_write(int fd, const void* buff, size_t n);

/**
 * @brief Read n bytes from the file descriptor
 * 
 * @param fd file descriptor
 * @param buff buffer
 * @param n amount of bytes
 * 
 * @return
 * 
 * - >0: the actual bytes that IO can write to file descriptor
 * 
 * - 0: end-of-file
 * 
 * - -1: error is occured
 */
extern ssize_t  ft_read(int fd, void* buff, size_t n);

/**
 * @brief Duplicate 'null-terminated' string
 * 
 * @param str 'null-terminated' string
 * 
 * @return
 * 
 * - not null: heap allocated 'null-terminated' string
 * 
 * - null: allocation is failed
 */
extern char *ft_strdup(const char* str);

#endif
