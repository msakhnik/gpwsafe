//
// main.cc
//
//     Created: 10.01.2012
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

#include "../config.h"
#include "App.hh"

#include <sys/stat.h>
#include <iostream>
#include <gcrypt.h>

using namespace std;
using namespace gPWS;

static char const *_Basename(char const *path)
{
    char const *res = strrchr(path, '/');
    if (!res)
        return path;
    return res + 1;
}

static void
_GcryProgressHandler(void *cb_data, const char *what,
                     int printchar, int current, int total)
{
    if (!strcmp(what, "need_entropy"))
    {
        cerr << "\rEntropy pool: " << current << " of " << total
             << " bytes are available.";
        if (current == total)
            cerr << " Done.              " << endl;
        else
            cerr << " Waiting for more..." << flush;
    }
}

int main(int argc, char* argv[])
{
    char const *program_name = _Basename(argv[0]);

    // Be nice and paranoid
    umask(0077);

    char const *const REQ_GCRYPT_VERSION = "1.2.0";
    if (!gcry_check_version(REQ_GCRYPT_VERSION))
    {
        cerr << "libgcrypt version mismatch\n" << endl;
        return 1;
    }
    // Allocate secure memory for sensitive information (won't be swapped)
    gcry_control(GCRYCTL_INIT_SECMEM, 16384, 0);
    gcry_set_progress_handler(_GcryProgressHandler, NULL);
    gcry_control(GCRYCTL_INITIALIZATION_FINISHED, 0);

    try
    {
        cApp app(program_name);
        app.Init(argc, argv);

        app.Run();
    }
    catch (cApp::ExitEx const &e)
    {
        return e.retcode;
    }
    return 0;
}

// vim: set et ts=4 sw=4:
