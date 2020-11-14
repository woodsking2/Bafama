#pragma once
/**
 * @file bafama_noncopyable.h
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
namespace bafama
{
    template <typename T> class Noncopyable
    {
    protected:
        Noncopyable() = default;
        ~Noncopyable() = default;

    public:
        Noncopyable(const Noncopyable &) = delete;
        Noncopyable &operator=(const Noncopyable &) = delete;
        Noncopyable(const Noncopyable &&) = delete;
        Noncopyable &operator=(const Noncopyable &&) = delete;
    };
} // namespace bafama
#endif
