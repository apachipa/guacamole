/******************************************************************************
 * guacamole - delicious VR                                                   *
 *                                                                            *
 * Copyright: (c) 2011-2013 Bauhaus-Universität Weimar                        *
 * Contact:   felix.lauer@uni-weimar.de / simon.schneegans@uni-weimar.de      *
 *                                                                            *
 * This program is free software: you can redistribute it and/or modify it    *
 * under the terms of the GNU General Public License as published by the Free *
 * Software Foundation, either version 3 of the License, or (at your option)  *
 * any later version.                                                         *
 *                                                                            *
 * This program is distributed in the hope that it will be useful, but        *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License   *
 * for more details.                                                          *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with this program. If not, see <http://www.gnu.org/licenses/>.             *
 *                                                                            *
 ******************************************************************************/

#ifndef GUA_INCLUDE_SPOINTS_HPP
#define GUA_INCLUDE_SPOINTS_HPP

#include <gua/spoints/SPointsNode.hpp>
#include <gua/spoints/SPointsPass.hpp>
#include <gua/spoints/SPointsLoader.hpp>

#if defined (_MSC_VER)
#if defined (GUA_SPOINTS_LIBRARY)
#define GUA_SPOINTS_DLL __declspec( dllexport )
#else
#define GUA_SPOINTS_DLL __declspec( dllimport )
#endif
#else
#define GUA_SPOINTS_DLL
#endif // #if defined(_MSC_VER)

#endif  // GUA_INCLUDE_SPOINTS_HPP
