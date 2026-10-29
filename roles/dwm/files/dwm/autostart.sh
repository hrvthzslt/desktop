#!/bin/sh

main() {
  export XDG_SESSION_TYPE=x11

  picom_version=$(picom --version)

  gnome-keyring-daemon -r -d &
  autorandr --change --force && nitrogen --restore
  sxhkd &
  dwmblocks &
  clipmenud &
  if [ "$picom_version" = 'v9.1' ]; then
    picom --experimental-backends &
  else
    picom &
  fi
  dunst &

  exec dwm >"$HOME"/.dwm/log 2>&1
}

main
