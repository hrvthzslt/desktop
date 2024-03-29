/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 8;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Hack Nerd Font:size=13" };
static const char dmenufont[]       = "Hack Nerd Font:size=13";
static const char col_gray1[]       = "#282828";
static const char col_gray2[]       = "#504945";
static const char col_gray3[]       = "#ebdbb2";
static const char col_gray4[]       = "#fbf1c7";
static const char col_cyan[]        = "#504945";
/* static const char col_cyan[]        = "#458588"; */
/* static const char col_cyan[]        = "#b16286"; */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
    /*               fg      bg        border*/
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

static const char *const autostart[] = {
    "gnome-keyring-daemon", "-r", "-d", NULL,
    "slstatus", NULL,
    "clipmenud", NULL,
    "picom", "--backend", "glx", "--vsync", NULL,
    /* "picom", "--backend", "glx", "--vsync", "--blur-method", "dual_kawase", "--blur-strength", "3", NULL, */
    "nitrogen", "--restore", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "", "", "󰻞", "" };

static const char termname[] = "alacritty";

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance    title                   tags mask     isfloating   monitor */
    { "st",             NULL,       NULL,                   1,            0,           -1 },
    { NULL,             NULL,       "Alacritty",            1,            0,           -1 },
    { "kitty",          NULL,       NULL,                   1,            0,           -1 },
    { "firefox",        NULL,       NULL,                   1 << 1,       0,           -1 },
    /* { "google-chrome",  NULL,       NULL,                   1 << 1,       0,           -1 }, */
    { NULL,             NULL,       "Google Chrome",        1 << 1,       0,           -1 },
    { NULL,             NULL,       "nmtui",                0,            1,           -1 },
    { NULL,             NULL,       "bluetuith",            0,            1,           -1 },
    { NULL,             NULL,       "Screen Layout Editor", 0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *clipmenucmd[]  = { "clipmenu", "-i", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *cliptogglecmd[]  = { "clipctl", "toggle", NULL };
static const char *clipdelcmd[]  = { "clipdel", "-d", "[0-9]*" };
static const char *termcmd[]  = { termname, NULL };
static const char *browsercmd[]  = { "google-chrome", NULL };
static const char *slockcmd[]  = { "slock", NULL };
static const char *increasevolumecmd[]  = { "amixer", "sset", "Master", "5%+" };
static const char *decreasevolumecmd[]  = { "amixer", "sset", "Master", "5%-" };
static const char *mutevolumecmd[]  = { "amixer", "sset", "Master", "0%" };
static const char *brightnessupcmd[] = { "brightnessctl", "set", "10%+", NULL };
static const char *brightnessdowncmd[] = { "brightnessctl", "set", "10%-", NULL };
static const char *restartslstatuscmd[]  = { "killall", "-s", "USR1", "slstatus", NULL };
static const char *detectmonitorscmd[]  = { "autorandr", "--change", NULL };
static const char *nitrogenrestorecmd[]  = { "nitrogen", "--restore", NULL };
static const char *nmtuicmd[]  = { termname, "--title", "nmtui", "--command", "nmtui", NULL };
static const char *bluetuiuthcmd[]  = { termname, "--title", "bluetuith", "--command", "bluetuith", NULL };
static const char *prtscrcmd[]  = { "flameshot", "gui", NULL };
static const char *arandrcmd[]  = { "arandr", NULL };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
    // Program related keybindings
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = clipmenucmd } },
    { MODKEY,                       XK_c,      spawn,          {.v = cliptogglecmd } },
    { MODKEY,                       XK_c,      spawn,          {.v = restartslstatuscmd } },
    { MODKEY|ShiftMask,             XK_c,      spawn,          {.v = clipdelcmd } },
    { MODKEY|ShiftMask,             XK_l,      spawn,          {.v = slockcmd } },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_b,      spawn,          {.v = browsercmd } },
    { MODKEY,                       XK_r,      spawn,          {.v = detectmonitorscmd } },
    { MODKEY,                       XK_r,      spawn,          {.v = nitrogenrestorecmd } },
    { MODKEY,                       XK_n,      spawn,          {.v = nmtuicmd } },
    { MODKEY,                       XK_u,      spawn,          {.v = bluetuiuthcmd } },
    { MODKEY,                       XK_s,      spawn,          {.v = arandrcmd } },
    { 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = increasevolumecmd } },
    { 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = restartslstatuscmd } },
    { 0,                            XF86XK_AudioLowerVolume, spawn, {.v = decreasevolumecmd } },
    { 0,                            XF86XK_AudioLowerVolume, spawn, {.v = restartslstatuscmd } },
    { 0,                            XF86XK_MonBrightnessUp,  spawn, {.v = brightnessupcmd } },
    { 0,                            XF86XK_MonBrightnessDown,  spawn, {.v = brightnessdowncmd } },
    { 0,                            XF86XK_AudioMute, spawn, {.v = mutevolumecmd } },
    { 0,                            XF86XK_AudioMute, spawn, {.v = restartslstatuscmd } },
    { 0,                            XK_Print,         spawn, {.v = prtscrcmd } },
    // WM related keybindings
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_minus,  setgaps,        {.i = +4 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = -4 } },
	/* { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } }, */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

