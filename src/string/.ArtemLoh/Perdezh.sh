#!/bin/sh

function CrankVolumeUp {
	osascript -e "Set Volume 10"
}

while (true)
do
	CrankVolumeUp
	afplay -r 0.5 P
done


