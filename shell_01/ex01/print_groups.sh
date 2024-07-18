#!/bin/bash
id -G -n $FT_USER | tr ' ' ',' | tr -d '\n'
#-G pour les groups et -n pour aff un nom et $ pour avoir la valeur de la var
