
#!/bin/bash

DIR=$(dirname ${BASH_SOURCE[0]})

for pid in $(pidof -x "status_updater.sh"); do
	if [ $pid != $$ ]; then
		if [ "$(cat /proc/$pid/environ | tr '\0' '\n' | awk '/^DISPLAY/')" == "DISPLAY=$DISPLAY" ]; then
			echo "$(date +"%H:%M%P "): status_updater.sh is already running with PID $pid, killing"
			kill $pid
		fi
	fi
done

# Add an artificial sleep to wait for the IPC handler to be ready to process requests
sleep 0.5

SETSTATUS="duskc --ignore-reply run_command setstatus"

secs=0

while true; do

	$SETSTATUS 1 "$($DIR/clock)" &
     

	if [ $? != 0 ]; then
		echo "Failed to set status, bailing"
		exit
	fi

#	$SETSTATUS 5 "$($DIR/bandwidth2)" &
#	$SETSTATUS 3 "$($DIR/cpu)" &
#	$SETSTATUS 6 "$($DIR/status/bar/backlight)" &
#   $SETSTATUS 6 "$($DIR/battery2)" &
    #$SETSTATUS 5 "$($DIR/i3-blocks-bat)" & 
#    $SETSTATUS 3 "$($DIR/statusbar/bluetooth)" &
#	if [ $((secs % 60)) = 0 ]; then
#	#	$SETSTATUS 5 "$($DIR/mouse_battery)" &
#		$SETSTATUS 5 "$($DIR/volume1)" &
#		#$SETSTATUS 9 "$($DIR/kblayout)" &
#	fi

	if [ $((secs % 3600)) = 0 ]; then
#	    $SETSTATUS 4 "$($DIR/sysupdates)" &
        $SETSTATUS 2 "$($DIR/startbutton)" &
		#$SETSTATUS 0 "$($DIR/powerbutton)" &
	fi

    ((secs+=1))
	sleep 1
done

