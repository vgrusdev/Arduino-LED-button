# vgrusdev/Arduino-LED-button
----
## What is this ?

### Short story: 
I have very simple LED light driver with RF remote control.
Very simple as any other, that is now offering in the market. 
For example like this one:
https://arlight.moscow/catalog/rgb-rgbw-seriya-sr-367/kontroller-sr-1009fa-1-12-36v-240-720w-018268.html
with Radio controller similar to:
https://arlight.moscow/catalog/vstraivaemye-paneli-452/panel-knob-sr-2833k1-rf-up-white-3v-dim-020945.html
it looks like normal wall-mounted light switcher. But switcher has many thinks that make it "uncomfortable":
- looks like very chip plastic mechanism,
- instead of switchOn-switchOff (as normal switcher work), has algorithm "buttonUp, buttonDown" (very unusable for my home relatives).

### My idea is:
to make very simple device that will have a control as normal light switcher (On-Off), will press one of two buttons on remote control device (buttonUp, buttonDown).

You may say, arduino is too complex solution for it. It would be enough to have something like transistor, capacitor and relay.
I'd agree, but I wanted to try Arduino as my one of the first micro-controller project.
Plus, Adruino nano is quite chip to build even small embedded solutions.

## How it works ?

#### 1. I've got: 
- Arduino nano (you can use any arduino board you have),
- two-relays 5v module,
- RF remote controller.

#### 2. General idea you can see in the graph below.

[![](https://downloader.disk.yandex.ru/preview/025e1e2cc2a256cfb98e7cf72b6b388b0f8760affc66c9854b91db381b6798b9/5c65afbf/z4zaGFJX8tCrpfIRI4kCXt0oDRC0HP0TTToGNXncP9_mwEq7bWlTzb2WQNS4REPd-Ew_vNja_CqoA4uQvO-ZBA%3D%3D?uid=0&filename=Arduino-LED-button-1.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=400x400)]()

At the **"setup"** stage perform some initialisation :

- switch channel initialised and digital input with Pull-Up resistor. It will then "grounded" to switch-on
- both buttons are moved to HIGH level
- depends on switch position short impulse "clicks" on of the button (side effect - light on or off depends of switch position at power-on time)

In the **"loop"**:

- if switch change position (turned to on, or off), corresponded impulse will "click" the button (up or down).
- Delays in the loop fix the problem of the switch contacts bounce.

#### 3. Arduino schematic:

[![](https://downloader.disk.yandex.ru/preview/860b0ebf7a95c92c3fbba8e640cfae3ab84c5edca142a8de7376214a13927019/5c65ac36/KKlYovBo48RsN1KQs29BQ9v4CN5QJfvSca25LQ2Im_99zVikL5ReyLiVJe-RZ75DeNJq-VEtufngDJWeQC3ouQ%3D%3D?uid=0&filename=Arduino-LED-button-2.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&size=400x400)]()

I used Arduino Nano

pins 12, 11 - go to relays
pin  10 - goes to switch

LED Driver RF controller from Arlight (China - Russia).
 
====

Quick setup — if you’ve done this kind of thing before
 Set up in Desktop	or	
HTTPS
SSH
	
We recommend every repository include a README, LICENSE, and .gitignore.
…or create a new repository on the command line

echo "# Test" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/vgrusdev/Test.git
git push -u origin master

…or push an existing repository from the command line

 git remote add origin https://github.com/vgrusdev/Test.git
git push -u origin master

…or import code from another repository

You can initialize this repository with code from a Subversion, Mercurial, or TFS project.
