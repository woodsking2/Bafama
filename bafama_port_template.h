#pragma once

/**
 * @brief print log when in isr or error
 * 
 */
#define BAFAMA_LOG_DIRECT(...)

/**
 * @brief normal print log 
 * 
 */
#define BAFAMA_LOG(...)

/**
 * @brief call when assert fail
 * 
 * @param expression 
 * @param message 
 * @param file 
 * @param line 
 */
void bafama_assert_handler(char const *const expression, char const *const message, char const *const file, int line);
