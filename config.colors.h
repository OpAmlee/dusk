
/*  Dmenu colorscheme */
static char dmenunormfgcolor[] = "#C6BDBD";
static char dmenunormbgcolor[] = "#080809";
static char dmenuselfgcolor[] = "#FFD400";
static char dmenuselbgcolor[] = "#080809";



static const unsigned int alphas[SchemeLast][3] = {
//  scheme title             foreground background  border    resource prefix
    [SchemeNorm]         = { OPAQUE,      0xd0,     OPAQUE },
};

static char *colors[SchemeLast][ColCount] = {
//  scheme title             foreground background  border    resource prefix 
[SchemeNorm]         = { "#D11B1B", "#131315", "#0C0A20", "norm"      },// main title bar color
[SchemeSel]          = { "#E8D9B1", "#292832", "#090819", "sel"       },
[SchemeTitleNorm]    = { "#E8D9B1", "#131315", "#090819", "titlenorm" },//border bar empty workspace
[SchemeTitleSel]     = { "#1793E8", "#3B4167", "#090819", "titlesel"  },
[SchemeWsNorm]       = { "#5F6064", "#101011", "#0C0A20", "wsnorm"    },// workspace empty
[SchemeWsVisible]    = { "#80787C", "#131315", "#090819", "wsvis"     },// layout indicator
[SchemeWsSel]        = { "#d10f3f", "#101011", "#090819", "wssel"     },// active ws sel indication
[SchemeWsOcc]        = { "#E5C368", "#101011", "#090819", "wsocc"     },// ws with open items
[SchemeHidNorm]      = { "#AD1C56", "#222222", "#090819", "hidnorm"   },
[SchemeHidSel]       = { "#D288C6", "#111111", "#090819", "hidsel"    },
[SchemeUrg]          = { "#bbbbbb", "#222222", "#d10f3f", "urg"       },
[SchemeMarked]       = { "#615656", "#FFD400", "#FFD400", "marked"    },
[SchemeScratchNorm]  = { "#787878", "#121212", "#020011", "scratchnorm"},//bar text bottom inactive
[SchemeScratchSel]   = { "#FFD400", "#121212", "#121212", "scratchsel" },//text bottom bar active
[SchemeFlexActTTB]   = { "#E8D9B1", "#080707", "#080707", "actTTB"    },
[SchemeFlexActLTR]   = { "#E8D9B1", "#440044", "#F00890", "actLTR"    },
[SchemeFlexActMONO]  = { "#A875FF", "#101011", "#101011", "actMONO"   },//inactive bar
[SchemeFlexActGRID]  = { "#E8D9B1", "#a875ff", "#a875ff", "actGRID"   },
[SchemeFlexActGRIDC] = { "#E8D9B1", "#a875ff", "#a875ff", "actGRIDC"  },
[SchemeFlexActGRD1]  = { "#E8D9B1", "#a875ff", "#a875ff", "actGRD1"   },
[SchemeFlexActGRD2]  = { "#E8D9B1", "#a875ff", "#a875ff", "actGRD2"   },
[SchemeFlexActGRDM]  = { "#E8D9B1", "#a7da1e", "#a7da1e", "actGRDM"   },
[SchemeFlexActHGRD]  = { "#E8D9B1", "#ff9b50", "#ff9b50", "actHGRD"   },
[SchemeFlexActDWDL]  = { "#E8D9B1", "#004444", "#004444", "actDWDL"   },
[SchemeFlexActDWDLC] = { "#E8D9B1", "#004444", "#004444", "actDWDLC"  },
[SchemeFlexActSPRL]  = { "#E8D9B1", "#32F709", "#32F709", "actSPRL"   },
[SchemeFlexActSPRLC] = { "#E8D9B1", "#32F709", "#32F709", "actSPRLC"  },
[SchemeFlexActTTMI]  = { "#E8D9B1", "#BA45A3", "#BA45A3", "actTTMI"   },
[SchemeFlexActTTMIC] = { "#E8D9B1", "#BA45A3", "#BA45A3", "actTTMIC"  },
[SchemeFlexActFloat] = { "#E8D9B1", "#9B2E2E", "#121212", "actfloat"  },
[SchemeFlexInaTTB]   = { "#E8D9B1", "#080707", "#080707", "normTTB"   },
[SchemeFlexInaLTR]   = { "#E8D9B1", "#330033", "#330033", "normLTR"   },
[SchemeFlexInaMONO]  = { "#A875FF", "#101011", "#101011", "normMONO"  },// bar inactive bg fg ws1-3
[SchemeFlexInaGRID]  = { "#E8D9B1", "#42c6ff", "#42c6ff", "normGRID"  },
[SchemeFlexInaGRIDC] = { "#E8D9B1", "#42c6ff", "#42c6ff", "normGRIDC" },
[SchemeFlexInaGRD1]  = { "#E8D9B1", "#42c6ff", "#42c6ff", "normGRD1"  },
[SchemeFlexInaGRD2]  = { "#E8D9B1", "#42c6ff", "#42c6ff", "normGRD2"  },
[SchemeFlexInaGRDM]  = { "#E8D9B1", "#506600", "#506600", "normGRDM"  },
[SchemeFlexInaHGRD]  = { "#E8D9B1", "#ff9b50", "#ff9b50", "normHGRD"  },
[SchemeFlexInaDWDL]  = { "#E8D9B1", "#003333", "#003333", "normDWDL"  },
[SchemeFlexInaDWDLC] = { "#3b4167", "#080707", "#161130", "normDWDLC" },//pop up terminal active 
[SchemeFlexInaSPRL]  = { "#E8D9B1", "#333300", "#333300", "normSPRL"  },
[SchemeFlexInaSPRLC] = { "#E8D9B1", "#333300", "#333300", "normSPRLC" },
[SchemeFlexInaTTMI]  = { "#E8D9B1", "#B32727", "#B32727", "normTTMI"  },
[SchemeFlexInaTTMIC] = { "#E8D9B1", "#B32727", "#B32727", "normTTMIC" },
[SchemeFlexInaFloat] = { "#121212", "#121212", "#171717", "normfloat" },// corrected border float
[SchemeFlexSelTTB]   = { "#FFD400", "#121212", "#121212", "selTTB"    },// border top active ws
[SchemeFlexSelLTR]   = { "#E8D9B1", "#550055", "#550055", "selLTR"    },
[SchemeFlexSelMONO]  = { "#FFD400", "#292832", "#121212", "selMONO"   },// active window
[SchemeFlexSelGRID]  = { "#E8D9B1", "#09E5B0", "#09E5B0", "selGRID"   },
[SchemeFlexSelGRIDC] = { "#E8D9B1", "#09E5B0", "#09E5B0", "selGRIDC"  },
[SchemeFlexSelGRD1]  = { "#E8D9B1", "#09E5B0", "#09E5B0", "selGRD1"   },
[SchemeFlexSelGRD2]  = { "#E8D9B1", "#09E5B0", "#09E5B0", "selGRD2"   },
[SchemeFlexSelGRDM]  = { "#E8D9B1", "#508822", "#508822", "selGRDM"   },
[SchemeFlexSelHGRD]  = { "#E8D9B1", "#ff9b50", "#ff9b50", "selHGRD"   },
[SchemeFlexSelDWDL]  = { "#E8D9B1", "#080707", "#161130", "selDWDL"   },
[SchemeFlexSelDWDLC] = { "#FFD400", "#080707", "#e61f44", "selDWDLC"  },//popup active text
[SchemeFlexSelSPRL]  = { "#E8D9B1", "#555500", "#555500", "selSPRL"   },
[SchemeFlexSelSPRLC] = { "#E8D9B1", "#555500", "#555500", "selSPRLC"  },
[SchemeFlexSelTTMI]  = { "#E8D9B1", "#e61f44", "#e61f44", "selTTMI"   },
[SchemeFlexSelTTMIC] = { "#E8D9B1", "#e61f44", "#e61f44", "selTTMIC"  },
[SchemeFlexSelFloat] = { "#E8D9B1", "#171717", "#121212", "selfloat"  },

[StatusZero]  =          { "#80787C", "#26262C", "#0C0A20", "statuszero"  },
[StatusOne]   =          { "#787878", "#131315", "#0C0A20", "statusone"   },
[StatusTwo]   =          { "#80787C", "#0B0B0C", "#0C0A20", "statustwo"   },
[StatusThree] =          { "#E8D9B1", "#0B0B0C", "#0C0A20", "statusthree" },
[StatusFour]  =          { "#80787C", "#32F709", "#0C0A20", "statusfour"  },
[StatusFive]  =          { "#ff9b50", "#0C0A20", "#0C0A20", "statusfive"  },
[StatusSix]   =          { "#80787C", "#17171A", "#0C0A20", "statussix"   },
[StatusSeven] =          { "#17171A", "#80787C", "#0C0A20", "statusseven" },
[StatusEight] =          { "#80787C", "#09E5B0", "#0C0A20", "statuseight" },
[StatusNine]  =          { "#80787C", "#CBCFCF", "#0C0A20", "statusnine"  },
[StatusTray]  =          { "#80787C", "#0B0B0C", "#0C0A20", "statustray"  },

};


/*
#0c0a20
#090819
#131033
#161130
#110d26
#3b4167
#2d2844
#BA45A3
#6A6EA3
#6564D1
#919ad9
#7984D1
#f2f3f7
#546A90
#e61f44
#ff9b50
#a7da1e
#A875FF
#ffd400
#1ea8fc
#3F88AD
#ff2afc
#df85ff
#42c6ff
#204052 
#80787C

*/
