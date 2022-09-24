#!/bin/bash

DIR=$(dirname ${BASH_SOURCE[0]})

case $BLOCK_STATUS in
	0) $DIR/powerbutton_click ;;
	1) $DIR/clock_click ;;
	2) $DIR/startbutton_click ;;
	3) $DIR/bluetooth_click ;;
	4) $DIR/sysupdates_click ;;
	6) $DIR/backlight_click ;;
    5) $DIR/volume1_click ;;
#	9) $DIR/kblayout_click ;;
	*) notify-send -t 2000 "Unknown status $BLOCK_STATUS clicked $BLOCK_BUTTON" & ;;
esac

