#pragma once
/**
 * @file bafama_digitail_in.h
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
         *      auto const create_result = Digitail_in::create(digitail_in_pin);
         *      Ensures(create_result.first == Result::success);
         *      auto* const digitail_in = create_result.second;
         *
         *      auto const enable_result = digitail_in->enable();
         *      Ensures(enable_result == Result::success);
         *
         *      auto const get_result = digitail_in->read();
         *      Ensures(get_result.first == Result::success);
         *
         *      auto const value = get_result.second();
         *      // do some thing
         *
         *      auto const disable_result = digitail_in->disable();
         *      Ensures(disable_result == Result::success);
         *
         *      auto const remove_result = Digitail_in::remove(digitail_in);
         *      Ensures(remove_result == Result::success);
         *
         * @endcode
         */
        class Digitail_in
        {
        public:
            enum class Pull_mode
            {
                none,
                down,
                up,
            };
            /**
             * @brief create a Digitail_in instance
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            static std::pair<Result, Digitail_in *> create(int pin, Pull_mode mode);

            /**
             * @brief delete a Digitail_in instance
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            static Result remove(gsl::not_null<Digitail_in *>);

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
             * @code
             */
            virtual std::pair<Result, bool> read() = 0;

        protected:
            Digitail_in() = default;
            virtual ~Digitail_in() override = default;
        };
    } // namespace hardware_interface
} // namespace bafama
#endif
