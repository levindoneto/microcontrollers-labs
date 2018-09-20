
## Commands for setting Galileo up

### Connect to the Galileo as a super user

```
$ ssh root@<IP_GALILEO_WITHOUT_REPEATED_ZEROS>
$ passwd
$ useradd -c <LOGIN_NEW_USER> -s /bin/bash -m <LOGIN_NEW_USER>
$ passwd <LOGIN_NEW_USER>
$ exit
```

### Log into Galileo with the created user (LOGIN_NEW_USER)

```
$ ssh <LOGIN_NEW_USER>@<IP_GALILEO_WITHOUT_REPEATED_ZEROS>
$ echo "export PATH=.:$PATH" >> .profile
$ exit
```

## Set up Galileo's system on a host machine and cross compiler

### Install the Intel System Studio IoT Edition

1.  Download it from [here](https://moodle.ece.ufrgs.br/mod/url/view.php?id=676).

2.  Get it into your machine (inside *computer/opt*).

```
$ sudo su
$ cd /opt
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

## Useful commands

```
$ ssh <USERNAME_GALILEO>@<IP_GALILEO_WITHOUT_REPEATED_ZEROS>

```
```
$ scp <FILE_IN_HOST> <USERNAME_GALILEO>@<IP_GALILEO_WITHOUT_REPEATED_ZEROS>:

```






