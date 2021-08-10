/*
 * pw_rand.c --- generate keysmashes
 *
 * THIS MAKES BAD PASSWORDS AND YOU SHOULD FEEL BAD FOR USING IT
 * 
 * This file may be distributed under the terms of the GNU Public
 * License.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pwgen.h"

const char *smash_toprow = "qwertyuiop";
const char *smash_homerow= "asdfghjkl";
const char *smash_bottomrow = "zxcvbnnm";

const int toprow_weight = 5;
const int homerow_weight = 100;
const int bottomrow_weight = 1;

void pw_smash(char *buf, int size, int pw_flags, char *remove)
{
	char		ch, *chars, *wchars;
	int		i, len;

	len = strlen(smash_toprow) * toprow_weight + \
		strlen(smash_homerow) * homerow_weight + \
		strlen(smash_bottomrow) * bottomrow_weight;
	chars = malloc(len+1);
	if (!chars) {
		fprintf(stderr, "Couldn't malloc pw_smash buffer.\n");
		exit(1);
	}
	wchars = chars;
	for (i = 0; i < toprow_weight; i++) {
		strcpy(wchars, smash_toprow);
		wchars += strlen(smash_toprow);
	}
	for (i = 0; i < homerow_weight; i++) {
		strcpy(wchars, smash_homerow);
		wchars += strlen(smash_homerow);
	}
	for (i = 0; i < bottomrow_weight; i++) {
		strcpy(wchars, smash_bottomrow);
		wchars += strlen(smash_bottomrow);
	}
	len = strlen(chars);

	i = 0;
	while (i < size) {
		if (i == 0) {
			ch = smash_homerow[pw_number(strlen(smash_homerow))];
		} else {
			ch = chars[pw_number(len)];
		}
		buf[i++] = ch;
	}
	buf[size] = 0;
	free(chars);
	return;
}	
