/* -*- indent-tabs-mode: nil -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var DESC = "Reads of closure-bound free variable";
// Compare against 'for-1' and 'globalvar-read-1.as'
// (only additional work should be closure var read and local var write)
include "driver.as"

function mkreadloop(closed_over_var:int):Function {
    function readloop():int {
        var v:int;
        for ( var i:uint=0; i < 100000 ; i++ )
            v = closed_over_var;
        return v;
    }
    return readloop;
}

TEST(mkreadloop(3), "closedvar-read-1");
