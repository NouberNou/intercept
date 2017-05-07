﻿/*!
@file
@author Verox (verox.averre@gmail.com)
@author Nou (korewananda@gmail.com)
@author Glowbal (thomasskooi@live.nl)

@brief World information functions.

Get information about the game world, wind, waves, date/time, etc.

https://github.com/NouberNou/intercept
*/
#pragma once
#include "shared.hpp"
#include "client\client.hpp"
#include "shared\client_types.hpp"

using namespace intercept::types;
namespace intercept {
    namespace sqf {
        /* World */

        struct rv_date {
            float year;
            float month;
            float day;
            float hour;
            float minute;

            rv_date(float year_, float month_, float day_, float hour_, float minute_) {
                year = year_;
                month = month_;
                day = day_;
                hour = hour_;
                minute = minute_;
            }

            static rv_date from_vector(const std::vector<float> &date_vector_) {
                return rv_date(date_vector_[0], date_vector_[1], date_vector_[2], date_vector_[3], date_vector_[4]);
            }

            operator game_value() {
                return game_value(std::vector<game_value>({
                    year,
                    month,
                    day,
                    hour,
                    minute
                }));
            }

            operator game_value() const {
                return game_value(std::vector<game_value>({
                    year,
                    month,
                    day,
                    hour,
                    minute
                }));
            }

            std::vector<float> to_vector() const {
                std::vector<float> ret_val{ year, month, day, hour, minute };
                return ret_val;
            }
        };

        float world_size();
        std::string world_name();
        float wind_str();
        float wind_dir();
        void set_wind(float x_, float y_);
        void set_wind(float x_, float y_, bool force_);
        vector3 wind();
        float gusts();
        float humidity();
        float waves();
        // TODO void set_waves(float lerp_time_, float val_); // TODO

        float lightnings();

        float moon_intensity();
        float next_weather_change();
        float overcast();
        float overcast_forecast();
        float rain();
        float rainbow();
        float sun_or_moon(); // BUT WHICH ONE IS IT!?!?!??!!?
        bool fog();
        float fog_forecast();

        float time();

        float time_multiplier();

        float date_to_number(int year_, int month_, int day_, int hour_, float minute_);
        rv_date number_to_date(int year_, float time_);
        rv_date date();
        rv_date mission_start();


        struct rv_fog_parameters {
            float value;
            float decay;
            float base;

            rv_fog_parameters(float value_, float decay_, float base_) {
                value = value_;
                decay = decay_;
                base = base_;
            }

            static rv_fog_parameters from_vector(const std::vector<float> &fog_params_vector_) {
                return rv_fog_parameters(fog_params_vector_[0], fog_params_vector_[1], fog_params_vector_[2]);
            }

            std::vector<float> to_vector() const {
                std::vector<float> ret_val{ value, decay, base };
                return ret_val;
            }
        };

        rv_fog_parameters fog_params();

        struct rv_rendering_distances {
            float object_distance;
            float shadow_distance;

            rv_rendering_distances(float object_distance_, float shadow_distance_) {
                object_distance = object_distance_;
                shadow_distance = shadow_distance_;
            }

            static rv_rendering_distances from_vector(const std::vector<float> &rendering_distances_vector_) {
                return rv_rendering_distances(rendering_distances_vector_[0], rendering_distances_vector_[1]);
            }

            std::vector<float> to_vector() const {
                std::vector<float> ret_val{ object_distance, shadow_distance };
                return ret_val;
            }
        };

        rv_rendering_distances get_object_view_distance();

        void set_date(int year_, int month_, int day_, int hour_, float minute_);
    }
}