	.file	"factorial.c"
	.text
	.section	.rodata
.LC0:
	.string	"Enter an integer: "
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"Factorial is not defined for negative numbers."
	.align 8
.LC3:
	.string	"Factorial for values greater than %d cannot be computed with int data type.\n"
.LC4:
	.string	"Factorial of %d is %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-20(%rbp), %eax
	testl	%eax, %eax
	jns	.L2
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	jmp	.L3
.L2:
	movl	-20(%rbp), %eax
	cmpl	$12, %eax
	jle	.L4
	movl	$12, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L4:
	movl	$1, -16(%rbp)
	movl	$1, -12(%rbp)
	jmp	.L5
.L6:
	movl	-16(%rbp), %eax
	imull	-12(%rbp), %eax
	movl	%eax, -16(%rbp)
	addl	$1, -12(%rbp)
.L5:
	movl	-20(%rbp), %eax
	cmpl	%eax, -12(%rbp)
	jle	.L6
	movl	-20(%rbp), %eax
	movl	-16(%rbp), %edx
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L3:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
