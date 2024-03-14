#!/bin/sh

setup_debian() {
  if command -v dpkg >/dev/null; then
    echo "Installing Debian dependencies"
    cd debian || return
    ./setup.sh
    cd .. || return
  fi
}

build() {
  echo "Building $1"
  cd "$1" || return
  sudo cp config.def.h config.h
  sudo make clean install
  cd .. || return
}

build_clipnotify() {
  echo "Building clipnotify"
  cd clipnotify || return
  sudo make install
  cd .. || return
}

main() {
  setup_debian
  build dmenu
  build dwm
  build slock
  build slstatus
  build_clipnotify
  build clipmenu
}

main
