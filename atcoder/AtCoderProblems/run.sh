files="/Users/hal0taso/.ghq/github.com/hal0taso/WriteUp/atcoder/AtCoderProblems/in/*"
for filepath in $files; do
  fname=`basename $filepath`
  echo $fname
  ./ahc < $filepath > './out/'$fname
done

# 0952
# 1128
# 1542
# 1566
# 1609
# 1651
# 