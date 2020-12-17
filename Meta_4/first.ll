declare i32 @getchar()
declare i32 @putchar(i32)
@a = global i32 451631784, align 4
@b = global i32 354356, align 4
@c = global i32 1, align 4
define i32 @main () #0 {
	%1 = load i32, i32* @a, align 4
	%2 = load i32, i32* @b, align 4
	%3 = icmp eq i32 %1, %2
	%4 = zext i1 %3 to i32
	store i32 %4, i32* @a, align 4
	%5 = load i32, i32* @a, align 4
	%6 = add i32 %5, 48
	%7 = call i32 @putchar(i32 %6)
	%8 = load i32, i32* @a, align 4
	%9 = load i32, i32* @b, align 4
	%10 = icmp ne i32 %8, %9
	%11 = zext i1 %10 to i32
	store i32 %11, i32* @a, align 4
	%12 = load i32, i32* @a, align 4
	%13 = add i32 %12, 48
	%14 = call i32 @putchar(i32 %13)
	%15 = load i32, i32* @a, align 4
	%16 = load i32, i32* @b, align 4
	%17 = icmp slt i32 %15, %16
	%18 = zext i1 %17 to i32
	store i32 %18, i32* @a, align 4
	%19 = load i32, i32* @a, align 4
	%20 = add i32 %19, 48
	%21 = call i32 @putchar(i32 %20)
	%22 = load i32, i32* @a, align 4
	%23 = load i32, i32* @b, align 4
	%24 = icmp sle i32 %22, %23
	%25 = zext i1 %24 to i32
	store i32 %25, i32* @a, align 4
	%26 = load i32, i32* @a, align 4
	%27 = add i32 %26, 48
	%28 = call i32 @putchar(i32 %27)
	%29 = load i32, i32* @a, align 4
	%30 = load i32, i32* @b, align 4
	%31 = icmp sgt i32 %29, %30
	%32 = zext i1 %31 to i32
	store i32 %32, i32* @a, align 4
	%33 = load i32, i32* @a, align 4
	%34 = add i32 %33, 48
	%35 = call i32 @putchar(i32 %34)
	%36 = load i32, i32* @a, align 4
	%37 = load i32, i32* @b, align 4
	%38 = icmp sge i32 %36, %37
	%39 = zext i1 %38 to i32
	store i32 %39, i32* @a, align 4
	%40 = load i32, i32* @a, align 4
	%41 = add i32 %40, 48
	%42 = call i32 @putchar(i32 %41)
	ret i32 0
	%44 = alloca i32, align 4
	%45 = load i32, i32* %44, align 4
	ret i32 %45
}

