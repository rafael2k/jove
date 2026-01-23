/**************************************************************************
 * This program is Copyright (C) 1986-2002 by Jonathan Payne.  JOVE is    *
 * provided by Jonathan and Jovehacks without charge and without          *
 * warranty.  You may copy, modify, and/or distribute JOVE, provided that *
 * this notice is included in all the source files and documentation.     *
 **************************************************************************/

/* keys.c is derived from keys.txt by setmaps */

/* Only edit keys.txt, not keys.c.
 *
 * keys.txt is processed as text by setmaps.  This means that what follows
 * is a very restricted subset of C.
 *
 * - Lines beginning with "#if", "#else", and "#endif" are understood
 *   to be the parts of conditional compilation.
 *   They will not be recognized if they are "spelled" differently
 *   (say, with whitespace).  Generally, there ought to be the same
 *   number of table entries in each branch of the if.
 *
 * - On a Mac, lines begining with "#MENU" are used to specify that
 *   the table is for a menu.
 *
 * - Lines begining with a tab followed by a " are treated as table entries.
 *
 * - Other lines are passed through, and are assumed to delimit tables.
 *   This means that they must not be within tables.
 */

#include "jove.h"
#include "commands.h"
#include "vars.h"

const struct cmd *cmdidx[IDXSZ] = {
	&commands[0], /* add-lisp-special */
	&commands[7], /* backward-character */
	&commands[23], /* c-mode */
	&commands[36], /* date */
	&commands[65], /* edit-word-abbrevs */
	&commands[76], /* fill-comment */
	&commands[91], /* gather-numeric-argument */
	&commands[96], /* handle-tab */
	&commands[97], /* i-search-forward */
	NULL,
	&commands[101], /* kill-next-word */
	&commands[109], /* left-margin-here */
	&commands[115], /* make-buffer-unmodified */
	&commands[117], /* name-kbd-macro */
	&commands[126], /* over-write-mode */
	&commands[127], /* page-next-window */
	&commands[146], /* query-replace-string */
	&commands[148], /* read-only-mode */
	&commands[156], /* save-file */
	&commands[193], /* teach-jove */
	&commands[197], /* unbound */
	&commands[198], /* version */
	&commands[201], /* window-find */
	NULL,
	&commands[208], /* yank */
	NULL,
};
const struct variable *varidx[IDXSZ] = {
	&variables[0], /* abort-char */
	&variables[4], /* bad-filename-extensions */
	&variables[5], /* c-argument-indentation */
	&variables[9], /* disable-biff */
	&variables[12], /* error-format-string */
	&variables[15], /* file-creation-mode */
	NULL,
	NULL,
	&variables[17], /* interrupt-character */
	&variables[18], /* jove-compiled-with */
	NULL,
	&variables[21], /* left-margin */
	&variables[23], /* mail-check-frequency */
	NULL,
	&variables[31], /* one-key-confirmation */
	&variables[32], /* paragraph-delimiter-pattern */
	NULL,
	&variables[34], /* right-margin */
	&variables[35], /* save-on-exit */
	&variables[47], /* tab-width */
	&variables[50], /* update-time-frequency */
	&variables[51], /* visible-bell */
	&variables[52], /* wrap-process-lines */
	NULL,
	NULL,
	NULL,
};
data_obj *MainKeys[NCHARS] = {
	(data_obj *) &commands[178],	/* ^@ set-mark */
	(data_obj *) &commands[16],	/* ^A beginning-of-line */
	(data_obj *) &commands[7],	/* ^B backward-character */
	(data_obj *) NULL,		/* ^C unbound */
	(data_obj *) &commands[43],	/* ^D delete-next-character */
	(data_obj *) &commands[68],	/* ^E end-of-line */
	(data_obj *) &commands[84],	/* ^F forward-character */
	(data_obj *) NULL,		/* ^G unbound */
	(data_obj *) &commands[45],	/* ^H delete-previous-character */
	(data_obj *) &commands[96],	/* ^I handle-tab */
	(data_obj *) &commands[120],	/* ^J newline-and-indent */
	(data_obj *) &commands[107],	/* ^K kill-to-end-of-line */
	(data_obj *) &commands[151],	/* ^L redraw-display */
	(data_obj *) &commands[118],	/* ^M newline */
	(data_obj *) &commands[122],	/* ^N next-line */
	(data_obj *) &commands[119],	/* ^O newline-and-backup */
	(data_obj *) &commands[135],	/* ^P previous-line */
	(data_obj *) &commands[147],	/* ^Q quoted-insert */
	(data_obj *) &commands[163],	/* ^R search-reverse */
	(data_obj *) &commands[161],	/* ^S search-forward */
	(data_obj *) &commands[195],	/* ^T transpose-characters */
	(data_obj *) &commands[91],	/* ^U gather-numeric-argument */
	(data_obj *) &commands[123],	/* ^V next-page */
	(data_obj *) &commands[103],	/* ^W kill-region */
	(data_obj *) NULL,		/* ^X unbound */
	(data_obj *) &commands[208],	/* ^Y yank */
	(data_obj *) &commands[160],	/* ^Z scroll-up */
	(data_obj *) NULL,		/* ESC unbound */
#ifdef MAC	/* peculiar cursor key codes */
	(data_obj *) &commands[7],	/* ^\ backward-character */
	(data_obj *) &commands[84],	/* ^] forward-character */
	(data_obj *) &commands[135],	/* ^^ previous-line */
	(data_obj *) &commands[122],	/* ^_ next-line */
#else
	(data_obj *) &commands[161],	/* ^\ search-forward */
	(data_obj *) &commands[82],	/* ^] find-tag-at-point */
	(data_obj *) &commands[147],	/* ^^ quoted-insert */
	(data_obj *) NULL,		/* ^_ unbound */
#endif
	(data_obj *) &commands[176],	/*   self-insert */
	(data_obj *) &commands[176],	/* ! self-insert */
	(data_obj *) &commands[176],	/* " self-insert */
	(data_obj *) &commands[176],	/* # self-insert */
	(data_obj *) &commands[176],	/* $ self-insert */
	(data_obj *) &commands[176],	/* % self-insert */
	(data_obj *) &commands[176],	/* & self-insert */
	(data_obj *) &commands[176],	/* ' self-insert */
	(data_obj *) &commands[176],	/* ( self-insert */
	(data_obj *) &commands[128],	/* ) paren-flash */
	(data_obj *) &commands[176],	/* * self-insert */
	(data_obj *) &commands[176],	/* + self-insert */
	(data_obj *) &commands[176],	/* , self-insert */
	(data_obj *) &commands[176],	/* - self-insert */
	(data_obj *) &commands[176],	/* . self-insert */
	(data_obj *) &commands[176],	/* / self-insert */
	(data_obj *) &commands[176],	/* 0 self-insert */
	(data_obj *) &commands[176],	/* 1 self-insert */
	(data_obj *) &commands[176],	/* 2 self-insert */
	(data_obj *) &commands[176],	/* 3 self-insert */
	(data_obj *) &commands[176],	/* 4 self-insert */
	(data_obj *) &commands[176],	/* 5 self-insert */
	(data_obj *) &commands[176],	/* 6 self-insert */
	(data_obj *) &commands[176],	/* 7 self-insert */
	(data_obj *) &commands[176],	/* 8 self-insert */
	(data_obj *) &commands[176],	/* 9 self-insert */
	(data_obj *) &commands[176],	/* : self-insert */
	(data_obj *) &commands[176],	/* ; self-insert */
	(data_obj *) &commands[176],	/* < self-insert */
	(data_obj *) &commands[176],	/* = self-insert */
	(data_obj *) &commands[176],	/* > self-insert */
	(data_obj *) &commands[176],	/* ? self-insert */
	(data_obj *) &commands[176],	/* @ self-insert */
	(data_obj *) &commands[176],	/* A self-insert */
	(data_obj *) &commands[176],	/* B self-insert */
	(data_obj *) &commands[176],	/* C self-insert */
	(data_obj *) &commands[176],	/* D self-insert */
	(data_obj *) &commands[176],	/* E self-insert */
	(data_obj *) &commands[176],	/* F self-insert */
	(data_obj *) &commands[176],	/* G self-insert */
	(data_obj *) &commands[176],	/* H self-insert */
	(data_obj *) &commands[176],	/* I self-insert */
	(data_obj *) &commands[176],	/* J self-insert */
	(data_obj *) &commands[176],	/* K self-insert */
	(data_obj *) &commands[176],	/* L self-insert */
	(data_obj *) &commands[176],	/* M self-insert */
	(data_obj *) &commands[176],	/* N self-insert */
	(data_obj *) &commands[176],	/* O self-insert */
	(data_obj *) &commands[176],	/* P self-insert */
	(data_obj *) &commands[176],	/* Q self-insert */
	(data_obj *) &commands[176],	/* R self-insert */
	(data_obj *) &commands[176],	/* S self-insert */
	(data_obj *) &commands[176],	/* T self-insert */
	(data_obj *) &commands[176],	/* U self-insert */
	(data_obj *) &commands[176],	/* V self-insert */
	(data_obj *) &commands[176],	/* W self-insert */
	(data_obj *) &commands[176],	/* X self-insert */
	(data_obj *) &commands[176],	/* Y self-insert */
	(data_obj *) &commands[176],	/* Z self-insert */
	(data_obj *) &commands[176],	/* [ self-insert */
	(data_obj *) &commands[176],	/* \ self-insert */
	(data_obj *) &commands[128],	/* ] paren-flash */
	(data_obj *) &commands[176],	/* ^ self-insert */
	(data_obj *) &commands[176],	/* _ self-insert */
	(data_obj *) &commands[176],	/* ` self-insert */
	(data_obj *) &commands[176],	/* a self-insert */
	(data_obj *) &commands[176],	/* b self-insert */
	(data_obj *) &commands[176],	/* c self-insert */
	(data_obj *) &commands[176],	/* d self-insert */
	(data_obj *) &commands[176],	/* e self-insert */
	(data_obj *) &commands[176],	/* f self-insert */
	(data_obj *) &commands[176],	/* g self-insert */
	(data_obj *) &commands[176],	/* h self-insert */
	(data_obj *) &commands[176],	/* i self-insert */
	(data_obj *) &commands[176],	/* j self-insert */
	(data_obj *) &commands[176],	/* k self-insert */
	(data_obj *) &commands[176],	/* l self-insert */
	(data_obj *) &commands[176],	/* m self-insert */
	(data_obj *) &commands[176],	/* n self-insert */
	(data_obj *) &commands[176],	/* o self-insert */
	(data_obj *) &commands[176],	/* p self-insert */
	(data_obj *) &commands[176],	/* q self-insert */
	(data_obj *) &commands[176],	/* r self-insert */
	(data_obj *) &commands[176],	/* s self-insert */
	(data_obj *) &commands[176],	/* t self-insert */
	(data_obj *) &commands[176],	/* u self-insert */
	(data_obj *) &commands[176],	/* v self-insert */
	(data_obj *) &commands[176],	/* w self-insert */
	(data_obj *) &commands[176],	/* x self-insert */
	(data_obj *) &commands[176],	/* y self-insert */
	(data_obj *) &commands[176],	/* z self-insert */
	(data_obj *) &commands[176],	/* { self-insert */
	(data_obj *) &commands[176],	/* | self-insert */
	(data_obj *) &commands[128],	/* } paren-flash */
	(data_obj *) &commands[176],	/* ~ self-insert */
	(data_obj *) &commands[45],	/* ^? delete-previous-character */
#if NCHARS != 128
	(data_obj *) &commands[176],	/* M-^@ self-insert */
	(data_obj *) &commands[176],	/* M-^A self-insert */
	(data_obj *) &commands[176],	/* M-^B self-insert */
	(data_obj *) &commands[176],	/* M-^C self-insert */
	(data_obj *) &commands[176],	/* M-^D self-insert */
	(data_obj *) &commands[176],	/* M-^E self-insert */
	(data_obj *) &commands[176],	/* M-^F self-insert */
	(data_obj *) &commands[176],	/* M-^G self-insert */
	(data_obj *) &commands[176],	/* M-^H self-insert */
	(data_obj *) &commands[176],	/* M-^I self-insert */
	(data_obj *) &commands[176],	/* M-^J self-insert */
	(data_obj *) &commands[176],	/* M-^K self-insert */
	(data_obj *) &commands[176],	/* M-^L self-insert */
	(data_obj *) &commands[176],	/* M-^M self-insert */
	(data_obj *) &commands[176],	/* M-^N self-insert */
	(data_obj *) &commands[176],	/* M-^O self-insert */
	(data_obj *) &commands[176],	/* M-^P self-insert */
	(data_obj *) &commands[176],	/* M-^Q self-insert */
	(data_obj *) &commands[176],	/* M-^R self-insert */
	(data_obj *) &commands[176],	/* M-^S self-insert */
	(data_obj *) &commands[176],	/* M-^T self-insert */
	(data_obj *) &commands[176],	/* M-^U self-insert */
	(data_obj *) &commands[176],	/* M-^V self-insert */
	(data_obj *) &commands[176],	/* M-^W self-insert */
	(data_obj *) &commands[176],	/* M-^X self-insert */
	(data_obj *) &commands[176],	/* M-^Y self-insert */
	(data_obj *) &commands[176],	/* M-^Z self-insert */
	(data_obj *) &commands[176],	/* M-ESC self-insert */
	(data_obj *) &commands[176],	/* M-^\ self-insert */
	(data_obj *) &commands[176],	/* M-^] self-insert */
	(data_obj *) &commands[176],	/* M-^^ self-insert */
	(data_obj *) &commands[176],	/* M-^_ self-insert */
	(data_obj *) &commands[176],	/* M-  self-insert */
	(data_obj *) &commands[176],	/* M-! self-insert */
	(data_obj *) &commands[176],	/* M-" self-insert */
	(data_obj *) &commands[176],	/* M-# self-insert */
	(data_obj *) &commands[176],	/* M-$ self-insert */
	(data_obj *) &commands[176],	/* M-% self-insert */
	(data_obj *) &commands[176],	/* M-& self-insert */
	(data_obj *) &commands[176],	/* M-' self-insert */
	(data_obj *) &commands[176],	/* M-( self-insert */
	(data_obj *) &commands[176],	/* M-) self-insert */
	(data_obj *) &commands[176],	/* M-* self-insert */
	(data_obj *) &commands[176],	/* M-+ self-insert */
	(data_obj *) &commands[176],	/* M-, self-insert */
	(data_obj *) &commands[176],	/* M-- self-insert */
	(data_obj *) &commands[176],	/* M-. self-insert */
	(data_obj *) &commands[176],	/* M-/ self-insert */
	(data_obj *) &commands[176],	/* M-0 self-insert */
	(data_obj *) &commands[176],	/* M-1 self-insert */
	(data_obj *) &commands[176],	/* M-2 self-insert */
	(data_obj *) &commands[176],	/* M-3 self-insert */
	(data_obj *) &commands[176],	/* M-4 self-insert */
	(data_obj *) &commands[176],	/* M-5 self-insert */
	(data_obj *) &commands[176],	/* M-6 self-insert */
	(data_obj *) &commands[176],	/* M-7 self-insert */
	(data_obj *) &commands[176],	/* M-8 self-insert */
	(data_obj *) &commands[176],	/* M-9 self-insert */
	(data_obj *) &commands[176],	/* M-: self-insert */
	(data_obj *) &commands[176],	/* M-; self-insert */
	(data_obj *) &commands[176],	/* M-< self-insert */
	(data_obj *) &commands[176],	/* M-= self-insert */
	(data_obj *) &commands[176],	/* M-> self-insert */
	(data_obj *) &commands[176],	/* M-? self-insert */
	(data_obj *) &commands[176],	/* M-@ self-insert */
	(data_obj *) &commands[176],	/* M-A self-insert */
	(data_obj *) &commands[176],	/* M-B self-insert */
	(data_obj *) &commands[176],	/* M-C self-insert */
	(data_obj *) &commands[176],	/* M-D self-insert */
	(data_obj *) &commands[176],	/* M-E self-insert */
	(data_obj *) &commands[176],	/* M-F self-insert */
	(data_obj *) &commands[176],	/* M-G self-insert */
	(data_obj *) &commands[176],	/* M-H self-insert */
	(data_obj *) &commands[176],	/* M-I self-insert */
	(data_obj *) &commands[176],	/* M-J self-insert */
	(data_obj *) &commands[176],	/* M-K self-insert */
	(data_obj *) &commands[176],	/* M-L self-insert */
	(data_obj *) &commands[176],	/* M-M self-insert */
	(data_obj *) &commands[176],	/* M-N self-insert */
	(data_obj *) &commands[176],	/* M-O self-insert */
	(data_obj *) &commands[176],	/* M-P self-insert */
	(data_obj *) &commands[176],	/* M-Q self-insert */
	(data_obj *) &commands[176],	/* M-R self-insert */
	(data_obj *) &commands[176],	/* M-S self-insert */
	(data_obj *) &commands[176],	/* M-T self-insert */
	(data_obj *) &commands[176],	/* M-U self-insert */
	(data_obj *) &commands[176],	/* M-V self-insert */
	(data_obj *) &commands[176],	/* M-W self-insert */
	(data_obj *) &commands[176],	/* M-X self-insert */
	(data_obj *) &commands[176],	/* M-Y self-insert */
	(data_obj *) &commands[176],	/* M-Z self-insert */
	(data_obj *) &commands[176],	/* M-[ self-insert */
	(data_obj *) &commands[176],	/* M-\ self-insert */
	(data_obj *) &commands[176],	/* M-] self-insert */
	(data_obj *) &commands[176],	/* M-^ self-insert */
	(data_obj *) &commands[176],	/* M-_ self-insert */
	(data_obj *) &commands[176],	/* M-` self-insert */
	(data_obj *) &commands[176],	/* M-a self-insert */
	(data_obj *) &commands[176],	/* M-b self-insert */
	(data_obj *) &commands[176],	/* M-c self-insert */
	(data_obj *) &commands[176],	/* M-d self-insert */
	(data_obj *) &commands[176],	/* M-e self-insert */
	(data_obj *) &commands[176],	/* M-f self-insert */
	(data_obj *) &commands[176],	/* M-g self-insert */
	(data_obj *) &commands[176],	/* M-h self-insert */
	(data_obj *) &commands[176],	/* M-i self-insert */
	(data_obj *) &commands[176],	/* M-j self-insert */
	(data_obj *) &commands[176],	/* M-k self-insert */
	(data_obj *) &commands[176],	/* M-l self-insert */
	(data_obj *) &commands[176],	/* M-m self-insert */
	(data_obj *) &commands[176],	/* M-n self-insert */
	(data_obj *) &commands[176],	/* M-o self-insert */
	(data_obj *) &commands[176],	/* M-p self-insert */
	(data_obj *) &commands[176],	/* M-q self-insert */
	(data_obj *) &commands[176],	/* M-r self-insert */
	(data_obj *) &commands[176],	/* M-s self-insert */
	(data_obj *) &commands[176],	/* M-t self-insert */
	(data_obj *) &commands[176],	/* M-u self-insert */
	(data_obj *) &commands[176],	/* M-v self-insert */
	(data_obj *) &commands[176],	/* M-w self-insert */
	(data_obj *) &commands[176],	/* M-x self-insert */
	(data_obj *) &commands[176],	/* M-y self-insert */
	(data_obj *) &commands[176],	/* M-z self-insert */
	(data_obj *) &commands[176],	/* M-{ self-insert */
	(data_obj *) &commands[176],	/* M-| self-insert */
	(data_obj *) &commands[176],	/* M-} self-insert */
	(data_obj *) &commands[176],	/* M-~ self-insert */
#ifdef PCNONASCII
	(data_obj *) NULL,		/* M-^? unbound */
#else
	(data_obj *) &commands[176],	/* M-^? self-insert */
#endif
#endif /* NCHARS != 128 */
};

data_obj *EscKeys[NCHARS] = {
	(data_obj *) &commands[178],	/* ^@ set-mark */
	(data_obj *) NULL,		/* ^A unbound */
	(data_obj *) &commands[10],	/* ^B backward-s-expression */
	(data_obj *) NULL,		/* ^C unbound */
	(data_obj *) &commands[64],	/* ^D down-list */
	(data_obj *) NULL,		/* ^E unbound */
	(data_obj *) &commands[87],	/* ^F forward-s-expression */
	(data_obj *) NULL,		/* ^G unbound */
	(data_obj *) NULL,		/* ^H unbound */
	(data_obj *) NULL,		/* ^I unbound */
	(data_obj *) NULL,		/* ^J unbound */
	(data_obj *) &commands[104],	/* ^K kill-s-expression */
	(data_obj *) &commands[32],	/* ^L clear-and-redraw */
	(data_obj *) NULL,		/* ^M unbound */
	(data_obj *) &commands[85],	/* ^N forward-list */
	(data_obj *) NULL,		/* ^O unbound */
	(data_obj *) &commands[8],	/* ^P backward-list */
	(data_obj *) NULL,		/* ^Q unbound */
	(data_obj *) NULL,		/* ^R unbound */
	(data_obj *) NULL,		/* ^S unbound */
	(data_obj *) NULL,		/* ^T unbound */
	(data_obj *) &commands[12],	/* ^U backward-up-list */
	(data_obj *) &commands[127],	/* ^V page-next-window */
	(data_obj *) NULL,		/* ^W unbound */
	(data_obj *) NULL,		/* ^X unbound */
	(data_obj *) NULL,		/* ^Y unbound */
	(data_obj *) NULL,		/* ^Z unbound */
	(data_obj *) NULL,		/* ESC unbound */
	(data_obj *) NULL,		/* ^\ unbound */
	(data_obj *) NULL,		/* ^] unbound */
	(data_obj *) NULL,		/* ^^ unbound */
	(data_obj *) NULL,		/* ^_ unbound */
	(data_obj *) NULL,		/*   unbound */
	(data_obj *) NULL,		/* ! unbound */
	(data_obj *) NULL,		/* " unbound */
	(data_obj *) NULL,		/* # unbound */
	(data_obj *) NULL,		/* $ unbound */
	(data_obj *) NULL,		/* % unbound */
	(data_obj *) NULL,		/* & unbound */
	(data_obj *) NULL,		/* ' unbound */
	(data_obj *) NULL,		/* ( unbound */
	(data_obj *) NULL,		/* ) unbound */
	(data_obj *) NULL,		/* * unbound */
	(data_obj *) NULL,		/* + unbound */
	(data_obj *) &commands[17],	/* , beginning-of-window */
	(data_obj *) &commands[62],	/* - digit-minus */
	(data_obj *) &commands[69],	/* . end-of-window */
	(data_obj *) NULL,		/* / unbound */
	(data_obj *) &commands[51],	/* 0 digit */
	(data_obj *) &commands[51],	/* 1 digit */
	(data_obj *) &commands[51],	/* 2 digit */
	(data_obj *) &commands[51],	/* 3 digit */
	(data_obj *) &commands[51],	/* 4 digit */
	(data_obj *) &commands[51],	/* 5 digit */
	(data_obj *) &commands[51],	/* 6 digit */
	(data_obj *) &commands[51],	/* 7 digit */
	(data_obj *) &commands[51],	/* 8 digit */
	(data_obj *) &commands[51],	/* 9 digit */
	(data_obj *) NULL,		/* : unbound */
	(data_obj *) NULL,		/* ; unbound */
	(data_obj *) &commands[15],	/* < beginning-of-file */
	(data_obj *) NULL,		/* = unbound */
	(data_obj *) &commands[67],	/* > end-of-file */
	(data_obj *) &commands[48],	/* ? describe-command */
	(data_obj *) NULL,		/* @ unbound */
	(data_obj *) &commands[11],	/* A backward-sentence */
	(data_obj *) &commands[13],	/* B backward-word */
	(data_obj *) &commands[27],	/* C case-word-capitalize */
	(data_obj *) &commands[101],	/* D kill-next-word */
	(data_obj *) &commands[88],	/* E forward-sentence */
	(data_obj *) &commands[89],	/* F forward-word */
	(data_obj *) &commands[92],	/* G goto-line */
	(data_obj *) NULL,		/* H unbound */
	(data_obj *) &commands[116],	/* I make-macro-interactive */
	(data_obj *) &commands[77],	/* J fill-paragraph */
	(data_obj *) &commands[108],	/* K kill-to-end-of-sentence */
	(data_obj *) &commands[28],	/* L case-word-lower */
	(data_obj *) &commands[83],	/* M first-non-blank */
	(data_obj *) NULL,		/* N unbound */
	(data_obj *) NULL,		/* O unbound */
	(data_obj *) NULL,		/* P unbound */
	(data_obj *) &commands[146],	/* Q query-replace-string */
	(data_obj *) &commands[154],	/* R replace-string */
#ifdef JOB_CONTROL
	(data_obj *) &commands[131],	/* S pause-jove */
#else
	(data_obj *) NULL,		/* S unbound */
#endif
	(data_obj *) NULL,		/* T unbound */
	(data_obj *) &commands[29],	/* U case-word-upper */
	(data_obj *) &commands[136],	/* V previous-page */
	(data_obj *) &commands[34],	/* W copy-region */
	(data_obj *) &commands[74],	/* X execute-named-command */
	(data_obj *) &commands[209],	/* Y yank-pop */
	(data_obj *) &commands[157],	/* Z scroll-down */
	(data_obj *) &commands[9],	/* [ backward-paragraph */
	(data_obj *) &commands[46],	/* \ delete-white-space */
	(data_obj *) &commands[86],	/* ] forward-paragraph */
	(data_obj *) NULL,		/* ^ unbound */
	(data_obj *) NULL,		/* _ unbound */
	(data_obj *) NULL,		/* ` unbound */
	(data_obj *) &commands[11],	/* a backward-sentence */
	(data_obj *) &commands[13],	/* b backward-word */
	(data_obj *) &commands[27],	/* c case-word-capitalize */
	(data_obj *) &commands[101],	/* d kill-next-word */
	(data_obj *) &commands[88],	/* e forward-sentence */
	(data_obj *) &commands[89],	/* f forward-word */
	(data_obj *) &commands[92],	/* g goto-line */
	(data_obj *) NULL,		/* h unbound */
	(data_obj *) &commands[116],	/* i make-macro-interactive */
	(data_obj *) &commands[77],	/* j fill-paragraph */
	(data_obj *) &commands[108],	/* k kill-to-end-of-sentence */
	(data_obj *) &commands[28],	/* l case-word-lower */
	(data_obj *) &commands[83],	/* m first-non-blank */
	(data_obj *) NULL,		/* n unbound */
	(data_obj *) NULL,		/* o unbound */
	(data_obj *) NULL,		/* p unbound */
	(data_obj *) &commands[146],	/* q query-replace-string */
	(data_obj *) &commands[154],	/* r replace-string */
#ifdef JOB_CONTROL
	(data_obj *) &commands[131],	/* s pause-jove */
#else
	(data_obj *) NULL,		/* s unbound */
#endif
	(data_obj *) NULL,		/* t unbound */
	(data_obj *) &commands[29],	/* u case-word-upper */
	(data_obj *) &commands[136],	/* v previous-page */
	(data_obj *) &commands[34],	/* w copy-region */
	(data_obj *) &commands[74],	/* x execute-named-command */
	(data_obj *) &commands[209],	/* y yank-pop */
	(data_obj *) &commands[157],	/* z scroll-down */
	(data_obj *) NULL,		/* { unbound */
	(data_obj *) NULL,		/* | unbound */
	(data_obj *) NULL,		/* } unbound */
	(data_obj *) &commands[115],	/* ~ make-buffer-unmodified */
	(data_obj *) &commands[102],	/* ^? kill-previous-word */
#if NCHARS != 128
	(data_obj *) NULL,		/* M-^@ unbound */
	(data_obj *) NULL,		/* M-^A unbound */
	(data_obj *) NULL,		/* M-^B unbound */
	(data_obj *) NULL,		/* M-^C unbound */
	(data_obj *) NULL,		/* M-^D unbound */
	(data_obj *) NULL,		/* M-^E unbound */
	(data_obj *) NULL,		/* M-^F unbound */
	(data_obj *) NULL,		/* M-^G unbound */
	(data_obj *) NULL,		/* M-^H unbound */
	(data_obj *) NULL,		/* M-^I unbound */
	(data_obj *) NULL,		/* M-^J unbound */
	(data_obj *) NULL,		/* M-^K unbound */
	(data_obj *) NULL,		/* M-^L unbound */
	(data_obj *) NULL,		/* M-^M unbound */
	(data_obj *) NULL,		/* M-^N unbound */
	(data_obj *) NULL,		/* M-^O unbound */
	(data_obj *) NULL,		/* M-^P unbound */
	(data_obj *) NULL,		/* M-^Q unbound */
	(data_obj *) NULL,		/* M-^R unbound */
	(data_obj *) NULL,		/* M-^S unbound */
	(data_obj *) NULL,		/* M-^T unbound */
	(data_obj *) NULL,		/* M-^U unbound */
	(data_obj *) NULL,		/* M-^V unbound */
	(data_obj *) NULL,		/* M-^W unbound */
	(data_obj *) NULL,		/* M-^X unbound */
	(data_obj *) NULL,		/* M-^Y unbound */
	(data_obj *) NULL,		/* M-^Z unbound */
	(data_obj *) NULL,		/* M-ESC unbound */
	(data_obj *) NULL,		/* M-^\ unbound */
	(data_obj *) NULL,		/* M-^] unbound */
	(data_obj *) NULL,		/* M-^^ unbound */
	(data_obj *) NULL,		/* M-^_ unbound */
	(data_obj *) NULL,		/* M-  unbound */
	(data_obj *) NULL,		/* M-! unbound */
	(data_obj *) NULL,		/* M-" unbound */
	(data_obj *) NULL,		/* M-# unbound */
	(data_obj *) NULL,		/* M-$ unbound */
	(data_obj *) NULL,		/* M-% unbound */
	(data_obj *) NULL,		/* M-& unbound */
	(data_obj *) NULL,		/* M-' unbound */
	(data_obj *) NULL,		/* M-( unbound */
	(data_obj *) NULL,		/* M-) unbound */
	(data_obj *) NULL,		/* M-* unbound */
	(data_obj *) NULL,		/* M-+ unbound */
	(data_obj *) NULL,		/* M-, unbound */
	(data_obj *) NULL,		/* M-- unbound */
	(data_obj *) NULL,		/* M-. unbound */
	(data_obj *) NULL,		/* M-/ unbound */
	(data_obj *) NULL,		/* M-0 unbound */
	(data_obj *) NULL,		/* M-1 unbound */
	(data_obj *) NULL,		/* M-2 unbound */
	(data_obj *) NULL,		/* M-3 unbound */
	(data_obj *) NULL,		/* M-4 unbound */
	(data_obj *) NULL,		/* M-5 unbound */
	(data_obj *) NULL,		/* M-6 unbound */
	(data_obj *) NULL,		/* M-7 unbound */
	(data_obj *) NULL,		/* M-8 unbound */
	(data_obj *) NULL,		/* M-9 unbound */
	(data_obj *) NULL,		/* M-: unbound */
	(data_obj *) NULL,		/* M-; unbound */
	(data_obj *) NULL,		/* M-< unbound */
	(data_obj *) NULL,		/* M-= unbound */
	(data_obj *) NULL,		/* M-> unbound */
	(data_obj *) NULL,		/* M-? unbound */
	(data_obj *) NULL,		/* M-@ unbound */
	(data_obj *) NULL,		/* M-A unbound */
	(data_obj *) NULL,		/* M-B unbound */
	(data_obj *) NULL,		/* M-C unbound */
	(data_obj *) NULL,		/* M-D unbound */
	(data_obj *) NULL,		/* M-E unbound */
	(data_obj *) NULL,		/* M-F unbound */
	(data_obj *) NULL,		/* M-G unbound */
	(data_obj *) NULL,		/* M-H unbound */
	(data_obj *) NULL,		/* M-I unbound */
	(data_obj *) NULL,		/* M-J unbound */
	(data_obj *) NULL,		/* M-K unbound */
	(data_obj *) NULL,		/* M-L unbound */
	(data_obj *) NULL,		/* M-M unbound */
	(data_obj *) NULL,		/* M-N unbound */
	(data_obj *) NULL,		/* M-O unbound */
	(data_obj *) NULL,		/* M-P unbound */
	(data_obj *) NULL,		/* M-Q unbound */
	(data_obj *) NULL,		/* M-R unbound */
	(data_obj *) NULL,		/* M-S unbound */
	(data_obj *) NULL,		/* M-T unbound */
	(data_obj *) NULL,		/* M-U unbound */
	(data_obj *) NULL,		/* M-V unbound */
	(data_obj *) NULL,		/* M-W unbound */
	(data_obj *) NULL,		/* M-X unbound */
	(data_obj *) NULL,		/* M-Y unbound */
	(data_obj *) NULL,		/* M-Z unbound */
	(data_obj *) NULL,		/* M-[ unbound */
	(data_obj *) NULL,		/* M-\ unbound */
	(data_obj *) NULL,		/* M-] unbound */
	(data_obj *) NULL,		/* M-^ unbound */
	(data_obj *) NULL,		/* M-_ unbound */
	(data_obj *) NULL,		/* M-` unbound */
	(data_obj *) NULL,		/* M-a unbound */
	(data_obj *) NULL,		/* M-b unbound */
	(data_obj *) NULL,		/* M-c unbound */
	(data_obj *) NULL,		/* M-d unbound */
	(data_obj *) NULL,		/* M-e unbound */
	(data_obj *) NULL,		/* M-f unbound */
	(data_obj *) NULL,		/* M-g unbound */
	(data_obj *) NULL,		/* M-h unbound */
	(data_obj *) NULL,		/* M-i unbound */
	(data_obj *) NULL,		/* M-j unbound */
	(data_obj *) NULL,		/* M-k unbound */
	(data_obj *) NULL,		/* M-l unbound */
	(data_obj *) NULL,		/* M-m unbound */
	(data_obj *) NULL,		/* M-n unbound */
	(data_obj *) NULL,		/* M-o unbound */
	(data_obj *) NULL,		/* M-p unbound */
	(data_obj *) NULL,		/* M-q unbound */
	(data_obj *) NULL,		/* M-r unbound */
	(data_obj *) NULL,		/* M-s unbound */
	(data_obj *) NULL,		/* M-t unbound */
	(data_obj *) NULL,		/* M-u unbound */
	(data_obj *) NULL,		/* M-v unbound */
	(data_obj *) NULL,		/* M-w unbound */
	(data_obj *) NULL,		/* M-x unbound */
	(data_obj *) NULL,		/* M-y unbound */
	(data_obj *) NULL,		/* M-z unbound */
	(data_obj *) NULL,		/* M-{ unbound */
	(data_obj *) NULL,		/* M-| unbound */
	(data_obj *) NULL,		/* M-} unbound */
	(data_obj *) NULL,		/* M-~ unbound */
	(data_obj *) NULL,		/* M-^? unbound */
#endif /* NCHARS != 128 */
};

data_obj	*CtlxKeys[NCHARS] = {
	(data_obj *) NULL,		/* ^@ unbound */
	(data_obj *) NULL,		/* ^A unbound */
	(data_obj *) &commands[111],	/* ^B list-buffers */
	(data_obj *) &commands[75],	/* ^C exit-jove */
	(data_obj *) NULL,		/* ^D unbound */
#ifdef SUBSHELL
	(data_obj *) &commands[33],	/* ^E compile-it */
#else
	(data_obj *) NULL,		/* ^E unbound */
#endif
	(data_obj *) &commands[80],	/* ^F find-file */
	(data_obj *) NULL,		/* ^G unbound */
	(data_obj *) NULL,		/* ^H unbound */
	(data_obj *) &commands[99],	/* ^I insert-file */
	(data_obj *) NULL,		/* ^J unbound */
	(data_obj *) NULL,		/* ^K unbound */
	(data_obj *) NULL,		/* ^L unbound */
	(data_obj *) &commands[205],	/* ^M write-modified-files */
	(data_obj *) &commands[121],	/* ^N next-error */
	(data_obj *) &commands[40],	/* ^O delete-blank-lines */
	(data_obj *) &commands[134],	/* ^P previous-error */
	(data_obj *) NULL,		/* ^Q unbound */
	(data_obj *) &commands[200],	/* ^R visit-file */
	(data_obj *) &commands[156],	/* ^S save-file */
	(data_obj *) &commands[196],	/* ^T transpose-lines */
	(data_obj *) NULL,		/* ^U unbound */
	(data_obj *) &commands[200],	/* ^V visit-file */
	(data_obj *) &commands[203],	/* ^W write-file */
	(data_obj *) &commands[71],	/* ^X exchange-point-and-mark */
	(data_obj *) NULL,		/* ^Y unbound */
	(data_obj *) NULL,		/* ^Z unbound */
	(data_obj *) NULL,		/* ESC unbound */
	(data_obj *) &commands[156],	/* ^\ save-file */
	(data_obj *) NULL,		/* ^] unbound */
	(data_obj *) NULL,		/* ^^ unbound */
	(data_obj *) NULL,		/* ^_ unbound */
	(data_obj *) NULL,		/*   unbound */
#ifdef SUBSHELL
	(data_obj *) &commands[179],	/* ! shell-command */
#else
	(data_obj *) NULL,		/* ! unbound */
#endif
	(data_obj *) NULL,		/* " unbound */
	(data_obj *) NULL,		/* # unbound */
	(data_obj *) NULL,		/* $ unbound */
	(data_obj *) NULL,		/* % unbound */
	(data_obj *) NULL,		/* & unbound */
	(data_obj *) NULL,		/* ' unbound */
	(data_obj *) &commands[14],	/* ( begin-kbd-macro */
	(data_obj *) &commands[66],	/* ) end-kbd-macro */
	(data_obj *) NULL,		/* * unbound */
	(data_obj *) NULL,		/* + unbound */
	(data_obj *) NULL,		/* , unbound */
	(data_obj *) NULL,		/* - unbound */
	(data_obj *) NULL,		/* . unbound */
	(data_obj *) NULL,		/* / unbound */
	(data_obj *) NULL,		/* 0 unbound */
	(data_obj *) &commands[44],	/* 1 delete-other-windows */
	(data_obj *) &commands[189],	/* 2 split-current-window */
	(data_obj *) NULL,		/* 3 unbound */
	(data_obj *) &commands[201],	/* 4 window-find */
	(data_obj *) NULL,		/* 5 unbound */
	(data_obj *) NULL,		/* 6 unbound */
	(data_obj *) NULL,		/* 7 unbound */
	(data_obj *) NULL,		/* 8 unbound */
	(data_obj *) NULL,		/* 9 unbound */
	(data_obj *) NULL,		/* : unbound */
	(data_obj *) NULL,		/* ; unbound */
	(data_obj *) NULL,		/* < unbound */
	(data_obj *) NULL,		/* = unbound */
	(data_obj *) NULL,		/* > unbound */
	(data_obj *) &commands[49],	/* ? describe-key */
	(data_obj *) NULL,		/* @ unbound */
	(data_obj *) NULL,		/* A unbound */
	(data_obj *) &commands[165],	/* B select-buffer */
	(data_obj *) NULL,		/* C unbound */
	(data_obj *) &commands[42],	/* D delete-current-window */
	(data_obj *) &commands[72],	/* E execute-kbd-macro */
	(data_obj *) NULL,		/* F unbound */
	(data_obj *) NULL,		/* G unbound */
	(data_obj *) NULL,		/* H unbound */
	(data_obj *) NULL,		/* I unbound */
	(data_obj *) NULL,		/* J unbound */
	(data_obj *) &commands[41],	/* K delete-buffer */
	(data_obj *) NULL,		/* L unbound */
	(data_obj *) NULL,		/* M unbound */
	(data_obj *) &commands[124],	/* N next-window */
	(data_obj *) &commands[137],	/* O previous-window */
	(data_obj *) &commands[137],	/* P previous-window */
	(data_obj *) NULL,		/* Q unbound */
	(data_obj *) NULL,		/* R unbound */
	(data_obj *) &commands[156],	/* S save-file */
	(data_obj *) &commands[81],	/* T find-tag */
	(data_obj *) NULL,		/* U unbound */
	(data_obj *) NULL,		/* V unbound */
	(data_obj *) NULL,		/* W unbound */
	(data_obj *) NULL,		/* X unbound */
	(data_obj *) NULL,		/* Y unbound */
	(data_obj *) NULL,		/* Z unbound */
	(data_obj *) NULL,		/* [ unbound */
	(data_obj *) NULL,		/* \ unbound */
	(data_obj *) NULL,		/* ] unbound */
	(data_obj *) &commands[95],	/* ^ grow-window */
	(data_obj *) NULL,		/* _ unbound */
	(data_obj *) NULL,		/* ` unbound */
	(data_obj *) NULL,		/* a unbound */
	(data_obj *) &commands[165],	/* b select-buffer */
	(data_obj *) NULL,		/* c unbound */
	(data_obj *) &commands[42],	/* d delete-current-window */
	(data_obj *) &commands[72],	/* e execute-kbd-macro */
	(data_obj *) NULL,		/* f unbound */
	(data_obj *) NULL,		/* g unbound */
	(data_obj *) NULL,		/* h unbound */
	(data_obj *) NULL,		/* i unbound */
	(data_obj *) NULL,		/* j unbound */
	(data_obj *) &commands[41],	/* k delete-buffer */
	(data_obj *) NULL,		/* l unbound */
	(data_obj *) NULL,		/* m unbound */
	(data_obj *) &commands[124],	/* n next-window */
	(data_obj *) &commands[137],	/* o previous-window */
	(data_obj *) &commands[137],	/* p previous-window */
	(data_obj *) NULL,		/* q unbound */
	(data_obj *) NULL,		/* r unbound */
	(data_obj *) &commands[156],	/* s save-file */
	(data_obj *) &commands[81],	/* t find-tag */
	(data_obj *) NULL,		/* u unbound */
	(data_obj *) NULL,		/* v unbound */
	(data_obj *) NULL,		/* w unbound */
	(data_obj *) NULL,		/* x unbound */
	(data_obj *) NULL,		/* y unbound */
	(data_obj *) NULL,		/* z unbound */
	(data_obj *) NULL,		/* { unbound */
	(data_obj *) NULL,		/* | unbound */
	(data_obj *) NULL,		/* } unbound */
	(data_obj *) NULL,		/* ~ unbound */
	(data_obj *) &commands[106],	/* ^? kill-to-beginning-of-sentence */
#if NCHARS != 128
	(data_obj *) NULL,		/* M-^@ unbound */
	(data_obj *) NULL,		/* M-^A unbound */
	(data_obj *) NULL,		/* M-^B unbound */
	(data_obj *) NULL,		/* M-^C unbound */
	(data_obj *) NULL,		/* M-^D unbound */
	(data_obj *) NULL,		/* M-^E unbound */
	(data_obj *) NULL,		/* M-^F unbound */
	(data_obj *) NULL,		/* M-^G unbound */
	(data_obj *) NULL,		/* M-^H unbound */
	(data_obj *) NULL,		/* M-^I unbound */
	(data_obj *) NULL,		/* M-^J unbound */
	(data_obj *) NULL,		/* M-^K unbound */
	(data_obj *) NULL,		/* M-^L unbound */
	(data_obj *) NULL,		/* M-^M unbound */
	(data_obj *) NULL,		/* M-^N unbound */
	(data_obj *) NULL,		/* M-^O unbound */
	(data_obj *) NULL,		/* M-^P unbound */
	(data_obj *) NULL,		/* M-^Q unbound */
	(data_obj *) NULL,		/* M-^R unbound */
	(data_obj *) NULL,		/* M-^S unbound */
	(data_obj *) NULL,		/* M-^T unbound */
	(data_obj *) NULL,		/* M-^U unbound */
	(data_obj *) NULL,		/* M-^V unbound */
	(data_obj *) NULL,		/* M-^W unbound */
	(data_obj *) NULL,		/* M-^X unbound */
	(data_obj *) NULL,		/* M-^Y unbound */
	(data_obj *) NULL,		/* M-^Z unbound */
	(data_obj *) NULL,		/* M-ESC unbound */
	(data_obj *) NULL,		/* M-^\ unbound */
	(data_obj *) NULL,		/* M-^] unbound */
	(data_obj *) NULL,		/* M-^^ unbound */
	(data_obj *) NULL,		/* M-^_ unbound */
	(data_obj *) NULL,		/* M-  unbound */
	(data_obj *) NULL,		/* M-! unbound */
	(data_obj *) NULL,		/* M-" unbound */
	(data_obj *) NULL,		/* M-# unbound */
	(data_obj *) NULL,		/* M-$ unbound */
	(data_obj *) NULL,		/* M-% unbound */
	(data_obj *) NULL,		/* M-& unbound */
	(data_obj *) NULL,		/* M-' unbound */
	(data_obj *) NULL,		/* M-( unbound */
	(data_obj *) NULL,		/* M-) unbound */
	(data_obj *) NULL,		/* M-* unbound */
	(data_obj *) NULL,		/* M-+ unbound */
	(data_obj *) NULL,		/* M-, unbound */
	(data_obj *) NULL,		/* M-- unbound */
	(data_obj *) NULL,		/* M-. unbound */
	(data_obj *) NULL,		/* M-/ unbound */
	(data_obj *) NULL,		/* M-0 unbound */
	(data_obj *) NULL,		/* M-1 unbound */
	(data_obj *) NULL,		/* M-2 unbound */
	(data_obj *) NULL,		/* M-3 unbound */
	(data_obj *) NULL,		/* M-4 unbound */
	(data_obj *) NULL,		/* M-5 unbound */
	(data_obj *) NULL,		/* M-6 unbound */
	(data_obj *) NULL,		/* M-7 unbound */
	(data_obj *) NULL,		/* M-8 unbound */
	(data_obj *) NULL,		/* M-9 unbound */
	(data_obj *) NULL,		/* M-: unbound */
	(data_obj *) NULL,		/* M-; unbound */
	(data_obj *) NULL,		/* M-< unbound */
	(data_obj *) NULL,		/* M-= unbound */
	(data_obj *) NULL,		/* M-> unbound */
	(data_obj *) NULL,		/* M-? unbound */
	(data_obj *) NULL,		/* M-@ unbound */
	(data_obj *) NULL,		/* M-A unbound */
	(data_obj *) NULL,		/* M-B unbound */
	(data_obj *) NULL,		/* M-C unbound */
	(data_obj *) NULL,		/* M-D unbound */
	(data_obj *) NULL,		/* M-E unbound */
	(data_obj *) NULL,		/* M-F unbound */
	(data_obj *) NULL,		/* M-G unbound */
	(data_obj *) NULL,		/* M-H unbound */
	(data_obj *) NULL,		/* M-I unbound */
	(data_obj *) NULL,		/* M-J unbound */
	(data_obj *) NULL,		/* M-K unbound */
	(data_obj *) NULL,		/* M-L unbound */
	(data_obj *) NULL,		/* M-M unbound */
	(data_obj *) NULL,		/* M-N unbound */
	(data_obj *) NULL,		/* M-O unbound */
	(data_obj *) NULL,		/* M-P unbound */
	(data_obj *) NULL,		/* M-Q unbound */
	(data_obj *) NULL,		/* M-R unbound */
	(data_obj *) NULL,		/* M-S unbound */
	(data_obj *) NULL,		/* M-T unbound */
	(data_obj *) NULL,		/* M-U unbound */
	(data_obj *) NULL,		/* M-V unbound */
	(data_obj *) NULL,		/* M-W unbound */
	(data_obj *) NULL,		/* M-X unbound */
	(data_obj *) NULL,		/* M-Y unbound */
	(data_obj *) NULL,		/* M-Z unbound */
	(data_obj *) NULL,		/* M-[ unbound */
	(data_obj *) NULL,		/* M-\ unbound */
	(data_obj *) NULL,		/* M-] unbound */
	(data_obj *) NULL,		/* M-^ unbound */
	(data_obj *) NULL,		/* M-_ unbound */
	(data_obj *) NULL,		/* M-` unbound */
	(data_obj *) NULL,		/* M-a unbound */
	(data_obj *) NULL,		/* M-b unbound */
	(data_obj *) NULL,		/* M-c unbound */
	(data_obj *) NULL,		/* M-d unbound */
	(data_obj *) NULL,		/* M-e unbound */
	(data_obj *) NULL,		/* M-f unbound */
	(data_obj *) NULL,		/* M-g unbound */
	(data_obj *) NULL,		/* M-h unbound */
	(data_obj *) NULL,		/* M-i unbound */
	(data_obj *) NULL,		/* M-j unbound */
	(data_obj *) NULL,		/* M-k unbound */
	(data_obj *) NULL,		/* M-l unbound */
	(data_obj *) NULL,		/* M-m unbound */
	(data_obj *) NULL,		/* M-n unbound */
	(data_obj *) NULL,		/* M-o unbound */
	(data_obj *) NULL,		/* M-p unbound */
	(data_obj *) NULL,		/* M-q unbound */
	(data_obj *) NULL,		/* M-r unbound */
	(data_obj *) NULL,		/* M-s unbound */
	(data_obj *) NULL,		/* M-t unbound */
	(data_obj *) NULL,		/* M-u unbound */
	(data_obj *) NULL,		/* M-v unbound */
	(data_obj *) NULL,		/* M-w unbound */
	(data_obj *) NULL,		/* M-x unbound */
	(data_obj *) NULL,		/* M-y unbound */
	(data_obj *) NULL,		/* M-z unbound */
	(data_obj *) NULL,		/* M-{ unbound */
	(data_obj *) NULL,		/* M-| unbound */
	(data_obj *) NULL,		/* M-} unbound */
	(data_obj *) NULL,		/* M-~ unbound */
	(data_obj *) NULL,		/* M-^? unbound */
#endif /* NCHARS != 128 */
};

#ifdef PCNONASCII
/* These are codes generated by non-ASCII keys on an IBM-PC keyboard.
 * Codes marked with [E] are only generated by enhanced keyboards.
 * The codes 171 to 183 are synthesized by JOVE when it detects
 * shift + a code in 71 to 83.
 */
data_obj	*NonASCIIKeys[NCHARS] = {
	(data_obj *) NULL,		/* ^@ unbound */
	(data_obj *) NULL,		/* ^A unbound */
	(data_obj *) NULL,		/* ^B unbound */
	(data_obj *) NULL,		/* ^C unbound */
	(data_obj *) NULL,		/* ^D unbound */
	(data_obj *) NULL,		/* ^E unbound */
	(data_obj *) NULL,		/* ^F unbound */
	(data_obj *) NULL,		/* ^G unbound */
	(data_obj *) NULL,		/* ^H unbound */
	(data_obj *) NULL,		/* ^I unbound */
	(data_obj *) NULL,		/* ^J unbound */
	(data_obj *) NULL,		/* ^K unbound */
	(data_obj *) NULL,		/* ^L unbound */
	(data_obj *) NULL,		/* ^M unbound */
	(data_obj *) NULL,		/* ^N unbound */
	(data_obj *) NULL,		/* ^O unbound */
	(data_obj *) &commands[146],	/* ^P query-replace-string */
	(data_obj *) &commands[34],	/* ^Q copy-region */
	(data_obj *) &commands[88],	/* ^R forward-sentence */
	(data_obj *) &commands[154],	/* ^S replace-string */
	(data_obj *) NULL,		/* ^T unbound */
	(data_obj *) &commands[209],	/* ^U yank-pop */
	(data_obj *) &commands[29],	/* ^V case-word-upper */
	(data_obj *) &commands[116],	/* ^W make-macro-interactive */
	(data_obj *) NULL,		/* ^X unbound */
	(data_obj *) NULL,		/* ^Y unbound */
	(data_obj *) NULL,		/* ^Z unbound */
	(data_obj *) NULL,		/* ESC unbound */
	(data_obj *) NULL,		/* ^\ unbound */
	(data_obj *) NULL,		/* ^] unbound */
	(data_obj *) &commands[11],	/* ^^ backward-sentence */
	(data_obj *) NULL,		/* ^_ unbound */
	(data_obj *) &commands[101],	/*   kill-next-word */
	(data_obj *) &commands[89],	/* ! forward-word */
	(data_obj *) &commands[92],	/* " goto-line */
	(data_obj *) NULL,		/* # unbound */
	(data_obj *) &commands[77],	/* $ fill-paragraph */
	(data_obj *) &commands[108],	/* % kill-to-end-of-sentence */
	(data_obj *) &commands[28],	/* & case-word-lower */
	(data_obj *) NULL,		/* ' unbound */
	(data_obj *) NULL,		/* ( unbound */
	(data_obj *) NULL,		/* ) unbound */
	(data_obj *) NULL,		/* * unbound */
	(data_obj *) NULL,		/* + unbound */
	(data_obj *) &commands[157],	/* , scroll-down */
	(data_obj *) &commands[74],	/* - execute-named-command */
	(data_obj *) &commands[27],	/* . case-word-capitalize */
	(data_obj *) &commands[136],	/* / previous-page */
	(data_obj *) &commands[13],	/* 0 backward-word */
	(data_obj *) NULL,		/* 1 unbound */
	(data_obj *) &commands[83],	/* 2 first-non-blank */
	(data_obj *) NULL,		/* 3 unbound */
	(data_obj *) NULL,		/* 4 unbound */
	(data_obj *) NULL,		/* 5 unbound */
	(data_obj *) NULL,		/* 6 unbound */
	(data_obj *) NULL,		/* 7 unbound */
	(data_obj *) NULL,		/* 8 unbound */
	(data_obj *) NULL,		/* 9 unbound */
	(data_obj *) NULL,		/* : unbound */
	(data_obj *) NULL,		/* ; unbound */
	(data_obj *) NULL,		/* < unbound */
	(data_obj *) NULL,		/* = unbound */
	(data_obj *) NULL,		/* > unbound */
	(data_obj *) NULL,		/* ? unbound */
	(data_obj *) NULL,		/* @ unbound */
	(data_obj *) NULL,		/* A unbound */
	(data_obj *) NULL,		/* B unbound */
	(data_obj *) NULL,		/* C unbound */
	(data_obj *) NULL,		/* D unbound */
	(data_obj *) NULL,		/* E unbound */
	(data_obj *) NULL,		/* F unbound */
	(data_obj *) &commands[16],	/* G beginning-of-line */
	(data_obj *) &commands[135],	/* H previous-line */
	(data_obj *) &commands[136],	/* I previous-page */
	(data_obj *) NULL,		/* J unbound */
	(data_obj *) &commands[7],	/* K backward-character */
	(data_obj *) NULL,		/* L unbound */
	(data_obj *) &commands[84],	/* M forward-character */
	(data_obj *) NULL,		/* N unbound */
	(data_obj *) &commands[68],	/* O end-of-line */
	(data_obj *) &commands[122],	/* P next-line */
	(data_obj *) &commands[123],	/* Q next-page */
	(data_obj *) &commands[126],	/* R over-write-mode */
	(data_obj *) NULL,		/* S unbound */
	(data_obj *) NULL,		/* T unbound */
	(data_obj *) NULL,		/* U unbound */
	(data_obj *) NULL,		/* V unbound */
	(data_obj *) NULL,		/* W unbound */
	(data_obj *) NULL,		/* X unbound */
	(data_obj *) NULL,		/* Y unbound */
	(data_obj *) NULL,		/* Z unbound */
	(data_obj *) NULL,		/* [ unbound */
	(data_obj *) NULL,		/* \ unbound */
	(data_obj *) NULL,		/* ] unbound */
	(data_obj *) NULL,		/* ^ unbound */
	(data_obj *) NULL,		/* _ unbound */
	(data_obj *) NULL,		/* ` unbound */
	(data_obj *) NULL,		/* a unbound */
	(data_obj *) NULL,		/* b unbound */
	(data_obj *) NULL,		/* c unbound */
	(data_obj *) NULL,		/* d unbound */
	(data_obj *) NULL,		/* e unbound */
	(data_obj *) NULL,		/* f unbound */
	(data_obj *) NULL,		/* g unbound */
	(data_obj *) NULL,		/* h unbound */
	(data_obj *) NULL,		/* i unbound */
	(data_obj *) NULL,		/* j unbound */
	(data_obj *) NULL,		/* k unbound */
	(data_obj *) NULL,		/* l unbound */
	(data_obj *) NULL,		/* m unbound */
	(data_obj *) NULL,		/* n unbound */
	(data_obj *) NULL,		/* o unbound */
	(data_obj *) NULL,		/* p unbound */
	(data_obj *) NULL,		/* q unbound */
	(data_obj *) NULL,		/* r unbound */
	(data_obj *) &commands[13],	/* s backward-word */
	(data_obj *) &commands[89],	/* t forward-word */
	(data_obj *) &commands[67],	/* u end-of-file */
	(data_obj *) &commands[124],	/* v next-window */
	(data_obj *) &commands[15],	/* w beginning-of-file */
	(data_obj *) &commands[166],	/* x select-buffer-1 */
	(data_obj *) &commands[168],	/* y select-buffer-2 */
	(data_obj *) &commands[169],	/* z select-buffer-3 */
	(data_obj *) &commands[170],	/* { select-buffer-4 */
	(data_obj *) &commands[171],	/* | select-buffer-5 */
	(data_obj *) &commands[172],	/* } select-buffer-6 */
	(data_obj *) &commands[173],	/* ~ select-buffer-7 */
	(data_obj *) &commands[174],	/* ^? select-buffer-8 */
	(data_obj *) &commands[175],	/* M-^@ select-buffer-9 */
	(data_obj *) &commands[167],	/* M-^A select-buffer-10 */
	(data_obj *) NULL,		/* M-^B unbound */
	(data_obj *) NULL,		/* M-^C unbound */
	(data_obj *) &commands[137],	/* M-^D previous-window */
	(data_obj *) NULL,		/* M-^E unbound */
	(data_obj *) NULL,		/* M-^F unbound */
	(data_obj *) NULL,		/* M-^G unbound */
	(data_obj *) NULL,		/* M-^H unbound */
	(data_obj *) NULL,		/* M-^I unbound */
	(data_obj *) NULL,		/* M-^J unbound */
	(data_obj *) NULL,		/* M-^K unbound */
	(data_obj *) NULL,		/* M-^L unbound */
	(data_obj *) NULL,		/* M-^M unbound */
	(data_obj *) NULL,		/* M-^N unbound */
	(data_obj *) NULL,		/* M-^O unbound */
	(data_obj *) NULL,		/* M-^P unbound */
	(data_obj *) NULL,		/* M-^Q unbound */
	(data_obj *) NULL,		/* M-^R unbound */
	(data_obj *) NULL,		/* M-^S unbound */
	(data_obj *) NULL,		/* M-^T unbound */
	(data_obj *) NULL,		/* M-^U unbound */
	(data_obj *) NULL,		/* M-^V unbound */
	(data_obj *) NULL,		/* M-^W unbound */
	(data_obj *) NULL,		/* M-^X unbound */
	(data_obj *) NULL,		/* M-^Y unbound */
	(data_obj *) NULL,		/* M-^Z unbound */
	(data_obj *) NULL,		/* M-ESC unbound */
	(data_obj *) NULL,		/* M-^\ unbound */
	(data_obj *) NULL,		/* M-^] unbound */
	(data_obj *) NULL,		/* M-^^ unbound */
	(data_obj *) NULL,		/* M-^_ unbound */
	(data_obj *) NULL,		/* M-  unbound */
	(data_obj *) NULL,		/* M-! unbound */
	(data_obj *) NULL,		/* M-" unbound */
	(data_obj *) NULL,		/* M-# unbound */
	(data_obj *) NULL,		/* M-$ unbound */
	(data_obj *) NULL,		/* M-% unbound */
	(data_obj *) NULL,		/* M-& unbound */
	(data_obj *) NULL,		/* M-' unbound */
	(data_obj *) NULL,		/* M-( unbound */
	(data_obj *) NULL,		/* M-) unbound */
	(data_obj *) NULL,		/* M-* unbound */
	(data_obj *) NULL,		/* M-+ unbound */
	(data_obj *) NULL,		/* M-, unbound */
	(data_obj *) NULL,		/* M-- unbound */
	(data_obj *) NULL,		/* M-. unbound */
	(data_obj *) NULL,		/* M-/ unbound */
	(data_obj *) NULL,		/* M-0 unbound */
	(data_obj *) NULL,		/* M-1 unbound */
	(data_obj *) NULL,		/* M-2 unbound */
	(data_obj *) NULL,		/* M-3 unbound */
	(data_obj *) NULL,		/* M-4 unbound */
	(data_obj *) NULL,		/* M-5 unbound */
	(data_obj *) NULL,		/* M-6 unbound */
	(data_obj *) NULL,		/* M-7 unbound */
	(data_obj *) NULL,		/* M-8 unbound */
	(data_obj *) NULL,		/* M-9 unbound */
	(data_obj *) NULL,		/* M-: unbound */
	(data_obj *) NULL,		/* M-; unbound */
	(data_obj *) NULL,		/* M-< unbound */
	(data_obj *) NULL,		/* M-= unbound */
	(data_obj *) NULL,		/* M-> unbound */
	(data_obj *) NULL,		/* M-? unbound */
	(data_obj *) NULL,		/* M-@ unbound */
	(data_obj *) NULL,		/* M-A unbound */
	(data_obj *) NULL,		/* M-B unbound */
	(data_obj *) NULL,		/* M-C unbound */
	(data_obj *) NULL,		/* M-D unbound */
	(data_obj *) NULL,		/* M-E unbound */
	(data_obj *) NULL,		/* M-F unbound */
	(data_obj *) NULL,		/* M-G unbound */
	(data_obj *) NULL,		/* M-H unbound */
	(data_obj *) NULL,		/* M-I unbound */
	(data_obj *) NULL,		/* M-J unbound */
	(data_obj *) NULL,		/* M-K unbound */
	(data_obj *) NULL,		/* M-L unbound */
	(data_obj *) NULL,		/* M-M unbound */
	(data_obj *) NULL,		/* M-N unbound */
	(data_obj *) NULL,		/* M-O unbound */
	(data_obj *) NULL,		/* M-P unbound */
	(data_obj *) NULL,		/* M-Q unbound */
	(data_obj *) NULL,		/* M-R unbound */
	(data_obj *) NULL,		/* M-S unbound */
	(data_obj *) NULL,		/* M-T unbound */
	(data_obj *) NULL,		/* M-U unbound */
	(data_obj *) NULL,		/* M-V unbound */
	(data_obj *) NULL,		/* M-W unbound */
	(data_obj *) NULL,		/* M-X unbound */
	(data_obj *) NULL,		/* M-Y unbound */
	(data_obj *) NULL,		/* M-Z unbound */
	(data_obj *) NULL,		/* M-[ unbound */
	(data_obj *) NULL,		/* M-\ unbound */
	(data_obj *) NULL,		/* M-] unbound */
	(data_obj *) NULL,		/* M-^ unbound */
	(data_obj *) NULL,		/* M-_ unbound */
	(data_obj *) NULL,		/* M-` unbound */
	(data_obj *) NULL,		/* M-a unbound */
	(data_obj *) NULL,		/* M-b unbound */
	(data_obj *) NULL,		/* M-c unbound */
	(data_obj *) NULL,		/* M-d unbound */
	(data_obj *) NULL,		/* M-e unbound */
	(data_obj *) NULL,		/* M-f unbound */
	(data_obj *) NULL,		/* M-g unbound */
	(data_obj *) NULL,		/* M-h unbound */
	(data_obj *) NULL,		/* M-i unbound */
	(data_obj *) NULL,		/* M-j unbound */
	(data_obj *) NULL,		/* M-k unbound */
	(data_obj *) NULL,		/* M-l unbound */
	(data_obj *) NULL,		/* M-m unbound */
	(data_obj *) NULL,		/* M-n unbound */
	(data_obj *) NULL,		/* M-o unbound */
	(data_obj *) NULL,		/* M-p unbound */
	(data_obj *) NULL,		/* M-q unbound */
	(data_obj *) NULL,		/* M-r unbound */
	(data_obj *) NULL,		/* M-s unbound */
	(data_obj *) NULL,		/* M-t unbound */
	(data_obj *) NULL,		/* M-u unbound */
	(data_obj *) NULL,		/* M-v unbound */
	(data_obj *) NULL,		/* M-w unbound */
	(data_obj *) NULL,		/* M-x unbound */
	(data_obj *) NULL,		/* M-y unbound */
	(data_obj *) NULL,		/* M-z unbound */
	(data_obj *) NULL,		/* M-{ unbound */
	(data_obj *) NULL,		/* M-| unbound */
	(data_obj *) NULL,		/* M-} unbound */
	(data_obj *) NULL,		/* M-~ unbound */
	(data_obj *) NULL,		/* M-^? unbound */
};
#endif /* PCNONASCII */
