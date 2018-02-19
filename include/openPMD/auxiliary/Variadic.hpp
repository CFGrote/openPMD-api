/* Copyright 2017 Fabian Koller
 *
 * This file is part of openPMD-api.
 *
 * openPMD-api is free software: you can redistribute it and/or modify
 * it under the terms of of either the GNU General Public License or
 * the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * openPMD-api is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License and the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * and the GNU Lesser General Public License along with openPMD-api.
 * If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#if __cplusplus >= 201703L
#   include <variant>
namespace variadicSrc = std;
#else
#   include <mpark/variant.hpp>
namespace variadicSrc = mpark;
#endif

#include <type_traits>


namespace openPMD
{
/** Generic object to store a set of datatypes in without losing type safety.
 *
 * @tparam T_DTYPES Enumeration of datatypes to be stored and identified.
 * @tparam T        Varaidic template argument list of datatypes to be stored.
 */
template< class T_DTYPES, typename ... T >
class Variadic
{
    static_assert(std::is_enum< T_DTYPES >::value, "Datatypes to Variadic must be supplied as enum.");

public:
    using resource = variadicSrc::variant< T ... >;
    /** Construct a lightweight wrapper around a generic object that indicates
     * the concrete datatype of the specific object stored.
     *
     * @note    Gerneric objects can only generated implicitly if their datatype
     *          is contained in T_DTYPES.
     * @param   r   Generic object to be stored.
     */
    Variadic(resource r)
            : dtype{static_cast<T_DTYPES>(r.index())},
              m_data{r}
    { }

    /** Retrieve a stored specific object of known datatype with ensured type-safety.
     *
     * @throw   std::bad_variant_access if stored object is not of type U.
     * @tparam  U   Type of the object to be retrieved.
     * @return  Copy of the retrieved object of type U.
     */
    template< typename U >
    U get() const
    {
        return variadicSrc::get< U >(m_data);
    }

    /** Retrieve the stored generic object.
     *
     * @return  Copy of the stored generic object.
     */
    resource getResource() const
    {
        return m_data;
    }

    T_DTYPES dtype;

private:
    resource m_data;
};
} // openPMD