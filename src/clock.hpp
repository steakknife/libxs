/*
    Copyright (c) 2010-2012 250bpm s.r.o.
    Copyright (c) 2010-2011 Other contributors as noted in the AUTHORS file

    This file is part of Crossroads I/O project.

    Crossroads I/O is free software; you can redistribute it and/or modify it
    under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    Crossroads is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __XS_CLOCK_HPP_INCLUDED__
#define __XS_CLOCK_HPP_INCLUDED__

#include "stdint.hpp"

namespace xs
{

    class clock_t
    {
    public:

        clock_t ();
        ~clock_t ();

        //  CPU's timestamp counter. Returns 0 if it's not available.
        static uint64_t rdtsc ();

        //  High precision timestamp.
        static uint64_t now_us ();

        //  Low precision timestamp. In tight loops generating it can be
        //  10 to 100 times faster than the high precision timestamp.
        uint64_t now_ms ();

    private:

        //  TSC timestamp of when last time measurement was made.
        uint64_t last_tsc;

        //  Physical time corresponding to the TSC above (in milliseconds).
        uint64_t last_time;

        clock_t (const clock_t&);
        const clock_t &operator = (const clock_t&);
    };

}

#endif
