
// DUSK BAR CONFIGURATION FILE
/* vim: set foldmethod=marker: */

/* Bar */

/* Bar settings, this defines what bars exists, their position, and what attributes they have.
 *
 *    monitor - the exact monitor number the bar should be created on
 *              (0 - primary, 1 - secondary, 2 - tertiary)
 *    idx     - the bar index, used in relation to bar rules below
 *              (bar indexes can be reused across monitors)
 *    vert    - whether the bar is horizontal (0) or vertical (1), not
 *              all bar modules will have support for being displayed
 *              in a vertical bar
 *    name    - this is just a reference tat can be used for logging
 *              purposes
 *
 *    Bar positioning consists of four values, x, y, w and h which,
 *    similarly to floatpos, can have different meaning depending on
 *    the characters used. Absolute positioning (as in cross-monitor)
 *    is not supported, but exact positions relative to the monitor
 *    can be used. Percentage values are recommended for portability.
 *
 *    All values can be a percentage relative to the space available
 *    on the monitor or they can be exact values, here are some example
 *    values:
 *       x
 *                  0% - left aligned (default)
 *                100% - right aligned
 *                 50% - bar is centered on the screen
 *                  0x - exact position relative to the monitor
 *                 -1x - value < 0 means use default
 *       y
 *                  0% - top bar (default)
 *                100% - bottom bar
 *                  0y - exact position relative to the monitor
 *                 -1y - value < 0 means use default
 *       w
 *                100% - bar takes up the full width of the screen (default)
 *                 20% - small bar taking a fifth of the width of the screen
 *                500w - the bar is 500 pixels wide (including border)
 *                 -1w - value <= 0 means use default
 *       h
 *                100% - bar takes up the full height of the screen
 *                 20% - small bar taking a fifth of the height of screen
 *                 30h - the bar is 30 pixels high (including border)
 *                 -1h - value <= 0 means use the default (deduced by font size)
 *
 *    Note that vertical and horizontal side padding are controlled by the
 *    vertpad and sidepad variables towards the top of this configuration file.
 */
static const BarDef bars[] = {
	/* monitor idx  vert   x     y      w     h     name  */
	{  0,      0,   0,    "0%    0%     100% -1h ", "Primary top" },
	{  0,      1,   0,    "0%    100%   100% -1h ", "Primary bottom" },
	{  1,      0,   0,    "0%    0%     100% -1h ", "Secondary top" },
	{  1,      1,   1,    "0%    100%    50% -1h ", "Secondary bottom" },
	{  2,      0,   0,    "0%    0%     100% -1h ", "Tertiary top" },
	{  2,      1,   0,    "0%    100%   100% -1h ", "Tertiary bottom" },


};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    scheme - defines the default scheme for the bar module
 *    lpad - adds artificial spacing on the left hand side of the module
 *    rpad - adds artificial spacing on the right hand side of the module
 *    value - arbitrary value where the interpretation is module specific
 *    alignment - how the module is aligned compared to other modules
 *    sizefunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
#define PWRL PwrlForwardSlash
static const BarRule barrules[] = {
/*mon bar scheme  lpad rpad value  alignment              sizefunc                 drawfunc                 clickfunc                hoverfunc            name */
//{ -1, 0, 0,         0, 0, 0, BAR_ALIGN_LEFT,   size_powerline,   draw_powerline,   NULL,             NULL, "powerline join" },

{ -1, 0, 0,         0, 0, PWRL, BAR_ALIGN_LEFT,   size_workspaces,  draw_workspaces,  click_workspaces, hover_workspaces,  "workspaces" },

{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_LEFT,   size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },

{ -1, 0, 0,         0, 0, PWRL, BAR_ALIGN_LEFT,   size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },
{ -1, 0, SchemeWsVisible,   5, 0, 0,    BAR_ALIGN_LEFT,   size_ltsymbol,    draw_ltsymbol,    click_ltsymbol,   NULL,  "layout" },
{  0, 0, StatusZero,   5, 5, 0,    BAR_ALIGN_LEFT,   size_status,      draw_status,      click_status,     NULL,  "statuszero" },
{ -1, 0, 0,         0, 0, PWRL, BAR_ALIGN_LEFT,   size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },

{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },

{ -1, 0, StatusOne, 0, 4, 1,    BAR_ALIGN_LEFT,  size_status,      draw_status,      click_status,     NULL,  "statusone" },
{ -1, 0, 0,         0, 0, PWRL, BAR_ALIGN_LEFT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },

{  0, 0, StatusTwo,   5, 5, 2,    BAR_ALIGN_RIGHT,  size_status,      draw_status,      click_status,     NULL,  "statustwo" },
{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },

{  0, 0, StatusThree, 5, 5, 3,    BAR_ALIGN_RIGHT,  size_status,      draw_status,      click_status,     NULL,  "statusthree" },
{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },

{  0, 0, 0,         5, 5, 4,    BAR_ALIGN_RIGHT,  size_status,      draw_status,      click_status,     NULL,  "statusfour" },
{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },

{  0, 0, StatusFive,   0, 4, 5,    BAR_ALIGN_RIGHT,  size_status,      draw_status,      click_status,     NULL,  "statusfive" },
{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },

{  0, 0, StatusSix,   0, 4, 6,    BAR_ALIGN_RIGHT,  size_status,      draw_status,      click_status,     NULL,  "statussix" },
{  0, 0, 6,         0, 0, PWRL, BAR_ALIGN_RIGHT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },

{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,   size_powerline,  draw_powerline,   NULL,             NULL,  "powerline join" },

{  0, 0, 0, 5, 5, 7,    BAR_ALIGN_LEFT,   size_status,     draw_status,      click_status,     NULL,  "statusseven" },
{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,   size_powerline,  draw_powerline,   NULL,             NULL,  "powerline join" },

{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },
{  0, 0, 0,         5, 5, 8,    BAR_ALIGN_RIGHT,  size_status,      draw_status,      click_status,     NULL,  "statuseight" },

{  0, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },
{  0, 0, 7,         5, 5, 9,    BAR_ALIGN_RIGHT,  size_status,      draw_status,      click_status,     NULL,  "statusnine" },
{ -1, 0, 0,         0, 0, PWRL, BAR_ALIGN_RIGHT,  size_powerline,   draw_powerline,   NULL,             NULL,  "powerline join" },


{'A', 0, 0,         0, 0, PWRL,BAR_ALIGN_RIGHT_RIGHT, size_powerline,draw_powerline,NULL,NULL,   "powerline join" },
{'A', 0, StatusTray, 5, 5, 0, BAR_ALIGN_RIGHT_RIGHT,size_systray,draw_systray,click_systray, NULL, "statustray" },
{'A', 0, 0,         0, 0, PWRL,BAR_ALIGN_RIGHT_RIGHT, size_powerline,draw_powerline,NULL,NULL,   "powerline join" },

{ -1, 1, 0,         0, 0, PWRL,BAR_ALIGN_LEFT,size_powerline,draw_powerline, NULL,NULL,     "powerline join" },
{ -1, 1, 0,         0, 0, PWRL,BAR_ALIGN_NONE,size_wintitle_sticky,draw_wintitle_sticky,click_wintitle_sticky,NULL,"wintitle_sticky" },
{ -1, 1, 0,         0, 0, PWRL,BAR_ALIGN_NONE,size_flexwintitle,draw_flexwintitle,click_flexwintitle, NULL, "flexwintitle" },

{  2, 0, 0,         0, 0,  PWRL,BAR_ALIGN_CENTER,size_pwrl_ifhidfloat,draw_powerline,NULL,NULL, "powerline join" },
{  2, 0, 0,         0, 0,  PWRL,BAR_ALIGN_RIGHT_RIGHT,size_wintitle_hidden,draw_wintitle_hidden,click_wintitle_hidden,NULL, "wintitle_hidden" },
{  2, 0, 0,         0, 0,  PWRL,BAR_ALIGN_LEFT_LEFT,size_wintitle_floating,draw_wintitle_floating,click_wintitle_floating,NULL, "wintitle_floating" },
};


/* */


/* Workspaces  {{{1

  WorkspaceaRule legend definitions {{{3
 *
 *    name     - the name of the workspace, this is a reference used for keybindings - see WSKEYS
 *    monitor  - the monitor number the workspace starts on by default, -1 means assign freely
 *    pinned   - whether the workspace is pinned on the assigned monitor
 *    layout   - the layout index the workspace should start with, refer to the layouts array
 *    mfact    - factor of master area size, -1 means use global config
 *    nmaster  - number of clients in master area, -1 means use global config
 *    nstack   - number of clients in primary stack area, -1 means use global config
 *    gaps     - whether gaps are enabled for the workspace, -1 means use global config
 *
 *    icons:
 *       def   - the default icon shown for the workspace, if empty string then the workspace is
 *               hidden by default, if NULL then the workspace name is used for the icon
 *       vac   - the vacant icon shows if the workspace is selected, the default icon is an empty
 *               string (hidden by default) and the workspace has no clients
 *       occ za  - the occupied icon shows if the workspace has clients   }}}*/
static const WorkspaceRule wsrules[] = {
/*  WorkspaceRule wsrules legend
 |===========================================================================================================|=====================|
 |      n     m     p     l     m     n     n     g |                                                        |       Icons         |
 |      a     o     i     a     f     m     s     a |                                                        |=====================|
 |      m     n     n     y     a     a     t     p |                                                        |    
 |      e     i     n     o     c     s     a     s |                                                        |
 |            t     e     u     t     t     c       |                     Schemes                            |
 |            o     d     t           e     k       |======================================================= |=====================|
 |==================================================|     default,         visible,    selected,    occupied, def,  vac,     occ, */
    {  "1",   0,    0,    3,   -1,   -1,   -1,   -1, SchemeWsNorm, SchemeWsVisible, SchemeWsSel, SchemeWsOcc, "1",   "",   "1", },
	{  "2",   0,    0,    3,   -1,   -1,   -1,   -1, SchemeWsNorm, SchemeWsVisible, SchemeWsSel, SchemeWsOcc, "2",   "",   "2", },
    {  "3",   0,    0,    9,   -1,    1,   -1,   -1, SchemeWsNorm, SchemeWsVisible, SchemeWsSel, SchemeWsOcc, "3",   "",   "3", },
	{  "4",   0,    0,    0,   -1,   -1,   -1,   -1, SchemeWsNorm, SchemeWsVisible, SchemeWsSel, SchemeWsOcc, "4",   "",   "4", },
	{  "5",   0,    0,    0,   -1,    1,   -1,   -1, SchemeWsNorm, SchemeWsVisible, SchemeWsSel, SchemeWsOcc, "5",   "",   "5", },
	{  "6",   1,    1,   14,  .70,    2,   -1,   -1, SchemeWsNorm, SchemeWsVisible, SchemeWsSel, SchemeWsOcc, "6",   "",   "6", },
	{  "7",   1,    1,   10,  .60,   -1,   -1,   -1, SchemeWsNorm, SchemeWsVisible, SchemeWsSel, SchemeWsOcc, "7",   "",   "7", },
	{  "8",   1,    1,   07,  .70,    1,   -1,   -1, SchemeWsNorm, SchemeWsVisible, SchemeWsSel, SchemeWsOcc, "8",   "",   "8", },
	{  "9",   1,    1,    3,  .50,   -1,   -1,   -1, SchemeWsNorm, SchemeWsVisible, SchemeWsSel, SchemeWsOcc, "9",   "",   "9", },
};

/*  












*/




static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int nstack      = 0;    /* number of clients in primary stack are */
static const int enablegaps  = 1;    /* whether gaps are enabled by default or not */

/* layout(s) */
static const Layout layouts[] = {
	/*     symbol       arrange function, {nmaster, nstack, layout,                master axis,         stack axis,          2nd axis,     symbol    func } */
	/*00*/{ "[]=",      flextile,         { -1,     -1, SPLIT_VERTICAL,            TOP_TO_BOTTOM,       TOP_TO_BOTTOM,            0,        NULL } }, // default tile layout
	/*01*/{ "|||",      flextile,         { -1,     -1, NO_SPLIT,                  LEFT_TO_RIGHT,       LEFT_TO_RIGHT,            0,        NULL } }, // columns
	/*02*/{ "===",      flextile,         { -1,     -1, NO_SPLIT,                  TOP_TO_BOTTOM,       TOP_TO_BOTTOM,            0,        NULL } }, // rows
	/*03*/{ "[M]",      flextile,         { -1,     -1, NO_SPLIT,                  MONOCLE,             MONOCLE,                  0,        NULL } }, // monocle
	/*04*/{ "||=",      flextile,         { -1,     -1, SPLIT_VERTICAL,            LEFT_TO_RIGHT,       TOP_TO_BOTTOM,            0,        NULL } }, // columns (col) layout
	/*05*/{ ">M>",      flextile,         { -1,     -1, FLOATING_MASTER,           LEFT_TO_RIGHT,       LEFT_TO_RIGHT,            0,        NULL } }, // floating master
	/*06*/{ "[D]",      flextile,         { -1,     -1, SPLIT_VERTICAL,            TOP_TO_BOTTOM,       MONOCLE,                  0,        NULL } }, // deck
	/*07*/{ "TTT",      flextile,         { -1,     -1, SPLIT_HORIZONTAL,          LEFT_TO_RIGHT,       LEFT_TO_RIGHT,            0,        NULL } }, // bstack
	/*08*/{ "===",      flextile,         { -1,     -1, SPLIT_HORIZONTAL,          LEFT_TO_RIGHT,       TOP_TO_BOTTOM,            0,        NULL } }, // bstackhoriz
	/*09*/{ "==#",      flextile,         { -1,     -1, SPLIT_HORIZONTAL,          TOP_TO_BOTTOM,       GAPPLESSGRID_CFACTS,      0,        NULL } }, // bstackgrid

	/*10*/{ "|M|",      flextile,         { -1,     -1, SPLIT_CENTERED_VERTICAL,   LEFT_TO_RIGHT,       TOP_TO_BOTTOM, TOP_TO_BOTTOM,       NULL } }, // centeredmaster
	/*11*/{ "-M-",      flextile,         { -1,     -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM,       LEFT_TO_RIGHT, LEFT_TO_RIGHT,       NULL } }, // centeredmaster horiz

	/*12*/{ ":::",      flextile,         { -1,     -1, NO_SPLIT,                  GAPPLESSGRID_CFACTS, GAPPLESSGRID_CFACTS,      0,        NULL } }, // gappless grid
	/*13*/{ "[\\]",     flextile,         { -1,     -1, NO_SPLIT,                  DWINDLE_CFACTS,      DWINDLE_CFACTS,           0,        NULL } }, // fibonacci dwindle
	/*14*/{ "(@)",      flextile,         { -1,     -1, NO_SPLIT,                  SPIRAL_CFACTS,       SPIRAL_CFACTS,            0,        NULL } }, // fibonacci spiral
	/*15*/{ "[T]",      flextile,         { -1,     -1, SPLIT_VERTICAL,            LEFT_TO_RIGHT,       TATAMI_CFACTS,            0,        NULL } }, // tatami mats
    /*16*/{ "><>",      NULL,             {0} },    /* no layout function means floating behavior */
	/*17*/{ NULL,       NULL,             {0} },    /* end of layouts marker for cyclelayouts */
};

