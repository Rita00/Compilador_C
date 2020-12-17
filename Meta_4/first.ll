declare i32 @getchar()
declare i32 @putchar(i32)
define i32 @teste (double %a, double %c, i32 %d) #0 {
	%1 = alloca double, align 8
	store double %a, double* %1, align 8
	%2 = alloca double, align 8
	store double %c, double* %2, align 8
	%3 = alloca i32, align 4
	store i32 %d, i32* %3, align 4
	%4 = sitofp i32 98 to double
	store double %4, double* %1, align 8
	store i32 4, i32* %3, align 4
	%5 = load i32, i32* %3, align 4
	%6 = sitofp i32 %5 to double
	%7 = fadd double 30.000000, %6
	store double %7, double* %1, align 8
	%8 = load double, double* %1, align 8
	%9 = load double, double* %2, align 8
	%10 = fadd double %8, %9
	store double %10, double* %2, align 8
	%g = alloca i32, align 4
	store i32 48, i32* %g, align 4
	%11 = load i32, i32* %3, align 4
	ret i32 %11
	%13 = alloca i32, align 4
	%14 = load i32, i32* %13, align 4
	ret i32 %14
}

define i32 @main () #0 {
	%d = alloca i32, align 4
	%1 = load i32, i32* %d, align 4
	%2 = sitofp i32 %1 to double
	%3 = call i32 @teste(double %2,double 0.2,i32 2)
	%f = alloca i32, align 4
	store i32 %3, i32* %f, align 4
	%4 = load i32, i32* %f, align 4
	%5 = add i32 %4, 48
	%6 = call i32 @putchar(i32 %5)
	%7 = alloca i32, align 4
	%8 = load i32, i32* %7, align 4
	ret i32 %8
}

