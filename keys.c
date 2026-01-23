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
	&commands[37], /* date */
	&commands[68], /* edit-word-abbrevs */
	&commands[80], /* fill-comment */
	&commands[95], /* gather-numeric-argument */
	&commands[100], /* handle-tab */
	&commands[101], /* i-search-forward */
	NULL,
	&commands[110], /* kill-next-word */
	&commands[119], /* left-margin-here */
	&commands[126], /* make-buffer-unmodified */
	&commands[128], /* name-kbd-macro */
	&commands[137], /* over-write-mode */
	&commands[138], /* page-next-window */
	&commands[162], /* query-replace-string */
	&commands[165], /* read-only-mode */
	&commands[173], /* save-file */
	&commands[213], /* teach-jove */
	&commands[217], /* unbound */
	&commands[218], /* version */
	&commands[221], /* window-find */
	&commands[228], /* xj-mouse-copy-cut */
	&commands[242], /* yank */
	NULL,
};
const struct variable *varidx[IDXSZ] = {
	&variables[0], /* abort-char */
	&variables[4], /* bad-filename-extensions */
	&variables[5], /* c-argument-indentation */
	&variables[9], /* dbx-format-string */
	&variables[13], /* error-format-string */
	&variables[16], /* file-creation-mode */
	NULL,
	&variables[18], /* highlight-mark */
	&variables[19], /* interrupt-character */
	&variables[20], /* jove-compiled-with */
	NULL,
	&variables[23], /* lc-ctype */
	&variables[26], /* mail-check-frequency */
	NULL,
	&variables[34], /* one-key-confirmation */
	&variables[35], /* paragraph-delimiter-pattern */
	NULL,
	&variables[38], /* right-margin */
	&variables[39], /* save-on-exit */
	&variables[52], /* tab-width */
	&variables[55], /* update-time-frequency */
	&variables[57], /* visible-bell */
	&variables[58], /* wrap-process-lines */
	NULL,
	NULL,
	NULL,
};
data_obj *MainKeys[NCHARS] = {
	(data_obj *) &commands[195],	/* ^@ set-mark */
	(data_obj *) &commands[16],	/* ^A beginning-of-line */
	(data_obj *) &commands[7],	/* ^B backward-character */
	(data_obj *) NULL,		/* ^C unbound */
	(data_obj *) &commands[45],	/* ^D delete-next-character */
	(data_obj *) &commands[71],	/* ^E end-of-line */
	(data_obj *) &commands[88],	/* ^F forward-character */
	(data_obj *) NULL,		/* ^G unbound */
	(data_obj *) &commands[47],	/* ^H delete-previous-character */
	(data_obj *) &commands[100],	/* ^I handle-tab */
	(data_obj *) &commands[131],	/* ^J newline-and-indent */
	(data_obj *) &commands[117],	/* ^K kill-to-end-of-line */
	(data_obj *) &commands[168],	/* ^L redraw-display */
	(data_obj *) &commands[129],	/* ^M newline */
	(data_obj *) &commands[133],	/* ^N next-line */
	(data_obj *) &commands[130],	/* ^O newline-and-backup */
	(data_obj *) &commands[146],	/* ^P previous-line */
	(data_obj *) &commands[164],	/* ^Q quoted-insert */
	(data_obj *) &commands[180],	/* ^R search-reverse */
	(data_obj *) &commands[178],	/* ^S search-forward */
	(data_obj *) &commands[215],	/* ^T transpose-characters */
	(data_obj *) &commands[95],	/* ^U gather-numeric-argument */
	(data_obj *) &commands[134],	/* ^V next-page */
	(data_obj *) &commands[113],	/* ^W kill-region */
	(data_obj *) NULL,		/* ^X unbound */
	(data_obj *) &commands[242],	/* ^Y yank */
	(data_obj *) &commands[177],	/* ^Z scroll-up */
	(data_obj *) NULL,		/* ESC unbound */
#ifdef MAC	/* peculiar cursor key codes */
	(data_obj *) &commands[7],	/* ^\ backward-character */
	(data_obj *) &commands[88],	/* ^] forward-character */
	(data_obj *) &commands[146],	/* ^^ previous-line */
	(data_obj *) &commands[133],	/* ^_ next-line */
#else
	(data_obj *) &commands[178],	/* ^\ search-forward */
	(data_obj *) &commands[86],	/* ^] find-tag-at-point */
	(data_obj *) &commands[164],	/* ^^ quoted-insert */
	(data_obj *) NULL,		/* ^_ unbound */
#endif
	(data_obj *) &commands[193],	/*   self-insert */
	(data_obj *) &commands[193],	/* ! self-insert */
	(data_obj *) &commands[193],	/* " self-insert */
	(data_obj *) &commands[193],	/* # self-insert */
	(data_obj *) &commands[193],	/* $ self-insert */
	(data_obj *) &commands[193],	/* % self-insert */
	(data_obj *) &commands[193],	/* & self-insert */
	(data_obj *) &commands[193],	/* ' self-insert */
	(data_obj *) &commands[193],	/* ( self-insert */
	(data_obj *) &commands[139],	/* ) paren-flash */
	(data_obj *) &commands[193],	/* * self-insert */
	(data_obj *) &commands[193],	/* + self-insert */
	(data_obj *) &commands[193],	/* , self-insert */
	(data_obj *) &commands[193],	/* - self-insert */
	(data_obj *) &commands[193],	/* . self-insert */
	(data_obj *) &commands[193],	/* / self-insert */
	(data_obj *) &commands[193],	/* 0 self-insert */
	(data_obj *) &commands[193],	/* 1 self-insert */
	(data_obj *) &commands[193],	/* 2 self-insert */
	(data_obj *) &commands[193],	/* 3 self-insert */
	(data_obj *) &commands[193],	/* 4 self-insert */
	(data_obj *) &commands[193],	/* 5 self-insert */
	(data_obj *) &commands[193],	/* 6 self-insert */
	(data_obj *) &commands[193],	/* 7 self-insert */
	(data_obj *) &commands[193],	/* 8 self-insert */
	(data_obj *) &commands[193],	/* 9 self-insert */
	(data_obj *) &commands[193],	/* : self-insert */
	(data_obj *) &commands[193],	/* ; self-insert */
	(data_obj *) &commands[193],	/* < self-insert */
	(data_obj *) &commands[193],	/* = self-insert */
	(data_obj *) &commands[193],	/* > self-insert */
	(data_obj *) &commands[193],	/* ? self-insert */
	(data_obj *) &commands[193],	/* @ self-insert */
	(data_obj *) &commands[193],	/* A self-insert */
	(data_obj *) &commands[193],	/* B self-insert */
	(data_obj *) &commands[193],	/* C self-insert */
	(data_obj *) &commands[193],	/* D self-insert */
	(data_obj *) &commands[193],	/* E self-insert */
	(data_obj *) &commands[193],	/* F self-insert */
	(data_obj *) &commands[193],	/* G self-insert */
	(data_obj *) &commands[193],	/* H self-insert */
	(data_obj *) &commands[193],	/* I self-insert */
	(data_obj *) &commands[193],	/* J self-insert */
	(data_obj *) &commands[193],	/* K self-insert */
	(data_obj *) &commands[193],	/* L self-insert */
	(data_obj *) &commands[193],	/* M self-insert */
	(data_obj *) &commands[193],	/* N self-insert */
	(data_obj *) &commands[193],	/* O self-insert */
	(data_obj *) &commands[193],	/* P self-insert */
	(data_obj *) &commands[193],	/* Q self-insert */
	(data_obj *) &commands[193],	/* R self-insert */
	(data_obj *) &commands[193],	/* S self-insert */
	(data_obj *) &commands[193],	/* T self-insert */
	(data_obj *) &commands[193],	/* U self-insert */
	(data_obj *) &commands[193],	/* V self-insert */
	(data_obj *) &commands[193],	/* W self-insert */
	(data_obj *) &commands[193],	/* X self-insert */
	(data_obj *) &commands[193],	/* Y self-insert */
	(data_obj *) &commands[193],	/* Z self-insert */
	(data_obj *) &commands[193],	/* [ self-insert */
	(data_obj *) &commands[193],	/* \ self-insert */
	(data_obj *) &commands[139],	/* ] paren-flash */
	(data_obj *) &commands[193],	/* ^ self-insert */
	(data_obj *) &commands[193],	/* _ self-insert */
	(data_obj *) &commands[193],	/* ` self-insert */
	(data_obj *) &commands[193],	/* a self-insert */
	(data_obj *) &commands[193],	/* b self-insert */
	(data_obj *) &commands[193],	/* c self-insert */
	(data_obj *) &commands[193],	/* d self-insert */
	(data_obj *) &commands[193],	/* e self-insert */
	(data_obj *) &commands[193],	/* f self-insert */
	(data_obj *) &commands[193],	/* g self-insert */
	(data_obj *) &commands[193],	/* h self-insert */
	(data_obj *) &commands[193],	/* i self-insert */
	(data_obj *) &commands[193],	/* j self-insert */
	(data_obj *) &commands[193],	/* k self-insert */
	(data_obj *) &commands[193],	/* l self-insert */
	(data_obj *) &commands[193],	/* m self-insert */
	(data_obj *) &commands[193],	/* n self-insert */
	(data_obj *) &commands[193],	/* o self-insert */
	(data_obj *) &commands[193],	/* p self-insert */
	(data_obj *) &commands[193],	/* q self-insert */
	(data_obj *) &commands[193],	/* r self-insert */
	(data_obj *) &commands[193],	/* s self-insert */
	(data_obj *) &commands[193],	/* t self-insert */
	(data_obj *) &commands[193],	/* u self-insert */
	(data_obj *) &commands[193],	/* v self-insert */
	(data_obj *) &commands[193],	/* w self-insert */
	(data_obj *) &commands[193],	/* x self-insert */
	(data_obj *) &commands[193],	/* y self-insert */
	(data_obj *) &commands[193],	/* z self-insert */
	(data_obj *) &commands[193],	/* { self-insert */
	(data_obj *) &commands[193],	/* | self-insert */
	(data_obj *) &commands[139],	/* } paren-flash */
	(data_obj *) &commands[193],	/* ~ self-insert */
	(data_obj *) &commands[47],	/* ^? delete-previous-character */
#if NCHARS != 128
	(data_obj *) &commands[193],	/* M-^@ self-insert */
	(data_obj *) &commands[193],	/* M-^A self-insert */
	(data_obj *) &commands[193],	/* M-^B self-insert */
	(data_obj *) &commands[193],	/* M-^C self-insert */
	(data_obj *) &commands[193],	/* M-^D self-insert */
	(data_obj *) &commands[193],	/* M-^E self-insert */
	(data_obj *) &commands[193],	/* M-^F self-insert */
	(data_obj *) &commands[193],	/* M-^G self-insert */
	(data_obj *) &commands[193],	/* M-^H self-insert */
	(data_obj *) &commands[193],	/* M-^I self-insert */
	(data_obj *) &commands[193],	/* M-^J self-insert */
	(data_obj *) &commands[193],	/* M-^K self-insert */
	(data_obj *) &commands[193],	/* M-^L self-insert */
	(data_obj *) &commands[193],	/* M-^M self-insert */
	(data_obj *) &commands[193],	/* M-^N self-insert */
	(data_obj *) &commands[193],	/* M-^O self-insert */
	(data_obj *) &commands[193],	/* M-^P self-insert */
	(data_obj *) &commands[193],	/* M-^Q self-insert */
	(data_obj *) &commands[193],	/* M-^R self-insert */
	(data_obj *) &commands[193],	/* M-^S self-insert */
	(data_obj *) &commands[193],	/* M-^T self-insert */
	(data_obj *) &commands[193],	/* M-^U self-insert */
	(data_obj *) &commands[193],	/* M-^V self-insert */
	(data_obj *) &commands[193],	/* M-^W self-insert */
	(data_obj *) &commands[193],	/* M-^X self-insert */
	(data_obj *) &commands[193],	/* M-^Y self-insert */
	(data_obj *) &commands[193],	/* M-^Z self-insert */
	(data_obj *) &commands[193],	/* M-ESC self-insert */
	(data_obj *) &commands[193],	/* M-^\ self-insert */
	(data_obj *) &commands[193],	/* M-^] self-insert */
	(data_obj *) &commands[193],	/* M-^^ self-insert */
	(data_obj *) &commands[193],	/* M-^_ self-insert */
	(data_obj *) &commands[193],	/* M-  self-insert */
	(data_obj *) &commands[193],	/* M-! self-insert */
	(data_obj *) &commands[193],	/* M-" self-insert */
	(data_obj *) &commands[193],	/* M-# self-insert */
	(data_obj *) &commands[193],	/* M-$ self-insert */
	(data_obj *) &commands[193],	/* M-% self-insert */
	(data_obj *) &commands[193],	/* M-& self-insert */
	(data_obj *) &commands[193],	/* M-' self-insert */
	(data_obj *) &commands[193],	/* M-( self-insert */
	(data_obj *) &commands[193],	/* M-) self-insert */
	(data_obj *) &commands[193],	/* M-* self-insert */
	(data_obj *) &commands[193],	/* M-+ self-insert */
	(data_obj *) &commands[193],	/* M-, self-insert */
	(data_obj *) &commands[193],	/* M-- self-insert */
	(data_obj *) &commands[193],	/* M-. self-insert */
	(data_obj *) &commands[193],	/* M-/ self-insert */
	(data_obj *) &commands[193],	/* M-0 self-insert */
	(data_obj *) &commands[193],	/* M-1 self-insert */
	(data_obj *) &commands[193],	/* M-2 self-insert */
	(data_obj *) &commands[193],	/* M-3 self-insert */
	(data_obj *) &commands[193],	/* M-4 self-insert */
	(data_obj *) &commands[193],	/* M-5 self-insert */
	(data_obj *) &commands[193],	/* M-6 self-insert */
	(data_obj *) &commands[193],	/* M-7 self-insert */
	(data_obj *) &commands[193],	/* M-8 self-insert */
	(data_obj *) &commands[193],	/* M-9 self-insert */
	(data_obj *) &commands[193],	/* M-: self-insert */
	(data_obj *) &commands[193],	/* M-; self-insert */
	(data_obj *) &commands[193],	/* M-< self-insert */
	(data_obj *) &commands[193],	/* M-= self-insert */
	(data_obj *) &commands[193],	/* M-> self-insert */
	(data_obj *) &commands[193],	/* M-? self-insert */
	(data_obj *) &commands[193],	/* M-@ self-insert */
	(data_obj *) &commands[193],	/* M-A self-insert */
	(data_obj *) &commands[193],	/* M-B self-insert */
	(data_obj *) &commands[193],	/* M-C self-insert */
	(data_obj *) &commands[193],	/* M-D self-insert */
	(data_obj *) &commands[193],	/* M-E self-insert */
	(data_obj *) &commands[193],	/* M-F self-insert */
	(data_obj *) &commands[193],	/* M-G self-insert */
	(data_obj *) &commands[193],	/* M-H self-insert */
	(data_obj *) &commands[193],	/* M-I self-insert */
	(data_obj *) &commands[193],	/* M-J self-insert */
	(data_obj *) &commands[193],	/* M-K self-insert */
	(data_obj *) &commands[193],	/* M-L self-insert */
	(data_obj *) &commands[193],	/* M-M self-insert */
	(data_obj *) &commands[193],	/* M-N self-insert */
	(data_obj *) &commands[193],	/* M-O self-insert */
	(data_obj *) &commands[193],	/* M-P self-insert */
	(data_obj *) &commands[193],	/* M-Q self-insert */
	(data_obj *) &commands[193],	/* M-R self-insert */
	(data_obj *) &commands[193],	/* M-S self-insert */
	(data_obj *) &commands[193],	/* M-T self-insert */
	(data_obj *) &commands[193],	/* M-U self-insert */
	(data_obj *) &commands[193],	/* M-V self-insert */
	(data_obj *) &commands[193],	/* M-W self-insert */
	(data_obj *) &commands[193],	/* M-X self-insert */
	(data_obj *) &commands[193],	/* M-Y self-insert */
	(data_obj *) &commands[193],	/* M-Z self-insert */
	(data_obj *) &commands[193],	/* M-[ self-insert */
	(data_obj *) &commands[193],	/* M-\ self-insert */
	(data_obj *) &commands[193],	/* M-] self-insert */
	(data_obj *) &commands[193],	/* M-^ self-insert */
	(data_obj *) &commands[193],	/* M-_ self-insert */
	(data_obj *) &commands[193],	/* M-` self-insert */
	(data_obj *) &commands[193],	/* M-a self-insert */
	(data_obj *) &commands[193],	/* M-b self-insert */
	(data_obj *) &commands[193],	/* M-c self-insert */
	(data_obj *) &commands[193],	/* M-d self-insert */
	(data_obj *) &commands[193],	/* M-e self-insert */
	(data_obj *) &commands[193],	/* M-f self-insert */
	(data_obj *) &commands[193],	/* M-g self-insert */
	(data_obj *) &commands[193],	/* M-h self-insert */
	(data_obj *) &commands[193],	/* M-i self-insert */
	(data_obj *) &commands[193],	/* M-j self-insert */
	(data_obj *) &commands[193],	/* M-k self-insert */
	(data_obj *) &commands[193],	/* M-l self-insert */
	(data_obj *) &commands[193],	/* M-m self-insert */
	(data_obj *) &commands[193],	/* M-n self-insert */
	(data_obj *) &commands[193],	/* M-o self-insert */
	(data_obj *) &commands[193],	/* M-p self-insert */
	(data_obj *) &commands[193],	/* M-q self-insert */
	(data_obj *) &commands[193],	/* M-r self-insert */
	(data_obj *) &commands[193],	/* M-s self-insert */
	(data_obj *) &commands[193],	/* M-t self-insert */
	(data_obj *) &commands[193],	/* M-u self-insert */
	(data_obj *) &commands[193],	/* M-v self-insert */
	(data_obj *) &commands[193],	/* M-w self-insert */
	(data_obj *) &commands[193],	/* M-x self-insert */
	(data_obj *) &commands[193],	/* M-y self-insert */
	(data_obj *) &commands[193],	/* M-z self-insert */
	(data_obj *) &commands[193],	/* M-{ self-insert */
	(data_obj *) &commands[193],	/* M-| self-insert */
	(data_obj *) &commands[193],	/* M-} self-insert */
	(data_obj *) &commands[193],	/* M-~ self-insert */
#ifdef PCNONASCII
	(data_obj *) NULL,		/* M-^? unbound */
#else
	(data_obj *) &commands[193],	/* M-^? self-insert */
#endif
#endif /* NCHARS != 128 */
};

data_obj *EscKeys[NCHARS] = {
	(data_obj *) &commands[195],	/* ^@ set-mark */
	(data_obj *) NULL,		/* ^A unbound */
	(data_obj *) &commands[10],	/* ^B backward-s-expression */
	(data_obj *) NULL,		/* ^C unbound */
	(data_obj *) &commands[66],	/* ^D down-list */
	(data_obj *) NULL,		/* ^E unbound */
	(data_obj *) &commands[91],	/* ^F forward-s-expression */
	(data_obj *) NULL,		/* ^G unbound */
	(data_obj *) NULL,		/* ^H unbound */
	(data_obj *) NULL,		/* ^I unbound */
	(data_obj *) NULL,		/* ^J unbound */
	(data_obj *) &commands[114],	/* ^K kill-s-expression */
	(data_obj *) &commands[32],	/* ^L clear-and-redraw */
	(data_obj *) NULL,		/* ^M unbound */
	(data_obj *) &commands[89],	/* ^N forward-list */
	(data_obj *) NULL,		/* ^O unbound */
	(data_obj *) &commands[8],	/* ^P backward-list */
	(data_obj *) NULL,		/* ^Q unbound */
	(data_obj *) NULL,		/* ^R unbound */
	(data_obj *) NULL,		/* ^S unbound */
	(data_obj *) NULL,		/* ^T unbound */
	(data_obj *) &commands[12],	/* ^U backward-up-list */
	(data_obj *) &commands[138],	/* ^V page-next-window */
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
	(data_obj *) &commands[64],	/* - digit-minus */
	(data_obj *) &commands[72],	/* . end-of-window */
	(data_obj *) NULL,		/* / unbound */
	(data_obj *) &commands[53],	/* 0 digit */
	(data_obj *) &commands[53],	/* 1 digit */
	(data_obj *) &commands[53],	/* 2 digit */
	(data_obj *) &commands[53],	/* 3 digit */
	(data_obj *) &commands[53],	/* 4 digit */
	(data_obj *) &commands[53],	/* 5 digit */
	(data_obj *) &commands[53],	/* 6 digit */
	(data_obj *) &commands[53],	/* 7 digit */
	(data_obj *) &commands[53],	/* 8 digit */
	(data_obj *) &commands[53],	/* 9 digit */
	(data_obj *) NULL,		/* : unbound */
	(data_obj *) NULL,		/* ; unbound */
	(data_obj *) &commands[15],	/* < beginning-of-file */
	(data_obj *) NULL,		/* = unbound */
	(data_obj *) &commands[70],	/* > end-of-file */
	(data_obj *) &commands[50],	/* ? describe-command */
	(data_obj *) NULL,		/* @ unbound */
	(data_obj *) &commands[11],	/* A backward-sentence */
	(data_obj *) &commands[13],	/* B backward-word */
	(data_obj *) &commands[27],	/* C case-word-capitalize */
	(data_obj *) &commands[110],	/* D kill-next-word */
	(data_obj *) &commands[92],	/* E forward-sentence */
	(data_obj *) &commands[93],	/* F forward-word */
	(data_obj *) &commands[96],	/* G goto-line */
	(data_obj *) NULL,		/* H unbound */
	(data_obj *) &commands[127],	/* I make-macro-interactive */
	(data_obj *) &commands[81],	/* J fill-paragraph */
	(data_obj *) &commands[118],	/* K kill-to-end-of-sentence */
	(data_obj *) &commands[28],	/* L case-word-lower */
	(data_obj *) &commands[87],	/* M first-non-blank */
	(data_obj *) NULL,		/* N unbound */
	(data_obj *) NULL,		/* O unbound */
	(data_obj *) NULL,		/* P unbound */
	(data_obj *) &commands[162],	/* Q query-replace-string */
	(data_obj *) &commands[171],	/* R replace-string */
#ifdef JOB_CONTROL
	(data_obj *) &commands[142],	/* S pause-jove */
#else
	(data_obj *) NULL,		/* S unbound */
#endif
	(data_obj *) NULL,		/* T unbound */
	(data_obj *) &commands[29],	/* U case-word-upper */
	(data_obj *) &commands[147],	/* V previous-page */
	(data_obj *) &commands[35],	/* W copy-region */
	(data_obj *) &commands[78],	/* X execute-named-command */
	(data_obj *) &commands[243],	/* Y yank-pop */
	(data_obj *) &commands[174],	/* Z scroll-down */
	(data_obj *) &commands[9],	/* [ backward-paragraph */
	(data_obj *) &commands[48],	/* \ delete-white-space */
	(data_obj *) &commands[90],	/* ] forward-paragraph */
	(data_obj *) NULL,		/* ^ unbound */
	(data_obj *) NULL,		/* _ unbound */
	(data_obj *) NULL,		/* ` unbound */
	(data_obj *) &commands[11],	/* a backward-sentence */
	(data_obj *) &commands[13],	/* b backward-word */
	(data_obj *) &commands[27],	/* c case-word-capitalize */
	(data_obj *) &commands[110],	/* d kill-next-word */
	(data_obj *) &commands[92],	/* e forward-sentence */
	(data_obj *) &commands[93],	/* f forward-word */
	(data_obj *) &commands[96],	/* g goto-line */
	(data_obj *) NULL,		/* h unbound */
	(data_obj *) &commands[127],	/* i make-macro-interactive */
	(data_obj *) &commands[81],	/* j fill-paragraph */
	(data_obj *) &commands[118],	/* k kill-to-end-of-sentence */
	(data_obj *) &commands[28],	/* l case-word-lower */
	(data_obj *) &commands[87],	/* m first-non-blank */
	(data_obj *) NULL,		/* n unbound */
	(data_obj *) NULL,		/* o unbound */
	(data_obj *) NULL,		/* p unbound */
	(data_obj *) &commands[162],	/* q query-replace-string */
	(data_obj *) &commands[171],	/* r replace-string */
#ifdef JOB_CONTROL
	(data_obj *) &commands[142],	/* s pause-jove */
#else
	(data_obj *) NULL,		/* s unbound */
#endif
	(data_obj *) NULL,		/* t unbound */
	(data_obj *) &commands[29],	/* u case-word-upper */
	(data_obj *) &commands[147],	/* v previous-page */
	(data_obj *) &commands[35],	/* w copy-region */
	(data_obj *) &commands[78],	/* x execute-named-command */
	(data_obj *) &commands[243],	/* y yank-pop */
	(data_obj *) &commands[174],	/* z scroll-down */
	(data_obj *) NULL,		/* { unbound */
	(data_obj *) NULL,		/* | unbound */
	(data_obj *) NULL,		/* } unbound */
	(data_obj *) &commands[126],	/* ~ make-buffer-unmodified */
	(data_obj *) &commands[111],	/* ^? kill-previous-word */
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
	(data_obj *) &commands[121],	/* ^B list-buffers */
	(data_obj *) &commands[79],	/* ^C exit-jove */
	(data_obj *) NULL,		/* ^D unbound */
#ifdef SUBSHELL
	(data_obj *) &commands[33],	/* ^E compile-it */
#else
	(data_obj *) NULL,		/* ^E unbound */
#endif
	(data_obj *) &commands[84],	/* ^F find-file */
	(data_obj *) NULL,		/* ^G unbound */
	(data_obj *) NULL,		/* ^H unbound */
	(data_obj *) &commands[104],	/* ^I insert-file */
	(data_obj *) NULL,		/* ^J unbound */
	(data_obj *) NULL,		/* ^K unbound */
	(data_obj *) NULL,		/* ^L unbound */
	(data_obj *) &commands[225],	/* ^M write-modified-files */
	(data_obj *) &commands[132],	/* ^N next-error */
	(data_obj *) &commands[42],	/* ^O delete-blank-lines */
	(data_obj *) &commands[145],	/* ^P previous-error */
	(data_obj *) NULL,		/* ^Q unbound */
	(data_obj *) &commands[220],	/* ^R visit-file */
	(data_obj *) &commands[173],	/* ^S save-file */
	(data_obj *) &commands[216],	/* ^T transpose-lines */
	(data_obj *) NULL,		/* ^U unbound */
	(data_obj *) &commands[220],	/* ^V visit-file */
	(data_obj *) &commands[223],	/* ^W write-file */
	(data_obj *) &commands[75],	/* ^X exchange-point-and-mark */
	(data_obj *) NULL,		/* ^Y unbound */
	(data_obj *) NULL,		/* ^Z unbound */
	(data_obj *) NULL,		/* ESC unbound */
	(data_obj *) &commands[173],	/* ^\ save-file */
	(data_obj *) NULL,		/* ^] unbound */
	(data_obj *) NULL,		/* ^^ unbound */
	(data_obj *) NULL,		/* ^_ unbound */
	(data_obj *) NULL,		/*   unbound */
#ifdef SUBSHELL
	(data_obj *) &commands[197],	/* ! shell-command */
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
	(data_obj *) &commands[69],	/* ) end-kbd-macro */
	(data_obj *) NULL,		/* * unbound */
	(data_obj *) NULL,		/* + unbound */
	(data_obj *) NULL,		/* , unbound */
	(data_obj *) NULL,		/* - unbound */
	(data_obj *) NULL,		/* . unbound */
	(data_obj *) NULL,		/* / unbound */
	(data_obj *) NULL,		/* 0 unbound */
	(data_obj *) &commands[46],	/* 1 delete-other-windows */
	(data_obj *) &commands[207],	/* 2 split-current-window */
	(data_obj *) NULL,		/* 3 unbound */
	(data_obj *) &commands[221],	/* 4 window-find */
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
	(data_obj *) &commands[51],	/* ? describe-key */
	(data_obj *) NULL,		/* @ unbound */
	(data_obj *) NULL,		/* A unbound */
	(data_obj *) &commands[182],	/* B select-buffer */
	(data_obj *) NULL,		/* C unbound */
	(data_obj *) &commands[44],	/* D delete-current-window */
	(data_obj *) &commands[76],	/* E execute-kbd-macro */
	(data_obj *) NULL,		/* F unbound */
	(data_obj *) NULL,		/* G unbound */
	(data_obj *) NULL,		/* H unbound */
	(data_obj *) NULL,		/* I unbound */
	(data_obj *) NULL,		/* J unbound */
	(data_obj *) &commands[43],	/* K delete-buffer */
	(data_obj *) NULL,		/* L unbound */
	(data_obj *) NULL,		/* M unbound */
	(data_obj *) &commands[135],	/* N next-window */
	(data_obj *) &commands[148],	/* O previous-window */
	(data_obj *) &commands[148],	/* P previous-window */
	(data_obj *) NULL,		/* Q unbound */
	(data_obj *) NULL,		/* R unbound */
	(data_obj *) &commands[173],	/* S save-file */
	(data_obj *) &commands[85],	/* T find-tag */
	(data_obj *) NULL,		/* U unbound */
	(data_obj *) NULL,		/* V unbound */
	(data_obj *) NULL,		/* W unbound */
	(data_obj *) NULL,		/* X unbound */
	(data_obj *) NULL,		/* Y unbound */
	(data_obj *) NULL,		/* Z unbound */
	(data_obj *) NULL,		/* [ unbound */
	(data_obj *) NULL,		/* \ unbound */
	(data_obj *) NULL,		/* ] unbound */
	(data_obj *) &commands[99],	/* ^ grow-window */
	(data_obj *) NULL,		/* _ unbound */
	(data_obj *) NULL,		/* ` unbound */
	(data_obj *) NULL,		/* a unbound */
	(data_obj *) &commands[182],	/* b select-buffer */
	(data_obj *) NULL,		/* c unbound */
	(data_obj *) &commands[44],	/* d delete-current-window */
	(data_obj *) &commands[76],	/* e execute-kbd-macro */
	(data_obj *) NULL,		/* f unbound */
	(data_obj *) NULL,		/* g unbound */
	(data_obj *) NULL,		/* h unbound */
	(data_obj *) NULL,		/* i unbound */
	(data_obj *) NULL,		/* j unbound */
	(data_obj *) &commands[43],	/* k delete-buffer */
	(data_obj *) NULL,		/* l unbound */
	(data_obj *) NULL,		/* m unbound */
	(data_obj *) &commands[135],	/* n next-window */
	(data_obj *) &commands[148],	/* o previous-window */
	(data_obj *) &commands[148],	/* p previous-window */
	(data_obj *) NULL,		/* q unbound */
	(data_obj *) NULL,		/* r unbound */
	(data_obj *) &commands[173],	/* s save-file */
	(data_obj *) &commands[85],	/* t find-tag */
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
	(data_obj *) &commands[116],	/* ^? kill-to-beginning-of-sentence */
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
	(data_obj *) &commands[162],	/* ^P query-replace-string */
	(data_obj *) &commands[35],	/* ^Q copy-region */
	(data_obj *) &commands[92],	/* ^R forward-sentence */
	(data_obj *) &commands[171],	/* ^S replace-string */
	(data_obj *) NULL,		/* ^T unbound */
	(data_obj *) &commands[243],	/* ^U yank-pop */
	(data_obj *) &commands[29],	/* ^V case-word-upper */
	(data_obj *) &commands[127],	/* ^W make-macro-interactive */
	(data_obj *) NULL,		/* ^X unbound */
	(data_obj *) NULL,		/* ^Y unbound */
	(data_obj *) NULL,		/* ^Z unbound */
	(data_obj *) NULL,		/* ESC unbound */
	(data_obj *) NULL,		/* ^\ unbound */
	(data_obj *) NULL,		/* ^] unbound */
	(data_obj *) &commands[11],	/* ^^ backward-sentence */
	(data_obj *) NULL,		/* ^_ unbound */
	(data_obj *) &commands[110],	/*   kill-next-word */
	(data_obj *) &commands[93],	/* ! forward-word */
	(data_obj *) &commands[96],	/* " goto-line */
	(data_obj *) NULL,		/* # unbound */
	(data_obj *) &commands[81],	/* $ fill-paragraph */
	(data_obj *) &commands[118],	/* % kill-to-end-of-sentence */
	(data_obj *) &commands[28],	/* & case-word-lower */
	(data_obj *) NULL,		/* ' unbound */
	(data_obj *) NULL,		/* ( unbound */
	(data_obj *) NULL,		/* ) unbound */
	(data_obj *) NULL,		/* * unbound */
	(data_obj *) NULL,		/* + unbound */
	(data_obj *) &commands[174],	/* , scroll-down */
	(data_obj *) &commands[78],	/* - execute-named-command */
	(data_obj *) &commands[27],	/* . case-word-capitalize */
	(data_obj *) &commands[147],	/* / previous-page */
	(data_obj *) &commands[13],	/* 0 backward-word */
	(data_obj *) NULL,		/* 1 unbound */
	(data_obj *) &commands[87],	/* 2 first-non-blank */
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
	(data_obj *) &commands[146],	/* H previous-line */
	(data_obj *) &commands[147],	/* I previous-page */
	(data_obj *) NULL,		/* J unbound */
	(data_obj *) &commands[7],	/* K backward-character */
	(data_obj *) NULL,		/* L unbound */
	(data_obj *) &commands[88],	/* M forward-character */
	(data_obj *) NULL,		/* N unbound */
	(data_obj *) &commands[71],	/* O end-of-line */
	(data_obj *) &commands[133],	/* P next-line */
	(data_obj *) &commands[134],	/* Q next-page */
	(data_obj *) &commands[137],	/* R over-write-mode */
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
	(data_obj *) &commands[93],	/* t forward-word */
	(data_obj *) &commands[70],	/* u end-of-file */
	(data_obj *) &commands[135],	/* v next-window */
	(data_obj *) &commands[15],	/* w beginning-of-file */
	(data_obj *) &commands[183],	/* x select-buffer-1 */
	(data_obj *) &commands[185],	/* y select-buffer-2 */
	(data_obj *) &commands[186],	/* z select-buffer-3 */
	(data_obj *) &commands[187],	/* { select-buffer-4 */
	(data_obj *) &commands[188],	/* | select-buffer-5 */
	(data_obj *) &commands[189],	/* } select-buffer-6 */
	(data_obj *) &commands[190],	/* ~ select-buffer-7 */
	(data_obj *) &commands[191],	/* ^? select-buffer-8 */
	(data_obj *) &commands[192],	/* M-^@ select-buffer-9 */
	(data_obj *) &commands[184],	/* M-^A select-buffer-10 */
	(data_obj *) NULL,		/* M-^B unbound */
	(data_obj *) NULL,		/* M-^C unbound */
	(data_obj *) &commands[148],	/* M-^D previous-window */
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
