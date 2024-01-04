#!/bin/sh

install_dependency() {
  for dependency in "$@"; do
    dpkg -s "$dependency" 2>/dev/null || sudo apt install "$dependency"
  done
}

copy_desktop_entry() {
  sudo cp ./dwm.desktop /usr/share/xsessions/
}

main() {
  install_dependency git make gcc libx11-dev libxft-dev libxinerama-dev xorg
  copy_desktop_entry
}

main
