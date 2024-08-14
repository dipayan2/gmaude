#!/bin/bash
top -1 -d 1 -b | grep "load average" -A 14
