
/*-----------------------------------------------------------------
src origin: hbmenu 
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

 Rev. KennyD
------------------------------------------------------------------*/


#include <string.h>
#include <vector>
#include "FileArgs.h"


using namespace std;

static inline void clearIcon (void) {
	dmaFillHalfWords(0, sprite, sizeof(banner.icon));
}

void iconTitleInit (char * name) {
	// initialize video mode
	videoSetMode(MODE_4_2D);

	// initialize VRAM banks
	vramSetPrimaryBanks(VRAM_A_MAIN_BG,
	                    VRAM_B_MAIN_SPRITE,
	                    VRAM_C_LCD,
	                    VRAM_D_LCD);

	// initialize OAM
	oamInit(&oamMain, SpriteMapping_1D_128, false);
	sprite = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_16Color);
	dmaFillHalfWords(0, sprite, sizeof(banner.icon));
	oamSet(&oamMain, 0, ICON_POS_X, ICON_POS_Y, 0, 0,
	       SpriteSize_32x32, SpriteColorFormat_16Color, sprite,
	       -1, 0, 0, 0, 0, 0);

	// oam can only be updated during vblank
	swiWaitForVBlank();
	oamUpdate(&oamMain);

		// this is an nds file!
		FILE *fp;
		unsigned int Icon_title_offset;
		int ret;

		// open file for reading info
		fp=fopen (name,"rb");
		if (fp==NULL) {
			// text
			printf ("(can't open file!)");
			// icon
			clearIcon();
			fclose (fp); return;
		}

		ret=fseek (fp, offsetof(tNDSHeader, bannerOffset), SEEK_SET);
		if (ret==0)
			ret=fread (&Icon_title_offset, sizeof(int), 1, fp); // read if seek succeed
		else
			ret=0;  // if seek fails set to !=1

		if (ret!=1) {
			// text
			printf ("(can't read file!)");
			// icon
			clearIcon();
			fclose (fp); return;
		}

		if (Icon_title_offset==0) {
			// text
			printf ("(no title/icon)");
			// icon
			clearIcon();
			fclose (fp); return;
		}

		ret=fseek (fp,Icon_title_offset,SEEK_SET);
		if (ret==0)
			ret=fread (&banner, sizeof(banner), 1, fp); // read if seek succeed
		else
			ret=0;  // if seek fails set to !=1

		if (ret!=1) {
			// text
			printf ("(can't read icon/title!)");
			// icon
			clearIcon();
			fclose (fp); return;
		}

		// close file!
		fclose (fp);

		// icon
		DC_FlushAll();
		dmaCopy(banner.icon,    sprite,         sizeof(banner.icon));
		dmaCopy(banner.palette, SPRITE_PALETTE, sizeof(banner.palette));
}

//this need ...
int bootArgVC (char *str)
{
		// Construct a command line
		int error = -1;
//		int pathLen = strlen (getcwd (cwd, MAXPATHLEN));
		std::vector<char*> argarray;

			char *pstr;
			const char seps[]= "\n\r\t ";

		// Tokenize arguments
			pstr= strtok(str, seps);

		while( pstr != NULL ) {
			argarray.push_back(strdup(pstr));
			pstr= strtok(NULL, seps);
		}

		if ( strcasecmp (argarray[0] + strlen(argarray[0]) - 4, ".nds") != 0 || argarray.size() == 0 ) {
			printf("no nds file specified\n");
		} else {
                         //copy & remove argarray.at(0) for runNdsFile()
                          cwd =strdup(argarray.at(0));
		          free(argarray.at(0));
                          argarray.erase(argarray.begin());

                //          argarray -= argarray.at(0); //overloaded opts nope
                //          argarray.pop_front;
                //          argarray.pop_back;
                //       argarray.erase(0);
                    

		//debug args
                  printf("cwd: %s \n", cwd); 
                  for(int x = 0; x < argarray.size(); x++) printf("argarray[%d] %s \n", x, argarray[x]);
	
	//	   error = runNdsFile (argarray[0], argarray.size() -1, (const char **)&argarray.at(1));
		   error = runNdsFile (cwd, argarray.size(), (const char **)&argarray[0]);

		while(argarray.size() !=0 ) {
			free(argarray.at(0));
			argarray.erase(argarray.begin());
		}

		while (1) {
			swiWaitForVBlank();
			scanKeys();
			if (!(keysHeld() & KEY_A)) break;
		}
 }  return error;
 }

 //kdl
