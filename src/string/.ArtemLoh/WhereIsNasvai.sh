#!/bin/bash

function CrankVolumeUp {
	osascript -e "Set Volume 10"
}

function SayLine {
	rate=100
	pause=0.5
	say -v Yuri -r $rate -i $1
}

function ReadText {
	while IFS= read -r line
	do
		#CrankVolumeUp
		SayLine "$line"
	done < $1
}


while (true)
do
	ReadText "$(pwd)/NasvaiSpeech.txt"
done
