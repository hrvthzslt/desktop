#!/bin/sh

gnome-keyring-daemon -r -d &
autorandr --change --force && nitrogen --restore;
sxhkd &
dwmblocks &
clipmenud &
picom --backend glx --vsync --blur-method dual_kawase --blur-strength 4 &
dunst &
sh ~/.dwm/poststart.sh 2>/dev/null &
