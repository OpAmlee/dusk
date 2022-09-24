#!/usr/bin/env bash
set -euo pipefail

sed -n '/start_keys/,/stop_keys/p' /home/trg/.config/arco-dusk/config.def.h | yad --text-info --back=#14161a --fore=#46d9fe --geometry=1200x800

#sed -n '/start_keys/,/stop_keys/p' /home/trg/.config/arco-dusk/config.def.h #| \
   # grep -e ', {KeyPress,' \
   # -e '\[ (' \
   # -e 'KB_GROUP' | \
#    #grep -v '\-\- , ("' | \
   # sed -e 's/^[ \t]*//' \
   # -e 's/, (/(/' \
   # -e 's/\[ (/(/' \
   # -e 's/-- KB_GROUP /\n/' \
   # -e 's/", /"\t: /' | \
#    yad --text-info --back=#14161a --fore=#ffffff --geometry=1200x800
