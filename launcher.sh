#!/bin/bash

#tested on debian 9 strech

if [ "$FIRST_TIME_LIB" != "False" ]; then
	#install requirement for script
	apt install 

	#tmp dir
	mkdir .tmp_aruco
	cd .tmp_aruco
	PWD=$(pwd)

	#clone repository
	wget --no-check-certificate --content-disposition https://github.com/[git]/tarball/v0.7.1

	#install opencv
	mkdir opencvdir
	cd opencvdir
	mv ../install-opencv.sh .
	chmod +x install-opencv.sh

	#configure opencv
	./install-opencv.sh
	cd $PWD

	#install aruco
	mkdir arucodir
	cd arucodir
	unzip ../aruco-master.zip
	cd aruco-master
	mkdir build
	cd build/
	cmake ..
	make -j6
	make install
	cd $PWD
	updatedb
	export LD_PATH="$LD_PATH:/usr/local/lib"
	
	#cleanup ?
	read -p "Do you want to remove the temporary folder ? " -n 1 -r
	if [[ $REPLY =~ ^[Yy]$ ]]
	then
    		rm -rf .tmp_aruco/
	fi
	
	export FIRST_TIME_LIB="False"
fi

#ask to configure aruco
read -p "Do you want to make a configuration file now (need graphical env)? " -n 1 -r
if [[ $REPLY =~ ^[Yy]$ ]]
then
    aruco_calibration live calib.yml -size 0.03 -save
    CALIBRATION_FILE="$(pwd)/calib.yml"
fi

#end
echo the calibration file is in users directory



