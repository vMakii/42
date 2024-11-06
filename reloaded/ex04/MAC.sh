#!/bin/bash
ifconfig | grep -o -E '([[:xdigit:]]{2}:){5}[[:xdigit:]]{2}'
#-o print seulement le match et -E pour utiliser une expression
#([[:xdigit:]]{2}:){5}[[:xdigit:]]{2} 6 groupes de 2 chiffres hexa separer d'un :

#ifconfig | grep ether | cut -b 8-31