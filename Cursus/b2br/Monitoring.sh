#!/bin/bash

#ARCHITECTURE
arch=$(uname -a)

#PHYSICAL CPU
pcpu=$(grep "physical id" /proc/cpuinfo | wc -l)

#VIRTUAL CPU
vcpu=$(grep "processor" /proc/cpuinfo | wc -l)

#RAM
used_ram=$(free --mega | awk '$1 == "Mem:" {print $3}')
total_ram=$(free --mega | awk '$1 == "Mem:" {print $2}')
ratio_ram=$(free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)", ($3/$2)*100)}')

#MEMORY
used_memmory=$(df -m | grep "/dev/" | grep -v "/boot/" | awk '{mem_use += $3} END {print mem_use}')
total_memory=$(df -m | grep "/dev/" | grep -v "/boot/" | awk '{mem_total += $2} END {printf("%.0fGb\n", mem_total/1024)}')
ratio_memory=$(df -m | grep "dev" | grep -v "boot" | awk '{total += $2} {use += $3} END {printf("(%d%%)\n", use/total*100)}')

#PROCESSOR
used_cpu_ratio=$(vmstat 1 2 | tail -1 | awk '{cpu_idle=$15} END {printf("%.1f%%\n", (100 - cpu_idle) * 100)}')

#LAST REBOOT
last_reboot=$(who -b | awk '$1 == "system" {print $3 " " $4}')

#LVM
lvm=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

#TCP
tcp=$(ss -t | grep ESTAB | wc -l)

#USERS
users=$(users | wc -w)

#NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

#COMMANDS
comm=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

#MESSAGE
wall "  #Architecture: $arch
        #CPU physical : $pcpu
        #vCPU : $vcpu
        #Memory Usage: $used_ram/${total_ram}MB $ratio_ram
        #Disk Usage: $used_memory/${total_memory} $ratio_memory
        #CPU load: $used_cpu_ratio
        #Last boot: $last_reboot
        #LVM use: $lvm
        #Connections TCP : $tcp ESTABLISHED
        #User log: $users
        #Network: IP $ip ($mac)
        #Sudo : $comm cmd"