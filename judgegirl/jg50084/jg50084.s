	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 13, 1
	.globl	_max                            ## -- Begin function max
	.p2align	4, 0x90
_max:                                   ## @max
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	LBB0_2
## %bb.1:
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)                 ## 4-byte Spill
	jmp	LBB0_3
LBB0_2:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)                 ## 4-byte Spill
LBB0_3:
	movl	-12(%rbp), %eax                 ## 4-byte Reload
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_jobfinish                      ## -- Begin function jobfinish
	.p2align	4, 0x90
_jobfinish:                             ## @jobfinish
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	$0, -32(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-32(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	LBB1_6
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movq	-24(%rbp), %rax
	movslq	-32(%rbp), %rcx
	movl	(%rax,%rcx,4), %eax
	movq	-16(%rbp), %rcx
	movslq	-32(%rbp), %rdx
	cmpl	(%rcx,%rdx,4), %eax
	jge	LBB1_4
## %bb.3:
	movb	$0, -1(%rbp)
	jmp	LBB1_7
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_5
LBB1_5:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	jmp	LBB1_1
LBB1_6:
	movb	$1, -1(%rbp)
LBB1_7:
	movb	-1(%rbp), %al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_jobchosen                      ## -- Begin function jobchosen
	.p2align	4, 0x90
_jobchosen:                             ## @jobchosen
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movl	16(%rbp), %eax
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	%r8, -40(%rbp)
	movl	%r9d, -44(%rbp)
	movl	$0, -48(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rax
	movslq	-48(%rbp), %rcx
	movl	(%rax,%rcx,4), %eax
	movq	-16(%rbp), %rcx
	movslq	-48(%rbp), %rdx
	cmpl	(%rcx,%rdx,4), %eax
	jne	LBB2_3
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	jmp	LBB2_1
LBB2_3:
	movl	-48(%rbp), %eax
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
LBB2_4:                                 ## =>This Inner Loop Header: Depth=1
	movl	-48(%rbp), %eax
	cmpl	16(%rbp), %eax
	jge	LBB2_10
## %bb.5:                               ##   in Loop: Header=BB2_4 Depth=1
	movq	-24(%rbp), %rax
	movslq	-48(%rbp), %rcx
	movl	(%rax,%rcx,4), %eax
	movq	-16(%rbp), %rcx
	movslq	-48(%rbp), %rdx
	cmpl	(%rcx,%rdx,4), %eax
	jge	LBB2_9
## %bb.6:                               ##   in Loop: Header=BB2_4 Depth=1
	movq	-8(%rbp), %rax
	movq	-40(%rbp), %rcx
	movslq	-48(%rbp), %rdx
	imulq	$4000, %rdx, %rdx               ## imm = 0xFA0
	addq	%rdx, %rcx
	movq	-24(%rbp), %rdx
	movslq	-48(%rbp), %rsi
	movslq	(%rdx,%rsi,4), %rdx
	movslq	(%rcx,%rdx,8), %rcx
	movl	(%rax,%rcx,4), %edi
	movq	-32(%rbp), %rax
	movslq	-48(%rbp), %rcx
	movl	(%rax,%rcx,4), %esi
	callq	_max
	movq	-40(%rbp), %rcx
	movslq	-48(%rbp), %rdx
	imulq	$4000, %rdx, %rdx               ## imm = 0xFA0
	addq	%rdx, %rcx
	movq	-24(%rbp), %rdx
	movslq	-48(%rbp), %rsi
	movslq	(%rdx,%rsi,4), %rdx
	addl	4(%rcx,%rdx,8), %eax
	movl	%eax, -56(%rbp)                 ## 4-byte Spill
	movq	-8(%rbp), %rax
	movq	-40(%rbp), %rcx
	movslq	-52(%rbp), %rdx
	imulq	$4000, %rdx, %rdx               ## imm = 0xFA0
	addq	%rdx, %rcx
	movq	-24(%rbp), %rdx
	movslq	-52(%rbp), %rsi
	movslq	(%rdx,%rsi,4), %rdx
	movslq	(%rcx,%rdx,8), %rcx
	movl	(%rax,%rcx,4), %edi
	movq	-32(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movl	(%rax,%rcx,4), %esi
	callq	_max
	movl	%eax, %ecx
	movl	-56(%rbp), %eax                 ## 4-byte Reload
	movq	-40(%rbp), %rdx
	movslq	-52(%rbp), %rsi
	imulq	$4000, %rsi, %rsi               ## imm = 0xFA0
	addq	%rsi, %rdx
	movq	-24(%rbp), %rsi
	movslq	-52(%rbp), %rdi
	movslq	(%rsi,%rdi,4), %rsi
	addl	4(%rdx,%rsi,8), %ecx
	cmpl	%ecx, %eax
	jge	LBB2_8
## %bb.7:                               ##   in Loop: Header=BB2_4 Depth=1
	movl	-48(%rbp), %eax
	movl	%eax, -52(%rbp)
LBB2_8:                                 ##   in Loop: Header=BB2_4 Depth=1
	jmp	LBB2_9
LBB2_9:                                 ##   in Loop: Header=BB2_4 Depth=1
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	jmp	LBB2_4
LBB2_10:
	movl	-52(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$2008064, %eax                  ## imm = 0x1EA400
	callq	____chkstk_darwin
	subq	%rax, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -2008020(%rbp)
	leaq	L_.str(%rip), %rdi
	leaq	-2008024(%rbp), %rsi
	leaq	-2008028(%rbp), %rdx
	movb	$0, %al
	callq	_scanf
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	cmpl	$0, -2008024(%rbp)
	movb	%al, -2008049(%rbp)             ## 1-byte Spill
	jle	LBB3_2
## %bb.1:
	cmpl	$500, -2008024(%rbp)            ## imm = 0x1F4
	setl	%al
	movb	%al, -2008049(%rbp)             ## 1-byte Spill
LBB3_2:
	movb	-2008049(%rbp), %al             ## 1-byte Reload
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %eax
	cltq
	cmpq	$0, %rax
	je	LBB3_4
## %bb.3:
	leaq	L___func__.main(%rip), %rdi
	leaq	L_.str.1(%rip), %rsi
	leaq	L_.str.2(%rip), %rcx
	movl	$43, %edx
	callq	___assert_rtn
LBB3_4:
	jmp	LBB3_5
LBB3_5:
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	cmpl	$0, -2008028(%rbp)
	movb	%al, -2008050(%rbp)             ## 1-byte Spill
	jle	LBB3_7
## %bb.6:
	cmpl	$500, -2008028(%rbp)            ## imm = 0x1F4
	setl	%al
	movb	%al, -2008050(%rbp)             ## 1-byte Spill
LBB3_7:
	movb	-2008050(%rbp), %al             ## 1-byte Reload
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %eax
	cltq
	cmpq	$0, %rax
	je	LBB3_9
## %bb.8:
	leaq	L___func__.main(%rip), %rdi
	leaq	L_.str.1(%rip), %rsi
	leaq	L_.str.3(%rip), %rcx
	movl	$44, %edx
	callq	___assert_rtn
LBB3_9:
	jmp	LBB3_10
LBB3_10:
	movl	$0, -2008032(%rbp)
LBB3_11:                                ## =>This Inner Loop Header: Depth=1
	movl	-2008032(%rbp), %eax
	cmpl	-2008024(%rbp), %eax
	jge	LBB3_14
## %bb.12:                              ##   in Loop: Header=BB3_11 Depth=1
	movslq	-2008032(%rbp), %rax
	movl	$0, -2016(%rbp,%rax,4)
## %bb.13:                              ##   in Loop: Header=BB3_11 Depth=1
	movl	-2008032(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2008032(%rbp)
	jmp	LBB3_11
LBB3_14:
	movl	$0, -2008036(%rbp)
LBB3_15:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB3_27 Depth 2
	movl	-2008036(%rbp), %eax
	cmpl	-2008028(%rbp), %eax
	jge	LBB3_35
## %bb.16:                              ##   in Loop: Header=BB3_15 Depth=1
	movslq	-2008036(%rbp), %rax
	movl	$0, -6016(%rbp,%rax,4)
	movslq	-2008036(%rbp), %rax
	leaq	-8016(%rbp), %rsi
	shlq	$2, %rax
	addq	%rax, %rsi
	movslq	-2008036(%rbp), %rax
	leaq	-4016(%rbp), %rdx
	shlq	$2, %rax
	addq	%rax, %rdx
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_scanf
	movslq	-2008036(%rbp), %rcx
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	cmpl	$0, -8016(%rbp,%rcx,4)
	movb	%al, -2008051(%rbp)             ## 1-byte Spill
	jl	LBB3_18
## %bb.17:                              ##   in Loop: Header=BB3_15 Depth=1
	movslq	-2008036(%rbp), %rax
	cmpl	$100, -8016(%rbp,%rax,4)
	setl	%al
	movb	%al, -2008051(%rbp)             ## 1-byte Spill
LBB3_18:                                ##   in Loop: Header=BB3_15 Depth=1
	movb	-2008051(%rbp), %al             ## 1-byte Reload
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %eax
	cltq
	cmpq	$0, %rax
	je	LBB3_20
## %bb.19:
	leaq	L___func__.main(%rip), %rdi
	leaq	L_.str.1(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$51, %edx
	callq	___assert_rtn
LBB3_20:                                ##   in Loop: Header=BB3_15 Depth=1
	jmp	LBB3_21
LBB3_21:                                ##   in Loop: Header=BB3_15 Depth=1
	movslq	-2008036(%rbp), %rcx
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	cmpl	$0, -4016(%rbp,%rcx,4)
	movb	%al, -2008052(%rbp)             ## 1-byte Spill
	jle	LBB3_23
## %bb.22:                              ##   in Loop: Header=BB3_15 Depth=1
	movslq	-2008036(%rbp), %rax
	cmpl	$500, -4016(%rbp,%rax,4)        ## imm = 0x1F4
	setl	%al
	movb	%al, -2008052(%rbp)             ## 1-byte Spill
LBB3_23:                                ##   in Loop: Header=BB3_15 Depth=1
	movb	-2008052(%rbp), %al             ## 1-byte Reload
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %eax
	cltq
	cmpq	$0, %rax
	je	LBB3_25
## %bb.24:
	leaq	L___func__.main(%rip), %rdi
	leaq	L_.str.1(%rip), %rsi
	leaq	L_.str.5(%rip), %rcx
	movl	$52, %edx
	callq	___assert_rtn
LBB3_25:                                ##   in Loop: Header=BB3_15 Depth=1
	jmp	LBB3_26
LBB3_26:                                ##   in Loop: Header=BB3_15 Depth=1
	movl	$0, -2008040(%rbp)
LBB3_27:                                ##   Parent Loop BB3_15 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-2008040(%rbp), %eax
	movslq	-2008036(%rbp), %rcx
	cmpl	-4016(%rbp,%rcx,4), %eax
	jge	LBB3_33
## %bb.28:                              ##   in Loop: Header=BB3_27 Depth=2
	movslq	-2008036(%rbp), %rax
	leaq	-2008016(%rbp), %rsi
	imulq	$4000, %rax, %rax               ## imm = 0xFA0
	addq	%rax, %rsi
	movslq	-2008040(%rbp), %rax
	shlq	$3, %rax
	addq	%rax, %rsi
	movslq	-2008036(%rbp), %rax
	leaq	-2008016(%rbp), %rdx
	imulq	$4000, %rax, %rax               ## imm = 0xFA0
	addq	%rax, %rdx
	movslq	-2008040(%rbp), %rax
	shlq	$3, %rax
	addq	%rax, %rdx
	addq	$4, %rdx
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_scanf
	movslq	-2008036(%rbp), %rcx
	leaq	-2008016(%rbp), %rax
	imulq	$4000, %rcx, %rcx               ## imm = 0xFA0
	addq	%rcx, %rax
	movslq	-2008040(%rbp), %rcx
	cmpl	$100, 4(%rax,%rcx,8)
	setl	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %eax
	cltq
	cmpq	$0, %rax
	je	LBB3_30
## %bb.29:
	leaq	L___func__.main(%rip), %rdi
	leaq	L_.str.1(%rip), %rsi
	leaq	L_.str.6(%rip), %rcx
	movl	$55, %edx
	callq	___assert_rtn
LBB3_30:                                ##   in Loop: Header=BB3_27 Depth=2
	jmp	LBB3_31
LBB3_31:                                ##   in Loop: Header=BB3_27 Depth=2
	jmp	LBB3_32
LBB3_32:                                ##   in Loop: Header=BB3_27 Depth=2
	movl	-2008040(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2008040(%rbp)
	jmp	LBB3_27
LBB3_33:                                ##   in Loop: Header=BB3_15 Depth=1
	jmp	LBB3_34
LBB3_34:                                ##   in Loop: Header=BB3_15 Depth=1
	movl	-2008036(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2008036(%rbp)
	jmp	LBB3_15
LBB3_35:
	jmp	LBB3_36
LBB3_36:                                ## =>This Inner Loop Header: Depth=1
	leaq	-4016(%rbp), %rdi
	leaq	-6016(%rbp), %rsi
	movl	-2008028(%rbp), %edx
	callq	_jobfinish
	xorb	$-1, %al
	testb	$1, %al
	jne	LBB3_37
	jmp	LBB3_38
LBB3_37:                                ##   in Loop: Header=BB3_36 Depth=1
	leaq	-2016(%rbp), %rdi
	leaq	-4016(%rbp), %rsi
	leaq	-6016(%rbp), %rdx
	leaq	-8016(%rbp), %rcx
	leaq	-2008016(%rbp), %r8
	movl	-2008024(%rbp), %r9d
	movl	-2008028(%rbp), %eax
	movl	%eax, (%rsp)
	callq	_jobchosen
	movl	%eax, -2008044(%rbp)
	movslq	-2008044(%rbp), %rcx
	leaq	-2008016(%rbp), %rax
	imulq	$4000, %rcx, %rcx               ## imm = 0xFA0
	addq	%rcx, %rax
	movslq	-2008044(%rbp), %rcx
	movslq	-6016(%rbp,%rcx,4), %rcx
	movslq	(%rax,%rcx,8), %rax
	movl	-2016(%rbp,%rax,4), %edi
	movslq	-2008044(%rbp), %rax
	movl	-8016(%rbp,%rax,4), %esi
	callq	_max
	movl	%eax, %ecx
	movslq	-2008044(%rbp), %rdx
	leaq	-2008016(%rbp), %rax
	imulq	$4000, %rdx, %rdx               ## imm = 0xFA0
	addq	%rdx, %rax
	movslq	-2008044(%rbp), %rdx
	movslq	-6016(%rbp,%rdx,4), %rdx
	addl	4(%rax,%rdx,8), %ecx
	movslq	-2008044(%rbp), %rdx
	leaq	-2008016(%rbp), %rax
	imulq	$4000, %rdx, %rdx               ## imm = 0xFA0
	addq	%rdx, %rax
	movslq	-2008044(%rbp), %rdx
	movslq	-6016(%rbp,%rdx,4), %rdx
	movslq	(%rax,%rdx,8), %rax
	movl	%ecx, -2016(%rbp,%rax,4)
	movslq	-2008044(%rbp), %rax
	movl	%ecx, -8016(%rbp,%rax,4)
	movslq	-2008044(%rbp), %rax
	movl	-6016(%rbp,%rax,4), %ecx
	addl	$1, %ecx
	movl	%ecx, -6016(%rbp,%rax,4)
	jmp	LBB3_36
LBB3_38:
	movl	$0, -2008048(%rbp)
LBB3_39:                                ## =>This Inner Loop Header: Depth=1
	movl	-2008048(%rbp), %eax
	cmpl	-2008028(%rbp), %eax
	jge	LBB3_42
## %bb.40:                              ##   in Loop: Header=BB3_39 Depth=1
	movslq	-2008048(%rbp), %rax
	movl	-8016(%rbp,%rax,4), %esi
	leaq	L_.str.7(%rip), %rdi
	movb	$0, %al
	callq	_printf
## %bb.41:                              ##   in Loop: Header=BB3_39 Depth=1
	movl	-2008048(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2008048(%rbp)
	jmp	LBB3_39
LBB3_42:
	movl	-2008020(%rbp), %eax
	movl	%eax, -2008056(%rbp)            ## 4-byte Spill
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB3_44
## %bb.43:
	movl	-2008056(%rbp), %eax            ## 4-byte Reload
	addq	$2008064, %rsp                  ## imm = 0x1EA400
	popq	%rbp
	retq
LBB3_44:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d%d"

L___func__.main:                        ## @__func__.main
	.asciz	"main"

L_.str.1:                               ## @.str.1
	.asciz	"jg50084.c"

L_.str.2:                               ## @.str.2
	.asciz	"N > 0 && N < MAX"

L_.str.3:                               ## @.str.3
	.asciz	"M > 0 && M < MAX"

L_.str.4:                               ## @.str.4
	.asciz	"jobtime[i] >= 0 && jobtime[i] < maxp"

L_.str.5:                               ## @.str.5
	.asciz	"jobamount[i] > 0 && jobamount[i] < maxq"

L_.str.6:                               ## @.str.6
	.asciz	"jobs[i][j].time < 100"

L_.str.7:                               ## @.str.7
	.asciz	"%d\n"

.subsections_via_symbols
