make

mkdir -p results

if [ $# -eq 2 ]
then
	./graphing $1 | dot -Tpdf > results/$2.pdf
else
	echo "Usage: ./run.sh <number of nodes on the graph> <filename output>"
fi

