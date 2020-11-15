#pragma once
/**
 * @file bafama_types.h
 * @author James Wang (woodsking2@hotmail.com)
 * @brief
 * @version 0.1
 * @date 2020-11-07
 *
 * Copyright (c) 2020 James Wang. All Rights Reserved.
 *
 */
#include "bafama_port.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "stdint.h" //!< for uint8_t, uint32_t

#define BAFAMA_DEBUG 0   //!< debugger connect, watch dog off
#define BAFAMA_DEVELOP 1 //!< debugger disconnect, watch dog off
#define BAFAMA_RELEASE 2 //!< debugger disconnect, watch dog on

#ifdef __cplusplus
}
namespace bafama
{
    constexpr auto pin_not_connected = -1;

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
} // namespace bafama
#endif
