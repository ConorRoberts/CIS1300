echo -n "Run beacon? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./dynCGOl beacon6X6.seed 10 6 6
fi

echo -n "Run blinker? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./dynCGOL blinker5X5.seed 10 5 5
fi

echo -n "Run diehard? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./dynCGOL diehard10X20.seed 150 10 20
fi

echo -n "Run penta? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./dynCGOL penta18X11.seed 30 18 11
fi

