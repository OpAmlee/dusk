#!/usr/bin/env bash

TIME=" $(date +'%R%p-%d%b%g')"

sh -c "echo ${TIME} | xclip -sel clip"
