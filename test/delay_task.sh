#!/bin/bash

shopt -s expand_aliases
source ~/.bash_aliases

ros2 topic pub -t 1 /action_modification_topic ma_interfaces/msg/ActionFeedback '{action_id: "task0", agent_id: "1", name: "task0", time: 6.0, action_started: 1}'
