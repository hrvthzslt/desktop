#!/bin/sh

setup_debian() {
  if command -v dpkg >/dev/null; then
    echo "Installing Debian dependencies"
    cd debian || return
    ./setup.sh
    cd .. || return
  fi
}

build_st() {
  echo "Building st"
  cd st || return
  sudo make clean install
  cd .. || return
}

build_dmenu() {
  echo "Building dmenu"
  cd dmenu || return
  sudo make clean install
  cd .. || return
}

build_dwm() {
  echo "Building dwm"
  cd dwm || return
  sudo make clean install
  cd .. || return
}

main() {
  setup_debian
  build_st
  build_dmenu
  build_dwm
}

main
