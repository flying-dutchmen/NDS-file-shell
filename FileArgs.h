

/*-----------------------------------------------------------------
origin:
 Copyright (C) 2005 - 2013
	Michael "Chishm" Chisholm
	Dave "WinterMute" Murphy
	Claudio "sverx"

License:
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.


------------------------------------------------------------------*/


#ifndef _FILEARGS_H_
#define	_FILEARGS_H_


#include <nds.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#include <fat.h>
#include <filesystem.h>
#include "nds_loader_arm9.h"

#ifdef __cplusplus
extern "C" {
#endif

static int bg2, bg3;
static u16 *sprite;
int ICON_POS_X, ICON_POS_Y;
static tNDSBanner banner;

char *cwd;
int bootArgVC (char *str);
void iconTitleInit (void);


#ifdef __cplusplus
}
#endif
#endif /* _FILEARGS_H_ */
