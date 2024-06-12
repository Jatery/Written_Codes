> Name: 陳彥璋  
> Student ID: B12902049

References:  
https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c  
https://www.quora.com/What-is-the-value-of-EOF  
https://stackoverflow.com/questions/2661766/how-do-i-lowercase-a-string-in-c  
https://stackoverflow.com/questions/12306591/read-no-more-than-size-of-string-with-scanf  

Compile: gcc driver.c sset.c cset.c

Usage: by running a.out(./a.out), you can start the course selection system. Valid input are as follows:

```
# 1. register a student into the system

register <student_name> <register_code>

# 2. withdraw a student out of the system

withdraw <student_name>

# 3. check if a student is in the system

check <student_name>
```

`<student_name>` should be two strings representing the lastname and the name, both with at most 15 characters, containing only letters. The uppercase and lowercase of the letters are equivalent.

`<register_code>` should be a string with 10 digits and only digits.

If the inputs are not enough, `Invalid input` will be printed; others like `Code invalid`, `Student already registered` or succeed messages will will be as written.
