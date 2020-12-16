declare i32 @getchar()
declare i32 @putchar(i32)
@b = common global i32 0, align 4
@w = common global double 0.0, align 8
define i32 @lower (i32 %c) #0 {
	%1 = alloca i32, align 4
	store i32 %c, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = add i32 %2, 97
	%4 = sub i32 %3, 65
	ret i32 %4
	%6 = alloca i32, align 4
	%7 = load i32, i32* %6, align 4
	ret i32 %7
}

define i32 @main () #0 {
	%t = alloca i32, align 4
	store i32 98, i32* %t, align 4
	%1 = call i32 @lower(i32 67)
	%2 = call i32 @putchar(i32 %1)
	%3 = load i32, i32* %t, align 4
	%4 = call i32 @putchar(i32 %3)
	%5 = load i32, i32* %t, align 4
	ret i32 %5
	%7 = alloca i32, align 4
	%8 = load i32, i32* %7, align 4
	ret i32 %8
}

