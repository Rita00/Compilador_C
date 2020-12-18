declare i32 @getchar()
declare i32 @putchar(i32)
@n1 = global i32 10, align 4
define void @print_int (i32 %value) #0 {
	%1 = alloca i32, align 4
	store i32 %value, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = icmp ne i32 %2, 0
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %label1, label %label2

	label1:
	%6 = load i32, i32* %1, align 4
	%7 = sdiv i32 %6, 10
	call void @print_int(i32 %7)
	%8 = load i32, i32* %1, align 4
	%9 = srem i32 %8, 10
	%10 = add i32 %9, 48
	%11 = call i32 @putchar(i32 %10)
	br label %label3

	label2:
	br label %label3

	label3:
	ret void
}

define void @func (i32 %n1) #0 {
	%1 = alloca i32, align 4
	store i32 %n1, i32* %1, align 4
	br label %label1

	label1:
	%2 = load i32, i32* %1, align 4
	%3 = sub i32 %2, 1
	store i32 %3, i32* %1, align 4
	%4 = load i32, i32* %1, align 4
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %label2, label %label3

	label2:
	%6 = load i32, i32* %1, align 4
	call void @print_int(i32 %6)
	br label %label1

	label3:
	store i32 10, i32* %1, align 4
	br label %label4

	label4:
	%7 = load i32, i32* %1, align 4
	%8 = sub i32 %7, 1
	store i32 %8, i32* %1, align 4
	%9 = load i32, i32* %1, align 4
	%10 = icmp ne i32 %9, 0
	br i1 %10, label %label5, label %label6

	label5:
	%11 = load i32, i32* %1, align 4
	call void @print_int(i32 %11)
	br label %label4

	label6:
	ret void
}

define i32 @main () #0 {
	call void @func(i32 20)
	ret i32 0
	%2 = alloca i32, align 4
	%3 = load i32, i32* %2, align 4
	ret i32 %3
}

