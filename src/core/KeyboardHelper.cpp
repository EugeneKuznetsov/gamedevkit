#include "KeyboardHelper.hpp"

#include <glfwcxx/KeyboardInput.hpp>

#include <GDK/Keyboard.hpp>

#define GLFWCXX_TO_GDK(glfwcxx_value, gdk_value) \
    case glfwcxx_value:                          \
        return gdk_value;

#define GDK_ENUM_DEFAULT(gdk_value) \
    default:                        \
        return gdk_value;

namespace gamedevkit::helpers::input {

auto keyboard_key(const glfwcxx::input::KeyboardKey& key) -> gamedevkit::input::keyboard::Key
{
    switch (key) {
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_unknown, gamedevkit::input::keyboard::Key::key_unknown)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_space, gamedevkit::input::keyboard::Key::key_space)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_apostrophe, gamedevkit::input::keyboard::Key::key_apostrophe)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_comma, gamedevkit::input::keyboard::Key::key_comma)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_minus, gamedevkit::input::keyboard::Key::key_minus)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_period, gamedevkit::input::keyboard::Key::key_period)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_slash, gamedevkit::input::keyboard::Key::key_slash)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_0, gamedevkit::input::keyboard::Key::key_0)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_1, gamedevkit::input::keyboard::Key::key_1)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_2, gamedevkit::input::keyboard::Key::key_2)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_3, gamedevkit::input::keyboard::Key::key_3)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_4, gamedevkit::input::keyboard::Key::key_4)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_5, gamedevkit::input::keyboard::Key::key_5)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_6, gamedevkit::input::keyboard::Key::key_6)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_7, gamedevkit::input::keyboard::Key::key_7)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_8, gamedevkit::input::keyboard::Key::key_8)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_9, gamedevkit::input::keyboard::Key::key_9)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_semicolon, gamedevkit::input::keyboard::Key::key_semicolon)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_equal, gamedevkit::input::keyboard::Key::key_equal)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_a, gamedevkit::input::keyboard::Key::key_a)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_b, gamedevkit::input::keyboard::Key::key_b)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_c, gamedevkit::input::keyboard::Key::key_c)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_d, gamedevkit::input::keyboard::Key::key_d)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_e, gamedevkit::input::keyboard::Key::key_e)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f, gamedevkit::input::keyboard::Key::key_f)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_g, gamedevkit::input::keyboard::Key::key_g)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_h, gamedevkit::input::keyboard::Key::key_h)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_i, gamedevkit::input::keyboard::Key::key_i)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_j, gamedevkit::input::keyboard::Key::key_j)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_k, gamedevkit::input::keyboard::Key::key_k)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_l, gamedevkit::input::keyboard::Key::key_l)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_m, gamedevkit::input::keyboard::Key::key_m)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_n, gamedevkit::input::keyboard::Key::key_n)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_o, gamedevkit::input::keyboard::Key::key_o)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_p, gamedevkit::input::keyboard::Key::key_p)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_q, gamedevkit::input::keyboard::Key::key_q)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_r, gamedevkit::input::keyboard::Key::key_r)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_s, gamedevkit::input::keyboard::Key::key_s)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_t, gamedevkit::input::keyboard::Key::key_t)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_u, gamedevkit::input::keyboard::Key::key_u)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_v, gamedevkit::input::keyboard::Key::key_v)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_w, gamedevkit::input::keyboard::Key::key_w)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_x, gamedevkit::input::keyboard::Key::key_x)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_y, gamedevkit::input::keyboard::Key::key_y)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_z, gamedevkit::input::keyboard::Key::key_z)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_left_bracket, gamedevkit::input::keyboard::Key::key_left_bracket)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_backslash, gamedevkit::input::keyboard::Key::key_backslash)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_right_bracket, gamedevkit::input::keyboard::Key::key_right_bracket)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_grave_accent, gamedevkit::input::keyboard::Key::key_grave_accent)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_world_1, gamedevkit::input::keyboard::Key::key_world_1)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_world_2, gamedevkit::input::keyboard::Key::key_world_2)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_escape, gamedevkit::input::keyboard::Key::key_escape)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_enter, gamedevkit::input::keyboard::Key::key_enter)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_tab, gamedevkit::input::keyboard::Key::key_tab)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_backspace, gamedevkit::input::keyboard::Key::key_backspace)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_insert, gamedevkit::input::keyboard::Key::key_insert)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_delete, gamedevkit::input::keyboard::Key::key_delete)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_right, gamedevkit::input::keyboard::Key::key_right)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_left, gamedevkit::input::keyboard::Key::key_left)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_down, gamedevkit::input::keyboard::Key::key_down)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_up, gamedevkit::input::keyboard::Key::key_up)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_page_up, gamedevkit::input::keyboard::Key::key_page_up)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_page_down, gamedevkit::input::keyboard::Key::key_page_down)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_home, gamedevkit::input::keyboard::Key::key_home)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_end, gamedevkit::input::keyboard::Key::key_end)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_caps_lock, gamedevkit::input::keyboard::Key::key_caps_lock)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_scroll_lock, gamedevkit::input::keyboard::Key::key_scroll_lock)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_num_lock, gamedevkit::input::keyboard::Key::key_num_lock)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_print_screen, gamedevkit::input::keyboard::Key::key_print_screen)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_pause, gamedevkit::input::keyboard::Key::key_pause)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f1, gamedevkit::input::keyboard::Key::key_f1)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f2, gamedevkit::input::keyboard::Key::key_f2)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f3, gamedevkit::input::keyboard::Key::key_f3)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f4, gamedevkit::input::keyboard::Key::key_f4)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f5, gamedevkit::input::keyboard::Key::key_f5)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f6, gamedevkit::input::keyboard::Key::key_f6)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f7, gamedevkit::input::keyboard::Key::key_f7)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f8, gamedevkit::input::keyboard::Key::key_f8)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f9, gamedevkit::input::keyboard::Key::key_f9)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f10, gamedevkit::input::keyboard::Key::key_f10)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f11, gamedevkit::input::keyboard::Key::key_f11)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f12, gamedevkit::input::keyboard::Key::key_f12)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f13, gamedevkit::input::keyboard::Key::key_f13)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f14, gamedevkit::input::keyboard::Key::key_f14)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f15, gamedevkit::input::keyboard::Key::key_f15)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f16, gamedevkit::input::keyboard::Key::key_f16)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f17, gamedevkit::input::keyboard::Key::key_f17)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f18, gamedevkit::input::keyboard::Key::key_f18)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f19, gamedevkit::input::keyboard::Key::key_f19)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f20, gamedevkit::input::keyboard::Key::key_f20)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f21, gamedevkit::input::keyboard::Key::key_f21)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f22, gamedevkit::input::keyboard::Key::key_f22)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f23, gamedevkit::input::keyboard::Key::key_f23)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f24, gamedevkit::input::keyboard::Key::key_f24)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_f25, gamedevkit::input::keyboard::Key::key_f25)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_0, gamedevkit::input::keyboard::Key::key_kp_0)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_1, gamedevkit::input::keyboard::Key::key_kp_1)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_2, gamedevkit::input::keyboard::Key::key_kp_2)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_3, gamedevkit::input::keyboard::Key::key_kp_3)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_4, gamedevkit::input::keyboard::Key::key_kp_4)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_5, gamedevkit::input::keyboard::Key::key_kp_5)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_6, gamedevkit::input::keyboard::Key::key_kp_6)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_7, gamedevkit::input::keyboard::Key::key_kp_7)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_8, gamedevkit::input::keyboard::Key::key_kp_8)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_9, gamedevkit::input::keyboard::Key::key_kp_9)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_decimal, gamedevkit::input::keyboard::Key::key_kp_decimal)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_divide, gamedevkit::input::keyboard::Key::key_kp_divide)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_multiply, gamedevkit::input::keyboard::Key::key_kp_multiply)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_subtract, gamedevkit::input::keyboard::Key::key_kp_subtract)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_add, gamedevkit::input::keyboard::Key::key_kp_add)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_enter, gamedevkit::input::keyboard::Key::key_kp_enter)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_kp_equal, gamedevkit::input::keyboard::Key::key_kp_equal)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_left_shift, gamedevkit::input::keyboard::Key::key_left_shift)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_left_control, gamedevkit::input::keyboard::Key::key_left_control)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_left_alt, gamedevkit::input::keyboard::Key::key_left_alt)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_left_super, gamedevkit::input::keyboard::Key::key_left_super)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_right_shift, gamedevkit::input::keyboard::Key::key_right_shift)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_right_control, gamedevkit::input::keyboard::Key::key_right_control)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_right_alt, gamedevkit::input::keyboard::Key::key_right_alt)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_right_super, gamedevkit::input::keyboard::Key::key_right_super)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKey::key_menu, gamedevkit::input::keyboard::Key::key_menu)
        GDK_ENUM_DEFAULT(gamedevkit::input::keyboard::Key::invalid);
    }
}

auto keyboard_action(const glfwcxx::input::KeyboardAction& action) -> gamedevkit::input::keyboard::Action
{
    switch (action) {
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardAction::release, gamedevkit::input::keyboard::Action::release)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardAction::press, gamedevkit::input::keyboard::Action::press)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardAction::repeat, gamedevkit::input::keyboard::Action::repeat)
        GDK_ENUM_DEFAULT(gamedevkit::input::keyboard::Action::invalid)
    }
}

auto keyboard_modifier(const glfwcxx::input::KeyboardKeyModifier& modifier) -> gamedevkit::input::keyboard::Modifier
{
    switch (modifier) {
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKeyModifier::mod_shift, gamedevkit::input::keyboard::Modifier::mod_shift)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKeyModifier::mod_control, gamedevkit::input::keyboard::Modifier::mod_control)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKeyModifier::mod_alt, gamedevkit::input::keyboard::Modifier::mod_alt)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKeyModifier::mod_super, gamedevkit::input::keyboard::Modifier::mod_super)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKeyModifier::mod_caps_lock, gamedevkit::input::keyboard::Modifier::mod_caps_lock)
        GLFWCXX_TO_GDK(glfwcxx::input::KeyboardKeyModifier::mod_num_lock, gamedevkit::input::keyboard::Modifier::mod_num_lock)
        GDK_ENUM_DEFAULT(gamedevkit::input::keyboard::Modifier::invalid)
    }
}

}  // namespace gamedevkit::helpers::input
