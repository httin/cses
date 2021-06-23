#!/bin/bash
for i in $(find . -regex './[0-9]+'); do
    rm -v $i;
done
