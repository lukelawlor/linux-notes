GNU Emacs

I'm learning this thing because it's customizable or whatever and has org-mode. Also it just looks kind of cool

5.17.23
5.19.23
5.20.23

Notes from the official emacs tutorial

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
C-s	Forward search
C-r	Reverse search
Note: Typing C-s or C-r while searching will move to the next/previous occurrence of the search

Misc
C-u <number> Gives a numeric argument which is usually used as a repeat count for commands
C-g 	     Stop the command currently being executed
C-x C-c	     Quit emacs
C-h m	     View documentation on the current major mode
M-x 	     Execute a named extended command
<ESC> x3     All-purpose get out command
      	     This can be used for eliminating extra windows and getting out of the minibuffer
	     It can also get you out of a recursive editing level

Basic editing
<DEL>	Delete the char before the cursor
C-d	Delete the char after the cursor
M-<DEL> Kill the word before the cursor
M-d	Kill the word after the cursor
C-k	Kill from the cursor position to the end of the line
M-k	Kill from the cursor position to the end of the sentence
C-<SPC>	Set mark
C-w	Kill the selected text
C-y	Yank text
M-y	Yank previously yanked text
C-/	Undo

Files
C-x C-f		Find a file
C-x C-s		Save the file
C-x C-b		List buffers
C-x b		Find buffer
C-x s		Confirm saving of buffers with changes made from their files

Window navigation
C-x 0		Kill current window
C-x 1		Kill all windows but the current one
C-x 2		Split windows vertically
C-x 3		Split windows horizontally
C-x o		Next window (arg positive = go to the next window arg times, arg negative = go to the previous window arg times)
C-x ^		Enlarge window vertically (arg = enlarge positively or negatively arg times)
C-x }		Enlarge window horizontally (arg = enlarge psitively or negatively arg times)
C-M-v		Scroll the other window

Frame Manipulation
C-x 5 2		Create a new frame
C-x 5 0		Remove the current frame

Help
C-h ?		General help
C-h c <Command>	Brief help on <Command> displayed in the minibuffer
C-h k <Command>	Detailed help on <Command>
C-h x <CommandName>	 Help on <CommandName>
C-h v <Variable>	 Documentation on <Variable>
C-h a <Keyword>		 List all the command whose names contain <Keyword> and the sequences to run them
C-h i 		Read included manuals aka info
C-h r		Read emacs manual

Minor Modes
      auto-fill-mode
		To change the margin, give a na to C-x f
		The margin is 70 by default
		M-q to re-fill a paragraph

Terminology
Note: See the glossary in the emacs manual for more emacs terms
	killing text	removing text that can be reinserted
	deleting text	removing text that cannot be reinserted
	yanking	 	reinsertion of deleted text
	find a file	view the file's contents within emacs
	minibuffer	the line at the bottom of emacs used for basic text input
	mode line	the line above the minibuffer
	     		it shows the percent through the buffer, line number, and major mode in parenthesis
			you'll see ** if unsaved changes are made to the buffer's file
	window		Place where a new buffer, scrollbar, and mode line are
	frame		a collection of windows, together with its menus, scroll bars, echo area, etc.
	recursive editing level	     You know you're in one when the mode is surrounded with square brackets