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


#ifndef _GRAPHICS_H
#define	_GRAPHICS_H


/*
 * Include needed librires
 */

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>


/*
 * Graphic drivers defines
 */

#define DETECT      0
#define CGA         1
#define MCGA        2
#define EGA         3
#define EGA64       4
#define EGAMONO     5
#define IBM8514     6
#define HERCMONO    7
#define ATT400      8
#define VGA         9
#define PC3270      10


/*
 * Graphic modes defines
 */

//  CGA
#define CGAC0       0   // 320 x 200   C0          1
#define CGAC1       1   // 320 x 200   C1          1
#define CGAC2       2   // 320 x 200   C2          1
#define CGAC3       3   // 320 x 200   C3          1
#define CGAHI       4   // 640 x 200   2цвета      1

//  MCGA
#define MCGAC0      0   // 320 x 200   C0          1
#define MCGAC1      1   // 320 x 200   C1          1
#define MCGAC2      2   // 320 x 200   C2          1
#define MCGAC3      3   // 320 x 200   C3          1
#define MCGAMED     4   // 640 x 200   2цвета      1
#define MCGAHI      5   // 640 x 480   2цвета      1

// EGA
#define EGALO       0   // 640 x 200   16цветов    4
#define EGAHI       1   // 640 x 350   16цветов    2

// EGA64
#define EGA64LO     0   // 640 x 200   16цветов    1
#define EGA64HI     1   // 640 x 350   4 цвета     1

// EGA-MONO
#define EGAMONOHI   3   // 640 x 350   2 цвета     1*
#define EGAMONOHI   3   // 640 x 350   2 цвета     2**

// HERC
#define HERCMONOHI  0   // 720 x 348   2 цвета     2

// AT400
#define ATT400C0    0   // 320 x 200   C0          1
#define ATT400C1    1   // 320 x 200   C1          1
#define ATT400C2    2   // 320 x 200   C2          1
#define ATT400C3    3   // 320 x 200   C3          1
#define ATT400MED   4   // 640 x 200   2 цвета     1
#define ATT400HI    5   // 640 x 400   2 цвета     1

// VGA
#define VGALO       0   // 640 x 200   16цветов    2
#define VGAMED      1   // 640 x 350   16цветов    2
#define VGAHI       2   // 640 x 380   16цветов    1

// PC3270
#define PC3270HI    0   // 720 x 350   2 цвета     1

// IBM8514
#define IBM8514HI   0   // 640 x 480   256цветов
#define IBM8514LO   0   // 1024 x 768   256цветов


/*
 * Color defines
 */

#define BLACK           0x000000FF
#define BLUE            0x0000FFFF
#define GREEN           0x008000FF
#define CYAN            0x00FFFFFF
#define RED             0xFF0000FF
#define MAGENTA         0xFF00FFFF
#define BROWN           0x964B00FF
#define LIGHTGRAY       0xD3D3D3FF
#define DARKGRAY        0x808080FF
#define LIGHTBLUE       0xADD8E6FF
#define LIGHTGREEN      0x00FF00FF
#define LIGHTCYAN       0xE0FFFFFF
#define LIGHTRED        0xFA8072FF
#define LIGHTMAGENTA    0xEE82EEFF
#define YELLOW          0xFFFF00FF
#define WHITE           0xFFFFFFFF


/*
 * Interface functions header
 */

void initgraph(int *, int *, const char *);
int graphresult();
void setactivepage(int);
void putpixel(int, int, int);
void closegraph();


#endif	/* _GRAPHICS_H */