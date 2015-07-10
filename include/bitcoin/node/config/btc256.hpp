/**
 * Copyright (c) 2011-2014 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-node.
 *
 * libbitcoin-node is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_NODE_BTC256_HPP
#define LIBBITCOIN_NODE_BTC256_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <boost/program_options.hpp>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/node/define.hpp>

namespace libbitcoin {
namespace node {

/**
 * Serialization helper to convert between base16 string and hash_digest.
 */
class btc256
{
public:

    /**
     * Default constructor.
     */
    BCN_API btc256();

    /**
     * Initialization constructor.
     * @param[in]  hexcode  The value to initialize with.
     */
    BCN_API btc256(const std::string& hexcode);

    /**
     * Initialization constructor.
     * @param[in]  value  The value to initialize with.
     */
    BCN_API btc256(const hash_digest& value);

    /**
     * Copy constructor.
     * @param[in]  other  The object to copy into self on construct.
     */
    BCN_API btc256(const btc256& other);

    /**
     * Overload cast to internal type.
     * @return  This object's value cast to internal type.
     */
    BCN_API operator const hash_digest&() const;

    /**
     * Overload stream in. Throws if input is invalid.
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    BCN_API friend std::istream& operator>>(std::istream& input,
        btc256& argument);

    /**
     * Overload stream out.
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    BCN_API friend std::ostream& operator<<(std::ostream& output,
        const btc256& argument);

private:

    /**
     * The state of this object.
     */
    hash_digest value_;
};

} // namespace node
} // namespace libbitcoin

#endif