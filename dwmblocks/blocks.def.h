//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" 󱌼 ", "free | grep Mem | awk '{printf \"%.0f%%\", $3/$2 * 100.0}'", 1, 0},
    {" ", "iostat -c | awk 'NR>= 4 && NR<=4' | awk '{printf \"%.0f%%\", $1}'",	1, 0},
    {" ", "df / | grep / | awk '{print $5}'", 1, 0},

    {"", "", 0, 0},

    {"", "[ \"$(clipctl status)\" = 'enabled' ] && echo 󰅎 || echo 󱘜", 0, 10},
    {" ", "[ \"$(dunstctl is-paused)\" = 'false' ] && echo 󰎚 || echo 󱞃", 0, 12},

    {"  ", "amixer sget Master | tail -1 | awk '{print $5 }' | sed 's@\\(\\[\\|\\]\\)@@g'", 0, 14},
    /* {"  ", 'nmcli dev wifi | grep "\*" | awk '{print $8}'\, 0, 14}, */

	{"", "date '+%Y-%m-%d %H:%M:%S'", 1, 0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " ";
static unsigned int delimLen = 5;
