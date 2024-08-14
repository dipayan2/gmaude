#!/bin/bash
./trace_data/runtop.sh >> $1 &
${@:2}
kill $(jobs -p)
