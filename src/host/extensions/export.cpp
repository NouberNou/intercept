﻿#include "export.hpp"
#include "invoker.hpp"


namespace intercept {
    namespace client_function_defs {

        game_value invoke_raw_nular_nolock(const nular_function function_)
        {
            return invoker::get().invoke_raw_nolock(function_);
        }

        game_value invoke_raw_unary_nolock(const unary_function function_, const game_value & right_arg_)
        {
            return invoker::get().invoke_raw_nolock(function_, right_arg_);
        }

        game_value invoke_raw_binary_nolock(const binary_function function_, const game_value & left_arg_, const game_value & right_arg_)
        {
            return invoker::get().invoke_raw_nolock(function_, left_arg_, right_arg_);
        }

        void get_type_structure(const char *type_name_, uintptr_t &type_def_, uintptr_t &data_type_def_) {
            auto structure = invoker::get().type_structures[std::string(type_name_)];
            type_def_ = structure.first;
            data_type_def_ = structure.second;
        }

        nular_function get_nular_function(const char *function_name_) {
            nular_function function;
            if (loader::get().get_function(std::string(function_name_), function)) {
                return function;
            }
            return nullptr;
        }

        unary_function get_unary_function(const char *function_name_) {
            unary_function function;
            if (loader::get().get_function(std::string(function_name_), function)) {
                return function;
            }
            return nullptr;
        }

        unary_function get_unary_function_typed(const char *function_name_, const char *right_arg_type_) {
            unary_function function;
            if (loader::get().get_function(std::string(function_name_), function, std::string(right_arg_type_))) {
                return function;
            }
            return nullptr;
        }

        binary_function get_binary_function(const char *function_name_) {
            binary_function function;
            if (loader::get().get_function(std::string(function_name_), function)) {
                return function;
            }
            return nullptr;
        }

        binary_function get_binary_function_typed(const char *function_name_, const char *left_arg_type_, const char *right_arg_type_) {
            binary_function function;
            if (loader::get().get_function(std::string(function_name_), function, std::string(left_arg_type_), std::string(right_arg_type_))) {
                return function;
            }
            return nullptr;
        }

        void invoker_lock()
        {
            invoker::get().lock();
        }

        void invoker_unlock()
        {
            invoker::get().unlock();
        }

        const types::__internal::allocatorInfo* get_engine_allocator() {
            return loader::get().get_allocator();
        }

        registered_sqf_function register_sqf_function(std::string name, std::string description, WrapperFunctionBinary function_, types::__internal::GameDataType return_arg_type, types::__internal::GameDataType left_arg_type, types::__internal::GameDataType right_arg_type) {
            return sqf_functions::get().registerFunction(name, description, function_, return_arg_type, left_arg_type, right_arg_type);
        }

        registered_sqf_function register_sqf_function_unary(std::string name, std::string description, WrapperFunctionUnary function_, types::__internal::GameDataType return_arg_type, types::__internal::GameDataType right_arg_type) {
            return sqf_functions::get().registerFunction(name, description, function_, return_arg_type, right_arg_type);
        }
        registered_sqf_function register_sqf_function_nular(std::string name, std::string description, WrapperFunctionNular function_, types::__internal::GameDataType return_arg_type) {
            return sqf_functions::get().registerFunction(name, description, function_, return_arg_type);
        }
        std::pair<types::__internal::GameDataType, sqf_script_type> register_sqf_type(r_string name, r_string localizedName, r_string description, r_string typeName, script_type_info::createFunc cf) {
            return sqf_functions::get().registerType(name, localizedName,description, typeName, cf);
        }
    }
}