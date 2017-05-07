﻿#include "uncategorized.hpp"
#include "client\pointers.hpp"
#include "common_helpers.hpp"
#include "position.hpp" //for uses of get_pos_obj. Should be removed once they are sorted

using namespace intercept::types;

namespace intercept {
    namespace sqf {



        /////////////////////// DO NOT IMPLEMENT THESE FUNCTIONS /////////////////////////
        ///////// They are haram. Discuss on slack prior to removing from list. //////////
        // unary__abs__scalar_nan__ret__scalar_nan
        // unary__acos__scalar_nan__ret__scalar_nan
        // unary__asin__scalar_nan__ret__scalar_nan
        // unary__atan__scalar_nan__ret__scalar_nan
        // unary__atg__scalar_nan__ret__scalar_nan
        // unary__assert__bool__ret__bool
        // unary__breakout__string__ret__nothing
        // unary__breakto__string__ret__nothing
        // unary__case__any__ret__switch
        // unary__comment__string__ret__nothing
        // unary__compilefinal__string__ret__code
        // unary__count__array__ret__scalar
        // unary__count__string__ret__scalar
        // unary__ceil__scalar_nan__ret__scalar_nan
        // unary__cos__scalar_nan__ret__scalar_nan
        // unary__debuglog__any__ret__nothing
        // unary__default__code__ret__nothing
        // unary__deg__scalar_nan__ret__scalar_nan
        // unary__exp__scalar_nan__ret__scalar_nan
        // unary__floor__scalar_nan__ret__scalar_nan
        // unary__for__string__ret__for
        // unary__for__array__ret__for
        // unary__format__array__ret__string
        // unary__formattext__array__ret__text
        // unary__goto__string__ret__nothing
        // unary__if__bool__ret__if
        // unary__isnil__code_string__ret__bool
        // unary__ln__scalar_nan__ret__scalar_nan
        // unary__log__scalar_nan__ret__scalar_nan
        // unary__not__bool__ret__bool
        // unary__oneachframe__code_string__ret__nothing
        // unary__ongroupiconclick__code_string__ret__nothing
        // unary__ongroupiconoverenter__code_string__ret__nothing
        // unary__ongroupiconoverleave__code_string__ret__nothing
        // unary__onhcgroupselectionchanged__code_string__ret__nothing
        // unary__onmapsingleclick__code_string__ret__nothing
        // unary__onplayerconnected__code_string__ret__nothing
        // unary__onplayerdisconnected__code_string__ret__nothing
        // unary__onpreloadfinished__code_string__ret__nothing
        // unary__onpreloadstarted__code_string__ret__nothing
        // unary__onteamswitch__code_string__ret__nothing
        // unary__param__array__ret__any
        // unary__params__array__ret__bool
        // unary__private__string_array__ret__nothing
        // unary__rad__scalar_nan__ret__scalar_nan
        // unary__random__array__ret__scalar_nan
        // unary__random__scalar_nan__ret__scalar_nan
        // unary__reverse__array__ret__nothing
        // unary__round__scalar_nan__ret__scalar_nan
        // unary__selectrandom__array__ret__any
        // unary__sin__scalar_nan__ret__scalar_nan
        // unary__str__any__ret__string
        // unary__sqrt__scalar_nan__ret__scalar_nan
        // unary__switch__any__ret__switch
        // unary__tan__scalar_nan__ret__scalar_nan
        // unary__text__string__ret__text
        // unary__textlog__any__ret__nothing
        // unary__textlogformat__array__ret__nothing
        // unary__tg__scalar_nan__ret__scalar_nan
        // unary__throw__any__ret__nothing
        // unary__toarray__string__ret__array
        // unary__tostring__array__ret__string
        // unary__try__code__ret__exception
        // unary__typename__any__ret__string
        // unary__vectormagnitude__array__ret__scalar
        // unary__vectormagnitudesqr__array__ret__scalar
        // unary__vectornormalized__array__ret__array
        // unary__waituntil__code__ret__nothing
        // unary__while__code__ret__while
        // unary__with__namespace__ret__with

        // binary__and__bool__bool__ret__bool
        // binary__and__bool__code__ret__bool
        // binary__append__array__array__ret__nothing
        // binary__arrayintersect__array__array__ret__array
        // binary__atan2__scalar_nan__scalar_nan__ret__scalar_nan
        // binary__breakout__any__string__ret__any
        // binary__camsetdir__object__array__ret__nothing
        // binary__catch__exception__code__ret__any
        // binary__count__code__array__ret__scalar
        // binary__deleteat__array__scalar__ret__any
        // binary__deleterange__array__array__ret__nothing
        // binary__do__while__code__ret__nothing
        // binary__do__with__code__ret__nothing
        // binary__do__for__code__ret__any
        // binary__do__switch__code__ret__any
        // binary__else__code__code__ret__array
        // binary__exitwith__if__code__ret__any
        // binary__find__array__any__ret__scalar
        // binary__find__string__string__ret__scalar
        // binary__foreach__code__array__ret__nothing
        // binary__foreachmember__code__team_member__ret__nothing
        // binary__foreachmemberagent__code__team_member__ret__nothing
        // binary__foreachmemberteam__code__team_member__ret__nothing
        // binary__from__for__scalar__ret__for
        // binary__in__any__array__ret__bool
        // binary__isequalto__any__any__ret__bool
        // binary__isequaltype__any__any__ret__bool
        // binary__isequaltypeall__array__any__ret__bool
        // binary__isequaltypeany__any__array__ret__bool
        // binary__isequaltypearray__array__array__ret__bool
        // binary__isequaltypeparams__any__array__ret__bool
        // binary__joinstring__array__string__ret__string
        // binary__max__scalar_nan__scalar_nan__ret__scalar_nan
        // binary__min__scalar_nan__scalar_nan__ret__scalar_nan
        // binary__mod__scalar_nan__scalar_nan__ret__scalar_nan
        // binary__lbsetselected__control__array__ret__nothing (Depreciated in favor of lbSetCurSel)
        // binary__or__bool__bool__ret__bool
        // binary__or__bool__code__ret__bool
        // binary__param__any__array__ret__any
        // binary__params__any__array__ret__bool
        // binary__pushback__array__any__ret__scalar
        // binary__resize__array__scalar__ret__nothing
        // binary__select__array__scalar__ret__any
        // binary__select__array__bool__ret__any
        // binary__select__array__array__ret__array
        // binary__select__string__array__ret__string
        // binary__set__array__array__ret__nothing
        // binary__sort__array__bool__ret__nothing
        // binary__spawn__any__code__ret__script ------------------------------------------------------------------------
        // binary__splitstring__string__string__ret__array
        // binary__step__for__scalar__ret__for
        // binary__then__if__code__ret__any
        // binary__then__if__array__ret__any
        // binary__throw__if__any__ret__nothing
        // binary__to__for__scalar__ret__for
        // binary__try__any__code__ret__exception
        // binary__vectoradd__array__array__ret__array
        // binary__vectorcos__array__array__ret__scalar
        // binary__vectorcrossproduct__array__array__ret__array
        // binary__vectordiff__array__array__ret__array
        // binary__vectordistance__array__array__ret__scalar
        // binary__vectordistancesqr__array__array__ret__scalar
        // binary__vectordotproduct__array__array__ret__scalar
        // binary__vectorfromto__array__array__ret__array
        // binary__vectormultiply__array__scalar__ret__array

        // nular__allsites__ret__array (deprecated - source: BI Wiki)
        // nular__false__ret__bool
        // nular__netobjnull__ret__netobject ----------------------------------------------------------------------------------
        // nular__nil__ret__any
        // nular__true__ret__bool


        /// INVESTIGATE
        /* No documentation.*/
        // unary__addforcegeneratorrtd__array__ret__scalar

        /* No documentation.*/
        // nular__airdensitycurvertd__ret__array

        /* No documentation.*/
        // unary__ctrlangle__control__ret__array

        /* No documentation for return array elements. */
        // unary__ctrlmapmouseover__control__ret__array
        // unary__curatorcameraarea__object__ret__array
        // unary__curatoreditingarea__object__ret__array

        /* No documentation.*/
        // unary__enableaudiofeature__array__ret__bool

        /* No documentation.*/
        // nular__getdlcassetsusage__ret__array

        /* No documentation.*/
        // nular__getmissiondlcs__ret__array

        /* No documentation.*/
        // nular__getmouseposition__ret__array

        /* No documentation.*/
        // unary__getpersonuseddlcs__object__ret__array
        // unary__getplayerscores__object__ret__array

        /* Last parameter can be position (x, y, z) or target, unknown what target is.*/
        // nular__hudmovementlevels__ret__array

        /* No documentation for type Team.*/
        // nular__teams__ret__array

        /* No documentation.*/
        // nular__windrtd__ret__array

        /* No documentation.*/
        // unary__resources__team_member__ret__array

        /* These functions apparently send arbatary messages across the network. They are apparently inactive.*/
        // unary__sendaumessage__array__ret__nothing
        // unary__sendudpmessage__array__ret__bool

        /* This function does _something_ to a listbox. No documentation.*/
        // binary__lbsettextright__control__array__ret__nothing

        /* This function is apparently depreciated but the functionality is different to the command which replaces it.*/
        // unary__lbselection__control__ret__array

        /* This undocumented function has the potential to be useful, my guess is it returns a float between 1 and 0 which
            corresponds to how visible a particular unit is from another unit. binary__knowsabout__object_group__object__ret__scalar*/
        // binary__checkvisibility__array__array__ret__scalar

        /* No documentation.*/
        // binary__ctrlsetangle__control__array__ret__nothing

        /* No documentation.*/
        // binary__ctrlsettextcolorsecondary__control__array__ret__nothing

        /* Poor documentation.*/
        // binary__backpackspacefor__object__string__ret__array

        /* No documentation for unary calls. If these are consistent with the other tv_* fuctions, they should take int idc_ as the first argument instead of ctrl and pass it as: ({idc_, ...}) */
        // unary__tvsort__array__ret__nothing
        // unary__tvsortbyvalue__array__ret__nothing

        /* No documentation but implemented (?) */
        // binary__tvtooltip__control__scalar__ret__string

        /* No documentation.*/
        // unary__tvtooltip__array__ret__string

        /* No documentation for this entire family of commands.*/
        // binary__menuaction__control__array__ret__string
        // binary__menuadd__control__array__ret__scalar
        // binary__menuchecked__control__array__ret__bool
        // binary__menucollapse__control__array__ret__nothing
        // binary__menudata__control__array__ret__string
        // binary__menudelete__control__array__ret__nothing
        // binary__menuenable__control__array__ret__nothing
        // binary__menuenabled__control__array__ret__bool
        // binary__menuexpand__control__array__ret__nothing
        // binary__menupicture__control__array__ret__string
        // binary__menusetaction__control__array__ret__nothing
        // binary__menusetcheck__control__array__ret__nothing
        // binary__menusetdata__control__array__ret__nothing
        // binary__menusetpicture__control__array__ret__nothing
        // binary__menusetvalue__control__array__ret__nothing
        // binary__menushortcut__control__array__ret__scalar
        // binary__menushortcuttext__control__array__ret__string
        // binary__menusize__control__array__ret__scalar
        // binary__menusort__control__array__ret__nothing
        // binary__menutext__control__array__ret__string
        // binary__menuurl__control__array__ret__string
        // binary__menuvalue__control__array__ret__scalar
        // unary__menuaction__array__ret__string
        // unary__menuadd__array__ret__scalar
        // unary__menuchecked__array__ret__bool
        // unary__menuclear__control__ret__nothing
        // unary__menuclear__scalar__ret__nothing
        // unary__menucollapse__array__ret__nothing
        // unary__menudata__array__ret__string
        // unary__menudelete__array__ret__nothing
        // unary__menuenable__array__ret__nothing
        // unary__menuenabled__array__ret__bool
        // unary__menuexpand__array__ret__nothing
        // unary__menuhover__control__ret__array
        // unary__menuhover__scalar__ret__array
        // unary__menupicture__array__ret__string
        // unary__menusetaction__array__ret__nothing
        // unary__menusetcheck__array__ret__nothing
        // unary__menusetdata__array__ret__nothing
        // unary__menusetpicture__array__ret__nothing
        // unary__menusetvalue__array__ret__nothing
        // unary__menushortcut__array__ret__scalar
        // unary__menushortcuttext__array__ret__string
        // unary__menusize__array__ret__scalar
        // unary__menusort__array__ret__nothing
        // unary__menutext__array__ret__string
        // unary__menuurl__array__ret__string
        // unary__menuvalue__array__ret__scalar

        /* No documentation.*/
        // unary__leaderboardgetrows__string__ret__array
        // unary__leaderboardrequestrowsglobal__array__ret__bool
        // unary__leaderboardrequestrowsglobalarounduser__array__ret__bool
        // unary__leaderboardsrequestuploadscore__array__ret__bool
        // unary__leaderboardsrequestuploadscorekeepbest__array__ret__bool

        /* No documentation.*/
        // unary__enginespowerrtd__object__ret__array
        // unary__forceatpositionrtd__array__ret__array
        // unary__forcegeneratorrtd__scalar__ret__array
        // unary__gettrimoffsetrtd__object__ret__array
        // unary__isautostartupenabledrtd__object__ret__array
        // binary__setforcegeneratorrtd__scalar__array__ret__nothing
        // binary__setwingforcescalertd__object__array__ret__nothing

        /* No documentation.*/
        // unary__setwinddir__array__ret__nothing

        /* No documentation.*/
        // nular__missionversion__ret__scalar
        // unary__weaponinertia__object__ret__array
        // unary__animationnames__object__ret__array
        // unary__animationselectionnames__object__ret__array
        // unary__call__code__ret__any
        // unary__clear3deninventory__array__ret__nothing
        // unary__tvpictureright__array__ret__string
        // unary__createobject__array__ret__object
        // unary__getdlcassetsusagebyname__string__ret__array
        // unary__getenginetargetrpmrtd__object__ret__array
        // unary__getfieldmanualstartpage__display__ret__array
        // unary__getunitloadout__object__ret__array
        // unary__getunitloadout__string__ret__array
        // unary__lbsettext__array__ret__string
        // unary__registerremoteexecfunc__string__ret__bool
        // unary__save3deninventory__array__ret__nothing
        // unary__set3denmodelsvisible__array__ret__nothing
        // unary__synchronizedtriggers__array__ret__array
        // binary__lnbcolorright__control__array__ret__array
        // unary__lnbcolorright__array__ret__array
        // unary__lnbpictureright__array__ret__string
        // binary__lnbpictureright__control__array__ret__string
        // unary__lnbsetcolorright__array__ret__nothing
        // binary__lnbsetcolorright__control__array__ret__nothing
        // unary__lnbsetpicturecolor__array__ret__nothing
        // binary__lnbsetpicturecolor__control__array__ret__nothing
        // unary__lnbsetpicturecolorright__array__ret__nothing
        // binary__lnbsetpicturecolorright__control__array__ret__nothing
        // unary__lnbsetpicturecolorselected__array__ret__nothing
        // binary__lnbsetpicturecolorselected__control__array__ret__nothing
        // unary__lnbsetpicturecolorselectedright__array__ret__nothing
        // binary__lnbsetpicturecolorselectedright__control__array__ret__nothing
        // unary__lnbsetpictureright__array__ret__nothing
        // binary__lnbsetpictureright__control__array__ret__nothing
        // unary__lnbsettextright__array__ret__nothing
        // binary__lnbsettextright__control__array__ret__nothing

        // unary__lnbsort__array__ret__nothing
        // binary__lnbsort__control__array__ret__nothing
        // unary__lnbsortbyvalue__array__ret__nothing
        // binary__lnbsortbyvalue__control__array__ret__nothing
        // unary__lnbtextright__array__ret__string
        // binary__lnbtextright__control__array__ret__string

        /* No documentation for return types. */
        // unary__getgroupicons__group__ret__array
        // unary__taskchildren__task__ret__array
        // unary__taskresult__task__ret__array
        // unary__triggeractivation__object__ret__array
        // unary__triggerstatements__object__ret__array
        // unary__waypointgetforcebehaviour__array__ret__string
        // unary__waypointstatements__array__ret__array
        // unary__waypointtimeout__array__ret__array

        /* Wrong documentation - seems to take Array instead of String. */
        // unary__lognetwork__array__ret__scalar

        /* Team Member things - apparently useless. */
        // unary__teammember__object__ret__team_member
        /////////////////////// DO NOT IMPLEMENT ABOVE FUNCTIONS /////////////////////////


game_value call(const code & code_, game_value args_)
{
    game_value args = std::vector<game_value>{ args_, code_ };
    host::memory_watcher.add_watch(args);
    sqf::set_variable(sqf::mission_namespace(), "INTERCEPT_CALL_ARGS", args);
    //#TODO these notes refer to old way call method.
    /*
    Why is this in a wrapper? Because code compiled in intercept apparently lacks
    the proper context in the SQF interpeter, so we need to be aware of that, and
    the easiest way to stay on top of it is to send the code to call into a wrapper
    in SQF itself, so the context is achieved.
    */
    host::functions.invoke_raw_unary(
        client::__sqf::unary__isnil__code_string__ret__bool,
        sqf::get_variable(sqf::mission_namespace(), "intercept_fnc_isNilWrapper")
    );

    // And returns are not handled correctly because of assumingly the SQF stack
    // implementation so, we just grab it from a gvar.
    return sqf::get_variable(sqf::mission_namespace(), "INTERCEPT_CALL_RETURN");
}

game_value call(const code & code_)
{
    game_value args = std::vector<game_value>{game_value(), code_ };
    host::memory_watcher.add_watch(args);
    sqf::set_variable(sqf::mission_namespace(), "INTERCEPT_CALL_ARGS", args);
    //#TODO these notes refer to old way call method.
    /*
    Why is this in a wrapper? Because code compiled in intercept apparently lacks
    the proper context in the SQF interpeter, so we need to be aware of that, and
    the easiest way to stay on top of it is to send the code to call into a wrapper
    in SQF itself, so the context is achieved.
    */
    host::functions.invoke_raw_unary(
        client::__sqf::unary__isnil__code_string__ret__bool,
        sqf::get_variable(sqf::mission_namespace(), "intercept_fnc_isNilWrapper")
    );

    // And returns are not handled correctly because of assumingly the SQF stack
    // implementation so, we just grab it from a gvar.
    return sqf::get_variable(sqf::mission_namespace(), "INTERCEPT_CALL_RETURN");
}

code compile(const std::string & sqf_)
{
    return code(host::functions.invoke_raw_unary(client::__sqf::unary__compile__string__ret__code, sqf_));
}

void set_variable(const rv_namespace & namespace_, const std::string & var_name_, game_value value_)
{
    //game_value args = std::vector<game_value>{ namespace_, std::vector<game_value>{ var_name_, value_ } };
    game_value args = std::vector<game_value>{ var_name_, value_ };
    host::memory_watcher.add_watch(args);
    
    host::functions.invoke_raw_binary(client::__sqf::binary__setvariable__namespace__array__ret__nothing, namespace_, args);
    //host::functions.invoke_raw_binary(client::__sqf::binary__call__any__code__ret__any, args, sqf::get_variable(sqf::mission_namespace(), "intercept_fnc_setVariableNamespace"));
}

void draw_line_3d(const vector3 & pos1_, const vector3 & pos2_, const rv_color & color_) {
            game_value args({
                pos1_,
                pos2_,
                color_
            });
            host::functions.invoke_raw_unary(client::__sqf::unary__drawline3d__array__ret__nothing, args);
        }

        void draw_icon_3d(const std::string & texture_, const rv_color & color_, const vector3 & pos_agl_, float width_, float height_, float angle_, const std::string & text_, float shadow_, float text_size_, const std::string & font_) {
            game_value args({
                texture_,
                color_,
                pos_agl_,
                width_,
                height_,
                angle_,
                text_,
                shadow_,
                text_size_,
                font_
            });

            host::functions.invoke_raw_unary(client::__sqf::unary__drawicon3d__array__ret__nothing, args);
        }

        vector3 vector_dir(const object &obj_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__vectordir__object__ret__array, obj_));
        }

        vector3 vector_dir_visual(const object & obj_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__vectordirvisual__object__ret__array, obj_));
        }

        vector3 selection_positon(const object & obj_, const std::string & selection_name_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__selectionposition__object__string_array__ret__array, obj_, selection_name_));
        }

        game_value get_variable(const rv_namespace & namespace_, const std::string & var_name_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__namespace__string__ret__any, namespace_, var_name_));
        }

        game_value get_variable(const rv_namespace & namespace_, const std::string & var_name_, game_value default_value_) {
            game_value args({
                var_name_,
                default_value_
            });
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__namespace__array__ret__any, namespace_, args));
        }

        game_value get_variable(const display & display_, const std::string & var_name_, game_value default_value_) {
            game_value args({
                var_name_,
                default_value_
            });
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__display__string_array__ret__any, display_, args));
        }

        game_value get_variable(const object & obj_, const std::string & var_name_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__object__string__ret__any, obj_, var_name_));
        }

        game_value get_variable(const object & obj_, const std::string & var_name_, game_value default_value_) {
            game_value args({
                var_name_,
                default_value_
            });
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__object__array__ret__any, obj_, args));
        }

        game_value get_variable(const group & group_, const std::string & var_name_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__group__string__ret__any, group_, var_name_));
        }

        game_value get_variable(const group & group_, const std::string & var_name_, game_value default_value_) {
            game_value args({
                var_name_,
                default_value_
            });
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__group__array__ret__any, group_, args));
        }

        game_value get_variable(const team_member & team_member_, const std::string & var_name_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__team_member__string__ret__any, team_member_, var_name_));
        }

        game_value get_variable(const team_member & team_member_, const std::string & var_name_, game_value default_value_) {
            game_value args({
                var_name_,
                default_value_
            });
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__team_member__array__ret__any, team_member_, args));
        }

        game_value get_variable(const task & task_, const std::string & var_name_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getvariable__task__string__ret__any, task_, var_name_));
        }




        

        std::vector<object> near_entities(const vector3 & pos_agl_, const std::vector<std::string>& types_, float range_) {
            std::vector<game_value> types;
            for (auto type : types_)
                types.push_back(type);
            game_value args(std::vector<game_value>{
                types,
                range_
            });

            game_value ret = host::functions.invoke_raw_binary(__sqf::binary__nearentities__object_array__scalar_array__ret__array, pos_agl_, args);
            std::vector<object> ret_objects;
            for (uint32_t i = 0; i < ret.length(); ++i)
                ret_objects.push_back(object(ret[i]));
            return ret_objects;
        }



        object create_vehicle_local(const std::string & type_, const vector3 & pos_atl_) {
            return object(host::functions.invoke_raw_binary(__sqf::binary__createvehiclelocal__string__array__ret__object, type_, pos_atl_));
        }



        std::vector<std::string> action_keys(const std::string &user_action_) {
            game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeys__string__ret__array, user_action_);
            std::vector<std::string> r_arr = __helpers::__convert_to_strings_vector(act_keys);
            return r_arr;
        }

        rv_text action_keys_images(const std::string &user_action_) {
            return rv_text(host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysimages__string_array__ret__text, user_action_));
        }

        std::string action_keys_names(const std::string &user_action_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnames__string_array__ret__string, user_action_));
        }

        std::string action_keys_names(const std::string &user_action_, int max_keys_) {
            std::vector<game_value> params{ user_action_, game_value((float)max_keys_) };
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnames__string_array__ret__string, params));
        }
        std::string action_keys_names(const std::string &user_action_, int max_keys_, const std::string &input_device_priority_) {
            game_value params({
                user_action_,
                (float)max_keys_,
                input_device_priority_
            });

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnames__string_array__ret__string, params));
        }

        std::vector<std::string> action_keys_names_array(const std::string &user_action_) {
            game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnamesarray__string_array__ret__array, user_action_);
            std::vector<std::string> r_arr = __helpers::__convert_to_strings_vector(act_keys);

            host::functions.free_value(&act_keys);
            return r_arr;
        }

        std::vector<std::string> action_keys_names_array(const std::string &user_action_, int max_keys_) {
            std::vector<game_value> params{ user_action_, game_value((float)max_keys_) };

            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnamesarray__string_array__ret__array, params));
        }
        std::vector<std::string> action_keys_names_array(const std::string &user_action_, int max_keys_, const std::string &input_device_priority_) {
            game_value params({
                user_action_,
                (float)max_keys_,
                input_device_priority_
            });

            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnamesarray__string_array__ret__array, params));
        }

        void activate_addons(std::vector<std::string> &addons_) {
            std::vector<game_value> addons;
            for (auto it : addons_)
                addons.push_back(it);

            host::functions.invoke_raw_unary(client::__sqf::unary__activateaddons__array__ret__nothing, addons);
        }


        

        void add_to_remains_collector(const std::vector<object> & objects_) {
            std::vector<game_value> objects;
            for (auto &it : objects_)
                objects.push_back(it);
            host::functions.invoke_raw_unary(client::__sqf::unary__addtoremainscollector__array__ret__nothing, objects);
        }

        void ais_finish_heal(const object &wounded_, const object &medic_, bool medic_can_heal_) {
            game_value params(std::vector<game_value>{
                wounded_,
                medic_,
                medic_can_heal_
            });

            host::functions.invoke_raw_unary(client::__sqf::unary__aisfinishheal__array__ret__nothing, params);
        }

        std::vector<object> all_mission_objects(const std::string &type_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__allmissionobjects__string__ret__array, type_));
        }

        std::vector<object> assigned_cargo(const object &veh_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__assignedcargo__object__ret__array, veh_));
        }





        std::vector<object> attached_objects(const object &obj_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__attachedobjects__object__ret__array, obj_));
        }

        object attached_to(const object &obj_) {
            return object(host::functions.invoke_raw_unary(client::__sqf::unary__attachedto__object__ret__array, obj_));
        }

        void attach_to(const object &object1_, const object &object2_, const vector3 &offset_, const std::string &memPoint_) {
            std::vector<game_value> args{
                object2_,
                offset_,
                memPoint_
            };
            host::functions.invoke_raw_binary(client::__sqf::binary__attachto__object__array__ret__nothing, object1_, args);
        }

        void attach_to(const object &object1_, const object &object2_, const vector3 &offset_) {
            std::vector<game_value> args{
                object2_,
                offset_
            };
            host::functions.invoke_raw_binary(client::__sqf::binary__attachto__object__array__ret__nothing, object1_, args);
        }

        bool attack_enabled(const object &unit_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__attackenabled__object_group__ret__bool, unit_);
        }

        bool attack_enabled(const group &group_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__attackenabled__object_group__ret__bool, group_));
        }

        sqf::rv_bounding_box bounding_box(const object &model_) {
            game_value rgv(host::functions.invoke_raw_unary(client::__sqf::unary__boundingbox__object__ret__array, model_));
            return sqf::rv_bounding_box({ vector3(rgv[0][0], rgv[0][1], rgv[0][2]), vector3(rgv[1][0], rgv[1][1], rgv[1][2]) });
        }

        sqf::rv_bounding_box bounding_box_real(const object &model_) {
            game_value rgv(host::functions.invoke_raw_unary(client::__sqf::unary__boundingboxreal__object__ret__array, model_));
            return sqf::rv_bounding_box({ vector3(rgv[0][0], rgv[0][1], rgv[0][2]), vector3(rgv[1][0], rgv[1][1], rgv[1][2]) });
        }

        vector3 bounding_center(const object &obj_) {
            return __helpers::__convert_to_vector3(host::functions.invoke_raw_unary(client::__sqf::unary__boundingcenter__object__ret__array, obj_));
        }





        std::string combat_mode(const object &unit_) {
            return __helpers::__string_unary_object(client::__sqf::unary__combatmode__object_group__ret__string, unit_);
        }

        void command_get_out(const object &unit_) {
            return __helpers::__empty_unary_object(client::__sqf::unary__commandgetout__object_array__ret__nothing, unit_);
        }

        void command_get_out(const std::vector<object> & units_) {
            std::vector<game_value> units;
            for (auto it : units_)
                units.push_back(it);

            host::functions.invoke_raw_unary(client::__sqf::unary__commandgetout__object_array__ret__nothing, units);
        }

        void command_stop(const object &unit_) {
            return __helpers::__empty_unary_object(client::__sqf::unary__commandstop__object_array__ret__nothing, unit_);
        }
        void command_stop(const std::vector<object> & units_) {
            std::vector<game_value> units;
            for (auto it : units_)
                units.push_back(it);

            host::functions.invoke_raw_unary(client::__sqf::unary__commandstop__object_array__ret__nothing, units);
        }

        object create_agent(const std::string &type_, const vector3 &pos_, const std::vector<marker> &markers_ /* = {}*/, float placement_ /*= 0.0f*/, const std::string &special_ /*= "NONE"*/) {
            std::vector<game_value> markers;
            for (auto &it : markers_)
                markers.push_back(it);

            game_value args({
                type_,
                pos_,
                markers,
                placement_,
                special_
            });

            return object(host::functions.invoke_raw_unary(__sqf::unary__createagent__array__ret__object, args));

        }

        void create_gear_dialog(const object &unit_, const std::string &resource_) {
            game_value params({
                unit_,
                resource_
            });

            host::functions.invoke_raw_unary(__sqf::unary__creategeardialog__array__ret__nothing, params);
        }

        void create_guarded_point(const side &side_, const vector3 &pos_, float idstatic_, const object &veh_) {
            game_value params({
                side_,
                pos_,
                idstatic_,
                veh_
            });

            host::functions.invoke_raw_unary(__sqf::unary__createguardedpoint__array__ret__nothing, params);
        }

        void action(const object & unit_, const std::vector<game_value>& action_array_) {
            host::functions.invoke_raw_binary(__sqf::binary__action__object__array__ret__nothing, unit_, action_array_);
        }

        float add_event_handler(const object & object_, const std::string & type_, const code & command_) {
            std::vector<game_value> args{
                type_,
                command_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__addeventhandler__object__array__ret__nothing_scalar, object_, args));
        }

        float add_event_handler(const object & object_, const std::string & type_, const std::string & command_) {
            std::vector<game_value> args{
                type_,
                command_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__addeventhandler__object__array__ret__nothing_scalar, object_, args));
        }

        

        object create_mine(const std::string &type_, const vector3 &pos_, const std::vector<marker> &markers_/* = {}*/, float placement_/* = 0.0f*/) {
            std::vector<game_value> markers;
            for (auto &it : markers_)
                markers.push_back(it);

            game_value args({
                type_,
                pos_,
                markers,
                placement_,
            });

            return object(host::functions.invoke_raw_unary(__sqf::unary__createmine__array__ret__object, args));
        }

        object create_sound_source(const std::string &type_, const vector3 &pos_, const std::vector<marker> &markers_/* = {}*/, float placement_/* = 0.0f*/) {
            std::vector<game_value> markers;
            for (auto it : markers_)
                markers.push_back(it);

            game_value args({
                type_,
                pos_,
                markers,
                placement_,
            });

            return object(host::functions.invoke_raw_unary(__sqf::unary__createsoundsource__array__ret__object, args));
        }

        team_member create_team(const std::string &type_, const std::string &name_) {
            game_value args({
                (type_),
                (name_),
            });

            return team_member(host::functions.invoke_raw_unary(__sqf::unary__createteam__array__ret__team_member, args));
        }

        

        std::vector<object> crew(const object & _veh) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(__sqf::unary__crew__object__ret__array, _veh));
        }

        std::vector<task> current_tasks(const team_member &team_member_) {
            game_value input = host::functions.invoke_raw_unary(client::__sqf::unary__currenttasks__team_member__ret__array, team_member_);

            std::vector<task> output;
            for (uint32_t i = 0; i < input.length(); ++i) {
                output.push_back(task(input[i]));
            }

            return output;
        }

        float add_action(const object &object_, const std::string &title_, const std::string &script_, const std::vector<game_value> &arguments_, float priority_, bool show_window_, bool hide_on_use_, const std::string &shortcut_, const std::string &condition_) {
            std::vector<game_value> args{
                title_,
                script_,
                arguments_,
                priority_,
                show_window_,
                hide_on_use_,
                shortcut_,
                condition_
            };

            return game_value(host::functions.invoke_raw_binary(__sqf::binary__addaction__object__array__ret__nothing_scalar, object_, args));
        }

        float add_action(const object &object_, const std::string &title_, const code &script_, const std::vector<game_value> &arguments_, float priority_, bool show_window_, bool hide_on_use_, const std::string &shortcut_, const std::string &condition_) {
            std::vector<game_value> args{
                title_,
                script_,
                arguments_,
                priority_,
                show_window_,
                hide_on_use_,
                shortcut_,
                condition_
            };

            return game_value(host::functions.invoke_raw_binary(__sqf::binary__addaction__object__array__ret__nothing_scalar, object_, args));
        }

        void enable_saving(bool enable_) {
            enable_saving(enable_, !enable_);
        }

        void enable_saving(bool enable_, bool autosave_) {
            game_value args(std::vector<game_value> {
                (enable_),
                (autosave_)
            });

            host::functions.invoke_raw_unary(__sqf::unary__enablesaving__bool_array__ret__nothing, args);
        }

        std::string formation(const object &leader_) {
            return game_value(host::functions.invoke_raw_unary(__sqf::unary__formation__object_group__ret__string, leader_));
        }

        std::string formation(const group &group_) {
            return game_value(host::functions.invoke_raw_unary(__sqf::unary__formation__object_group__ret__string, group_));
        }

        std::vector<object> formation_members(const object &unit_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(__sqf::unary__formationmembers__object__ret__array, unit_));
        }

        vector3 formation_position(const object &unit_) {
            return __helpers::__convert_to_vector3(host::functions.invoke_raw_unary(__sqf::unary__formationposition__object__ret__array, unit_));
        }

        std::vector<rv_crew_member> full_crew(const object &veh_) {
            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__fullcrew__object__ret__array, veh_);

            std::vector<rv_crew_member> crew_members;
            for (uint32_t i = 0; i < ret.length(); ++i) {
                std::vector<int> turret_path = __helpers::__convert_to_integers_vector(ret[i][3]);
                crew_members.push_back(rv_crew_member(ret[i][0], ret[i][1], ret[i][2], turret_path, ret[i][4]));
            }

            return crew_members;
        }

        std::vector<rv_crew_member> full_crew(const object &veh_, const std::string &filter_, bool include_empty_) {
            std::vector<game_value> params{
                veh_,
                filter_,
                include_empty_
            };

            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__fullcrew__array__ret__array, params);

            std::vector<rv_crew_member> crew_members;
            for (uint32_t i = 0; i < ret.length(); ++i) {
                std::vector<int> turret_path = __helpers::__convert_to_integers_vector(ret[i][3]);
                crew_members.push_back(rv_crew_member(ret[i][0], ret[i][1], ret[i][2], turret_path, ret[i][4]));
            }

            return crew_members;
        }

        std::vector<std::string> get_artillery_ammo(const std::vector<object>& units_) {
            std::vector<game_value> units;
            for (auto &it : units_)
                units.push_back(it);

            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__getartilleryammo__array__ret__array, units));
        }

        vector3 get_center_of_mass(const object &obj_) {
            return __helpers::__convert_to_vector3(host::functions.invoke_raw_unary(client::__sqf::unary__getcenterofmass__object__ret__array, obj_));
        }

        std::vector<float> get_dlcs(float filter_) {
            return __helpers::__convert_to_numbers_vector(host::functions.invoke_raw_unary(client::__sqf::unary__getdlcs__scalar__ret__array, filter_));
        }

        /* Core */
        object player() {
            return object(host::functions.invoke_raw_nular(client::__sqf::nular__player__ret__object));
        }

        object create_vehicle(const std::string &type_, const vector3 &pos_) {
            return object(host::functions.invoke_raw_binary(__sqf::binary__createvehicle__string__array__ret__object, type_, pos_));
        }

        object create_vehicle(const std::string &type_, const vector3 &pos_, const std::vector<marker> &markers_, float placement_, const std::string &special_) {
            std::vector<game_value> markers;
            for (auto it : markers_) {
                markers.push_back(it);
            }
            game_value args({
                type_,
                pos_,
                markers,
                placement_,
                special_
            });

            return object(host::functions.invoke_raw_unary(__sqf::unary__createvehicle__array__ret__object, args));
        }

        void delete_vehicle(const object &obj_) {
            host::functions.invoke_raw_unary(__sqf::unary__deletevehicle__object__ret__nothing, obj_);
        }

        void create_unit(const std::string &type_, const vector3 &pos_, const group &group_, const std::string &init_, float skill_, const std::string &rank_) {
            game_value args({
                pos_,
                group_,
                init_,
                skill_,
                rank_
            });

            host::functions.invoke_raw_binary(__sqf::binary__createunit__string__array__ret__nothing, type_, args);
        }

        object create_unit(const group &group_, const std::string &type_, const vector3 &pos_, const std::vector<marker> &markers_, float placement_, const std::string &special_) {
            std::vector<game_value> markers;
            for (auto it : markers_) {
                markers.push_back(it);
            }
            game_value args({
                type_,
                pos_,
                markers,
                placement_,
                special_
            });

            return object(host::functions.invoke_raw_binary(__sqf::binary__createunit__group__array__ret__object, group_, args));
        }

        std::vector<object> all_curators() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__allcurators__ret__array));
        }

        std::vector<object> all_dead() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__alldead__ret__array));
        }

        std::vector<object> all_deadmen() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__alldeadmen__ret__array));
        }

        std::vector<display> all_displays() {
            return __helpers::__convert_to_displays_vector(host::functions.invoke_raw_nular(client::__sqf::nular__alldisplays__ret__array));
        }

        std::vector<group> all_groups() {
            return __helpers::__convert_to_groups_vector(host::functions.invoke_raw_nular(client::__sqf::nular__allgroups__ret__array));
        }

        std::vector<object> all_mines() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__allmines__ret__array));
        }

        std::vector<object> all_players() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__allplayers__ret__array));
        }

        std::vector<object> all_units() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__allunits__ret__array));
        }

        std::vector<object> all_units_uav() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__allunitsuav__ret__array));
        }

        float server_time() {
            return game_value(host::functions.invoke_raw_nular(client::__sqf::nular__servertime__ret__scalar));
        }

        std::string server_name() {
            return game_value(host::functions.invoke_raw_nular(client::__sqf::nular__servername__ret__string));
        }

        bool is_null(const object &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isnull__object__ret__bool, value_));
        }



        bool is_null(const control &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isnull__control__ret__bool, value_));
        }

        bool is_null(const display &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isnull__display__ret__bool, value_));
        }

        bool is_null(const script &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isnull__script__ret__bool, value_));
        }

        bool is_null(const task &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isnull__task__ret__bool, value_));
        }

        script script_null() {
            return script(host::functions.invoke_raw_nular(client::__sqf::nular__scriptnull__ret__script));
        }

        task task_null() {
            return task(host::functions.invoke_raw_nular(client::__sqf::nular__tasknull__ret__task));
        }

        rv_namespace ui_namespace() {
            return rv_namespace(host::functions.invoke_raw_nular(client::__sqf::nular__uinamespace__ret__namespace));
        }

        

        bool __sqfassert(bool test_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isnull__script__ret__bool, test_));
        }

        std::vector<std::string> all_turrets(const object &vehicle_, bool person_turrets_) {
            game_value array_input(std::vector<game_value>{
                vehicle_,
                person_turrets_
            });

            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(
                client::__sqf::unary__allturrets__array__ret__array, array_input));
        }

        std::vector<std::string> all_turrets(const object &vehicle_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(
                client::__sqf::unary__allturrets__object__ret__array, vehicle_));
        }

        std::vector<std::string> all_variables(const object &value_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(
                client::__sqf::unary__allvariables__object__ret__array, value_));
        }
        std::vector<std::string> all_variables(const team_member &value_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(
                client::__sqf::unary__allvariables__team_member__ret__array, value_));
        }
        std::vector<std::string> all_variables(rv_namespace value_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(
                client::__sqf::unary__allvariables__namespace__ret__array, value_));
        }

        std::vector<std::string> all_variables(const task &value_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(
                client::__sqf::unary__allvariables__task__ret__array, value_));
        }


        std::vector<std::string> all_variables(const control &value_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(
                client::__sqf::unary__allvariables__control__ret__array, value_));
        }

        

        /* Misc */
        float acc_time() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__acctime__ret__scalar);
        }

        object agent(const team_member &value_) {
            return object(host::functions.invoke_raw_unary(client::__sqf::unary__agent__team_member__ret__object, value_));
        }

        std::vector<std::string> activated_addons() {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_nular(client::__sqf::nular__activatedaddons__ret__array));
        }

        std::vector<team_member> agents() {
            return __helpers::__convert_to_team_members_vector(host::functions.invoke_raw_nular(client::__sqf::nular__agents__ret__array));
        }

        float armory_points() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__armorypoints__ret__scalar);
        }

        float benchmark() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__benchmark__ret__scalar);
        }

        side blufor() {
            return __helpers::__retrieve_nular_side(client::__sqf::nular__blufor__ret__side);
        }

        std::string briefing_name() {
            return __helpers::__retrieve_nular_string(client::__sqf::nular__briefingname__ret__string);
        }

        bool cadet_mode() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__cadetmode__ret__bool);
        }

        object camera_on() {
            return __helpers::__retrieve_nular_object(client::__sqf::nular__cameraon__ret__object);
        }



        bool cheats_enabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__cheatsenabled__ret__bool);
        }

        side civilian() {
            return __helpers::__retrieve_nular_side(client::__sqf::nular__civilian__ret__side);
        }

        void clear_forces_rtd() {
            __helpers::__empty_nular(client::__sqf::nular__clearforcesrtd__ret__nothing);
        }

        void clear_item_pool() {
            __helpers::__empty_nular(client::__sqf::nular__clearitempool__ret__nothing);
        }

        void clear_magazine_pool() {
            __helpers::__empty_nular(client::__sqf::nular__clearmagazinepool__ret__nothing);
        }

        void clear_radio() {
            __helpers::__empty_nular(client::__sqf::nular__clearradio__ret__nothing);
        }

        void clear_weapon_pool() {
            __helpers::__empty_nular(client::__sqf::nular__clearweaponpool__ret__nothing);
        }

        float client_owner() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__clientowner__ret__scalar);
        }

        std::string commanding_menu() {
            return __helpers::__retrieve_nular_string(client::__sqf::nular__commandingmenu__ret__string);
        }

        std::string copy_from_clipboard() {
            return __helpers::__retrieve_nular_string(client::__sqf::nular__copyfromclipboard__ret__string);
        }

        rv_namespace current_namespace() {
            return __helpers::__retrieve_nular_namespace(client::__sqf::nular__currentnamespace__ret__namespace);
        }

        object cursor_target() {
            return __helpers::__retrieve_nular_object(client::__sqf::nular__cursortarget__ret__object);
        }

        float daytime() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__daytime__ret__scalar);
        }

        bool dialog() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__dialog__ret__bool);
        }

        float difficulty() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__difficulty__ret__scalar);
        }

        bool difficulty_enabled_rtd() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__difficultyenabledrtd__ret__bool);
        }

        void disable_debriefing_stats() {
            __helpers::__empty_nular(client::__sqf::nular__disabledebriefingstats__ret__nothing);
        }

        void disable_serialization() {
            __helpers::__empty_nular(client::__sqf::nular__disableserialization__ret__nothing);
        }

        display display_null() {
            return __helpers::__retrieve_nular_display(client::__sqf::nular__displaynull__ret__display);
        }

        float distribution_region() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__distributionregion__ret__scalar);
        }

        side east() {
            return __helpers::__retrieve_nular_side(client::__sqf::nular__east__ret__side);
        }

        void enable_end_dialog() {
            __helpers::__empty_nular(client::__sqf::nular__enableenddialog__ret__nothing);
        }

        void end_loading_screen() {
            __helpers::__empty_nular(client::__sqf::nular__endloadingscreen__ret__nothing);
        }

        float estimated_end_server_time() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__estimatedendservertime__ret__scalar);
        }

        void exit() {
            __helpers::__empty_nular(client::__sqf::nular__exit__ret__nothing);
        }

        void finish_mission_init() {
            __helpers::__empty_nular(client::__sqf::nular__finishmissioninit__ret__nothing);
        }



        // TODO std::vector<float> fog_params();

        void force_end() {
            __helpers::__empty_nular(client::__sqf::nular__forceend__ret__nothing);
        }

        void force_weather_change() {
            __helpers::__empty_nular(client::__sqf::nular__forceweatherchange__ret__nothing);
        }

        bool free_look() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__freelook__ret__bool);
        }



        std::string getclientstate() {
            return __helpers::__retrieve_nular_string(client::__sqf::nular__getclientstate__ret__string);
        }

        float getelevationoffset() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__getelevationoffset__ret__scalar);
        }

        // TODO std::array<float, 2> get_mouse_position();
        // TODO std::array<float, 2> get_object_view_distance();

        bool get_remote_sensors_disabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__getremotesensorsdisabled__ret__bool);
        }

        // TODO std::array<float, 6> get_resolution();
        float get_shadow_distance() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__getshadowdistance__ret__scalar);
        }

        float get_total_dlc_usage_time() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__gettotaldlcusagetime__ret__scalar);
        }

        void halt() {
            __helpers::__empty_nular(client::__sqf::nular__halt__ret__nothing);
        }

        bool has_interface() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__hasinterface__ret__bool);
        }

        side independent() {
            return __helpers::__retrieve_nular_side(client::__sqf::nular__independent__ret__side);
        }

        void init_ambient_life() {
            __helpers::__empty_nular(client::__sqf::nular__initambientlife__ret__nothing);
        }

        bool is_autotest() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__isautotest__ret__bool);
        }

        bool is_filepatching_enabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__isfilepatchingenabled__ret__bool);
        }

        bool is_instructor_figure_enabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__isinstructorfigureenabled__ret__bool);
        }

        bool is_pip_enabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__ispipenabled__ret__bool);
        }

        bool is_steam_mission() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__issteammission__ret__bool);
        }

        bool is_stream_friendly_ui_enabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__isstreamfriendlyuienabled__ret__bool);
        }

        bool is_stress_damage_enabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__isstressdamageenabled__ret__bool);
        }

        bool is_tut_hints_enabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__istuthintsenabled__ret__bool);
        }

        std::string language() {
            return __helpers::__retrieve_nular_string(client::__sqf::nular__language__ret__string);
        }

        std::vector<rv_credit> library_credits() {
            game_value input = host::functions.invoke_raw_nular(client::__sqf::nular__librarycredits__ret__array);

            std::vector<rv_credit> output;
            for (uint32_t i = 0; i < input.length(); ++i) {
                output.push_back(input[i]);
            }
            return output;
        }

        std::vector<std::string> library_disclaimers() {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_nular(client::__sqf::nular__librarydisclaimers__ret__array));
        }

        std::string line_break() {
            return game_value(host::functions.invoke_raw_nular(client::__sqf::nular__linebreak__ret__text));
        }

        void load_game() {
            __helpers::__empty_nular(client::__sqf::nular__loadgame__ret__nothing);
        }



        void log_entities() {
            __helpers::__empty_nular(client::__sqf::nular__logentities__ret__nothing);
        }

        bool mark_as_finished_on_steam() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__markasfinishedonsteam__ret__bool);
        }

        float mission_difficulty() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__missiondifficulty__ret__scalar);
        }

        std::string mission_name() {
            return __helpers::__retrieve_nular_string(client::__sqf::nular__missionname__ret__string);
        }

        rv_namespace mission_namespace() {
            return __helpers::__retrieve_nular_namespace(client::__sqf::nular__missionnamespace__ret__namespace);
        }

        // TODO std::array<float, 6> mission_start();

        float music_volume() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__musicvolume__ret__scalar);
        }

        object obj_null() {
            return __helpers::__retrieve_nular_object(client::__sqf::nular__objnull__ret__object);
        }

        side opfor() {
            return __helpers::__retrieve_nular_side(client::__sqf::nular__opfor__ret__side);
        }

        rv_namespace parsing_namespace() {
            return __helpers::__retrieve_nular_namespace(client::__sqf::nular__parsingnamespace__ret__namespace);
        }

        float particles_quality() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__particlesquality__ret__scalar);
        }

        float pi() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__pi__ret__scalar);
        }

        float pixel_h() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__pixelh__ret__scalar);
        }

        float pixel_w() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__pixelw__ret__scalar);
        }

        std::vector<object> playable_units() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__playableunits__ret__array));
        }

        float player_respawn_time() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__playerrespawntime__ret__scalar);
        }

        side player_side() {
            return __helpers::__retrieve_nular_side(client::__sqf::nular__playerside__ret__side);
        }

        std::string profile_name() {
            return __helpers::__retrieve_nular_string(client::__sqf::nular__profilename__ret__string);
        }
        rv_namespace profile_namespace() {
            return __helpers::__retrieve_nular_namespace(client::__sqf::nular__profilenamespace__ret__namespace);
        }

        std::string profile_namesteam() {
            return __helpers::__retrieve_nular_string(client::__sqf::nular__profilenamesteam__ret__string);
        }



        side resistance() {
            return __helpers::__retrieve_nular_side(client::__sqf::nular__resistance__ret__side);
        }

        bool reversed_mouse_y() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__reversedmousey__ret__bool);
        }

        void run_init_script() {
            __helpers::__empty_nular(client::__sqf::nular__runinitscript__ret__nothing);
        }

        

        float view_distance() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__viewdistance__ret__scalar);
        }

        bool team_switch_enabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__teamswitchenabled__ret__bool);
        }

        void team_switch() {
            __helpers::__empty_nular(client::__sqf::nular__teamswitch__ret__nothing);
        }

        float system_of_units() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__systemofunits__ret__scalar);
        }

        std::vector<object> switchable_units() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(client::__sqf::nular__switchableunits__ret__array));
        }

        float sound_volume() {
            return __helpers::__retrieve_nular_number(client::__sqf::nular__soundvolume__ret__scalar);
        }

        bool sling_load_assistant_shown() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__slingloadassistantshown__ret__bool);
        }

        void simul_weather_sync() {
            __helpers::__empty_nular(client::__sqf::nular__simulweathersync__ret__nothing);
        }

        void select_no_player() {
            __helpers::__empty_nular(client::__sqf::nular__selectnoplayer__ret__nothing);
        }

        bool saving_enabled() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__savingenabled__ret__bool);
        }

        void save_profile_namespace() {
            __helpers::__empty_nular(client::__sqf::nular__saveprofilenamespace__ret__nothing);
        }

        std::string action_name(const std::string & action_) {
            return __helpers::__string_unary_string(client::__sqf::unary__actionname__string__ret__string, action_);
        }

        void activate_key(const std::string & keyname_) {
            __helpers::__empty_unary_string(client::__sqf::unary__activatekey__string__ret__nothing, keyname_);
        }

        void add_switchable_unit(const object & unit_) {
            __helpers::__empty_unary_object(client::__sqf::unary__addswitchableunit__object__ret__nothing, unit_);
        }

        float air_density_rtd(float altitude_) {
            return __helpers::__number_unary_number(client::__sqf::unary__airdensityrtd__scalar__ret__scalar, altitude_);
        }

        void airport_side(int id_) {
            __helpers::__empty_unary_number(client::__sqf::unary__airportside__object_scalar__ret__nothing, (float)id_);
        }
        void airport_side(const object & target_) {
            __helpers::__empty_unary_number(client::__sqf::unary__airportside__object_scalar__ret__nothing, target_);
        }

        bool alive(const object & obj_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__alive__object__ret__bool, obj_);
        }

        std::string animation_state(const object & unit_) {
            return __helpers::__string_unary_object(client::__sqf::unary__animationstate__object__ret__string, unit_);
        }

        object assigned_commander(const object & veh_) {
            return __helpers::__object_unary_object(client::__sqf::unary__assignedcommander__object__ret__object, veh_);
        }

        object assigned_driver(const object & veh_) {
            return __helpers::__object_unary_object(client::__sqf::unary__assigneddriver__object__ret__object, veh_);
        }

        object assigned_gunner(const object & veh_) {
            return __helpers::__object_unary_object(client::__sqf::unary__assignedgunner__object__ret__object, veh_);
        }

        object assigned_target(const object & veh_) {
            return __helpers::__object_unary_object(client::__sqf::unary__assignedtarget__object__ret__object, veh_);
        }

        std::string assigned_team(const object & unit_) {
            return __helpers::__string_unary_object(client::__sqf::unary__assignedteam__object__ret__string, unit_);
        }

        object assigned_vehicle(const object & unit_) {
            return __helpers::__object_unary_object(client::__sqf::unary__assignedvehicle__object__ret__object, unit_);
        }



        std::string behaviour(const object & unit_) {
            return __helpers::__string_unary_object(client::__sqf::unary__behaviour__object__ret__string, unit_);
        }

        std::string binocular(const object & unit_) {
            return __helpers::__string_unary_object(client::__sqf::unary__binocular__object__ret__string, unit_);
        }

        void buldozer(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__buldozer_enableroaddiag__bool__ret__nothing, value_);
        }

        bool buldozer(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__buldozer_loadnewroads__string__ret__bool, value_);
        }

        void set_particle_params(const object & particle_source_, const rv_particle_array & particle_array_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setparticlecircle__object__array__ret__nothing, particle_source_, particle_array_);
        }

        void set_particle_random(const object & particle_source_, const rv_particle_random & particle_random_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setparticlerandom__object__array__ret__nothing, particle_source_, particle_random_);
        }

        void set_particle_circle(const object & particle_source_, float radius_, const vector3 & velocity_) {
            std::vector<game_value> args{
                radius_,
                velocity_
            };
            host::functions.invoke_raw_binary(client::__sqf::binary__setparticlecircle__object__array__ret__nothing, particle_source_, args);
        }

        void set_particle_fire(const object & particle_source_, float core_intensity_, float core_distance_, float damage_time_) {
            std::vector<game_value> args{
                core_intensity_,
                core_distance_,
                damage_time_
            };
            host::functions.invoke_raw_binary(client::__sqf::binary__setparticlefire__object__array__ret__nothing, particle_source_, args);
        }

        void drop(const rv_particle_array & particle_array_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__drop__array__ret__nothing, particle_array_);
        }

        

        bool can_fire(const object & unit_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__canfire__object__ret__bool, unit_);
        }

        bool can_move(const object & unit_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__canmove__object__ret__bool, unit_);
        }

        bool can_stand(const object & unit_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__canstand__object__ret__bool, unit_);
        }

        bool can_unload_in_combat(const object & unit_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__canunloadincombat__object__ret__bool, unit_);
        }

        bool captive(const object & unit_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__captive__object__ret__bool, unit_);
        }

        float captive_num(const object & unit_) {
            return __helpers::__number_unary_object(client::__sqf::unary__captivenum__object__ret__scalar, unit_);
        }

        bool check_aifeature(const std::string & feature_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__checkaifeature__string__ret__bool, feature_);
        }

        float collective_rtd(const object & helicopter_) {
            return __helpers::__number_unary_object(client::__sqf::unary__collectivertd__object__ret__scalar, helicopter_);
        }

        object commander(const object & veh_) {
            return __helpers::__object_unary_object(client::__sqf::unary__commander__object__ret__object, veh_);
        }
        bool completed_fsm(float handle_) {
            return __helpers::__bool_unary_number(client::__sqf::unary__completedfsm__scalar__ret__bool, handle_);
        }

        void copy_to_clipboard(const std::string & text_) {
            __helpers::__empty_unary_string(client::__sqf::unary__copytoclipboard__string__ret__nothing, text_);
        }

        void create_vehicle_crew(const object & veh_) {
            __helpers::__empty_unary_object(client::__sqf::unary__createvehiclecrew__object__ret__nothing, veh_);
        }

        std::string current_command(const object & veh_) {
            return __helpers::__string_unary_object(client::__sqf::unary__currentcommand__object__ret__string, veh_);
        }

       
        int current_vision_mode(const object & unit_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__currentvisionmode__object__ret__scalar, unit_));
        }



        float current_zeroing(const object & gunner_) {
            return __helpers::__number_unary_object(client::__sqf::unary__currentzeroing__object__ret__scalar, gunner_);
        }

        float damage(const object & object_) {
            return __helpers::__number_unary_object(client::__sqf::unary__damage__object__ret__scalar, object_);
        }

        void de_activate_key(const std::string & key_) {
            __helpers::__empty_unary_string(client::__sqf::unary__deactivatekey__string__ret__nothing, key_);
        }

        float debriefing_text(const std::string & debriefing_) {
            return __helpers::__number_unary_string(client::__sqf::unary__debriefingtext__string__ret__scalar, debriefing_);
        }

        void delete_collection(const object & collection_) {
            __helpers::__empty_unary_object(client::__sqf::unary__deletecollection__object__ret__nothing, collection_);
        }

        bool delete_identity(const std::string & identity_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__deleteidentity__string__ret__bool, identity_);
        }

        void delete_site(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__deletesite__object__ret__nothing, value_);
        }

        bool delete_status(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__deletestatus__string__ret__bool, value_);
        }

        void detach(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__detach__object__ret__nothing, value_);
        }

        bool did_jipowner(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__didjipowner__object__ret__bool, value_);
        }

        bool difficulty_enabled(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__difficultyenabled__string__ret__bool, value_);
        }




        void disable_remote_sensors(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__disableremotesensors__bool__ret__nothing, value_);
        }

        void disable_user_input(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__disableuserinput__bool__ret__nothing, value_);
        }

        void dissolve_team(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__dissolveteam__string__ret__nothing, value_);
        }

        object driver(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__driver__object__ret__object, value_);
        }

        void echo(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__echo__string__ret__nothing, value_);
        }

        object effective_commander(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__effectivecommander__object__ret__object, value_);
        }



        void enable_caustics(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__enablecaustics__bool__ret__nothing, value_);
        }

        void enable_diag_legend(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__enablediaglegend__bool__ret__nothing, value_);
        }

        void enable_engine_artillery(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__enableengineartillery__bool__ret__nothing, value_);
        }

        void enable_environment(bool ambient_life_, bool ambient_sound_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__enableenvironment__bool_array__ret__nothing, { ambient_life_, ambient_sound_ });
        }

        void enable_radio(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__enableradio__bool__ret__nothing, value_);
        }

        void enable_sat_normal_on_detail(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__enablesatnormalondetail__bool__ret__nothing, value_);
        }

        void enable_sentences(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__enablesentences__bool__ret__nothing, value_);
        }

        void enable_stress_damage(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__enablestressdamage__bool__ret__nothing, value_);
        }

        void enable_team_switch(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__enableteamswitch__bool__ret__nothing, value_);
        }

        void enable_traffic(bool value_) {
            __helpers::__empty_unary_bool(client::__sqf::unary__enabletraffic__bool__ret__nothing, value_);
        }

        void end_mission(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__endmission__string__ret__nothing, value_);
        }

        void estimated_time_left(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__estimatedtimeleft__scalar__ret__nothing, value_);
        }

        float exec_fsm(const std::string &value_) {
            return __helpers::__number_unary_string(client::__sqf::unary__execfsm__string__ret__scalar, value_);
        }

        void export_jipmessages(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__exportjipmessages__string__ret__nothing, value_);
        }

        std::string face(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__face__object__ret__string, value_);
        }

        std::string faction(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__faction__object__ret__string, value_);
        }

        void fail_mission(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__failmission__string__ret__nothing, value_);
        }

        void fill_weapons_from_pool(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__fillweaponsfrompool__object__ret__nothing, value_);
        }

        bool finite(float value_) {
            return __helpers::__bool_unary_number(client::__sqf::unary__finite__scalar_nan__ret__bool, value_);
        }


        object flag(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__flag__object__ret__object, value_);
        }

        object flag_owner(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__flagowner__object__ret__object, value_);
        }

        std::string flag_texture(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__flagtexture__object__ret__string, value_);
        }

        bool fleeing(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__fleeing__object__ret__bool, value_);
        }

        void force_respawn(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__forcerespawn__object__ret__nothing, value_);
        }

        object form_leader(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__formleader__object__ret__object, value_);
        }

        float formation_direction(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__formationdirection__object__ret__scalar, value_);
        }

        object formation_leader(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__formationleader__object__ret__object, value_);
        }

        std::string formation_task(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__formationtask__object__ret__string, value_);
        }

        float fuel(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__fuel__object__ret__scalar, value_);
        }

        float gear_idcammo_count(float value_) {
            return __helpers::__number_unary_number(client::__sqf::unary__gearidcammocount__scalar__ret__scalar, value_);
        }

        float get_aiming_coef(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getaimingcoef__object__ret__scalar, value_);
        }

        float get_ammo_cargo(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getammocargo__object__ret__scalar, value_);
        }

        float get_anim_aim_precision(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getanimaimprecision__object__ret__scalar, value_);
        }

        float get_anim_speed_coef(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getanimspeedcoef__object__ret__scalar, value_);
        }

        float get_bleeding_remaining(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getbleedingremaining__object__ret__scalar, value_);
        }

        float get_burning_value(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getburningvalue__object__ret__scalar, value_);
        }

        object get_connected_uav(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__getconnecteduav__object__ret__object, value_);
        }

        float get_custom_aim_coef(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getcustomaimcoef__object__ret__scalar, value_);
        }

        float get_dlcusage_time(float value_) {
            return __helpers::__number_unary_number(client::__sqf::unary__getdlcusagetime__scalar__ret__scalar, value_);
        }

        float get_dammage(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getdammage__object__ret__scalar, value_);
        }

        float get_dir(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getdir__object__ret__scalar, value_);
        }

        float get_dir_visual(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getdirvisual__object__ret__scalar, value_);
        }

        float get_fatigue(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getfatigue__object__ret__scalar, value_);
        }

        float get_fuel_cargo(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getfuelcargo__object__ret__scalar, value_);
        }

        float get_mass(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getmass__object__ret__scalar, value_);
        }

        float get_object_dlc(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getobjectdlc__object__ret__scalar, value_);
        }

        float get_object_type(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getobjecttype__object__ret__scalar, value_);
        }

        float get_oxygen_remaining(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getoxygenremaining__object__ret__scalar, value_);
        }

        std::string get_player_uid(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__getplayeruid__object__ret__string, value_);
        }

        float get_repair_cargo(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getrepaircargo__object__ret__scalar, value_);
        }

        float get_rotor_brake_rtd(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getrotorbrakertd__object__ret__scalar, value_);
        }

        object get_sling_load(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__getslingload__object__ret__object, value_);
        }

        float get_stamina(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getstamina__object__ret__scalar, value_);
        }

        float get_stat_value(const std::string &value_) {
            return __helpers::__number_unary_string(client::__sqf::unary__getstatvalue__string__ret__scalar, value_);
        }

        float get_suppression(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getsuppression__object__ret__scalar, value_);
        }

        float get_weapon_sway(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getweaponsway__object__ret__scalar, value_);
        }

        float get_wings_orientation_rtd(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getwingsorientationrtd__object__ret__scalar, value_);
        }

        float get_wings_position_rtd(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__getwingspositionrtd__object__ret__scalar, value_);
        }

        std::string goggles(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__goggles__object__ret__string, value_);
        }

        object gunner(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__gunner__object__ret__object, value_);
        }

        float hands_hit(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__handshit__object__ret__scalar, value_);
        }

        void hc_remove_all_groups(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__hcremoveallgroups__object__ret__nothing, value_);
        }


        std::string headgear(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__headgear__object__ret__string, value_);
        }

        void hide_body(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__hidebody__object__ret__nothing, value_);
        }

        void hide_object(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__hideobject__object__ret__nothing, value_);
        }

        void hide_object_global(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__hideobjectglobal__object__ret__nothing, value_);
        }

        void hint_c(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__hintc__string__ret__nothing, value_);
        }

        std::string hmd(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__hmd__object__ret__string, value_);
        }

        std::string incapacitated_state(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__incapacitatedstate__object__ret__string, value_);
        }

        bool inflamed(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__inflamed__object__ret__bool, value_);
        }

        float input_action(const std::string &value_) {
            return __helpers::__number_unary_string(client::__sqf::unary__inputaction__string__ret__scalar, value_);
        }

        bool is_able_to_breathe(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isabletobreathe__object__ret__bool, value_);
        }

        bool is_aim_precision_enabled(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isaimprecisionenabled__object__ret__bool, value_);
        }

        bool is_auto_hover_on(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isautohoveron__object__ret__bool, value_);
        }

        bool is_auto_trim_on_rtd(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isautotrimonrtd__object__ret__bool, value_);
        }

        bool is_autonomous(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isautonomous__object__ret__bool, value_);
        }

        bool is_bleeding(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isbleeding__object__ret__bool, value_);
        }

        bool is_burning(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isburning__object__ret__bool, value_);
        }

        bool is_collision_light_on(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__iscollisionlighton__object__ret__bool, value_);
        }

        bool is_copilot_enabled(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__iscopilotenabled__object__ret__bool, value_);
        }

        bool is_dlcavailable(float value_) {
            return __helpers::__bool_unary_number(client::__sqf::unary__isdlcavailable__scalar__ret__bool, value_);
        }

        bool is_engine_on(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isengineon__object__ret__bool, value_);
        }

        bool is_forced_walk(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isforcedwalk__object__ret__bool, value_);
        }

        bool is_formation_leader(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isformationleader__object__ret__bool, value_);
        }

        bool is_hidden(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__ishidden__object__ret__bool, value_);
        }

        bool is_in_remains_collector(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isinremainscollector__object__ret__bool, value_);
        }

        bool is_key_active(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__iskeyactive__string__ret__bool, value_);
        }

        bool is_light_on(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__islighton__object__ret__bool, value_);
        }

        bool is_localized(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__islocalized__string__ret__bool, value_);
        }

        bool is_manual_fire(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__ismanualfire__object__ret__bool, value_);
        }

        bool is_marked_for_collection(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__ismarkedforcollection__object__ret__bool, value_);
        }

        bool is_object_hidden(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isobjecthidden__object__ret__bool, value_);
        }

        bool is_object_rtd(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isobjectrtd__object__ret__bool, value_);
        }

        bool is_player(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isplayer__object__ret__bool, value_);
        }

        bool is_sprint_allowed(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__issprintallowed__object__ret__bool, value_);
        }

        bool is_stamina_enabled(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isstaminaenabled__object__ret__bool, value_);
        }

        bool is_touching_ground(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__istouchingground__object__ret__bool, value_);
        }

        bool is_turned_out(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isturnedout__object__ret__bool, value_);
        }

        bool is_uavconnected(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isuavconnected__object__ret__bool, value_);
        }

        bool is_walking(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__iswalking__object__ret__bool, value_);
        }

        bool is_weapon_deployed(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isweapondeployed__object__ret__bool, value_);
        }

        bool is_weapon_rested(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__isweaponrested__object__ret__bool, value_);
        }

        std::string land_result(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__landresult__object__ret__string, value_);
        }

        object laser_target(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__lasertarget__object__ret__object, value_);
        }

        object leader(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__leader__object__ret__object, value_);
        }

        bool leaderboard_de_init(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__leaderboarddeinit__string__ret__bool, value_);
        }

        bool leaderboard_init(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__leaderboardinit__string__ret__bool, value_);
        }

        bool leaderboard_request_rows_friends(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__leaderboardrequestrowsfriends__string__ret__bool, value_);
        }

        float leaderboard_state(const std::string &value_) {
            return __helpers::__number_unary_string(client::__sqf::unary__leaderboardstate__string__ret__scalar, value_);
        }

        std::string life_state(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__lifestate__object__ret__string, value_);
        }

        void light_detach_object(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__lightdetachobject__object__ret__nothing, value_);
        }

        std::string light_is_on(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__lightison__object__ret__string, value_);
        }

        

        std::string load_file(const std::string &value_) {
            return __helpers::__string_unary_string(client::__sqf::unary__loadfile__string__ret__string, value_);
        }



        std::string localize(const std::string &value_) {
            return __helpers::__string_unary_string(client::__sqf::unary__localize__string__ret__string, value_);
        }

        bool lock_identity(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__lockidentity__object__ret__bool, value_);
        }

        float locked(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__locked__object__ret__scalar, value_);
        }

        bool locked_driver(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__lockeddriver__object__ret__bool, value_);
        }

        bool mine_active(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__mineactive__object__ret__bool, value_);
        }

        float morale(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__morale__object__ret__scalar, value_);
        }

        void move_out(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__moveout__object__ret__nothing, value_);
        }

        float move_time(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__movetime__object__ret__scalar, value_);
        }

        bool move_to_completed(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__movetocompleted__object__ret__bool, value_);
        }

        bool move_to_failed(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__movetofailed__object__ret__bool, value_);
        }

        std::string name(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__name__object__ret__string, value_);
        }



        std::string name_sound(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__namesound__object__ret__string, value_);
        }

        object nearest_building(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__nearestbuilding__object__ret__object, value_);
        }

        object nearest_building(const vector3 &value_) {
            return object(host::functions.invoke_raw_unary(client::__sqf::unary__nearestbuilding__array__ret__object, value_));
        }

        float need_reload(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__needreload__object__ret__scalar, value_);
        }

        std::string net_id(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__netid__object__ret__string, value_);
        }
        float number_of_engines_rtd(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__numberofenginesrtd__object__ret__scalar, value_);
        }

        object object_parent(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__objectparent__object__ret__object, value_);
        }

        void on_briefing_group(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__onbriefinggroup__string__ret__nothing, value_);
        }

        void on_briefing_notes(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__onbriefingnotes__string__ret__nothing, value_);
        }

        void on_briefing_plan(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__onbriefingplan__string__ret__nothing, value_);
        }

        void on_briefing_team_switch(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__onbriefingteamswitch__string__ret__nothing, value_);
        }

        bool open_dlc_page(float value_) {
            return __helpers::__bool_unary_number(client::__sqf::unary__opendlcpage__scalar__ret__bool, value_);
        }

        bool open_youtube_video(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__openyoutubevideo__string__ret__bool, value_);
        }

        float owner(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__owner__object__ret__scalar, value_);
        }

        float parse_number(const std::string &value_) {
            return __helpers::__number_unary_string(client::__sqf::unary__parsenumber__string__ret__scalar, value_);
        }

        void pick_weapon_pool(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__pickweaponpool__object__ret__nothing, value_);
        }

        std::string pitch(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__pitch__object__ret__string, value_);
        }

        void play_music(const std::string &class_) {
            __helpers::__empty_unary_string(client::__sqf::unary__playmusic__string__ret__nothing, class_);
        }

        void play_music(const std::string &class_, float start_) {
            std::vector<game_value> params{
                class_,
                start_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playmusic__array__ret__nothing, params);
        }

        void play_sound(const std::string &name_) {
            __helpers::__empty_unary_string(client::__sqf::unary__playsound__string__ret__nothing, name_);
        }

        void play_sound(const std::string &name_, bool force_) {
            std::vector<game_value> params{
                name_,
                force_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playsound__array__ret__nothing, params);
        }

        

        float precision(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__precision__object__ret__scalar, value_);
        }

        bool preload_sound(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__preloadsound__string__ret__bool, value_);
        }

        std::string preprocess_file(const std::string &value_) {
            return __helpers::__string_unary_string(client::__sqf::unary__preprocessfile__string__ret__string, value_);
        }

        std::string preprocess_file_line_numbers(const std::string &value_) {
            return __helpers::__string_unary_string(client::__sqf::unary__preprocessfilelinenumbers__string__ret__string, value_);
        }



        void process_diary_link(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__processdiarylink__string__ret__nothing, value_);
        }

        void progress_loading_screen(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__progressloadingscreen__scalar__ret__nothing, value_);
        }

        void public_variable(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__publicvariable__string__ret__nothing, value_);
        }

        void public_variable_server(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__publicvariableserver__string__ret__nothing, value_);
        }

        void put_weapon_pool(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__putweaponpool__object__ret__nothing, value_);
        }

        float query_items_pool(const std::string &value_) {
            return __helpers::__number_unary_string(client::__sqf::unary__queryitemspool__string__ret__scalar, value_);
        }

        float query_magazine_pool(const std::string &value_) {
            return __helpers::__number_unary_string(client::__sqf::unary__querymagazinepool__string__ret__scalar, value_);
        }

        float query_weapon_pool(const std::string &value_) {
            return __helpers::__number_unary_string(client::__sqf::unary__queryweaponpool__string__ret__scalar, value_);
        }

        std::string rank(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__rank__object__ret__string, value_);
        }

        float rank_id(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__rankid__object__ret__scalar, value_);
        }

        float rating(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__rating__object__ret__scalar, value_);
        }

        void reload(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__reload__object__ret__nothing, value_);
        }

        bool reload_enabled(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__reloadenabled__object__ret__bool, value_);
        }

        void remove_all_actions(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__removeallactions__object__ret__nothing, value_);
        }



        void remove_all_mission_event_handlers(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__removeallmissioneventhandlers__string__ret__nothing, value_);
        }

        void remove_all_music_event_handlers(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__removeallmusiceventhandlers__string__ret__nothing, value_);
        }

        void remove_switchable_unit(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__removeswitchableunit__object__ret__nothing, value_);
        }

        bool required_version(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__requiredversion__string__ret__bool, value_);
        }

        void reset_subgroup_direction(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__resetsubgroupdirection__object__ret__nothing, value_);
        }


        std::string role_description(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__roledescription__object__ret__string, value_);
        }

        bool rope_attach_enabled(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__ropeattachenabled__object__ret__bool, value_);
        }

        object rope_attached_to(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__ropeattachedto__object__ret__object, value_);
        }

        void rope_destroy(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__ropedestroy__object__ret__nothing, value_);
        }

        float rope_length(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__ropelength__object__ret__scalar, value_);
        }

        bool rope_unwound(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__ropeunwound__object__ret__bool, value_);
        }


        void save_var(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__savevar__string__ret__nothing, value_);
        }

        void scope_name(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__scopename__string__ret__nothing, value_);
        }

        float score(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__score__object__ret__scalar, value_);
        }

        void script_name(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__scriptname__string__ret__nothing, value_);
        }

        float scud_state(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__scudstate__object__ret__scalar, value_);
        }



        void select_player(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__selectplayer__object__ret__nothing, value_);
        }


        bool server_command(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__servercommand__string__ret__bool, value_);
        }

        bool server_command_available(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__servercommandavailable__string__ret__bool, value_);
        }

        bool server_command_executable(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__servercommandexecutable__string__ret__bool, value_);
        }

        void set_acc_time(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__setacctime__scalar__ret__nothing, value_);
        }



        void set_armory_points(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__setarmorypoints__scalar__ret__nothing, value_);
        }

        void set_horizon_parallax_coef(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__sethorizonparallaxcoef__scalar__ret__nothing, value_);
        }

        void set_object_view_distance(float distance_) {
            __helpers::__empty_unary_number(client::__sqf::unary__setobjectviewdistance__scalar__ret__nothing, distance_);
        }

        void set_object_view_distance(float object_distance_, float shadow_distance_) {
            std::vector<game_value> params{
                object_distance_,
                shadow_distance_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__setobjectviewdistance__array__ret__nothing, params);
        }

        void set_playable(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__setplayable__object__ret__nothing, value_);
        }

        void set_player_respawn_time(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__setplayerrespawntime__scalar__ret__nothing, value_);
        }

        void set_shadow_distance(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__setshadowdistance__scalar__ret__nothing, value_);
        }

        void set_simul_weather_layers(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__setsimulweatherlayers__scalar__ret__nothing, value_);
        }

        void set_stamina_scheme(const std::string &value_) {
            __helpers::__empty_unary_string(client::__sqf::unary__setstaminascheme__string__ret__nothing, value_);
        }

        void set_system_of_units(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__setsystemofunits__scalar__ret__nothing, value_);
        }

        void set_terrain_grid(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__setterraingrid__scalar__ret__nothing, value_);
        }

        void set_time_multiplier(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__settimemultiplier__scalar__ret__nothing, value_);
        }

        void set_traffic_distance(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__settrafficdistance__scalar__ret__nothing, value_);
        }

        void set_view_distance(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__setviewdistance__scalar__ret__nothing, value_);
        }

        bool simulation_enabled(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__simulationenabled__object__ret__bool, value_);
        }

        float size_of(const std::string &value_) {
            return __helpers::__number_unary_string(client::__sqf::unary__sizeof__string__ret__scalar, value_);
        }

        float skill(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__skill__object__ret__scalar, value_);
        }

        void skip_time(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__skiptime__scalar__ret__nothing, value_);
        }

        void sleep(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__sleep__scalar__ret__nothing, value_);
        }

        bool some_ammo(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__someammo__object__ret__bool, value_);
        }

        std::string speaker(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__speaker__object__ret__string, value_);
        }

        float speed(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__speed__object__ret__scalar, value_);
        }

        std::string stance(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__stance__object__ret__string, value_);
        }

        void stop_engine_rtd(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__stopenginertd__object__ret__nothing, value_);
        }

        bool stopped(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__stopped__object__ret__bool, value_);
        }

        std::string text(const std::string &value_) {
            return __helpers::__string_unary_string(client::__sqf::unary__text__location__ret__string, value_);
        }

        void title_fade_out(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__titlefadeout__scalar__ret__nothing, value_);
        }

        std::string to_lower(const std::string &value_) {
            return __helpers::__string_unary_string(client::__sqf::unary__tolower__string__ret__string, value_);
        }

        std::string to_upper(const std::string &value_) {
            return __helpers::__string_unary_string(client::__sqf::unary__toupper__string__ret__string, value_);
        }

       

        std::string type_of(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__typeof__object__ret__string, value_);
        }

        void uisleep(float value_) {
            __helpers::__empty_unary_number(client::__sqf::unary__uisleep__scalar__ret__nothing, value_);
        }

        void unassign_team(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__unassignteam__object__ret__nothing, value_);
        }

        void unassign_vehicle(const object &value_) {
            __helpers::__empty_unary_object(client::__sqf::unary__unassignvehicle__object__ret__nothing, value_);
        }

        bool underwater(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__underwater__object__ret__bool, value_);
        }

        std::string unit_pos(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__unitpos__object__ret__string, value_);
        }

        float unit_recoil_coefficient(const object &value_) {
            return __helpers::__number_unary_object(client::__sqf::unary__unitrecoilcoefficient__object__ret__scalar, value_);
        }

        bool unlock_achievement(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__unlockachievement__string__ret__bool, value_);
        }


        object vehicle(const object &value_) {
            return __helpers::__object_unary_object(client::__sqf::unary__vehicle__object__ret__object, value_);
        }

        std::string vehicle_var_name(const object &value_) {
            return __helpers::__string_unary_object(client::__sqf::unary__vehiclevarname__object__ret__string, value_);
        }

        bool verify_signature(const std::string &value_) {
            return __helpers::__bool_unary_string(client::__sqf::unary__verifysignature__string__ret__bool, value_);
        }

        bool waypoints_enabled_uav(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__waypointsenableduav__object__ret__bool, value_);
        }

        bool weapon_lowered(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__weaponlowered__object__ret__bool, value_);
        }

        // BINARY FUNCTIONS

        

        void add_live_stats(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__addlivestats__object__scalar__ret__nothing, value0_, value1_);
        }

        

        void add_rating(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__addrating__object__scalar__ret__nothing, value0_, value1_);
        }

        void add_score(const object &value0_,float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__addscore__object__scalar__ret__nothing, value0_, value1_);
        }

        void add_score_side(const side &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__addscoreside__side__scalar__ret__nothing, value0_, value1_);
        }

        

        void add_vehicle(const group &value0_, const object &value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__addvehicle__group__object__ret__nothing, value0_, value1_);
        }

        


        void allow_crew_in_immobile(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__allowcrewinimmobile__object__bool__ret__nothing, value0_, value1_);
        }

        void allow_damage(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__allowdamage__object__bool__ret__nothing, value0_, value1_);
        }

        void allow_dammage(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__allowdammage__object__bool__ret__nothing, value0_, value1_);
        }


        void allow_sprint(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__allowsprint__object__bool__ret__nothing, value0_, value1_);
        }

        float ammo(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__ammo__object__string__ret__scalar, value0_, value1_));
        }

        float animation_phase(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__animationphase__object__string__ret__scalar, value0_, value1_));
        }

        void assign_team(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__assignteam__object__string__ret__nothing, value0_, value1_);
        }

        void assign_to_airport(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__assigntoairport__object__object_scalar__ret__nothing, value0_, value1_);
        }

        void assign_to_airport(const object &value0_, const object &target_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__assigntoairport__object__object_scalar__ret__nothing, value0_, target_);
        }

        

        void debug_fsm(float value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__debugfsm__scalar__bool__ret__nothing, value0_, value1_);
        }

        bool diary_subject_exists(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__diarysubjectexists__object__string__ret__bool, value0_, value1_));
        }

        void direct_say(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__directsay__object__string__ret__nothing, value0_, value1_);
        }

        void disable_ai(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__disableai__object__string__ret__nothing, value0_, value1_);
        }

        void disable_conversation(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__disableconversation__object__bool__ret__nothing, value0_, value1_);
        }

        void disable_nvgequipment(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__disablenvgequipment__object__bool__ret__nothing, value0_, value1_);
        }

        void disable_tiequipment(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__disabletiequipment__object__bool__ret__nothing, value0_, value1_);
        }

        void display_remove_all_event_handlers(const std::string& value0_, const display &value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__displayremovealleventhandlers__display__string__ret__nothing, value0_, value1_);
        }

        float door_phase(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__doorphase__object__string__ret__scalar, value0_, value1_));
        }

        float empty_positions(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__emptypositions__object__string__ret__scalar, value0_, value1_));
        }

        void enable_ai(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enableai__object__string__ret__nothing, value0_, value1_);
        }

        void enable_aifeature(bool value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enableaifeature__string__bool__ret__nothing, value0_, value1_);
        }

        void enable_aim_precision(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enableaimprecision__object__bool__ret__nothing, value0_, value1_);
        }

        void enable_auto_start_up_rtd(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enableautostartuprtd__object__bool__ret__nothing, value0_, value1_);
        }

        bool enable_auto_trim_rtd(const object &value0_, bool value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__enableautotrimrtd__object__bool__ret__bool, value0_, value1_));
        }

        void enable_copilot(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enablecopilot__object__bool__ret__nothing, value0_, value1_);
        }

        void enable_fatigue(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enablefatigue__object__bool__ret__nothing, value0_, value1_);
        }

        void enable_mimics(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enablemimics__object__bool__ret__nothing, value0_, value1_);
        }

        void enable_reload(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enablereload__object__bool__ret__nothing, value0_, value1_);
        }

        void enable_rope_attach(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enableropeattach__object__bool__ret__nothing, value0_, value1_);
        }

        void enable_simulation(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enablesimulation__object__bool__ret__nothing, value0_, value1_);
        }

        void enable_simulation_global(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enablesimulationglobal__object__bool__ret__nothing, value0_, value1_);
        }

        void enable_stamina(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enablestamina__object__bool__ret__nothing, value0_, value1_);
        }

        void enable_uavwaypoints(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enableuavwaypoints__object__bool__ret__nothing, value0_, value1_);
        }

        void engine_on(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__engineon__object__bool__ret__nothing, value0_, value1_);
        }

        void fire(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__fire__object__string__ret__nothing, value0_, value1_);
        }

        void fly_in_height(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__flyinheight__object__scalar__ret__nothing, value0_, value1_);
        }

        void force_add_uniform(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__forceadduniform__object__string__ret__nothing, value0_, value1_);
        }

        void force_speed(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__forcespeed__object__scalar__ret__nothing, value0_, value1_);
        }

        void force_walk(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__forcewalk__object__bool__ret__nothing, value0_, value1_);
        }


        float get_hit(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__gethit__object__string__ret__scalar, value0_, value1_));
        }

        float get_hit_index(const object &value0_, float value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__gethitindex__object__scalar__ret__scalar, value0_, value1_));
        }

        float get_hit_point_damage(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__gethitpointdamage__object__string__ret__scalar, value0_, value1_));
        }


        float get_speed(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getspeed__object__string__ret__scalar, value0_, value1_));
        }

        void global_radio(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__globalradio__object__string__ret__nothing, value0_, value1_);
        }

        void hc_remove_group(const object &value0_, const group &value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__hcremovegroup__object__group__ret__nothing, value0_, value1_);
        }

        void hide_object(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__hideobject__object__bool__ret__nothing, value0_, value1_);
        }

        void hide_object_global(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__hideobjectglobal__object__bool__ret__nothing, value0_, value1_);
        }

        void hint_c(const std::string& value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__hintc__string__text__ret__nothing, value0_, value1_);
            // Identical from intercept's side: binary__hintc__string__string__ret__nothing
        }


        void inflame(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__inflame__object__bool__ret__nothing, value0_, value1_);
        }

        bool is_flashlight_on(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__isflashlighton__object__string__ret__bool, value0_, value1_));
        }

        bool is_irlaser_on(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__isirlaseron__object__string__ret__bool, value0_, value1_));
        }

        bool is_kind_of(const object &obj_, const std::string &type_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__iskindof__object__string__ret__bool, obj_, type_));
        }

        bool is_kind_of(const std::string &type1_, const std::string &type2_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__iskindof__string__string__ret__bool, type1_, type2_));
        }

        bool is_kind_of(const std::string &type1_, const std::string &type2_, const config &target_config_) {
            std::vector<game_value> params{
                type2_,
                target_config_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__iskindof__string__array__ret__bool, type1_, params));
        }

        bool kb_add_database(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__kbadddatabase__object__string__ret__bool, value0_, value1_));
        }

        bool kb_add_database_targets(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__kbadddatabasetargets__object__string__ret__bool, value0_, value1_));
        }

        bool kb_has_topic(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__kbhastopic__object__string__ret__bool, value0_, value1_));
        }

        void kb_remove_topic(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__kbremovetopic__object__string__ret__nothing, value0_, value1_);
        }

        float knows_about(const object &source_, const object &target_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__knowsabout__object_group__object__ret__scalar, source_, target_));
        }

        float knows_about(const group &source_, const object &target_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__knowsabout__object_group__object__ret__scalar, source_, target_));
        }

        float knows_about(const side &side_, const object &target_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__knowsabout__side__object__ret__scalar, side_, target_));
        }

        void land(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__land__object__string__ret__nothing, value0_, value1_);
        }

        void land_at(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__landat__object__object_scalar__ret__nothing, value0_, value1_);
        }

        void land_at(const object &value0_, const object & helipad_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__landat__object__object_scalar__ret__nothing, value0_, helipad_);
        }

        void leave_vehicle(const object &value0_, const group &value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__leavevehicle__group__object__ret__nothing, value0_, value1_);
        }

        void limit_speed(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__limitspeed__object__scalar__ret__nothing, value0_, value1_);
        }

        bool load_identity(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__loadidentity__object__string__ret__bool, value0_, value1_));
        }

        bool load_status(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__loadstatus__object__string__ret__bool, value0_, value1_));
        }

        void lock(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__lock__object__bool__ret__nothing, value0_, value1_);
        }

        void lock(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__lock__object__scalar__ret__nothing, value0_, value1_);
        }

        void lock_cargo(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__lockcargo__object__bool__ret__nothing, value0_, value1_);
        }

        void lock_driver(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__lockdriver__object__bool__ret__nothing, value0_, value1_);
        }

        bool locked_cargo(const object &value0_, float value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__lockedcargo__object__scalar__ret__bool, value0_, value1_));
        }


        bool mine_detected_by(const object &value0_, const side &value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__minedetectedby__object__side__ret__bool, value0_, value1_));
        }


        void play_action(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__playaction__object__string__ret__nothing, value0_, value1_);
        }

        void play_action_now(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__playactionnow__object__string__ret__nothing, value0_, value1_);
        }

        void play_gesture(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__playgesture__object__string__ret__nothing, value0_, value1_);
        }

        void play_move(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__playmove__object__string__ret__nothing, value0_, value1_);
        }

        void play_move_now(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__playmovenow__object__string__ret__nothing, value0_, value1_);
        }




        void public_variable_client(float value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__publicvariableclient__scalar__string__ret__nothing, value0_, value1_);
        }

        bool register_task(const team_member &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__registertask__team_member__string__ret__bool, value0_, value1_));
        }

        void remove_action(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__removeaction__object__scalar__ret__nothing, value0_, value1_);
        }

        void remove_all_event_handlers(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__removealleventhandlers__object__string__ret__nothing, value0_, value1_);
        }

        void remove_all_mpevent_handlers(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__removeallmpeventhandlers__object__string__ret__nothing, value0_, value1_);
        }

        

        void reveal_mine(const object &value0_, const side &value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__revealmine__side__object__ret__nothing, value0_, value1_);
        }

        bool save_identity(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__saveidentity__object__string__ret__bool, value0_, value1_));
        }

        bool save_status(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__savestatus__object__string__ret__bool, value0_, value1_));
        }

        void select_diary_subject(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__selectdiarysubject__object__string__ret__nothing, value0_, value1_);
        }

        void send_simple_command(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__sendsimplecommand__object__string__ret__nothing, value0_, value1_);
        }

        void set_actual_collective_rtd(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setactualcollectivertd__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_airport_side(float value0_, const side &value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setairportside__object_scalar__side__ret__nothing, value0_, value1_);
        }

        void set_airport_side(const object & target_, const side &value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setairportside__object_scalar__side__ret__nothing, target_, value1_);
        }
        void set_ammo_cargo(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setammocargo__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_anim_speed_coef(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setanimspeedcoef__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_autonomous(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setautonomous__object__bool__ret__nothing, value0_, value1_);
        }

        void set_bleeding_remaining(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setbleedingremaining__object__scalar__ret__nothing, value0_, value1_);
        }





        void set_collision_light(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setcollisionlight__object__bool__ret__nothing, value0_, value1_);
        }

        void set_combat_mode(const team_member &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setcombatmode__team_member__string__ret__nothing, value0_, value1_);
        }

        void set_custom_aim_coef(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setcustomaimcoef__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_custom_weight_rtd(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setcustomweightrtd__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_damage(const object &value0_, float value1_, bool use_effects_) {
            if (use_effects_)
                host::functions.invoke_raw_binary(client::__sqf::binary__setdamage__object__scalar_array__ret__nothing, value0_, value1_);
            else
                host::functions.invoke_raw_binary(client::__sqf::binary__setdamage__object__scalar_array__ret__nothing, value0_, {value1_,use_effects_});
        }

        void set_dammage(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setdammage__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_dir(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setdir__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_drop_interval(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setdropinterval__object__scalar__ret__nothing, value0_, value1_);
        }


        void set_face(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setface__object__string__ret__nothing, value0_, value1_);
        }

        void set_faceanimation(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setfaceanimation__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_fatigue(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setfatigue__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_flag_side(const object &value0_, const side &value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setflagside__object__side__ret__nothing, value0_, value1_);
        }

        void set_flag_texture(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setflagtexture__object__string__ret__nothing, value0_, value1_);
        }

        void set_formation(const team_member &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setformation__team_member__string__ret__nothing, value0_, value1_);
        }

        void set_formation_task(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setformationtask__object__string__ret__nothing, value0_, value1_);
        }

        void set_from_editor(const team_member &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setfromeditor__team_member__bool__ret__nothing, value0_, value1_);
        }

        void set_fuel(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setfuel__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_fuel_cargo(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setfuelcargo__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_identity(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setidentity__object__string__ret__nothing, value0_, value1_);
        }

        void set_light_brightness(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setlightbrightness__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_light_day_light(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setlightdaylight__object__bool__ret__nothing, value0_, value1_);
        }

        void set_light_flare_max_distance(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setlightflaremaxdistance__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_light_flare_size(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setlightflaresize__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_light_intensity(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setlightintensity__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_light_use_flare(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setlightuseflare__object__bool__ret__nothing, value0_, value1_);
        }

        void set_mimic(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setmimic__object__string__ret__nothing, value0_, value1_);
        }

        void set_name(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setname__object__string__ret__nothing, value0_, value1_);
        }

        void set_name_sound(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setnamesound__object__string__ret__nothing, value0_, value1_);
        }

        bool set_owner(const object &value0_, float value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__setowner__object__scalar__ret__bool, value0_, value1_));
        }

        void set_oxygen_remaining(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setoxygenremaining__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_particle_class(const object &particle_source_, const std::string& particle_class_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setparticleclass__object__string__ret__nothing, particle_source_, particle_class_);
        }

        void set_pilot_light(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setpilotlight__object__bool__ret__nothing, value0_, value1_);
        }

        void set_pitch(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setpitch__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_radio_msg(float value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setradiomsg__scalar__string__ret__nothing, value0_, value1_);
        }

        void set_random_lip(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setrandomlip__object__bool__ret__nothing, value0_, value1_);
        }

        void set_rank(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setrank__object__string__ret__nothing, value0_, value1_);
        }

        void set_repair_cargo(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setrepaircargo__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_rotor_brake_rtd(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setrotorbrakertd__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_skill(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setskill__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_speaker(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setspeaker__object__string__ret__nothing, value0_, value1_);
        }

        void set_stamina(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setstamina__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_suppression(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setsuppression__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_target_age(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__settargetage__object__string__ret__nothing, value0_, value1_);
        }



        void set_unconscious(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setunconscious__object__bool__ret__nothing, value0_, value1_);
        }

        void set_unit_ability(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setunitability__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_unit_pos(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setunitpos__object__string__ret__nothing, value0_, value1_);
        }

        void set_unit_pos_weak(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setunitposweak__object__string__ret__nothing, value0_, value1_);
        }

        void set_unit_rank(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setunitrank__object__string__ret__nothing, value0_, value1_);
        }

        void set_unit_recoil_coefficient(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setunitrecoilcoefficient__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_vehicle_ammo(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setvehicleammo__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_vehicle_ammo_def(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setvehicleammodef__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_vehicle_armor(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setvehiclearmor__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_vehicle_id(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setvehicleid__object__scalar__ret__nothing, value0_, value1_);
        }

        void set_vehicle_lock(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setvehiclelock__object__string__ret__nothing, value0_, value1_);
        }

        void set_vehicle_var_name(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__setvehiclevarname__object__string__ret__nothing, value0_, value1_);
        }


        float skill(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__skill__object__string__ret__scalar, value0_, value1_));
        }

        float skill_final(const object &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__skillfinal__object__string__ret__scalar, value0_, value1_));
        }



        void stop(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__stop__object__bool__ret__nothing, value0_, value1_);
        }

        void suppress_for(const object &value0_, float value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__suppressfor__object__scalar__ret__nothing, value0_, value1_);
        }

        void switch_action(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__switchaction__object__string__ret__nothing, value0_, value1_);
        }



        void switch_gesture(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__switchgesture__object__string__ret__nothing, value0_, value1_);
        }

        void switch_light(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__switchlight__object__string__ret__nothing, value0_, value1_);
        }

        void switch_move(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__switchmove__object__string__ret__nothing, value0_, value1_);
        }



        

        bool unregister_task(const team_member &value0_, const std::string& value1_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__unregistertask__team_member__string__ret__bool, value0_, value1_));
        }

        void use_audio_time_for_moves(const object &value0_, bool value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__useaudiotimeformoves__object__bool__ret__nothing, value0_, value1_);
        }

        void vehicle_radio(const object &value0_, const std::string& value1_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__vehicleradio__object__string__ret__nothing, value0_, value1_);
        }

        side create_center(const side & side_) {
            return side(host::functions.invoke_raw_unary(client::__sqf::unary__createcenter__side__ret__side, side_));
        }

        void delete_center(const side & side_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__deletecenter__side__ret__nothing, side_);
        }

        void delete_team(const team_member &value_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__deleteteam__team_member__ret__nothing, value_);
        }

        display find_display(float value_) {
            return display(host::functions.invoke_raw_unary(client::__sqf::unary__finddisplay__scalar__ret__display, value_));
        }

        side flag_side(const object &value_) {
            return side(host::functions.invoke_raw_unary(client::__sqf::unary__flagside__object__ret__side, value_));
        }

        std::string formation(const team_member &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__formation__team_member__ret__string, value_));
        }

        bool from_editor(const team_member &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__fromeditor__team_member__ret__bool, value_));
        }


        object hc_leader(const group &value_) {
            return object(host::functions.invoke_raw_unary(client::__sqf::unary__hcleader__group__ret__object, value_));
        }

        std::string image(const std::string& value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__image__string__ret__text, value_));
        }

        bool is_agent(const team_member &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isagent__team_member__ret__bool, value_));
        }

        std::string key_image(float value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__keyimage__scalar__ret__text, value_));
        }

        std::string key_name(float value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__keyname__scalar__ret__string, value_));
        }

        team_member leader(const team_member &value_) {
            return team_member(host::functions.invoke_raw_unary(client::__sqf::unary__leader__team_member__ret__team_member, value_));
        }

        std::string net_id(const group &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__netid__group__ret__string, value_));
        }

        object object_from_net_id(const std::string& value_) {
            return object(host::functions.invoke_raw_unary(client::__sqf::unary__objectfromnetid__string__ret__object, value_));
        }


        float parse_number(bool value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__parsenumber__bool__ret__scalar, value_));
        }

        std::string parse_text(const std::string& value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__parsetext__string__ret__text, value_));
        }

        float playable_slots_number(const side &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__playableslotsnumber__side__ret__scalar, value_));
        }

        float players_number(const side &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__playersnumber__side__ret__scalar, value_));
        }

        float score_side(const side &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__scoreside__side__ret__scalar, value_));
        }

        bool show_subtitles(bool value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__showsubtitles__bool__ret__bool, value_));
        }

        std::string team_name(const team_member &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__teamname__team_member__ret__string, value_));
        }

        std::string team_type(const team_member &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__teamtype__team_member__ret__string, value_));
        }

        float waypoint_timeout_current(const group &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__waypointtimeoutcurrent__group__ret__scalar, value_));
        }

        float radio_volume() {
            return game_value(host::functions.invoke_raw_nular(client::__sqf::nular__radiovolume__ret__scalar));
        }

        void save_game() {
            host::functions.invoke_raw_nular(client::__sqf::nular__savegame__ret__nothing);
        }

        void save_joysticks() {
            host::functions.invoke_raw_nular(client::__sqf::nular__savejoysticks__ret__nothing);
        }

        side side_enemy() {
            return side(host::functions.invoke_raw_nular(client::__sqf::nular__sideenemy__ret__side));
        }

        side side_friendly() {
            return side(host::functions.invoke_raw_nular(client::__sqf::nular__sidefriendly__ret__side));
        }

        side side_logic() {
            return side(host::functions.invoke_raw_nular(client::__sqf::nular__sidelogic__ret__side));
        }

        side side_unknown() {
            return side(host::functions.invoke_raw_nular(client::__sqf::nular__sideunknown__ret__side));
        }

        team_member team_member_null() {
            game_value ret_value = host::functions.invoke_raw_nular(client::__sqf::nular__teammembernull__ret__team_member);
            return team_member(host::functions.invoke_raw_nular(client::__sqf::nular__teammembernull__ret__team_member));
        }

        side west() {
            return side(host::functions.invoke_raw_nular(client::__sqf::nular__west__ret__side));
        }

        bool buldozer_is_enabled_road_diag() {
            return game_value(host::functions.invoke_raw_nular(client::__sqf::nular__buldozer_isenabledroaddiag__ret__bool));
        }

        void buldozer_reload_oper_map() {
            host::functions.invoke_raw_nular(client::__sqf::nular__buldozer_reloadopermap__ret__nothing);
        }

        void cancel_simple_task_destination(task value_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__cancelsimpletaskdestination__task__ret__nothing, value_);
        }

        task current_task(const object &value_) {
            return task(host::functions.invoke_raw_unary(client::__sqf::unary__currenttask__object__ret__task, value_));
        }

        script exec_vm(const std::string& value_) {
            return script(host::functions.invoke_raw_unary(client::__sqf::unary__execvm__string__ret__script, value_));
        }

        float priority(task value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__priority__task__ret__scalar, value_));
        }

        bool script_done(script value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__scriptdone__script__ret__bool, value_));
        }

        bool task_completed(task value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__taskcompleted__task__ret__bool, value_));
        }

        task task_parent(task value_) {
            return task(host::functions.invoke_raw_unary(client::__sqf::unary__taskparent__task__ret__task, value_));
        }

        std::string task_state(task value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__taskstate__task__ret__string, value_));
        }

        void terminate(script value_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__terminate__script__ret__nothing, value_);
        }

        std::string type(task value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__type__task__ret__string, value_));
        }

        /* Multiplayer */
                bool local(const object &value_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__local__object__ret__bool, value_);
        }

        bool local(const group &value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__local__group__ret__bool, value_));
        }

        bool is_server() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__isserver__ret__bool);
        }

        bool is_multiplayer() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__ismultiplayer__ret__bool);
        }

        bool is_dedicated() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__isdedicated__ret__bool);
        }

        bool did_jip() {
            return __helpers::__retrieve_nular_bool(client::__sqf::nular__didjip__ret__bool);
        }

        std::vector<object> near_objects(const vector3 &pos_, const float &radius_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_binary(__sqf::binary__nearobjects__object_array__scalar_array__ret__array, pos_, radius_));
        }

        std::vector<object> near_objects(const object &object_, const float &radius_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_binary(__sqf::binary__nearobjects__object_array__scalar_array__ret__array, object_, radius_));
        }

        std::vector<object> near_objects(const vector3 &pos_, const std::string &type_, const float &radius_) {
            game_value args(std::vector<game_value>{
                type_,
                radius_
            });

            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_binary(__sqf::binary__nearobjects__object_array__scalar_array__ret__array, pos_, args));
        }

        std::vector<object> near_objects(const object &object_, const std::string &type_, const float &radius_) {
            game_value args(std::vector<game_value>{
                type_,
                radius_
            });

            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_binary(__sqf::binary__nearobjects__object_array__scalar_array__ret__array, object_, args));
        }

        void hint(const std::string &text_) {
            __helpers::__empty_unary_string(client::__sqf::unary__hint__text_string__ret__nothing, text_);
        }

        void hint_cadet(const std::string &text_) {
            __helpers::__empty_unary_string(client::__sqf::unary__hintcadet__text_string__ret__nothing, text_);
        }

        void hint_silent(const std::string &text_) {
            __helpers::__empty_unary_string(client::__sqf::unary__hintsilent__text_string__ret__nothing, text_);
        }



        std::vector<object> roads_connected_to(const object &obj_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(__sqf::unary__roadsconnectedto__object__ret__array, obj_));
        }

        std::vector<object> rope_attached_objects(const object &obj_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(__sqf::unary__ropeattachedobjects__object__ret__array, obj_));
        }

        std::vector<object> ropes(const object &obj_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(__sqf::unary__ropes__object__ret__array, obj_));
        }

        vector3 screen_to_world(const vector2 &pos_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__screentoworld__array__ret__array, pos_));
        }



        std::string speed_mode(const object &obj_) {
            return __helpers::__string_unary_object(client::__sqf::unary__speedmode__object_group__ret__string, obj_);
        }

        std::string speed_mode(const group &grp_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__speedmode__object_group__ret__string, grp_));
        }

        game_value get_mission_config_value(const std::string& attribute_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__getmissionconfigvalue__string_array__ret__array_string, attribute_));
        }

        game_value get_mission_config_value(const std::string& attribute_, game_value default_value_) {
            return game_value(
                host::functions.invoke_raw_unary(client::__sqf::unary__getmissionconfigvalue__string_array__ret__array_string, {attribute_,default_value_})
            );
        }

        void move(const object& unit_, const vector3& pos_) {
            host::functions.invoke_raw_binary(__sqf::binary__move__object_group__array__ret__nothing, unit_, pos_);
        }

        void move(const group& group_, const vector3& pos_) {
            host::functions.invoke_raw_binary(__sqf::binary__move__object_group__array__ret__nothing, group_, pos_);
        }

        bool move_in_any(const object& unit_, const object& vehicle_) {
            return game_value(host::functions.invoke_raw_binary(__sqf::binary__moveinany__object__object__ret__bool, unit_, vehicle_));
        }

        void move_in_cargo(const object& unit_, const object& vehicle_, int cargo_index_) {
            if (cargo_index_ == -1)
            {
                host::functions.invoke_raw_binary(__sqf::binary__moveincargo__object__object__ret__nothing, unit_, vehicle_);
            }
            else
            {
                game_value params(std::vector<game_value> {
                    vehicle_,
                    (float)cargo_index_
                });

                host::functions.invoke_raw_binary(__sqf::binary__moveincargo__object__array__ret__nothing, unit_, params);
            }
        }

        void move_in_commander(const object& unit_, const object& vehicle_) {
            host::functions.invoke_raw_binary(__sqf::binary__moveincommander__object__object__ret__nothing, unit_, vehicle_);
        }

        void move_in_driver(const object& unit_, const object& vehicle_) {
            host::functions.invoke_raw_binary(__sqf::binary__moveindriver__object__object__ret__nothing, unit_, vehicle_);
        }

        void move_in_gunner(const object &unit_, const object &vehicle_) {
            host::functions.invoke_raw_binary(__sqf::binary__moveingunner__object__object__ret__nothing, unit_, vehicle_);
        }

        void move_in_turret(const object& unit_, const object& vehicle_, const std::vector<int> turret_path_) {
            std::vector<game_value> path;
            for (int item : turret_path_)
                path.push_back(game_value((float)item));

            game_value params(std::vector<game_value> {
                vehicle_,
                path
            });

            host::functions.invoke_raw_binary(__sqf::binary__moveinturret__object__array__ret__nothing, unit_, params);
        }

        void move_to(const object& unit_, const vector3& pos_) {
            host::functions.invoke_raw_binary(__sqf::binary__moveto__object__array__ret__nothing, unit_, pos_);
        }





        rv_resolution get_resolution() {
            return rv_resolution::from_vector(__helpers::__convert_to_numbers_vector(host::functions.invoke_raw_nular(__sqf::nular__getresolution__ret__array)));
        }



        std::vector<object> vehicles() {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_nular(__sqf::nular__vehicles__ret__array));
        }



        rv_artillery_computer_settings get_artillery_computer_settings() {
            return rv_artillery_computer_settings(host::functions.invoke_raw_nular(client::__sqf::nular__getartillerycomputersettings__ret__array));
        }

        rv_product_version product_version() {
            return rv_product_version(host::functions.invoke_raw_nular(client::__sqf::nular__productversion__ret__array));
        }

        side get_side(const object &object_) {
            return side(host::functions.invoke_raw_unary(client::__sqf::unary__side__object__ret__side, object_));
        }







        std::string wf_side_text(const object &object_) {
            return __helpers::__string_unary_object(client::__sqf::unary__wfsidetext__object__ret__string, object_);
        }

        std::string wf_side_text(const group &group_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__wfsidetext__group__ret__string, group_));
        }

        std::string wf_side_text(const side &side_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__wfsidetext__side__ret__string, side_));
        }

        float count_side(const side &side_, std::vector<object> &objects_) {
            std::vector<game_value> objects;
            for (auto type : objects_)
                objects.push_back(type);

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__countside__side__array__ret__scalar, side_, objects));
        }

        float get_friend(const side &side1_, const side &side2_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getfriend__side__side__ret__scalar, side1_, side2_));
        }

        void set_friend(const side &side1_, const side &side2_, float value_) {
            game_value args(std::vector<game_value>{
                side2_,
                value_
            });

            host::functions.invoke_raw_binary(client::__sqf::binary__setfriend__side__array__ret__nothing, side1_, args);
        }

        std::vector<object> entities(const std::string& type_)
        {
            return __helpers::__convert_to_objects_vector(game_value(host::functions.invoke_raw_unary(client::__sqf::unary__entities__string__ret__array, type_)));
        }








        

        std::vector<object> nearest_terrain_objects(const vector3& pos_, const std::vector<std::string> types_, float radius_)
        {
            std::vector<game_value> loctypes;
            for (std::string l_ : types_)
                loctypes.push_back(l_);

            game_value args({
                pos_,
                loctypes,
                radius_
            });

            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__nearestlocation__array__ret__location, args));
        }

        std::vector<object> nearest_terrain_objects(const object& unit_, const std::vector<std::string> types_, float radius_)
        {
            std::vector<game_value> loctypes;
            for (std::string l_ : types_)
                loctypes.push_back(l_);

            game_value args({
                unit_,
                loctypes,
                radius_
            });

            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__nearestlocation__array__ret__location, args));
        }










        std::vector<object> units(const object& unit_)
        {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__units__object__ret__array, unit_));
        }

        std::string call_extension(const std::string& extension_, const std::string& arguments_)
        {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__callextension__string__string__ret__string, extension_, arguments_));
        }

        

       

        void hintc(const std::string& title_, std::vector<std::string> content_)
        {
            std::vector<game_value> ga_content;
            for (std::string _str : content_)
                ga_content.push_back(_str);

            host::functions.invoke_raw_binary(client::__sqf::binary__hintc__string__array__ret__nothing, title_, ga_content);
        }





        float aimed_at_target(const object& vehicle_, const object& target_) {
            game_value params({
                target_
            });

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__aimedattarget__object__array__ret__scalar, vehicle_, params));
        }

        float aimed_at_target(const object& vehicle_, const object& target_, const std::string& weapon_) {
            game_value params({
                target_,
                weapon_
            });

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__aimedattarget__object__array__ret__scalar, vehicle_, params));
        }

        void allow_fleeing(const object& object_, float cowardice_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__allowfleeing__object_group__scalar__ret__nothing, object_, cowardice_);
        }

        void allow_fleeing(const group& group_, float cowardice_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__allowfleeing__object_group__scalar__ret__nothing, group_, cowardice_);
        }

        void allow_get_in(const std::vector<object>& units_, bool allow_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value((object)item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__allowgetin__array__bool__ret__nothing, units, allow_);
        }

        void animate(const object& obj_, const std::string& animation_name_, float phase_) {
            std::vector<game_value> params {
                animation_name_,
                phase_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__animate__object__array__ret__nothing, obj_, params);
        }

        void animate(const object& obj_, const std::string& animation_name_, float phase_, bool instant_) {
            std::vector<game_value> params {
                animation_name_,
                phase_,
                instant_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__animate__object__array__ret__nothing, obj_, params);
        }

        void animate_door(const object& obj_, const std::string& door_name_, float phase_, bool now_) {
            std::vector<game_value> params {
                door_name_,
                phase_,
                now_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__animatedoor__object__array__ret__nothing, obj_, params);
        }

        void assign_as_cargo(const object& unit_, const object& vehicle_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__assignascargo__object__object__ret__nothing, unit_, vehicle_);
        }

        void assign_as_commander(const object& unit_, const object& vehicle_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__assignascommander__object__object__ret__nothing, unit_, vehicle_);
        }

        void assign_as_driver(const object& unit_, const object& vehicle_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__assignasdriver__object__object__ret__nothing, unit_, vehicle_);
        }

        void assign_as_gunner(const object& unit_, const object& vehicle_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__assignasgunner__object__object__ret__nothing, unit_, vehicle_);
        }

        void assign_as_turret(const object& unit_, const object& vehicle_, const std::vector<float>& turret_path_) {
            std::vector<game_value> turret_path;
            for (float item : turret_path_) {
                turret_path.push_back(game_value(item));
            }

            std::vector<game_value> params {
                vehicle_,
                turret_path
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__assignasgunner__object__object__ret__nothing, unit_, params);
        }

        void assign_as_cargo_index(const object& unit_, const object& vehicle_, int index_) {
            std::vector<game_value> params {
                vehicle_,
                (float)index_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__assignascargoindex__object__array__ret__nothing, unit_, params);
        }

        void assign_curator(const object& player_, const object& curator_module_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__assigncurator__object__object__ret__nothing, player_, curator_module_);
        }



        bool can_sling_load(const object& vehicle_, const object& cargo_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__canslingload__object__object__ret__bool, vehicle_, cargo_));
        }

        void command_artillery_fire(const object& unit_, const vector3& pos_, const std::string& type_, int rounds_) {
            std::vector<game_value> params{
                pos_,
                type_,
                (float)rounds_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__commandartilleryfire__object_array__array__ret__nothing, unit_, params);
        }

        void command_artillery_fire(const object& unit_, const vector2& pos_, const std::string& type_, int rounds_) {
            std::vector<game_value> params{
                pos_,
                type_,
                (float)rounds_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__commandartilleryfire__object_array__array__ret__nothing, unit_, params);
        }

        void command_artillery_fire(const std::vector<object>& units_, const vector3& pos_, const std::string& type_, int rounds_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            std::vector<game_value> params{
                pos_,
                type_,
                (float)rounds_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__commandartilleryfire__object_array__array__ret__nothing, units, params);
        }

        void command_artillery_fire(const std::vector<object>& units_, const vector2& pos_, const std::string& type_, int rounds_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            std::vector<game_value> params{
                pos_,
                type_,
                (float)rounds_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__commandartilleryfire__object_array__array__ret__nothing, units, params);
        }

        void command_fire(const object& unit_, const object& target_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__commandfire__object_array__object__ret__nothing, unit_, target_);
        }

        void command_fire(const std::vector<object>& units_, const object& target_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__commandfire__object_array__object__ret__nothing, units, target_);
        }

        void command_follow(const object& unit_, const object& target_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__commandfollow__object_array__object__ret__nothing, unit_, target_);
        }

        void command_follow(const std::vector<object>& units_, const object& target_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__commandfollow__object_array__object__ret__nothing, units, target_);
        }

        void command_fsm(const object& unit_, const std::string& fsm_, const vector3& pos_, const object& target_) {
            std::vector<game_value> params{
                fsm_,
                pos_,
                target_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__commandfsm__object_array__array__ret__nothing, unit_, params);
        }

        void command_fsm(const object& unit_, const std::string& fsm_, const vector2& pos_, const object& target_) {
            std::vector<game_value> params{
                fsm_,
                pos_,
                target_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__commandfsm__object_array__array__ret__nothing, unit_, params);
        }

        void command_fsm(const std::vector<object>& units_, const std::string& fsm_, const vector3& pos_, const object& target_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            std::vector<game_value> params{
                fsm_,
                pos_,
                target_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__commandfsm__object_array__array__ret__nothing, units, params);
        }

        void command_fsm(const std::vector<object>& units_, const std::string& fsm_, const vector2& pos_, const object& target_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            std::vector<game_value> params{
                fsm_,
                pos_,
                target_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__commandfsm__object_array__array__ret__nothing, units, params);
        }

        void command_move(const object& unit_, const vector3& pos_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__commandmove__object_array__array__ret__nothing, unit_, pos_);
        }

        void command_move(const object& unit_, const vector2& pos_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__commandmove__object_array__array__ret__nothing, unit_, pos_);
        }

        void command_move(const std::vector<object>& units_, const vector3& pos_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__commandmove__object_array__array__ret__nothing, units, pos_);
        }

        void command_move(const std::vector<object>& units_, const vector2& pos_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__commandmove__object_array__array__ret__nothing, units, pos_);
        }

        void command_radio(const object& unit_, const std::string& radio_name_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__commandradio__object_array__string__ret__nothing, unit_, radio_name_);
        }

        void command_radio(const std::vector<object>& units_, const std::string& radio_name_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__commandradio__object_array__string__ret__nothing, units, radio_name_);
        }

        void command_target(const object& unit_, const object& target_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__commandtarget__object_array__object__ret__nothing, unit_, target_);
        }

        void command_target(const std::vector<object>& units_, const object& target_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__commandtarget__object_array__object__ret__nothing, units, target_);
        }

        void command_watch(const object& unit_, const vector3& pos_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__commandwatch__object_array__array__ret__nothing, unit_, pos_);
        }

        void command_watch(const object& unit_, const vector2& pos_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__commandwatch__object_array__array__ret__nothing, unit_, pos_);
        }

        void command_watch(const std::vector<object>& units_, const vector3& pos_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__commandwatch__object_array__array__ret__nothing, units, pos_);
        }

        void command_watch(const std::vector<object>& units_, const vector2& pos_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__commandwatch__object_array__array__ret__nothing, units, pos_);
        }

        void command_watch(const object& unit_, const object& target_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__commandwatch__object_array__object__ret__nothing, unit_, target_);
        }

        void command_watch(const std::vector<object>& units_, const object& target_) {
            std::vector<game_value> units;
            for (object item : units_) {
                units.push_back(game_value(item));
            }

            host::functions.invoke_raw_binary(client::__sqf::binary__commandwatch__object_array__object__ret__nothing, units, target_);
        }

        float distance(const object& start_, const object& end_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__distance__object_array__object_array__ret__scalar, start_, end_));
        }

        float distance(const vector3& start_, const object& end_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__distance__object_array__object_array__ret__scalar, start_, end_));
        }

        float distance(const object& start_, const vector3& end_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__distance__object_array__object_array__ret__scalar, start_, end_));
        }

        float distance(const vector3& start_, const vector3& end_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__distance__object_array__object_array__ret__scalar, start_, end_));
        }




        

        void remote_control(const object &controller_, const object &controlled_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__remotecontrol__object__object__ret__nothing, controller_, controlled_);
        }

        void set_hit(const object &object_, const std::string &part_, float damage_) {
            std::vector<game_value> params{
                part_,
                damage_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__sethit__object__array__ret__nothing, object_, params);
        }

        void set_hit_index(const object &object_, int part_index_, float damage_) {
            std::vector<game_value> params{
                (float)part_index_,
                damage_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__sethitindex__object__array__ret__nothing, object_, params);
        }

        void set_hit_point_damage(const object &object_, const std::string &hit_point_, float damage_) {
            std::vector<game_value> params{
                hit_point_,
                damage_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__sethitpointdamage__object__array__ret__nothing, object_, params);
        }



        

        bool in(const object &unit_, const object &vehicle_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__in__object__object__ret__bool, unit_, vehicle_));
        }



        float add_mission_event_handler(const std::string &type_, const code &command_) {
            std::vector<game_value> params{
                type_,
                command_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__addmissioneventhandler__array__ret__nothing_scalar, params));
        }

        float add_mission_event_handler(const std::string &type_, const std::string &command_) {
            std::vector<game_value> params{
                type_,
                command_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__addmissioneventhandler__array__ret__nothing_scalar, params));
        }

        float add_music_event_handler(const std::string &type_, const code &command_) {
            std::vector<game_value> params{
                type_,
                command_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__addmusiceventhandler__array__ret__scalar, params));
        }

        float add_music_event_handler(const std::string &type_, const std::string &command_) {
            std::vector<game_value> params{
                type_,
                command_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__addmusiceventhandler__array__ret__scalar, params));
        }

        void add_weapon_pool(const std::string &weapon_name_, int count_) {
            std::vector<game_value> params{
                weapon_name_,
                (float)count_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__addweaponpool__array__ret__nothing, params);
        }

        rv_vehicle_role assigned_vehicle_role(const object &unit_) {
            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__assignedvehiclerole__object__ret__array, unit_);

            if (ret.length() == 0) {
                return rv_vehicle_role({});
            }
            else if (ret.length() == 1) {
                return rv_vehicle_role({ ret[0] });
            }
            else {
                std::vector<int> turret_path = __helpers::__convert_to_integers_vector(ret[1]);
                return rv_vehicle_role({ ret[0], turret_path });
            }
        }

        std::string compose_text(const std::vector<std::string> &texts_) {
            std::vector<game_value> texts;
            for (auto text : texts_)
                texts.push_back(game_value(text));

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__composetext__array__ret__text, texts));
        }

        std::string create_diary_link(const std::string &subject_, const object &object_, const std::string &text_) {
            std::vector<game_value> params{
                subject_,
                object_,
                text_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__creatediarylink__array__ret__string, params));
        }

        std::string create_diary_record(const object &object_, const std::string &subject_, const std::string &text_) {
            std::vector<game_value> params{
                subject_,
                text_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__creatediaryrecord__object__array__ret__diary_record, object_, params));
        }

        std::string create_diary_record(const object &object_, const std::string &subject_, const std::string &text_, const task &task_) {
            std::vector<game_value> params{
                subject_,
                text_,
                task_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__creatediaryrecord__object__array__ret__diary_record, object_, params));
        }

        std::string create_diary_record(const object &object_, const std::string &subject_, const std::string &text_, const task &task_, const std::string &state_) {
            std::vector<game_value> params{
                subject_,
                text_,
                task_,
                state_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__creatediaryrecord__object__array__ret__diary_record, object_, params));
        }

        std::string create_diary_record(const object &object_, const std::string &subject_, const std::string &title_, const std::string &text_) {
            std::vector<game_value> params{
                subject_,
                game_value({
                    title_,
                    text_
                })
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__creatediaryrecord__object__array__ret__diary_record, object_, params));
        }

        std::string create_diary_record(const object &object_, const std::string &subject_, const std::string &title_, const std::string &text_, const task &task_) {
            std::vector<game_value> params{
                subject_,
                game_value({
                    title_,
                    text_,
                }),
                task_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__creatediaryrecord__object__array__ret__diary_record, object_, params));
        }

        std::string create_diary_record(const object &object_, const std::string &subject_, const std::string &title_, const std::string &text_, const task &task_, const std::string &state_) {
            std::vector<game_value> params{
                subject_,
                game_value({
                    title_,
                    text_
                }),
                task_,
                state_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__creatediaryrecord__object__array__ret__diary_record, object_, params));
        }

        float create_diary_subject(const object &object_, const std::string &subject_, const std::string &name_) {
            std::vector<game_value> params{
                subject_,
                name_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__creatediarysubject__object__array__ret__scalar, object_, params));
        }

        float create_diary_subject(const object &object_, const std::string &subject_, const std::string &name_, const std::string &picture_) {
            std::vector<game_value> params{
                subject_,
                name_,
                picture_
            };

            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__creatediarysubject__object__array__ret__scalar, object_, params));
        }

        

        float linear_conversion(float min_, float max_, float value_, float new_min_, float new_max_) {
            std::vector<game_value> params{
                min_,
                max_,
                value_,
                new_min_,
                new_max_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__linearconversion__array__ret__scalar, params));
        }

        float linear_conversion(float min_, float max_, float value_, float new_min_, float new_max_, bool clamp_) {
            std::vector<game_value> params{
                min_,
                max_,
                value_,
                new_min_,
                new_max_,
                clamp_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__linearconversion__array__ret__scalar, params));
        }

        bool is_on_road(const object &object_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isonroad__object_array__ret__bool, object_));
        }

        bool is_on_road(const vector3 &position_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isonroad__object_array__ret__bool, position_));
        }

        void host_mission(const config &config_, const display &display_) {
            std::vector<game_value> params{
                config_,
                display_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__hostmission__array__ret__nothing, params);
        }

        std::vector<group> hc_selected(const object &unit_) {
            return __helpers::__convert_to_groups_vector(host::functions.invoke_raw_unary(client::__sqf::unary__hcselected__object__ret__array, unit_));
        }

        std::vector<group> hc_all_groups(const object &unit_) {
            return __helpers::__convert_to_groups_vector(host::functions.invoke_raw_unary(client::__sqf::unary__hcallgroups__object__ret__array, unit_));
        }

        group get_group(const object &unit_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__group__object__ret__group, unit_));
        }

        vector3 get_wp_pos(const group &group_, int index_) {
            std::vector<game_value> params{
                group_,
                (float)index_
            };

            return __helpers::__convert_to_vector3(host::functions.invoke_raw_unary(client::__sqf::unary__getwppos__array__ret__array, params));
        }

        void do_stop(const object &unit_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__dostop__object_array__ret__nothing, unit_);
        }

        void do_stop(const std::vector<object> &units_) {
            std::vector<game_value> units;
            for (auto unit : units_)
                units.push_back(game_value(unit));

            host::functions.invoke_raw_unary(client::__sqf::unary__dostop__object_array__ret__nothing, units);
        }

        void do_get_out(const object &unit_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__dogetout__object_array__ret__nothing, unit_);
        }

        void do_get_out(const std::vector<object> &units_) {
            std::vector<game_value> units;
            for (auto unit : units_)
                units.push_back(game_value(unit));

            host::functions.invoke_raw_unary(client::__sqf::unary__dogetout__object_array__ret__nothing, units);
        }



        std::vector<object> detected_mines(const side &side_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__detectedmines__side__ret__array, side_));
        }

        void diag_log(const std::string &text_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__diag_log__any__ret__nothing, text_);
        }

        std::vector<bool> engines_is_on_rtd(const object &heli_) {
            return __helpers::__convert_to_booleans_vector(host::functions.invoke_raw_unary(client::__sqf::unary__enginesisonrtd__object__ret__array, heli_));
        }

        std::vector<float> engines_rpm_rtd(const object &heli_) {
            return __helpers::__convert_to_numbers_vector(host::functions.invoke_raw_unary(client::__sqf::unary__enginesrpmrtd__object__ret__array, heli_));
        }

        std::vector<float> engines_torque_rtd(const object &heli_) {
            return __helpers::__convert_to_numbers_vector(host::functions.invoke_raw_unary(client::__sqf::unary__enginestorquertd__object__ret__array, heli_));
        }

        rv_hit_points_damage get_all_hit_points_damage(const object &veh_) {
            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__getallhitpointsdamage__object__ret__array, veh_);

            std::vector<std::string> hit_points = __helpers::__convert_to_strings_vector(ret[0]);
            std::vector<std::string> hit_selections = __helpers::__convert_to_strings_vector(ret[1]);
            std::vector<float> damages = __helpers::__convert_to_numbers_vector(ret[2]);

            return rv_hit_points_damage({ hit_points, hit_selections, damages });
        }

        std::vector<rv_forces_rtd> rotors_forces_rtd(const object &heli_) {
            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__rotorsforcesrtd__object__ret__array, heli_);

            std::vector<rv_forces_rtd> rotors_forces;
            for (uint32_t i = 0; i < ret.length(); ++i) {
                rotors_forces.push_back(rv_forces_rtd{ ret[i][0], ret[i][1], ret[i][2] });
            }

            return rotors_forces;
        }

        std::vector<rv_forces_rtd> wings_forces_rtd(const object &heli_) {
            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__wingsforcesrtd__object__ret__array, heli_);

            std::vector<rv_forces_rtd> wings_forces;
            for (uint32_t i = 0; i < ret.length(); ++i) {
                wings_forces.push_back(rv_forces_rtd{ ret[i][0], ret[i][1], ret[i][2] });
            }

            return wings_forces;
        }

        std::vector<float> rotors_rpm_rtd(const object &heli_) {
            return __helpers::__convert_to_numbers_vector(host::functions.invoke_raw_unary(client::__sqf::unary__rotorsrpmrtd__object__ret__array, heli_));
        }

        rv_weight_rtd weight_rtd(const object &heli_) {
            return rv_weight_rtd::from_vector(__helpers::__convert_to_numbers_vector(host::functions.invoke_raw_unary(client::__sqf::unary__weightrtd__object__ret__array, heli_)));
        }

        void set_brakes_rtd(const object &heli_, float amount_, int wheel_index_) {
            std::vector<game_value> params{
                amount_,
                (float)wheel_index_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__setbrakesrtd__object__array__ret__nothing, heli_, params);
        }

        void set_engine_rpm_rtd(const object &heli_, float rpms_, int engine_index_) {
            std::vector<game_value> params{
                rpms_,
                (float)engine_index_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__setenginerpmrtd__object__array__ret__nothing, heli_, params);
        }

        void set_wanted_rpm_rtd(const object &heli_, float rpms_, float time_, int engine_index_) {
            std::vector<game_value> params{
                rpms_,
                time_,
                (float)engine_index_
            };

            host::functions.invoke_raw_binary(client::__sqf::binary__setwantedrpmrtd__object__array__ret__nothing, heli_, params);
        }

        

        int get_cargo_index(const object &vehicle_, const object &unit_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__getcargoindex__object__object__ret__scalar, vehicle_, unit_));
        }



       

        std::vector<std::string> get_object_materials(const object &object_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__getobjectmaterials__object__ret__array, object_));
        }

        std::vector<std::string> get_object_textures(const object &object_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__getobjecttextures__object__ret__array, object_));
        }

        std::vector<object> group_selected_units(const object &unit_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__groupselectedunits__object__ret__array, unit_));
        }





        std::vector<object> members(const team_member &team_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__members__team_member__ret__array, team_));
        }

        

        object nearest_object(const vector3 &pos_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__nearestobject__array__ret__object, pos_));
        }

        object nearest_object(const vector3 &pos_, const std::string &type_) {
            std::vector<game_value> params{
                pos_,
                type_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__nearestobject__array__ret__object, params));
            // Same as: position nearObjects filter (where position is vector3 and filter is string) - binary__nearestobject__array__string__ret__object
        }

        object nearest_object(const object &obj_, const std::string &type_) {
            std::vector<game_value> params{
                obj_,
                type_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__nearestobject__array__ret__object, params));
        }

        object nearest_object(const vector3 &pos_, float id_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::binary__nearestobject__array__scalar__ret__object, pos_, id_));
        }

        std::vector<object> nearest_objects(const vector3 &pos_, const std::vector<std::string> &types_, float radius_) {
            std::vector<game_value> types;
            for (auto type : types_)
                types.push_back(game_value(type));

            std::vector<game_value> params{
                pos_,
                types,
                radius_
            };

            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__nearestobjects__array__ret__array, params));
        }

        std::vector<object> nearest_objects(const object &obj_, const std::vector<std::string> &types_, float radius_) {
            std::vector<game_value> types;
            for (auto type : types_)
                types.push_back(game_value(type));

            std::vector<game_value> params{
                obj_,
                types,
                radius_
            };

            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__nearestobjects__array__ret__array, params));
        }

        std::vector<object> nearest_terrain_objects(const vector3 &pos_, const std::vector<std::string> &types_, float radius_) {
            std::vector<game_value> types;
            for (auto type : types_)
                types.push_back(game_value(type));

            std::vector<game_value> params{
                pos_,
                types,
                radius_
            };

            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__nearestterrainobjects__array__ret__array, params));
        }

        std::vector<object> nearest_terrain_objects(const object &obj_, const std::vector<std::string> &types_, float radius_) {
            std::vector<game_value> types;
            for (auto type : types_)
                types.push_back(game_value(type));

            std::vector<game_value> params{
                obj_,
                types,
                radius_
            };

            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__nearestterrainobjects__array__ret__array, params));
        }

        void on_command_mode_changed(const code &command_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__oncommandmodechanged__code_string__ret__nothing, command_);
        }

        void on_command_mode_changed(const std::string &command_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__oncommandmodechanged__code_string__ret__nothing, command_);
        }

        void play_mission(const std::string &campaign_, const std::string &mission_) {
            std::vector<game_value> params{
                campaign_,
                mission_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playmission__array__ret__nothing, params);
        }

        void play_mission(const std::string &campaign_, const std::string &mission_, bool skip_briefing_) {
            std::vector<game_value> params{
                campaign_,
                mission_,
                skip_briefing_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playmission__array__ret__nothing, params);
        }

        void play_mission(const std::string &campaign_, const config &mission_) {
            std::vector<game_value> params{
                campaign_,
                mission_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playmission__array__ret__nothing, params);
        }

        void play_mission(const std::string &campaign_, const config &mission_, bool skip_briefing_) {
            std::vector<game_value> params{
                campaign_,
                mission_,
                skip_briefing_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playmission__array__ret__nothing, params);
        }

        void play_scripted_mission(const std::string &world_, const code &command_) {
            std::vector<game_value> params{
                world_,
                command_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playscriptedmission__array__ret__nothing, params);
        }

        void play_scripted_mission(const std::string &world_, const code &command_, const config &config_) {
            std::vector<game_value> params{
                world_,
                command_,
                config_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playscriptedmission__array__ret__nothing, params);
        }

        void play_scripted_mission(const std::string &world_, const code &command_, const config &config_, bool ignore_child_window_) {
            std::vector<game_value> params{
                world_,
                command_,
                config_,
                ignore_child_window_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playscriptedmission__array__ret__nothing, params);
        }

        void play_sound_3d(const std::string &name_, const object &source_) {
            std::vector<game_value> params{
                name_,
                source_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playsound3d__array__ret__nothing, params);
        }

        void play_sound_3d(const std::string &name_, const object &source_, vector3 &pos_) {
            std::vector<game_value> params{
                name_,
                source_,
                pos_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playsound3d__array__ret__nothing, params);
        }

        void play_sound_3d(const std::string &name_, const object &source_, vector3 &pos_, float volume_) {
            std::vector<game_value> params{
                name_,
                source_,
                pos_,
                volume_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playsound3d__array__ret__nothing, params);
        }

        void play_sound_3d(const std::string &name_, const object &source_, vector3 &pos_, float volume_, float pitch_) {
            std::vector<game_value> params{
                name_,
                source_,
                pos_,
                volume_,
                pitch_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playsound3d__array__ret__nothing, params);
        }

        void play_sound_3d(const std::string &name_, const object &source_, vector3 &pos_, float volume_, float pitch_, float distance_) {
            std::vector<game_value> params{
                name_,
                source_,
                pos_,
                volume_,
                pitch_,
                distance_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__playsound3d__array__ret__nothing, params);
        }





        std::vector<std::string> registered_tasks(const team_member &member_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__registeredtasks__team_member__ret__array, member_));
        }

        void remove_from_remains_collector(const std::vector<object> &remains_) {
            std::vector<game_value> remains;
            for (auto remain : remains_)
                remains.push_back(game_value(remain));

            host::functions.invoke_raw_unary(client::__sqf::unary__removefromremainscollector__array__ret__nothing, remains);
        }

        void remove_mission_event_handler(const std::string &type_, float index_) {
            std::vector<game_value> params{
                type_,
                index_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__removemissioneventhandler__array__ret__nothing, params);
        }

        void remove_music_event_handler(const std::string &type_, float id_) {
            std::vector<game_value> params{
                type_,
                id_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__removemusiceventhandler__array__ret__nothing, params);
        }

        object rope_create(const object &from_obj_, const vector3 &from_point_, const object &to_obj_, const vector3 &to_point_, float segments_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                to_obj_,
                to_point_,
                segments_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const vector3 &from_point_, const object &to_obj_, const vector3 &to_point_, float segments_, float length_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                to_obj_,
                to_point_,
                segments_,
                length_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const std::string &from_point_, const object &to_obj_, const vector3 &to_point_, float segments_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                to_obj_,
                to_point_,
                segments_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const std::string &from_point_, const object &to_obj_, const vector3 &to_point_, float segments_, float length_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                to_obj_,
                to_point_,
                segments_,
                length_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const vector3 &from_point_, const object &to_obj_, const std::string &to_point_, float segments_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                to_obj_,
                to_point_,
                segments_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const vector3 &from_point_, const object &to_obj_, const std::string &to_point_, float segments_, float length_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                to_obj_,
                to_point_,
                segments_,
                length_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const std::string &from_point_, const object &to_obj_, const std::string &to_point_, float segments_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                to_obj_,
                to_point_,
                segments_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const std::string &from_point_, const object &to_obj_, const std::string &to_point_, float segments_, float length_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                to_obj_,
                to_point_,
                segments_,
                length_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const vector3 &from_point_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }


        object rope_create(const object &from_obj_, const vector3 &from_point_, float length_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                length_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const std::string &from_point_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        object rope_create(const object &from_obj_, const std::string &from_point_, float length_) {
            std::vector<game_value> params{
                from_obj_,
                from_point_,
                length_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__ropecreate__array__ret__object, params));
        }

        void rope_cut(const object &rope_, float distance_) {
            std::vector<game_value> params{
                rope_,
                distance_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__ropecut__array__ret__nothing, params);
        }

        std::vector<vector3> rope_end_position(const object &rope_) {
            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__ropeendposition__object__ret__array, rope_);

            std::vector<vector3> end_positions = { __helpers::__convert_to_vector3(ret[0]), __helpers::__convert_to_vector3(ret[1]) };
            return end_positions;
        }

        void rope_unwind(const object &rope_, float speed_, float length_) {
            std::vector<game_value> params{
                rope_,
                speed_,
                length_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__ropeunwind__array__ret__nothing, params);
        }

        void rope_unwind(const object &rope_, float speed_, float length_, bool relative_) {
            std::vector<game_value> params{
                rope_,
                speed_,
                length_,
                relative_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__ropeunwind__array__ret__nothing, params);
        }



        std::vector<rv_best_place> select_best_places(const object &obj_, float radius_, const std::string &expression_, float precision_, float max_results_) {
            std::vector<game_value> params{
                obj_,
                radius_,
                expression_,
                precision_,
                max_results_
            };

            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__selectbestplaces__array__ret__array, params);

            std::vector<rv_best_place> best_places;
            for (uint32_t i = 0; i < ret.length(); ++i)
                best_places.push_back(rv_best_place({ ret[i] }));

            return best_places;
        }

        std::vector<rv_best_place> select_best_places(const vector3 &pos_, float radius_, const std::string &expression_, float precision_, float max_results_) {
            std::vector<game_value> params{
                pos_,
                radius_,
                expression_,
                precision_,
                max_results_
            };

            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__selectbestplaces__array__ret__array, params);

            std::vector<rv_best_place> best_places;
            for (uint32_t i = 0; i < ret.length(); ++i)
                best_places.push_back(rv_best_place({ ret[i] }));

            return best_places;
        }

        

        void set_compass_oscillation(float angle_, float freq_min_, float freq_max_) {
            std::vector<game_value> params{
                angle_,
                freq_min_,
                freq_max_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__setcompassoscillation__array__ret__nothing, params);
        }



        void set_detail_map_blend_pars(float full_detail_, float no_detail_) {
            std::vector<game_value> params{
                full_detail_,
                no_detail_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__setdetailmapblendpars__array__ret__nothing, params);
        }

        void set_group_icons_visible(bool map_, bool hud_) {
            std::vector<game_value> params{
                map_,
                hud_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__setgroupiconsvisible__array__ret__nothing, params);
        }

        std::vector<bool> group_icons_visible() {
            return __helpers::__convert_to_booleans_vector(host::functions.invoke_raw_nular(client::__sqf::nular__groupiconsvisible__ret__array));
        }

        void set_hud_movement_levels(float min_speed_, float max_speed_, float min_alt_, float max_alt_, float min_dir_, float max_dir_, const object & obj_) {
            std::vector<game_value> params{
                min_speed_,
                max_speed_,
                min_alt_,
                max_alt_,
                min_dir_,
                max_dir_,
                obj_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__sethudmovementlevels__array__ret__nothing, params);
        }

        void set_hud_movement_levels(float min_speed_, float max_speed_, float min_alt_, float max_alt_, float min_dir_, float max_dir_, const vector3& pos_) {
            std::vector<game_value> params{
                min_speed_,
                max_speed_,
                min_alt_,
                max_alt_,
                min_dir_,
                max_dir_,
                pos_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__sethudmovementlevels__array__ret__nothing, params);
        }

        void set_local_wind_params(float strength_, float diameter_) {
            std::vector<game_value> params{
                strength_,
                diameter_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__setlocalwindparams__array__ret__nothing, params);
        }

        void set_mouse_position(float x_, float y_) {
            std::vector<game_value> params{
                x_,
                y_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__setmouseposition__array__ret__nothing, params);
        }

        float set_music_event_handler(const std::string& type_, const std::string& command_) {
            std::vector<game_value> params{
                type_,
                command_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__setmusiceventhandler__array__ret__nothing, params));
        }

        bool set_stat_value(const std::string& name_, float value_) {
            std::vector<game_value> params{
                name_,
                value_
            };

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__setstatvalue__array__ret__bool, params));
        }

        void set_traffic_density(float density_, float x_min_, float x_max_, float z_min_, float z_max_) {
            std::vector<game_value> params{
                density_,
                x_min_,
                x_max_,
                z_min_,
                z_max_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__settrafficdensity__array__ret__nothing, params);
        }

        void set_traffic_gap(float gap_, float x_min_, float x_max_, float z_min_, float z_max_) {
            std::vector<game_value> params{
                gap_,
                x_min_,
                x_max_,
                z_min_,
                z_max_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__settrafficgap__array__ret__nothing, params);
        }

        void set_traffic_speed(float speed_, float x_min_, float x_max_, float z_min_, float z_max_) {
            std::vector<game_value> params{
                speed_,
                x_min_,
                x_max_,
                z_min_,
                z_max_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__settrafficspeed__array__ret__nothing, params);
        }

        

        std::vector<task> simple_tasks(const object& unit_) {
            return __helpers::__convert_to_tasks_vector(host::functions.invoke_raw_unary(client::__sqf::unary__simpletasks__object__ret__array, unit_));
        }

        void simul_cloud_density(const vector3& pos_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__simulclouddensity__array__ret__scalar, pos_);
        }

        void simul_cloud_occlusion(const vector3& pos1_, const vector3& pos2_) {
            std::vector<game_value> params{
                pos1_,
                pos2_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__simulcloudocclusion__array__ret__scalar, params);
        }

        bool simul_in_clouds(const vector3& pos_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__simulinclouds__array__ret__bool, pos_));
        }



        std::vector<std::string> squad_params(const object &unit_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__squadparams__object__ret__array, unit_));
        }

        void start_loading_screen(const std::string& text_) {
            std::vector<game_value> params{
                text_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__startloadingscreen__array__ret__nothing, params);
        }

        void start_loading_screen(const std::string& text_, const std::string& resource_) {
            std::vector<game_value> params{
                text_,
                resource_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__startloadingscreen__array__ret__nothing, params);
        }

        std::vector<std::string> support_info(const std::string& mask_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__supportinfo__string__ret__array, mask_));
        }

        bool surface_is_water(const vector3& pos_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__surfaceiswater__array__ret__bool, pos_));
        }

        vector3 surface_normal(const vector3& pos_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__surfacenormal__array__ret__array, pos_));
        }

        std::string surface_type(const vector3& pos_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__surfacetype__array__ret__string, pos_));
        }

        std::vector<object> synchronized_objects(const object& obj_) {
            return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__synchronizedobjects__object__ret__array, obj_));
        }

        object cursor_object() {
            return game_value(__helpers::__retrieve_nular_object(client::__sqf::nular__cursorobject__ret__object));
        }

        float get_client_state_number() {
            return game_value(__helpers::__retrieve_nular_number(client::__sqf::nular__getclientstatenumber__ret__string));
        }





        bool unit_ready(const object& unit_) {
            return __helpers::__bool_unary_object(client::__sqf::unary__unitready__object_array__ret__bool, unit_);
        }

        std::vector<std::string> unit_addons(const std::string& class_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__unitaddons__string__ret__array, class_));
        }



        rv_uav_control uav_control(const object& uav_) {
            return rv_uav_control(host::functions.invoke_raw_unary(client::__sqf::unary__uavcontrol__object__ret__array, uav_));
        }





        std::vector<std::string> task_description(const task& task_) {
            return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__taskdescription__task__ret__array, task_));
        }

        void task_hint(const std::string& text_, const rv_color& color_, const std::string& icon_) {
            std::vector<game_value> params{
                text_,
                color_,
                icon_
            };

            host::functions.invoke_raw_unary(client::__sqf::unary__taskhint__array__ret__nothing, params);
        }

        rv_expected_destination expected_destination(const object& unit_) {
            return rv_expected_destination(host::functions.invoke_raw_unary(client::__sqf::unary__expecteddestination__object__ret__array, unit_));
        }



        rv_model_info get_model_info(const object& object_) {
            return rv_model_info(host::functions.invoke_raw_unary(client::__sqf::unary__getmodelinfo__object__ret__array, object_));
        }




        void log_network_terminate(const float& handle_) {
            host::functions.invoke_raw_unary(client::__sqf::unary__lognetworkterminate__scalar__ret__nothing, handle_);
        }



      
        vector3 task_destination(const task& task_) {
            game_value ret = host::functions.invoke_raw_unary(client::__sqf::unary__taskdestination__task__ret__array, task_);

            if (ret.length() == 0) {
                return {};
            }
            else {
                return __helpers::__convert_to_vector3(ret);
            }
        }

        

        bool is_equal_to(const object& l_, const object& r_) {
            return game_value(host::functions.invoke_raw_binary(client::__sqf::__sqf::binary__isequalto__any__any__ret__bool, l_,r_));
        }

        std::string format(const std::vector<game_value> &params_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::__sqf::unary__format__array__ret__string, params_));         
        }



        bool open_map(bool value_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__openmap__bool__ret__bool, value_));
        }

        bool open_map(bool show_, bool forced_) {
            game_value args(std::vector<game_value> {
                show_,
                    forced_
            });

            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__openmap__array__ret__bool, args));
        }

        void enable_uav_waypoints(object & uav_, bool enable_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__enableuavwaypoints__object__bool__ret__nothing, enable_, uav_);
        }



    }
}
