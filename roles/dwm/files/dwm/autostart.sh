#!/bin/sh

gnome-keyring-daemon -r -d &
autorandr --change --force && nitrogen --restore;
slstatus &
clipmenud &
picom --backend glx --vsync --blur-method dual_kawase --blur-strength 4 &
