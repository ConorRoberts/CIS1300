echo "cat testfile1.txt | ./testChop"
cat testfile1.txt | ./testChop > stuff1
echo "comparing testChop result to answer..."
diff stuff1 result1
echo "----------";
echo "cat testfile1.txt | ./testConvert"
cat testfile1.txt | ./testConvert > stuff2
echo "comparing testConvert result to answer..."
diff stuff2 result2
echo "----------";
echo "cat testfile1.txt | ./testReplaceDigits"
cat testfile1.txt | ./testReplaceDigits > stuff3
echo "comparing testReplaceDigits result to answer..."
diff stuff3 result3
echo "----------";
echo "cat testfile1.txt | ./testReplacePunc"
cat testfile1.txt | ./testReplacePunc > stuff4
echo "comparing testReplacePunc result to answer..."
diff stuff4 result4
echo "----------";
echo "cat testfile1.txt | ./testReduceSpace"
cat testfile1.txt | ./testReduceSpace > stuff5
echo "comparing testReduceSpace result to answer..."
diff stuff5 result5
echo "----------";
echo "cat testfile2.txt | ./testTrim"
cat testfile2.txt | ./testTrim > stuff6
echo "comparing testTrim result to answer..."
diff stuff6 result6
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

