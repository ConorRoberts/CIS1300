echo "Checking that the program handles correct input..."
echo ""
echo "./dates 20 4 2019"
./dates 20 4 2019
echo ""

echo "./dates 1 1 2020"
./dates 1 1 2020
echo ""

echo "./dates 23 8 2000"
./dates 23 8 2000
echo ""

echo "./dates 23 8 1900"
./dates 23 8 1900
echo ""
echo "Checking that the program handles incorrect input..."
echo ""
echo "- no commandline argument"
echo "./dates"
./dates
echo ""
echo "- incorrect months"
echo "./dates 1 13 2019"
./dates 1 13 2019
echo ""
echo "./dates 1 -1 2018"
./dates 1 -1 2018
echo ""
echo "- incorrect days"
echo "./dates 32 1 2018"
./dates 32 1 2018
echo ""
echo "./dates 31 9 2019"
./dates 31 9 2019
echo ""
