#pragma once
/**
 * @file bafama_i2c.h
 * @author James Wang (woodsking2@hotmail.com)
 * @brief
 * @version 0.1
 * @date 2020-11-06
 *
 * Copyright (c) 2020 James Wang. All Rights Reserved.
 *
 */
#include "bafama_port.h"
#include "bafama_types.h"
#include "gsl/gsl"
#ifdef __cplusplus
namespace bafama
{
    namespace hardware_interface
    {
        /**
         * @code
         *      auto const create_result = I2c::create(clock_pin, data_pin);
         *      Ensures(create_result.first == Result::success);
         *      auto* const i2c = create_result.second;
         *
         *      auto const enable_result = i2c->enable();
         *      Ensures(enable_result == Result::success);
         *
         *      // do some thing by read(),write(),read_register(),write_register()
         *
         *      auto const disable_result = i2c->disable();
         *      Ensures(disable_result == Result::success);
         *
         *      delete i2c;
         *
         * @endcode
         */
        class I2c : private Noncopyable<I2c>
        {
        public:
            /**
             * @brief create a I2c instance
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            static std::pair<Result, gsl::owner<I2c *>> create(int clock_pin, int data_pin);
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result read(int address_7_bit, gsl::span<uint8_t> data, bool repeated) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result write(int address_7_bit, gsl::span<uint8_t const> data, bool repeated) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result read_register(int address_7_bit, gsl::span<uint8_t const> reg, gsl::span<uint8_t> data) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result write_register(int address_7_bit, gsl::span<uint8_t const> reg, gsl::span<uint8_t const> data) = 0;

            /**
             * @brief enable I2c peripheral
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result enable() = 0;

            /**
             * @brief disable I2c peripheral
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result disable() = 0;
            /**
             * @brief Destroy the Digitail_out object
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual ~I2c() = default;

        protected:
            I2c() = default;
        };
    } // namespace hardware_interface
} // namespace bafama
#endif
