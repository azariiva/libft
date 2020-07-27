#!/bin/bash

function CrankVolumeUp {
	osascript -e "Set Volume 10"
}

function SayLine {
	rate=100
	pause=0.5
	say -v Yuri -r $rate -i $1
}

flag=0
trap "(( flag = 1 ))" SIGINT SIGTERM SIGQUIT SIGTSTP SIGCONT

function main {
	while [ 1 ]; do
		if [[ $flag == 1 ]]; then
				CrankVolumeUp
				SayLine 'Не у би вай ме ня, Ар тём!'
				(( flag = 0 ))
		fi
		ls -lGR $HOME/Desktop
	done
}

main
