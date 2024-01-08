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
  install_packages st nitrogen picom
}

copy_desktop_entry() {
  sudo cp ./dwm.desktop /usr/share/xsessions/
}

main() {
  install_dependencies
  install_desktop_programs
  copy_desktop_entry
}

main
