/* misc.c -- miscellaneous common functions
   Copyright (C) 1986, 1995, 1996 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <config.h>
#include "system.h"
#include "strxtra.h"
#include "misc.h"

int
tree8_count_levels (unsigned int cardinality)
{
  int levels = 1;
  cardinality--;
  while (cardinality >>= 3)
    ++levels;
  return levels;
}

int
gets_past_00 (char *tok, FILE *input_FILE)
{
  int got = 0;
  int c;
  do
    {
      do
	{
	  got++;
	  c = getc (input_FILE);
	  *tok++ = c;
	}
      while (c > 0);
      got++;
      c = getc (input_FILE);
      *tok++ = c;
    }
  while (c > 0);
  return got - 2;
}

int
skip_past_00 (FILE *input_FILE)
{
  int skipped = 0;
  do
    {
      do
	skipped++;
      while (getc (input_FILE) > 0);
      skipped++;
    }
  while (getc (input_FILE) > 0);
  return skipped;
}
