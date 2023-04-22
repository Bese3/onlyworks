	.file	"2d.c"
	.text
	.globl	a
	.data
	.align 32
	.type	a, @object
	.size	a, 36
a:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.long	7
	.long	8
	.long	9
	.section	.rodata
.LC0:
	.string	"Sample Array"
	.align 8
.LC1:
	.string	"  ####################################"
	.align 8
.LC2:
	.string	"  #    2D Array Implementation       #"
	.align 8
.LC3:
	.string	" 1. Insert\n 2. Traverse\n 3. Search\n 4. Delete\n 5. Display"
.LC4:
	.string	"%d"
	.align 8
.LC5:
	.string	"Which Row And Column Do U Like To Update?"
.LC6:
	.string	"Row:"
.LC7:
	.string	"Column:"
.LC8:
	.string	"Enter The Number:"
	.align 8
.LC9:
	.string	"Which Row And Column Do U Like To Delete?"
.LC10:
	.string	"Invalid Choice"
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
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	call	display
.L10:
	movl	$10, %edi
	call	putchar@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-16(%rbp), %eax
	cmpl	$5, %eax
	ja	.L2
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L4(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L4(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L2-.L4
	.long	.L8-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
.L8:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-12(%rbp), %edx
	movl	-20(%rbp), %ecx
	movl	-24(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	insert
	jmp	.L9
.L7:
	movl	$0, %eax
	call	traverse
	jmp	.L9
.L6:
	movl	$0, %eax
	call	search
	jmp	.L9
.L5:
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	delete
	jmp	.L9
.L3:
	movl	$0, %eax
	call	display
	jmp	.L9
.L2:
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L9:
	movl	-16(%rbp), %eax
	cmpl	$1, %eax
	je	.L10
	movl	-16(%rbp), %eax
	cmpl	$2, %eax
	je	.L10
	movl	-16(%rbp), %eax
	cmpl	$3, %eax
	je	.L10
	movl	-16(%rbp), %eax
	cmpl	$4, %eax
	je	.L10
	movl	-16(%rbp), %eax
	cmpl	$5, %eax
	je	.L10
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L12
	call	__stack_chk_fail@PLT
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC11:
	.string	"Enter a Value in the size of the Array"
	.text
	.globl	insert
	.type	insert, @function
insert:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	cmpl	$0, -20(%rbp)
	jle	.L14
	cmpl	$0, -24(%rbp)
	jle	.L14
	cmpl	$3, -20(%rbp)
	jg	.L14
	cmpl	$3, -24(%rbp)
	jle	.L15
.L14:
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L13
.L15:
	movl	$2, -12(%rbp)
	jmp	.L17
.L24:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	je	.L18
	movl	$2, -8(%rbp)
	jmp	.L19
.L20:
	movl	-8(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-8(%rbp), %eax
	movslq	%eax, %rsi
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rsi, %rax
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	(%rdx,%rax), %edx
	movslq	%ecx, %rsi
	movl	-12(%rbp), %eax
	movslq	%eax, %rcx
	movq	%rcx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	addq	%rsi, %rax
	leaq	0(,%rax,4), %rcx
	leaq	a(%rip), %rax
	movl	%edx, (%rcx,%rax)
	subl	$1, -8(%rbp)
.L19:
	cmpl	$0, -8(%rbp)
	jns	.L20
	jmp	.L21
.L18:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jne	.L21
	movl	$2, -4(%rbp)
	jmp	.L22
.L23:
	movl	-4(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-4(%rbp), %eax
	movslq	%eax, %rsi
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rsi, %rax
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	(%rdx,%rax), %edx
	movslq	%ecx, %rsi
	movl	-12(%rbp), %eax
	movslq	%eax, %rcx
	movq	%rcx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	addq	%rsi, %rax
	leaq	0(,%rax,4), %rcx
	leaq	a(%rip), %rax
	movl	%edx, (%rcx,%rax)
	subl	$1, -4(%rbp)
.L22:
	movl	-24(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -4(%rbp)
	jge	.L23
.L21:
	subl	$1, -12(%rbp)
.L17:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jge	.L24
	movl	-20(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-24(%rbp), %eax
	subl	$1, %eax
	movslq	%eax, %rcx
	movslq	%edx, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,4), %rcx
	leaq	a(%rip), %rdx
	movl	-28(%rbp), %eax
	movl	%eax, (%rcx,%rdx)
	nop
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	insert, .-insert
	.section	.rodata
.LC12:
	.string	" %d   "
	.text
	.globl	display
	.type	display, @function
display:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	jmp	.L26
.L29:
	movl	$0, -4(%rbp)
	jmp	.L27
.L28:
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, %esi
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L27:
	cmpl	$2, -4(%rbp)
	jle	.L28
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -8(%rbp)
.L26:
	cmpl	$2, -8(%rbp)
	jle	.L29
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	display, .-display
	.globl	delete
	.type	delete, @function
delete:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	cmpl	$0, -20(%rbp)
	jle	.L32
	cmpl	$0, -24(%rbp)
	jle	.L32
	cmpl	$3, -20(%rbp)
	jg	.L32
	cmpl	$3, -24(%rbp)
	jle	.L33
.L32:
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L31
.L33:
	movl	-20(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-24(%rbp), %eax
	subl	$1, %eax
	movslq	%eax, %rcx
	movslq	%edx, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	$0, (%rdx,%rax)
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	.L35
.L42:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jne	.L36
	movl	-24(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.L37
.L38:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rcx
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	(%rdx,%rax), %edx
	movl	-8(%rbp), %eax
	movslq	%eax, %rsi
	movl	-12(%rbp), %eax
	movslq	%eax, %rcx
	movq	%rcx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	addq	%rsi, %rax
	leaq	0(,%rax,4), %rcx
	leaq	a(%rip), %rax
	movl	%edx, (%rcx,%rax)
	addl	$1, -8(%rbp)
.L37:
	cmpl	$2, -8(%rbp)
	jle	.L38
	jmp	.L39
.L36:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	je	.L39
	movl	$0, -4(%rbp)
	jmp	.L40
.L41:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rcx
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	(%rdx,%rax), %edx
	movl	-4(%rbp), %eax
	movslq	%eax, %rsi
	movl	-12(%rbp), %eax
	movslq	%eax, %rcx
	movq	%rcx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	addq	%rsi, %rax
	leaq	0(,%rax,4), %rcx
	leaq	a(%rip), %rax
	movl	%edx, (%rcx,%rax)
	addl	$1, -4(%rbp)
.L40:
	cmpl	$2, -4(%rbp)
	jle	.L41
.L39:
	addl	$1, -12(%rbp)
.L35:
	cmpl	$2, -12(%rbp)
	jle	.L42
	movl	$0, 32+a(%rip)
	nop
.L31:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	delete, .-delete
	.section	.rodata
.LC13:
	.string	"Enter the Array[%d][%d]:\n"
	.text
	.globl	traverse
	.type	traverse, @function
traverse:
.LFB4:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	jmp	.L44
.L47:
	movl	$0, -4(%rbp)
	jmp	.L45
.L46:
	movl	-4(%rbp), %eax
	leal	1(%rax), %edx
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	addl	$1, -4(%rbp)
.L45:
	cmpl	$2, -4(%rbp)
	jle	.L46
	addl	$1, -8(%rbp)
.L44:
	cmpl	$2, -8(%rbp)
	jle	.L47
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	traverse, .-traverse
	.section	.rodata
.LC14:
	.string	"Enter the number to search"
	.align 8
.LC15:
	.string	"Found the number %d in the Array[%d][%d]\n"
	.align 8
.LC16:
	.string	"Your number isnt found in the Array"
	.text
	.globl	search
	.type	search, @function
search:
.LFB5:
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
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -24(%rbp)
	jmp	.L50
.L55:
	movl	$0, -20(%rbp)
	jmp	.L51
.L54:
	movl	-20(%rbp), %eax
	movslq	%eax, %rcx
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	movq	-16(%rbp), %rax
	cmpq	%rax, %rdx
	jne	.L59
	movl	-20(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-24(%rbp), %eax
	leal	1(%rax), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L49
.L59:
	nop
	addl	$1, -20(%rbp)
.L51:
	cmpl	$2, -20(%rbp)
	jle	.L54
	addl	$1, -24(%rbp)
.L50:
	cmpl	$2, -24(%rbp)
	jle	.L55
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
.L49:
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L57
	call	__stack_chk_fail@PLT
.L57:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	search, .-search
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
