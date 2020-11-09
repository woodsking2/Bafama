#pragma once
/**
 * @file bafama_pwm_out.h
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
         *      auto const create_result = Pwm_out::create(pin);
         *      Ensures(create_result.first == Result::success);
         *      auto* const pwm_out = create_result.second;
         *
         *      auto const enable_result = pwm_out->enable();
         *      Ensures(enable_result == Result::success);
         *
         *      // set pwm with period_seconds() or pulse_width_seconds()
         *      // cotrol pwm by write()
         *
         *      auto const disable_result = pwm_out->disable();
         *      Ensures(disable_result == Result::success);
         *
         *      delete pwm_out;
         *
         * @endcode
         */
        class Pwm_out : private Noncopyable<Pwm_out>
        {
        public:
            /**
             * @brief create a Pwm_out instance
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            static std::pair<Result, gsl::owner<Pwm_out *>> create(int pin);
            /**
             * @brief 0.0f (representing on 0%) and 1.0f (representing on 100%).
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result write(float value) = 0;
            /**
             * @brief 0.0f (representing on 0%) and 1.0f (representing on 100%).
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual std::pair<Result, float> read() = 0;

            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result period_seconds(float seconds) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result period_milliseconds(int milliseconds) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result period_microseconds(int microseconds) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result pulse_width_seconds(float seconds) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result pulse_width_milliseconds(int milliseconds) = 0;
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result pulse_width_microseconds(int microseconds) = 0;

            /**
             * @brief Destroy the Digitail_out object
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual ~Pwm_out() = default;

        protected:
            Pwm_out() = default;
        };
    } // namespace hardware_interface
} // namespace bafama
#endif
