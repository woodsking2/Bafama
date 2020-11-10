#pragma once
/**
 * @file bafama_interrupt_in.h
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
#include "bafama_digitail_in.h"
#ifdef __cplusplus
namespace bafama
{
    namespace hardware_interface
    {
        /**
         * @code
         *      void rise_in(gsl::not_null<Interrupt_in *> interrupt_in, void * pointer)
         *      {
         *          auto * const context = reinterpret_cast<Context*>(pointer);
         *          auto const get_result = interrupt_in->read();
         *          Ensures(get_result.first == Result::success);
         *
         *          auto const value = get_result.second(); // voltage level
         *
         *          auto const disable_result = interrupt_in->disable(); //stop interrupt_in
         *      }
         *
         *      int main()
         *      {
         *          auto const create_result = Interrupt_in::create(digitail_in_pin);
         *          Ensures(create_result.first == Result::success);
         *          auto* const interrupt_in = create_result.second;
         *
         *          auto const enable_result = interrupt_in->enable();
         *          Ensures(enable_result == Result::success);
         *
         *          static Context context{}; // store context
         *          auto cosnt set_rise_result = interrupt_in->set_rise_callback(rise_in, &context);
         *      }
         *
         * @endcode
         */
        class Interrupt_in : public virtual Digitail_in
        {
        public:
            /**
             * @brief create a Interrupt_in instance
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            static std::pair<Result, gsl::owner<Interrupt_in *>> create(int pin, Pull_mode mode);

            /**
             * @brief
             *        callback FromISR or Thread Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result set_rise_callback(void (*callback)(gsl::not_null<Interrupt_in *>, void *), void *context) = 0;
            /**
             * @brief
             *        callback FromISR or Thread Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result set_fall_callback(void (*callback)(gsl::not_null<Interrupt_in *>, void *), void *context) = 0;
            /**
             * @brief enable Interrupt_in peripheral
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result enable() = 0;

            /**
             * @brief disable Interrupt_in peripheral
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result disable() = 0;

            /**
             * @brief Destroy the Digitail_out object
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual ~Interrupt_in() = default;

        protected:
            Interrupt_in() = default;
        };
    } // namespace hardware_interface
} // namespace bafama
#endif
