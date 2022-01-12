echo -n "Run disappear? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./cgol disappear20X40.seed 50
fi

echo -n "Run gun? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./cgol gun20x40.seed 50
fi

echo -n "Run diehard? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./cgol diehard20X40.seed 50
fi

echo -n "Run glider? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./cgol glider20X40.seed 100
fi

echo -n "Run pufferTrain? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./cgol pufferTrain20X40.seed 150
fi

echo -n "Run gliderMany? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./cgol gliderMany20X40.seed 200
fi

echo -n "Run puffer [y or n]: "
read answer
if [ $answer = 'y' ]
then
./cgol puffer20X40.seed 175
fi

echo -n "Run wrong sized file? [y or n]: "
read answer
if [ $answer = 'y' ]
then
./cgol blinker5X5.seed 10
fi

