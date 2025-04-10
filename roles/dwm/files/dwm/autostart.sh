#!/bin/sh

picom_version=$(picom --version)

gnome-keyring-daemon -r -d &
autorandr --change --force && nitrogen --restore;
sxhkd &
dwmblocks &
clipmenud &
if [ "$picom_version" = 'v9.1' ]; then
    picom --experimental-backends &
else
    picom &
fi
dunst &
sh ~/.dwm/poststart.sh 2>/dev/null &
