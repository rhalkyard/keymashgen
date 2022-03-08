/*
 * pw_rand.c --- generate completely random (and hard to remember)
 * 	passwords
 *
 * Copyright (C) 2001,2002 by Theodore Ts'o
 * 
 * This file may be distributed under the terms of the GNU Public
 * License.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pwgen.h"

const char *smash_semicolon_toprow = "qwertyuiop";
const char *smash_semicolon_homerow= "asdfghjkl;";
const char *smash_semicolon_bottomrow = "zxcvbnnm";

const int toprow_semicolon_weight = 5;
const int homerow_semicolon_weight = 100;
const int bottomrow_semicolon_weight = 5;

void pw_smash_semicolon(char *buf, int size, int pw_flags, char *remove)
{
	char		ch, *chars, *wchars;
	int		i, len;

	len = strlen(smash_semicolon_toprow) * toprow_semicolon_weight + strlen(smash_semicolon_homerow) * homerow_semicolon_weight + strlen(smash_semicolon_bottomrow) * bottomrow_semicolon_weight;
	chars = malloc(len+1);
	if (!chars) {
		fprintf(stderr, "Couldn't malloc pw_rand buffer.\n");
		exit(1);
	}
	wchars = chars;
	for (i = 0; i < toprow_semicolon_weight; i++) {
		strcpy(wchars, smash_semicolon_toprow);
		wchars += strlen(smash_semicolon_toprow);
	}
	for (i = 0; i < homerow_semicolon_weight; i++) {
		strcpy(wchars, smash_semicolon_homerow);
		wchars += strlen(smash_semicolon_homerow);
	}
	for (i = 0; i < bottomrow_semicolon_weight; i++) {
		strcpy(wchars, smash_semicolon_bottomrow);
		wchars += strlen(smash_semicolon_bottomrow);
	}
	len = strlen(chars);

	i = 0;
	while (i < size) {
		if (i == 0) {
			ch = smash_semicolon_homerow[pw_number(strlen(smash_semicolon_homerow))];
		} else {
			ch = chars[pw_number(len)];
		}
		buf[i++] = ch;
	}
	buf[size] = 0;
	free(chars);
	return;
}	
