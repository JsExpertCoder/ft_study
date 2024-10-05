_Turn-in directory : ex07/
Files to turn in : r_dwssap.sh
Allowed functions : None_

Write a command line that displays the output of a cat /etc/passwd command,
removing comments, every other line starting from the second line, reversing each lo-
gin, sorted in reverse alphabetical order, and keeping only logins between FT_LINE1
and FT_LINE2 included, and they must separated by ", " (without quotation
marks), and the output must end with a ".".

# 0 - displays the output of a cat /etc/passwd command
```bash
cat /etc/passwd
```

# 1 - no comments, every other line starting from the second line, and just usernames
```bash
 | awk -F ':' '!/^#/ && NR % 2 == 0 {print $1}'
```

- no comments
```bash
 | awk '!/^#/'
```

- every other line starting from the second line
```bash
 | awk 'NR % 2 == 0'
```

- just usernames
```bash
 | awk -F ':'  '{print $1}'
```

# 4 - reversing each login
```bash
 | rev
```

# 5 - sorted in reverse alphabetical order
```bash
 | sort -r
```

# 6 - keeping only logins between FT_LINE1 and FT_LINE2 included
```bash
 | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2"
```

# 7 - and they must separated by ", " (without quotation marks)
```bash
| paste -sd "," - | sed 's/,/, /g'
```
- `paste -sd"," -`: Joins the logins with commas.
- `sed 's/,/, /g'`: Adds a space after each comma.

The paste command is typically used to merge lines from multiple files or inputs. In this case, we're using it to join the lines of logins into a single string, separated by commas.

`-s`: This option tells paste to merge (or "paste") all input lines serially into one single line, rather than combining them side by side.

`-d,`: The -d option specifies the delimiter to use between the merged lines. In this case, we're telling paste to use a comma (,) to separate the login names.

`-`: This refers to standard input, meaning the command will take its input from whatever is being piped to it (in this case, the list of reversed login names from the previous steps).




# 8 - and the output must end with a "."
```bash
sed 's/$/./'
```
This sed command is used to ensure that the final output ends with a period (.).

- `s/$/./`: The s command in sed stands for "substitute." It’s used to replace text in a line.
   - `$`: This is a special character that represents the end of the line.

    - `.`: This is what we want to add at the end of the line.

So, the command says: "Replace the end of the line ($) with a period (.)."


# result:

```bash
cat /etc/passwd | awk -F ':' '!/^#/ && NR % 2 == 0 {print $1}' | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | paste -sd "," - | sed 's/,/, /g' | sed 's/$/./' | tr -d '\n'

