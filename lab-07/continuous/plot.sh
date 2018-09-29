#!/bin/bash
if [ -z "$1" ] ; then
	echo "usage: plot.sh <datafile>"
	exit -1;
fi;
gnuplot -p << EOF
plot "$1" using 5:1 with lines title "POT_A0", \
	"$1" using 5:2 with lines title "LIGHT_A1", \
	"$1" using 5:3 with lines title "SOUND_A2", \
	"$1" using 5:4 with lines title "TEMP_A3"
EOF
