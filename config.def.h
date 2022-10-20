/*pdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqppdbqpdbqpdbqpdbqpdbqpdbqpdb
     `7MM                    `7MM          MMP""MM""YMM `7MM"""Mq.   .g8"""bgd
       MM                      MM          P'   MM   `7   MM   `MM..dP'     `M
  ,M""bMM `7MM  `7MM  ,pP"Ybd  MM  ,MP'         MM        MM   ,M9 dM'       `
,AP    MM   MM    MM  8I   `"  MM ;Y            MM        MMmmdM9  MM
8MI    MM   MM    MM  `YMMMa.  MM;Mm            MM        MM  YM.  MM.    `7MMF'
`Mb    MM   MM    MM  L.   I8  MM `Mb.          MM        MM   `Mb.`Mb.     MM
 `Wbmd"MML. `Mbod"YML.M9mmmP'.JMML. YA.       .JMML.    .JMML. .JMM. `"bmmmdPY
pdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqppdbqpdbqpdbqpdbqpdbqpdbqpdbq*/

/*  Mon 27 May 2022 09:51:10 PM CDT*/
#include "config.colors.h"
#include "config.bar.h"

/*{{{ Technical Appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 1;  /* snap pixel */
static const unsigned int gappih         = 5;   /* horiz inner gap between windows */
static const unsigned int gappiv         = 5;   /* vert inner gap between windows */
static const unsigned int gappoh         = 5;   /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 5;   /* vert outer gap between windows and screen edge */
static const unsigned int gappfl         = 5;   /* gap between floating windows (when relevant) */
static const unsigned int smartgaps_fact = 0;   /* smartgaps factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */



/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab			= showtab_never;        /* Default tab bar show mode */
static const int toptab				= False;               /* False means bottom tab bar */



static unsigned int attachdefault        = AttachAside; // AttachMaster, AttachAbove, AttachAside, AttachBelow, AttachBottom

static const int initshowbar             = 1;   /* 0 means no bar */

static const int bar_height              = 0;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = borderpx;  /* vertical (outer) padding of bar */
static const int sidepad                 = borderpx;  /* horizontal (outer) padding of bar */

static const int iconsize                = 24;  /* icon size */
static const int iconspacing             = 5;   /* space between icon and title */

static const int scalepreview            = 10;   /* size of workspace previews compared to monitor size */

static int floatposgrid_x                 = 5;   /* float grid columns */
static int floatposgrid_y                 = 5;   /* float grid rows */

static const int horizpadbar             = 2;   /* horizontal (inner) padding for statusbar (increases lrpad) */
static const int vertpadbar              = 0;   /* vertical (inner) padding for statusbar (increases bh, overridden by bar_height) */

static const char slopspawnstyle[]       = "-t 0 -c 0.92,0.85,0.69,0.3 -o"; /* do NOT define -f (format) here */
static const char slopresizestyle[]      = "-t 0 -c 0.92,0.85,0.69,0.3"; /* do NOT define -f (format) here */
static const unsigned int systrayspacing = 7;   /* systray spacing */
static const char *toggle_float_pos       = "50% 50% 80% 80%"; // default floating position when triggering togglefloating
static const double defaultopacity       = 0;   /* client default opacity, e.g. 0.75. 0 means don't apply opacity */
static const double moveopacity          = 0.50;   /* client opacity when being moved, 0 means don't apply opacity */
static const double resizeopacity        = 0.50;   /* client opacity when being resized, 0 means don't apply opacity */
static const double placeopacity         = 0;   /* client opacity when being placed, 0 means don't apply opacity */

/* Indicators: see lib/bar_indicators.h for options */
static int wsindicatortype               = INDICATOR_NONE;
static int wspinnedindicatortype         = INDICATOR_NONE;
static int fakefsindicatortype           = INDICATOR_PLUS;
static int floatfakefsindicatortype       = INDICATOR_PLUS_AND_LARGER_SQUARE;
static int floatindicatortype             = INDICATOR_TOP_LEFT_LARGER_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;

/* Custom indicators using status2d markup, e.g. enabled via INDICATOR_CUSTOM_3 */
static char *custom_2d_indicator_1 = "^c#00A523^^r0,h,w,2^"; // green underline
static char *custom_2d_indicator_2 = "^c#55cdfc^^r3,3,4,4^^c#E72608^^r4,4,2,2^"; // blue rectangle
static char *custom_2d_indicator_3 = "^f-10^^c#E72608^𐄛"; // example using a character as an indicator
static char *custom_2d_indicator_4 = "^c#E26F0B^^r0,h,w,1^^r0,0,1,h^^r0,0,w,1^^rw,0,1,h^"; // orange box
static char *custom_2d_indicator_5 = "^c#CB9700^^r0,h,w,1^^r0,0,w,1^"; // top and bottom lines
static char *custom_2d_indicator_6 = "^c#F0A523^^r6,2,1,-4^^r-6,2,1,-4^"; // orange vertical bars

/*  }}} */

/* Workspace label functionality {{{1 */
/* The below are only used if the WorkspaceLabels functionality is enabled */
static char *occupied_workspace_label_format = "%s: %s"; /* format of a workspace label */
static char *vacant_workspace_label_format = "%s";       /* format of an empty / vacant workspace */
static int lowercase_workspace_labels = 1;               /* whether to change workspace labels to lower case */
/*  }}} */

/*  {{{ Patch options */
/* See util.h for options */
static unsigned long functionality = 0
//	|AutoReduceNmaster // automatically reduce the number of master clients if one is closed
	|SmartGaps // enables no or increased gaps if there is only one visible window
//	|SmartGapsMonocle // enforces no gaps in monocle layout
	|Systray // enables a systray in the bar
//	|SystrayNoAlpha // disables the use of transparency for the systray, enable if you do not use a compositor
	|Swallow // allows terminals to swallow X applications started from the command line
	|SwallowFloating // means swallow floating windows by default
	|CenteredWindowName // center the window titles on the bar
//	|BarActiveGroupBorderColor // use border color of active group, otherwise title scheme is used
	|BarMasterGroupBorderColor // use border color of master group, otherwise title scheme is used
	|FlexWinBorders // use the SchemeFlex* color schemes, falls back to SchemeTitle* if disabled
	|SpawnCwd // spawn applications in the currently selected client's working directory
	|ColorEmoji // enables color emoji support (removes Xft workaround)
//	|Status2DNoAlpha // option to not use alpha when drawing status2d status
	|BarBorder // draw a border around the bar
	|BarPadding // add vertical and side padding as per vertpad and sidepad variables above
//	|NoBorders // as per the noborder patch, show no border when only one client in tiled mode
//	|Warp // warp cursor to currently focused window
//	|FocusedOnTop // allows focused window to stay on top of other windows
	|DecorationHints // omit drawing the window border if the applications asks not to
	|FocusOnNetActive //  allow windows demanding attention to receive focus automatically
	|AllowNoModifierButtons // allow some window operations, like move and resize, to work without having to hold down a modifier key
	|CenterSizeHintsClients // center tiled clients subject to size hints within their tiled area
	|ResizeHints // respect size hints also when windows are tiled
	|SnapToWindows // snap to windows when moving floating clients
	|SortScreens // monitors are numbered from left to right
//	|ViewOnWs // follow a window to the workspace it is being moved to
	|Xresources // add support for changing colours via Xresources
	|Debug // enables additional debug output
//	|AltWorkspaceIcons // show the workspace name instead of the icons
//	|GreedyMonitor // disables swap of workspaces between monitors
	|SmartLayoutConvertion // automatically adjust layout based on monitor orientation when moving a workspace from one monitor to another
	|AutoHideScratchpads // automatically hide open scratchpads when moving to another workspace
//	|RioDrawIncludeBorders // indicates whether the area drawn using slop includes the window borders
//	|RioDrawSpawnAsync // spawn the application alongside rather than after drawing area using slop
//	|RestrictFocusstackToMonitor // restrict focusstack to only operate within the monitor, otherwise focus can drift between monitors
	|WinTitleIcons // adds application icons to window titles in the bar
//	|WorkspaceLabels // adds the class of the master client next to the workspace icon
	|WorkspacePreview // adds preview images when hovering workspace icons in the bar
;
/*  }}} */

/*  {{{ Bar indicator length for active windows */
static int flexwintitle_masterweight     = 30; // master weight compared to hidden and floating window titles
static int flexwintitle_stackweight      = 10;  // stack weight compared to hidden and floating window titles
static int flexwintitle_hiddenweight     = 8;  // hidden window title weight
static int flexwintitle_floatweight       = 0;  // floating window title weight, set to 0 to not show floating windows
static int flexwintitle_separator        = 0;  // width of client separator
/*  }}} */

/*{{{ Fonts */
static const char *fonts[]               = { "Go Mono Nerd Font:size=13" };
static const char dmenufont[]            = "Go Mono Nerd Font:size=16";
/*}}} */

/*{{{ Autostart */

static const char *const autostart[] = {
	//"st", NULL,
	"autostart-dusk", NULL, // apps to start /usr/share/local/bin
	NULL /* terminate */
};

/*}}} */

/*{{{ Struct */

/* There are two options when it comes to per-client rules:
 *  - a traditional struct table or
 *  - specifying the fields used
 *
 * A traditional struct table looks like this:*/

//          class  role   instance  title  wintype  opacity   flags   floatpos   scratchkey   workspace
//       { "Gimp", NULL,     NULL,   NULL,   NULL,       0,     0,     NULL,      NULL,        "4"        },
//{ "firefox", NULL,     NULL,   NULL,   NULL,       0,     0,     NULL,      NULL,        "2"        },

 // Alternatively you can specify the fields that are relevant to your rule, e.g.
 //
 //    { .class = "Gimp", .workspace = "5" },
 //   { .class = "firefox", .workspace = "9" },
 //
 // Any fields that you do not specify will default to 0 or NULL.
 //
 //Refer to the Rule struct definition for the list of available fields.
 //
//{ "Firefox",  NULL,       NULL,       1 << 8,       True,       -1 }//Change 1<<8 to 0.

static const Rule clientrules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */

	{ .wintype = WTYPE "DESKTOP", .flags = Unmanaged|Lower },
	{ .wintype = WTYPE "DOCK", .flags = Unmanaged|Raise },
	{ .wintype = WTYPE "DIALOG", .flags = AlwaysOnTop|Centered|Floating },
	{ .wintype = WTYPE "UTILITY", .flags = AlwaysOnTop|Centered|Floating },
	{ .wintype = WTYPE "TOOLBAR", .flags = AlwaysOnTop|Centered|Floating },
	{ .wintype = WTYPE "SPLASH", .flags = AlwaysOnTop|Centered|Floating },
	{ .wintype = "_KDE_NET_WM_WINDOW_TYPE_OVERRIDE", .flags = Unmanaged },
	{ .instance = "spterm (w)", .scratchkey = 'w', .flags = Floating },
	{ .instance = "spterm (e)", .scratchkey = 'e', .flags = Floating },
	{ .instance = "spterm (r)", .scratchkey = 'r', .flags = Floating|Centered|AlwaysOnTop, .floatpos = "40% 40%" },

	
    { .instance = "spfm (a)", .scratchkey = 'a', .flags = Floating },

    { .instance = "fzf", .flags = Floating|Centered|AlwaysOnTop },


//	{ .class = "firefox"       , .workspace = "NULL"  },
      //{ .class = "Steam"         , .flags = IgnoreCfgReqPos|Floating|Centered },
      //{ .class = "steam_app_"    , .flags = SteamGame|IgnoreCfgReqPos|Floating|Centered },
    { .class = "Google-chrome" , .role = "GtkFileChooserDialog", .floatpos = "50% 50%", .flags = AlwaysOnTop|Centered|Floating },
	{ .role = "pop-up"         , .flags = AlwaysOnTop|Floating|Centered },


   { .role = "GtkFileChooserDialog", .floatpos = "30% 30%", .flags = AlwaysOnTop|Centered },
   { .role = "gimp-file-chooser", .floatpos = "30% 30%", .flags = AlwaysOnTop|Centered },



	{ .class = "Gnome-terminal", .role = "gnome-terminal-preferences", .flags = Centered },
	{ .class = "Diffuse"       , .workspace = "4", .flags = NoSwallow|SwitchWorkspace|RevertWorkspace },
	{ .class = "File-roller"   , .workspace = "9", .flags = Centered|Floating|SwitchWorkspace|RevertWorkspace },
	{ .class = "Alacritty"     , .flags = Terminal|NoSwallow },
	{ .class = "kitty"         , .flags = Terminal },
    { .class = "urxvt"         , .flags = Terminal },
//	{ .class = "st"            , .flags = NoSwallow},
	{ .class = "st-256color"   , .flags = Terminal|AttachBottom },
	{ .class = "xterm-256color", .flags = Terminal },
	{ .class = "Xephyr"        , .flags = Floating|Centered },

    { .class = "Yad"           , .flags = Floating },
    { .class = "yad"           , .flags = Floating  },
    { .class = "Archlinux-logout.py", .flags = AlwaysOnTop|FullScreen },

    { .title = "Event Tester"  , .flags = NoSwallow },
    { .title = "Save Image"    , .flags = Floating|NoSwallow|Centered, .floatpos = "50% 50%" },
    { .title = "Dunst"         , .flags = AlwaysOnTop },
    { .class = "sxiv"          , .flags = AlwaysOnTop|Centered },
    { .class = "viewnior"      , .flags = AlwaysOnTop|Centered },

    { .class = "flameshot"     , .flags = AlwaysOnTop|Centered },
    { .class = "cherrytree"    , .flags = AlwaysOnTop|Centered },
    { .class = "gpick"         , .flags = Floating|AlwaysOnTop|Centered },
    { .class = "firefox"       , .flags = AttachBelow|OnlyModButtons|SwitchWorkspace, .workspace = "2" },

    
    { .class = "URxvt"         , .flags = Floating|Centered|AlwaysOnTop ,.floatpos = "-26x 26y" },
    
 //   { .class = "Leafpad", .floatpos = "50% 50%"  },

     { .class = "Leafpad",  .flags = SwitchWorkspace, .floatpos = "50% 50%", .workspace = "5"  },
//        class  role instance title wintype opac flags floatpos scratchkey worksp
	// class      role      instance  title  wintype  transient opacity   flags   floatpos   scratchkey   workspace   label       resume
};


/*}}} */

/* Define keys {{{1 */
#define Shift ShiftMask
#define Ctrl ControlMask
#define Alt Mod1Mask
#define AltGr Mod3Mask
#define Super Mod4Mask
#define ShiftGr Mod5Mask

#define MODKEY Super
#define ALTKEY Alt

#define SCRATCHKEYS(MOD,KEY,CMD) \
	{ KeyPress,   MOD,                      KEY,      togglescratch,       {.v = CMD } }, \
	{ KeyPress,   MOD|Ctrl,                 KEY,      setscratch,          {.v = CMD } }, \
	{ KeyPress,   MOD|Ctrl|Shift,           KEY,      removescratch,       {.v = CMD } }, \

#define WSKEYS(MOD,KEY,NAME) \
	{ KeyPress,   MOD,                      KEY,      comboviewwsbyname,   {.v = NAME} }, \
	{ KeyPress,   MOD|Shift,                KEY,      movetowsbyname,      {.v = NAME} }, \
	{ KeyPress,   MOD|Ctrl|Shift,           KEY,      movealltowsbyname,   {.v = NAME} }, \
	{ KeyPress,   MOD|Ctrl|Alt,             KEY,      moveallfromwsbyname, {.v = NAME} }, \
	{ KeyPress,   MOD|Ctrl,                 KEY,      swapwsbyname,        {.v = NAME} }, \
	{ KeyPress,   MOD|Alt,                  KEY,      enablewsbyname,      {.v = NAME} }, \

#define STACKKEYS(MOD,ACTION) \
	{ KeyPress,   MOD, XK_j, ACTION, {.i = INC(+1) } }, \
	{ KeyPress,   MOD, XK_k, ACTION, {.i = INC(-1) } }, \
	{ KeyPress,   MOD, XK_s, ACTION, {.i = PREVSEL } }, \
	{ KeyPress,   MOD, XK_w, ACTION, {.i = 0 } }, \
	{ KeyPress,   MOD, XK_e, ACTION, {.i = 1 } }, \
	{ KeyPress,   MOD, XK_a, ACTION, {.i = 2 } }, \
	{ KeyPress,   MOD, XK_z, ACTION, {.i = -1 } },

/*}}}*/

/*  Assign Programs  {{{*/

/* Helper macros for spawning commands */
#define SHCMD(cmd) { .v = (const char*[]){ NULL, "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ NULL, __VA_ARGS__, NULL } }

/* Scratch/Spawn commands:        NULL (scratchkey), command, argument, argument, ..., NULL */
//static const char *termcmd[]  = { NULL, "st", NULL };

static const char *termcmd[]    = { NULL, "kitty","--config","/home/trg/.config/kitty.d/core-primary.conf", NULL };
static const char *term2cmd[]   = { NULL, "kitty","--config","/home/trg/.config/kitty.d/core-secondary.conf", NULL };
static const char *fmcmd[]      = { NULL, "spacefm", NULL };
static const char *notecmd[]    = { NULL, "leafpad", NULL };


//static const char *sshotcmd[] = { ".scripts/flameshot.sh", NULL };
//static const char *screenshotcmd[] = { NULL, "./scripts/sshot-generic.sh", NULL };

static const char *dmenucmd[] = {
	NULL,
	"dmenu_run",
	"-fn", dmenufont,
	"-nb", dmenunormbgcolor,
	"-nf", dmenunormfgcolor,
	"-sb", dmenuselbgcolor,
	"-sf", dmenuselfgcolor,
	NULL
};


static const char *spcmd_w[] = {"w","kitty","--name","spterm (w)","--config","/home/trg/.config/kitty.d/core-scratch-pri.conf",NULL };
static const char *spcmd_e[] = {"e","kitty","--name","spterm (e)","--config","/home/trg/.config/kitty.d/core-scratch-sec.conf",NULL };
static const char *spcmd_r[] = {"r","cherrytree","--name","spterm (r)",NULL };

static const char *spcmd_a[] = {"a", "kitty", "--name", "spfm (a)", "--config","/home/trg/.config/kitty.d/core-ranger.conf", "-e","ranger", NULL };

//static const char *spcmd_a[] = {"a", "st"    , "-n",     "spfm (a)" , "-g", "144x41", "-e", "ranger", NULL };
//static const char *spcmd_a[] = {"a", "kitty"    , "--name","spfm (a)","-e","ranger", NULL };

static const char *statusclickcmd[] = { NULL, "/home/trg/.config/dusk/scripts/statusbar/statusclick.sh", NULL };

static const char *clientmenu[] = { NULL, "/home/trg/.config/dusk/scripts/menu/client", NULL };

static const char *layoutmenu[] = { NULL, "/home/trg/.config/dusk/scripts/menu/layout", NULL };

static const char *powermenu[] = { NULL, "/home/trg/.config/dusk/scripts/menu/power", NULL };

static const char *rootmenu[] = { NULL, "/home/trg/.config/dusk/scripts/menu/root", NULL };
/*  }}} */

/* Keybinds {{{1 */
// START_KEYS
static Key keys[] = {

    /* ALTKEY *//*{{{*/
	/* type       modifier                      key              function                argument */
  //  { KeyPress,   ALTKEY,                       XK_f,            spawn,                  {.v = browsercmd } },   // draw/spawn a web firefox
    { KeyPress,   Alt,                       XK_e,            spawn,                  {.v = fmcmd } },        // draw/spawn a file manager
    { KeyPress,   ALTKEY,                       XK_n,            spawn,                  {.v = notecmd } },      // draw/spawn a notepad
/*}}}*/

/*   MODKEY *//*{{{*/
{ KeyPress,   MODKEY,            XK_d,            spawn,                  {.v = dmenucmd } },  /*spawn dmenu for launching other programs */
//{ KeyPress,   MODKEY,            XK_c,            spawn,                  {.v = emacscmd } }, // draw/spawn a emacs
{ KeyPress,   MODKEY,            XK_b,            togglebar,              {0} }, // toggles the display of the bar(s) on the current monitor
{ KeyPress,   MODKEY,            XK_z,            showhideclient,         {0} }, // hide the currently selected client (or show if hidden)
{ KeyPress,   MODKEY,            XK_c,            killclient,             {0} }, // close the currently focused window
{ KeyPress,   MODKEY,            XK_v,            group,                  {0} }, // groups floating clients together
{ KeyPress,   MODKEY,            XK_m,            togglemark,             {0} }, // marks or unmarks the selected client for group action
{ KeyPress,   MODKEY,            XK_n,            zoom,                   {0} }, // moves the currently focused window to/from the master area (for tiled layouts)
{ KeyPress,   MODKEY,            XK_g,            togglefloating,         {0} }, // toggles between tiled and floating arrangement for the currently focused client
{ KeyPress,   MODKEY,            XK_f,            togglefullscreen,       {0} }, // toggles fullscreen for the currently selected client
{ KeyPress,   MODKEY,            XK_j,            focusstack,             {.i = +1 } }, // focus on the next client in the stack
{ KeyPress,   MODKEY,            XK_k,            focusstack,             {.i = -1 } }, // focus on the previous client in the stack
{ KeyPress,   MODKEY,            XK_i,            incnmaster,             {.i = +1 } }, // increase the number of clients in the master area
{ KeyPress,   MODKEY,            XK_u,            incnmaster,             {.i = -1 } }, // decrease the number of clients in the master area
{ KeyPress,   MODKEY,            XK_o,            viewselws,              {0} },        // view the selected workspace (only relevant when viewing multiple workspaces)
{ KeyPress,   MODKEY,            XK_0,            viewalloccwsonmon,      {0} },        // view all workspaces on the current monitor that has clients
{ KeyPress,   MODKEY,            XK_h,            setmfact,               {.f = -0.05} }, // decrease the size of the master area compared to the stack area(s)
{ KeyPress,   MODKEY,            XK_l,            setmfact,               {.f = +0.05} }, // increase the size of the master area compared to the stack area(s)
//{ KeyPress,   MODKEY,            XK_a,            markall,                {0} }, // marks all clients on the selected workspace


{ KeyPress,   MODKEY,            XK_comma,        viewwsdir,              {.i = -2 } }, // view the next workspace left of current workspace that has clients (on the current monitor)
{ KeyPress,   MODKEY,            XK_period,       viewwsdir,              {.i = +2 } }, // view the next workspace right of current workspace that has clients (on the current monitor)
//{ KeyPress,   MODKEY,            XK_backslash,    togglepinnedws,         {0} }, // toggle pinning of currently selected workspace on the current monitor
{ KeyPress,   MODKEY,            XK_bracketleft,  rotatelayoutaxis,       {.i = -1 } }, // cycle through the available layout splits (horizontal, vertical, centered, no split, etc.)
{ KeyPress,   MODKEY,            XK_bracketright, rotatelayoutaxis,       {.i = +1 } }, // cycle through the available layout splits (horizontal, vertical, centered, no split, etc.)
{ KeyPress,   MODKEY,            XK_Tab,          viewwsdir,              {.i = +2 } }, // view the next workspace right of current workspace that has clients (on the current monitor)
{ KeyPress,   MODKEY,            XK_space,        setlayout,              {0} }, // toggles between current and previous layout
{ KeyPress,   MODKEY,            XK_Return,       spawn,                  {.v = termcmd } }, // spawn a terminal
//{ KeyPress,   MODKEY,            XK_Print,        spawn,                  {.v = screenshotcmd } },  /*spawn dmenu for launching other programs */


    /*}}}*/

/*   MODKEY|Shift *//*{{{*/
{ KeyPress,   MODKEY|Shift,      XK_r,            restart,                {0} }, // restart dusk
{ KeyPress,   MODKEY|Shift,      XK_a,            unmarkall,              {0} }, // unmarks all clients
{ KeyPress,   MODKEY|Shift,      XK_v,            ungroup,                {0} }, // ungroups floating clients
{ KeyPress,   MODKEY|Shift,      XK_f,            togglefakefullscreen,   {0} }, // toggles "fake" fullscreen for the selected window
{ KeyPress,   MODKEY|Shift,      XK_h,            setcfact,               {.f = +0.25} }, // increase size respective to other windows within the same area
{ KeyPress,   MODKEY|Shift,      XK_l,            setcfact,               {.f = -0.25} }, // decrease client size respective to other windows within the same area
{ KeyPress,   MODKEY|Shift,      XK_o,            setcfact,               {0} },
{ KeyPress,   MODKEY|Shift,      XK_Return,       spawn,                  {.v = term2cmd } }, // draw/spawn menu
{ KeyPress,   MODKEY|Shift,      XK_plus,         changeopacity,          {.f = +0.05 } }, // increase the client opacity (for compositors that support _NET_WM_OPACITY)
{ KeyPress,   MODKEY|Shift,      XK_minus,        changeopacity,          {.f = -0.05 } }, // decrease the client opacity (for compositors that support _NET_WM_OPACITY)
{ KeyPress,   MODKEY|Shift,      XK_comma,        focusmon,               {.i = -1 } }, // focus on the previous monitor, if any
{ KeyPress,   MODKEY|Shift,      XK_period,       focusmon,               {.i = +1 } }, // focus on the next monitor, if any
{ KeyPress,   MODKEY|Shift,      XK_Tab,          viewwsdir,              {.i = -2 } }, // view the next workspace left of current workspace that has clients (on the current monitor)
{ KeyPress,   MODKEY|Shift,      XK_bracketleft,  rotatelayoutaxis,       {.i = -3 } }, // cycle through the available tiling arrangements for the primary (first) stack area
{ KeyPress,   MODKEY|Shift,      XK_bracketright, rotatelayoutaxis,       {.i = +3 } }, // cycle through the available tiling arrangements for the primary (first) stack area
/*}}}*/

/*   MODKEY|Alt *//*{{{*/
{ KeyPress,   MODKEY|Alt,        XK_comma,        clienttomon,            {.i = -1 } }, // sends the current client to an adjacent monitor
{ KeyPress,   MODKEY|Alt,        XK_period,       clienttomon,            {.i = +1 } }, // sends the current client to an adjacent monitor
{ KeyPress,   MODKEY|Alt,        XK_a,            markall,                {2} }, // marks all hidden clients on the selected workspace
{ KeyPress,   MODKEY|Alt,        XK_space,        spawn,                  {.v = termcmd } }, // draw/spawn default terminal
{ KeyPress,   MODKEY|Alt,        XK_bracketleft,  rotatelayoutaxis,       {.i = -2 } }, // cycle through the available tiling arrangements for the master area
{ KeyPress,   MODKEY|Alt,        XK_bracketright, rotatelayoutaxis,       {.i = +2 } }, // cycle through the available tiling arrangements for the master area
/*}}}*/

/*   MODKEY|Ctrl *//*{{{*/
{ KeyPress,   MODKEY|Ctrl,       XK_0,            viewallwsonmon,         {0} },        // view all workspaces on the current monitor
{ KeyPress,   MODKEY|Ctrl,       XK_a,            markall,                {1} }, // marks all floating clients on the selected workspace
{ KeyPress,   MODKEY|Ctrl,       XK_j,            pushdown,               {0} }, // move the selected client down the stack
{ KeyPress,   MODKEY|Ctrl,       XK_k,            pushup,                 {0} }, // move the selected client up the stack
{ KeyPress,   MODKEY|Ctrl,       XK_i,            incnstack,              {.i = +1 } }, // increase the number of clients in the primary (first) stack area
{ KeyPress,   MODKEY|Ctrl,       XK_u,            incnstack,              {.i = -1 } }, // increase the number of clients in the primary (first) stack area
{ KeyPress,   MODKEY|Ctrl,       XK_g,            floatpos,               {.v = "45% 45% 70% 70%" } }, // center client and take up 80% of the screen
{ KeyPress,   MODKEY|Ctrl,       XK_m,            mirrorlayout,           {0} }, // flip the master and stack areas
{ KeyPress,   MODKEY|Ctrl,       XK_comma,        viewwsdir,              {.i = -1 } }, // view the workspace on the immediate left of current workspace (on the current monitor)
{ KeyPress,   MODKEY|Ctrl,       XK_period,       viewwsdir,              {.i = +1 } }, // view the workspace on the immediate right of current workspace (on the current monitor)
{ KeyPress,   MODKEY|Ctrl,       XK_bracketleft,  rotatelayoutaxis,       {.i = -4 } }, // cycle through the available tiling arrangements for the secondary stack area
{ KeyPress,   MODKEY|Ctrl,       XK_bracketright, rotatelayoutaxis,       {.i = +4 } }, // cycle through the available tiling arrangements for the secondary stack area
/*}}}za*/

/*   MODKEY|Ctrl|Shift *//*{{{*/
{ KeyPress,   MODKEY|Ctrl|Shift, XK_m,            layoutconvert,          {0} }, // flip between horizontal and vertical layout
/*}}}*/

/*    MODKEY|Alt|Shift *//*{{{*/
{ KeyPress,   MODKEY|Alt|Shift,  XK_j,            focusstack,             {.i = +2 } }, // allows focusing on hidden clients
{ KeyPress,   MODKEY|Alt|Shift,  XK_k,            focusstack,             {.i = -2 } }, // allows focusing on hidden clients
{ KeyPress,   MODKEY|Alt|Shift,  XK_comma,        clientstomon,           {.i = +1 } }, // sends all clients to an adjacent monitor
{ KeyPress,   MODKEY|Alt|Shift,  XK_period,       clientstomon,           {.i = -1 } }, // sends all clients to an adjacent monitor
/*}}}*/

/*   MODKEY|Ctrl|Alt *//*{{{*/
{ KeyPress,   MODKEY|Ctrl|Alt,   XK_q,            quit,                   {0} }, // exit dusk
{ KeyPress,   MODKEY|Ctrl|Alt,   XK_comma,        movewsdir,              {.i = -1 } }, // move client to workspace on the immediate left of current workspace (on the current monitor)
{ KeyPress,   MODKEY|Ctrl|Alt,   XK_period,       movewsdir,              {.i = +1 } }, // move client to workspace on the immediate right of current workspace (on the current monitor)
/*}}}*/

/*   MODKEY|ControlMask *//*{{{*/
{ KeyPress,   ControlMask,          XK_Left,   placedir, {.i = 0 } }, // swap  client window on the immediate left of the current client
{ KeyPress,   ControlMask,          XK_Right,  placedir, {.i = 1 } }, // swap  client window on the immediate right of the current client
{ KeyPress,   ControlMask,          XK_Up,     placedir, {.i = 2 } }, // swap  client window on the immediate up of the current client
{ KeyPress,   ControlMask,          XK_Down,   placedir, {.i = 3 } }, // swap  client window on the immediate down of the current client

{ KeyPress,   ALTKEY,               XK_Left,   focusdir, {.i = 0 } }, // focus on the client left of the currently focused client
{ KeyPress,   ALTKEY,               XK_Right,  focusdir, {.i = 1 } }, // focus on the client right of the currently focused client
{ KeyPress,   ALTKEY,               XK_Up,     focusdir, {.i = 2 } }, // focus on the client above the currently focused client
{ KeyPress,   ALTKEY,               XK_Down,   focusdir, {.i = 3 } }, // focus on the client below the currently focuse
/*}}}*/


// END_KEYS


/*  Stack keys  *//*{{{*/
//	STACKKEYS(AltGr|Ctrl,                             stackfocus)                           // focus on the nth client in the stack, see the STACKKEYS macro for keybindings
//	STACKKEYS(AltGr|Ctrl|Shift,                       stackpush)                            // move the currently focused client to the nth place in the stack
/*}}}*/

/*  Scratch keys  *//*{{{*/
    SCRATCHKEYS(MODKEY,              XK_w,            spcmd_w)
	SCRATCHKEYS(MODKEY,              XK_e,            spcmd_e)
	SCRATCHKEYS(MODKEY,              XK_r,            spcmd_r)
	SCRATCHKEYS(MODKEY,              XK_a,            spcmd_a)
//	SCRATCHKEYS(MODKEY,              XK_s,            spcmd_s)
/*}}}*/

/*  WS Keys *//*{{{{{{*/
    WSKEYS(MODKEY,                   XK_1,            "1")
	WSKEYS(MODKEY,                   XK_2,            "2")
	WSKEYS(MODKEY,                   XK_3,            "3")
	WSKEYS(MODKEY,                   XK_4,            "4")
	WSKEYS(MODKEY,                   XK_5,            "5")
	WSKEYS(MODKEY,                   XK_6,            "6")
	WSKEYS(MODKEY,                   XK_7,            "7")
	WSKEYS(MODKEY,                   XK_8,            "8")
	WSKEYS(MODKEY,                   XK_9,            "9")
/*}}}}}}*/

/* Unassigned key bindings (available externally via the duskc command) *//*{{{*/

//	{ KeyPress,   MODKEY,                       XK_Control_R,    showbar,                {0} },
//	{ KeyRelease, MODKEY|AltGr,                 XK_Control_R,    hidebar,                {0} },
//	{ KeyPress,   MODKEY,                       XK_,             incrgaps,               {.i = +1 } }, // increase all gaps (outer, inner, horizontal and vertical)
//	{ KeyPress,   MODKEY,                       XK_,             incrgaps,               {.i = -1 } }, // decrease all gaps (outer, inner, horizontal and vertical)
//	{ KeyPress,   MODKEY,                       XK_,             incrigaps,              {.i = +1 } }, // increase inner gaps (horizontal and vertical)
//	{ KeyPress,   MODKEY,                       XK_,             incrigaps,              {.i = -1 } }, // decrease inner gaps (horizontal and vertical)
//	{ KeyPress,   MODKEY,                       XK_,             incrogaps,              {.i = +1 } }, // increase outer gaps (horizontal and vertical)
//	{ KeyPress,   MODKEY,                       XK_,             incrogaps,              {.i = -1 } }, // decrease outer gaps (horizontal and vertical)
//	{ KeyPress,   MODKEY,                       XK_,             incrihgaps,             {.i = +1 } }, // increase inner horizontal gaps
//	{ KeyPress,   MODKEY,                       XK_,             incrihgaps,             {.i = -1 } }, // decrease inner horizontal gaps
//	{ KeyPress,   MODKEY,                       XK_,             incrivgaps,             {.i = +1 } }, // increase inner vertical gaps
//	{ KeyPress,   MODKEY,                       XK_,             incrivgaps,             {.i = -1 } }, // decrease inner vertical gaps
//	{ KeyPress,   MODKEY,                       XK_,             incrohgaps,             {.i = +1 } }, // increase outer horizontal gaps
//	{ KeyPress,   MODKEY,                       XK_,             incrohgaps,             {.i = -1 } }, // decrease outer horizontal gaps
//	{ KeyPress,   MODKEY,                       XK_,             incrovgaps,             {.i = +1 } }, // increase outer vertical gaps
//	{ KeyPress,   MODKEY,                       XK_,             incrovgaps,             {.i = -1 } }, // decrease outer vertical gaps
//	{ KeyPress,   MODKEY,                       XK_,             mark,                   {0} }, // marks the currently selected client
//	{ KeyPress,   MODKEY,                       XK_,             unmark,                 {0} }, // unmarks the currently selected client
//	{ KeyPress,   MODKEY,                       XK_,             togglegaps,             {0} }, // enables and disables the rendering of gaps in tiled layouts
//	{ KeyPress,   MODKEY,                       XK_,             defaultgaps,            {0} }, // revert gaps to the default settings
//	{ KeyPress,   MODKEY,                       XK_,             cyclelayout,            {.i = -1 } }, // cycle through the available layouts
//	{ KeyPress,   MODKEY,                       XK_,             cyclelayout,            {.i = +1 } }, // cycle through the available layouts (in reverse)
//	{ KeyPress,   MODKEY,                       XK_,             viewwsdir,              {.i = -1 } }, // move to the workspace on the immediate left of the current workspace on the current monitor (wraps around)
//	{ KeyPress,   MODKEY,                       XK_,             viewwsdir,              {.i = +1 } }, // move to the workspace on the immediate right of the current workspace on the current monitor (wraps around)
//	{ KeyPress,   MODKEY,                       XK_,             focusmaster,            {0} }, // change focus to the first client in the stack (master)
//	{ KeyPress,   MODKEY,                       XK_,             transfer,               {0} }, // move a client between the master and stack area automatically adjusting nmaster
//	{ KeyPress,   MODKEY,                       XK_,             transferall,            {0} }, // swaps all clients in the stack area with all clients in the master area
//	{ KeyPress,   MODKEY,                       XK_,             togglesticky,           {0} }, // makes a client show on all workspaces)
//	{ KeyPress,   MODKEY,                       XK_,             focusurgent,            {0} }, // focus on the client marked as urgent
//	{ KeyPress,   MODKEY,                       XK_,             inplacerotate,          {.i = +1} }, // rotate clients within the respective area (master, primary stack, secondary stack) clockwise
//	{ KeyPress,   MODKEY,                       XK_,             inplacerotate,          {.i = -1} }, // rotate clients within the respective area (master, primary stack, secondary stack) counter-clockwise
//	{ KeyPress,   MODKEY,                       XK_,             rotatestack,            {.i = +1 } }, // rotate all clients (clockwise)
//	{ KeyPress,   MODKEY,                       XK_,             rotatestack,            {.i = -1 } }, // rotate all clients (counter-clockwise)
//	{ KeyPress,   MODKEY,                       XK_,             riodraw,                {0} }, // use slop to resize the currently selected client
//	{ KeyPress,   MODKEY,                       XK_,             unfloatvisible,         {0} }, // makes all floating clients on the currently selected workspace tiled
//	{ KeyPress,   MODKEY,                       XK_,             switchcol,              {0} }, // changes focus between the master and the primary stack area
//	{ KeyPress,  MODKEY|Alt,                    XK_r,             xrdb,                   {0 } }, // reloads colors fron XResources
/*}}}*/

/*  Extras  *//*{{{*/ // sets a specific layout, see the layouts array for indices
    { KeyPress,  MODKEY|Alt,  XK_F1,   setlayout,  {.v = &layouts[1]} },
    { KeyPress,  MODKEY|Alt,  XK_F2,   setlayout,  {.v = &layouts[2]} },
    { KeyPress,  MODKEY|Alt,  XK_F3,   setlayout,  {.v = &layouts[3]} },
    { KeyPress,  MODKEY|Alt,  XK_F4,   setlayout,  {.v = &layouts[4]} },
    { KeyPress,  MODKEY|Alt,  XK_F5,   setlayout,  {.v = &layouts[5]} },
    { KeyPress,  MODKEY|Alt,  XK_F6,   setlayout,  {.v = &layouts[6]} },
    { KeyPress,  MODKEY|Alt,  XK_F7,   setlayout,  {.v = &layouts[7]} },
    { KeyPress,  MODKEY|Alt,  XK_F8,   setlayout,  {.v = &layouts[8]} },
    { KeyPress,  MODKEY|Alt,  XK_F9,   setlayout,  {.v = &layouts[9]} },
    { KeyPress,  MODKEY|Alt,  XK_F10,  setlayout,  {.v = &layouts[10]}},
    { KeyPress,  MODKEY|Alt,  XK_F11,  setlayout,  {.v = &layouts[11]}},
    { KeyPress,  MODKEY|Alt,  XK_F12,  setlayout,  {.v = &layouts[12]}},





    /*}}}*/


};

/* Click Buttons *//*{{{*/
/* click can be ClkWorkspaceBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  
    { ClkRootWin,                0,                       Button3,        spawn,            {.v = rootmenu } },

    { ClkClientWin,     MODKEY|Alt,                       Button3,        spawn,            {.v = clientmenu } },
    /* click                     event mask               button          function          argument */
    { ClkLtSymbol,               0,                       Button3,        spawn,            {.v = layoutmenu } },

    { ClkPower,                  0,                       Button3,        spawn,            {.v = powermenu } },
	
//    { ClkLtSymbol,               0,                       Button4,        setlayout,        {0} }, // toggles between current and previous layout

    { ClkLtSymbol,               MODKEY,                  Button1,        cyclelayout,      {.i = -1 } }, // cycle through the available layouts (in reverse)
	{ ClkLtSymbol,               0,                       Button1,        cyclelayout,      {.i = +1 } }, // cycle through the available layouts

    { ClkWinTitle,               0,                       Button1,        focuswin,         {0} }, // focus on the given client
	{ ClkWinTitle,               0,                       Button3,        showhideclient,   {0} }, // hide the currently selected client (or show if hidden)
//	{ ClkWinTitle,               0,                       Button2,        zoom,             {0} }, // moves the currently focused window to/from the master area (for tiled layouts)
	{ ClkStatusText,             0,                       Button1,        statusclick,      {.i = 1 } }, // sends mouse button presses to statusclick script when clicking on status modules
	{ ClkStatusText,             0,                       Button8,        statusclick,      {.i = 2 } },
	{ ClkStatusText,             0,                       Button3,        statusclick,      {.i = 3 } },
	{ ClkStatusText,             0,                       Button4,        statusclick,      {.i = 4 } },
	{ ClkStatusText,             0,                       Button5,        statusclick,      {.i = 5 } },
	{ ClkStatusText,             0,                       Button6,        statusclick,      {.i = 6 } },
	{ ClkStatusText,             0,                       Button7,        statusclick,      {.i = 7 } },
	{ ClkStatusText,             0,                       Button8,        statusclick,      {.i = 8 } },
	{ ClkStatusText,             0,                       Button9,        statusclick,      {.i = 9 } },
	{ ClkStatusText,             Shift,                   Button1,        statusclick,      {.i = 10 } },
	{ ClkStatusText,             Shift,                   Button2,        statusclick,      {.i = 11 } },
	{ ClkStatusText,             Shift,                   Button3,        statusclick,      {.i = 12 } },
	{ ClkClientWin,              MODKEY,                  Button8,        markmouse,        {1} }, // toggles marking of clients under the mouse cursor for group action
//	{ ClkClientWin,              MODKEY,                  Button9,        markmouse,        {0} }, // unmarks clients under the mouse cursor
	{ ClkClientWin,              MODKEY,                  Button1,        moveorplace,      {1} }, // moves a client window into a floating or tiled position depending on floating state
	{ ClkClientWin,              MODKEY|Shift,            Button1,        movemouse,        {0} }, // moves a floating window, if the window is tiled then it will snap out to become floating
	{ ClkClientWin,              MODKEY|Alt,              Button2,        togglefloating,   {0} }, // toggles between tiled and floating arrangement for given client
	{ ClkClientWin,              MODKEY,                  Button3,        resizeorcfacts,   {0} }, // change the size of a floating client window or adjust cfacts (dragcfact) when tiled
	{ ClkClientWin,              MODKEY|Shift,            Button3,        resizemouse,      {0} }, // change the size of a floating client window
//	{ ClkClientWin,              0,                       Button8,        movemouse,        {0} }, // move a client window using extra mouse buttons (previous)
//	{ ClkClientWin,              0,                       Button9,        resizemouse,      {0} }, // resize a client window using extra mouse buttons (next)
	{ ClkClientWin,              MODKEY,                  Button2,        zoom,             {0} }, // moves the currently focused window to/from the master area (for tiled layouts)
//	{ ClkClientWin,              MODKEY|Ctrl,             Button1,        dragmfact,        {0} }, // dynamically change the size of the master area compared to the stack area(s)
//	{ ClkRootWin,                MODKEY|Ctrl,             Button1,        dragmfact,        {0} }, // dynamically change the size of the master area compared to the stack area(s)
	{ ClkClientWin,              MODKEY,                  Button4,        inplacerotate,    {.i = +1 } }, // rotate clients within the respective area (master, primary stack, secondary stack) clockwise
	{ ClkClientWin,              MODKEY,                  Button5,        inplacerotate,    {.i = -1 } }, // rotate clients within the respective area (master, primary stack, secondary stack) counter-clockwise
	{ ClkClientWin,              MODKEY|Shift,            Button4,        rotatestack,      {.i = +1 } }, // rotate all clients (clockwise)
	{ ClkClientWin,              MODKEY|Shift,            Button5,        rotatestack,      {.i = -1 } }, // rotate all clients (counter-clockwise)
	{ ClkWorkspaceBar,           0,                       Button1,        viewws,           {0} }, // view the workspace by clicking on workspace icon
	{ ClkWorkspaceBar,           MODKEY,                  Button1,        movews,           {0} }, // sends (moves) the currently focused client to given workspace
	{ ClkWorkspaceBar,           MODKEY|Shift|Ctrl,       Button1,        swapws,           {0} }, // swaps all clients on current workspace with that of the given workspace
//	{ ClkWorkspaceBar,           0,                       Button3,        enablews,         {0} }, // enables the workspace in addition to other workspaces
	{ ClkWorkspaceBar,           0,                       Button4,        viewwsdir,        {.i = +2 } }, // view the next workspace right of current workspace that has clients (on the current monitor)
	{ ClkWorkspaceBar,           0,                       Button5,        viewwsdir,        {.i = -2 } }, // view the next workspace left of current workspace that has clients (on the current monitor)
	{ ClkWorkspaceBar,           MODKEY,                  Button2,        togglepinnedws,   {0} }, // toggles the pinning of a workspace to the current monitor
};




/*{{{ IPCCommand */

static const char *ipcsockpath = "/tmp/dusk.sock";
static IPCCommand ipccommands[] = {
	IPCCOMMANDS( customlayout, 8, ARG_TYPE_SINT, ARG_TYPE_STR, ARG_TYPE_SINT, ARG_TYPE_SINT, ARG_TYPE_SINT, ARG_TYPE_SINT, ARG_TYPE_SINT, ARG_TYPE_SINT ),
	IPCCOMMAND( changeopacity, ARG_TYPE_FLOAT ),
	IPCCOMMAND( clienttomon, ARG_TYPE_SINT ),
	IPCCOMMAND( clientstomon, ARG_TYPE_SINT ),
	IPCCOMMAND( cyclelayout, ARG_TYPE_SINT ),
	IPCCOMMAND( enable, ARG_TYPE_STR ),
	IPCCOMMAND( enablewsbyname, ARG_TYPE_STR ),
	IPCCOMMAND( defaultgaps, ARG_TYPE_NONE ),
	IPCCOMMAND( disable, ARG_TYPE_STR ),
	IPCCOMMAND( floatpos, ARG_TYPE_STR ),
	IPCCOMMAND( focusdir, ARG_TYPE_SINT ),
	IPCCOMMAND( focusmaster, ARG_TYPE_NONE ),
	IPCCOMMAND( focusmon, ARG_TYPE_SINT ),
	IPCCOMMAND( focusstack, ARG_TYPE_SINT ),
	IPCCOMMAND( focusurgent, ARG_TYPE_NONE ),
	IPCCOMMAND( hidebar, ARG_TYPE_NONE ),
	IPCCOMMAND( incrgaps, ARG_TYPE_SINT ),
	IPCCOMMAND( incrigaps, ARG_TYPE_SINT ),
	IPCCOMMAND( incrogaps, ARG_TYPE_SINT ),
	IPCCOMMAND( incrihgaps, ARG_TYPE_SINT ),
	IPCCOMMAND( incrivgaps, ARG_TYPE_SINT ),
	IPCCOMMAND( incrohgaps, ARG_TYPE_SINT ),
	IPCCOMMAND( incrovgaps, ARG_TYPE_SINT ),
	IPCCOMMAND( incnmaster, ARG_TYPE_SINT ),
	IPCCOMMAND( incnstack, ARG_TYPE_SINT ),
	IPCCOMMAND( inplacerotate, ARG_TYPE_SINT ),
	IPCCOMMAND( killclient, ARG_TYPE_NONE ),
	IPCCOMMAND( killunsel, ARG_TYPE_NONE ),
	IPCCOMMAND( layoutconvert, ARG_TYPE_NONE ),
	IPCCOMMAND( mark, ARG_TYPE_NONE ),
	IPCCOMMAND( markall, ARG_TYPE_SINT ), // 0 = mark all, 1 = mark floating, 2 = mark hidden
	IPCCOMMAND( mirrorlayout, ARG_TYPE_NONE ),
	IPCCOMMAND( movetowsbyname, ARG_TYPE_STR ),
	IPCCOMMAND( movealltowsbyname, ARG_TYPE_STR ),
	IPCCOMMAND( moveallfromwsbyname, ARG_TYPE_STR ),
	IPCCOMMAND( movewsdir, ARG_TYPE_SINT ),
	IPCCOMMAND( rotatelayoutaxis, ARG_TYPE_SINT ),
	IPCCOMMAND( rotatestack, ARG_TYPE_SINT ),
	IPCCOMMAND( placedir, ARG_TYPE_SINT ),
	IPCCOMMAND( pushdown, ARG_TYPE_NONE ),
	IPCCOMMAND( pushup, ARG_TYPE_NONE ),
	IPCCOMMAND( quit, ARG_TYPE_NONE ),
	IPCCOMMAND( restart, ARG_TYPE_NONE ),
	IPCCOMMAND( rioresize, ARG_TYPE_NONE ),
	IPCCOMMAND( setattachdefault, ARG_TYPE_STR),
	IPCCOMMAND( setborderpx, ARG_TYPE_SINT ),
	IPCCOMMAND( setlayoutaxisex, ARG_TYPE_SINT ),
	IPCCOMMAND( setlayoutex, ARG_TYPE_SINT ),
	IPCCOMMAND( setlayoutsafe, ARG_TYPE_PTR ),
	IPCCOMMAND( setcfact, ARG_TYPE_FLOAT ),
	IPCCOMMAND( setmfact, ARG_TYPE_FLOAT ),
	IPCCOMMAND( setgapsex, ARG_TYPE_SINT ),
	IPCCOMMANDS( setstatus, 2, ARG_TYPE_UINT, ARG_TYPE_STR ),
	IPCCOMMAND( showbar, ARG_TYPE_NONE ),
	IPCCOMMAND( showhideclient, ARG_TYPE_NONE ),
	IPCCOMMAND( stackpush, ARG_TYPE_SINT ),
	IPCCOMMAND( stackfocus, ARG_TYPE_SINT ),
	IPCCOMMAND( switchcol, ARG_TYPE_NONE ),
	IPCCOMMAND( swapwsbyname, ARG_TYPE_STR ),
	IPCCOMMAND( toggle, ARG_TYPE_STR ), // toggle functionality on and off
	IPCCOMMAND( togglebar, ARG_TYPE_NONE ),
	IPCCOMMAND( togglebarpadding, ARG_TYPE_NONE ),
	IPCCOMMAND( toggleclientflag, ARG_TYPE_STR ),
	IPCCOMMAND( togglefakefullscreen, ARG_TYPE_NONE ),
	IPCCOMMAND( togglefloating, ARG_TYPE_NONE ),
	IPCCOMMAND( togglefullscreen, ARG_TYPE_NONE ),
	IPCCOMMAND( togglegaps, ARG_TYPE_NONE ),
	IPCCOMMAND( togglemark, ARG_TYPE_NONE ),
	IPCCOMMAND( togglenomodbuttons, ARG_TYPE_NONE ),
	IPCCOMMAND( togglepinnedws, ARG_TYPE_NONE ),
	IPCCOMMAND( togglesticky, ARG_TYPE_NONE ),
	IPCCOMMAND( transfer, ARG_TYPE_NONE ),
	IPCCOMMAND( transferall, ARG_TYPE_NONE ),
	IPCCOMMAND( unfloatvisible, ARG_TYPE_NONE ),
	IPCCOMMAND( unmark, ARG_TYPE_NONE ),
	IPCCOMMAND( unmarkall, ARG_TYPE_NONE ),
	IPCCOMMAND( viewallwsonmon, ARG_TYPE_NONE ),
	IPCCOMMAND( viewalloccwsonmon, ARG_TYPE_NONE ),
	IPCCOMMAND( viewselws, ARG_TYPE_NONE ),
	IPCCOMMAND( viewwsbyname, ARG_TYPE_STR ),
	IPCCOMMAND( viewwsdir, ARG_TYPE_SINT ),
	IPCCOMMAND( xrdb, ARG_TYPE_NONE ), // reload xrdb / Xresources
	IPCCOMMAND( zoom, ARG_TYPE_NONE ),
};


/*}}} */
