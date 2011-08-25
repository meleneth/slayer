%module Slayer
%{
/* Includes the header in the wrapper code */
#include "entity.hpp"
#include "entitymgr.hpp"
#include "sector.hpp"
%}

/* Parse the header file to generate wrappers */
%include "entity.hpp"
%include "entitymgr.hpp"
%include "sector.hpp"

