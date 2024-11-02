//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" 󱌼 ", "mem_perc", 1, 0},
    {"  ", "cpu_perc",	1, 0},
    {"  ", "disk_perc", 1, 0},

    {"", "", 0, 0},

    {"", "clipctl_status", 0, 10},
    {" ", "dunst_status", 0, 12},

    {"  ", "alsa_perc", 0, 14},
    {" 󰂯 ", "bluetooth_count", 10, 0},
    {" 󱊣 ", "battery", 60, 0},

    {"", "", 0, 0},

	{"", "date_hour", 1, 0},

    {" ", "", 0, 0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " ";
static unsigned int delimLen = 5;
