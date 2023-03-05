for n in `seq 9`; do 
    head -c ${n}0000000 /dev/urandom > dummy
    for exec in cpp rust cpp_py; do
        perf stat -e instructions build/$exec dummy > output_${exec}_${n}.txt 2>&1
    done
done

for exec in cpp rust cpp_py; do
    echo $exec > instructions_$exec.txt
    echo $exec > time_$exec.txt
    grep instructions output_${exec}_?.txt | awk '{print $2}' >> instructions_$exec.txt
    grep time output_${exec}_?.txt | awk '{print $2}' >> time_$exec.txt
done
echo instructions
paste instructions_*
echo
echo time
paste time_*
