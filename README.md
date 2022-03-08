# pwgen(1) but for home-row keysmashing

[![Tweet by @halkyardo: "patching pwgen(1) to generate randomised but plausible-looking keymashing"](tweet.jpg)](https://twitter.com/halkyardo/status/1425098716235640833)

## THIS IS A LOW-EFFORT SHITPOST, DO NOT ACTUALLY USE THIS

The `-b` / `--bottom` option invokes the `pw_smash` generator, that tries to
approximate keymashing, preferring characters on the home row.

Alternately, use `-s` / `--bottom-semicolons` to include the *entire* home row, if that's your sort of thing.

**ONCE AGAIN, THIS GENERATES BAD PASSWORDS AND IS PROBABLY BROKEN. DO NOT USE THIS**

```
$ ./pwgen -b 10 -n 5
jfkshfhssd kgjghglddg hfjjuhkgfk kahksjqgdl fgsjghkjhh
$ ./pwgen -b 23 -n 3
hgkahdadalkskkflfstssja fkhdldahsrfahaljhghyalk ddmpfkgudllglsdffstdhlg
$ ./pwgen -b 6 -n 10
ggkgff hgflhs ghhgkj dkallj hhhdfd aldhkd sofigd kadkss sffjjk hafajk
```
