# Mario Required

Builds a right-aligned half-pyramid of hashes of height h (1–8), similar to the blocks in Nintendo’s Mario. The program repeatedly prompts the user for an integer height until they provide a valid value in the range 1–8 inclusive, then prints the pyramid.

## Requirements

- Prompt: “Height: ” (reprompt until 1 ≤ h ≤ 8)
- Output: Right-aligned half-pyramid of height h using `#`
- Each row i (1-indexed) has:
  - Spaces: `h - i`
  - Hashes: `i`
- No trailing spaces required
- Newline at end of each row

## Examples

Input:
Height: 4

Output:
   #
  ##
 ###
####

Input:
Height: 8

Output:
       #
      ##
     ###
    ####
   #####
  ######
 #######
########

## Hints

- Validate input in a loop until 1–8.
- Use nested loops: one for rows, inner loops for spaces and hashes.
- Avoid trailing spaces by printing exactly the counts.

## Testing

- Try edge cases: 1 and 8.
- Try invalid inputs: 0, 9, negatives, non-numeric (will reprompt).
- Compare with the spec’s examples.

## Common Pitfalls

- Forgetting to reprompt until valid.
- Off-by-one in spaces/hashes.
- Extra spaces at end of lines.

## How to Run

```bash
make mario
./mario
```

Enter a height between 1 and 8 when prompted.

## Submission Instructions

Follow this workflow to submit your solution:

1) Create a new branch
- Branch must be prefixed with your name and surname, followed by /lecture1.
- Example: john-doe/lecture1

```bash
git checkout -b name-surname/lecture1
```

2) Add your files into lecture1/
- Place your solution files inside a folder named lecture1 at the repo root.
- Example structure:
  - lecture1/mario-required.c

```bash
git add lecture1
git commit -m "Add mario-required solution in lecture1"
```

3) Push the branch

```bash
git push -u origin name-surname/lecture1
```

4) Open a Pull Request (PR)
- Base: main (or the repository’s default branch)
- Compare: name-surname/lecture1
- Title suggestion: Mario (less): name-surname/lecture1
- Description: Briefly describe what you added in lecture1/

5) Assign reviewers
- Assign meho and selmir to the PR as reviewers.

6) Address feedback
- Push follow-up commits to the same branch to update the PR as needed.
