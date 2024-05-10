.global get_len
.text
get_len:
    mov r1, r0      // Move the value of x into r1
    mov r2, #20     // Move the value 20 into r2
    sub r0, r2, r1  // Subtract r1 from r2 and store the result in r0
    bx lr           // Return from the function

.end