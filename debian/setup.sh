#!/bin/sh

install_packages() {
  for dependency in "$@"; do
    dpkg -s "$dependency" 2>/dev/null || sudo apt install "$dependency"
  done
}

install_dependencies() {
  install_packages git make gcc libx11-dev libxft-dev libxinerama-dev libxrandr-dev xorg
}

install_desktop_programs() {
  install_packages st \
    nitrogen \
    picom \
    arandr \
    xrandr \
    autorandr \
    mpv \
    dunst \
    gnome-keyring-daemon \
    alacritty \
    flameshot \
    brightnessctl

  sudo chmod +s "$(which brightnessctl)"
}

copy_desktop_entry() {
  sudo cp -v ../config/dwm.desktop /usr/share/xsessions/
}

copy_touchpad_config() {
  sudo cp -v ../config/30-touchpad.conf /etc/X11/xorg.conf.d/
}

main() {
  install_dependencies
  install_desktop_programs
  copy_desktop_entry
  copy_touchpad_config
}

main
