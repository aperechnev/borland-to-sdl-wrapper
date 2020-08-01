/***************************************************************************
 *   Copyright (C) 2010 by Alexander Peretchnev                            *
 *   herfleisch@gmail.com                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "graphics.h"


SDL_Surface * LBGH_screenMain = NULL;
int LBGH_errorcode;



void initgraph(int * graphdriver, int * graphmode, const char * pathtodriver)
{
    SDL_Init(SDL_INIT_VIDEO);

    if (*graphdriver == DETECT)
    {
        *graphdriver = EGA;
        *graphmode = EGAHI;
    }

    switch (*graphdriver)
    {
        case CGA:
            break;  
        case VGA:
            switch (*graphmode)
            {
                case VGALO:
                    LBGH_screenMain = SDL_SetVideoMode(640, 200, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
                    break;
                case VGAMED:
                    LBGH_screenMain = SDL_SetVideoMode(640, 350, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
                    break;
                case VGAHI:
                    LBGH_screenMain = SDL_SetVideoMode(640, 380, 16, SDL_HWSURFACE);
                    break;
                default:
                    LBGH_errorcode = -10;
            }
            break;
        case EGA:
            switch (*graphmode)
            {
                case EGALO:
                    LBGH_screenMain = SDL_SetVideoMode(640, 200, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
                    break;
                case EGAHI:
                    LBGH_screenMain = SDL_SetVideoMode(640, 350, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
                    break;
                default:
                    LBGH_errorcode = -10;
            }
            break;
        default:
            LBGH_errorcode = -3;
            break;
    }
}

int graphresult() { return LBGH_errorcode; }

void putpixel(int x, int y, int color)
{
    pixelColor(LBGH_screenMain, x, y, color);
}

void setactivepage(int pagen)
{
    SDL_Flip(LBGH_screenMain);
}

void closegraph() { SDL_Quit(); }