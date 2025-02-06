#!/bin/bash
#SBATCH --job-name=mergesort
#SBATCH --partition=Centaurus
#SBATCH --time=01:00:00
#SBATCH --mem=32G
#SBATCH --output=times.txt

g++  mergeSort-Alex.cpp -o  mergeSort

for size in 10 100 1000 10000 100000 1000000 10000000 100000000 1000000000
do
    echo "Running merge sort for size: $size" >> timesRecorded.txt

    ./mergeSort <<< "$size" >> timesRecorded.txt
done

echo "Results in timesRecorded.txt"



