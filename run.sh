make

mkdir -p results

./graphing $1 | dot -Tpdf > results/$2.pdf
