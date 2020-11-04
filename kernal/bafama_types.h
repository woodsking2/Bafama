#pragma once
#include "bafama_port.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"

#ifdef __cplusplus
}
namespace bafama
{
    /**
     * @brief >=0 : success
     * 
     */
    enum class Result
    {
        success = 0,
        unknown_error = -1,
        wrong_param = -2,
    };
}
#endif
