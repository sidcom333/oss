echo "Enter a number:"
read num
calculate_factorial() {
    if [ $1 -eq 0 ] || [ $1 -eq 1 ]; then
        echo 1
    else
        echo $(( $1 * $(calculate_factorial $(( $1 - 1 ))) ))
    fi
}

result=$(calculate_factorial $num)
echo "The factorial of $num is $result."
