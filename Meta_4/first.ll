declare i32 @getchar()
declare i32 @putchar(i32)
@x = common global i32 0, align 4
define i32 @twice (i32 %z) #0 {
	%1 = alloca i32, align 4
	store i32 %z, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = icmp ne i32 %2, 0
	%4 = xor i1 %3, true
	%5 = zext i1 %4 to i32
	store i32 %5, i32* @x, align 4
	%6 = load i32, i32* %1, align 4
	%7 = mul i32 2, %6
	ret i32 %7
	%9 = alloca i32, align 4
	store i32 0, i32* %9, align 4
	%10 = load i32, i32* %9, align 4
	ret i32 %10
}

define i32 @main () #0 {
	%1 = icmp ne i32 0, 0
	br i1 %1, label %label4, label %label3

	label3:
	%2 = call i32 @twice(i32 13)
	%3 = icmp sgt i32 %2, 0
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br label %label4

	label4:
	%6 = phi i1 [ true, %0 ], [ %5, %label3 ]
	%7 = zext i1 %6 to i32
	%8 = icmp ne i32 %7, 0
	br i1 %8, label %label2, label %label1

	label1:
	%9 = call i32 @twice(i32 25)
	%10 = icmp sgt i32 %9, 0
	%11 = zext i1 %10 to i32
	%12 = icmp ne i32 %11, 0
	br label %label2

	label2:
	%13 = phi i1 [ true, %label4 ], [ %12, %label1 ]
	%14 = zext i1 %13 to i32
	%15 = add i32 %14, 65
	%16 = call i32 @putchar(i32 %15)
	ret i32 0
	%18 = alloca i32, align 4
	store i32 0, i32* %18, align 4
	%19 = load i32, i32* %18, align 4
	ret i32 %19
}

