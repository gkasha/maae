#!/bin/bash

shopt -s expand_aliases
source ~/.bash_aliases

gnome-terminal --title "clock" -- bash -c "./run_clock.sh; exec bash"

gnome-terminal --title "agent 0" -- bash -c "./run_agent.sh 0 3000 0.3 3 3 1; exec bash"
gnome-terminal --title "agent 1" -- bash -c "./run_agent.sh 1 3000 0.3 3 3 1; exec bash"
gnome-terminal --title "agent 2" -- bash -c "./run_agent.sh 2 3000 0.3 3 3 1; exec bash"
gnome-terminal --title "agent 3" -- bash -c "./run_agent.sh 3 3000 0.3 3 3 1; exec bash"
gnome-terminal --title "agent 4" -- bash -c "./run_agent.sh 4 3000 0.3 3 3 1; exec bash"
gnome-terminal --title "agent 5" -- bash -c "./run_agent.sh 5 3000 0.3 3 3 1; exec bash"
gnome-terminal --title "agent 6" -- bash -c "./run_agent.sh 6 3000 0.3 3 3 1; exec bash"
gnome-terminal --title "agent 7" -- bash -c "./run_agent.sh 7 3000 0.3 3 3 1; exec bash"

gnome-terminal --title "goal_manager" -- bash -c "./run_gm.sh; exec bash"
gnome-terminal --title "execution_interface" -- bash -c "./run_executor.sh; exec bash"

