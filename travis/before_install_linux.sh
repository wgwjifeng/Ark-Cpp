"/sbin/start-stop-daemon --start --quiet --pidfile /tmp/custom_xvfb_1.pid --make-pidfile --background --exec /usr/bin/Xvfb -- :1 -ac -screen 0 1280x1024x16"
sleep 3
export DISPLAY=:1.0
wget http://downloads.arduino.cc/arduino-1.6.5-linux64.tar.xz
tar xf arduino-1.6.5-linux64.tar.xz
sudo mv arduino-1.6.5 /usr/local/share/arduino
sudo ln -s /usr/local/share/arduino/arduino /usr/local/bin/arduino
