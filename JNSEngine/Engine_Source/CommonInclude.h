#pragma once
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <type_traits>

#define arraysize(a) (sizeof(a) / sizeof(a[0]))

// Enable enum flags:
// https://www.justsoftwaresolutions.co.uk/cplusplus/using-enum-classes-as-bitfields.html

template<typename E>
struct enable_bitmask_operators
{
	static constexpr bool enable = false;
};

template<typename E>
constexpr typename std::enable_if<enable_bitmask_operators<E>::enable, E>::type operator|(E lhs, E rhs)
{
	typedef typename std::underlying_type<E>::type underlying;
	return static_cast<E>
		(
			static_cast<underlying>(lhs) | static_cast<underlying>(rhs)
			);
}

template<typename E>
constexpr typename std::enable_if<enable_bitmask_operators<E>::enable, E&>::type operator|=(E& lhs, E rhs)
{
	typedef typename std::underlying_type<E>::type underlying;
	lhs = static_cast<E>
		(
			static_cast<underlying>(lhs) | static_cast<underlying>(rhs)
			);

	return lhs;
}

template<typename E>
constexpr typename std::enable_if<enable_bitmask_operators<E>::enable, E>::type operator&(E lhs, E rhs)
{
	typedef typename std::underlying_type<E>::type underlying;
	return static_cast<E>
		(
			static_cast<underlying>(lhs) & static_cast<underlying>(rhs)
			);
}

template<typename E>
constexpr typename std::enable_if<enable_bitmask_operators<E>::enable, E&>::type operator&=(E& lhs, E rhs)
{
	typedef typename std::underlying_type<E>::type underlying;
	lhs = static_cast<E>
		(
			static_cast<underlying>(lhs) & static_cast<underlying>(rhs)
			);

	return lhs;
}

template<typename E>
constexpr typename std::enable_if<enable_bitmask_operators<E>::enable, E>::type operator~(E rhs)
{
	typedef typename std::underlying_type<E>::type underlying;
	rhs = static_cast<E>
		(
			~static_cast<underlying>(rhs)
			);

	return rhs;
}

template<typename E>
constexpr bool has_flag(E lhs, E rhs)
{
	return (lhs & rhs) == rhs;
}


#include <random>
std::mt19937 gen{ std::random_device{}() };
// Define a uniform distribution between 0 and 1
std::uniform_real_distribution<float> dist{ 0.0f, 1.0f };

std::uniform_real_distribution<> disX(-800.0f, 800.0f);
std::uniform_real_distribution<> disY(-420.0f, 420.0f);
std::uniform_real_distribution<> rangecolorR(0.0f, 1.0f);
std::uniform_real_distribution<> rangecolorG(0.0f, 1.0f);
std::uniform_real_distribution<> rangecolorB(0.0f, 1.0f);
std::uniform_real_distribution<> rangeScale(10.0f, 30.0f);