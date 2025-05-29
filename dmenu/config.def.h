/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy  = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"Hack Nerd Font:size=13"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#CFC1BA", "#1C1917" },
	[SchemeSel] = { "#F0EDEC", "#2C363C" },
	[SchemeOut] = { "#F0EDEC", "#2C363C" },
    [SchemeSelHighlight] = { "#CFC1BA", "#2C363C" },
    [SchemeNormHighlight] = { "#F0EDEC", "#1C1917" },
    // [SchemeNorm] = { "#bbbbbb", "#222222" },
    // [SchemeSel] = { "#eeeeee", "#005577" },
    // [SchemeOut] = { "#000000", "#00ffff" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
