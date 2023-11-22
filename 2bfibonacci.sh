echo "Enter the number of Fibonacci numbers to generate:"
read n

a=0
b=1

echo "Fibonacci sequence:"
for ((i=0; i<n; i++)); do
    echo -n "$a "
    temp=$a
    a=$b
    b=$((temp + b))
done

echo 
