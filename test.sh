time=0
strings=0


for file in maps/*
do
	time=$({ time ./lem-in < $file >/dev/null; } 2>&1 | grep user)
	strings=$(./lem-in < $file | wc -l)
	echo "\033[36mOn map $file Lem-in made: \033[32m$strings\033[m iteration(s) \033[1m\033[33m($time)\033[m"
done
	echo "\n\033[1m\033[32mEnjoy our vizualizer (./vis.sh)  🤗  \033[m"
