//
// Field.hh
//
//     Created: 20.01.2012
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

#pragma once

#include "Defs.hh"

#include <stdint.h>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

namespace gPWS {

struct sField
    : boost::noncopyable
{
    typedef boost::shared_ptr<sField> PtrT;

    enum eType
    {
        T_GROUP = 0x02,
        T_TITLE = 0x03,
        T_USER = 0x04,
        T_NOTES = 0x05,
        T_PASS = 0x06,
        T_URL = 0x0D,

        T_END = 0xFF
    };

    uint8_t type;
    StringX value;

    void *operator new(size_t n);
    void operator delete(void *p, size_t n);
};

} //namespace gPWS;

// vim: set et ts=4 sw=4:
