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
	push {r3, lr}


	cmp r0, #0
	beq .L3

	mov r3, r2
	add r2, r1, r2
	mov r1, r3
	sub r0, #1
	bl fibonacci
	mov r0, r1


	pop {r3, pc}		@EPILOG

	@ END CODE MODIFICATION
.L3:
	mov r0, #0
	pop {r3, pc}		@ EPILOG

	.size fibonacci, .-fibonacci
	.end
