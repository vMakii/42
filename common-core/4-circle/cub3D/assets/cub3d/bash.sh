#!/bin/bash
mkdir -p xpm_output

for file in *.png; do
    name=$(basename "$file" .png)
    convert "$file" "xpm_output/$name.xpm"
done
