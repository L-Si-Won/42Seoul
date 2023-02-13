ifconfig | grep ether | tr -d '\t' | cut -d ' ' -f 2 | grep -v auto
