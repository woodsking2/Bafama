#pragma once
/**
 * @file bafama_digitail_out.h
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
         *      auto const create_result = Digitail_out::create(digitail_out_pin);
         *      Ensures(create_result.first == Result::success);
         *      auto* const digitail_out = create_result.second;
         *
         *      auto const enable_result = digitail_out->enable();
         *      Ensures(enable_result == Result::success);
         *
         *      auto const get_result = digitail_out->read();
         *      Ensures(get_result.first == Result::success);
         *
         *      auto const value = get_result.second();
         *      // do some thing
         *
         *      auto const write_result = digitail_out.write(true);
         *
         *      auto const disable_result = digitail_out->disable();
         *      Ensures(disable_result == Result::success);
         *
         *      delete digitail_out;
         *
         * @endcode
         */
        class Digitail_out
        {
        public:
            /**
             * @brief create a Digitail_out instance
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            static std::pair<Result, Digitail_out *> create(int pin);

            /**
             * @brief get the implement pointer
             *        Implement by PCBA manufacturer
             *        Used by PCBA manufacturer
             */
            virtual gsl::not_null<void *> get_raw() = 0;

            /**
             * @brief true: high level
             *        low: low level
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual std::pair<Result, bool> read() = 0;

            /**
             * @brief true: high level
             *        low: low level
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result write(bool) = 0;

            virtual ~Digitail_out() override = default;

        protected:
            Digitail_out() = default;
        };
    } // namespace hardware_interface
} // namespace bafama
#endif
