#pragma once
/**
 * @file bafama_analog_in.h
 * @author James Wang (woodsking2@hotmail.com)
 * @brief
 * @version 0.1
 * @date 2020-11-04
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
         *      auto const create_result = Analog_in::create(analog_in_pin);
         *      Ensures(create_result.first == Result::success);
         *      auto* const analog_in = create_result.second;
         *
         *      auto const enable_result = analog_in->enable();
         *      Ensures(enable_result == Result::success);
         *
         *      auto const get_result = analog_in->read();
         *      //auto const get_result = analog_in->read_raw();
         *      Ensures(get_result.first == Result::success);
         *
         *      auto const value = get_result.second();
         *
         *      // do some thing
         *      auto const disable_result = analog_in->disable();
         *      Ensures(disable_result == Result::success);
         *
         *      auto const remove_result = Analog_in::remove(analog_in);
         *      Ensures(remove_result == Result::success);
         *
         * @endcode
         */
        class Analog_in
        {
        public:
            /**
             * @brief create a Analog_in instance
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            static std::pair<Result, Analog_in *> create(int pin);

            /**
             * @brief delete a Analog_in instance
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            static Result remove(gsl::not_null<Analog_in *>);

            /**
             * @brief get the implement pointer
             *        Implement by PCBA manufacturer
             *        Used by PCBA manufacturer
             */
            virtual gsl::not_null<void *> get_raw() = 0;

            /**
             * @brief float, unit V, 3.3f means 3.3V
             *        Implement by PCBA manufacturer
             *        Used by application developer
             * @code
             */
            virtual std::pair<Result, float> read() = 0;

            /**
             * @brief raw_data, 0 - UINT32_MAX, unit defined by PCBA manufacturer
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual std::pair<Result, uint32_t> read_raw() = 0;

            /**
             * @brief enable analog_in peripheral
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result enable() = 0;

            /**
             * @brief disable analog_in peripheral
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result disable() = 0;

        protected:
            Analog_in() = default;
            virtual ~Analog_in() override = default;
        };
    } // namespace hardware_interface
} // namespace bafama
#endif
