VIM IS EPIC.

  k	
h   l    to move
  j

Press x to remove the character at your cursor's position

Shift+A to start adding to the end of the line
Shift+I to start adding to the start of the line
i to start adding right where the cursor is
a to start adding once spot ahead of where the cursor is


Press the o key to start in insert mode after the line you are currently on
Press Shift+O to start in insert mode one line before the line you are currently on





0 jump to the start of a line
Shift+4 jump to the end of a line
Shift+5 jump to the middle of a line

Type ZZ to save and quit
Type ZQ to quit without saving changes



Find and replace:
s/old/new/		//does it on one line
s/old/new/g		//does it on all lines




To move up and down through one singular line that wraps across the screen: g+k or g+j






You may want to specify an option in vim, like ":set number".
To undo this, type ":set nonumber"

Also, the vim command line has auto-completion when you TAB


Jump to the bottom of the document
G

Jump to the top of a document
gg

Jump to line #
20g			//go to line 20

Jump x percent through the document
20%			//jump to 20% through the document

Show info about the document: Ctrl+G

zz to center your view around your cursor



//VERY USEFUL
u to undo
Ctrl+R to redo
~ to capitalize or lowercase the selected characters
> to tab a line to the right
< to tab a line to the left
4> to tab aline to the right four times





//VERY USEFUL
Repeat last action on a line: .
Typing . will do the last set of actions you did on a line, starting doing more actions on a different line and those actions you once did will not be redone next time, instead the current action you are doing!



//VERY USEFUL
Selecting in visual mode:

Press v to start selecting from the characters your cursor moves over

Press Shift+V to start selecting the entirety of each line your cursor moves over

Press Ctrl+V to start a rectangle selection of characters




//VERY USEFUL
Do an action in normal mode on multiple lines:

Step 1. Select lines to perform actions on in visual mode
Step 2. :norm
Step 3. Type in the command you want to do



//VERY USEFUL
//REPLACE MODE
to start replacing characters at your cursor's position, type Shift+R






//SPELL CHECK
Enter this vim command:
:setlocal spell! spellang=en_us

Words highlighted in blue are not capitalized.
Words highlighted in red are spelled wrong.
When your cursor is over a word that is spelled wrong, type z= to bring up a list of words it could be.

To jump to the next misspelled word, type ]s

To turn of spellcheck, enter this vim command:
:setlocal spell!






//Searching
Type / followed by the thing you want to search for, then press enter.
You will be brought to the next occurence of the text, press n to move to the next next occurence.

Type /ignore <WORD> to ignore case, or enter the command ":set ic" to start ignoring case

Also, ":set hls" will highlight what you're searching for.












