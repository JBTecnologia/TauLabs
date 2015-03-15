#!/bin/bash
for OUTPUT in $(git branch -r)
do
	echo "AAA" $OUTPUT
done