#pragma once
/**
 * @file bafama_spi.h
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
         *      auto const create_result = Spi::create(clock_pin, data_pin);
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
        class Spi : private Noncopyable<Spi>
        {
        public:
            /**
             * @brief
             * mode | POL PHA
             * -----+--------
             *   0  |  0   0
             *   1  |  0   1
             *   2  |  1   0
             *   3  |  1   1
             *
             */
            enum class Mode
            {
                mode_0,
                mode_1,
                mode_2,
                mode_3,
            };
            enum class Bits
            {
                bits_8,
                bits_16,
            };
            enum class Significant_bit
            {
                msb,
                lsb,

            };
            /**
             * @brief create a Spi instance
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            static std::pair<Result, gsl::owner<Spi *>> create(int clock_pin, int data_pin);

            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result set_frequency(int hz) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result set_mode(Mode mode) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result set_bits(Bits bits) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result set_lsb(Significant_bit significant_bit) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result set(Mode mode, Bits bits, int hz, Significant_bit significant_bit) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result transfer(gsl::span<uint8_t const> tx_buffer, gsl::span<uint8_t> rx_buffer) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result async_transfer(gsl::span<uint8_t const> tx_buffer, gsl::span<uint8_t> rx_buffer, void (*callback)(gsl::not_null<Spi *>, void *), void *context) = 0;

            /**
             * @brief 
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result select() = 0;

            /**
             * @brief 
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result deselect() = 0;
            /**
             * @brief Destroy the Digitail_out object
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual ~Spi() = default;

        protected:
            Spi() = default;
        };
    } // namespace hardware_interface
} // namespace bafama
#endif
