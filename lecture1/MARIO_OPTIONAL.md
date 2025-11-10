# Mario Optional 

Recreate the half-pyramid program from Super Mario Bros., but with two side-by-side half-pyramids separated by two spaces.

- Input: an integer height h in [1, 8]
- Output: two right-aligned half-pyramids of height h, separated by two spaces

## Behavior

Prompt the user until they enter an integer between 1 and 8 inclusive. Then print h rows. On row i (1-indexed):

- Left padding: (h − i) spaces
- Left blocks: i hashes (#)
- Gap: two spaces
- Right blocks: i hashes (#)
- Newline

Examples:

For h = 1
  #  #

For h = 2
   #  #
  ##  ##
```
For h = 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```

Note: No trailing spaces at line ends.

## Input constraints

- Only accept integers 1 through 8.
- Reprompt on invalid input (non-integer or out of range).

## Hints

- Use loops for spaces and hashes (for/while).
- Avoid trailing spaces; print exactly what’s needed, then newline.
- Think row-by-row, segment-by-segment.

## Testing

- Try inputs: 0, 9, -3, "hi" → should reprompt
- Valid: 1, 2, 8 → should match the examples exactly

## Common pitfalls

- Printing extra spaces at end of line
- Off-by-one errors in loops
- Not validating input range [1, 8]
- Using tabs instead of spaces (use spaces)

## Style

Good luck!
