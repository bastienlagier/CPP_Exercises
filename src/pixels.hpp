#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA
{
    uint8_t r,g,b,a;
};
struct RGB
{
    uint8_t r,g,b;
};
struct Luma
{
    uint8_t gray;
};


template<typename A, typename B>
A from(const B & stuff);

template<>
RGBA from(const RGBA & x)
{
    return x;
}

template<>
RGB from(const RGB & x)
{
    return x;
}

template<>
Luma from(const Luma & x)
{
    return x;
}

template<>
RGBA from(const RGB & x)
{
    return {x.r,x.g,x.b,255};
}

template<>
RGB from(const RGBA & x)
{
    return {x.r,x.g,x.b};
}

template<>
RGB from(const Luma & x) {
    auto rgb = lib::grayscale_to_rgb(x.gray);
    return {rgb[0], rgb[1], rgb[2]};
}

template<>
Luma from(const RGB & x) {
    return {lib::rgb_to_grayscale(x.r, x.g, x.b)};
}

template<>
RGBA from(const Luma & x) {
    auto rgb = lib::grayscale_to_rgb(x.gray);
    return {rgb[0], rgb[1], rgb[2], 255};
}

template<>
Luma from(const RGBA & x) {
    return {lib::rgb_to_grayscale(x.r, x.g, x.b)};
}

RGBA operator+(const RGBA & lhs, const RGBA & rhs) {
    const auto [r, g, b, a] = lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, 
        rhs.r, rhs.g, rhs.b, rhs.a);
    return {r, g, b, a};
}

RGBA operator+(const RGBA & lhs, const RGB & rhs) {
    const auto [r, g, b, a] = lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, 
        rhs.r, rhs.g, rhs.b, 255);
    return {r, g, b, a};
}

RGB operator+(const RGB & lhs, const RGBA & rhs) {
    const auto [r, g, b, a] = lib::mix_color(lhs.r, lhs.g, lhs.b, 255, 
        rhs.r, rhs.g, rhs.b, rhs.a);
    return {r, g, b};
}

RGB operator+(const Luma & lhs, const RGBA & rhs) {
    RGB rgb = from<RGB, Luma>(lhs);
    const auto [r, g, b, a] = lib::mix_color(rgb.r, rgb.g, rgb.b, 255, 
        rhs.r, rhs.g, rhs.b, rhs.a);
    return {r, g, b};
}

RGB operator+(const Luma & lhs, const RGB & rhs) {
    RGB rgb = from<RGB, Luma>(lhs);
    const auto [r, g, b, a] = lib::mix_color(rgb.r, rgb.g, rgb.b, 255, 
        rhs.r, rhs.g, rhs.b, 255);
    return {r, g, b};
}

RGB operator+(const RGB & lhs, const RGB & rhs) {
    const auto [r, g, b, a] = lib::mix_color(lhs.r, lhs.g, lhs.b, 255, 
        rhs.r, rhs.g, rhs.b, 255);
    return {r, g, b};
}


template<typename A> 
RGBA operator+(const A & p, const Luma & mask) {
    RGBA rgba = from<RGBA, A>(p);
    rgba.a = uint8_t((uint32_t(rgba.a)*uint32_t(mask.gray)/255));
    return rgba;
}