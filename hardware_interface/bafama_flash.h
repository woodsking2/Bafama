#pragma once
/**
 * @file bafama_flash.h
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
         *      auto & flash = get_instance<Flash>();//provide by PCBA manufacturer
         *
         *      auto const enable_result = display->enable();
         *      Ensures(enable_result == Result::success);
         *
         *      // do some thing
         *
         *      auto const disable_result = display->disable();
         *      Ensures(disable_result == Result::success);
         *
         *
         * @endcode
         */
        class Flash : private Noncopyable<Flash>
        {
        public:
            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result erase_sector(uint32_t address) = 0;

            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result read(uint32_t address, gsl::span<uint8_t> data) = 0;

            /**
             * @brief
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result program_sector(uint32_t address, gsl::span<uint8_t const> data) = 0;

            /**
             * @brief enable Flash peripheral
             *        Implement by PCBA manufacturer
             *        Used by application developer
             */
            virtual Result enable() = 0;

            /**
             * @brief disable Flash peripheral
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
            virtual ~Flash() = default;
            Flash() = default;
        };
    } // namespace hardware_interface
} // namespace bafama
#endif
