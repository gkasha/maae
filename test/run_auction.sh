#!/bin/bash

shopt -s expand_aliases
source ~/.bash_aliases

gnome-terminal --title "agent 0" -- bash -c "./run_agent.sh 0 300 3; exec bash"
gnome-terminal --title "agent 1" -- bash -c "./run_agent.sh 1 300 3; exec bash"
gnome-terminal --title "agent 2" -- bash -c "./run_agent.sh 2 300 3; exec bash"

gnome-terminal --title "goal_manager" -- bash -c "./run_gm.sh; exec bash"
gnome-terminal --title "execution_interface" -- bash -c "./run_executor.sh; exec bash"
