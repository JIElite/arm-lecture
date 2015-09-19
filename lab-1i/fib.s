	.syntax unified
	.arch armv7-a
	.text
	.align 2
	.thumb
	.thumb_func

	.global fibonacci
	.type fibonacci, function

fibonacci:
	@ ADD/MODIFY CODE BELOW
	@ PROLOG
	push {r3, r4, r5, lr}
		
	@ because r0 is as same as input, we use it as counter
	cmp r0, #0
	beq .L3

	cmp r0, #1
	beq .L4

	@ If input number is bigger than 1
	@ R4 is used to be counter 

	mov r3, #0
	mov r4, #1

.L5:
	@ use r5 as tmp variable
	mov r5, r4
	add r4, r4, r3
	mov r3, r5
	
	@ treat r0 as counter
	sub r0, r0, #1
	cmp r0, #1
	bne .L5

	mov r0, r4
		
	pop {r3, r4, r5, pc}		@EPILOG

	@ END CODE MODIFICATION

.L3:
	@ return value is r0
	mov r0, #0			@ R0 = 0
	pop {r3, r4, r5, pc}		@ EPILOG

.L4:
	@ return value is r0
	mov r0, #1			@ R0 = 1
	pop {r3, r4, r5, pc}		@ EPILOG

	.size fibonacci, .-fibonacci
	.end
