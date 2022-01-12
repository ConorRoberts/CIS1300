echo "cat testfile1.txt | ./testChop"
cat testfile1.txt | ./testChop
echo "----------";
echo "cat testfile1.txt | ./testConvert"
cat testfile1.txt | ./testConvert
echo "----------";
echo "cat testfile1.txt | ./testReplaceDigits"
cat testfile1.txt | ./testReplaceDigits
echo "----------";
echo "cat testfile1.txt | ./testReplacePunc"
cat testfile1.txt | ./testReplacePunc
echo "----------";
echo "cat testfile1.txt | ./testReduceSpace"
cat testfile1.txt | ./testReduceSpace
echo "----------";
echo "cat testfile2.txt | ./testTrim"
cat testfile2.txt | ./testTrim
echo "----------";
echo "cat verne2.txt | ./findWords | sort > answer1.txt"
cat verne2.txt | ./findWords | sort > answer1.txt
echo "comparing findWords result to answer..."
diff answer1.txt verne2FindWords.result
echo "----------";
echo "cat verne2.txt | ./findWords | sort | ./wordBag > answer2.txt"
cat verne2.txt | ./findWords | sort | ./wordBag > answer2.txt
echo "comparing wordBag result to answer..."
diff answer2.txt verne2WordBag.result
echo "----------";

