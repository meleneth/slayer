%module Slayer
%{
/* Includes the header in the wrapper code */
#include "entity.hpp"
#include "entitymgr.hpp"
#include "sector.hpp"
#include "console.hpp"
#include "globals.hpp"
%}

/* Parse the header file to generate wrappers */
%include <std_string.i>
%include "entity.hpp"
%include "entitymgr.hpp"
%include "sector.hpp"
%include "console.hpp"
%include "globals.hpp"

