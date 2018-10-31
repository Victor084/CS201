	.file	"program.c"
	.text
	.globl	msg
	.data
	.align 32
	.type	msg, @object
	.size	msg, 357
msg:
	.ascii	"Switch statements are often implemented using a switch table"
	.ascii	" that consists\nof pointers to code that "
	.string	"are indexed by the value of the integer being\ntested.  In this assignment, you you will need to decode the switch table to\nfind out the value that will unlock the level.  The assembly output of the\nprogram is in 3.06_switch.s for your viewing convenience\n\n"
	.section	.rodata
.LC0:
	.string	"%s"
	.text
	.globl	print_msg
	.type	print_msg, @function
print_msg:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	msg(%rip), %rdi
	call	strlen@PLT
	movl	%eax, -4(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L2
.L3:
	movl	-16(%rbp), %eax
	movl	$0, %edx
	divl	-4(%rbp)
	movl	%edx, %eax
	movl	%eax, %edx
	leaq	msg(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movsbl	%al, %ecx
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	$0, %edx
	divl	-4(%rbp)
	movl	%edx, %eax
	movl	%eax, %edx
	leaq	msg(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movsbl	%al, %eax
	addl	%ecx, %eax
	addl	%eax, -12(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	$0, %edx
	divl	-4(%rbp)
	movl	%edx, %eax
	movl	%eax, %edx
	leaq	msg(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movsbl	%al, %ecx
	movl	-16(%rbp), %eax
	addl	$2, %eax
	movl	$0, %edx
	divl	-4(%rbp)
	movl	%edx, %eax
	movl	%eax, %edx
	leaq	msg(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movsbl	%al, %eax
	addl	%ecx, %eax
	addl	%eax, -8(%rbp)
	addl	$1, -16(%rbp)
.L2:
	movl	-4(%rbp), %eax
	imull	$100, %eax, %eax
	cmpl	%eax, -16(%rbp)
	jb	.L3
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jne	.L4
	leaq	msg(%rip), %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L4:
	leaq	msg(%rip), %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L6:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	print_msg, .-print_msg
	.section	.rodata
.LC1:
	.string	"Enter the password: "
.LC2:
	.string	"%d"
.LC3:
	.string	"Try again."
.LC4:
	.string	"Good Job."
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %eax
	call	print_msg
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-12(%rbp), %eax
	subl	$51182, %eax
	cmpl	$4, %eax
	ja	.L8
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L10(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	leaq	.L10(%rip), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L10:
	.long	.L9-.L10
	.long	.L11-.L10
	.long	.L12-.L10
	.long	.L11-.L10
	.long	.L9-.L10
	.text
.L9:
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	jmp	.L13
.L11:
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	jmp	.L13
.L12:
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	jmp	.L13
.L8:
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
.L13:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L15
	call	__stack_chk_fail@PLT
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
