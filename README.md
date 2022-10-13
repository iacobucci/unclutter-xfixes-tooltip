# unclutter-xfixes-tooltip

## About

I have quickly patched [unclutter](https://github.com/Airblader/unclutter-xfixes) for it to have the mouse pointer move away from where it's left off and lessen the [annoyance](https://unix.stackexchange.com/questions/697055/run-a-script-when-mouse-is-idle) of pop-ups and highlights, like [wikipedia's](https://www.mediawiki.org/wiki/Reference_Tooltips).\
You can use the `--new-coordinates <x,y>` option to specify where the pointer will be moved. If the option is not passed to the program, the pointer won't be moved.

## Installation

### Manual

Make sure to install the missing dependencies first:

* libev-devel
* libX11-devel
* libXi-devel
* asciidoc 
* xdotool

You can then clone the git repository, compile and install it using like this:

```
git clone https://github.com/iacobucci/unclutter-xfixes
cd unclutter-xfixes
make
sudo make install
```

## Usage

See `man unclutter` after installation.
