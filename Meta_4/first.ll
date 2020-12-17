declare i32 @getchar()
declare i32 @putchar(i32)
define i32 @fibonnaci (i32 %n) #0 {
	%1 = alloca i32, align 4
	store i32 %n, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = icmp sle i32 %2, 1
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %label1, label %label2

	label1:
	%6 = load i32, i32* %1, align 4
	ret i32 %6
	br label %label3

	label2:
	%8 = load i32, i32* %1, align 4
	%9 = sub i32 %8, 1
	%10 = call i32 @fibonnaci(i32 %9)
	%11 = load i32, i32* %1, align 4
	%12 = sub i32 %11, 2
	%13 = call i32 @fibonnaci(i32 %12)
	%14 = add i32 %10, %13
	ret i32 %14
	br label %label3

	label3:
	%16 = alloca i32, align 4
	%17 = load i32, i32* %16, align 4
	ret i32 %17
}

define i32 @fatorial (i32 %n) #0 {
	%1 = alloca i32, align 4
	store i32 %n, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = icmp sle i32 %2, 1
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %label1, label %label2

	label1:
	ret i32 1
	br label %label3

	label2:
	%7 = load i32, i32* %1, align 4
	%8 = sub i32 %7, 1
	%9 = call i32 @fatorial(i32 %8)
	%10 = load i32, i32* %1, align 4
	%11 = mul i32 %10, %9
	ret i32 %11
	br label %label3

	label3:
	%13 = alloca i32, align 4
	%14 = load i32, i32* %13, align 4
	ret i32 %14
}

define i32 @gcd (i32 %a, i32 %b) #0 {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = alloca i32, align 4
	store i32 %b, i32* %2, align 4
	%r = alloca i32, align 4
	br label %label1

	label1:
	%3 = load i32, i32* %2, align 4
	%4 = icmp sgt i32 %3, 0
	%5 = zext i1 %4 to i32
	%6 = icmp ne i32 %5, 0
	br i1 %6, label %label2, label %label3

	label2:
	%7 = load i32, i32* %1, align 4
	%8 = load i32, i32* %2, align 4
	%9 = srem i32 %7, %8
	store i32 %9, i32* %r, align 4
	%10 = load i32, i32* %2, align 4
	store i32 %10, i32* %1, align 4
	%11 = load i32, i32* %r, align 4
	store i32 %11, i32* %2, align 4
	br label %label1

	label3:
	%12 = load i32, i32* %1, align 4
	ret i32 %12
	%14 = alloca i32, align 4
	%15 = load i32, i32* %14, align 4
	ret i32 %15
}

define i32 @bigmod (i32 %a, i32 %p, i32 %m) #0 {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = alloca i32, align 4
	store i32 %p, i32* %2, align 4
	%3 = alloca i32, align 4
	store i32 %m, i32* %3, align 4
	%c = alloca i32, align 4
	%4 = load i32, i32* %2, align 4
	%5 = icmp eq i32 %4, 0
	%6 = zext i1 %5 to i32
	%7 = icmp ne i32 %6, 0
	br i1 %7, label %label1, label %label2

	label1:
	ret i32 1
	br label %label3

	label2:
	br label %label3

	label3:
	%9 = load i32, i32* %2, align 4
	%10 = srem i32 %9, 2
	%11 = icmp ne i32 %10, 0
	br i1 %11, label %label4, label %label5

	label4:
	%12 = load i32, i32* %1, align 4
	%13 = load i32, i32* %3, align 4
	%14 = srem i32 %12, %13
	%15 = load i32, i32* %2, align 4
	%16 = sub i32 %15, 1
	%17 = load i32, i32* %1, align 4
	%18 = load i32, i32* %3, align 4
	%19 = call i32 @bigmod(i32 %17,i32 %16,i32 %18)
	%20 = mul i32 %14, %19
	%21 = load i32, i32* %3, align 4
	%22 = srem i32 %20, %21
	ret i32 %22
	br label %label6

	label5:
	%24 = load i32, i32* %2, align 4
	%25 = sdiv i32 %24, 2
	%26 = load i32, i32* %1, align 4
	%27 = load i32, i32* %3, align 4
	%28 = call i32 @bigmod(i32 %26,i32 %25,i32 %27)
	store i32 %28, i32* %c, align 4
	%29 = load i32, i32* %c, align 4
	%30 = load i32, i32* %3, align 4
	%31 = srem i32 %29, %30
	%32 = load i32, i32* %c, align 4
	%33 = load i32, i32* %3, align 4
	%34 = srem i32 %32, %33
	%35 = mul i32 %31, %34
	%36 = load i32, i32* %3, align 4
	%37 = srem i32 %35, %36
	ret i32 %37
	br label %label6

	label6:
	%39 = alloca i32, align 4
	%40 = load i32, i32* %39, align 4
	ret i32 %40
}

define i32 @primes (i32 %n) #0 {
	%1 = alloca i32, align 4
	store i32 %n, i32* %1, align 4
	%i = alloca i32, align 4
	store i32 3, i32* %i, align 4
	%count = alloca i32, align 4
	%c = alloca i32, align 4
	%2 = load i32, i32* %1, align 4
	%3 = icmp sge i32 %2, 1
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %label1, label %label2

	label1:
	%6 = call i32 @putchar(i32 50)
	%7 = call i32 @putchar(i32 32)
	br label %label3

	label2:
	br label %label3

	label3:
	store i32 2, i32* %count, align 4
	br label %label4

	label4:
	%8 = load i32, i32* %count, align 4
	%9 = load i32, i32* %1, align 4
	%10 = icmp sle i32 %8, %9
	%11 = zext i1 %10 to i32
	%12 = icmp ne i32 %11, 0
	br i1 %12, label %label5, label %label6

	label5:
	store i32 2, i32* %c, align 4
	br label %label7

	label7:
	%13 = load i32, i32* %i, align 4
	%14 = sub i32 %13, 1
	%15 = load i32, i32* %c, align 4
	%16 = icmp sle i32 %15, %14
	%17 = zext i1 %16 to i32
	%18 = load i32, i32* %i, align 4
	%19 = load i32, i32* %c, align 4
	%20 = srem i32 %18, %19
	%21 = icmp ne i32 %20, 0
	%22 = zext i1 %21 to i32
	%23 = icmp ne i32 %17, 0
	br i1 %23, label %label10, label %label11

	label10:
	%24 = icmp ne i32 %22, 0
	br label %label11

	label11:
	%25 = phi i1 [false, %label7], [%24, %label10]
	%26 = zext i1 %25 to i32
	%27 = icmp ne i32 %26, 0
	br i1 %27, label %label8, label %label9

	label8:
	%28 = load i32, i32* %c, align 4
	%29 = add i32 %28, 1
	store i32 %29, i32* %c, align 4
	br label %label7

	label9:
	%30 = load i32, i32* %c, align 4
	%31 = load i32, i32* %i, align 4
	%32 = icmp eq i32 %30, %31
	%33 = zext i1 %32 to i32
	%34 = icmp ne i32 %33, 0
	br i1 %34, label %label12, label %label13

	label12:
	%35 = load i32, i32* %i, align 4
	%36 = add i32 %35, 48
	%37 = call i32 @putchar(i32 %36)
	%38 = call i32 @putchar(i32 44)
	%39 = load i32, i32* %count, align 4
	%40 = add i32 %39, 1
	store i32 %40, i32* %count, align 4
	br label %label14

	label13:
	br label %label14

	label14:
	%41 = load i32, i32* %i, align 4
	%42 = add i32 %41, 1
	store i32 %42, i32* %i, align 4
	br label %label4

	label6:
	ret i32 0
	%44 = alloca i32, align 4
	%45 = load i32, i32* %44, align 4
	ret i32 %45
}

define i32 @main () #0 {
	%a = alloca i32, align 4
	store i32 10, i32* %a, align 4
	%1 = load i32, i32* %a, align 4
	%2 = sub i32 %1, 5
	%3 = call i32 @fatorial(i32 %2)
	%4 = call i32 @putchar(i32 %3)
	%5 = call i32 @putchar(i32 10)
	%6 = load i32, i32* %a, align 4
	%7 = call i32 @fibonnaci(i32 %6)
	%8 = call i32 @putchar(i32 %7)
	%9 = call i32 @putchar(i32 10)
	%10 = call i32 @bigmod(i32 151,i32 5,i32 200)
	%11 = add i32 %10, 48
	%12 = call i32 @putchar(i32 %11)
	%13 = call i32 @putchar(i32 10)
	%14 = call i32 @gcd(i32 10,i32 5)
	%15 = call i32 @bigmod(i32 151,i32 5,i32 200)
	%16 = add i32 %14, %15
	%17 = load i32, i32* %a, align 4
	%18 = sub i32 %17, 5
	%19 = call i32 @fatorial(i32 %18)
	%20 = add i32 %16, %19
	%21 = load i32, i32* %a, align 4
	%22 = call i32 @fibonnaci(i32 %21)
	%23 = add i32 %20, %22
	%24 = add i32 %23, 48
	%25 = call i32 @putchar(i32 %24)
	%26 = call i32 @putchar(i32 10)
	%27 = call i32 @primes(i32 5)
	%28 = call i32 @putchar(i32 %27)
	%29 = call i32 @putchar(i32 10)
	%30 = call i32 @fibonnaci(i32 4)
	%31 = icmp ne i32 10, 0
	br i1 %31, label %label2, label %label1

	label1:
	%32 = icmp ne i32 %30, 0
	br label %label2

	label2:
	%33 = phi i1 [true, %0], [%32, %label1]
	%34 = zext i1 %33 to i32
	%or = alloca i32, align 4
	store i32 %34, i32* %or, align 4
	%35 = load i32, i32* %or, align 4
	%36 = add i32 %35, 48
	%37 = call i32 @putchar(i32 %36)
	%38 = alloca i32, align 4
	%39 = load i32, i32* %38, align 4
	ret i32 %39
}

