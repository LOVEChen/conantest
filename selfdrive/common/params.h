#ifndef _SELFDRIVE_COMMON_PARAMS_H_
#define _SELFDRIVE_COMMON_PARAMS_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ERR_NO_VALUE -33

int write_db_value(const char* key, const char* value, size_t value_size, bool persistent_param = false);

// Reads a value from the params database.
// Inputs:
//  key: The key to read.
//  value: A pointer where a newly allocated string containing the db value will
//         be written.
//  value_sz: A pointer where the size of value will be written. Does not
//            include the NULL terminator.
//  persistent_param: Boolean indicating if the param store in the /persist partition is to be used.
//                    e.g. for sensor calibration files. Will not be cleared after wipe or re-install.
//
// Returns: Negative on failure, otherwise 0.
int read_db_value(const char* key, char** value, size_t* value_sz, bool persistent_param = false);

// Delete a value from the params database.
// Inputs are the same as read_db_value, without value and value_sz.
int delete_db_value(const char* key, bool persistent_param = false);

// Reads a value from the params database, blocking until successful.
// Inputs are the same as read_db_value.
void read_db_value_blocking(const char* key, char** value, size_t* value_sz, bool persistent_param = false);

int ui_get_params(const char* param_name, int *pValue = NULL);

#ifdef __cplusplus
}  // extern "C"
#endif

#ifdef __cplusplus
#include <map>
#include <string>
int read_db_all(std::map<std::string, std::string> *params, bool persistent_param = false);
#endif

#endif  // _SELFDRIVE_COMMON_PARAMS_H_
