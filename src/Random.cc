//
// Random.cc
//
//     Created: 27.01.2012
//      Author: A. Sakhnik
//
// This file is part of gpwsafe.
//
// Gpwsafe is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Gpwsafe is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with gpwsafe.  If not, see <http://www.gnu.org/licenses/>

#include "Random.hh"

#include <gcrypt.h>

namespace gPWS {

void cRandom::CreateNonce(uint8_t *buffer, unsigned len)
{
    gcry_create_nonce(buffer, len);
}

void cRandom::Randomize(uint8_t *buffer, unsigned length)
{
    gcry_randomize(buffer, length, GCRY_VERY_STRONG_RANDOM);
}

} //namespace gPWS;

// vim: set et ts=4 sw=4:
