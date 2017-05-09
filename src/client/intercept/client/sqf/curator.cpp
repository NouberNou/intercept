﻿#include "curator.hpp"
#include "client\pointers.hpp"
#include "common_helpers.hpp"

namespace intercept {
    namespace sqf {
        /* Curator */
        object curator_camera() {
            return __helpers::__retrieve_nular_object(client::__sqf::nular__curatorcamera__ret__object);
        }

        object curator_mouse_over() {
            return __helpers::__retrieve_nular_object(client::__sqf::nular__curatormouseover__ret__object);
        }

        std::vector<object> curator_selected() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__curatorselected__ret__array));
        }

        void open_curator_interface() {
            __helpers::__empty_nular(client::__sqf::nular__opencuratorinterface__ret__nothing);
        }

        bool shown_curatorcompass() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__showncuratorcompass__ret__bool);
        }

        float curator_camera_area_ceiling(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__curatorcameraareaceiling__object__ret__scalar, value_);
        }

        bool curator_editing_area_type(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__curatoreditingareatype__object__ret__bool, value_);
        }

        float curator_points(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__curatorpoints__object__ret__scalar, value_);
        }

        float curator_waypoint_cost(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__curatorwaypointcost__object__ret__scalar, value_);
        }

        object get_assigned_curator_logic(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__getassignedcuratorlogic__object__ret__object, value_);
        }

        object get_assigned_curator_unit(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__getassignedcuratorunit__object__ret__object, value_);
        }

        void remove_all_curator_addons(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__removeallcuratoraddons__object__ret__nothing, value_);
        }

        void remove_all_curator_camera_areas(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__removeallcuratorcameraareas__object__ret__nothing, value_);
        }

        void remove_all_curator_editing_areas(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__removeallcuratoreditingareas__object__ret__nothing, value_);
        }

        void show_curator_compass(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__showcuratorcompass__bool__ret__nothing, value_);
        }

        void unassign_curator(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__unassigncurator__object__ret__nothing, value_);
        }

        void add_curator_points(const object &value1_, float value0_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__addcuratorpoints__object__scalar__ret__nothing, value0_, value1_);
        }

        void allow_curator_logic_ignore_areas(const object &value1_, bool value0_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__allowcuratorlogicignoreareas__object__bool__ret__nothing, value0_, value1_);
        }
        float curator_coef(const object &value0_, const std::string &value1_) {
            return host::functions.invoke_raw_binary(client::__sqf::binary__curatorcoef__object__string__ret__scalar, value0_, value1_);
        }

        void remove_curator_camera_area(const object &value1_, float value0_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__removecuratorcameraarea__object__scalar__ret__nothing, value0_, value1_);
        }

        void remove_curator_editing_area(const object &value1_, float value0_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__removecuratoreditingarea__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_curator_camera_area_ceiling(const object &value1_, float value0_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setcuratorcameraareaceiling__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_curator_editing_area_type(const object &value1_, bool value0_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setcuratoreditingareatype__object__bool__ret__nothing, value0_, value1_);
        }

        void set_curator_waypoint_cost(const object &value1_, float value0_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setcuratorwaypointcost__object__scalar__ret__nothing, value0_, value1_);
        }

        void add_curator_addons(const object & curator_object_, const std::vector<std::string>& addons_) {
            std::vector<game_value> addons; //#TODO remove temp std::vector
            for (std::string addon : addons_) {
                addons.push_back(game_value(addon));
            }
            host::functions.invoke_raw_binary(client::__sqf::binary__addcuratoraddons__object__array__ret__nothing, curator_object_, addons);
        }

        void add_curator_camera_area(const object & curator_object_, int camera_area_id_, const vector2 & position_, float radius_) {
            game_value args({
                (float) camera_area_id_,
                position_,
                radius_
            });

            host::functions.invoke_raw_binary(client::__sqf::binary__addcuratorcameraarea__object__array__ret__nothing, curator_object_, args);
        }

        void add_curator_camera_area(const object & curator_object_, int camera_area_id_, const vector3 & position_, float radius_) {
            game_value args({
                (float) camera_area_id_,
                position_,
                radius_
            });

            host::functions.invoke_raw_binary(client::__sqf::binary__addcuratorcameraarea__object__array__ret__nothing, curator_object_, args);
        }

        void add_curator_editable_object(const object & curator_object_, const std::vector<object>& objects_, bool add_crew_) {
            std::vector<game_value> objects; //#TODO remove temp std::vector
            for (object cobject : objects_) {
                objects.push_back(game_value(cobject));
            }
            game_value args({
                objects,
                add_crew_
            });

            host::functions.invoke_raw_binary(client::__sqf::binary__addcuratoreditableobjects__object__array__ret__nothing, curator_object_, args);
        }

        void add_curator_editing_area(const object & curator_object_, int edit_area_id_, const vector2 & position_, float radius_) {
            game_value args({
                (float) edit_area_id_,
                position_,
                radius_
            });

            host::functions.invoke_raw_binary(client::__sqf::binary__addcuratoreditingarea__object__array__ret__nothing, curator_object_, args);
        }

        std::vector<std::string> curator_addons(const object &curator_module_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__curatoraddons__object__ret__array, curator_module_));
        }

        std::vector<object> curator_editable_objects(const object &curator_module_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__curatoreditableobjects__object__ret__array, curator_module_));
        }

        std::vector<object> curator_registered_objects(const object &curator_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__curatorregisteredobjects__object__ret__array, curator_));
        }
        std::vector<object> object_curators(const object &obj_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__objectcurators__object__ret__array, obj_));
        }
    }
}
