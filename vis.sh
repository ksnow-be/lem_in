for file in vismaps/*
do
	./lem-in -v $1 < "$file"
done
