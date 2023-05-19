GNU Emacs

I'm learning this thing because it's customizable or whatever and has org-mode. Also it just looks kind of cool

5.17.23
5.19.23

Vocab used in these notes
      na      	   numeric argument
      <DEL>	   backspace
      <SPC>	   spacebar

Movement
C-v	Scroll screen down
	na - move n lines down
M-v	Scroll screen up
	na - move n lines up
C-l	Center screen around cursor
C-n	Next line
C-p	Previous line
C-f	Forward 1 char
C-b	Backward 1 char
M-f	Forward 1 word
M-b	Backward 1 word
C-a	Move to beginning of line
C-e	Move to end of line
M-a	Move to beginning of sentence
M-e	Move to end of sentence
M-<	Move to the beginning of the file
M->	Move to the end of the file

Misc
C-u <number> Gives a numeric argument which is usually used as a repeat count for commands
C-g 	     Stop the command currently being executed

Basic editing
<DEL>	Delete the char before the cursor
C-d	Delete the char after the cursor
M-<DEL> Kill the word before the cursor
M-d	Kill the word after the cursor
C-k	Kill from the cursor position to the end of theline
M-k	Kill from the cursor position to the end of the sentence
C-<SPC>	Set mark
C-w	Kill the selected text

Window navigation
C-x 0		Kill current window
C-x 1		Kill all windows but the current one
C-x 2		Split windows vertically
C-x 3		Split windows horizontally
C-x o		Next window (arg positive = go to the next window arg times, arg negative = go to the previous window arg times)
C-x ^		Enlarge window vertically (arg = enlarge positively or negatively arg times)
C-x }		Enlarge window horizontally (arg = enlarge psitively or negatively arg times)

Terminology
	killing text	removing text that can be reinserted
	deleting text	removing text that cannot be reinserted
	yanking	 	reinsertion of deleted text