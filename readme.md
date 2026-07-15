*This project has been created as part of the 42 curriculum by acamelo.*

# C Piscine C 02 - String Manipulation & Memory Layouts

## Description

**C 02** deepens the exploration of memory by focusing heavily on **string manipulation, memory mapping, and character classification**. In C, strings are not native high-level objects; they are contiguous arrays of characters ending with a null-terminator (`\0`). Understanding how to duplicate, format, sanitize, and validate these arrays safely is a crucial milestone for secure software development.

Throughout this module, the objective is to replicate standard foundational routines from `<string.h>` (such as `strcpy`, `strncpy`, and string case toggles), while engineering low-level analytics engines that audit string formats. Additionally, it addresses the display of raw unprintable memory frames via hex manipulation, working entirely within the code constraints of the **42 Norm**.

---

## Instructions

### Prerequisites

To compile and execute these programs, you require a standard C compiler (`gcc` or `clang`) installed within a UNIX-like environment.

### Compiling and Testing

Each exercise is isolated in its own directory and compiled independently. They contain an operational `main.c` layout to allow instant structural debugging.

* **To compile a specific exercise using the standard 42 security flags:**
```bash
cc -Wall -Wextra -Werror ft_strcpy.c -o test_program

```


* **To run the generated binary executable:**
```bash
./test_program

```



---

## Detailed Description of Exercises

Every exercise targets a specific application of string parsing, layout validation, or data output conversions:

### 1. String Copying Foundations

* **ex00: `ft_strcpy.c**` – Replicates the standard `strcpy` function. It copies a source string into a destination buffer pointer, moving character-by-character until it duplicates the null-terminator.
* **ex01: `ft_strncpy.c**` – Replicates `strncpy`. It copies up to $n$ bytes from a source string. If the source is shorter than $n$, it pads the remaining space in the destination buffer with `\0` bytes to ensure predictable memory behavior.

### 2. String Content Auditing & Validation

* **ex02: `ft_str_is_alpha.c**` – Scans a string to verify it contains exclusively alphabetical characters. It returns `1` if valid or if the string is empty, and `0` if it detects any symbol, number, or space.
* **ex03: `ft_str_is_numeric.c**` – Validates that a string consists entirely of numerical digits (`0-9`).
* **ex04: `ft_str_is_lowercase.c**` – Audits the target memory block to verify that all alphabetic letters are strictly lowercase.
* **ex05: `ft_str_is_uppercase.c**` – Audits the target memory block to verify that all alphabetic letters are strictly uppercase.
* **ex06: `ft_str_is_printable.c**` – Checks whether every character in the string falls within the printable ASCII range (decimals 32 to 126), catching hidden control characters or escape sequences.

### 3. Case Transformation Engines

* **ex07: `ft_strupcase.c**` – Iterates through a string and modifies it in-place, transforming every lowercase character into its uppercase counterpart by adjusting its ASCII offset.
* **ex08: `ft_strlowcase.c**` – Performs the reverse operational logic of the previous exercise, converting uppercase characters into lowercase in-place.

---

## Technical Decisions & Challenges

### Preventing Memory Overflows in String Copying

A major security risk in low-level programming is handling uncontrolled string copies. While `ft_strcpy` assumes the destination buffer is pre-allocated with enough space, `ft_strncpy` introduces a size barrier ($n$) to bound the tracking loop. Implementing this required careful index synchronization: ensuring that if the source string ends early, the function continues to explicitly fill the rest of the requested $n$ buffer space with null-terminators to prevent data leaks from uninitialized memory segments.

### Bitwise and Offset-Based Character Mapping

Rather than building extensive lookup matrices to toggle character capitalization in `ft_strupcase` and `ft_strlowcase`, the conversion leverages a constant ASCII mathematical offset. Since the difference between any lowercase letter (e.g., `'a'` = 97) and uppercase letter (e.g., `'A'` = 65) is exactly 32, the transformation applies filter boundaries (`if (str[i] >= 'a' && str[i] <= 'z')`) and directly shifts the value (`str[i] -= 32;`), minimizing processing overhead.

---

## Resources

### References & Learning Materials

* **Standard C Specifications (`man strcpy` / `man strncpy`):** Utilized to cross-reference exactly how edge cases—such as string length being equal to or greater than the character parameter count $n$—should be handled down to the exact byte.
* **ASCII Value Structural Tables:** Used to map out character classification ranges for printable strings and alphabetic shifts without importing external headers like `<ctype.h>`.
* **Cluster Peer Feedback:** Constant collaboration at 42 Madrid helped establish comprehensive edge-case validation suites, verifying that empty strings safely returned default true states (`1`) across all validation tasks.

### AI Usage Statement

Artificial Intelligence was integrated into this project as a structural and educational advisor under the following rules:

* **Algorithmic Boundary Reviews:** Used to inspect nested safety loops inside string validations to ensure structural performance.
* **Technical Editing:** AI assisted in organizing, structuring, and polishing this technical `README.md` to guarantee a clean, professional look for engineering managers and recruiters at the Web Summit.
* *Note: Every single line of code was written manually, line-by-line, adhering strictly to the 42 Norm guidelines.*