/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 30;       /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Cascadia Code,Noto,monospace:size=12" };
static const char dmenufont[]       = { "Cascadia Code,Noto,monospace:size=12" };
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      						instance    title       tags mask			iscentered     	isfloating   monitor */
	{ "csgo_linux64",  					NULL,       NULL,       1,					1,				0,           -1 },
	{ "Dirt4",  						NULL,       NULL,       1,					1,				0,           -1 },
	{ "code-oss",  						NULL,       NULL,       1,					1,				0,           -1 },
	{ "Eclipse",  						NULL,       NULL,       1,					1,				0,           -1 },
	{ "Darktable",  					NULL,       NULL,       1,					1,				0,           -1 },
	{ "Gimp",  							NULL,       NULL,       1,					1,				0,           -1 },
	{ "kdenlive",  						NULL,       NULL,       1,					1,				0,           -1 },

	{ "Steam",							NULL,       NULL,       1 << 1,				1,				0,           -1 },
	{ "Lutris",							NULL,       NULL,       1 << 1,				1,				0,           -1 },
	{ "discord",						NULL,       NULL,       1 << 1,				1,				0,           -1 },

	{ "firefox",  						NULL,       NULL,       1 << 2,				1,				0,           -1 },
	{ "Chromium",  						NULL,       NULL,       1 << 2,				1,				0,           -1 },
	{ "Brave-browser",  				NULL,       NULL,       1 << 2,				1,				0,           -1 },

	{ "Spotify",  						NULL,       NULL,       1 << 3,				1,				0,           -1 },
	{ "Tor Browser",  					NULL,       NULL,       1 << 3,				1,				1,           -1 },
	{ "Thunar",  						NULL,       NULL,       1 << 3,				1,				0,           -1 },

	{ "obs",  							NULL,       NULL,       1 << 4,				1,				0,           -1 },
	{ "Audacity",  						NULL,       NULL,       1 << 4,				1,				0,           -1 },
	{ "dolphin",  						NULL,       NULL,       1 << 4,				1,				0,           -1 },
	{ "SimpleScreenRecorder",			NULL,       NULL,       1 << 4,				1,				0,           -1 },

	{ "Pavucontrol",					NULL,       NULL,       1 << 5,				1,				0,           -1 },
	{ "pavucontrol-qt",					NULL,       NULL,       1 << 5,				1,				0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st" };

static Key keys[] = {
	/* modifier                     key						   function        argument */
	{ MODKEY,                       XK_semicolon,				spawn,          {.v = dmenucmd } },
	{ MODKEY,			            XK_Return,				   	spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,					   	togglebar,      {0} },
	{ MODKEY,                       XK_a,					   	focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_j,					   	focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,					   	focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,					   	incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,					   	incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,					   	setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,					   	setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return,				   	zoom,           {0} },
	{ MODKEY,                       XK_Tab,					   	view,           {0} },
	{ MODKEY,             			XK_o,						killclient,     {0} },
	{ MODKEY,                       XK_t,					   	setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_e,					   	setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,					   	setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,				   	setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,				   	togglefloating, {0} },
	{ MODKEY,                       XK_0,					   	view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,					   	tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,				   	focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,				   	focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,				   	tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,				   	tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F5,					   	xrdb,           {.v = NULL } },
	TAGKEYS(                        XK_1,						0)
	TAGKEYS(                        XK_2,						1)
	TAGKEYS(                        XK_3,						2)
	TAGKEYS(                        XK_q,						3)
	TAGKEYS(                        XK_w,						4)
	TAGKEYS(                        XK_f,						5)
	TAGKEYS(                        XK_7,						6)
	TAGKEYS(                        XK_8,						7)
	TAGKEYS(                        XK_9,						8)
	{ MODKEY|ShiftMask,             XK_o,						quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
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

