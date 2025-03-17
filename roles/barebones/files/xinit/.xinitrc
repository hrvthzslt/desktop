dbus-update-activation-environment --systemd DBUS_SESSION_BUS_ADDRESS DISPLAY XAUTHORITY

session=${1:-dwm}

case $session in
    dwm) exec dwm > "$HOME"/.dwm/log 2>&1 ;;
    i3) exec i3 ;;
    *) exec $1 ;;
esac
