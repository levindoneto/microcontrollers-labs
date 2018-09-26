## LAB 03 | gpio

### How to export a pin
```
echo -n "46" > /sys/class/gpio/export
```

### GPIO setup

In order to set up the GPIOs for each experiment, you need to have in your **root** user on Galileo the files *eng10032lab03_X*, which can be found on the [init folder](/init_d/).
Execute the following commands on your root user on Galileo:

```
$ groupadd -r gpio
$ groupmems -g gpio -a <USERNAME>
$ cp ~/eng10032lab03_X /etc/init.d
$ chmod +x /etc/init.d/eng10032lab03_1
$ update-rc.d eng10032lab03_1 defaults
$ reboot
```

Now, in your host machine, you can compile the programs and tranfer them via ssc to your user on Galileo.


### Remove initialization script
```
$ update-rc.d -f eng10032lab03_1 remove
```

### Experiments:

I made one video for each experiment (in Portuguese), showing where the connections in the grove shield must be done.

#### Blink 1
[Watch it](https://photos.app.goo.gl/JNhgDj2h1eUfeixD9)

#### Blink 2
[Watch it](https://photos.app.goo.gl/vs3gyEePPLcp3at69)

#### PushLed
[Watch it](https://photos.app.goo.gl/kgsEjibv3W74WaVr8)

