--- Goblin Camp ---

-- About: --
Goblin Camp aims to be a roguelike city builder with an emphasis on
macromanaging the economy and military. I've drawn inspiration from games
such as Anno 1404, Dwarf Fortress and Dungeon Keeper.

Goblin Camp is open source, the full source is available at:
http://bitbucket.org/genericcontainer/goblin-camp
Code contributions are welcome!

-- Basic Controls --

*Right-click to open up the root menu. Clicking outside the menu or 
	right-clicking closes the menu.
*Middle-click moves back one level.
*Spacebar pauses the game
*Press the 'h' key down (and keep it pressed down) to see keyboard help text. 
	Basically there are keyboard shortcuts for most of the menus, and you can use
	the numbers 0-9 to choose a menu item.
*Keybindings can be changed from the main menu

- Stock manager controls -

*To quickly find the item you're looking for, type part of its name. 
	The stock manager will automatically sort the items based on your input.
*Either click the +/- buttons to change minimums, or press +/- on your numberpad.
*Holding down shift will change the minimums by 10

-- How to Play --

A good way to start is to create a pile by choosing it from the menu 
Constructions -> Basics -> Pile. Goblins will gather up all the items lying
around and store them in the pile.

Next designate trees for cutting by choosing Orders -> Designate trees, you can
pretty much drag the selection over as big an area as you feel like. The trees 
will only be cut down as needed. Open up the Stock Manager and raise the wood 
log minimum, maybe to 50 or so.

Now that the trees are being cut down, it might be a good idea to create another
pile, as only have one will be really inefficient in the long run. Fetching items
from the middle of a pile is slow.

Designate a farm plot, and allow whichever seed types you want there. 
Once spring begins, your goblins should plant all the seeds they have in the 
fields, as long as they are in a pile to begin with. For items to be usable
they must be stored in a pile.

You'll need planks for various things, so now you should build a saw pit. 
You can then raise the minimums for planks. You'll need a carpenter's workshop
for wooden clubs and other wooden items.

You can create your first military squad by opening the Squads menu. Type in a
name for the squad, set how many orcs you wish to be in it and click Create. 
Note that military orcs will not work in workshops! You can then set them to 
guard a specific spot, follow an npc, and choose which category of weapon they 
should use. If they are wielding nothing and you specify a weapon category, 
they'll automatically pick up weapons. If you later change the category, or 
make better weapons of the same category, click Rearm to order that squad to 
pickup better weapons.

Building walls for your camp is important, wild animals won't be able to attack 
you as freely. Doors will keep out most animals, only creatures with hands are 
able to open them. Flying creatures won't care though, so you have to be wary of 
them at all times.

A note on the Stock Manager. Setting minimums for producable goods like planks 
queues up jobs at the corresponding workshops, but it works slightly differently 
for seeds. A seed minimum actually defines how many seeds will be reserved 
_only_  for planting, and nothing else. You should set this to a value high enough
so that you'll always have seeds for farming and won't accidentally mill them all 
into flour.

You'll want to place your spawning pool to get more orcs and goblins, you'll be
losing them as monsters start harassing you. You only get to place one pool,
and can't move it later, so think before you place it!

-- Configuration --

The easiest way to change settings is through the main menu, but you can also
change the settings through config.ini as described below:

You can change the resolution and switch between windowed/full screen mode by
editing config.py which you'll find in your
/Documents/My Games/Goblin camp/ folder (or equivalent).

--

Licensing information is in COPYING.txt
Goblin Camp crash reporter tool uses SharpZipLib, which is GPL licensed (refer to COPYING.txt).

Copyright 2010-2011 Ilkka Halila (aka Generic Container), gencontain@gmail.com; Twitter: ihalila

Copyright 2020-2022 Nikolay Shaplov (aka dhyan.nataraj), dhyan@nataraj.su; Matrix: @dhyan:nataraj.su



