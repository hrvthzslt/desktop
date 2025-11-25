//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"", "mem_perc_block", 1, 0},
    {"", "cpu_perc_block",	1, 0},
    {"", "disk_perc_block", 1, 0},

    {"", "", 0, 0},

    {"", "clipctl_status_block", 0, 10},
    {"", "dunst_status_block", 0, 12},

    {" ", "alsa_perc_block", 5, 14},
    {"", "wifi_perc_block", 5, 0},
    {"", "bluetooth_count_block", 5, 0},
    {"", "battery_block", 1, 0},
    {"", "power get", 0, 16},
    {" ", "keemap icon", 0, 18},

    {"", "", 0, 0},

	{"", "date_hour_block", 1, 0},

    {" ", "", 0, 0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " ";
static unsigned int delimLen = 5;
