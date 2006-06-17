/*
    This file is part of SUPPL - the supplemental library for DOS
    Copyright (C) 1996-2000 Steffen Kaiser

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
/* $RCSfile$
   $Locker$	$Name$	$State$

ob(ject): getbootdisk
su(bsystem): portable
ty(pe): 
sh(ort description): Return boot disk / boot drive
pr(erequistes): 
va(lue): 0: on failure
	\item else: drive ID: 1 == A:, 2 == B:, ...
re(lated to): getdisk
se(condary subsystems): 
in(itialized by): 
wa(rning): Supported since MS DOS 4+, Novell DOS 7, OS/2 Warp v3+
bu(gs): 
co(mpilers): 

*/

#include "initsupl.loc"

#include <portable.h>

#include "suppldbg.h"

#ifdef RCS_Version
static char const rcsid[] = 
	"$Id$";
#endif

int getbootdisk(void)
{	int drive;
	USEREGS

	DBG_ENTER("getbootdisk", Suppl_portable)

	_DL = 0xff;
	_AX = 0x3305;
	geninterrupt(0x21);
	drive = _DL;
	if(_AL == 0xFF || drive > 32)
		DBG_RETURN_I( 0)

	DBG_RETURN_I( drive)
}
