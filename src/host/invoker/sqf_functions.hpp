﻿/*!
@file
@author Dedmen (dedmen@dedmen.de)

@brief Contains the intercept::sqf_functions class.

https://github.com/NouberNou/intercept
*/
#pragma once
#include "shared.hpp"
#include "singleton.hpp"
#include "logging.hpp"
#include "arguments.hpp"
#include "loader.hpp"
#include "shared/types.hpp"
#include <mutex>
#include <condition_variable>
#include <queue>

namespace intercept {

    namespace __internal {
        enum class functionType {
            sqf_nular,
            sqf_function,
            sqf_operator
        };

        class registered_sqf_func_wrapper {
            using GameDataType = types::__internal::GameDataType;
        public:
            registered_sqf_func_wrapper(GameDataType return_type_, __internal::gsNular* func_);
            registered_sqf_func_wrapper(GameDataType return_type_, GameDataType left_arg_type_, __internal::gsFunction* func_);
            registered_sqf_func_wrapper(GameDataType return_type_, GameDataType left_arg_type_, GameDataType right_arg_type_, __internal::gsOperator* func_);
            void setUnused();

            const functionType _type;
            const r_string _name;
            union {
                const __internal::gsNular* _nular;
                const __internal::gsFunction* _func;
                const __internal::gsOperator* _op;
            };
            const types::__internal::GameDataType _lArgType;
            const types::__internal::GameDataType _rArgType;
            const types::__internal::GameDataType _returnType;
        };
    }

    class registered_sqf_function_impl {
    public:
        registered_sqf_function_impl(std::shared_ptr<__internal::registered_sqf_func_wrapper> func_);
        /*!
        @brief Gets called when Plugin unloads. This replaces the Function that will get unloaded by a dummy function
        */
        ~registered_sqf_function_impl();

        std::shared_ptr<__internal::registered_sqf_func_wrapper> _func;
    };

    /*!
    @brief Takes care of Wrapper functions for registered SQF Functions
    */
    class sqf_functions
        : public singleton<sqf_functions> {
        friend class registered_sqf_function_impl;
    public:
        sqf_functions();
        ~sqf_functions();
        void initialize();
        using WrapperFunctionBinary = game_value*(*)(game_value*, uintptr_t, uintptr_t, uintptr_t);
        using WrapperFunctionUnary = game_value*(*)(game_value*, uintptr_t, uintptr_t);
        using WrapperFunctionNular = game_value*(*)(game_value*, uintptr_t);
        /**
         * \brief Registers a custom SQF Binary Command
         * \param name 
         * \param description 
         * \param function_ 
         * \param return_arg_type 
         * \param left_arg_type 
         * \param right_arg_type 
         * \return A wrapper that should be kept alive as long as the function should be usable
         */
        [[nodiscard]] registered_sqf_function registerFunction(std::string name, std::string description, WrapperFunctionBinary function_, types::__internal::GameDataType return_arg_type, types::__internal::GameDataType left_arg_type, types::__internal::GameDataType right_arg_type);
        /**
         * \brief Registers a custom SQF Unary Command
         * \param name 
         * \param description 
         * \param function_ 
         * \param return_arg_type 
         * \param right_arg_type 
         * \return A wrapper that should be kept alive as long as the function should be usable
         */
        [[nodiscard]] registered_sqf_function registerFunction(std::string name, std::string description, WrapperFunctionUnary function_, types::__internal::GameDataType return_arg_type, types::__internal::GameDataType right_arg_type);
        /**
         * \brief Registers a custom SQF Nular Command
         * \param name 
         * \param description 
         * \param function_ 
         * \param return_arg_type 
         * \return A wrapper that should be kept alive as long as the function should be usable
         */
        [[nodiscard]] registered_sqf_function registerFunction(std::string name, std::string description, WrapperFunctionNular function_, types::__internal::GameDataType return_arg_type);


        bool unregisterFunction(const std::shared_ptr<__internal::registered_sqf_func_wrapper>& shared);


    private:
        __internal::gsNular* findNular(std::string name) const;
        __internal::gsFunction* findUnary(std::string name, types::__internal::GameDataType argument_type) const;
        __internal::gsOperator* findBinary(std::string name, types::__internal::GameDataType left_argument_type, types::__internal::GameDataType right_argument_type) const;
        __internal::game_operators* findOperators(std::string name) const;
        __internal::game_functions* findFunctions(std::string name) const;
        sqf_register_functions _registerFuncs;
        /**
         * \brief If true then we can carelessly modify the script command tables
         */
        bool _canRegister {false};
    };

}
