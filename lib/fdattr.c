/*	$Id$

 *  Return attributes of an opened handle
 *
 *  Return:
 *    0: on failure (means: modified regular file on fixed drv A:)
 *    else: attributes

	This file bases on OPENF.C of FreeCOM v0.81 beta 1.

	$Log$
	Revision 1.3  2006/06/11 02:47:05  blairdude
	Optimized FreeCOM for size, fixed LFN bugs, and started an int 2e handler (which safely fails at the moment)

	Revision 1.2  2004/02/01 13:52:17  skaus
	add/upd: CVS $id$ keywords to/of files
	
	Revision 1.1  2001/04/12 00:33:53  skaus
	chg: new structure
	chg: If DEBUG enabled, no available commands are displayed on startup
	fix: PTCHSIZE also patches min extra size to force to have this amount
	   of memory available on start
	bugfix: CALL doesn't reset options
	add: PTCHSIZE to patch heap size
	add: VSPAWN, /SWAP switch, .SWP resource handling
	bugfix: COMMAND.COM A:\
	bugfix: CALL: if swapOnExec == ERROR, no change of swapOnExec allowed
	add: command MEMORY
	bugfix: runExtension(): destroys command[-2]
	add: clean.bat
	add: localized CRITER strings
	chg: use LNG files for hard-coded strings (hangForEver(), init.c)
		via STRINGS.LIB
	add: DEL.C, COPY.C, CBREAK.C: STRINGS-based prompts
	add: fixstrs.c: prompts & symbolic keys
	add: fixstrs.c: backslash escape sequences
	add: version IDs to DEFAULT.LNG and validation to FIXSTRS.C
	chg: splitted code apart into LIB\*.c and CMD\*.c
	bugfix: IF is now using error system & STRINGS to report errors
	add: CALL: /N
	
 */

#include <dos.h>
#include "../config.h"

int fdattr(const int fd)
{
  struct REGPACK r;

  r.r_ax = 0x4400;              /* Get handle information */
  r.r_bx = fd;
  intr(0x21, &r);
  return (!( r.r_flags & 1 ) )         /* call OK */
  ? r.r_dx          /* attributes */
  : 0;            /* error */
}
