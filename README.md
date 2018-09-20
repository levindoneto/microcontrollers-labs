## Set Up from scratch of Galileo on a computer

### Install the Intel System Studio IoT Edition

1.  Download it from [here](https://moodle.ece.ufrgs.br/mod/url/view.php?id=676).

2.  Get it into your machine.

```
$ sudo su
$ cd /home/<USERNAME>
$ mkdir opt
$ cd opt
$ tar -xjf iss-iot-linux_03-24-16.tar.bz2
$ rm iss-iot-linux_03-24-16.tar.bz2
```

3.  Adjust the permissions of the obtained files

```
$ chown -R root.root iss-iot-linux
$ chmod -R go-w iss-iot-linux
$ chmod -R -s iss-iot-linux
```

4.  Create links

```
$ ln -s iss-iot-linux iot-devkit
$ cd iot-devkit
$ ln -s devkit-x86 1.7.2
$ INSTALL_DIR=`pwd` sdk-relocator/relocate_sdk.sh
```

### Clean up cross compiler

Since the cross compiler has been previously set on your the computer, if you try to use the normal compiler it won't work. For this purpose, just type on the terminal the following command:

```
$ export CROSS_COMPILE=

```

##
