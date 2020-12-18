declare i32 @getchar()
declare i32 @putchar(i32)
define i32 @main () #0 {
	%a = alloca i32, align 4
	%b = alloca i32, align 4
	%c = alloca i32, align 4
	%1 = load i32, i32* %a, align 4
	%2 = icmp ne i32 %1, 0
	br i1 %2, label %label4, label %label3

	label3:
	%3 = load i32, i32* %b, align 4
	%4 = icmp ne i32 %3, 0
	br i1 %4, label %label5, label %label6

	label5:
	%5 = load i32, i32* %c, align 4
	%6 = icmp ne i32 %5, 0
	%7 = xor i1 %6, true
	%8 = zext i1 %7 to i32
	%9 = icmp ne i32 %8, 0
	br label %label6

	label6:
	%10 = and i1 %4, %9
	%11 = zext i1 %10 to i32
	%12 = icmp ne i32 %11, 0
	br label %label4

	label4:
	%13 = or i1 %2, %12
	%14 = zext i1 %13 to i32
	store i32 %14, i32* %a, align 4
	%15 = load i32, i32* %a, align 4
	%16 = icmp ne i32 %15, 0
	br i1 %16, label %label2, label %label1

	label1:
	%17 = load i32, i32* %b, align 4
	store i32 %17, i32* %c, align 4
	%18 = load i32, i32* %c, align 4
	%19 = icmp ne i32 %18, 0
	br label %label2

	label2:
	%20 = or i1 %16, %19
	%21 = zext i1 %20 to i32
	store i32 %21, i32* %a, align 4
	%22 = load i32, i32* %a, align 4
	ret i32 %22
	%24 = alloca i32, align 4
	store i32 0, i32* %24, align 4
	%25 = load i32, i32* %24, align 4
	ret i32 %25
}

