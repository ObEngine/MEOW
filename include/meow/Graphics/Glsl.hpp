////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2021 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_GLSL_HPP
#define SFML_GLSL_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <meow/Graphics/Color.hpp>
#include <meow/Graphics/Transform.hpp>
#include <meow/System/Vector2.hpp>
#include <meow/System/Vector3.hpp>

namespace meow {
namespace priv {
// Forward declarations
template <std::size_t Columns, std::size_t Rows> struct Matrix;

template <typename T> struct Vector4;

#include <meow/Graphics/Glsl.inl>

} // namespace priv

////////////////////////////////////////////////////////////
/// \brief Namespace with GLSL types
///
////////////////////////////////////////////////////////////
namespace Glsl {

////////////////////////////////////////////////////////////
/// \brief 2D float vector (\p vec2 in GLSL)
///
////////////////////////////////////////////////////////////
typedef Vector2<float> Vec2;

////////////////////////////////////////////////////////////
/// \brief 2D int vector (\p ivec2 in GLSL)
///
////////////////////////////////////////////////////////////
typedef Vector2<int> Ivec2;

////////////////////////////////////////////////////////////
/// \brief 2D bool vector (\p bvec2 in GLSL)
///
////////////////////////////////////////////////////////////
typedef Vector2<bool> Bvec2;

////////////////////////////////////////////////////////////
/// \brief 3D float vector (\p vec3 in GLSL)
///
////////////////////////////////////////////////////////////
typedef Vector3<float> Vec3;

////////////////////////////////////////////////////////////
/// \brief 3D int vector (\p ivec3 in GLSL)
///
////////////////////////////////////////////////////////////
typedef Vector3<int> Ivec3;

////////////////////////////////////////////////////////////
/// \brief 3D bool vector (\p bvec3 in GLSL)
///
////////////////////////////////////////////////////////////
typedef Vector3<bool> Bvec3;

#ifdef SFML_DOXYGEN

////////////////////////////////////////////////////////////
/// \brief 4D float vector (\p vec4 in GLSL)
///
/// 4D float vectors can be implicitly converted from meow::Color
/// instances. Each color channel is normalized from integers
/// in [0, 255] to floating point values in [0, 1].
/// \code
/// meow::Glsl::Vec4 zeroVector;
/// meow::Glsl::Vec4 vector(1.f, 2.f, 3.f, 4.f);
/// meow::Glsl::Vec4 color = meow::Color::Cyan;
/// \endcode
////////////////////////////////////////////////////////////
typedef implementation - defined Vec4;

////////////////////////////////////////////////////////////
/// \brief 4D int vector (\p ivec4 in GLSL)
///
/// 4D int vectors can be implicitly converted from meow::Color
/// instances. Each color channel remains unchanged inside
/// the integer interval [0, 255].
/// \code
/// meow::Glsl::Ivec4 zeroVector;
/// meow::Glsl::Ivec4 vector(1, 2, 3, 4);
/// meow::Glsl::Ivec4 color = meow::Color::Cyan;
/// \endcode
////////////////////////////////////////////////////////////
typedef implementation - defined Ivec4;

////////////////////////////////////////////////////////////
/// \brief 4D bool vector (\p bvec4 in GLSL)
///
////////////////////////////////////////////////////////////
typedef implementation - defined Bvec4;

////////////////////////////////////////////////////////////
/// \brief 3x3 float matrix (\p mat3 in GLSL)
///
/// The matrix can be constructed from an array with 3x3
/// elements, aligned in column-major order. For example,
/// a translation by (x, y) looks as follows:
/// \code
/// float array[9] =
/// {
///     1, 0, 0,
///     0, 1, 0,
///     x, y, 1
/// };
///
/// meow::Glsl::Mat3 matrix(array);
/// \endcode
///
/// Mat3 can also be implicitly converted from meow::Transform:
/// \code
/// meow::Transform transform;
/// meow::Glsl::Mat3 matrix = transform;
/// \endcode
////////////////////////////////////////////////////////////
typedef implementation - defined Mat3;

////////////////////////////////////////////////////////////
/// \brief 4x4 float matrix (\p mat4 in GLSL)
///
/// The matrix can be constructed from an array with 4x4
/// elements, aligned in column-major order. For example,
/// a translation by (x, y, z) looks as follows:
/// \code
/// float array[16] =
/// {
///     1, 0, 0, 0,
///     0, 1, 0, 0,
///     0, 0, 1, 0,
///     x, y, z, 1
/// };
///
/// meow::Glsl::Mat4 matrix(array);
/// \endcode
///
/// Mat4 can also be implicitly converted from meow::Transform:
/// \code
/// meow::Transform transform;
/// meow::Glsl::Mat4 matrix = transform;
/// \endcode
////////////////////////////////////////////////////////////
typedef implementation - defined Mat4;

#else // SFML_DOXYGEN

typedef priv::Vector4<float> Vec4;
typedef priv::Vector4<int> Ivec4;
typedef priv::Vector4<bool> Bvec4;
typedef priv::Matrix<3, 3> Mat3;
typedef priv::Matrix<4, 4> Mat4;

#endif // SFML_DOXYGEN

} // namespace Glsl
} // namespace meow

#endif // SFML_GLSL_HPP

////////////////////////////////////////////////////////////
/// \namespace meow::Glsl
/// \ingroup graphics
///
/// \details The meow::Glsl namespace contains types that match
/// their equivalents in GLSL, the OpenGL shading language.
/// These types are exclusively used by the meow::Shader class.
///
/// Types that already exist in SFML, such as \ref meow::Vector2<T>
/// and \ref meow::Vector3<T>, are reused as typedefs, so you can use
/// the types in this namespace as well as the original ones.
/// Others are newly defined, such as Glsl::Vec4 or Glsl::Mat3. Their
/// actual type is an implementation detail and should not be used.
///
/// All vector types support a default constructor that
/// initializes every component to zero, in addition to a
/// constructor with one parameter for each component.
/// The components are stored in member variables called
/// x, y, z, and w.
///
/// All matrix types support a constructor with a float*
/// parameter that points to a float array of the appropriate
/// size (that is, 9 in a 3x3 matrix, 16 in a 4x4 matrix).
/// Furthermore, they can be converted from meow::Transform
/// objects.
///
/// \see meow::Shader
///
////////////////////////////////////////////////////////////
