#pragma once
//=========================================================================//
/*7331 Define*/
#define _CRT_SECURE_NO_WARNINGS
//=========================================================================//
/*Official Headers*/
#include <windows.h>
#include <math.h>
#include <Psapi.h>
#include <stdio.h>
#include <string>
//=========================================================================//
/*My Headers*/
#include "cEngine.h"
#include "cApis.h"
#include "cMemory.h"
#include "cVector.h"
#include "cClientPlayer.h"
#include "cClientEngine.h"
#include "cMiscs.h"
#include "cNetvars.h"
#include "cMaths.h"
#include "cCvars.h"
#include "cAimbot.h"
//=========================================================================//


extern cEngine *cEng;
extern cMiscs *cMisc;
extern cApis *cApi;
extern cMemory *cMem;
extern cAimbot *cAim;
extern cNetvars *cNetvar;
extern cMaths *cMath;
extern cCvars *cVars;