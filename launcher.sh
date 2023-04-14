#!/bin/bash

NAME=terminal_minigames
rename='printf "\e]2;Terminal MiniGames\a"'
launch="./$NAME"

if [ ! -f $NAME ]; then
	make
fi
gnome-terminal -- sh -c "$rename; $launch"