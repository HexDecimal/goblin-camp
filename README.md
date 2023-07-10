# Goblin Camp

Goblin Camp aims to be a roguelike city builder with an emphasis on
macromanaging the economy and military. I've drawn inspiration from games
such as Anno 1404, Dwarf Fortress and Dungeon Keeper.

Game have been originaly created by Ilkka Halila (aka  Generic Container) in
2010-2011 and brought back to live by Nikolay Shaplov in 2020-2022

## Gameplay

See [game/Readme.txt](game/Readme.txt)

## Building

Building is currently implemented and tested only for Linux. If you want to
add build files for your system, please contact the maintainer and submit merge-request.

### Linux

#### Building libtcod

First you will need relatively new version of [https://github.com/libtcod/libtcod](tcod library)
Goblin Camp is known to work with `libctod` v.1.19.0 and higher. But to build libctod in some older
systems (that has gcc 8.3), you might need `libctod` that will be released after v.1.21.0,
it will have gcc 8.3 building bug fixed.

While buildig wou will need to install libctod into `/usr` dir (not in `/usr/local` that goes by
default). To do it you sould pass  `--prefix=/usr` option to  `./configure` script. You can use
[libtcod building manual](https://github.com/libtcod/libtcod/blob/main/buildsys/autotools/README.md)
but do not forget adding extra option.

#### Getting dependences

To build Goblin Camp, you will need git, Cmake, Boost Libray, Pyhton, SDL2 and SDL2-image. For Debian-based
systems these programs and libraries can be obtained using following command:

```
sudo apt-get install build-essential git libsdl2-dev libboost-all-dev cmake libsdl2-image-dev
```

For other systems you should figure out how to get them.

#### Building

```
git clone https://gitlab.com/dhyannataraj/goblin-camp.git
mkdir goblin-camp/_build/
cd goblin-camp/_build/
cmake ..
sudo make install
```

If everything went well, you can run the game using `goblin-camp` command.

#### Useful configuring options

There are several building options that might be useful. You should pass them to `cmake` command
while preparing building.

`-DFORCE_PYTHON27=YES` -- forces build system to use python27 while building, if it is available.

`-DUSE_THREADS=NO` -- disables thread usage in Goblin Camp. Might be useful while debugging.

`-DUSE_VCPKG=YES` -- uses Vcpkg to download and link program dependencies.

# Obtaining code, reporting and contributing

You can obtain latest game code at https://gitlab.com/dhyannataraj/goblin-camp, there you can also
report bugs and file merge requests.

# License and author information

Game code is licensed under GNU/GPL v.3 or later. For more info see  [game/COPYING.txt](game/COPYING.txt)

## Copyrights

2010-2011 Originally created in by Ilkka Halila (aka Generic Container), gencontain@gmail.com; Twitter: ihalila

2020-2023 Brought back to live and maintained by Nikolay Shaplov (aka dhyan.nataraj), dhyan@nataraj.su; Matrix: @dhyan:nataraj.su
