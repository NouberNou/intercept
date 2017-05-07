﻿/*!
@file
@author Verox (verox.averre@gmail.com)
@author Nou (korewananda@gmail.com)
@author Glowbal (thomasskooi@live.nl)

@brief Wrappers for the 3den 3D editor functions.

These are wrappers for the 3den 3D editor that will be released in the next major
Arma 3 release.

https://github.com/NouberNou/intercept
*/
#pragma once
#include "shared.hpp"
#include "client\client.hpp"
#include "shared\types.hpp"
#include "shared\client_types.hpp"

using namespace intercept::types;

namespace intercept {
    namespace sqf {
        /* eden */
        std::string current_eden_operation();
        object get_eden_camera();
        // [showScene,showMap]
        std::pair<bool, bool> get_eden_icons_visible();
        // [showScene,showMap]
        std::pair<bool, bool> get_eden_lines_visible();
        // TODO array[] get_eden_mouse_over(); //      Array in format: [type,Eden Entity], where type can be: "Object", "Group", "Trigger", "Logic", "Waypoint" or "Marker"
        bool is_eden();
        bool is_eden_multiplayer();
        float get_eden_action_state(const std::string &value_);
        void edit_eden_mission_attributes(const std::string &value_);
        float add_eden_layer(int parent_layer_id_, const std::string& name_);
        bool remove_eden_layer(float value_);
        void remove_all_eden_eventhandlers(const std::string &value_);
        float add_eden_event_handler(const std::string &type_, const code &code_);
        std::vector<game_value> create_3den_composition(const config &config_path_, const vector3 &position_);// TODO add Eden Entity type
        game_value create_3den_entity(const std::string &mode_, const std::string &class_, const vector3 &position_, bool is_empty_); // TODO array[] of array[string,Eden entity] and mode can only be  "Object", "Trigger", "Logic", "Waypoint" or "Marker"
        std::vector<game_value> create_3den_connections(const game_value &entity_);
        game_value get_3den_entity(const float &entity_id_);
        std::vector<game_value> get_3den_layer_entities(const float &layer_id_);
        std::vector<game_value> get_3den_selected(const std::string &type_);
        bool set_3den_attributes(const std::vector<game_value> &entity_attributes_);
        std::vector<object> all_eden_entities();
        void do_eden_action(const std::string& value_);
        void get_eden_grid(const std::string& value_);
        struct rv_eden_mouse_over {
            std::string type;
            game_value entity;

            rv_eden_mouse_over(const game_value &rv_game_value_)
                : type(rv_game_value_[0]),
                entity(rv_game_value_[1]) {}
        };
        rv_eden_mouse_over get_eden_mouse_over();
        void collect_eden_history(const code &code_);
        float get_eden_entity_id(const object &entity_);
        float get_eden_entity_id(const group &entity_);
        float get_eden_entity_id(const vector3 &entity_);
        float get_eden_entity_id(const marker &entity_);
        void delete_eden_entities(const object &entity_);
        void delete_eden_entities(const group &entity_);
        void delete_eden_entities(const vector3 &entity_);
        void delete_eden_entities(const marker &entity_);

        bool add_eden_connection(const std::string &type_, const std::vector<object> &from_, const object &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<object> &from_, const group &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<object> &from_, const vector3 &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<object> &from_, const marker &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<group> &from_, const object &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<group> &from_, const group &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<group> &from_, const vector3 &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<group> &from_, const marker &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<vector3> &from_, const object &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<vector3> &from_, const group &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<vector3> &from_, const vector3 &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<vector3> &from_, const marker &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<marker> &from_, const object &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<marker> &from_, const group &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<marker> &from_, const vector3 &to_);
        bool add_eden_connection(const std::string &type_, const std::vector<marker> &from_, const marker &to_);

        void set_eden_grid(const std::string &type_, float increment_);
        void set_eden_icons_visible(bool map_, bool scene_);
        void set_eden_lines_visible(bool map_, bool scene_);
        bool set_eden_mission_attributes(const std::string &section_, const std::string &class_, const game_value &value_);

        void remove_eden_event_handler(const std::string &type_, float id_);
        void move_eden_camera(const vector3 &pos_, const vector3 &offset_);

    }
}
