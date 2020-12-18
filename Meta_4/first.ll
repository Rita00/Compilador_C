declare i32 @getchar()
declare i32 @putchar(i32)
define i32 @main () #0 {
	%1 = mul i32 23, 757
	%2 = add i32 %1, 65
	%3 = call i32 @putchar(i32 %2)
	%a = alloca i32, align 4
	store i32 10, i32* %a, align 4
	%4 = load i32, i32* %a, align 4
	%5 = add i32 %4, 65
	%6 = call i32 @putchar(i32 %5)
	%c = alloca i32, align 4
	store i32 0, i32* %c, align 4
	%7 = load i32, i32* %c, align 4
	%8 = add i32 %7, 65
	%9 = call i32 @putchar(i32 %8)
	%10 = alloca i32, align 4
	store i32 0, i32* %10, align 4
	%11 = load i32, i32* %10, align 4
	ret i32 %11
}

