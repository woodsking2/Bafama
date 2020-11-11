#pragma once
/**
 * @file bafama_display_hal.h
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
         *      auto & display = get_instance<Diaplay>();//provide by PCBA manufacturer
         *
         *      auto const enable_result = display->enable();
         *      Ensures(enable_result == Result::success);
         *
         *      // set display by write_command(), write_data(), deselect()
         *      // flush display memory by write_command(), write_data(), deselect()
         *
         *      auto const disable_result = display->disable();
         *      Ensures(disable_result == Result::success);
         *
         *
         * @endcode
         */
        class Diaplay : private Noncopyable<Diaplay_hal>
        {
        public:
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result write_command(gsl::span<uint8_t const> command) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result write_data(gsl::span<uint8_t const> data) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result async_write_data(gsl::span<uint8_t const> data, void (*callback)(void *), void *context) = 0;

            /**
             * @brief enable display peripheral
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result enable() = 0;

            /**
             * @brief disable display peripheral
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result disable() = 0;

            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result deselect() = 0;

        protected:
            virtual ~Diaplay() = default;
            Diaplay() = default;
        };
    } // namespace hardware_interface
} // namespace bafama
#endif
